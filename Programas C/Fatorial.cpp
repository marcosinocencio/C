#include <stdlib.h>
#include <stdio.h>

///////////////////////////////////////////////
long int Fatorial (int N){
     
     if ((N == 0) || (N == 1)) return(1);
     else return (N*Fatorial(N-1));
     
     
}
///////////////////////////////////////////////


int main (void){
    
 int x;
   
 printf("Insira um numero inteiro positivo:");
 scanf("%ld", &x);   
    
 printf("\n\nO fatorial de (%ld) e:%ld\n\n", x, Fatorial(x));   
    
      
system("pause");    
}  

  
