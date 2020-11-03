#define MAX 10

typedef struct{
        int Lista[MAX];
        int inicio;
        int fim;
} Lista;

void Menu(Lista *L);
void Start(Lista *L);
short Insert(Lista *L, int Info);
short Remove(Lista *L, int Info);
void Print(Lista *L);
