#include <stdlib.h>
#include <stdio.h>
#define MAX 10                                             //numero de elemento na lista
#define ESP printf("             ");


typedef struct no* Linha;

struct no{
       Linha prox;            
       int valor;
       };


int gera_valor( int valor);
void coloca_elemento(Linha *Ponteiros,int valor);
void Inicializar_Lista(Linha *linCol);
void imprime_toda(Linha *Ponteiro);
void Excluir(Linha *Ponteiros,int valor);
void Busca(Linha *Ponteiro,int valor);
