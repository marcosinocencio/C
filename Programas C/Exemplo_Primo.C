#include <stdlib.h>
#include <stdio.h>
#include <math.h>

short Primo(int p);


short Primo(int P) {
  int i = 3, exp1 = (int)sqrt((double)P) + 1;
  if (P == 2) return(1);
  if (P % 2 == 0) return(0);
  for (; i <= exp1; i=i+2)
    if (P%i == 0) return(0); 

    
  return(1);
}


int main(void) {
  int p = 0, valor, p1, p2, exp1;
  
  //printf("\nEntre com o inteiro que voce quer verificar se e primo:");
  //scanf("%d",&p); 

  for (p=4; p <=1000; p = p+2) {
    exp1 = p/2 + 2;
    for (p1=2; p1<exp1; p1++)
      if ( Primo(p1) && Primo(p-p1))
        printf("\n %d = %d + %d",p,p1, p-p1);
    
    system("pause");
  }
   
   
  printf("\n\n\n");
  system("pause");
  return(0);
}
