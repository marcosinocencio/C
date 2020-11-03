/*******************************************************************************
  Estrutura de Dados: �rvore B
  Autor: Luiz Paulo Rabachini
  Cria��o: 19 de outubro de 2010
  Atualiza��o: 19 de outubro de 2010
  Vers�o: 0.1
*******************************************************************************/

#define n 2 // Grau m�nimo

typedef struct ElemA NoAB; // Elemento de �rvore B

struct ElemA{ // Estrutura do elento de �rvore B
       int nchaves; // Indica o n�mero de chaves em cada n�
       int chaves[2*n]; // Elementos que o n� ira armazenar
       NoAB *filhos[2*n + 1]; // Filhos de cada elemento
       NoAB *pai; // Indica o pai do n�
       short folha; // Indica se o n� � folha
};

typedef struct{ // Defini��o da estrutura de �rvore B
 NoAB *raiz; // Raiz da �rvore (primeiro elemento)
} ArvoreB;

typedef struct ElemF NoF; // Elemento de fila

struct ElemF{ // Estrutura do elemento de fila
 NoF *prox; // Pr�ximo elemento da fila
 NoAB *elem; // Elemento da posi��o atual
};

typedef struct{ // Defini��o da estrutura de fila para auxiliar na arvore
 NoF *prim; // Primeiro elemento da fila
 NoF *ult; // �ltimo elemento da fila
} Fila;

// Fun��es ---------------------------------------------------------------------

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

