#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////

float Potencia(long int B, long int E){
 
    if (E == 0) return(1);
    else if(E < 0) return(1/Potencia(B, -1*E));
    else return(B*Potencia(B, E-1));
    
}
///////////////////////////////////////////////////////////

int main (void){
    
  long int e, b, r;   
  
     
  printf("Introduza um numero para a base da potencia:");
  scanf("%ld", &b);
    
  printf("\n\nIntroduza um numero inteiro para o expoente:");
  scanf("%ld", &e);  
    
  printf("\n\n%ld elevado a %ld e: %-15.5lf\n\n", b, e, Potencia(b,e));
  
    
system("pause");  
}
