#include "arvore_binaria.h"

// Fun��o de Menu --------------------------------------------------------------
void Menu(Arvore *M)
{
 int op = 0;
 char cont;
 
 do{
    system("cls");
    printf(":: Arvore Binaria v1.0 ::\n\n");
    printf("-> Selecione uma opcao\n\n");
    printf("[1] Inserir elemento\n");
    printf("[2] Remover elemento\n");
    printf("[3] Buscar elemento\n");
    printf("[4] Imprimir arvore\n");
    printf("[0] Sair\n\n");
    printf("Opcao: ");
    scanf("%d", &op);
    switch (op){
           case 1: 
           break;
           case 2: 
           break;
           case 3: 
           break;
           case 4: 
           break;
           case 0: return;
           }
    printf("\nDeseja continuar? (s/n)");
    fflush(stdin);
    cont = getchar();
 }while((cont=='s')||(cont=='S'));
 return;
}

// Fun��o de inicializa��o da �rvore -------------------------------------------
void Iniciar_Arvore(Arvore *A)
{
 A->raiz = NULL;
 return;
}

// Fun��o de inicializa��o da fila ---------------------------------------------
void Iniciar_Fila(Fila *F)
{
 F->prim = NULL;
 F->ult = NULL;
}

// Fun��o de inser��o em fila --------------------------------------------------
short Inserir_No_Fila(Fila *F, No *N)
{
 NoF *f = NULL;
 
 f = (NoF*)malloc(sizeof(NoF));
 if (f == NULL)
    return 0;
 f->elem = N;
 f->prox = NULL;
 if (!F->prim)
    F->prim = F->ult = f;
 else{
      F->ult->prox = f;
      F->ult = f;
 }
 return 1;
}
// Fun��o para inser��o na �rvore ----------------------------------------------
short Inserir_No(Arvore *A, int Info, const int No_P, short E_D)
{
 No **no_aux = NULL;
 No *novo_no = NULL;
 
 if (Buscar_No_Arvore(A->raiz, *no_aux, 1, No_P))  
    if (E_D)
       if ((*no_aux)->prox_d)
          return 0;
       else{
            novo_no = (No*)malloc(sizeof(No));
            novo_no->Info = Info;
            novo_no->prox_e = NULL;
            novo_no->prox_d = NULL;
            (*no_aux)->prox_d = novo_no;
       }
    else
        if ((*no_aux)->prox_e)
           return 0;
        else{
            novo_no = (No*)malloc(sizeof(No));
            novo_no->Info = Info;
            novo_no->prox_e = NULL;
            novo_no->prox_d = NULL;
            (*no_aux)->prox_e = novo_no;
       }
 return 1;
}

// Fun��o para remo��o da �rvore -----------------------------------------------
// N�o implementada

// Fun��o para busca na �rvore -------------------------------------------------
short Buscar_No_Arvore(No *No_A, No *No_S, int N, const int No_P)
{
 if (No_A == NULL)
    return 0;
 else
      if (N == No_P){
         *No_S = *No_A;
         return 1;
         }
      else
          if (Buscar_No_Arvore(No_A->prox_e, No_S, 2 * N, No_P))
             return 1;
          else
               if (Buscar_No_Arvore(No_A->prox_d, No_S, 2 * N + 1, No_P))
                  return 1;
               else
                   return 0; 
}

/* Fun��o de verifica��o do n�vel do n� ----------------------------------------
int Verificar_Nivel_No(No *No_A, int Nivel, int N, const int No_P)
{
 if (No_A == NULL)
    return 0;
 else
      if (N == No_P){
         *No_S = *No_A;
         return Nivel;
         }
      else
          if (Verificar_Nivel_No(No_A->prox_e, Nivel + 1, 2 * N, No_P) > 0)
             return Nivel;
          else
               if (Verificar_Nivel_No(No_A->prox_d, Nivel + 1, 2 * N + 1, No_P) > 0)
                  return Nivel;
               else
                   return -1; 
}
*/
// Fun��o para verifica��o do grau de determinado "n�" -------------------------
int Verificar_Grau_No(No *No_A, const int No_P)
{
 No no_aux;
 int grau = 0;
 
 if (Buscar_No_Arvore(&(*No_A), &no_aux, 1, No_P)){  
       if (no_aux.prox_d)
          grau++;
       if (no_aux.prox_e)
          grau++;
       return grau;
 }
 else
     return -1;
}

// Percurso Em-Ordem ou Profundidade -------------------------------------------
void Percurso_PreOrdem_Arvore(No *No_A)
{
 if (No_A == NULL)
    return;
 else{
      printf("%d ", No_A->Info);
      Percurso_PreOrdem_Arvore(No_A->prox_e);
      Percurso_PreOrdem_Arvore(No_A->prox_d);
      return; 
 }  
}

// Percurso Em-Ordem ou Ordem Sim�trica ---------------------------------------- 
void Percurso_EmOrdem_Arvore(No *No_A)
{
 if (No_A == NULL)
    return;
 else{
      Percurso_EmOrdem_Arvore(No_A->prox_e);
      printf("%d ", No_A->Info);
      Percurso_EmOrdem_Arvore(No_A->prox_d);
      return; 
 }  
}

// Percurso P�s-Ordem ---------------------------------------------------------- 
void Percurso_PosOrdem_Arvore(No *No_A)
{
 if (No_A == NULL)
    return;
 else{
      Percurso_PosOrdem_Arvore(No_A->prox_e);
      Percurso_PosOrdem_Arvore(No_A->prox_d);
      printf("%d ", No_A->Info);
      return; 
 }  
}

// Fun��o que determina a profundidade de uma �rvore ---------------------------
void Verificar_Prof_Arvore(No *No_A, int P, int *Prof)
{
 if (No_A == NULL)
    return;
 else{
      Verificar_Prof_Arvore(No_A->prox_e, P + 1, Prof);
      Verificar_Prof_Arvore(No_A->prox_d, P +  1, Prof);
      if (P >= *Prof)
         *Prof = P;
      return; 
 } 
}

// Fun��o que "empacota" um n�vel da �rvore em uma fila ------------------------
void Empacotar_Arvore(No *No_A, int N, int Nivel, Fila *F)
{
if ((No_A == NULL)||(N > Nivel))
    return;
 else
      if (N == Nivel){
         Inserir_No_Fila(&(*F), No_A);
         return;
      }
      else{
          Empacotar_Arvore(No_A->prox_e, N+1, Nivel, &(*F));
          Empacotar_Arvore(No_A->prox_d, N+1, Nivel, &(*F));
          return;
      }  
}

// Fun��o de impress�o da fila -------------------------------------------------
void Imprimir_Fila(Fila *F)
{
 NoF *f = NULL;
 
 for (f = F->prim; f; f = f->prox)
     printf("%d ", f->elem->Info);
 printf("\n\n");
 return;
}
