#include <stdio.h>
#include <stdlib.h>

//==============================================================================

typedef struct ElemA No;

struct ElemA // Definição da estrutura de cada "nó".
{
 int Info;
 No *prox_d;
 No *prox_e;
};

typedef struct // Definição da estrutura de árvore binária.
{
 No *raiz;
} Arvore;

typedef struct ElemF NoF;

struct ElemF
{
 NoF *prox;
 No *elem;
};

typedef struct // Definição da estrutura de fila.
{
 NoF *prim;
 NoF *ult;
} Fila;
//==============================================================================

void Menu(Arvore *A);
void Iniciar_Arvore(Arvore *A);
void Percurso_PreOrdem_Arvore(No *No_A);
void Percurso_EmOrdem_Arvore(No *No_A);
void Percurso_PosOrdem_Arvore(No *No_A);
short Inserir_No(Arvore *A, int Info, const int No_P, short E_D);
int Verificar_Grau_No(No *No_A, const int No_P);
void Verificar_Prof_Arvore(No *No_A, int P, int *Prof);
void Empacotar_Arvore(No *No_A, int N, int Nivel, Fila *F);
short Buscar_No_Arvore(No *No_A, No *No_S, int N, const int No_P);
void Imprimir_Arvore(No *no, int n, int nivel);

void Iniciar_Fila(Fila *F);
short Inserir_No_Fila(Fila *F, No *N);
void Imprimir_Fila(Fila *F);
