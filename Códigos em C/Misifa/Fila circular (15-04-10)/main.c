#include <stdio.h>
#include <stdlib.h>
#include "filacircular.h"

int main(int argc, char *argv[])
{
  int op=0;
  FilaC fc;
  
  Start(&fc);
  do{
     Menu(&fc);
     printf("Deseja continuar? ");
     scanf("%d",&op);
  }while(op);
  //system("PAUSE");	
  return 0;
}
