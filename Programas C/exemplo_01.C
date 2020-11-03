// EXEMPLO 0: Manipulação básica de um arranjo unidimensional

#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // numero maximo de componentes do array

int i,           // indice para percorrer o array    
    a[MAX], b[2*MAX] = {1,2,3,3,4,5,6,7,8,8};      // array para armazenar os elementos da sequencia

int main(void) {
  
  
  // Associando valores as componentes do array para exemplificar
  a[0] = 7;
  a[1] = -13;
  a[2] = 2*a[0];
  a[3] = a[1] - 4*a[0];
  a[4] = a[1];
  
  
  
  // Impressao dos valores associados ao array
  
  printf("Terceira Componente --> a[3] = %d", a[3]);
  printf("\n\n\n\n");
  // Impressao dos valores associados ao array usando índice da posição
  for ( i = 0; i < MAX; i++)
     printf("\n a[%d] = %d \n\n",i, a[i]);


	// ERRO GRAVE DE PROGRAMAÇÃO - Acessando componente fora dos limites definidos
	// A linguagem não faz verificação de limites. Isto é responsabilidade do programador
  
   printf("\n\n --> %d", a[8]);
   printf("\n\n --> %d\n\n", a[38]);



   printf("\n\n%p\n\n",a);
   printf("\n\n%p\n\n",&a[1]);
    
  system("Pause");
  return(0);
} // main
