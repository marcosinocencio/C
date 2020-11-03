// Definição da estrutura para leitura do arquivo
typedef struct
{
 char nome[20];
 int prd;
 int prox;
} RegArq;

// Definição dos nós
typedef struct Reg No;

struct Reg
{
 char nome[20]; // nome do registro
 int prd; // prioridade do registro
 No *prox; // próximo elemento
 No *ant; // elemento anterior
};

typedef struct
{
 No *prim; // cabeça 1
 No *ult; // cabeça 2
} Fila;

// Declaração dos escopos
void Start(Fila *F);
short ReadNew(Fila *F);
//short ReadNew(char *Arq, Fila *F);
short IncludeReg(No *Novo, Fila *F);
short Insert(No *Novo, Fila *F);
short Remove(No **Exc, Fila *F);
void Copy(No *Est1, No **Est2);
void Print(Fila *F);
