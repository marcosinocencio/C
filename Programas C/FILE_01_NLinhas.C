// Contando o numero de linhas de um arquivo


#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>

FILE *f1;

int main(void) {
 char nome_arq[51], ch, ch1;
 int cont = 0;
 printf("\n Introduza o NOME DO ARQUIVO : ");
 gets(nome_arq);
 
 
 if ( ( f1=fopen(nome_arq,"r") ) == NULL ) {
     printf("Erro na abertura do arquivo %s", nome_arq);
     exit(1);
    }

 while ( (ch = fgetc(f1)) != EOF ) {
       
       if ( ch == '\n') { printf("\n ---> %c",ch1); cont++; }
 	   ch1 = ch;
 }

 cont++;  // ultima linha do arquivo EOF/CTRL-Z

 if ( fclose(f1) != 0 )
   printf("\n Erro ao fechar o arquivo %s ",nome_arq);
   
 printf("\nO numero de linhas do arquivo %s e igual a %d",nome_arq, cont);
 
 puts("\n\n\n");
 system("Pause");
 return(0);
}
