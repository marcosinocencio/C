//Busca Linear: Verificar se um dado elemento pertence a uma base de
//============= dados armazenadas numa estrutura de array.
//A variavel que armazena os elementos e global. Futuramente (proximas aulas), iremos
//aprender a passar variaveis do tipo array como parametros e melhorar este codigo.
// Alem disso, pense na seguinte  situacao: Se eu tivesse que manipular 50 estruturas
// de arrays e realizar uma Busca_Linear em todas elas, como eu faria?

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX1 40    // numero maximo de numeros aleatorios
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
     printf("Insira o numero de componentes do array (>= 1 && <= 1000): ");
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX1) ) continua = 1;
   }
  while ( continua );

  return(dim);
} // Leitura_Dimensao_Array


/*------------------------------------------------------------------*/
void Associando_Valores_Array(int Dim)
{
 int i;   // indice para percorrer o array
 clock_t semente;

 semente = clock();
 srand((unsigned) semente);  // inicializando o gerador
 for (i = 0; i < Dim; i++)
     elem[i]= rand();     // a variavel elem e global (precisamos eliminar isso)

 return;
} // Associando_Valores_Array


/*------------------------------------------------------------------*/

short Busca_Linear(int Chave, int Dim)
{
 int i;   // indice para percorrer o array

 // Observem que a variável elem é global ou seja, essa funcao so funciona
 // para o array de nome elem. Pense na pergunta feita la em cima.
 for (i = 0; i < Dim; i++)
      if ( elem[i] == Chave ) return(1);  // elemento localizado

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

  n = Leitura_Dimensao_Array();
  Associando_Valores_Array(n);
  //Imprimindo_Valores_Array(n);

  chave = rand();
  //chave = elem[n-2];
  // E claro que eu tambem poderia fazer a leitura da chave

  if ( Busca_Linear(chave,n) )
     printf("\n O elemento %d pertence ao array \n\n", chave);
  else printf("\n O elemento %d nao pertence ao array \n\n", chave);
  //Imprimindo_Valores_Array(n);


 system("Pause");
 return(0);
}


// Pergunta: Da forma como esta o codigo, como eu faria se tivesse que realizar a busca
// ========== em 10 arrays diferentes. Uma alternativa simples seria duplicar o codigo.
// Isto tem sentido? Pense!!!




