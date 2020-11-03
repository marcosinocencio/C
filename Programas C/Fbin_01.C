// Exemplo: Escrita e leitura em arquivos


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI          3.14159265358979323846
#define RADIANO(x)  ((x)*PI/180.0)
#define STR   "not defined"
FILE *f1;

int main(void) {
 int dd, grau;
 double t, t1, t2, t3, radiano;

 if ( (f1=fopen("trig.dad","wb+")) == NULL ) {
    printf("Erro na abertura do arquivo trig.dad");
    exit(1);
    }

 for (grau=0; grau <= 89; grau++) {
      t = RADIANO(grau); t1 = sin(t);
      t2 = cos(t); t3 = tan(t);
      fwrite(&grau,sizeof(int),1,f1);
      fwrite(&t1,sizeof(double),1,f1);
      fwrite(&t2,sizeof(double),1,f1);
      fwrite(&t3,sizeof(double),1,f1);
     }
 printf("O arquivo trig.dad foi gerado com sucesso !!! \n\n\n");
 system("Pause");
 
 rewind(f1);
 printf("\nANGULO        SENO       COSSENO           TANGENTE");

 while ( !feof(f1) ) {
     
     fread(&grau,sizeof(int),1,f1);
     fread(&t1,sizeof(double),1,f1);
     fread(&t2,sizeof(double),1,f1);
     fread(&t3,sizeof(double),1,f1);
     
     
     if ( !feof(f1) )
       if (grau % 7 == 0)
	      printf("\n %3d        %lf    %lf         %10.6lf", grau, t1, t2, t3);
   }

 fclose(f1);
 fprintf(stdout,"\n\n\n");
 system("Pause");
 return(0);
}
