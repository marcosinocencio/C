#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct no{
int valor;
struct no *prox;
};

typedef struct no tno;

void teste(tno *ve){
int j;

    printf("\n\nIMPRESSAO FORA DA FUNCAO");
    for(j=0;j<5;j++){
    printf("\n%d",ve[j].valor);
    }

    printf("\n\nIMPRESSAO FORA DA FUNCAO 2");
    for(j=0;j<5;j++){
    printf("\n%d",ve[j].prox->valor);
    }

}

int main(void){
tno v[5];
int i;

for(i=0;i<5;i++){
v[i].valor = i*10;
v[i].prox = (tno*) malloc(sizeof(tno));
v[i].prox->valor = 2;
}

printf("IMPRESSAO DENTRO DA FUNCAO");
for(i=0;i<5;i++){
printf("\n%d",v[i].valor);
}


printf("\n\nIMPRESSAO DENTRO DA FUNCAO 2");
for(i=0;i<5;i++){
printf("\n%d",v[i].prox->valor);
}

teste(&v[0]);

}
