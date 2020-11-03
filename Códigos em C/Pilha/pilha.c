#include "TadPilha.h"
#include <stdio.h>
#include <stdlib.h>

void IniciarPilha(TPilha *Pilha){
Pilha->Topo = NULL;
}

void Empilha(TPilha *Pilha, int Elemento){
TNo NovoNo;

    NovoNo = (TNo) malloc(sizeof(TNo));
    NovoNo->Valor = Elemento;
    
    if(Pilha->Topo == NULL){
    NovoNo->Prox = NULL;
    }
    else{
    NovoNo->Prox = Pilha->Topo;
    } 
    Pilha->Topo = NovoNo;
}

void Desempilha(TPilha *Pilha){
TNo AntigoNo;

    AntigoNo = Pilha->Topo;
    Pilha->Topo = AntigoNo->Prox;
    free(AntigoNo);
}

void ImprimePilha(TPilha *Pilha){
TNo AtualNo;
int Posi=0;

    printf("\n\n");
    AtualNo = Pilha->Topo;
    while(AtualNo != NULL){
    printf("\nPosicao: %d -> Valor: %d",Posi,AtualNo->Valor);
    Posi++;
    AtualNo=AtualNo->Prox;
    }
    
}
