#include <stdlib.h>
#include <stdio.h>

int main (void){
    int a, *ap;
    
    a=2;
    ap=&a;
    
    printf("Ponteiro: %d Variavel: %d\n",*ap,a);
    printf("Ponteiro: %p Variavel: %d\n",&ap,a);
    
    system("pause");
    return(0);
}
