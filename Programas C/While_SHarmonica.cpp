#include <stdio.h>
#include <stdlib.h>

int main(void) {

double lim, soma = 0.0;
int i  = 0;

 printf("Introduza um valor real : ");
 scanf("%lf",&lim);
 
 printf("\n valor lido: %lf ", lim);
 
 while ( soma <= lim ) {
    //printf("\n .....%d",i);
    //i++;
    soma += 1.0/(double)++i;    
   }
   
   printf("\n\n WHILE>>>Numero de termos >>> %d \n\n", i);

system("Pause");
return(0);
}
