// EXEMPLO 1: Manipulacao basica de um arranjo unidimensional
//            Leitura de dados pelo teclado de uma sequencia de valores e armazenamento destes
//            valores numa estrutura de array e obtencao da soma dos pares e dos impares.
//            

#include <stdio.h>
#include <stdlib.h>

#define MAX 10   // numero maximo de componentes do array

int i,            // indice para percorrer o array
    n,            // tamanho real do array
    si,           // armazena a soma dos impares
    sp,           // armazena a soma dos pares
    a[MAX];       // array para armazenar os elementos da sequencia (Máximo 100 elementos)

int main(void) {
  int continua;
  
  // Fazer uma função para esta atividade
  do {
     continua = 0;
     printf("Insira o numero de componentes do array (>= 1 && <= 10): ");
     scanf("%d",&n);
     if ( (n <= 0) || (n > MAX) ) continua = 1;
     }
  while ( continua );


  // Entrada dos Dados pelo teclado de uma sequencia de valores e respectivo armazenamento
  // numa estrutura de array (arranjo)
  for ( i = 0; i < n; i++) {
     printf("\n\nIntroduza o valor associado a componente A[%d] = ",i);
     scanf("%d", &a[i]);
    }
    
  // Impressao dos valores associados ao array
  for ( i = 0; i < n; i++)
     printf("\n A[%d] = %d ",i, a[i]);

  // Encontrando a soma dos pares e dos impares
  for ( i = 0; i < n; i++)
   if (a[i]%2 == 0) sp += a[i];
   else si += a[i];

  printf("\n\nA Soma dos Pares e igual a : %d", sp);
  printf("\n\nA Soma dos Impares e igual a : %d\n\n", si);


   for ( i = 0; i < n; i++)
     printf("\n A[%d] = %d ",i, a[i]);
  system("Pause");
  return(0);

} // main

//EXERCICIO: Reescrever de modo que encontre tambem a quantidade dos pares e dos impares.
