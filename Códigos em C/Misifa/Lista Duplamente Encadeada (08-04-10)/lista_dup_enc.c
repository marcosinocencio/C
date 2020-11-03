/*
------------------------------------------------------
@copyright Luiz Paulo Rabachini @file: lista_dup_enc.c
Release: 1.4 - Updated: 20/04/2010
------------------------------------------------------
Resume: Algorítimos do arquivo lista_dup_enc.h
------------------------------------------------------
*/

// Inclusão das headers
#include <stdio.h>
#include <stdlib.h>
#include "lista_dup_enc.h"

// Define mensagens de alerta
#define MSGOK "Operacao realizada com sucesso\n"
#define MSGERROR "Erro durante a operacao\n"
#define MSGSOK "Elemento: %d. Posicao: %d\n"
#define MSGSERROR "Elemento nao encontrado\n"

// Função de inicialização da lista
void Start(Lista *L)
{
 L->prim=NULL;
 L->ult=NULL;
 return;
}
//------------------------------------------------------------------------------

// Função para exibição do menu
void Menu(Lista *L)
{
     int set=0, op=-1, info=0, p=0;
     No *elem;
     
     do{
        system("cls");
        printf("\n\n----------------------------------------------------------------\n\n");
        printf(":: Lista Duplamente Encadeda (V1.4) ::\n\n");
        printf("[0] Sair\n");
        printf("[1] Inserir elemento na lista\n");
        printf("[2] Remover elemento da lista\n");
        printf("[3] Buscar elemento da lista\n");
        printf("[4] Imprimir lista\n");
        printf("\nOpcao: [ ]\b\b"); scanf("%d",&op);
        switch (op){
               case 0: return;
               break;
               case 1: do{
                          printf("[1] Inserir elemento na lista\n");
                          printf("Elemento: "); fflush(stdin); scanf("%d",&info);
                          printf("Opcoes de insercao:\n");
                          printf("(0)Ordenada, (1)No inicio, (2)Na posicao x, (3)Apos elemento y, (4)No final\n");
                          fflush(stdin); scanf("%d",&set);
                        } while((set<0)||(set>4));
                        if(Insert(set,L,info)) printf(MSGOK);
                        else printf(MSGERROR);
               break;
               case 2: printf("[2] Remover elemento da lista\n");
                       printf("Elemento: "); fflush(stdin); scanf("%d",&info);
                       if(Remove(L,info)) printf(MSGOK);
                       else printf(MSGERROR);
               break;
               case 3: printf("[3] Buscar elemento da lista\n");
                       printf("Elemento: "); fflush(stdin); scanf("%d",&info);
                       if(p=Search(0,&elem,L,info)) printf(MSGSOK,info,p);
                       //int Search(int Set, No **Elem, No *L, int Info)
                       else printf(MSGSERROR);
               break;
               case 4:  printf("[4] Imprimir lista\n");
                        Print(L);
               break;
               case 5:  printf("\nPrim: %d",L->prim->info);
                        printf("\nUlt: %d",L->ult->info);
               break;
               default: printf("Opcao nao encontrada\n");       
      }
      system("pause");
     } while(1);
}
//------------------------------------------------------------------------------

// Função para inserção na lista
short Insert(int Set, Lista *L, int Info)
{
      No *novo, *elem=NULL;
      int aux=0;
      
      switch (Set){
             case 0: Search(1,&elem,L,Info);
                     if (elem)
                        if (elem!=L->prim){
                           novo=(No*)malloc(sizeof(No));
                           if (!novo) return(0);
                           novo->info=Info;
                           elem->ant->prox=novo;
                           novo->ant=elem->ant;
                           novo->prox=elem;
                           elem->ant=novo;
                        }
                        else Insert(1,L,Info);
                     else Insert(4,L,Info);
                     return(1);
             break;
             case 1: novo=(No*)malloc(sizeof(No));
                     if (!novo) return(0);
                     novo->info=Info;
                     novo->ant=NULL;
                     novo->prox=L->prim;
                     if (L->prim) L->prim->ant=novo;
                     else L->ult=novo; 
                     L->prim=novo;
                     return(1);
             break;
             case 2: CAux(&aux);
             printf("%d",aux);
                     if(!Search(2,&elem,L,aux)) return(0);
                     if(elem==L->prim) Insert(1,L,Info);
                     else{
                          novo=(No*)malloc(sizeof(No));
                          if (!novo) return(0);
                          novo->info=Info;
                          if(elem->ant) elem->ant->prox=novo;
                          novo->ant=elem->ant;
                          novo->prox=elem;
                          elem->ant=novo;
                          return(1);
                     }
             break;
             case 3: CAux(&aux);
                     if (Search(0,&elem,L,aux)){
                        if (elem==L->ult) Insert(4,L,Info);
                        else{
                             novo=(No*)malloc(sizeof(No));
                             if (!novo) return(0);
                             novo->info=Info;
                             novo->ant=elem;
                             novo->prox=elem->prox;
                             novo->prox->ant=novo;
                             elem->prox=novo;
                        }
                     }
                     else return(0);
                     return(1);
             break;
             case 4: if (L->prim){
                        novo=(No*)malloc(sizeof(No));
                        if (!novo) return(0);
                        novo->info=Info;
                        novo->ant=L->ult;
                        novo->prox=NULL;
                        L->ult->prox=novo;
                        L->ult=novo;
                     }
                     else Insert(1,L,Info);
                     return(1);
             break;
      }
}
//------------------------------------------------------------------------------

// Função para remoção da lista
short Remove(Lista *L,int Info)
{
      No *elem;
      
      if(!Search(0,&elem,L,Info)) return(0);
      if (L->prim==L->ult)
         Start(L);
      else if (elem==L->ult){
              L->ult=L->ult->ant;
              free(L->ult->prox);
              L->ult->prox=NULL;
           }
           else if (elem==L->prim){
                   L->prim=L->prim->prox;
                   L->prim->ant=NULL;
                   free(elem);
                }
                else{
                     elem->ant->prox=elem->prox;
                     if (elem->prox) elem->prox->ant=elem->ant;
                     free(elem);
                }
      return(1);
}
//------------------------------------------------------------------------------

// Função para busca na lista
int Search(int Set, No **Elem, Lista *L, int Info)
{
    No *busca;
    int i=1;
    
    switch (Set){
           case 0: for (busca=L->prim,i=1;busca;busca=busca->prox,i++)
                       if (busca->info==Info){
                          *Elem=busca;
                          return(i);
                       }
           break;
           case 1: for (busca=L->prim;busca;busca=busca->prox)
                       if (busca->info>=Info){
                          *Elem=busca;
                          return(1);
                       }
           break;
           case 2: for (busca=L->prim,i=1;busca;busca=busca->prox,i++)
                       if (i==Info){
                          *Elem=busca;
                          return(1);
                       }
           break;
    }
    *Elem=NULL;
    return(0);
}
//------------------------------------------------------------------------------

// Função para impressão da lista
void Print(Lista *L)
{
     No *elem;
     
     for (elem=L->prim;elem;elem=elem->prox)
         printf("| %d |",elem->info);
     return;
}            
//------------------------------------------------------------------------------

// Função auxiliar para captura de parâmetro extra
void CAux(int *Aux)
{
 printf("Insira a posicao: ");
 fflush(stdin);
 scanf("%d",&(*Aux));
 return;
}
//------------------------------------------------------------------------------
