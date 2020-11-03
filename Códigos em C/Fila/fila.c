#include "TadFila.h"
#include <stdio.h>
#include <stdlib.h>



void IniciaFila(TFila *Fila){
Fila->Inicio = NULL; //Como a fila esta vazia ent�o o inicio n�o aponta para ningu�m
Fila->Fim = NULL; //Logo o fim tamb�m n�o aponta para ningu�m
}

void InsereFila(TFila *Fila,int Elemento){
TNo NovoNo;

    NovoNo = (TNo) malloc(sizeof(TNo)); // Aloco o novo item na memoria
    NovoNo->Valor = Elemento;
    
    if(Fila->Inicio == NULL){ //Como o in�cio n�o aponta para ningu�m ent�o a lista est� vazia
    Fila->Fim    = NovoNo; //Como ele acabou de ser inserido ele � o �ltimo, logo o fim aponta para ele
    Fila->Inicio = NovoNo; //Como a lista est� vazia e ele acabou de ser inserido ent�o o in�cio tamb�m dever� apontar para ele
    }
    else{ //Se entrou nesta parte do la�o ent�o a lista n�o est� vazia
    NovoNo->Prox = NULL; //O novo item alocado n�o dever� apontar para ningu�m visto que � o �ltimo, ent�o n�o apontar� para nada
    Fila->Fim->Prox = NovoNo; //O ex-fim agora aponta para este �ltimo item inserido    
    Fila->Fim = NovoNo; //O Fim da fila agora aponta para o ultimo elemento inserido
    }

}

int DeletaDaFila(TFila *Fila){
TNo NovoNo, NoAnterior;
    
    if(Fila->Inicio == Fila->Fim){
    free(Fila->Inicio);
    Fila->Inicio = NULL;
    Fila->Fim = NULL;
    }
    else{
    NovoNo = Fila->Inicio;
    Fila->Inicio = NovoNo->Prox; //O In�cio agora aponta para o segundo elemento
    free(NovoNo);
    }
    
}

int ImprimeFila(TFila *Fila){
TNo NovoNo;
int Posicao=0;
      
      
      printf("\n\n");
      NovoNo = Fila->Inicio;//O primeiro item a ser examinado ser� o primeiro elemento da fila
      if(Fila->Inicio == NULL) return 0;
      else{
     
            while(NovoNo != NULL){                        
            printf("\nPosicao: %d -> Valor: %d",Posicao,NovoNo->Valor);            
            NovoNo = NovoNo->Prox;//Faz o NovoNo agora apontar para o pr�ximo da fila             
            Posicao++;
            }
      
      }
      return 1;
}
