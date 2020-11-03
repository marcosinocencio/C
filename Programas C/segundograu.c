#include <stdio.h>		// funcoes de entrada e saida
#include <stdlib.h>		// system
#include <math.h>		// sqrt   fabs

#define ZERO    0.0
#define DOIS    2.0



int main(void) {

float a, b, c; 				// coeficientes da equacao
float delta, re, im;		// valores auxiliares
float x1, x2;				// raizes da equacao


// Sinta-se a vontade para alterar o codigo abaixo (mantendo a correcao) e fazer todas
// as experiencias que julgar convenientes.


   printf("*******************************************\n");
   printf("*******************************************\n");
   printf("*RESOLUCAO DE UMA EQUAÇÃO DO SEGUNDO GRAU**\n");
   printf("*******************************************\n");
   printf("*******************************************\n\n\n");

   printf("\n\n Introduza o coeficiente de A (real): ");
   scanf("%f",&a);	// leitura do valor do coeficiente A

   printf("\n\n Introduza o coeficiente de B (real): ");
   scanf("%f",&b);	// leitura do valor do coeficiente B

   printf("\n\n Introduza o coeficiente de C (real): ");
   scanf("%f",&c);	// leitura do valor do coeficiente C

   if ( a != ZERO ) {			// define uma equacao do 2 grau
     delta = b*b - 4.0*a*c;		//  observe que estou usando uma constante literal
     if ( delta >= ZERO ) {		// raizes reais
        x1 = (-b - sqrt(delta))/(DOIS*a);
        x2 = (-b + sqrt(delta))/(DOIS*a);
        printf("\n\n		Raizes REAIS \n\n");
        printf("Raiz 1: %10.5f \n",x1);
        printf("Raiz 2: %10.5f",x2);
     }  //if 
     else {			   		  	// raizes complexas
        re = -b/(DOIS*a);				// parte real
        im = sqrt(fabs(delta))/(DOIS*a);	// parte imaginaria
        printf("\n\n		Raizes COMPLEXAS \n\n");
        printf("Raiz 1: %10.5f + %10.5f*i \n",re, im);
        printf("Raiz 2: %10.5f - %10.5f*i",re, im);
     }
   
   }
   else printf("\n ERRO NOS DADOS DE ENTRADA (A != 0 )\n\n");

   
   printf("\n\n\n");
system("PaUse");
return(0);
}
