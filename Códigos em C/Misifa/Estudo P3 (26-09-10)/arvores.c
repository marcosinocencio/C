/*
  Estruturas de Dados
  Implementação dos exercícios propostos para estudo P3
*/

#include "arvores.h"

int AltA = 0;

void Menu(NoA *No_A)
{
 int op = 0;
 
 do {   
    printf (":: ESTRUTURAS DE DADOS ::\n\nImplementacao de Arvores\n\n");
    printf ("Estruturas disponiveis:\n\n");
    printf ("[1] Arvore Binaria\n");
    printf ("[2] Arvore Binaria de Busca\n");
    printf ("[3] Arvore AVL\n");
    printf ("[4] Arvore B\n");
    printf ("[5] Imprimir arvore\n");
    printf ("[0] Sair\n\n");
    printf ("Opcao: "); scanf ("%d", &op);
    switch (op){
           case 0: printf ("BYE!\n\n");
           break;
           case 1: printf ("BYE!\n\n");
           break;
           case 2: printf ("BYE!\n\n");
           break;
           case 3: printf ("BYE!\n\n");
           break;
           case 4: printf ("BYE!\n\n");
           break;
           case 5: printf ("Selecione o tipo de impressao\n");
                   printf ("[1]Impressao Pre Ordem\n[2]Impressao Pos Ordem\n[3]Impressao Em Ordem\n\
                   [4]Impressao Em Nivel\n[0]Impressão 'modo grafico'\n\n");
                   printf ("Opcao: "); scanf("%d", &op);
                   Print_Arvore (&(*No_A), op);
           break;
    }
    }while (1); // Laço para exibição do menu
}

// Função para impressão da árvore ---------------------------------------------
void Print_Arvore(NoA *No_A, int Op)
{ 
 switch (Op){     
        case 1: printf("Impressao Pre Ordem\n");
                Percurso_PreOrdem_Arvore(&(*No_A));       
        break;
        case 2: printf("Impressao Pos Ordem\n");
                Percurso_PosOrdem_Arvore(&(*No_A));       
        break;
        case 3: printf("Impressao Em Ordem\n");
                Percurso_EmOrdem_Arvore(&(*No_A));
        break; 
        case 4: printf("Impressao Em Nivel\n");
                //Percurso_EmNivel_Arvore(&(*No_A));
        break;
 }
}

// Percurso Em-Ordem ou Profundidade -------------------------------------------
void Percurso_PreOrdem_Arvore(NoA *No_A)
{
 if (No_A == NULL)
    return;
 else{
      printf("%d ", No_A->info);
      Percurso_PreOrdem_Arvore(No_A->prox_e);
      Percurso_PreOrdem_Arvore(No_A->prox_d);
      return; 
 }  
}

// Percurso Pós-Ordem ---------------------------------------------------------- 
void Percurso_PosOrdem_Arvore(NoA *No_A)
{
 if (No_A == NULL)
    return;
 else{
      Percurso_PosOrdem_Arvore(No_A->prox_e);
      Percurso_PosOrdem_Arvore(No_A->prox_d);
      printf("%d ", No_A->info);
      return; 
 }  
}

// Percurso Em-Ordem ou Ordem Simétrica ---------------------------------------- 
void Percurso_EmOrdem_Arvore(NoA *No_A)
{
 if (No_A == NULL)
    return;
 else{
      Percurso_EmOrdem_Arvore(No_A->prox_e);
      printf("%d ", No_A->info);
      Percurso_EmOrdem_Arvore(No_A->prox_d);
      return; 
 }  
}


// Percurso Em-Nivel -----------------------------------------------------------
void Percurso_EmNivel_Arvore(NoA *No_A)
{
 Fila f; // short Inserir_No_Fila(Fila *F, NoA *No_A)
 NoA no_a;
 
 if (No_A == NULL) return;
 no_a.info = 0;
 no_a.prox_d = NULL;
 no_a.prox_e = NULL;
 Iniciar_Fila(&f);
 Inserir_No_Fila(&f, &(*No_A));
 do{
    if(!Retirar_No_Fila(&f, &no_a)) return;
    printf("- %d", no_a.info);
    Inserir_No_Fila(&f, no_a.prox_e);
    Inserir_No_Fila(&f, no_a.prox_d);
 }while (Fila_Vazia(&f));  
 return;
}


// Função de inicialização da árvore -------------------------------------------
void Iniciar_Arvore(NoA *No_A)
{
 No_A = NULL;
 return;
}

// Função para destruir a arvore -----------------------------------------------
void Deletar_Arvore(NoA *No_A)
{
 if (No_A == NULL)
    return;
 else{
      Percurso_PosOrdem_Arvore(No_A->prox_e);
      Percurso_PosOrdem_Arvore(No_A->prox_d);
      free(No_A);
      return; 
 } 
}

// Inserir em árvore -----------------------------------------------------------
short Inserir_No_Arvore(NoA *No_A, int Key, int Info)
{
 if (No_A == NULL){
    No_A = (NoA*)malloc(sizeof(NoA));
    No_A->key = Key;
    No_A->info = Info;
    No_A->prox_d = NULL;
    No_A->prox_e = NULL;
    return 1;
 } 
 if (Key == No_A->key) return 0;
 else if (Key < No_A->key)
         if (No_A->prox_e) return(Inserir_No_Arvore(No_A->prox_e, Key, Info));
         else{
              NoA *no_a = NULL;
              no_a = (NoA*)malloc(sizeof(NoA));
              no_a->key = Key;
              no_a->info = Info;
              no_a->prox_d = no_a->prox_e = NULL;
              No_A->prox_e = no_a;
              return 1;
         }
      else if (No_A->prox_d) return(Inserir_No_Arvore(No_A->prox_d, Key, Info));
           else{
                NoA *no_a = NULL;
                no_a = (NoA*)malloc(sizeof(NoA));
                no_a->key = Key;
                no_a->info = Info;
                no_a->prox_d = no_a->prox_e = NULL;
                No_A->prox_d = no_a;
                return 1;
           }
}

// Remover da árvore -----------------------------------------------------------
// Algorítimo ridículo. Funciona mas é extremamente ineficiente
// Por exemplo, sempre modifico os ponteiros do pai, ao invés de só trocar os valores
// do nó a ser removido por um folha. Modificarei isso depois.
short Remover_No_Arvore(NoA **No_R, int Key)
{
 NoA **No_BR, **No_P = NULL, **No_Paux, **No_S = NULL, **No_Saux;
 No_BR = No_R; // Backup do nó raiz, caso o nó a ser retirado seja o raiz
 *No_P = NULL; // Conteúdo no ponteiro do nó pai é anulado
 if (Buscar_No_Arvore(Key, *No_P, *No_R, &(*No_S))){ // Busca do nó a ser excluído Buscar_No_Arvore(int Key, NoA *No_P, NoA *No_B, NoA **No_S)
    if (*No_P == NULL){ // se o pai for nulo, o nó encontrado só pode ser o raiz
       free(*No_P); // Exclui a raiz
       *No_BR = NULL; // Anula a raiz
       return 1;
    }
    // Substituição pelo nó mais a direita da esquerda
    if ((*No_S)->prox_e == NULL) // Verifica se o nó a esquerda é nulo
          if ((*No_S)->prox_d == NULL) // Verifica se o nó a direita é nulo
             // Esquerda e direita são nulos = nó folha
             // Verifica de que lado o filho está do pai
             if ((*No_P)->prox_e->key == Key){ 
                free(*No_S);
                (*No_P)->prox_e = NULL;
             }
             else{
                  free(*No_S);
                  (*No_P)->prox_d = NULL;
             }
             // Esquerda é nula mas direita não
          else
              // Verifica de que lado o filho está do pai
              if ((*No_P)->prox_e->key == Key){
                 (*No_P)->prox_e = (*No_S)->prox_d;
                 free(*No_S);
              }
              else{
                   (*No_P)->prox_d = (*No_S)->prox_d;
                   free(*No_S);
              }
    else
        if ((*No_S)->prox_d == NULL)
           // Direita é nula mas esquerda não
           // Verifica de que lado o filho está do pai
           if ((*No_P)->prox_e->key == Key){
                  (*No_P)->prox_e = (*No_S)->prox_e;
                  free(*No_S);
               }
           else{
                (*No_P)->prox_d = (*No_S)->prox_e;
                free(*No_S);
           }
        // Nem esquerda e nem direita são nulos
        else{
             *No_Paux = *No_S; // Auxiliar pega o nó a ser retirado como pai
             *No_Saux = (*No_Paux)->prox_e; // Auxiliao do nó a ser substituído começa a correr para a direita da esquerda do nó pai acima
             for (;;){ // Laço corre os nós candidatos a substituirem o nó a ser removido
                 if ((*No_Saux)->prox_d == NULL) break; // quebra o laço antes de anular o ponteiro
                 *No_Paux = *No_Saux; // Vai salvando os pais em cada nível
                 *No_Saux = (*No_Saux)->prox_d; // Corre o ponteiro para a direita de cada nó
             }
             (*No_S)->key = (*No_Saux)->key; // Muda a chava
             (*No_S)->info = (*No_Saux)->info; // Muda a info
             if ((*No_Paux)->prox_e->key == (*No_Saux)->key) (*No_Paux)->prox_e = NULL; // Verifica se o nó encontrado não está a esquerda do pai
             else (*No_Paux)->prox_d = NULL; // Anula o lado certo do pai
             free(*No_Saux);
        }
 }   
 else return 0;
}

// Busca elemento na arvore ----------------------------------------------------
short Buscar_No_Arvore(int Key, NoA *No_P, NoA *No_B, NoA **No_S)
{// No_P, que é o nó pai, deve entrar nulo para a função
 if (!No_B) return 0; // Se o nó de entrada (raíz) da busca for nulo, retorna 0
 if (No_B->key == Key){ // Verifica se a Key de busca foi encontrada
    *No_S = No_B; // Caso verdade, atribui o nó em que a busca está ao nó de saída
    return 1;
 }
 if (No_B->key < Key){ // Se a Key for menor, vai para esquerda
    No_P = No_B; // Nó pai guarda a nó atual
    return(Buscar_No_Arvore(Key, &(*No_P), No_B->prox_e, &(*No_S))); // Busca o nó a esquerda
 }
 else{
      No_P = No_B; // Nó pai guarda a nó atual
      return(Buscar_No_Arvore(Key, &(*No_P), No_B->prox_d, &(*No_S))); // Busca o nó a direita
 }
}

// Cálculo do fator de balanceamento de cada nó --------------------------------
void Calc_Alt_No_Arvore(NoA *No_CA, int ALT)
{// Devemos garantir que ALT (altura da árvore) entre com valor 0
 if (No_CA == NULL){
    if (ALT > AltA) AltA = ALT;
    return;
 }
 else{
      Calc_Alt_No_Arvore(No_CA->prox_e, ALT + 1);
      Calc_Alt_No_Arvore(No_CA->prox_d, ALT + 1);
      return; 
 }   
}

int Calc_FB_No_Arvore(NoA *No_CFB)
{
 int alt_e = 0, alt_d = 0;
 
 Calc_Alt_No_Arvore(No_CFB->prox_e, 0);
 alt_e = AltA;
 Calc_Alt_No_Arvore(No_CFB->prox_d, 0);
 alt_d = AltA;
 return (alt_d - alt_e);
}

void Bal_AVL_Arvore(NoA **No_R)
{
 if ((*No_R)->fb < -1){
 // Giro para a direita
    if ((*No_R)->prox_e->fb != (*No_R)->fb)
       Bal_AVL_Arvore(&((*No_R)->prox_e));
    if ((*No_R)->prox_d->fb != (*No_R)->fb)
       Bal_AVL_Arvore(&((*No_R)->prox_d));
    Rot_No_Arvore_Dir(&(*No_R));
 }
 else if ((*No_R)->fb > 1){
 // Giro para a esquerda
         if ((*No_R)->prox_e->fb != (*No_R)->fb)
            Bal_AVL_Arvore(&((*No_R)->prox_e));
         if ((*No_R)->prox_d->fb != (*No_R)->fb)
            Bal_AVL_Arvore(&((*No_R)->prox_d));
         Rot_No_Arvore_Esq(&(*No_R));
      }
      else return;  
}

// Rotaciona a árvore para a direita -------------------------------------------
void Rot_No_Arvore_Dir(NoA **No_Rot)
{
 NoA **No_Q, **No_Temp;
 
 *No_Q = (*No_Rot)->prox_e;
 *No_Temp = (*No_Q)->prox_d;
 (*No_Q)->prox_d = *No_Rot;
 (*No_Rot)->prox_e = *No_Temp;
 return;
}

// Rotaciona a árvore para a esquerda -------------------------------------------
void Rot_No_Arvore_Esq(NoA **No_Rot)
{
 NoA **No_Q, **No_Temp;
 
 (*No_Q) = (*No_Rot)->prox_d;
 *No_Temp = (*No_Q)->prox_e;
 (*No_Q)->prox_e = *No_Rot;
 (*No_Rot)->prox_d = *No_Temp;
 return;
}

// Função de inicialização da fila ---------------------------------------------
void Iniciar_Fila(Fila *F)
{
 F->prim = NULL;
 F->ult = NULL;
 return;
}

// Função para destruir a fila -------------------------------------------------
void Deletar_Fila(Fila *F)
{
 NoF *f_at = NULL;
 NoF *f_ant = NULL;
 
 f_at = F->prim;
 while (F){
       f_ant = f_at;
       f_at = f_at->prox;
       free(f_ant);
 }
 Iniciar_Fila(&(*F));
 return;
}

// Função de inserção em fila --------------------------------------------------
short Inserir_No_Fila(Fila *F, NoA *No_A)
{
 NoF *f = NULL;
 
 f = (NoF*)malloc(sizeof(NoF));
 if (f == NULL)
    return 0;
 f->elem = &(*No_A);
 f->prox = NULL;
 if (!F->prim)
    F->prim = F->ult = f;
 else{
      F->ult->prox = f;
      F->ult = f;
 }
 return 1;
}

// Retira nó da fila -----------------------------------------------------------
short Retirar_No_Fila(Fila *F, NoA *No_A)
{
 if (!F->prim)
    return 0;
 *(No_A) = *(F->prim->elem);
 F->prim = F->prim->prox;
 return 1;
}

// Função de verificação de fila vazia -----------------------------------------
short Fila_Vazia(Fila *F)
{
 if (F->prim) return 1;
 else return 0;
}
