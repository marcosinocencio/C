#include <stdio.h>
#include <stdlib.h>

int main (void){
    
    int x, y, c, q, n, nc;
    
    printf("Introduza um numero positivo:");
    scanf("%d", &n);
    c = 0;
    
    while (n%10 != 0){
          q = n/10; 
          x = n%10;  
          nc = q; 
             
             while (q%10 != 0){
                   y = q%10;
                   if (x == y)
                   c = 1;
                   q = q/10;
                   }
            
             n = nc;
}   

if (c != 0)
printf("\n\nO numero possui dois digitos iguais\n\n");
else printf("\n\nO numero NAO possui dois digitos iguais\n\n");
system("pause");   
}
