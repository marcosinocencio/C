#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct no{
int valor;
struct no *prox;
};

typedef struct no *tno;


void teste2(tno *v){ //PODE SER TANTO DEFINIDO COMO *V OU V[]
int j;

    printf("\n\nCHAMADA DE ANULAMENTO FORA DA FUNCAO:\n\n");
    for(j=0;j<5;j++){
    free(*v);
    *v = NULL;
    }


}

void teste3(tno *v){
int j;


    printf("CHAMADA DE IMPRESSAO FORA DA FUNCAO:\n\n");
    for(j=0;j<5;j++){
    printf("\n[%d] -> %d",j,v[j]->valor);
    }
}

int main(void){
tno v[5];
int i;

    for(i=0;i<5;i++){
    v[i] = (tno) malloc(sizeof(tno));
    v[i]->valor = i*10;
    }

    printf("CHAMADA DE IMPRESSAO DENTRO DA FUNCAO:\n\n");
    for(i=0;i<5;i++){
    printf("\n[%d] -> %d",i,v[i]->valor);
    }

    teste2(&v[0]);


}
