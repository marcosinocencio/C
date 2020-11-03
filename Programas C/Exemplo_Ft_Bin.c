#include <stdio.h>
#include <stdlib.h>



// Declaracao dos prototipos das funcoes
 
 long int Fatorial (long int N);
 long int Coef_Binomial(long int N, long int P);


long int n, p, fat;         // vari�veis locais


/******************************************************/
/* Funcao Coef_Binomial :                             */
/* ====================                               */
/*                                                    */
/* Calcula o COEFICIENTE BINOMIAL ou o numero de      */
/* Combinacoes de n objetos p a p.                    */ 
/*                                                    */
/* Parametros Formais :                               */
/* ==================                                 */
/*   N - Tipo inteiro (long int)                      */
/*   P - Tipo inteiro (long int)         		      */
/*                                                    */
/*  RESTRICOES: (n,p >= 0) e (n>=p)                   */
/*  ==========                                        */
/*                                                    */
/* Tipo de dado do valor de Retorno : long int        */
/* ================================                   */
/******************************************************/

long int Coef_Binomial(long int N, long int P){

  return( Fatorial(N)/(Fatorial(P)*Fatorial(N-P)) );
}		

/******************************************************/
/* Funcao Fatorial :                                  */
/* ================                                   */
/*                                                    */
/* Calcula o FATORIAL de um numero inteiro positivo   */
/*                                                    */
/* Par�metros Formais :                               */
/* ==================                                 */
/*   N - Tipo inteiro (long int)                      */
/*                                                    */
/*  RESTRI��ES: (n>= 0)                               */
/*  ==========                                        */
/*                                                    */
/* Tipo de dado do valor de Retorno : long int        */
/* ================================                   */
/*                                                    */
/*                                                    */
/* OBSERVA��ES: A fun��o Fatorial cresce muito rapi-  */
/*   damente para baixos valores de n, logo se voc�   */
/*   desejar calcular o Fatorial de valores maiores   */
/*   esta fun��o deve ser alterada.                   */
/******************************************************/

long int Fatorial (long int N) {

long int i, fat = 1;        // vari�veis locais
  
  if (N == 0) return (1);
  else
    for (i = 1; i <= N; i++) fat *= i;
  
  return(fat);
}

/******************************************************/
/******************************************************/
/******************************************************/
/*********************FUN��O MAIN**********************/
/******************************************************/
/******************************************************/
/******************************************************/


int main(void) {

  printf("\n Entre com o valor de n: ");
  scanf("%ld",&n);
  
  printf("\n Entre com o valor de p: ");
  scanf("%ld",&p);
  if ( n >= 0) {
      fat = Fatorial(n);
      printf("\nFatorial(%ld) = %ld. \n\n",n,fat);
      //printf("\nFatorial(%ld) = %ld. \n\n",n, Fatorial(n));
    }
  else printf("\n\nPor favor, introduza um << VALOR POSITIVO >>");
  
  if (n >= p)
    printf("\n\nCoeficienteBinomial(%ld,%ld) = %ld. \n\n",n,p, Coef_Binomial(n,p));
   
  system("Pause");
  return(0);
}
