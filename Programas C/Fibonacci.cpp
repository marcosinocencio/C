#include <stdio.h>
#include <stdlib.h>


long int Fibonacci(int K,long int *N) {         // k > 0
static long int cont = 0;
    
    *N = cont++;
    if ( ( K==1) ||(K == 2) ) return(1);  // k >= 1. Primeiro termo é 1.
    else return(Fibonacci(K-1,N) + Fibonacci(K-2,N));

}  // Fibonacci



int main() {
long int num, n = 0;

    printf("Introduza um numero inteiro positivo: ");
    scanf("%ld",&num);
    printf("\n\n Fibo(%ld) = %ld\n\n",num, Fibonacci(num,&n));
    printf("Numero de Chamadas: %ld\n\n", n);
    
    
    system("Pause");
return(0);
} 
