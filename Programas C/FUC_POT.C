#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// IN�CIO DA DECLARA��O DOS PROT�TIPOS DAS FUN��ES

// ...
double Potencia(double X,int N);   // prot�tipo da fun��o

// ...

// FINAL DA DECLARA��O DOS PROT�TIPOS DAS FUN��ES


/*----------------------------------------------------*/
/* Funcao Potencia :                                  */
/* ================                                   */
/* Computa a pot�ncia de base X elevado ao expoente N.*/ 
/*                                                    */
/* Par�metros Formais :                               */
/* ==================                                 */
/*   X - Tipo double 			                      */
/*   N - Tipo inteiro           		              */
/*                                                    */
/* Tipo de dado do valor de Retorno : double          */
/* ================================                   */
/*----------------------------------------------------*/

double Potencia (double X, int N) {
 int i = 1;
 double resultado = 1.0;

 if (N == 0) return(resultado);
 for ( ; i <= abs(N); i++)
     resultado *= X;
 
// if (N > 0) return(resultado);
// else return(1.0/resultado);

 return( (N > 0) ? resultado : 1.0/resultado); 
}	// Potencia


/******************************************************/
/******************************************************/
/******************************************************/
/*********************FUN��O MAIN**********************/
/******************************************************/
/******************************************************/
/******************************************************/

int main(void) {
  double x, resultado;
  int n;

  printf("\n Entre com a BASE (numero real): ");
  scanf("%lf", &x);
  printf("\n Entre com o EXPOENTE ( numero inteiro): ");
  scanf("%d",&n);

  resultado = Potencia(x,n);   //chamada/referencia a funcao Potencia  
  
  printf("\n\n A BASE %lf elevado ao EXPOENTE %d e igual a %lf \n\n", x,n,resultado);
  system("Pause");
  
  return(0);
}

