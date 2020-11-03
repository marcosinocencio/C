// Defini��o da estrutura para leitura do arquivo
typedef struct
{
 char nome[20];
 int prd;
 int prox;
} RegArq;

// Defini��o dos n�s
typedef struct Reg No;

struct Reg
{
 char nome[20]; // nome do registro
 int prd; // prioridade do registro
 No *prox; // pr�ximo elemento
 No *ant; // elemento anterior
};

typedef struct
{
 No *prim; // cabe�a 1
 No *ult; // cabe�a 2
} Fila;

// Declara��o dos escopos
void Start(Fila *F);
short ReadNew(Fila *F);
//short ReadNew(char *Arq, Fila *F);
short IncludeReg(No *Novo, Fila *F);
short Insert(No *Novo, Fila *F);
short Remove(No **Exc, Fila *F);
void Copy(No *Est1, No **Est2);
void Print(Fila *F);
