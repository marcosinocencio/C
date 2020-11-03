// copia arquivo caractere a caractere


#define MAX_CHAR   81
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE *f1, *f2;

int main(void) {
 char nome_arq1[11], nome_arq2[11], ch;
 char str[MAX_CHAR];

 printf("\n Introduza o NOME DO ARQUIVO que deseja copiar : ");
 gets(nome_arq1);

 printf("\n Introduza o NOME DO ARQUIVO a ser copiado: ");
 gets(nome_arq2);

 if ( (f1=fopen(nome_arq1,"r")) == NULL ) {
    printf("Erro na abertura do arquivo %s", nome_arq1);
    exit(1);
    }


 if ( ( f2=fopen(nome_arq2,"w") ) == NULL ) {
    printf("Erro na abertura do arquivo %s", nome_arq2);
    exit(1);
    }

  while ( (ch = fgetc(f1)) != EOF ) 
     fputc(ch,f2);
     
 
 fclose(f1);
 fclose(f2);
 printf("O arquivo %s foi copiado com sucesso !!! ",nome_arq1);
 
 puts("\n\n\n");
 system("Pause");
 return(0);

}
