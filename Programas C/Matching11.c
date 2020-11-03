#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//constantes do tipo string
#define STR1 "Por favor, Introduza a primeira string: "
#define STR2 "Por favor, Introduza a segunda string (padr�o): "
#define STR3 "<<<<< Introdu��o das strings para realiza��o do casamento de padr�es >>>>>: "
#define MAX 100

//Defini��o de um novo tipo de dados
typedef char string[MAX];

short Matching_Forca_Bruta1(char *Str1, char *Str2) {
int i,              // passeando pela string Str1 
    j,              // passeando pela string Str2
    k, num;
    
int n = strlen(Str1), m = strlen(Str2);
  
  num = n - m + 1;
  for (i=0; i < num; i++) {
      k = i;              // posi��o inicial da busca em Str1
      j = 0;              // 
      while ( ( *(Str1 + k) == *(Str2 + j) ) && (j < m) ) {
         j++;
         k++; 
      }	// while
     
      if ( j == m ) return(i); // posi��o inicial onde ocorreu o casamento 
     
  } // for
  
  return(-1);	// n�o ocorreu o casamento (matching)
}   // Matching_Forca_Bruta1

short Matching_Forca_Bruta2(char *Str1, char *Str2) {
int i, j, k, num;
int n = strlen(Str1), m = strlen(Str2);

  //printf("\n\n Comp(Str1) = %d\n\n",n);
  //printf("\n\n Comp(Str2) = %d\n\n",m);
  
  num = n - m + 1;
  
  for (i=0; i<num; i++) {
      j = 0;
      while ( (j < m) && *(Str1 + i + j) == *(Str2 + j) ) j++;
    
        if ( j == m ) return(i);        
  } // for
  
  return(-1);	// n�o ocorreu o casamento (matching)
}   // Matching_Forca_Bruta2

int main(){
int pos = -1;
string  str1, str2;
  
  printf("\n\n %s",STR1); gets(str1);
  printf("\n\n %s",STR2); gets(str2);

  if (  (pos = Matching_Forca_Bruta1(str1, str2) ) != -1 )  
        printf("\n\n\n OCORREU CASAMENTO do padr�o na posi��o : %d\n\n", pos);
  else  printf("\n\n\n N�o OCORREU CASAMENTO do padr�o!!!!\n\n");


  if (  (pos = Matching_Forca_Bruta2(str1, str2) ) != -1 )  
        printf("\n\n\n OCORREU CASAMENTO do padr�o na posi��o : %d\n\n", pos);
  else  printf("\n\n\n N�o OCORREU CASAMENTO do padr�o!!!!\n\n");

system("Pause");
return(0);
}
