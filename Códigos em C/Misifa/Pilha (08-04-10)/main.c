/* -----------------------------------------------------------------------------
@copyright Luiz Paulo Rabachini @file: pilha.h
Release: 1.5 - Updated: 21/04/2010
--------------------------------------------------------------------------------
Resume: TAD Pilha
------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

int main(int argc, char *argv[])
{
  int op=0, resultado=0;
  char funcao[50];
  Pilha P;
  
  Start(&P);
  printf(":: Menu ::\n\n");
  printf("[0] Sair\n");
  printf("[1] TAD Pilha\n");
  printf("[2] Calculadora pos fixada (nao implementado)\n");
  printf("Opcao: "); scanf("%d",&op);
  switch (op){
         case 0: return 0;
         break;
         case 1: Menu(&P);
         break;
         case 2: CapFunc(funcao);
                 StrIn(&P,funcao,&resultado);
                 printf("Resultado: %d",resultado);
         break;
  }
  //system("PAUSE");	
  return 0;
}
