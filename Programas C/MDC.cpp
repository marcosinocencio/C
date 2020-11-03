#include <stdlib.h>
#include <stdio.h>
/////////////////////////////////////////////////////

int MDC(int N, int M){

    if (M == 0) return(N);
    else return (MDC(M, N%M));

}
/////////////////////////////////////////////////////
int MDC2 (int A, int B){
int nb;

    while (B!=0){
      nb = B;
      B = A%B;
      A =nb;
      }
      return(A);
}
//////////////////////////////////////////////////////
int main (void){
    
  int x, y;      
    
  printf("Introduza dois numeros inteiros positivos para calcular o MDC:");  
  scanf("%d %d", &x, &y);
      
  printf("\n\nO MDC de (%d,%d) e: %d\n\n", x,y, MDC(x,y)); 
  printf("\n\nO MDC de (%d,%d) e: %d\n\n", x,y, MDC2(x,y));  
    
    
    
system("pause");  
}
