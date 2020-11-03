#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct no{
int coluna;
int linha;
int valor;
struct no *proxlinha;
struct no *proxcoluna;
};
typedef struct no Tno;

struct matriz{
Tno *Linha[MAX];
Tno *Coluna[MAX];
};

typedef struct matriz Tmatriz;

void InsereMatriz(Tmatriz *Matriz,int linha, int coluna,int num);
void ExcluiMatriz(int linha, int coluna, int valor);
void ImprimeMatriz(Tmatriz *Matriz);
void IniciarMatriz(Tmatriz *Matriz);
