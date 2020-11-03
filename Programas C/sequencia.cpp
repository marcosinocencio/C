#include <stdio.h>
#include <stdlib.h>

int main (void){
    
    int me1, me2, ma1, ma2, n, i, num;
    
    printf("Introduza quantos numeros tera a sequencia (4 ou mais numeros):");
    scanf("%d", &n);
    
    printf("\n\nIntroduza o primeiro elemento da sequencia:");
    scanf("%d", &num);
    me1 = me2 = ma1 = ma2 = num;
    
    for(i = 2; i <= n; i++){
    
    
    printf("\n\nIntroduza o proximo elemento da sequencia:");
    scanf("%d", &num);
    
    if (num >= ma2 ){
    ma1 = ma2;
    ma2 = num;
    }
    
    else if ( num > me2 && num < ma2 ) 
    ma1 = num;

               
    else if (num > me1 && num < ma1  )
    me2 = num;    
    
    else   {
    me2 = me1;
    me1 = num;
    }
    
    
    
    
}  
printf("\n\nO primeiro menor elemento da sequencia e: %d", me1);
printf("\n\nO segundo menor elemento da sequencia e: %d", me2);
printf("\n\nO primeiro maior elemento da sequencia e: %d", ma1);
printf("\n\nO segundo maior elemento da sequencia e: %d\n\n", ma2);
system("pause");   
}
