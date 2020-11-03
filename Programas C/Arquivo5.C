#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define PI          3.14159265358979323846
#define RADIANO(x)  ((x)*PI/180.0)
#define STR   "not defined"
FILE *f1;

int  main(void) {
 int grau, dd;
 double t, radiano;


 if ( (f1=fopen("trig1.dad","w")) == NULL ) {
    printf("Erro na abertura do arquivo trig.dad");
    exit(1);
    }

 for (grau=0; grau <= 89; grau++) {
      t = RADIANO(grau);
      dd= fprintf(f1,"%3d %lf %lf %lf\n",grau, sin(t), cos(t), tan(t));
      fprintf(stdout," %d \n",dd);
     }
     

 fclose(f1);
 printf("O arquivo trig1.dad foi gerado com sucesso !!! ");
 system("Pause");
 return(0);
} 
