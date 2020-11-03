//Busca Linear: Verificar se um dado elemento pertence a um conjunto de
//============= dados armazenados numa estrutura de array.
//A variavel que armazena os elementos é global. Futuramente (próximas aulas), iremos
//aprender a passar o endereço de variáveis do tipo array como parâmetros e melhorar este código.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX1 100000    // numero maximo de numeros aleatorios
#define MAX2 2000   // numeros aleatorios no intervalo [0,9999]



int n,                 // tamanho real do array
    chave,             // elemento que sera verificado
    elem[MAX1];        // array para armazenar a quantidade de ocorrencias

int Leitura_Dimensao_Array(void);
void Associando_Valores_Array(int Dim);
short Busca_Linear(int Chave, int Dim);
void Imprimindo_Valores_Array(int Dim);

/*------------------------------------------------------------------*/
int Leitura_Dimensao_Array(void) {
  int dim, continua;
  do {
     continua = 0;
     printf("Insira o numero de componentes do array (>= 1 && <= 100000): ");
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX1) ) continua = 1;
   }
  while ( continua );

  return(dim);
} // Leitura_Dimensao_Array


/*------------------------------------------------------------------*/
void Associando_Valores_Array(int Dim) {
 int i;   // indice para percorrer o array
 clock_t semente; 
 
 semente = clock();  
 srand((unsigned) semente);  // inicializando o gerador
 for (i = 0; i < Dim; i++)
     elem[i]= rand();        // observe que esta função associa valores somente ao vetor elem
 
 return;
} // Associando_Valores_Array


/*------------------------------------------------------------------*/

short Busca_Linear(int Chave, int Dim) {
 int i;   // indice para percorrer o array

 // Observem que a variável elem é global 
 for (i = 0; i < Dim; i++)
      if ( elem[i] == Chave ) {return(1);}  // elemento localizado

 return(0);  // elemento nao pertence ao array
}  // Busca_Linear


/*------------------------------------------------------------------*/
void Imprimindo_Valores_Array(int Dim) {
 int i;   // indice para percorrer o array
 for (i = 0; i < Dim; i++)
     printf("\n [%d] = %d ",i,elem[i]);

} // Associando_Valores_Array
/*------------------------------------------------------------------*/


int main(void) {
  int pos = -1;
  n = Leitura_Dimensao_Array();
  Associando_Valores_Array(n);
  Imprimindo_Valores_Array(n); 
  
  //chave = rand();
  //chave = elem[0];
  printf("\n\nIntroduza um valor inteiro: "); scanf("%d",&chave);
  
 
  //Imprimindo_Valores_Array(n);
 if ( Busca_Linear(chave,n) ) {
     printf("\n O elemento %d pertence ao array \n\n", chave); 
     //printf("\n e esta na posicao << %d >> \n\n", pos); 
     }
  else printf("\n O elemento %d nao pertence ao array \n\n", chave);

 system("Pause");
 return(0);
}


// Pergunta: Da forma como esta o codigo, como eu faria se tivesse que realizar a busca
// ========== em 10 arrays diferentes. Uma alternativa simples seria duplicar o codigo,
// ou seja, escrever uma funcao de busca para cada array.
// Isso tem sentido? Pense!!!
// E se eu tivesse que realizar dezenas de operacoes sobre cada um dos diferentes arrays.
// Escreveria cada operacao (uma funcao) para cada array? Isso e inteligente?



