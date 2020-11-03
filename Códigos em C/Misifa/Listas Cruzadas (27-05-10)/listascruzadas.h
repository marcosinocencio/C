// Definição da estrutura -------------------------------------------------
typedef struct{
        int x;
        int y;
} Posicao;

typedef struct Elem No;

struct Elem{
        int valor;
        Posicao pos;
        No *proxl;
        No *proxc;        
};

typedef struct{
        Posicao tmax;
        No *priml;
        No *primc;
} Matriz;

// Escopos das funções ---------------------------------------------------
void StartLista(Matriz *M);
void CriarLista(Matriz *M, int X, int Y);
short InserirElemento(Matriz *M, int Valor, int X, int Y);
