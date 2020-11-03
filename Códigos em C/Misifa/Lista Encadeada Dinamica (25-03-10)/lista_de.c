/*
@copyright Luiz Paulo Rabachini @file: listadinamica.c
Release: 1.8 - Updated: 15/04/2010
---
Resume: Algorítimos do arquivo listadinamica.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista_de.h"

void Menu(Lista *L){
     int op=4, n=0, n2=0, p=0, cont=0;
     No *ant, *pos, *Aux, *Aux2;
     
     do{
     do{
        system("cls");
        if(L->prim) printf("%d\n",L->prim->info);
        if(L->ult) printf("%d\n\n",L->ult->info);
        printf("[1] Inserir na lista (ordenado)\n");
        printf("[2] Inserir na lista (no inicio)\n");
        printf("[3] Inserir na lista (no fim)\n");
        printf("[4] Inserir na lista (apos elemento x)\n");
        printf("[5] Inserir na lista (na posicao y)\n");
        printf("[6] Buscar elemento\n");
        printf("[7] Remover da lista\n");
        printf("[8] Imprimir lista\n");
        printf("[9] Sair\n\n");
        printf("Opcao: [  ]\b\b\b");
        scanf("%d",&op);
     } while((op<1)||(op>10));
     switch (op){
            case 1: printf("\n[1] Insercao na lista (ordenado)\n\n");
                    printf("Insira o elemento: "); scanf("%d",&n);
                    if(Insert(L,n,0,0)) printf("\nOperacao realizada com sucesso\n");
                    else printf("\nErro\n");
            break;
            case 2: printf("\n[2] Insercao na lista (no inicio)\n\n");
                    printf("Insira o elemento: "); scanf("%d",&n);
                    if(Insert(L,n,0,1)) printf("\nOperacao realizada com sucesso\n");
                    else printf("\nErro\n");
            break;
            case 3: printf("\n[3] Insercao na lista (no fim)\n\n");
                    printf("Insira o elemento: "); scanf("%d",&n);
                    if(Insert(L,n,0,2)) printf("\nOperacao realizada com sucesso\n");
                    else printf("\nErro\n");
            break;
            case 4: printf("\n[4] Insercao na lista (apos elemento x)\n\n");
                    printf("Insira o elemento: "); scanf("%d",&n);
                    printf("Insira o elemento x: "); scanf("%d",&n2);
                    if(Insert(L,n,n2,4)) printf("\nOperacao realizada com sucesso\n");
                    else printf("\nErro\n");
            break;
            case 5: printf("\n[5] Insercao na lista (na posicao y)\n\n");
                    printf("Insira o elemento: "); scanf("%d",&n);
                    printf("Insira a posicao y: "); scanf("%d",&n2);
                    if(Insert(L,n,n2,3)) printf("\nOperacao realizada com sucesso\n");
                    else printf("\nErro\n");
            break;
            case 6: printf("\n[6] Busca por elemento\n\n");
                    printf("Insira o elemento: "); scanf("%d",&n);
                    if(p=Search(L,2,n,&ant,&pos)) printf("\nElemento: %d Posicao: %d\n",pos->info,p);
                    else printf("\nErro\n");
            break;
            case 7: printf("\n[7] Remover elemento\n\n");
                    printf("Insira o elemento: "); scanf("%d",&n);
                    if(Remove(L,n)) printf("\nElemento retirado\n");
                    else printf("\nErro\n");
            break;
            case 8: Print(L);
            break;
            case 9: return;
            case 10:Aux=L->prim;
                    Aux2=L->ult;
                    printf("Prim: %d - Ult: %d\n",Aux->info,Aux2->info);            
                    Invert(&(L->prim));
                    Aux=L->prim;
                    Aux2=L->ult;
                    printf("Prim: %d - Ult: %d\n",Aux->info,Aux2->info);
                    L->prim=L->ult;
                    L->ult=Aux;
                    L->ult->prox=NULL;
                    printf("Inicio: %d",L->prim->info);
                    printf("Ult: %d",L->ult->info);
            break;
     }
     printf("\nDeseja continuar?(0:Sair,1:Prosseguir) Op: ");
     fflush(stdin);
     scanf("%d",&cont);
     } while(cont);
     return;
}

void StartLista(Lista* L){
     L->prim=NULL;
     L->ult=NULL;
     return;
}

int Search(Lista *L, int Op, int Index, No **Ant, No **Pos){
      int i;
      No *busca;
      
      *Ant=NULL;
      switch (Op){
             //Busca para inserção ordenada
             case 0: for (*Pos=(L->prim); *Pos; *Ant=*Pos, *Pos=(*Pos)->prox)
                         if (((*Pos)->info)>=Index) return(1);
                     return(0);
             //Busca para inserção em determinada posição
             case 1: for (*Pos=(L->prim), i=1; i<Index; *Ant=*Pos, *Pos=(*Pos)->prox, ++i)
                         if (!(*Pos)){
                            if (!Insert(L,0,0,2)) return(0);
                            *Pos=(L->ult);
                         }
                     return(1);
             //Busca de elemento (retornado pelo Pos)
             case 2: for (*Pos=(L->prim), i=1; *Pos; *Ant=*Pos, *Pos=(*Pos)->prox, i++)
                         if (((*Pos)->info)==Index) return(i);
                     return(0);
             default: printf("Search error: Opcao nao encontrada\n");
                      return(0);
      }
}

short Insert(Lista *L, int Info, int Index, int Op){
      No *novo;
      No *ant, *pos;
      
      switch (Op){
             //Inserção ordenada
             case 0: novo=(No*)malloc(sizeof(No));
                     if (!novo) return(0);
                     if (!(L->prim)){
                        novo->info=Info;
                        novo->prox=NULL;
                        L->prim=novo;
                        L->ult=novo;
                        return(1);
                     }
                     else{
                          Search(L,0,Info,&ant,&pos);    
                          novo->info=Info;
                          novo->prox=pos;
                          if(pos==NULL) L->ult=novo;
                          if (!ant) L->prim=novo;
                          else ant->prox=novo;
                          return(1); 
                     }
             //Inserção no início
             case 1: novo=(No*)malloc(sizeof(No));
                     if(!novo) return(0);
                     novo->info=Info;
                     if (!(L->prim)) L->ult=novo;
                     novo->prox=L->prim;
                     L->prim=novo;
                     return(1);
             //Inserção no final
             case 2: novo=(No*)malloc(sizeof(No));
                     if(!novo) return(0);
                     if (!(L->ult)) L->prim=novo;
                     else L->ult->prox=novo;
                     novo->info=Info;
                     novo->prox=NULL;
                     L->ult=novo;
                     return(1);
             //Inserção em determinada posição
             case 3: novo=(No*)malloc(sizeof(No));
                     if (!novo) return(0);
                     if (!Search(L,1,Index,&ant,&pos)) return(0);                     
                     novo->info=Info;
                     novo->prox=pos;
                     if(!ant) L->prim=novo;
                     else ant->prox=novo;
                     if(ant==L->ult) L->ult=novo;
                     return(1);
             //Inserção após elemento x 
             case 4: novo=(No*)malloc(sizeof(No));
                     if (!novo) return(0);
                     if (!Search(L,2,Index,&ant,&pos)) return(0);                     
                     novo->info=Info;
                     novo->prox=pos;
                     if(!ant) L->prim=novo;
                     else ant->prox=novo;
                     return(1);
             default:return(0);
      }
}

short Remove(Lista *L, int Info){
      No *ant, *pos;
      
      if (Search(L,2,Info,&ant,&pos)){
         if(pos==L->ult) L->ult=ant;
         if (!ant) L->prim=L->prim->prox;
         else ant->prox=pos->prox;
         free(pos);
         return(1);
      }
      else return(0);
}

void Print(Lista *L){
     No *index;
     
     for (index=L->prim; index; index=index->prox)
         printf("%d\n",index->info);
     return;
}

void Invert(No **A){
     
     if ((*A)->prox->prox==NULL){
        (*A)->prox->prox=(*A);
        return;
     }
     else{
          Invert(&((*A)->prox));
          (*A)->prox->prox=*A;
          return;
     }    
}
