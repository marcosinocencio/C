#include <stdio.h>
#include <stdlib.h>

#include "listaencadeada.h"

// Menu: Função para exibição do menu;
int Menu(Lista *L){
    int op=0, op2=0, indexop=-1, cont=0, valor=0;
         
     system("cls");
     printf("%d - %d\n\n",L->prim,L->dispo);
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
            case 2: printf("\nInserir: [1]Inicio [2]Fim [3]Apos: [4]Ordenado");
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
                        case 4: op2=4;
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

short Order(Lista *L){
      int index=-1, aux=0;
      short cont=0;
      
      index=L->prim;
      if(index==-1) return(0);
      do{
         cont=0;
         while (L->l[index].prox!=-1){
               if ((L->l[index].info)>(L->l[L->l[index].prox].info)){
                  aux=L->l[index].info;
                  L->l[index].info=L->l[L->l[index].prox].info;
                  L->l[L->l[index].prox].info=aux;
                  cont=1;
               }
               index=L->l[index].prox;
         }
      }
      while(cont);
      return(1);
}

// Insert: Função de inserção na lista;
// Info: Informação a ser inserida; *L: Ponteiro p/ Lista; OP: Opção de inserção
// (início [1], fim [2] e após x [3]; Index: x de OP 3;
short Insert(int Info, Lista *L, int OP, int Index){
      int aux=-1, aux2=0, aux3=0;
      switch (OP){
             case 1: if (L->dispo==-1) return(0);
                     if (L->prim==-1){
                        L->prim=0;
                        L->l[L->dispo].info=Info;
                        L->dispo=L->l[L->dispo].prox;
                        return(1);
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
             case 4: if (L->dispo==-1) return(0);
                     if (L->prim==-1){
                        L->l[L->dispo].info=Info;
                        L->prim=L->dispo;
                        L->dispo=L->l[L->dispo].prox;
                        return(1);
                     }
                     if(Order(L)) printf("OK\n");
                     else printf("ERRO");
                     break;
      }
      return(0);
}
//------------------------------------------------------------------------------

// Segmentar: Arruma as coisas. Reseguimenta a Lista p/ não haver loop infinito;
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

// PreencherLista: Preenche as informações da Lista c/ determinado elemento;
// *L: Ponteiro para Lista; N: elemento a ser inserido em todas as informações;
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

// Search: Busca determniado elemento na Lista. Retorna a posição, caso o elemento
// seja encontrado e -1, caso o elemento não seja encontrado;
// Info: Informação buscada; *L: Ponteiro p/ lista.
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

// SearchFinal: Retorna o conteúdo do último elemento da Lista;
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

// Start: Inicializa a Lista p/ utilização;
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

// Print: Imprime em ordem as informações armazenadas ou progressivamente, a
// partir de 0, os ponteiros armazenados em cada Reg;
// *L: Ponteiro p/ Lista; OP: Opção de impressão ([1] Ponteiros [2]Infromações)
void Print(Lista *L, int OP){
     int i=0;
     
     switch (OP){
            case 1: for (i=0;i<MAX;i++)
                        printf("%d\n",L->l[i].prox);
            return;
            case 2: i=L->prim;
                    while (i!=-1){
                        printf("%d\n",L->l[i].info);
                        i=L->l[i].prox;
                        if(i==L->prim) break;
                    }
            return;
     }
}
//------------------------------------------------------------------------------
