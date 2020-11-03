#include <stdio.h>
#include <stdlib.h>
#include "tadexparsa.h"


void IniciarMatriz(Tmatriz *Matriz){
int x;

    for(x=0;x<MAX;x++){
    Matriz->Linha[x]  = NULL;
    Matriz->Coluna[x] = NULL;
    }

}

void ImprimeMatriz(Tmatriz *Matriz){
int x,y;
Tno *aux;

//Para imprimir a matriz, fixo a linha e vario a coluna

    for(x=0;x<MAX;x++){
    printf("\n");

     aux = Matriz->Linha[x];

     for(y=0;y<MAX;y++){

        if(aux != NULL){

              if (aux->coluna == y)
              {
              printf("%d ",aux->valor);
              aux = aux->proxcoluna;
              }
              else   printf("0 ");
        }
        else printf("0 ");
     }


    }
}

void InsereMatriz(Tmatriz *Matriz,int linha, int coluna,int num){
Tno *NovoNo, *NoAtual, *NoAnterior;

    NovoNo = (Tno*) malloc(sizeof(Tno));
    NovoNo->valor = num;
    NovoNo->linha = linha;
    NovoNo->coluna = coluna;

    //INSERINDO NA COLUNA CORRETA
    NoAtual = Matriz->Coluna[coluna];
    if(Matriz->Coluna[coluna]== NULL)NovoNo->proxcoluna = NULL;
    else{
    printf("A");


        while((NoAtual->coluna < linha)&&(NoAtual->proxcoluna != NULL)){
        printf("B");
        NoAnterior = NoAtual;
        NoAtual = NoAtual->proxcoluna;
        }

        //arrumar aqui
        if(NoAnterior == NULL) { Matriz->Coluna[coluna]= NovoNo; NovoNo->proxlinha = NoAtual; }
        else if (NoAtual != NULL) {
        NoAnterior->proxlinha = NovoNo;
        NovoNo->proxlinha = NoAtual;
        }
        else NoAnterior->proxlinha = NovoNo;


    }


}
