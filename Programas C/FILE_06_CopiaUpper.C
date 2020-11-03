// Cria uma copia de um arquivo com os caracteres alfabeticos escritos
// em letras maiusculas e imprimi o arquivo copiado na saída padrão

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE *f1, *f2;

int main(void) {
 char nome_arq1[11], nome_arq2[11], ch, ch1;
 printf("\n Introduza o NOME DO ARQUIVO que deseja copiar : ");
 gets(nome_arq1);
 printf("Arquivo lido %s",nome_arq1);

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

  while ( (ch=fgetc(f1)) != EOF ) {
       ch1 = toupper(ch);
       fprintf(stdout,"%c",ch1);
       fputc(ch1,f2);
  }
/*  
  while ( !feof(f1) ) {
      ch = fgetc(f1);
      if ( !feof(f1) ) fputc(toupper(ch),f2);     
      printf("%c",ch);	// imprimindo na tela uma cópia em minúsculas
     }
*/


 fclose(f1);
 fclose(f2);
 printf("O arquivo %s foi copiado com sucesso !!! ",nome_arq1);
 
 puts("\n\n\n");
 system("Pause");
 return(0);

}
