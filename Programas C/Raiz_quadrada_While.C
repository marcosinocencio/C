/**************************************************/
/*  Raiz quadrada                                 */
/*  Este programa calcula a raiz quadrada de      */
/* de um numero real com um erro estipulado.       */
/**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MSG1 "\n\n Erro nos dados de Entrada!!!\n\n "
#define ERRO  1.0e-06            //0.0000000001
#define ZERO  0.0


int main(void) {
  double x, app = 1.0;

  printf("\nEntre com o valor x:");
  scanf("%lf",&x);

  if ( x >= ZERO) { 
     while ( fabs(x - app*app ) >= ERRO )
       app = (x/app + app)/2.0;

     printf("\nO valor aproximado obtido da raiz de %lf com o ",x);
     printf("erro %13.10lf e: \n %13.10lf",ERRO ,app);
     printf("\n\n SQRT(%13.10lf) = %13.10lf",x,sqrt(x));
  }
  else printf(MSG1);
  
  
 printf("\n\n\n");
 system("Pause");
 return(0);
}
