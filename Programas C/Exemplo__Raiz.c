#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERRO 0.000001

double Raiz_2 (double X);
double Raiz_3 (double X);


// Faça os comentários
//funcao raiz_2
double Raiz_2 (double X) {
double app = 1.0;
   
   while ( fabs(X - app*app ) > ERRO )
     app = (X/app + app)/2.0;
   
return(app);
}   // Raiz_2
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//funcao raiz_3

double Raiz_3 (double X) {
double app = 1.0;


while ( fabs(X -app*app*app) > ERRO )
   app = (2*app + X/(app*app))/3.0;

return(app);
}   // Raiz_3
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


int main(void) {
  double x, app;

  printf("\nEntre com o valor x:");
  scanf("%lf",&x);	// supondo valores válidos

  //app = Raiz_2(x);
  
  printf("\nO valor aproximado da raiz quadrada de %lf com ",x);
  printf("\nerro %lf e: %lf \n\n\n",ERRO ,Raiz_2(x));
  printf("\n\nRaiz Cubica de %lf = %lf\n\n", x, Raiz_3(x));


  system("Pause");
  return(0);
}
