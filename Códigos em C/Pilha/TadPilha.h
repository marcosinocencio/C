struct no{
int Valor;
struct no *Prox;
};

typedef struct no *TNo;

typedef struct{
TNo Topo;
} TPilha;

#ifndef NULL
#define NULL __null
#endif

void IniciarPilha(TPilha *Pilha);
void Empilha(TPilha *Pilha, int Elemento);
void Desempilha(TPilha *Pilha);
void ImprimePilha(TPilha *Pilha);

