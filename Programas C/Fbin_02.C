// Exemplo: Leitura dos dados do arquivo e exibicao na tela.

#include <stdio.h>
#include <stdlib.h>
#define DEZ    10
FILE *f1;



int main(void) {
 int i, grau;
 double sino, coss, tang;


 if ( (f1=fopen("trig.dad","rb")) == NULL ) {
    printf("Erro na abertura do arquivo trig.dad");
    exit(1);
    }


 printf("\nANGULO        SENO       COSSENO         TANGENTE");

   while ( !feof(f1) ) {
       fread(&grau,sizeof(int),1,f1);
       fread(&sino,sizeof(double),1,f1);
       fread(&coss,sizeof(double),1,f1);
       fread(&tang,sizeof(double),1,f1);

   	   //if (grau % 3 == 0)
   	   if ( !feof(f1) )
	      fprintf(stderr,"\n %3d        %lf    %lf         %lf", grau, sino, coss, tang);
   }


 fclose(f1);
 fprintf(stdout,"\n\n\n");
 system("Pause");
 return(0);

}
