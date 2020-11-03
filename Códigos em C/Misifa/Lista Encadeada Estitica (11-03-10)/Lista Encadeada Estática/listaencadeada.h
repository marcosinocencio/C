#define MAX 20

// Estrutura do tipo registro;
// info: Informa��o armazenada; prox: Indica o pr�ximo elemento da lista;
struct Reg{
       int info;
       int prox;
};
//------------------------------------------------------------------------------

// Estrutura do tipo Lista que armazena estruturas do tipo Reg;
// dispo: Indica uma posi��o dispon�vel; prim: Indica o primeiro elemento;
typedef struct{
        int dispo;
        int prim;
        struct Reg l[MAX];
} Lista;
//------------------------------------------------------------------------------

// Escopo das fun��es;
short Order(Lista *L);
int Search(int Info, Lista *L);
short Insert(int Info, Lista *L, int OP, int Index);
short Remove(int Info, Lista *L);
void PreencherLista(Lista *L, int N);
int SearchFinal(Lista *L);
void Start(Lista *L);
void Print(Lista *L, int OP);
void Segmentar(Lista *L);
int Menu(Lista *L);
//------------------------------------------------------------------------------
