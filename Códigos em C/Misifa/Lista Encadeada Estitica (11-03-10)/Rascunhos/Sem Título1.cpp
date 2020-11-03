#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Estrutura do tipo registro;
// info: Informa��o armazenada; prox: Indica o pr�ximo elemento da lista;
struct Reg{
       int info;
       int prox;
};
//------------------------------------------------------------------------------

// Estrutura do tipo Lista que armazena estruturas do tipo Reg;
// dispo: Indica uma posi��o dispon�vel; prim: Indica o primeiro elemento;
typedef struct{
        int dispo;
        int prim;
        struct Reg l[MAX];
} Lista;
//------------------------------------------------------------------------------

// Escopo das fun��es;
int Search(int Info, Lista *L);
short Insert(int Info, Lista *L, int OP, int Index);
short Remove(int Info, Lista *L);
void PreencherLista(Lista *L, int N);
int SearchFinal(Lista *L);
void Start(Lista *L);
void Print(Lista *L, int OP);
void Segmentar(Lista *L);
int Menu(Lista *L);
//------------------------------------------------------------------------------

int Menu(Lista *L){
    int op=0, op2=0, indexop=-1, cont=0, valor=0;
         
     system("cls");
     op=0; op2=0; indexop=-1;
     printf("[0] Sair\n");
     printf("[1] Pesquisa\n");
     printf("[2] Insercao\n");
     printf("[3] Remocao\n");
     printf("[4] Prencher lista com zeros\n");
     printf("[5] Imprimir vetor\n\n");
     scanf("%d",&op);            
     switch (op){
            case 0: return(0);
            break;
            case 1: printf("Insira o valor: ");
                    scanf("%d",&valor);
                    printf("%d",Search(valor,L));
            break;
            case 2: printf("\nInserir: [1]Inicio [2]Fim [3]Apos: ");
                 scanf("%d",&op2);
                 switch (op2){
                        case 1: op2=1;
                        break;
                        case 2: op2=2;
                        break;
                        case 3: op2=3;
                                printf("\nInserir apos o elemento: ");
                                scanf("%d",&indexop);
                        break;
                        default: op2=2;
                 }
                 printf("Insira o valor: ");
                 scanf("%d",&valor);
                 if(Insert(valor,L,op2,indexop)) printf("Operacao realizada com sucesso\n\n");
                 else printf("Erro\n\n");
            break;
            case 3: printf("Insira o valor: ");
                    scanf("%d",&valor);
                    if(Remove(valor,L)) printf("Operacao realizada com sucesso\n\n");
                    else printf("Erro\n\n");
            break;
            case 4: PreencherLista(L,1);
            break;
            case 5: printf("Insira a opcao: ");
                    int OP; scanf("%d",&OP);
                    Print(L,OP);
     }
     printf("\nReiniciar? ");
     scanf("%d",&cont);
     return(cont);
}


// Insert: Fun��o de inser��o na lista;
// Info: Informa��o a ser inserida; *L: Ponteiro p/ Lista; OP: Op��o de inser��o
// (in�cio [1], fim [2] e ap�s x [3]; Index: x de OP 3;
short Insert(int Info, Lista *L, int OP, int Index){
      int aux=-1, aux2=0, aux3=0;
      switch (OP){
             case 1: if (L->dispo==-1) return(0);
                     if (L->prim==-1){
                        L->prim=0;
                        L->l[L->dispo].info=Info;
                        L->dispo=L->l[L->dispo].prox;
                     }
                     else{
                          Segmentar(L);
                          aux=L->l[L->dispo].prox;
                          L->l[L->dispo].info=Info;
                          L->l[L->dispo].prox=L->prim;
                          L->prim=L->dispo;
                          L->dispo=aux;
                          return(1);
                     }
                     break;
             case 2: if(L->dispo==-1) return(0);
                     if(L->prim==-1) L->prim=0;
                     L->l[L->dispo].info=Info;
                     L->dispo=L->l[L->dispo].prox;
                     return(1);
                     break;
             case 3: if((L->dispo==-1)||(L->prim==-1)) return(0);
                     aux2=Search(Index,L);
                     if (aux2!=-1){
                        Segmentar(L);
                        aux3=L->l[L->dispo].prox;
                        L->l[L->dispo].info=Info;
                        L->l[L->dispo].prox=L->l[aux2].prox;
                        L->l[aux2].prox=L->dispo;
                        L->dispo=aux3;
                        return(1);
                     }
                     else return(0);
                     break;
      }
      return(0);
}
//------------------------------------------------------------------------------

// Segmentar: Arruma as coisas. Reseguimenta a Lista p/ n�o haver loop infinito;
// *L: Ponteiro p/ Lista;
void Segmentar(Lista *L){
     int index;
     
     index=L->prim;
     while (index!=-1){
           if (L->l[index].prox==L->dispo){
              L->l[index].prox=L->l[L->dispo].prox;
              break;
           }
           index=L->l[index].prox;
     }
     return;
}
//------------------------------------------------------------------------------

// Remove: Remove o elemento da lista
// Info: elemento a ser retirado; *L: Ponteiro para Lista;
short Remove(int Info, Lista *L){
      int index=-1, aux=0;
      
      aux=index=L->prim;
      while (index!=-1){
           if (L->l[index].info==Info){
              if(index==L->prim) L->prim=L->l[index].prox;
              L->l[aux].prox=L->l[index].prox;
              L->l[SearchFinal(L)].prox=index;
              L->l[index].prox=-1;
              return(1);
           }
           aux=index;
           index=L->l[index].prox;
     }
      return(0);
}
//------------------------------------------------------------------------------

// PreencherLista: Preenche as informa��es da Lista c/ determinado elemento;
// *L: Ponteiro para Lista; N: elemento a ser inserido em todas as informa��es;
void PreencherLista(Lista *L, int N){
     int index=-1;
     
     L->prim=L->dispo;
     index=L->prim;
     while (index!=-1){
           L->l[index].info=N;
           index=L->l[index].prox;
     }
     return;     
}
//------------------------------------------------------------------------------

// Search: Busca determniado elemento na Lista. Retorna a posi��o, caso o elemento
// seja encontrado e -1, caso o elemento n�o seja encontrado;
// Info: Informa��o buscada; *L: Ponteiro p/ lista.
int Search(int Info, Lista *L){
     int index=-1;
     
     index=L->prim;
     while ((index!=-1)&&(index!=L->dispo)){
           if(L->l[index].info==Info) return(index);
           index=L->l[index].prox;
           if(index==L->dispo) return(-1);
     }
     return(index);
}
//------------------------------------------------------------------------------

// SearchFinal: Retorna o conte�do do �ltimo elemento da Lista;
// *L: Ponteiro p/ Lista;
int SearchFinal(Lista *L){
     int index=-1;
     
     index=L->prim;
     for (;index!=-1;){
           if(L->l[index].prox==-1) return(index);
           index=L->l[index].prox;
     }
     return(index);
}
//------------------------------------------------------------------------------

// Start: Inicializa a Lista p/ utiliza��o;
// *L: Ponteiro p/ Lista;
void Start(Lista *L){
     int i;
     
     L->dispo=0;
     L->prim=-1;
     for (i=0;i<MAX-1;i++)
         L->l[i].prox=i+1;
     L->l[i].prox=-1;    
}
//------------------------------------------------------------------------------

// Print: Imprime em ordem as informa��es armazenadas ou progressivamente, a
// partir de 0, os ponteiros armazenados em cada Reg;
// *L: Ponteiro p/ Lista; OP: Op��o de impress�o ([1] Ponteiros [2]Infroma��es)
void Print(Lista *L, int OP){
     
     switch (OP){
            case 1: for (int i=0;i<MAX;i++)
                        printf("%d\n",L->l[i].prox);
            return;
            case 2: int i=L->prim;
                    while (i!=-1){
                        printf("%d\n",L->l[i].info);
                        i=L->l[i].prox;
                        if(i==L->prim) break;
                    }
            return;
     }
}
//------------------------------------------------------------------------------

// Fun��o main;
int main (void){
    Lista lista;
    
    Start(&lista);
    while(Menu(&lista));
    
    system("pause");
    return(0);
}
