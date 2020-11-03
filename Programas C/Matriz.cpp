#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX1 100
#define MAX2 500
//////////////////////////////////////////////////////////////////////
short Soma_Matriz(int *A, int *B, int *Res, int Dim){
int i,j;
 for (i=0; i<Dim; i++)
      for (j=0; j<Dim; j++) *(Res+i*Dim+j) = *(A+i*Dim+j) + *(B+i*Dim+j);

return(1);
}
//////////////////////////////////////////////////////////////////////
void Leitura_Valores_Matriz(int *A, int Dim) {
int i, j;

for (i=0; i<Dim; i++)
    for (j=0; j<Dim; j++) {
        printf("A[%d ,%d] = ",i,j);
        scanf("%d", (A + i*Dim + j) );
        } 
return;
}
///////////////////////////////////////////////////////////////////////
void Impressao_Valores_Matriz(const int *A, int Dim) {
int i,j;
    for (i=0; i<Dim; i++) {
        printf("\n"); 
        for (j=0; j<Dim; j++)
        printf("%4d ", *(A + i*Dim + j) );
} 
return;
}
///////////////////////////////////////////////////////////////////////
int Soma_Diagonal_Principal(const int *A, int Dim) {
int i, soma = 0;
for (i=0; i<Dim; i++)
soma += *(A + i*Dim + i ); // soma += A[i][i];
return(soma);
}
///////////////////////////////////////////////////////////////////////
void Transposta_Matriz(const int *A, int *AT, int Dim) {
int i,j;
for (i=0; i<Dim; i++)
    for (j=0; j<Dim; j++)
    *(AT + i*Dim + j) = *(A + j*Dim + i);
return;
}
////////////////////////////////////////////////////////////////////////
short Soma_Todos_Elementos(int *A, int Dim){
int i,j, soma=0;
    for(i=0; i<Dim; i++)                              
       for(j=0 ;j<Dim; j++)
           soma += *(A + i*Dim + j);              
return(soma);
}
////////////////////////////////////////////////////////////////////////
short Soma_Diagonal_Secundaria(int *A, int Dim){
int i=0, soma=0;
    for(; i<Dim; i++)                              
          soma += *(A+i*Dim+(Dim-i-1));              
return(soma);
}

////////////////////////////////////////////////////////////////////////
int Verificar_Simetria_Matriz (const int *A, int Dim) {
int i, j;
for (i=1; i<Dim; i++)
    for (j=0; j<i; j++)
    if ( *(A + i*Dim + j) != *(A + j*Dim + i) ) return(0);
    return(1);
}
////////////////////////////////////////////////////////////////////////
void Maior_Valor(const int *A, int Dim){
int i,j , maior = 0;    
       for (i=0; i<Dim; i++)
         for (j=0; j<Dim; j++) 
                 if (abs(*(A + j*Dim + i)) > maior)
                       maior = abs(*(A + j*Dim + i));  
                       
     printf("\nO Maior numero e:%d\n\n", maior);                    
return;
}
////////////////////////////////////////////////////////////////////////
void Soma_Acima_Diagonal (const int *A, int Dim){
int i = 0, j,soma = 0;
 for(; i<Dim; i++)
    
    soma += *(A + i*Dim+(Dim));

  printf("\nSoma:%d\n", soma);
return;
}
////////////////////////////////////////////////////////////////////////
int A1[MAX1][MAX2], A2[MAX1][MAX2], A3[MAX1][MAX2], AT[MAX1][MAX2],Di;

int main (void){
    
   
  printf("Introduza a demensao da matriz1(quadrada):");  
  scanf("%d", &Di); 
  Leitura_Valores_Matriz(&A1[0][0], Di); 
  Impressao_Valores_Matriz(&A1[0][0], Di);
  printf("\nSoma:%d\n\n", Soma_Todos_Elementos(*A1, Di));
  printf("\nSoma:%d\n\n", Soma_Diagonal_Secundaria(*A1, Di));
  Transposta_Matriz(*A1, *AT, Di);
  Impressao_Valores_Matriz(*AT, Di);
  Verificar_Simetria_Matriz (&A1[0][0], Di);
  if (Verificar_Simetria_Matriz (&A1[0][0], Di))
  printf("\nA matriz e simetrica");
  else printf("\nA matriz NAO e simetrica");
  Maior_Valor(*A1, Di);
  Soma_Acima_Diagonal  (&A1[0][0], Di);
  
  printf("Introduza a demensao da matriz2(quadrada):");  
  scanf("%d", &Di);
  Leitura_Valores_Matriz(*A2, Di); 
  Impressao_Valores_Matriz(*A2, Di);
  printf("\nA soma da matriz 1 com a 2 e a matriz:\n\n");
  Soma_Matriz(*A1, *A2, *A3, Di);
  Impressao_Valores_Matriz(*A3, Di);
  
system("pause");
return(0);
}
