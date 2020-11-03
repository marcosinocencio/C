#define MAX 100

typedef struct {
int Valor;
int Lig;
} TRegistro;

typedef struct{
int Ini;
int Fim;
int Dispo;
TRegistro Lista[MAX];
} TLista;

void IniciaLista(TLista *PtrLista);
int InsereLista(TLista *PtrLista, int Elemento);
int DeletaLista(TLista *PtrLista, int Elemento);
int AchaLista(TLista *PtrLista, int Elemento,int *Anterior);
int ImprimeLista(TLista *PtrLista);
int ImprimeListaCompleta(TLista *PtrLista);
