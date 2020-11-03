#include <stdio.h>
#include <stdlib.h>
#include "candidate.h"

#define MAX=200

int Menu();

int Menu(){
     int i=0;
     bool aux=false;
     
     do{
        printf(":: Escolha a operacao desejada ::\n\n");
        printf("[1] Pesquisa de candidato\n");
        printf("[2] Insercao de candidato\n");
        printf("[3] Remocao de candidato\n");
        printf("[4] Alteracao de candidato\n\n");
        scanf("%d",&i);
        if ((i<1)||(i>4)){
           aux=false;
           printf("Opcao nao encontrada\n\n");
           system("pause");
        }
        else aux=true;
     }while(aux);
     return();
}

int main(void){
    //candidate C[200];   
    
    //ClearCandidate(C,MAX);
    return(0);
}
