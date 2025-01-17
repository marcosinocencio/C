//EXEMPLO3: Inicializando um array com n�meros aleat�rios facilitando a manipula��o de arrays
//          com grandes quantidades de dados (arrays de alta dimens�o). 
//
//          Esta alternativa facilita a simulacao de nossos codigos para diferentes conjuntos
//          de valores obtidos de forma instantanea, eliminando a entrada de dados pelo teclado.
//
//
//          OBSERVEM BEM O CODIGO. SERA QUE NAO E POSSIVEL ESCREVER FUNCOES DE PROPOSITO GERAL
//          PARA LEITURA, GERACAO DE NUMEROS ALEATORIOS E IMPRESSAO?


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX1 10


//   Vari�veis Globais. Vamos alterar este c�digo para que as vari�veis sejam locais e 
//   possa ocorrer a passagem de par�metros. Aguardem!!!

int 	i,             // indice para percorrer o array
	    n,             // tamanho real do array
	    vetor1[MAX1],  // array vetor1 para armazenar os elementos   
        vetor2[MAX1],  // array vetor1 para armazenar os elementos   
        vetor3[MAX1],  // array vetor1 para armazenar os elementos   
      	maior1;       // maior elemento do vetor
	   

int main(void) {

clock_t semente; 

  // inicializando todas as componentes dos arrays
  for ( i = 0; i < MAX1; i++) 
    vetor1[i] = vetor2[i] = vetor3[i] = 0;
  
    
  semente = clock();  
  srand((unsigned) semente);  // inicializando o gerador
  
// Inicializando os vetores com n�meros aleat�rios
// OBSERVEM A DUPLICA��O DE C�DIGO  
  for ( i = 0; i < MAX1; i++) {
   vetor1[i] = rand();
   vetor2[i] = rand();
   vetor3[i] = rand();
  }
  
// imprimindo os valores associados aos diferentes arrays
// OBSERVEM A DUPLICA��O DE C�DIGO
  
  printf("\n\n VETOR1\n");
  for ( i = 0; i < MAX1; i++) printf("\n%d",vetor1[i]);
  
  printf("\n\n VETOR2\n");
  for ( i = 0; i < MAX1; i++) printf("\n%d",vetor2[i]);
  
  printf("\n\n VETOR3\n");
   for ( i = 0; i < MAX1; i++) printf("\n%d",vetor3[i]);
  
// ENCONTRANDO O MAIOR VALOR DO VETOR1
  
  maior1 = vetor1[0];
  for ( i = 1; i < MAX1; i++)	// a partir do segundo elemento - posi��o 1
    if ( vetor1[i] > maior1) maior1 = vetor1[i];
   printf("\n\nO maior elemento do vetor1 e o valor: << %d >> ", maior1);
  
  
// ENCONTRANDO O MAIOR VALOR DO VETOR2
  
  maior1 = vetor2[0];
  for ( i = 1; i < MAX1; i++)	// a partir do segundo elemento - posi��o 1
    if ( vetor2[i] > maior1) maior1 = vetor2[i];
   printf("\n\nO maior elemento do vetor2 e o valor: << %d >> ", maior1);

// ENCONTRANDO O MAIOR VALOR DO VETOR3
  
  maior1 = vetor3[0];
  for ( i = 1; i < MAX1; i++)	// a partir do segundo elemento - posi��o 1
    if ( vetor3[i] > maior1) maior1 = vetor3[i];
   printf("\n\nO maior elemento do vetor3 e o valor: << %d >> \n\n\n", maior1);
    
    
  
  system("Pause");
  
// COMO EVITAR A DUPLICACAO DE CoDIGO. VAMOS CONTINUAR DUPLICANDO CODIGO PARA MOSTRAR A 
// NECESSIDADE  DE SE DESENVOLVER FUNCOES DE PROPOSITO GERAL QUE MANIPULAM VETORES QUAISQUER, 
// INDEPENDENTE DE SUA DIMENSAO. 

//COMO FAZER PARA EVITAR A DUPLICACAO DE CODIGO ? PENSEM ATE A SEMANA QUE VEM.
  
  
  return(0);
}


// E SE EU DESEJASSE TAMB�M A POSI��O DO MAIOR ELEMENTO em cada um dos vetores.  

