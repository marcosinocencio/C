#define MAX 50

typedef struct
{
 int pilha[MAX];
 int index[MAX];
 int tp;
} PilhaM;

void Menu(PilhaM *Pm);
void Start(PilhaM *Pm);
void SetBase(PilhaM *Pm);
short SetPilha(PilhaM *Pm, int *Base);
short Insert(PilhaM *Pm, int Info, int Base);
short Remove(PilhaM *Pm, int Base);
void Print(PilhaM *Pm);
void PrintIndex(PilhaM *Pm);
