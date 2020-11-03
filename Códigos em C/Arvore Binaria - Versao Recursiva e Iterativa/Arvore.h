#include <stdlib.h>
#include <stdio.h>
#define ESP printf("             ");


typedef struct No *PontNo;

struct No{
       int valor;                                         //valor!
       PontNo direita, esquerda;                          //ponteiros!!!
       };

void coloca(PontNo *raiz,int valor);
void  elemina_elemento(PontNo *pontraiz,int valor);
void Imprimir_pre(PontNo raiz);
void Imprimir_em(PontNo raiz);
void Imprimir_pos(PontNo raiz);
void procurar(PontNo raiz, int valor,char inicio);
void coloca_it(PontNo *primeiro, int valor);
void procura_it(PontNo *raiz,int valor);
