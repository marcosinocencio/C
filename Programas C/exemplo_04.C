// Verificando a uniformidade do gerador de numeros pseudo-aleatorios

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX1 1000000  // numero maximo de numeros aleatorios
#define MAX2 10      // numero maximo de componentes do array - 10 subintervalos
#define MAX  32767

int i,              // indice para percorrer o array
    inter[MAX2];    // array para armazenar a quantidade de ocorrencias

float  num,           // numero aleatorio em [0,1]
       a, b;

int  main(void) {
clock_t semente; 

    // inicializando as componentes do vetor com zero
  for ( i = 0; i < MAX2; i++) inter[i] = 0;
  
  semente = clock();  
  srand((unsigned) semente);  // inicializando o gerador
 
  for ( i = 1; i < MAX1; i++) {
      num = (float)rand()/(float)MAX;
       
      if ( num < 0.1) inter[0]++;			// Classificando os números por intervalo
      else if ( num < 0.2) inter[1]++; 
      else if ( num < 0.3) inter[2]++;
      else if ( num < 0.4) inter[3]++;
      else if ( num < 0.5) inter[4]++;
      else if ( num < 0.6) inter[5]++;
      else if ( num < 0.7) inter[6]++;
      else if ( num < 0.8) inter[7]++;
      else if ( num < 0.9) inter[8]++;
      else  inter[9]++;
     } 

// EXERCICIO: Substituir o comando if encadeado (10 linhas) por uma unica linha;
// ==========


  printf("		QUANTIDADE DE NUMEROS POR INTERVALO\n\n\n");
  a = 0.0; b = 0.0;
  for ( i = 0; i < MAX2; i++) {
     b = a + 0.1;
     printf("\n Intervalo[%3.1f,%3.1f) = %d",a,b, inter[i]);
     a = b;
    }
    
  printf("\n\n\n");  
  system("Pause");
  return(0);
}
