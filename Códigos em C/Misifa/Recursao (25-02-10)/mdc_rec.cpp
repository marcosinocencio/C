#include <stdio.h>
#include <stdlib.h>

int mdc(int M, int N){
 if(M==N) return(M);
 if(N==0) return(M);
 else if(N>M) return(mdc(N,M));
      else return(N*fat(N-1));
}

int main (void){
 int n=0,n2=0;
 
 printf("Insira n: ");
 scanf("%d",&n);
 
 printf("Insira n2: ");
 scanf("%d",&n2);
 
 printf("\nMDC de %d = %d\n\n",n,mdc(n,n2));
 
 system("pause");
 return(0);
}
