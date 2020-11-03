#include <stdio.h>
#define MAX 20
#define Arq "Lista.reg"

// Estrutura do tipo registro;
// info: Informação armazenada; prox: Indica o próximo elemento da lista;
typedef struct{
       int info;
       int prox;
} Reg;
//------------------------------------------------------------------------------

// Estrutura do tipo Lista que armazena estruturas do tipo Reg;
// dispo: Indica uma posição disponível; prim: Indica o primeiro elemento;
typedef struct{
        int dispo;
        int prim;
        //struct Reg l[MAX];
} RegIndex;
//------------------------------------------------------------------------------

// Escopo das funções;
int Menu(FILE *fptr);
short Insert(int Info, FILE *fptr, int OP, int Index);
void Segmentar(FILE *fptr);
short Remove(int Info, FILE *fptr);
int Search(int Info, FILE *fptr);
int SearchFinal(FILE *fptr);
void CreatLista(FILE *fptr);
void Print(FILE *fptr, int OP);
//------------------------------------------------------------------------------
