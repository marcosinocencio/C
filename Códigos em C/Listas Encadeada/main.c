#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main(int argc, char *argv[])
{
TLista L1;  

IniciaLista(&L1);
if(InsereLista(&L1,11))printf("Lista Cheia\n");
if(InsereLista(&L1,12))printf("Lista Cheia\n");
if(InsereLista(&L1,17))printf("Lista Cheia\n");
if(InsereLista(&L1,2))printf("Lista Cheia\n");
if(InsereLista(&L1,5))printf("Lista Cheia\n");
ImprimeLista(&L1);
printf("\n\n");
DeletaLista(&L1,12);
if(InsereLista(&L1,16))printf("Lista Cheia\n");
if(InsereLista(&L1,17))printf("Lista Cheia\n");
ImprimeLista(&L1);





//printf("%d %d\n\n",L1.Ini,L1.Dispo);
//printf("O retorno da funcao deu %d",AchaLista(&L1,));

  system("PAUSE");	
  return 0;
}
