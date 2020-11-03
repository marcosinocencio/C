/*
*/

// Headers ------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "listascruzadas.h"
//---------------------------------------------------------------

// Inicializa a matriz ------------------------------------------
void StartMatriz(Matriz *M){
     M->primc=M->priml=NULL;
     M->tmax.x=M->tmax.y=0;
     return;
}

// Cria a matriz de tamanho X x Y -------------------------------
void CriarLista(Matriz *M, int X, int Y){
     M->tmax.x=X;
     M->tmax.y=Y;
     return;
}

// Insere na matriz ----------------------------------------------
short InserirElemento(Matriz *M, int Valor, int X, int Y){
      No *elem, *aux1, *aux2;      
      
      if ((X > M->tmax.x)||(Y > M->tmax.y)) return 0;
      elem=(No*)malloc(sizeof(No));
      if (!elem) return 0;
      elem->valor=Valor;
      if (!M->primc){
         M->primc=elem;
         M->priml=elem;
         elem->proxl=elem->proxc=NULL;
         return 1;
      }
      for (aux1=M->primc, aux2=aux1; aux2; aux1=aux2, aux2=aux2->proxc)
          if (aux2->pos.x > X){
             elem->proxc=aux2;
             if (aux1 == M->primc) aux1=elem;
             else aux1->proxc=elem;  
             break;
          }
      if (!aux2){
         aux1->proxc=elem;
         elem->proxc=NULL;
      }
      for (aux1=M->priml, aux2=aux1; aux2; aux1=aux2, aux2=aux2->proxl)
          if (aux2->pos.y > Y){
             elem->proxl=aux2;
             if (aux1 == M->priml) aux1=elem;
             else aux1->proxl=elem;  
             break;
          }
      if (!aux2){
         aux1->proxl=elem;
         elem->proxl=NULL;
      }
      return 1;      
}

/*/ Remove da matriz ----------------------------------------------
short RemoverElemento(){
}

// Busca na matriz ------------------------------------------------
short BuscarElemento(){
}*/

// Imprime a matriz -----------------------------------------------
void ImprimirMatriz(Matriz *M){
     int x=0, y=0;
     No *aux;
     
     for (x=0; aux=M->priml; aux; x++){
         if (x < aux->pos)
            printf("0 ");
         else{
              print("%d ", aux->valor);
              aux=aux->proxc
         }
     }
}
//-----------------------------------------------------------------
