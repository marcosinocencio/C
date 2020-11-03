/* Conta o numero de ocorrencias de cada uma das letras do alfabeto */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE *f1;

int  main(void) {
 char nome_arq[51], ch, ch1;
 int ind, conta_letras[26];
 printf("\n Introduza o NOME DO ARQUIVO : ");
 gets(nome_arq);
 
 if ( ( f1=fopen(nome_arq,"r") ) == NULL )
    {
     printf("Erro na abertura do arquivo %s", nome_arq);
     exit(1);
    }

 for (ind=0; ind<26; ind++) conta_letras[ind] = 0;  // inicializando o vetor a quantidade de ocorrencias de cada caractere

 
//while ( !feof(f1) ) {

 while ( (ch = fgetc(f1)) != EOF ) {  // enquanto não chegar ao final do arquivo
    //ch = fgetc(f1);
    ch1 = toupper(ch);
    ind = (int)ch1 - 65;
    if ( (ind >= 0) && (ind<26) ) conta_letras[ind]++;
    }
 fclose(f1);
 printf("\n NéMERO DE OCORRENCIAS DE CADA UM DOS CARACTERES");
 
 for (ind=0; ind<26; ind++) {
     ch = (char)(ind+65);
     printf("\n %c   =  %d  ",ch, conta_letras[ind]);
    }
    
    
 puts("\n\n\n");
 system("Pause");
 return(0);
}
