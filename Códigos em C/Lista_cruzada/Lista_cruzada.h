#define MAX 10

typedef struct no *No;

struct no{
  int elem;
  int linha, coluna;
  No proxL, proxC;
};       


struct lista_cruzada{
   No VC[MAX];
   No VL[MAX];   
   int n; 
 };
 
// Funções

void Opcao ( int *op );
void inicializa (struct lista_cruzada *lista);
void insere (struct lista_cruzada *lista, int elem, int linha, int coluna);
void remove (struct lista_cruzada *lista, int linha, int coluna);
void imprime (struct lista_cruzada *lista);
 
 
 
 
 
       
