/*******************************************************************************
  Estrutura de Dados: �rvore B
  Autor: Luiz Paulo Rabachini
  Cria��o: 19 de outubro de 2010
  Atualiza��o: 19 de outubro de 2010
  Vers�o: 0.1
*******************************************************************************/

#include <stdlib.h>
#include "arvoreb.h"

// Menu de exibi��o ------------------------------------------------------------
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
 }while (1); // La�o para exibi��o do menu
}

// Inicia a �rvore tipo B para utiliza��o --------------------------------------
void IniciarArvoreB(ArvoreB *ArvB)
{
 ArvB->raiz = NULL;
 return;     
}

// Ininicializa o novo n� para utiliza��o --------------------------------------
void IniciarNoAB(NoAB **NoEnt)
{
 int i = 0;
 
 (*NoEnt)->nchaves = 0; // Zera o n�mero de chaves do n�
 (*NoEnt)->folha = 1; // Diz que o n� deve ser folha
 (*NoEnt)->pai = NULL; // Anula o pai do n� (garante consist�ncia)
 for (i = 0; i < 2*n; i++){
     (*NoEnt)->chaves[i] = 0; // Zera todas as entradas (s� para aproveitar o la�o e garantir uma inst�ncia inicial)
     (*NoEnt)->filhos[i] = NULL; // Anula os filhos   
 }
 (*NoEnt)->filhos[i] = NULL; // Anula o filho que fica faltando
 return;
}

// Verifica se a �rvore � do tipo B --------------------------------------------
short VerificarArvoreB(NoAB *Raiz, int Ref, short Sinal)
{
 int i = 0;
 
 if (!Raiz) return 0; // Verifica se o n� esta nulo
 if (Sinal)
    if (NoEnt->chaves[i] > Ref) return 0; // Verifico se o primeiro elemento j� n�o quebra a regra
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

// Insere nova chave na �rvore tipo B ------------------------------------------
short InserirChave(ArvoreB *ArvB, int Valor) // Insere caso a �rvore seja nula, ou seja, sem ra�z
{// Fiz isso devido ao fato da fun��o de inser��o ser recursiva e o caso de �rvore vazia ser especial
 NoAB *NovoNoAB = NULL, **Aux = NULL; // Novo n� e aux para manipular diretamente a vari�vel

 if (ArvB->raiz == NULL){ // Para �rvore vazia
    NovoNoAB = (NoAB*)malloc(sizeof(NoAB)); // Aloca espa�o em mem�ria
    if(NovoNoAB == NULL) return 0; // Verifica se a aloca��o ocorreu bem
    IniciarNoAB(&NovoNoAB); // Inicia o n�
    NovoNoAB->chaves[0] = Valor; // Insere a chave na posi��o
    NovoNoAB->nchaves++; // Incrementa o n�mero de chaves
    Aux = &(ArvB->raiz); // Aux pega o endere�o do ponteiro raiz
    *Aux = NovoNoAB; // Aux muda o ponteiro raiz (precisava de um **)
    return 1;
 }
 else return (InserirChaveRec(&(ArvB->raiz), &(ArvB->raiz), Valor, 0)); // Chama a fun��o de inser��o recursiva
}

// Eis o monstro (Bazinga!) ----------------------------------------------------
short InserirChaveRec(NoAB **NoEnt, NoAB **NoPai, int Valor, short Fe) // Fe for�a a entrada mesmo que o n� n�o seja folha
{
 int i = 0, j = 0, aux = 0; // A vari�vel i � reaproveitada sempre que poss�vel mas com fins diferentes dependendo do bloco
 NoAB *novoNoAB = NULL, *temp = NULL; 
 
 if (*NoPai == NULL) // 
    if (Fe){ // Se Fe for true, estou for�ando a entrada e precisarei quebrar a raiz      
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
 if (((*NoEnt)->folha)||(Fe)){ // � folha ou deve for�ar a entrada porque o n� inferior est� cheio
    if ((*NoEnt)->nchaves < 2*n){ // Verifica se o n� n�o est� cheio
       for (i = 0; i < (*NoEnt)->nchaves - 1; i++){ // Apenas busco uma posi��o para inserir o elemento
           aux = (*NoEnt)->chaves[i]; // Usado na troca de valores
           if (Valor <= aux){ // Insere ordenado
              (*NoEnt)->chaves[i] = Valor; // Grava a chave
              Valor = aux; // Aproveito a vari�vel Valor para ordenar o array
           }
       }
       (*NoEnt)->chaves[i] = Valor; // Grava a �ltima chave que ficou faltando
       (*NoEnt)->nchaves++; // Incrementa o n�mero de chaves
       return 1;
    }
    else{ // � folha mas est� cheia
          i = (int)(((*NoEnt)->nchaves-1)/2); // pega o elemento do meio no array
          InserirChaveRec(&(*NoEnt), &((*NoEnt)->pai), (*NoEnt)->chaves[i], 1);
          for (; i < (*NoEnt)->nchaves - 1; i++) // Compacta o n�
              (*NoEnt)->chaves[i] = (*NoEnt)->chaves[i+1];    
          (*NoEnt)->nchaves--; // Decrementa o n�mero de chaves, pois retirei uma do n�
          for (i = 0; i < (*NoEnt)->nchaves - 1; i++){ // Apenas busco uma posi��o para inserir o elemento
              aux = (*NoEnt)->chaves[i];               // por isso desprezo a �ltima posi��o para n�o pegar lixo!
              if (Valor <= aux){ // Se for menor, troca
                 (*NoEnt)->chaves[i] = Valor; // Grava a chave
                 Valor = aux; // Aproveito a vari�vel Valor para ordenar o array
              }
          }
          (*NoEnt)->chaves[i] = Valor; // Grava a �ltima chave que ficou faltando
          (*NoEnt)->nchaves++; // Incrementa o n�mero de chaves
          return 1;          
    }
 }
 else // O n� n�o � folha
     for (i = 0; i <= 2*n; i++) // Busca para qual n� dever� redirecionar
         if (i == 2*n) // Para evitar o estouro do array de chaves, pois preciso ir at� 2*n, que � a dimens�o do array de filhos
            InserirChaveRec(&((*NoEnt)->filhos[i]), &(*NoEnt), Valor, 0); // Se for estourar, chamo a fun��o com o �ltimo filho
         else if (Valor <= (*NoEnt)->chaves[i]) // Verifico se o Valor de entrada � menor do que os armazenados, para que fique ordenado
                 InserirChaveRec(&((*NoEnt)->filhos[i]), &(*NoEnt), Valor, 0); // Se for, chamo a fun��o recursivamente
}

// Imprime �rvore tipo B -------------------------------------------------------
short PrintArvoreB(NoAB *NoEnt)
{
 int i = 0; // Contador das posi��es do array
 Fila f; // Fila que auxilia na impress�o
 NoAB *NoAux = NULL; // N� auxiliar para impress�o
 
 IniciarFila(&f); // Inicia a fila para inser��o     
 if (NoEnt == NULL) return 0; // Verifica se o n� de entrada n�o est� nulo
 InserirNoFila(&f, NoEnt); // Insere primeiro a raiza na fila
 do{
    RetirarNoFila(&f, &NoAux); // Impress�o em n�vel com fila
    for (i = 0; i < NoAux->nchaves; i++){ // Imprime os elementos de um n� e   
        printf ("| %d ", NoAux->chaves[i]); // aproveita para inserir os filhos
        InserirNoFila(&f, NoAux->filhos[i]); // na fila, mas fica faltando o �ltimo
    }
    InserirNoFila(&f, NoAux->filhos[i]); // Insere o �ltimo filho que ficou faltando
 }while (FilaVazia(&f)); // Corre at� a fila ficar vazia
 return 1; 
}

// Fun��o de inicializa��o da fila ---------------------------------------------
void IniciarFila(Fila *F)
{
 F->prim = NULL;
 F->ult = NULL;
 return;
}

// Fun��o para destruir a fila -------------------------------------------------
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

// Fun��o de inser��o em fila --------------------------------------------------
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

// Retira n� da fila -----------------------------------------------------------
short RetirarNoFila(Fila *F, NoAB **NoEnt)
{
 if (!F->prim)
    return 0;
 *(NoEnt) = F->prim->elem;
 F->prim = F->prim->prox;
 return 1;
}

// Fun��o de verifica��o de fila vazia -----------------------------------------
short FilaVazia(Fila *F)
{
 if (F->prim) return 1;
 else return 0;
}

// Remove chave da �rvore tipo B -----------------------------------------------
short RemoverChave()
{
 return 1;
}

// Busca chave na �rvore tipo B ------------------------------------------------
short BuscarChave()
{
 return 1;
}

// Verifica a altura da �rvore tipo B ------------------------------------------
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
