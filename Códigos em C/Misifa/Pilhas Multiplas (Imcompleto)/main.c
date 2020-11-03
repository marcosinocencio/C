#include <stdio.h>
#include <stdlib.h>
#include "pilhasmult.h"

int main()
{
  int cont=0;
  PilhaM Pm;
  
  SetBase(&Pm);
  do{
     Menu(&Pm);
     printf("Deseja continuar? ");
     scanf("%d",&cont);
  }while(cont);	
  //system("PAUSE");
  return 0;
}
