#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERRO 0.0000001


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//funcao raiz_2
double Raiz_2 (double X) {
double app = 1.0;
   
   while ( fabs(X - app*app ) > ERRO )
     app = (X/app + app)/2.0;
   
   return(app);
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


main(void) {
  double x, app;

  printf("\nEntre com o valor x:");
  scanf("%lf",&x);

  //app = Raiz_2(x);
  printf("\nO valor aproximado da raiz de %lf com ",x);
  printf("\nerro %lf e: %lf \n\n\n",ERRO ,Raiz_2(x));
  
  printf("\nerro SQRT(%lf) = %lf \n\n\n",x ,sqrt(x));
  
  system("Pause");
  return(0);
}
