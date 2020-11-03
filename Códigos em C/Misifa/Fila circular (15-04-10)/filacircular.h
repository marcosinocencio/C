#define MAX 10

typedef struct // Estrutura que armazena a fila circular
{
 int fila[MAX];
 int prim;
 int ult;
} FilaC;

// Escopo das funções
void Menu(FilaC *Fc);
void Start(FilaC *Fc);
int Check(FilaC *Fc);
short Insert(FilaC *Fc, int Info);
short Remove(FilaC *Fc);
void Print(FilaC *Fc);
//------------------------------------------------------------------------------
