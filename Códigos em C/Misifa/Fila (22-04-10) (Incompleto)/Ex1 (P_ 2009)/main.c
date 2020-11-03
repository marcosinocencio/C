#include <stdio.h>
#include <stdlib.h>
#include "p1.h"

int main(void)
{
 Fila f;
 
 NewFile();
 Start(&f);
 if(ReadNew(&f)) printf("OK\n");
 else printf("Erro\n");
 Print(&f);
 system("PAUSE");	
 return 0;
}
