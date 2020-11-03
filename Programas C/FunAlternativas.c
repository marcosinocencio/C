#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define STR1 "Por favor, Introduza a primeira string: "
#define STR2 "Por favor, Introduza a segunda string (padrão): "
#define STR3 "<<<<< Introdução das strings para realização do casamento de padrões >>>>>: "

typedef char string[MAX];

//====================================================================
//====================================================================
// Comprimento de uma string 
int Funcao_Comprimento_Strings1(const char *Str1) {
int i = 0;

   for ( ; *(Str1 + i) != '\0'; i++ );
     
   return(i);				// as strings são diferentes
}	// Funcao_Comprimento_Strings1


// Comprimento Alternativo de uma string 
int Funcao_Comprimento_Strings2(const char *Str1) {
const char *sp = Str1;

   while ( *( sp++ ) );		
     
     
   printf(" >>>>> %o - %o", sp, Str1);
   
   return(sp-Str1 - 1);				
}	// Funcao_Comprimento_Strings2

//====================================================================
//====================================================================
// Copia a string apontada por Str2 para Str1
char *Funcao_Copia_Strings(char *Str1, const char *Str2) {
int i = 0;

  // Str1 comporta a string Str2 e as strings são diferentes
   if ( (strlen(Str2) < MAX-1) && (Str1 != Str2) )	
     for ( ; *(Str1 + i) = *(Str2 + i); i++ );
     
   return(Str1);
}	// Funcao_Copia_Strings


//====================================================================
//====================================================================


// Comparação entre duas strings 
int Funcao_Compara_Strings1(const char *Str1, const char *Str2) {
int i = 0;

   for ( ; *(Str1 + i) == *(Str2 + i) && *(Str1+i) != '\0'; i++ );
      
     
   return( *(Str1+i) - *(Str2+i) );				// as strings são diferentes ??
}	// Funcao_Compara_Strings1

// Comparação Alternativa entre duas strings 
int Funcao_Compara_Strings2(const char *Str1, const char *Str2) {

   for ( ; *Str1 == *Str2 && *Str1 != '\0';  Str1++, Str2++);
     
   return( *Str1 - *Str2 );				
}	// Funcao_Compara_Strings2

//====================================================================
//====================================================================


char *Funcao_Remove_Caractere_String(char *Str1, char Ch){
int i, j;

  for (i=j=0; *(Str1+i) != '\0'; i++)
     if ( *(Str1 + i) != Ch) {
        *(Str1+j)= *(Str1+i);
        j++;
     }	// if
        
 *(Str1 + j) = '\0';

return(Str1);
}	// Funcao_Remove_Caractere_String

char *Funcao_Remove_Caractere_String1(char *Str1, char Ch){
int i=0, j=0;

  for (; *(Str1+i) != '\0'; i++) {
     if ( *(Str1+i) == Ch ) 
        for (j=i; *(Str1+j)!= '\0'; j++)
           *(Str1+j) = *(Str1+j+1); 
   }
     
        
// *(Str1 + j) = '\0';

return(Str1);
}	// Funcao_Remove_Caractere_String1





//====================================================================
//====================================================================
//=============================MAIN===================================
int main(){
int ind, ind1, ind2;
char  *str;
string  str1, str2;   // char str1[MAX];

  
  printf("\n\n %s",STR1);
  gets(str1);
  
  //printf("\n\n %s",STR2);
  //gets(str2);
  
  // Início dos testes --> Comprimento

//  printf("\n\n Versão 1   =====> %d\n\n",Funcao_Comprimento_Strings1(str1));
//  printf("\n\n Versão 2   =====> %d\n\n",Funcao_Comprimento_Strings2(str1));
//  printf("\n\n Primitiva  =====> %d\n\n",strlen(str1));


  // Início dos testes --> Copia de uma string 
  //Funcao_Copia_Strings(str2,str1);
  //strcpy(str2,str1);  

  //puts(str1);
  //puts(str2);

  // Início dos testes --> Comparação entre duas strings 
 /* 
  ind1 = Funcao_Compara_Strings1(str1,str2);
  ind2 = Funcao_Compara_Strings2(str1,str2);
  
  if (ind1 == 0) printf("\n\n Strings Iguais");
  else if (ind1 < 0) printf("String1 < String2");
  else printf("String1 > String2");
  
  if (ind2 == 0) printf("\n\n Strings Iguais");
  else if (ind2 < 0) printf("\n\nString1 < String2");
  else printf("\n\nString1 > String2");
  
  
  
  ind = strcmp(str1,str2);
  if (ind < 0) printf("\n\n String1 < String2");
  else if (ind == 0) printf("\n\n Strings IGUAIS");
  else printf("\n\n String1 > String2");

*/

 puts(str1);
 str = Funcao_Remove_Caractere_String1(str1,'a');
 puts(str1);
 

  puts("\n\n\n");
  system("Pause");
  return(0);
}
