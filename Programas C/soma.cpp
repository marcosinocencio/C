#include <stdio.h>
#include <stdlib.h>

int main (void){

    long int p, soma, n;

    printf("Introduza um numero positivo:");
    scanf("%ld", &n);
    p = 0;
    for (soma = 0; soma < n; soma += p)
     
           p = p + 2;
     
    
printf("\n\nO ultimo par das somas dos pares que nao excede o numero e: %d\n\n" , p-2);

system("pause");
}
