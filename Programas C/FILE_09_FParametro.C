// Contando o numero de ocorrencias de um caractere (maiusculas e minusculas) arquivo e usando passagem de parâmetros
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int Conta_Caracteres(char *Nome, char Ch) {
 FILE *f1;
 int cont = 0;
 char ch, ch1 = toupper(Ch);

// printf("\n\n---->%c", Ch);
// printf("\n\n---->%s", Nome);


 if ( ( f1=fopen(Nome,"r") ) == NULL )
    {
     printf("Erro na abertura do arquivo %s", Nome);
     exit(1);
    }

   while ( (ch=fgetc(f1)) != EOF) {
	   printf("%c", ch);
       ch = toupper(ch);
       if (ch == ch1) cont++;
      }
  fclose(f1);
  return(cont);
}              // Conta_Caracteres


int  main(void) {
 char nome_arq[51], ch;
 int cont = 0;
 printf("\n Introduza o NOME DO ARQUIVO : ");
 gets(nome_arq);
 //while ( (ch = fgetc(f1)) != EOF )
 ch = '#';
 cont = Conta_Caracteres(&nome_arq[0],ch);

 printf("\nO numero de ocorrencias da letra < %c > no arquivo %s e igual a %d\n\n",ch, nome_arq, cont);
 system("Pause");
 return(0);
}
