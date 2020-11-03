#include <stdio.h>
#define MAX 20
#define Arq "Lista.reg"

// Estrutura do tipo registro;
// info: Informa��o armazenada; prox: Indica o pr�ximo elemento da lista;
typedef struct{
       int info;
       int prox;
} Reg;
//------------------------------------------------------------------------------

// Estrutura do tipo Lista que armazena estruturas do tipo Reg;
// dispo: Indica uma posi��o dispon�vel; prim: Indica o primeiro elemento;
typedef struct{
        int dispo;
        int prim;
        //struct Reg l[MAX];
} RegIndex;
//------------------------------------------------------------------------------

// Escopo das fun��es;
int Menu(FILE *fptr);
short Insert(int Info, FILE *fptr, int OP, int Index);
void Segmentar(FILE *fptr);
short Remove(int Info, FILE *fptr);
int Search(int Info, FILE *fptr);
int SearchFinal(FILE *fptr);
void CreatLista(FILE *fptr);
void Print(FILE *fptr, int OP);
//------------------------------------------------------------------------------
