#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Estrutura do tipo registro --------------------------------------------------
struct Reg{
       int info;
       int prox;
};
// Estrutura do tipo lista que armazena estruturas do tipo registro ------------
typedef struct{
        int dispo;
        int prim;
        struct Reg l[MAX];
} Lista;

int Search(int Info, Lista *L);
short Insert(int Info, Lista *L, int OP, int Index);
short Remove(int Info, Lista *L);
void PreencherLista(Lista *L, int N);
int *SearchFinal(Lista *L);
void Start(Lista *L);
void Print(Lista *L, int OP);

// Função de inserção na lista. Possui três opções de inserção: No início [1],
// no fim [2] e após determinado elemento [3] ----------------------------------
short Insert(int Info, Lista *L, int OP, int Index){
      int aux=-1, aux2=0, aux3=0;
      //Insert(valor,&lista,op2,indexop)
      switch (OP){
             case 1: if (L->dispo==-1) return(0);
                     if (L->prim==-1) L->prim=0;
                     aux=L->l[L->dispo].prox;
                     L->l[L->dispo].info=Info;
                     L->l[L->dispo].prox=L->prim;
                     L->prim=L->dispo;
                     L->dispo=aux;
                     return(1);
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
                        aux3=L->l[L->dispo].prox;
                        //L->l[L->l[aux].prox].prox=aux2;
                        L->l[L->dispo].info=Info;
                        L->l[L->dispo].prox=L->l[aux2].prox;
                        L->l[aux2].prox=aux3;
                        L->dispo=aux3;
                        return(1);
                     }
                     else return(0);
                     break;
      }
      return(0);
}

short Remove(int Info, Lista *L){
      int index=-1, aux=0;
      
      aux=index=L->prim;
      while (index!=-1){
           if (L->l[index].info==Info){
              if(index==L->prim) L->prim=L->l[index].prox;
              L->l[aux].prox=L->l[index].prox;
              L->l[L->l[index].prox].prox=index;
              L->l[index].prox=L->dispo;
              L->dispo=index;
              return(1);
           }
           aux=index;
           index=L->l[index].prox;
     }
      return(0);
}

void PreencherLista(Lista *L, int N){
     int index=-1;
     
     L->prim=L->dispo;
     index=L->prim;
     while (index!=-1){
           L->l[index].info=N;
           index=L->l[index].prox;
           //index=L->l[index].prox;
     }
     return;     
}

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

int *SearchFinal(Lista *L){
     int index=-1;
     
     index=L->prim;
     while (index!=-1)
           index=L->l[index].prox;
     return(&(L->l[index].info));
}

void Start(Lista *L){
     int i;
     
     L->dispo=0;
     L->prim=-1;
     for (i=0;i<MAX-1;i++)
         L->l[i].prox=i+1;
     L->l[i].prox=-1;    
}

void Print(Lista *L, int OP){
     
     //printf("%d",L->dispo);
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

int main (void){
    
    Lista lista;
    int op=0, op2=0, indexop=-1, cont=0, valor=0;
    
    Start(&lista);
    do{
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
                      printf("%d",Search(valor,&lista));
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
                             default: op2=2;
                      }
                      printf("Insira o valor: ");
                      scanf("%d",&valor);
                      if(Insert(valor,&lista,op2,indexop)) printf("Operacao realizada com sucesso\n\n");
                      else printf("Erro\n\n");
              break;
              case 3: printf("Insira o valor: ");
                      scanf("%d",&valor);
                      if(Remove(valor,&lista)) printf("Operacao realizada com sucesso\n\n");
                      else printf("Erro\n\n");
              case 4: PreencherLista(&lista,1);
              break;
              case 5: printf("Insira a opcao: ");
                      int OP; scanf("%d",&OP);
                      Print(&lista,OP);
       }
       printf("\nReiniciar? ");
       scanf("%d",&cont);
    }
    while(cont);
    
    system("pause");
    return(0);
}
