#include "TadFila.h"
#include <stdio.h>
#include <stdlib.h>



void IniciaFila(TFila *Fila){
Fila->Inicio = NULL; //Como a fila esta vazia então o inicio não aponta para ninguém
Fila->Fim = NULL; //Logo o fim também não aponta para ninguém
}

void InsereFila(TFila *Fila,int Elemento){
TNo NovoNo;

    NovoNo = (TNo) malloc(sizeof(TNo)); // Aloco o novo item na memoria
    NovoNo->Valor = Elemento;
    
    if(Fila->Inicio == NULL){ //Como o início não aponta para ninguém então a lista está vazia
    Fila->Fim    = NovoNo; //Como ele acabou de ser inserido ele é o último, logo o fim aponta para ele
    Fila->Inicio = NovoNo; //Como a lista está vazia e ele acabou de ser inserido então o início também deverá apontar para ele
    }
    else{ //Se entrou nesta parte do laço então a lista não está vazia
    NovoNo->Prox = NULL; //O novo item alocado não deverá apontar para ninguém visto que é o último, então não apontará para nada
    Fila->Fim->Prox = NovoNo; //O ex-fim agora aponta para este último item inserido    
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
    Fila->Inicio = NovoNo->Prox; //O Início agora aponta para o segundo elemento
    free(NovoNo);
    }
    
}

int ImprimeFila(TFila *Fila){
TNo NovoNo;
int Posicao=0;
      
      
      printf("\n\n");
      NovoNo = Fila->Inicio;//O primeiro item a ser examinado será o primeiro elemento da fila
      if(Fila->Inicio == NULL) return 0;
      else{
     
            while(NovoNo != NULL){                        
            printf("\nPosicao: %d -> Valor: %d",Posicao,NovoNo->Valor);            
            NovoNo = NovoNo->Prox;//Faz o NovoNo agora apontar para o próximo da fila             
            Posicao++;
            }
      
      }
      return 1;
}
