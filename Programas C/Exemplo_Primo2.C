/********************************************/
/*   Funcao Primo                           */
/*   Esta funcao verifica se o numero       */
/*  e primo.                                 */
/********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

short Primo(int p);


//funcao primo
short Primo(int p)
{
  int i = 3, exp;
  if (p == 2) return(1);
  if (p % 2 == 0) return(0);
  
  exp = (int)sqrt((double)p)+1;	// P:�mpar e �ltimo divisor antes de p � menor que sqrt(q)
  for (; i <= exp; i=i+2)
    if (p%i == 0) return(0);
  return(1);
}


// Verificando o primeiro n�mero da rela��o abaixo que n�o � primo. Lembram-se??

int main(void) {
  int p = 0, valor, cont = 1;

  printf("\nEntre com o inteiro que voce quer verificar se e primo:");

  for ( ; cont <=1000 ;p++ ) {
    
      valor = p*p-79*p+1601;  // 1� valor cuja rela��o n�o d� um n�mero primo
      cont++;
     if ( Primo(valor) ) {
       printf("\n %d NAO PRIMO >>> %d", p, valor); 
       //break;
     }
  }            //for 

  printf("\n\n\n");
  system("Pause");
  return(0);
}
