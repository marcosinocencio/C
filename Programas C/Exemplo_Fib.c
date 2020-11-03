#include <stdio.h>
#include <stdlib.h>

//=============================================================
// DECLARAÇÃO DOS PROTÓTIPOS DAS FUNÇÕES
// long int Fibonacci(long int F);


//=============================================================


//=============================================================
// Definição das funções

/*----------------------------------------------------*/
/* Funcao Fibonacci :                                 */
/* ================                                   */
/* Calcula o k-ésimo termo da seqüência de Fibonacci. */ 
/*                                                    */
/* Parâmetros Formais :                               */
/* ==================                                 */
/*   F - Tipo long int 			                      */
/*													  */
/*  RESTRIÇÕES: (F > 0)                               */
/*  ==========                                        */
/*                                                    */
/* Tipo de dado do valor de Retorno : long int        */
/* ================================                   */
/*----------------------------------------------------*/


//=============================================================


//=============================================================
//=============================================================
//						Função main
//=============================================================
//=============================================================

int main(void) {
  long int f, atual;
  printf("\nEntre com o termo da sequencia de Fibonacci ");
  printf("que voce quer:");
  scanf("%ld",&f); 
  
  atual = Fibonacci(f);
  printf("\n\n \nO %ld§ termo da sequencia de Fibonacci e:%ld\n\n",f,atual);
  printf("\n\n \nO %ld§ termo da sequencia de Fibonacci e:%ld\n\n",f,Fibonacci(f));

  system("Pause");
  return(0);
}

long int Fibonacci(long int F){
  
  if ((F == 1) || (F == 2)) return(1);
  else {   
   long int pen = 1, ant = 1, atual = 0, i = 3;     // declaração de variáveis dentro do bloco
    for( ; i <= F; i++) {                           // onde elas serão usadas.
      atual = pen + ant;
      pen = ant;
      ant = atual;
    }
   return(atual);   
  } // else
 
} 	// Fibonacci

