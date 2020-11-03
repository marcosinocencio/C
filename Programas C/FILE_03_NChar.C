// Conta o numero de caracteres de um arquivo, incluindo os caracteres de
// mudanca de linha. Nao conta o caractere de terminacao do arquivo.

#include <stdio.h>
#include <stdlib.h>


FILE *f1;
int main(void) {
 char nome_arq[51], ch;
 int cont = 0;
 printf("\n Introduza o NOME DO ARQUIVO : ");
 gets(nome_arq);

 if ( ( f1=fopen(nome_arq, "r") ) == NULL ) {
    printf("Erro na abertura do arquivo %s", nome_arq);
    exit(1);
    }

 while ( (ch = fgetc(f1)) != EOF ) cont++;
 
 // cont++;     //se desejar contar o caractere de terminação do arquivo
 
 fclose(f1);
 printf("O numero de caracteres do arquivo %s e igual a %d",nome_arq, cont);

 puts("\n\n\n");
 system("Pause");
 return(0);

}
