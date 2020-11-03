/*******************************************************************************
  Estrutura de Dados: Árvore B
  Autor: Luiz Paulo Rabachini
  Criação: 19 de outubro de 2010
  Atualização: 19 de outubro de 2010
  Versão: 0.1
*******************************************************************************/

#define n 2 // Grau mínimo

typedef struct ElemA NoAB; // Elemento de árvore B

struct ElemA{ // Estrutura do elento de árvore B
       int nchaves; // Indica o número de chaves em cada nó
       int chaves[2*n]; // Elementos que o nó ira armazenar
       NoAB *filhos[2*n + 1]; // Filhos de cada elemento
       NoAB *pai; // Indica o pai do nó
       short folha; // Indica se o nó é folha
};

typedef struct{ // Definição da estrutura de árvore B
 NoAB *raiz; // Raiz da árvore (primeiro elemento)
} ArvoreB;

typedef struct ElemF NoF; // Elemento de fila

struct ElemF{ // Estrutura do elemento de fila
 NoF *prox; // Próximo elemento da fila
 NoAB *elem; // Elemento da posição atual
};

typedef struct{ // Definição da estrutura de fila para auxiliar na arvore
 NoF *prim; // Primeiro elemento da fila
 NoF *ult; // Último elemento da fila
} Fila;

// Funções ---------------------------------------------------------------------

void Menu(NoAB **NoEnt);
void IniciarArvoreB(ArvoreB *ArvB);
void IniciarNoAB(NoAB **NoEnt);
short InserirChave(ArvoreB *ArvB, int Valor);
short InserirChaveRec(NoAB **NoEnt, NoAB **NoPai, int Valor, short Fe);
short RemoverChave();
short BuscarChave();
short VerificarArvoreB();
int AlturaArvoreB();
short PrintArvoreB(NoAB *NoEnt);
void IniciarFila(Fila *F);
void DeletarFila(Fila *F);
short InserirNoFila(Fila *F, NoAB *NoEnt);
short RetirarNoFila(Fila *F, NoAB **NoEnt);
short FilaVazia(Fila *F);

