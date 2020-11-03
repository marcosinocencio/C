#include <stdio.h>
#include <stdlib.h>

#define PULA "\n\n\n"

void Troca(int *Ptra, int *Ptrb) {
 int aux;

 aux = *Ptra;
 *Ptra = *Ptrb;
 *Ptrb = aux;
} // Troca

int main(void) {
int a, b, *ptra, *ptrb;

  printf("Introduza dois valores inteiros >>\n");
  scanf("%d %d", &a, &b);
  printf("\n ANTES DA TROCA");
  printf("\n A= %d B= %d\n\n", a,b);
  Troca(&a,&b);
  printf("\n DEPOIS DA TROCA");
  printf("\n A= %d B= %d\n\n", a,b);
  
  ptra = &a;
  ptrb = &b;
  
  printf("\n\n Endereço de A = %p ", &a);
  printf("\n Endereço de A = %p ", ptra);
  
  printf("\n\n Endereço de B = %p ", &b);
  printf("\n Endereço de B = %p ", ptrb);
    
  printf("\n\n Conteudo de A = %d ", a);
  printf("\n Conteudo de A = %d ", *ptra);
  
  printf("\n\n Conteudo de A = %d ", b);
  printf("\n Conteudo de B = %d ", *ptrb);
    
  printf(PULA);  
  system("Pause");
  return(0);
}
