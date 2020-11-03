#include <stdio.h>		// funcoes de entrada e saida
#include <stdlib.h>		// system



int main(void) {

float x, y, res; 				// coeficientes da equacao




   printf("\n\n Introduza o valor de X (real): ");
   scanf("%f",&x);	// leitura do valor do coeficiente A

   printf("\n\n Introduza o valor de Y (real): ");
   scanf("%f",&y);	// leitura do valor do coeficiente A
	

// E possivel encontrar outras solucoes. Observe com atencao
// em que situacao os valores de x e de y mudam.    
   


	if  (x >= 0) 
       if ( y >=0 ) res = x + y;
       else res = x + y*y;
    else
       if ( y >=0 ) res = x*x + y;
       else res = x*x + y*y;


/*   if ( (x >= 0) && (y>=0) ) res = x + y;
   if ( (x >= 0) && (y<0) ) res = x + y*y;
   if ( (x < 0) && (y>=0) ) res = x*x + y;
   if ( (x < 0) && (y < 0) ) res = x*x + y*y;
*/   
   
   printf("Resultado Final f(%4.2f,%4.2f) = %6.3f", x,y,res);
   
   printf("\n\n\n");
system("PaUse");
return(0);
}
