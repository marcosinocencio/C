#include <stdio.h>
#include <conio.h>


void teste2(int *v){ //PODE SER TANTO DEFINIDO COMO *V OU V[]
int i;

    printf("\n\nCHAMADA DE IMPRESSAO FORA DA FUNCAO:\n\n");
    for(i=0;i<5;i++){
    printf("\n[%d] -> %d",i,v[i]);
    }

}

int main(void){
int v[5], i;

    for(i=0;i<5;i++){
    v[i] = i*10;
    }

    printf("CHAMADA DE IMPRESSAO DENTRO DA FUNCAO:\n\n");
    for(i=0;i<5;i++){
    printf("\n[%d] -> %d",i,v[i]);
    }

    teste2(&v[0]);

}
