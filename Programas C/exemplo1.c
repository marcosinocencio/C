#include <stdio.h>
#include <stdlib.h>

#define PULA "\n\n\n"


int main(void) {
int a, b, c;

// Boas pr�tica de programa��o
int *pa = NULL,*pb = NULL,*pc =NULL;           //declara��o e inicializacao de vari�veis do tipo pointer

double   aa, *ptr;



   
   a = 10, b = 20, c = 30;      // inicializando vari�veis
   pa = &a;                     // pa aponta para o endere�o da variavel a
   pb = &b;
   pc = &c;
   
   printf("\n %d",*pa);         // imprimindo o conteudo de onde pa aponta
   printf("\n Endereco (Base 16) %p", pa);         // endere�o no sistema de numera��o hexadecimal (default)
   printf("\n Endereco (Base 10) %d", pa);         // endere�o no sistema de numera��o decimal
   printf("\n Endereco (Base 08) %o", pa);         // endere�o no sistema de numera��o octal

   pa = pa+1;
   printf("\n Endereco (Base 10) %d", pa);         // endere�o no sistema de numera��o decimal
   
   
   printf("\n Endereco DOUBLE ) %p", ptr);         // endere�o no sistema de numera��o decimal
   
   
   printf("\n Tamanho inteiro %d", sizeof(a));         // endere�o no sistema de numera��o decimal   
   printf("\n Tamanho double  %d", sizeof(aa));         // endere�o no sistema de numera��o decimal   
   
   printf("\n Tamanho char  %d", sizeof(short int));
  printf(PULA);  
  system("Pause");
  return(0);
}
