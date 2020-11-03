/*
*/
#include <stdio.h>
#include <stdlib.h>

#define OM 10 // Define a ordem da matriz (default: 20)

//==============================================================================      

typedef struct // Estrutura que define a orienta��o de linha e coluna da c�lula.
{
 int i;
 int j;
} PosCel;

typedef struct Reg No; // Define o tipo de dado No.

struct Reg // Estrutura que armazena os dados (Registro).
{
 int Info; // Informa��o da c�lula.
 PosCel Pos; // Posi��o da linha e coluna.
 No *prox_dir; // Ponteiro para o "n�" a direita.
 No *prox_inf; // Ponteiro para o "n�" inferior.
};

typedef struct // Estrutura que indica a primeira e a �ltima c�lula.
{
 No *prim; // Ponteiro para o primeiro elemento da coluna ou lista.
 No *ult; // Ponteiro para o �ltimo elemento da coluna ou lista.
} Cel;

typedef struct // Tipo de dado matriz de ordem OM.
{
 Cel Col[OM];
 Cel Lin[OM];
} Matriz;
//==============================================================================

void Menu(Matriz *M);
void Iniciar_Matriz(Matriz *M);
short Inserir_No(Matriz *M, int Info, PosCel Pos);
short Remover_No(Matriz *M, PosCel Pos);
short Buscar_No(Matriz *M, PosCel Pos, int *S);
void Somar_Matriz(Matriz *M, PosCel Pos, int Op, int *S);
void Perm_LC_Matriz(Matriz *M, int Op, PosCel Pos);
void Mult_LC_Matriz(Matriz *M, int Op, PosCel Pos, int K);
void Imprimir_Matriz(Matriz *M);

