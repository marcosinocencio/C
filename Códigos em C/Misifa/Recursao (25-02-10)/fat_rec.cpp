#include <stdio.h>
#include <stdlib.h>

int fat(int N){
 if(N==0) return(1);
 else return(N*fat(N-1));
}

int main (void){
 int n=0;
 
 printf("Insira n: ");
 scanf("%d",&n);
 
 printf("\nFatorial de %d = %d\n\n",n,fat(n));
 
 system("pause");
 return(0);
}
