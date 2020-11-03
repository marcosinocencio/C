#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define ESP printf("               ");


typedef struct elemento* Lista;

struct elemento{
       Lista pc,pl;
       int i,j,valor;
       };
       
       
       
void coloca_valor(int valor, int i, int j, Lista *Linha, Lista *Coluna);
void Inicializar_Lista(Lista *linCol);
void imprimir_matriz(Lista *Linha);
int busca_elem(Lista *Linha, int busca);
