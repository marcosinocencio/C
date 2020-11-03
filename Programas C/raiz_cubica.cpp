#include <stdio.h>
#include <stdlib.h>
#include <math.h>
  
#define TRR   0.33333333333

#define ERRO 1.0E-08

int main(void){
double app = 1.0, x;
    
    printf("\nEntre com o valor x:");
    scanf("%lf",&x);
    
    printf("--------------------------------Raiz Cubica\n\n\n\n");
    printf("%lf\n\n", x);
 
    while ( fabs(x - app*app*app) >= ERRO ){
            //printf("\n %lf", app); 
       app = (2.0*app+x/(app*app))/3.0;
  
    
  }
    
    printf("Resultado : ----------------------\n%lf \n\n\n",app);
    printf("POW() : ----------------------\n%lf \n\n\n",pow(x,TRR));
    
system("pause");
return(0);
}
    
    
    
    
