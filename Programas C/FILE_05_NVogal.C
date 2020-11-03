// Conta o numero de vogais minusculas em um arquivo
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE *f1;


int main(void) {
 char nome_arq[51];
 char ch;
 int cont = 0;
 printf("\n Introduza o NOME DO ARQUIVO : ");
 gets(nome_arq);

 if ( ( f1=fopen(nome_arq, "r") ) == NULL ) {
    printf("Erro na abertura do arquivo %s", nome_arq);
    exit(1);
    }

 while ( (ch=fgetc(f1)) != EOF ) {
     printf("%c",ch);  // imprimindo na saída padrão
     ch = toupper(ch);
     if ( (ch =='A')||(ch =='E')||(ch =='I')||(ch =='O')||(ch =='U') )
     cont++;
   }
 fclose(f1);
 printf("O numero de vogais minusculas no arquivo %s e igual a %d",nome_arq, cont);
 
 puts("\n\n\n");
 system("Pause");
 return(0);

}
