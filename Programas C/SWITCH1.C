/*
Exemplo 01 : Uso do comando switch
============
Leitura de um caractere e verificacao se o mesmo e uma VOGAL.
Caso nao seja vogal, o valor ordinal do respectivo caractere 
e determinado.
*/

#include <stdio.h>
#include <stdlib.h>

char ch;
int main(void) {
 
 printf("Por favor, pressione um caracter >> ");
 scanf("%c",&ch);

 switch(ch) {
   case 'a': 
   case 'A': printf("\n\n Foi pressionada a vogal A \n\n");
             printf("\n\n\n O Valor ordinal do caracter pressionado e < %d > \n\n", ch);
             break;
   
   case 'e': 
   case 'E': printf("\n\n Foi pressionada a vogal E \n\n");
		     break;
   case 'i': 
   case 'I': printf("\n\n Foi pressionada a vogal I \n\n");
		     break;
   case 'o': 
   case 'O': printf("\n\n Foi pressionada a vogal O \n\n");
             break;
   case 'u': 
   case 'U': printf("\n\n Foi pressionada a vogal U \n\n");
             break;
   default: printf("\n\n Foi pressionado o caracter < %c >", ch);
           printf("\n\n\n O Valor ordinal do caracter pressionado e < %d > \n\n", ch);
           printf("\n\n\n O Valor ordinal do caracter pressionado e < %d > \n\n", ch);
           break;
   
 } // switch 
 
 system("Pause");
 return(0);
}
