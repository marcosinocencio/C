#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "hash1.h"


int qtd = 5;

void iniciaVetor(tno *v[]){
int i=0;

    for(;i<qtd;i++){
    v[i]->prox = NULL;
    }

    for(;i<qtd;i++){
    printf("\n[%d] = %d",i,v[i]->prox);
    }

}

void teste(tno *v[]){
v[1]->prox;

printf("\n\n%d",v[1]->prox);
}
