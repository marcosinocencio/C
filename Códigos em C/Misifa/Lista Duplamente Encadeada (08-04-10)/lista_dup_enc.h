/*
------------------------------------------------------
@copyright Luiz Paulo Rabachini @file: lista_dup_enc.h
Release: 1.4 - Updated: 20/04/2010
------------------------------------------------------
Resume: Header do arquivo lista_dup_enc.c
------------------------------------------------------
*/

typedef struct Reg No;

// Definição da estrutura de cada Nó
struct Reg
{
 int info;
 No *ant;
 No *prox;       
};

// Definição do TAD Lista
typedef struct
{
 No *prim;
 No *ult;
} Lista;

// Escopos das funções
void Start(Lista *L);
void Menu(Lista *L);
short Insert(int Set, Lista *L, int Info);
short Remove(Lista *L,int Info);
int Search(int Set, No **Elem, Lista *L, int Info);
void Print(Lista *L);
void CAux(int *Aux);
