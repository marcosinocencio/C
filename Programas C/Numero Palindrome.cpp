#include <stdio.h>
#include <stdlib.h>


int main (void){
    
    unsigned long int nr, n, nc;
    
        printf("Introduza um numero positivo:");
        scanf("%ld", &n);
        nc = n; nr = 0;
        
        while (n%10 != 0){
        
        nr = nr*10 + n%10;  
        n = n/10;
        }

if (nr - nc == 0)
printf("\n\nO numero e palindrome\n\n");
else printf("\n\nO numero NAO e palindrome\n\n");  
system("pause");
}
