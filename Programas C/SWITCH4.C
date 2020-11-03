/*
Exemplo 01 : Uso do comando switch
============
Leitura de um valor no intervalo [1,7] e determinacao do
respectivo dia da semana.

*/
// Comente alguns breaks das opcoes iniciais e introduza um valor baixo
// para ver o que acontece. Qual o papel do break mesmo?

#include <stdio.h>
#include <stdlib.h>

int num;
int main(void) {
 printf("Por favor, introduza um numero no intervalo [1-7] >> ");
 scanf("%d",&num);

 switch(num) {
   
   default : printf("\n\n <%d> Numero fora do intervalo valido. Entrada Incorreta!!!\n\n", num);
    break;
   case 1: printf("\n\n <%d> Segunda-feira!!\n\n", num); 
           break;
   case 2: printf("\n\n <%d> Terca-feira!!\n\n", num); 
           break;
   case 3: printf("\n\n <%d> Quarta-feira!!\n\n", num);
           break;
   case 4: printf("\n\n <%d> Quinta-feira!!\n\n", num);
           break;
   case 5: printf("\n\n <%d> Sexta-feira!!\n\n", num); 
           break;
   case 6: printf("\n\n <%d> Sabado!!\n\n", num); 
           break;
   case 7: printf("\n\n <%d> Domingo!!\n\n", num); 
           break;
    } // switch

 system("Pause");
 return(0);
}
