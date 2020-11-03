#include <stdio.h>


extern int a, b, c;


void Impressao_Valores(void){


  printf("\n\n Arquivo 01.");
  a += 10;
  b += 10;
  c += 10;
  
  printf(" (A,B,C) = (%d, %d, %d )", a, b,c);



}
