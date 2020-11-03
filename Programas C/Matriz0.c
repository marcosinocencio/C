#include <stdio.h>



void Leitura_Valores_Matriz(int *A, int Dim); 
void Impressao_Valores_Matriz(int *A, int Dim);


void Leitura_Valores_Matriz(int *A, int Dim) {
int i, j;

  for  (i=0; i<Dim; i++)
    for  (j=0; j<Dim; j++) {
      printf(" Introduza o elemento A[%d , %d] = ",i,j);
      scanf("%d", (A+i*Dim +j) );
    }   // for j
return;
}	// Leitura_Valores_Matriz                    

void Impressao_Valores_Matriz(int *A, int Dim) {
int i, j;

  printf("\n\n\n");
  for  (i=0; i<Dim; i++) {
    printf("\n");
    for  (j=0; j<Dim; j++)
      printf(" %4d ", *(A + i*Dim + j) );
  }   // for i
return;
}	// Impressao_Valores_Matriz                    
    

int main(){

int a[3][3] = {1,2,3,4,5,6,7,8,9};
int a1[3][3] = { {1,2,3}, {4,5,6},{7,8,9} };
int a2[3][3] = {1,2,3,4,5};
int AB[3][3], mm[3][3];


   Leitura_Valores_Matriz(&AB[0][0],3);
   Impressao_Valores_Matriz(&AB[0][0],3);   
   printf("\n\n\n");
   
   Leitura_Valores_Matriz(&mm[0][0],3);
   
   Impressao_Valores_Matriz(&a[0][0],3);   
   Impressao_Valores_Matriz(&a1[0][0],3);   
   Impressao_Valores_Matriz(&a2[0][0],3);
   Impressao_Valores_Matriz(&mm[0][0],3);
         
               
system("Pause");
return(0);
}
