/********************************************/
/*   Funcao Fibonacci                       */
/*   Esta funcao retorna o termo da         */
/*  serie de fibonacci do respectivo indice */
/*  introduzido.                            */
/********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main(void){
  long int n;
  long int pen, ant, atual = 0, i;
  
  
  printf("\nEntre com o termo da sequencia de Fibonacci ");
  printf("que voce quer: ");
  scanf("%ld",&n);
  pen = ant = 1;
  if ( n>=1 ) {
    if ((n == 1) || (n == 2)) atual = 1;
    else
      for(i=3 ; i <= n; i++) {
        atual = pen + ant;
        pen = ant;
        ant = atual;
      }        // for
  
    printf("\nO %ld-termo da sequencia de Fibonacci e: < %ld > ",n,atual);
  }
  else printf("\n\n Introduza um valor maior ou igual a <1>"); 
  
  printf("\n\n\n");
  system("pause");			// Mantendo a Janela de Resultados
  return(0);
}
