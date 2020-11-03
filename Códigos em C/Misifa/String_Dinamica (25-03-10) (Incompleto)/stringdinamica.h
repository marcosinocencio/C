typedef struct Reg No;

struct Reg
{
 char info;
 No *prox;
 No *ant;
};

typedef struct
{
 No *prim;
 No *ult;
} Text;

// Escopo das funções
void Start(Text *T);
short ClearText(Text *T);
short PrintText(Text *T);
int SizeText(Text *T);
