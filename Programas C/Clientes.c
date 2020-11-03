// Criação de um arquivo sequencial
// Extraído do Livro do Deitel


#include <stdio.h>
#include <stdlib.h>

#define MAX 40

int  main(void) {
     
int             conta;       // numero da conta
char            nome[MAX];  // nome da conta (nome simples)
double          saldo;      // saldo da conta

FILE *f1;       // variável ponteiro de arquivo

 if ( (f1=fopen("clentes.dad","w")) == NULL ) {
    printf("Erro na abertura do arquivo clientes.dad");
    exit(1);      // saída incondicional do programa
    }
 else {
    printf("Introduza o numero da conta, nome e saldo : \n");
    printf("Digite fim de arquivo para terminar a entrada: ");  //CTRL + z (Windows)     
    printf("? "); 
    scanf("%d %s %lf",&conta, nome, &saldo);    // Unix/Linux/MAC OS- CTRL + d
 
    while ( !feof(stdin) ) {
      fprintf(f1,"%d %s %8.3f\n",conta, nome, saldo);
      printf("? ");       
      scanf("%d %s %lf",&conta, nome, &saldo);      
    } // while
    
    fclose(f1); // fechando arquivo
 } //else
 
 printf("O arquivo clientes.dad foi gerado com sucesso !!! ");
  
 system("Pause");
 return(0); 
}
