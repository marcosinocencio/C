#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 5;

struct no{
int valor;
struct no *prox;
};

typedef struct no tno;



void iniciaVetor(tno *v[]);
void teste(tno *v[]);
