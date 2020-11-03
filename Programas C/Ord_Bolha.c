#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX1 500    // numero maximo de numeros aleatorios
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
void Troca1(int *S, int Ind1, int Ind2) {
int aux;

  aux =  *(S+Ind1);
  *(S+Ind1) =  *(S+Ind2);
  *(S+Ind2) = aux;
} // Troca1


/*--------------------------------------------------------*/
void Ordenacao_Bolha1(int *Elem, int Dim) //ordem crescente
{
 int i, j;
 for (i = 1; i < Dim; i++)       // controla o numero de varreduras
   for (j = 0; j < Dim-i; j++)   // aponta para as posicoes do array
      if ( *(Elem + j) >  *(Elem+j+1) ) // permutando elementos
	 //Troca( (Elem+j),(Elem+j+1) );
  return;
} // Ordenacao_Bolha1
/*--------------------------------------------------------*/
void Ordenacao_Bolha2(int *Elem, int Dim) //ordem crescente
{
 int i=1, j, continua=1, exp1;

 while ( (i < Dim ) && continua ) { // controla o numero de varreduras
     continua = 0;
     exp1 = Dim-i;
     for (j = 0; j < exp1; j++)   // aponta para as posicoes do array
       {
	 if ( *(Elem+j) > *(Elem+j+1) ) // permutando elementos
	   {
	     Troca1(Elem,j,j+1);
	     continua = 1;          // realizou uma troca
	   }
	 }
     i++;
   }
  return;
} // Ordenacao_Bolha2
/*--------------------------------------------------------*/  
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
   
int main(){
  
  
  int 	i,              // indice para percorrer o array
	    n1,             // tamanho real do array vetor1
	    n2,             // tamanho real do array vetor2
	    n3,             // tamanho real do array vetor3
	    vetor1[MAX1],   // array vetor1 para armazenar os elementos   
        vetor2[MAX2],
        vetor3[MAX1],
        maior1;
        //vetor2[MAX2],   // array vetor1 para armazenar os elementos   
        //vetor3[MAX2],   // array vetor1 para armazenar os elementos   
      	//maior1;         // maior elemento do vetor

  //n1 = Leitura_Dimensao_Array();
  //Associa_Valores_Array(vetor1,n1);
  //Ordenacao_Bolha2(vetor1,n1);
  //Imprimindo_Valores_Array(vetor1,n1);
  puts("\n\n\n");
  
  n2 = Leitura_Dimensao_Array();
  Associa_Valores_Array(vetor2,n2);
  Ordenacao_Bolha2(vetor2,n2);
  //Imprimindo_Valores_Array(vetor2,n2);
  puts("\n\n\n");
  puts("\n\n\n");
  
   
 //Imprimindo_Valores_Array(vetor1,n1);   
   
  puts("\n\n\n");
  printf("Acabei!!!");
  system("Pause");
  return(0);
}
