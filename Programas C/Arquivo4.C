#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR   81

FILE *f1;

int  main(void) {
 
char nome_arq1[11];
char erro[MAX_CHAR] = "Erro de manipulação no arquivo ";

 printf("\n Introduza o NOME DO ARQUIVO que deseja copiar : ");
 gets(nome_arq1);

 // supondo que o arquivo não exista
 if ( (f1=fopen(nome_arq1,"r")) == NULL ) {
    
    perror(strcat(erro,nome_arq1));
    perror("Erro na Abertura do Arquivo");

    }

printf(">>>>>>>>>>>>>>>>>>>>>>>>");

   
 
 puts("\n\n\n");
 system("Pause");
 return(0);

}
