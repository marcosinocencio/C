#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX2 200000    // numero maximo de numeros aleatorios

/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
int Leitura_Dimensao_Array(void) { 
int dim, continua;
  do
   {
     continua = 0; 
     printf("Insira o numero de componentes do array (>= 1 && <= 500000): ");
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > 200000) ) continua = 1;
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
void Troca(int *Ind1, int *Ind2) {
int aux;
  aux =  *Ind1;
  *Ind1 =  *Ind2;
  *Ind2 = aux;
} // Troca
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
void Ordenacao_Insercao(int *Elem, int Dim) { //ordem crescente
 int i, j, x;
 
 for (i = 1; i < Dim; i++) {       // controla o numero de varreduras que deve ser (Dim-1)
   x = *(Elem+i);
   j = i-1;
   while ( (j >= 0) &&  (*(Elem+j) > x) ) {   // procura a posição correta para inserir o elemento x
     *(Elem+j+1) = *(Elem+j);  // deslocando o elemento e abrindo espaço para a futura inserção
     j--;
   }     // while	 
   *(Elem+j+1) = x;
  }  //for
  return;
} // Ordenacao_Insercao
/*--------------------------------------------------------*/


/*--------------------------------------------------------*/
/*--------------------------------------------------------*/

void ShellSort (int *Str, int Dim) {
int i, j, x, salto;

for (salto=Dim/2; salto>0; salto /=2){
   for (i = salto; i < Dim; i++) {
     x = *(Str+i);
     for (j=i; j >= salto && x < *(Str+j-salto); j=j-salto)
        *(Str+j) = *(Str+j-salto);
     *(Str+j) = x;
   }	//for i
}	// for k
return;
}	//ShellSort
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/




/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/

int main(voi){
int     n1, i = 0,            // tamanho real do array vetor1
	    vetor1[MAX2], vetor2[MAX2];   // array vetor1 para armazenar os elementos   

  n1 = Leitura_Dimensao_Array();
  Associa_Valores_Array(vetor1,n1);
  for (; i < n1; i++) *(vetor2+i) = *(vetor1+i);     // vetor2[i] = vetor1[i]
  
  //Imprimindo_Valores_Array(vetor1,n1);
  puts("\n\n\n");
   
  //Imprimindo_Valores_Array(vetor1,n1);   
  puts("\n\n\n");
  //Imprimindo_Valores_Array(vetor2,n1);  

   
  Ordenacao_Insercao(vetor1,n1);
  printf("\n\n Acabou INsercao!!!"); 
  ShellSort(vetor2,n1);
  
  //Imprimindo_Valores_Array(vetor1,n1);   
  puts("\n\n\n");
  //Imprimindo_Valores_Array(vetor2,n1);  
  
  printf("\n\n Acabou Shell!!!"); 
  puts("\n\n\n");
  system("Pause");
  return(0);
}
