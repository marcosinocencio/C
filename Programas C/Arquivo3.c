// Anexando palavras num arquivo

#include <stdio.h>
#include <stdlib.h>


#define MAX_CHAR   81
#define TAM  4




int main(void){

char palavra[MAX_CHAR]; 

FILE *f1;

 if ( (f1=fopen("palavras.dad","a+")) == NULL ) {
    printf("Erro na abertura do arquivo palavras.dad");
    exit(1);
    }

  puts("Introduza palavras para serem acrescentadas a um arquivo.");
  puts("Para terminar, pressione a tecla ENTER no inicio da palavra.");
 
  while (gets(palavra) != NULL && palavra[0] != '\0')
          fprintf(f1,"%s\n",palavra);   //fputs(palavra,f1);
        
  
  rewind(f1);       // reposicionando o ponteiro de arquivo novamente na primeira posição
  
  
  
  
   
   
  while ( (fgets(palavra,MAX_CHAR,f1)) != NULL )
       fputs(palavra,stdout);
  
  //while (fscanf(f1,"%s",palavra) != EOF)
    // puts(palavra); 
  
  
  
 if (fclose(f1) != 0 )
    fprintf(stderr,"Erro no fechamento de Arquivo!!!");
 
 
 puts("\n\n\n");
 system("Pause");
 return(0);
 }
