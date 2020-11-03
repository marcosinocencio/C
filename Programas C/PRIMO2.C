#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define LIM  100000

long int  i, cont = 0, primo = 1, p, exp1, continua;

int main() {
  
  printf("    2  \n");
  for (p=3; p <= LIM; p = p + 2) {
     primo = 1;
     exp1 = (int)sqrt(p) + 1;
     for (i = 3; i <= exp1; i = i + 2)
        if ( p%i == 0) { primo = 0; break; }
     if (primo) { 
       cont++; 
       if ( cont%5 == 0) printf("%5d  \n", p);
       else printf("%5d  ", p);
  
      }  // if (primo) 
  }   // for mais externo
  
  printf("\n\n Ha %d Numeros Primos em [2, %d] \n\n\n", cont,LIM);
  system("pause");			// Mantendo a Janela de Resultados
  return(0);
}
