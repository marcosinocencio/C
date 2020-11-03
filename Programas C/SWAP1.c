#include <stdio.h>
#include <stdlib.h>

#define PULA "\n\n\n"

void Troca(int Ptra, int Ptrb) {
 int aux;

 aux = Ptra;
 Ptra = Ptrb;
 Ptrb = aux;
 printf("\n DENTRO DA FUNÇÃO");
 printf("\n A= %d B= %d\n\n", Ptra, Ptrb);
 
} // Troca

int main(void) {
int a, b;

  printf("Introduza dois valores inteiros >>\n");
  scanf("%d %d", &a, &b);
  printf("\n ANTES DA TROCA");
  printf("\n A= %d B= %d\n\n", a,b);
  Troca(a,b);
  printf("\n DEPOIS DA TROCA");
  printf("\n A= %d B= %d\n\n", a,b); 
    
  printf(PULA);  
  system("Pause");
  return(0);
}
