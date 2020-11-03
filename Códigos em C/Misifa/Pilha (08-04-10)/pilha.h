/* -----------------------------------------------------------------------------
@copyright Luiz Paulo Rabachini @file: lista.h
Release: 1.5 - Updated: 21/04/2010
--------------------------------------------------------------------------------
Resume: Header do arquivo pilha.c
------------------------------------------------------------------------------*/

#define MAX 20 // Tamanho máximo da pilha

typedef struct
{
 int Pilha[MAX];
 int topo;
 int base;
} Pilha;

// Escopo das funções
void Start(Pilha *P);
short Insert(Pilha *P, int Info);
short Remove(Pilha *P, int *Info);
int Size(Pilha *P);
int Search(Pilha *P, int Info);
void Print(Pilha *P);
//------------------------------------------------------------------------------

void CapFunc(char *Funcao);
short StrIn(Pilha *P, char *Funcao, int *Res);
short Operacao(Pilha *P, char C);
short Operar(Pilha *P, int Set);

//------------------------------------------------------------------------------
