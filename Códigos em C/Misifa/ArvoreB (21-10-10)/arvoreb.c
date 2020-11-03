/*******************************************************************************
  Estrutura de Dados: Árvore B
  Autor: Luiz Paulo Rabachini
  Criação: 19 de outubro de 2010
  Atualização: 19 de outubro de 2010
  Versão: 0.1
*******************************************************************************/

#include <stdlib.h>
#include "arvoreb.h"

// Menu de exibição ------------------------------------------------------------
void Menu(NoAB **NoEnt)
{
 int op = 0, valor = 0;
 
 do {
    valor = 0;   
    printf (":: ESTRUTURAS DE DADOS ::\n\n");
    printf ("Implementacao de ArvoreB\n\n");
    printf ("Opcoes disponiveis:\n\n");
    printf ("[1] Inserir elemento (int)\n");
    printf ("[2] Remover elemento (int)\n");
    printf ("[3] Buscar elemento (int)\n");
    printf ("[4] Verificar tipo de arvore\n");
    printf ("[5] Imprimir arvore\n");
    printf ("[0] Sair\n\n");
    printf ("Opcao: "); scanf ("%d", &op);
    switch (op){
           case 1: printf ("Inserir elemento: ");
                   scanf ("%d", &valor);
           break;
           case 2: printf ("Remover elemento: ");
                   scanf ("%d", &valor);
           break;
           case 3: printf ("Buscar elemento:");
                   scanf ("%d", &valor);
           break;
           case 4:
           break;
           case 5: printf (":: Impressao de Arvore tipo B ::\n\n");
           break;
           case 0: return; 
           break;
    }
 }while (1); // Laço para exibição do menu
}

// Inicia a árvore tipo B para utilização --------------------------------------
void IniciarArvoreB(ArvoreB *ArvB)
{
 ArvB->raiz = NULL;
 return;     
}

// Ininicializa o novo nó para utilização --------------------------------------
void IniciarNoAB(NoAB **NoEnt)
{
 int i = 0;
 
 (*NoEnt)->nchaves = 0; // Zera o número de chaves do nó
 (*NoEnt)->folha = 1; // Diz que o nó deve ser folha
 (*NoEnt)->pai = NULL; // Anula o pai do nó (garante consistência)
 for (i = 0; i < 2*n; i++){
     (*NoEnt)->chaves[i] = 0; // Zera todas as entradas (só para aproveitar o laço e garantir uma instância inicial)
     (*NoEnt)->filhos[i] = NULL; // Anula os filhos   
 }
 (*NoEnt)->filhos[i] = NULL; // Anula o filho que fica faltando
 return;
}

// Verifica se a árvore é do tipo B --------------------------------------------
short VerificarArvoreB(NoAB *Raiz, int Ref, short Sinal)
{
 int i = 0;
 
 if (!Raiz) return 0; // Verifica se o nó esta nulo
 if (Sinal)
    if (NoEnt->chaves[i] > Ref) return 0; // Verifico se o primeiro elemento já não quebra a regra
 else
     if (NoEnt->chaves[i] < Ref) return 0;
 for (i = 0; i < NoEnt->nchaves - 1; i++){
     if (VerificarArvoreB(NoEnt->filhos[i], NoEnt->chaves[i], 1));
     else return 0;
     if ((NoEnt->chaves[i] - NoEnt->chaves[i+1]) < 0) return 0;
 }
 if (VerificarArvoreB(NoEnt->filhos[i], NoEnt->chaves[i - 1], 0))
    return 1;
 else return 0;
}

// Insere nova chave na árvore tipo B ------------------------------------------
short InserirChave(ArvoreB *ArvB, int Valor) // Insere caso a árvore seja nula, ou seja, sem raíz
{// Fiz isso devido ao fato da função de inserção ser recursiva e o caso de árvore vazia ser especial
 NoAB *NovoNoAB = NULL, **Aux = NULL; // Novo nó e aux para manipular diretamente a variável

 if (ArvB->raiz == NULL){ // Para árvore vazia
    NovoNoAB = (NoAB*)malloc(sizeof(NoAB)); // Aloca espaço em memória
    if(NovoNoAB == NULL) return 0; // Verifica se a alocação ocorreu bem
    IniciarNoAB(&NovoNoAB); // Inicia o nó
    NovoNoAB->chaves[0] = Valor; // Insere a chave na posição
    NovoNoAB->nchaves++; // Incrementa o número de chaves
    Aux = &(ArvB->raiz); // Aux pega o endereço do ponteiro raiz
    *Aux = NovoNoAB; // Aux muda o ponteiro raiz (precisava de um **)
    return 1;
 }
 else return (InserirChaveRec(&(ArvB->raiz), &(ArvB->raiz), Valor, 0)); // Chama a função de inserção recursiva
}

// Eis o monstro (Bazinga!) ----------------------------------------------------
short InserirChaveRec(NoAB **NoEnt, NoAB **NoPai, int Valor, short Fe) // Fe força a entrada mesmo que o nó não seja folha
{
 int i = 0, j = 0, aux = 0; // A variável i é reaproveitada sempre que possível mas com fins diferentes dependendo do bloco
 NoAB *novoNoAB = NULL, *temp = NULL; 
 
 if (*NoPai == NULL) // 
    if (Fe){ // Se Fe for true, estou forçando a entrada e precisarei quebrar a raiz      
       novoNoAB = (NoAB*)malloc(sizeof(NoAB));
       IniciarNoAB(&novoNoAB);
       temp = (NoAB*)malloc(sizeof(NoAB));
       IniciarNoAB(&temp);
       i = (int)(((*NoEnt)->nchaves-1)/2); // Pega o elemento do meio no array
       novoNoAB->chaves[0] = (*NoEnt)->chaves[i];
       (*NoEnt)->chaves[i] = 0;
       novoNoAB->nchaves++;
       novoNoAB->filhos[0] = *NoEnt;
       novoNoAB->filhos[1] = temp;
       for (aux = 0, j = i, i++; i < (*NoEnt)->nchaves - 1; i++, aux++){
           temp->chaves[aux] = (*NoEnt)->chaves[i];
           temp->filhos[aux] = (*NoEnt)->filhos[i];
           (*NoEnt)->chaves[i] = 0;
           (*NoEnt)->filhos[i] = NULL;
       }
       temp->filhos[aux] = (*NoEnt)->filhos[i];
       (*NoEnt)->filhos[i] = NULL;
       return 1;
    }
 if (((*NoEnt)->folha)||(Fe)){ // É folha ou deve forçar a entrada porque o nó inferior está cheio
    if ((*NoEnt)->nchaves < 2*n){ // Verifica se o nó não está cheio
       for (i = 0; i < (*NoEnt)->nchaves - 1; i++){ // Apenas busco uma posição para inserir o elemento
           aux = (*NoEnt)->chaves[i]; // Usado na troca de valores
           if (Valor <= aux){ // Insere ordenado
              (*NoEnt)->chaves[i] = Valor; // Grava a chave
              Valor = aux; // Aproveito a variável Valor para ordenar o array
           }
       }
       (*NoEnt)->chaves[i] = Valor; // Grava a última chave que ficou faltando
       (*NoEnt)->nchaves++; // Incrementa o número de chaves
       return 1;
    }
    else{ // é folha mas está cheia
          i = (int)(((*NoEnt)->nchaves-1)/2); // pega o elemento do meio no array
          InserirChaveRec(&(*NoEnt), &((*NoEnt)->pai), (*NoEnt)->chaves[i], 1);
          for (; i < (*NoEnt)->nchaves - 1; i++) // Compacta o nó
              (*NoEnt)->chaves[i] = (*NoEnt)->chaves[i+1];    
          (*NoEnt)->nchaves--; // Decrementa o número de chaves, pois retirei uma do nó
          for (i = 0; i < (*NoEnt)->nchaves - 1; i++){ // Apenas busco uma posição para inserir o elemento
              aux = (*NoEnt)->chaves[i];               // por isso desprezo a última posição para não pegar lixo!
              if (Valor <= aux){ // Se for menor, troca
                 (*NoEnt)->chaves[i] = Valor; // Grava a chave
                 Valor = aux; // Aproveito a variável Valor para ordenar o array
              }
          }
          (*NoEnt)->chaves[i] = Valor; // Grava a última chave que ficou faltando
          (*NoEnt)->nchaves++; // Incrementa o número de chaves
          return 1;          
    }
 }
 else // O nó não é folha
     for (i = 0; i <= 2*n; i++) // Busca para qual nó deverá redirecionar
         if (i == 2*n) // Para evitar o estouro do array de chaves, pois preciso ir até 2*n, que é a dimensão do array de filhos
            InserirChaveRec(&((*NoEnt)->filhos[i]), &(*NoEnt), Valor, 0); // Se for estourar, chamo a função com o último filho
         else if (Valor <= (*NoEnt)->chaves[i]) // Verifico se o Valor de entrada é menor do que os armazenados, para que fique ordenado
                 InserirChaveRec(&((*NoEnt)->filhos[i]), &(*NoEnt), Valor, 0); // Se for, chamo a função recursivamente
}

// Imprime árvore tipo B -------------------------------------------------------
short PrintArvoreB(NoAB *NoEnt)
{
 int i = 0; // Contador das posições do array
 Fila f; // Fila que auxilia na impressão
 NoAB *NoAux = NULL; // Nó auxiliar para impressão
 
 IniciarFila(&f); // Inicia a fila para inserção     
 if (NoEnt == NULL) return 0; // Verifica se o nó de entrada não está nulo
 InserirNoFila(&f, NoEnt); // Insere primeiro a raiza na fila
 do{
    RetirarNoFila(&f, &NoAux); // Impressão em nível com fila
    for (i = 0; i < NoAux->nchaves; i++){ // Imprime os elementos de um nó e   
        printf ("| %d ", NoAux->chaves[i]); // aproveita para inserir os filhos
        InserirNoFila(&f, NoAux->filhos[i]); // na fila, mas fica faltando o último
    }
    InserirNoFila(&f, NoAux->filhos[i]); // Insere o último filho que ficou faltando
 }while (FilaVazia(&f)); // Corre até a fila ficar vazia
 return 1; 
}

// Função de inicialização da fila ---------------------------------------------
void IniciarFila(Fila *F)
{
 F->prim = NULL;
 F->ult = NULL;
 return;
}

// Função para destruir a fila -------------------------------------------------
void DeletarFila(Fila *F)
{
 NoF *f_at = NULL;
 NoF *f_ant = NULL;
 
 f_at = F->prim;
 while (F){
       f_ant = f_at;
       f_at = f_at->prox;
       free(f_ant);
 }
 IniciarFila(&(*F));
 return;
}

// Função de inserção em fila --------------------------------------------------
short InserirNoFila(Fila *F, NoAB *NoEnt)
{
 NoF *f = NULL;
 
 if (NoEnt == NULL) return 0;
 f = (NoF*)malloc(sizeof(NoF));
 if (f == NULL)
    return 0;
 f->elem = &(*NoEnt);
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
short RetirarNoFila(Fila *F, NoAB **NoEnt)
{
 if (!F->prim)
    return 0;
 *(NoEnt) = F->prim->elem;
 F->prim = F->prim->prox;
 return 1;
}

// Função de verificação de fila vazia -----------------------------------------
short FilaVazia(Fila *F)
{
 if (F->prim) return 1;
 else return 0;
}

// Remove chave da árvore tipo B -----------------------------------------------
short RemoverChave()
{
 return 1;
}

// Busca chave na árvore tipo B ------------------------------------------------
short BuscarChave()
{
 return 1;
}

// Verifica a altura da árvore tipo B ------------------------------------------
int AlturaArvoreB()
{
 return 0;
}
//==============================================================================

void em_ordem(arvoreB *raiz)
{
  int i;

  if (raiz != NULL)
   {
     if (!raiz->filhos[0]){
	         free(raiz);
	         return;
     }
     for (i = 0; i <= raiz->num_chaves; i++)
         em_ordem(raiz->filhos[i]);
     free(raiz);
  }   
  return;
}
