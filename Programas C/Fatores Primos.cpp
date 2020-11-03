#include <stdio.h>
#include <stdlib.h>


int main (void){
    
    int num, mult, fator;
    printf("Introduza um numero inteiro positivo:");
    scanf("%d", &num);
    
    fator = 2;
    mult = 0;
    
    while (num != 1){
          
         while ( (num%fator) == 0){
         mult++;
         num /= fator;
         }
         
         if (mult != 0){
         printf("\n[%d, %d]\n\n", fator, mult);         
         mult = 0;         
         }
         
         fator++;
    }
system("pause");    
}
