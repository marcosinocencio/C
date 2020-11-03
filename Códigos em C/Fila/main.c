#include <stdio.h>
#include <stdlib.h>
#include "TadFila.h"

int main(int argc, char *argv[])
{
int flag;
TFila F1;

IniciaFila(&F1);
InsereFila(&F1,4);
InsereFila(&F1,5);
if(ImprimeFila(&F1))printf("Fila Vazia");
DeletaDaFila(&F1);
DeletaDaFila(&F1);
if(ImprimeFila(&F1))printf("Fila Vazia");

system("PAUSE"); 
return 0;
}
