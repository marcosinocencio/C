// Leitura de um arquivo sequencial
// Extraído do Livro do Deitel


#include <stdio.h>
#include <stdlib.h>

#define MAX 40

int  main(void) {
     
int             conta;       // numero da conta
char            nome[MAX];  // nome da conta (nome simples)
double          saldo;      // saldo da conta

FILE *f1;       // variável ponteiro de arquivo

 if ( (f1=fopen("clientes.dad","r")) == NULL ) {
    printf("Erro na abertura do arquivo clientes.dad");
    exit(1);      // saída incondicional do programa
    }
 else {
    printf(" Conta     Nome     Saldo");
    fscanf(f1,"%d %s %lf",&conta, nome, &saldo);    // Unix/Linux/MAC OS- CTRL + d
 
    while ( !feof(f1) ) {          // enquanto não chegar ao final do arquivo
      fprintf(stdout,"%d %s %8.3f\n",conta, nome, saldo);
      fscanf(f1,"%d %s %lf",&conta, nome, &saldo);      
    } // while
    
    fclose(f1); // fechando arquivo
 } //else
 
 
 system("Pause");
 return(0); 
}
