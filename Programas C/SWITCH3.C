#include <stdio.h>
#include <stdlib.h>

int num;
int main(void) {
 printf("Por favor, introduza um numero no intervalo [1-7] >> ");
 scanf("%d",&num);

 if ( (num >= 1) && (num <= 7) ) {
   if (num == 1) printf("\n\n <%d> Segunda-feira!!\n\n", num);
   else if (num == 2) printf("\n\n <%d> Terca-feira!!\n\n", num);
   else if (num == 3) printf("\n\n <%d> Quarta-feira!!\n\n", num);
   else if (num == 4) printf("\n\n <%d> Quinta-feira!!\n\n", num);
   else if (num == 5) printf("\n\n <%d> Sexta-feira!!\n\n", num);
   else if (num == 6) printf("\n\n <%d> Sabado!!\n\n", num);
   else if (num == 7) printf("\n\n <%d> Domingo!!\n\n", num);
 }
 else printf("\n\nEntrada incorreta!!!\n\n");
 
 system("Pause");
 return(0);
}
