// Anexando palavras num arquivo

#include <stdio.h>
#include <stdlib.h>

#define MAX    40




int main(void){

char palavra[MAX]; 
FILE *f1;

 if ( (f1=fopen("palavras.dad","a+")) == NULL ) {
    printf("Erro na abertura do arquivo palavras.dad");
    exit(1);
    }

  puts("Introduza palavras para serem acrescentadas a um arquivo.");
  puts("Para terminar, pressione a tecla ENTER no inicio da palavra.");
 
  while (gets(palavra) != NULL && palavra[0] != '\0')
       fprintf(f1,"%s\n",palavra);
  
  rewind(f1);       // reposicionando o ponteiro de arquivo novamente na primeira posicao
  
  while ( fscanf(f1,"%s",palavra) != EOF)        // lendo as palavras
     puts(palavra);                              //imprimindo no dispositivo padrão
     //fprintf(stdout,"%s",palavra)
     
 if (fclose(f1) != 0 )
    fprintf(stderr,"Erro no fechamento de Arquivo!!!");
 puts("\n\n\n");
 system("Pause");
 return(0);
 }
