#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main(void)
{
  int a = 0, b = 0;
  Arvore arv;
  Fila f; 
  No no1, no2, no3, no4, no5, no6, no7, no8, no_aux;
  
  no1.Info = 1; no1.prox_e = NULL; no1.prox_d = NULL;
  no2.Info = 2; no2.prox_e = NULL; no2.prox_d = NULL;
  no3.Info = 3; no3.prox_e = NULL; no3.prox_d = NULL;
  no4.Info = 4; no4.prox_e = NULL; no4.prox_d = NULL;
  no5.Info = 5; no5.prox_e = NULL; no5.prox_d = NULL;
  no6.Info = 6; no6.prox_e = NULL; no6.prox_d = NULL;
  no7.Info = 7; no7.prox_e = NULL; no7.prox_d = NULL;
  no8.Info = 8; no8.prox_e = NULL; no8.prox_d = NULL;
  
  Iniciar_Fila(&f);
  Iniciar_Arvore(&arv);
  
  arv.raiz = &no1;
  
  arv.raiz->prox_e = &no2;
  arv.raiz->prox_d = &no3;
  
  arv.raiz->prox_e->prox_e = &no4; arv.raiz->prox_e->prox_e->prox_e = &no8;
  arv.raiz->prox_e->prox_d = &no5;
  
  arv.raiz->prox_d->prox_e = &no6;
  arv.raiz->prox_d->prox_d = &no7;
  
  Percurso_PreOrdem_Arvore(arv.raiz);
  printf("\n\n");
  Percurso_EmOrdem_Arvore(arv.raiz);
  printf("\n\n");
  Percurso_PosOrdem_Arvore(arv.raiz);
  Verificar_Prof_Arvore(arv.raiz, 1, &a);
  printf("\n\n");
  printf("Profundidade: %d", a);
  printf("\n\n");
  for (b = 0; b < a; b++)
      Empacotar_Arvore(arv.raiz, 0, b, &f);
  Imprimir_Fila(&f);
  
  if (Buscar_No_Arvore(arv.raiz, &no_aux, 1, 8)){
     printf("Ok\n\n");
     printf("Elemento: %d\n\n", no_aux.Info);
  } 
  printf("Grau do no 8: %d\n\n", Verificar_Grau_No(arv.raiz, 8));
  system("pause");	
  return 0;
}
