#include "TadPilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
TPilha P1;
IniciarPilha(&P1);

Empilha(&P1,4);
Empilha(&P1,5);  
Empilha(&P1,6);  
Empilha(&P1,7);
ImprimePilha(&P1);
Desempilha(&P1);
Desempilha(&P1);  
ImprimePilha(&P1);
  
system("PAUSE");	
return 0;
}
