struct no{
int Valor;
struct no *Prox;
};

typedef struct no *TNo;

typedef struct {
TNo Inicio;
TNo Fim;
} TFila;


#ifndef NULL
#define NULL __null
#endif

void IniciaFila(TFila *Fila);
int DeletaDaFila(TFila *Fila);
void InsereFila(TFila *Fila,int Elemento);
int ImprimeFila(TFila *Fila);
