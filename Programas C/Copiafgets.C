// Cria uma copia um arquivo em outro, ou seja, duplica um arquivo, mas
// usando fgets e fputs e nao fgetc e fputc, como nos exemplos anteriores.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_CHAR   81

FILE *f1, *f2;

int  main(void) {
 
 char nome_arq1[11], nome_arq2[11], ch;
 char str[MAX_CHAR];

 printf("\n Introduza o NOME DO ARQUIVO que deseja copiar : ");
 gets(nome_arq1);

 printf("\n Introduza o NOME DO ARQUIVO que sera copiado: ");
 gets(nome_arq2);

 if ( (f1=fopen(nome_arq1,"r")) == NULL ) {
    printf("Erro na abertura do arquivo %s", nome_arq1);
    exit(1);
    }

 if ( ( f2=fopen(nome_arq2,"w") ) == NULL ) {
    printf("Erro na abertura do arquivo %s", nome_arq2);
    exit(1);
    }
    
    
   while ( !feof(f1) )
      if ( fgets(str,MAX_CHAR,f1) )
          if ( !feof(f1) ) fputs(str,f2);
  
   
 fclose(f1);
 fclose(f2);
 printf("O arquivo %s foi copiado com sucesso !!! ",nome_arq1);
 
 puts("\n\n\n");
 system("Pause");
 return(0);

}
