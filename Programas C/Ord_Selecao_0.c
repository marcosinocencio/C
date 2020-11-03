//Ordenação: Dado uma base de dados arbitraria (Conjunto de números inteiros), organize estes dados 
//numa estrutura de array, de forma que eles estejam ordenados (crescentemente). 
//O primeiro algoritmo que vamos ver e considerado como sendo de Forca-bruta, ou seja, e bastante 
//primitivo. O tempo que ele leva para resolver o problema de ordenação é quadrático.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX2 500000    // numero maximo de numeros aleatorios



/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
int Leitura_Dimensao_Array(void) { 
int dim, continua;
  do
   {
     continua = 0; 
     printf("Insira o numero de componentes do array (>= 1 && <= 1000): ");
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX2) ) continua = 1;
   }
  while ( continua ); 

return(dim);
} // Leitura_Dimensao_Array

/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
void Associa_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array
time_t t;
  
  srand((unsigned) time(&t));
  for ( ; i < Dim; i++) *(Ptr+i) = rand();
 
return; 
} // Associando_Valores_Array

/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
void Imprimindo_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array
 
 for (; i < Dim; i++) 
   printf("\n [%d] = %d ",i,*(Ptr+i));
} // Associando_Valores_Array

/*--------------------------------------------------------*/
/*--------------------------------------------------------*/

void Ordenacao_Quadratica1(int *Str, int Dim) { //ordenação por Seleção 
int aux, i, j, lim = Dim-1;

  for (i = 0; i < lim; i++)
    for (j = i+1; j < Dim; j++)	// j = i+1
      if ( *(Str+j) <  *(Str+i) ){       // permuta os elementos relativos as posições i e j
	     aux =  *(Str+i); 
	     *(Str+i) = *(Str+j);
         *(Str+j) = aux;
   	  }
  return;
} // Ordenacao_Quadratica1
/*-------------------------------------------------------*/
/*-------------------------------------------------------*/
void Troca(int *S,int Ind1, int Ind2) {
int aux;
  aux =  *(S +Ind1); 
  *(S+Ind1) =  *(S+Ind2); 
  *(S+Ind2) = aux;
} // Troca

/*-------------------------------------------------------*/
/*-------------------------------------------------------*/

void Ordenacao_Quadratica2(int *Str, int Dim) { 
int i, j, lim = Dim-1;
  for (i = 0; i < lim; i++)
    for (j = i+1; j < Dim; j++)		// j+ i+1
      if ( *(Str+j) <  *(Str+i) ) // permutando elementos associados as posições i e j
	     Troca(Str,i,j);
  return;
} // Ordenacao_Quadratica2

/*-------------------------------------------------------*/
/*-------------------------------------------------------*/

void Ordenacao_Quadratica3(int *Str, int Dim) {
int ind, i, j, lim = Dim-1;
  for (i = 0; i < lim; i++) {		//j = i+1
     ind = i;   // posicao onde o menor elemento deve ser colocado
     for (j = i+1; j < Dim; j++)
       if ( *(Str+j) < *(Str+ind) )  ind = j;
       
     if ( i != ind ) Troca(Str,ind,i);
     }
  return;
} // Ordenacao_Quadratica3
/*-------------------------------------------------------*/
/*-------------------------------------------------------*/
/*-------------------------------------------------------*/
/*-------------------------------------------------------*/

int main(void) {
  
int 	i,              // indice para percorrer o array
	    n1,             // tamanho real do array vetor1
	    n2,             // tamanho real do array vetor2
	    n3,   maior1,          // tamanho real do array vetor3
	    vetor1[MAX2];   // array vetor1 para armazenar os elementos   
        //vetor2[MAX2],   // array vetor1 para armazenar os elementos   
        //vetor3[MAX2],   // array vetor1 para armazenar os elementos   
      	//maior1;         // maior elemento do vetor

  n1 = Leitura_Dimensao_Array();
  Associa_Valores_Array(vetor1,n1);
  //n2 = Leitura_Dimensao_Array();
  //Associa_Valores_Array(vetor2,n2);
  
  //Imprimindo_Valores_Array(vetor1,n1);
  puts("\n\n\n");
  //Imprimindo_Valores_Array(vetor2,n2);
  
  
  puts("\n\n\n");
  Ordenacao_Quadratica3(vetor1,n1);
  //Ordenacao_Quadratica1(vetor2,n2);
  //Imprimindo_Valores_Array(vetor1,n1);
  puts("\n\n\n");
  //Imprimindo_Valores_Array(vetor1,n1);
  printf("\n\n\n Acabei!!!!");


  puts("\n\n\n");
  system("Pause");
  return(0);
}
