/*
@copyright Luiz Paulo Rabachini @file: listadinamica.h
Release: 1.8 - Updated: 15/04/2010
---
Resume: Header do arquivo listadinamica.c
*/

typedef struct Reg No;

struct Reg{
       int info;
       No *prox;   
};

typedef struct{
        No *prim;
        No *ult;
} Lista;

void StartLista(Lista *L);
int Search(Lista *L, int Op, int Index, No **Ant, No **Pos);
short Insert(Lista *L, int Info, int Index, int Op);
short Remove(Lista *L, int Info);
void Print(Lista *L);
void Invert(No **A);
