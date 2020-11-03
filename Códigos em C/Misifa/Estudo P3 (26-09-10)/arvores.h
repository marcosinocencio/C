/*
  Estruturas de Dados
  Implementação dos exercícios propostos para estudo P3
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ElemA NoA; // Elemento de arvore

struct ElemA // Estrutura do elemento de arvore
{
 int key;
 int info;
 int fb;
 NoA *prox_d;
 NoA *prox_e;
};

typedef struct // Definição da estrutura de árvore binária.
{
 NoA *raiz;
} Arvore;

typedef struct ElemF NoF; // Elemento de fila

struct ElemF // Estrutura do elemento de fila
{
 NoF *prox;
 NoA *elem;
};

typedef struct // Definição da estrutura de fila para auxiliar na arvore
{
 NoF *prim;
 NoF *ult;
} Fila;

//Declaração de funções
void Menu(NoA *No_A);
void Iniciar_Arvore(NoA *No_A);
void Deletar_Arvore(NoA *No_A);
short Inserir_No_Arvore(NoA *No_A, int Key, int Info);
short Buscar_No_Arvore(int Key, NoA *No_P, NoA *No_B, NoA **No_S);
short Remover_No_Arvore(NoA **No_R, int Key);
void Calc_Alt_No_Arvore(NoA *No_CA, int ALT);
int Calc_FB_No_Arvore(NoA *No_CFB);
void Bal_AVL_Arvore(NoA **No_R);
void Rot_No_Arvore_Dir(NoA **No_Rot);
void Rot_No_Arvore_Esq(NoA **No_Rot);
void Iniciar_Fila(Fila *F);
void Deletar_Fila(Fila *F);
short Inserir_No_Fila(Fila *F, NoA *No_A);
short Retirar_No_Fila(Fila *F, NoA *No_A);
short Fila_Vazia(Fila *F);
void Print_Arvore(NoA *No_A, int Op);
void Percurso_PreOrdem_Arvore(NoA *No_A);
void Percurso_PosOrdem_Arvore(NoA *No_A);
void Percurso_EmOrdem_Arvore(NoA *No_A);
