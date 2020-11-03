#include <stdio.h>
#include <stdlib.h>

#define PULA "\n\n\n"


int main(void) {
int a, b, c;

// Boas prática de programação
int *pa = NULL,*pb = NULL,*pc =NULL;           //declaração e inicializacao de variáveis do tipo pointer

double   aa, *ptr;



   
   a = 10, b = 20, c = 30;      // inicializando variáveis
   pa = &a;                     // pa aponta para o endereço da variavel a
   pb = &b;
   pc = &c;
   
   printf("\n %d",*pa);         // imprimindo o conteudo de onde pa aponta
   printf("\n Endereco (Base 16) %p", pa);         // endereço no sistema de numeração hexadecimal (default)
   printf("\n Endereco (Base 10) %d", pa);         // endereço no sistema de numeração decimal
   printf("\n Endereco (Base 08) %o", pa);         // endereço no sistema de numeração octal

   pa = pa+1;
   printf("\n Endereco (Base 10) %d", pa);         // endereço no sistema de numeração decimal
   
   
   printf("\n Endereco DOUBLE ) %p", ptr);         // endereço no sistema de numeração decimal
   
   
   printf("\n Tamanho inteiro %d", sizeof(a));         // endereço no sistema de numeração decimal   
   printf("\n Tamanho double  %d", sizeof(aa));         // endereço no sistema de numeração decimal   
   
   printf("\n Tamanho char  %d", sizeof(short int));
  printf(PULA);  
  system("Pause");
  return(0);
}
