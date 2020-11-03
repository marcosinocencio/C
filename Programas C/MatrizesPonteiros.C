/*************************************************************************/
/*************************************************************************/
/*           >>>>>>>>>>>> MANIPULA€ÇO MATRICIAL <<<<<<<<<<<<              */
/*OBJETIVOS: Realizar algumas operações clássicas com matrizes e ilustrar */
/*=========  a passagem de parâmetros através de ponteiros.               */
/* Lembrem-se que o conceito de ponteiro está  intimamente relacionado ao */
/* conceito de matrizes. Divirtam-se!!!                                   */
/**************************************************************************/
/**************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#define MAX 300

/**********************************************************************/
/**********************************************************************/
/*                      =====================                         */
/*			            CABEÇÁRIO DAS FUNÇÕES                         */
/*                      =====================                         */
/**********************************************************************/
/**********************************************************************/

short Permutar_Linhas_Matriz(int *A, int Da, int L1, int L2);
short Soma_Matrizes(int *A, int *B, int *Res, int Da, int Db);
short Produto_Matrizes(int *A, int *B,int *Res, int Da, int Db);
void  Transposta_Matriz(int *A, int *AT, int Da);
short Matriz_Simetrica(int *A, int Dim_Lin );
void  Soma_Diagonais_Matriz(int *A, int Dim_Lin, int *Dia_Pri, int *Dia_Sec );
void  Imprime_Matriz(int *A, int Dim_Lin, int Dim_Col);



/***************************************************************************/
/***************************************************************************/
/*                       DEFINIÇÕES DAS FUNÇÕES                            */
/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
/*Function Permutar_Linhas_Matriz: Permuta duas linhas de uma matriz.      */
/*================================ Devolve o valor 1 em caso de sucesso e 0*/
/* caso as linhas sejam coincidentes ou fora dos limites v lidos.          */
/***************************************************************************/

short Permutar_Linhas_Matriz(int *A, int Da, int L1, int L2) {
int aux, i=0;

  if ( (L1 != L2) && (L1 >= 0) && (L1 < Da)
		  && (L2 >= 0) && (L2 < Da)) {
     for (; i < Da; i++) {
	  aux = *(A+L1*Da+i);
	  *(A+L1*Da+i) = *(A+L2*Da+i);
	  *(A+L2*Da+i) = aux;
     }
     return(1);
  }
  else return (0);
} // Permutar_Linhas_Matriz


/***************************************************************************/
/*Function Soma_Matrizes: Soma duas matrizes arbitr rias de mesma dimensão.*/
/*======================  Devolve o valor 1 em caso de sucesso e 0, caso as*/
/* as matrizes possuam dimensões diferentes                                */
/***************************************************************************/

short Soma_Matrizes(int *A,    // Primeira matriz
		    int *B,    // Segunda matriz
		    int *Res,  // Matriz resultante da soma
		    int Da,    // DimensÆo de A
		    int Db)    // DimensÆo de B
{
int i=0,j;

  if (Da != Db) return(0);
  else
    for (; i<Da; i++)
      for (j=0; j<Da; j++) *(Res+i*Da+j) = *(A+i*Da+j) + *(B+i*Da+j);

  return(1);
}  // Soma_Matrizes

/***************************************************************************/
/*Function Produto_Matrizes: Faz o produto entre duas matrizes quadradas de*/
/*======================  mesma ordem. Devolve o valor 1 em caso de sucesso*/
/* e 0, caso as matrizes possuam dimensões diferentes.                     */
/***************************************************************************/

short Produto_Matrizes(int *A,    // Primeira matriz
		       int *B,    // Segunda matriz
		       int *Res,  // Matriz resultante do PRODUTO
		       int Da,    // Dimensão de A
		       int Db)    // Dimensão de B
{
int i=0,k, j;

  if (Da != Db) return(0);
  else {
    for (; i<Da; i++)
      for (k=0; k<Da; k++) {
      *(Res+i*Da+k) = 0;
      for (j=0; j<Da; j++)
      *(Res+i*Da+k) += (*(A+i*Da+j))*(*(B+j*Da+k));
      }
  return(1);
  } // else
}  // Produto_Matrizes



/***************************************************************************/
/*Function Transposta_Matriz: Encontra a TRANSPOSTA de uma matriz qualquer.*/
/*======================                                                   */
/*Observem que não estou me preocupando em armazenar a dimensão da matriz  */
/*resultante. Dependendo do que V. for fazer isto ser  fundamental.        */
/***************************************************************************/

void Transposta_Matriz(int *A,        // Matriz qualquer
		    int *AT,          // Armazena a TRANSPOSTA de A
		    int Da )          // Dimensão de A

{
int i=0,j;
    
    for (; i<Da; i++)
      for (j=0; j<Da; j++)
    	 *(AT + j*Da + i) = *(A + i*Da + j);

return;
       //*(AT+i*Da+j) = *(A+j*Da+i);
}  // Transposta_Matriz

/***************************************************************************/
/*Function Matriz_Simetrica: Verifica se uma matriz quadrada qualquer ‚   .*/
/*========================== SIMÉTRICA. Retorna o valor 1 em caso afirma-*/
/*vo e 0, em caos contrário.                                               */
/***************************************************************************/

short Matriz_Simetrica(int *A,        // Matriz qualquer
		      int Dim_Lin )    // Número de Linhas de A
{
int i=0,j;

// estamos supondo que matriz A ‚ quadrada. Isto deve ser verificado antes
// da chamada a esta função. O Problema ‚ seu. Se por acaso estiver
// manipulando matrizes retangulares, tome cuidado.

  for (; i<Dim_Lin; i++)
    for (j=0; j<i; j++)
      if ( *(A + i*Dim_Lin+j) != *(A+j*Dim_Lin+i) ) return(0);

  return(1);
}  // Matriz_Simetrica


/***************************************************************************/
/*Function Soma_Diagonais_Matriz : Soma os elementos da diagonal principal */
/*================================ e secundária de uma matriz quadrada.    */
/***************************************************************************/

void Soma_Diagonais_Matriz(int *A,         // Matriz quadrada qualquer
			   int Dim_Lin,    // Dimensão de A
			   int *Dia_Pri,   // Valor da Diagonal Principal
			   int *Dia_Sec )  // Valor da Diagonal Principal
{
int i=0;

// estamos supondo que matriz A ‚ quadrada. Isto deve ser verificado antes
// da chamada a esta função. O Problema ‚ seu. Se por acaso estiver
// manipulando matrizes retangulares, tome cuidado.


  *Dia_Pri = 0;
  *Dia_Sec = 0;

  for ( ;i<Dim_Lin; i++) {
     *Dia_Pri += *(A+i*Dim_Lin+i);
     *Dia_Sec += *(A+i*Dim_Lin+(Dim_Lin-i-1) );
  } // for
  
  return;
}  // Soma_Diagonais_Matriz


/***************************************************************************/
/*Function Imprime_Matriz : Imprime uma matriz qualquer no formato de uma  */
/*========================== matriz. Dependendo da dimensão da matriz isto */
/* não ser  possível, já  que estamos limitado a dimensão física da tela.  */
/***************************************************************************/


void Imprime_Matriz(int *A, int Dim_Lin, int Dim_Col)
{
int i=0,j;

    printf("\n\n");
    for (; i<Dim_Lin; i++) {
      printf("\n\n");
      for (j=0; j<Dim_Col; j++) 
	     printf("%5d ",    *(A + i*Dim_Col + j) );
    } // for_i

   printf("\n\n");
   return;
}  // Imprime_Matriz

int main(void) {

int  m3[MAX][MAX], m4[MAX][MAX];


// duas formas diferentes de inicializar uma matriz
int m1[MAX][MAX] = {1,1,1,1,1,1,1,1,1};
int m2[MAX][MAX] = { { 2,-15,-12 }, { -15,6,3 },{ -12,3,-4 } };

int sdp = 0, sds = 0;

/*
  Imprime_Matriz(&m1[0][0],MAX,MAX);
  Imprime_Matriz(&m2[0][0],MAX,MAX);
  if ( Soma_Matrizes(&m1[0][0],&m2[0][0],&m3[0][0],MAX,MAX) ) {
    Imprime_Matriz(&m3[0][0],MAX,MAX);
     Transposta_Matriz(&m3[0][0],&m4[0][0],MAX);
     Imprime_Matriz(&m4[0][0],MAX,MAX);
    }
  else printf("\n Impossivel multiplicar matrizes de dimensÆo diferente.");


 Imprime_Matriz(&m2[0][0],MAX,MAX);
 Transposta_Matriz(&m2[0][0],&m4[0][0],MAX);
 Imprime_Matriz(&m4[0][0],MAX,MAX);
*/


   Imprime_Matriz(&m2[0][0],MAX,MAX);

   if (Matriz_Simetrica(&m1[0][0], MAX) )
     printf("\n A MAtriz M2 ‚ Sim‚trica");
   else printf("\n A MAtriz M2 N¶O ‚ Sim‚trica");


/*
   Soma_Diagonais_Matriz(&m2[0][0],MAX,&sdp,&sds);
   printf("\n Soma da Diagonal Principal = %d ", sdp);
   printf("\n Soma da Diagonal Secund ria= %d ", sds);
*/
/*

    if ( Produto_Matrizes(&m1[0][0],&m2[0][0],&m3[0][0],MAX,MAX) )
      if ( Produto_Matrizes(&m3[0][0],&m2[0][0],&m4[0][0],MAX,MAX) )
	Imprime_Matriz(&m4[0][0],MAX,MAX);
    else printf("\n Impossivel multiplicar matrizes de dimensÆo diferente.");
*/


  /* Imprime_Matriz(&m2[0][0],MAX,MAX);
   Transposta_Matriz(&m2[0][0],&m4[0][0],MAX);
   Imprime_Matriz(&m4[0][0],MAX,MAX);
   */
   
   
   //Imprime_Matriz(&m1[0][0],MAX,MAX);
/*
	Imprime_Matriz(&m2[0][0],MAX,MAX);
   if ( Soma_Matrizes(&m2[0][0],&m2[0][0],&m4[0][0],3,MAX) )
       Imprime_Matriz(&m4[0][0],MAX,MAX);
   else printf("\n\n Impossivel somar matrizes com ....");
*/
//	Imprime_Matriz(&m2[0][0],MAX,MAX);
       //Imprime_Matriz(&m2[0][0],MAX,MAX);

/*   if ( Permutar_Linhas_Matriz(&m2[0][0],MAX,0,2) )
       Imprime_Matriz(&m2[0][0],MAX,MAX);
       else printf("\n\n Impossivel operar matrizes com ....");

*/   
    
     
   system("Pause");

  
 
 system("Pause");
 return(0);
} // main
