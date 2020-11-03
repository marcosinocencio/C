#include <stdio.h>
#include <stdlib.h>
#include "listascruzadas.h"

int main(void)
{
 int x=0, y=0;
 Matriz m;
  
  StartMatriz(&m);
  printf("Insira o numero de colunas: "); scanf("%d",&x);
  printf("Insira o numero de linhas: "); scanf("%d",&y);
  CriarLista(&m,x,y);
  InserirElemento(&m,4,5,1);
  
  system("PAUSE");	
  return 0;
}
