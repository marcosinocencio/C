
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX2 100000    // numero maximo de numeros aleatorios



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
short Busca_Binaria_Iterativa(int *Str, int Chave, int Dim) {
 int ini = 0,   // indice que indica a posicao inicial do intervalo
     meio,      // indice que indica a posicao central do intervalo
     fim = Dim-1; // indice que indica a posicao final do intervalo

  while ( ini <= fim) {
     meio = (ini+fim)/2;
     if ( *(Str+meio) == Chave ) return(1); // elemento pertence ao array
     else if ( Chave < *(Str+meio) ) fim = meio - 1;
     else ini = meio + 1;
    }

 return(0);  // elemento nao pertence ao array
}  // Busca_Linear

void Troca(int *S,int Ind1, int Ind2) {
int aux;
  aux =  *(S +Ind1); 
  *(S+Ind1) =  *(S+Ind2); 
  *(S+Ind2) = aux;
} // Troca


void Ordenacao_Quadratica3(int *Str, int Dim) {
int ind, i, j, lim = Dim-1;
  for (i = 0; i < lim; i++) {
     ind = i;   // posicao onde o menor elemento será colocado
     for (j = i; j < Dim; j++)
       if ( *(Str+j) < *(Str+ind) )  ind = j;
       
     if ( i != ind ) Troca(Str,ind,i);
     }
  return;
} // Ordenacao_Quadratica3

int main() {
  
int 	i,              // indice para percorrer o array
	    n1,             // tamanho real do array vetor1
	    n2,             // tamanho real do array vetor2
	    n3,             // tamanho real do array vetor3
	    vetor1[MAX2],   // array vetor1 para armazenar os elementos   
        vetor2[MAX2],   // array vetor1 para armazenar os elementos   
        vetor3[MAX2],   // array vetor1 para armazenar os elementos   
        chave;
  n1 = Leitura_Dimensao_Array();
  Associa_Valores_Array(vetor1,n1);
  //Imprimindo_Valores_Array(vetor1,n1);
  puts("\n\n\n");
  Ordenacao_Quadratica3(vetor1,n1);
  
  //chave = vetor1[10];
  chave = 35000;
  // Elaborar uma função para entrar com a chave
  if ( Busca_Binaria_Iterativa(vetor1,chave,n1) )
     printf("\n O elemento %d pertence ao array", chave);
  else printf("\n O elemento %d nao pertence ao array", chave);



  puts("\n\n\n");
  system("Pause");
  return(0);
}
