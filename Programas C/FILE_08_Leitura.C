#include <stdio.h>
#include <stdlib.h>

#define DEZ    10
FILE *f1;

int main(void) {
 int i, grau;
 double sino, coss, tang;


 if ( (f1=fopen("trig1.dad","r")) == NULL ) {
    printf("Erro na abertura do arquivo trig.dad");
    exit(1);
    }


 printf("\nANGULO        SENO       COSSENO         TANGENTE");

   while (fscanf(f1,"%d %lf %lf %lf\n",&grau, &sino, &coss, &tang) != EOF)
     if (grau % 2 == 0)
       printf("\n %3d        %lf    %lf         %lf", grau, sino, coss, tang);


printf("\n\n\n");
 fclose(f1);
 system("Pause");
 return(0);
}
