#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

double lim, soma = 0.0;
int i = 0;

 printf("Introduza um valor real : ");
 scanf("%lf",&lim);
 
  do {
    i++;
    soma += 1.0/(double)i;
    //printf("\n .....%d",i);
   }
  while ( soma <= lim );  
   printf("\n\n DO-WHILE>>>Numero de termos >>> %d \n\n", i);

system("Pause");
return(0);
}
