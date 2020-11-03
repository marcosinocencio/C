#include <stdio.h>
#include <math.h>

#define PI          3.14159265358979323846
#define RADIANO(x)  ((x)*PI/180.0)
#define STR   "not defined"
FILE *f1;

void main(void)
{
 int dd, grau;
 double t, radiano;

 if ( (f1=fopen("trig111.dad","w+")) == NULL ) {
    printf("Erro na abertura do arquivo trig.dad");
    exit();
    }

 for (grau=2; grau <= 5; grau++) {
      t = RADIANO(grau);
      dd= fprintf(f1,"%3d %lf %lf %lf\n",grau, sin(t), cos(t), tan(t));
     }
 fclose(f1);
 printf("O arquivo trig.dad foi gerado com sucesso !!! ");
 getch();
}