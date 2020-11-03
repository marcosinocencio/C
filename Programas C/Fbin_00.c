// Exemplo 0: Cria Arquivo de inteiros de 1 a n

#include<stdio.h>
#include<stdlib.h>


FILE *fp;
int i,n;


int main(void){
 if( ( fp=fopen( "numeros.dad","wb" ) ) == NULL ){
   printf( "\nEsse arquivo nao pode ser aberto!\n" );
   system("pause>nul");
   exit(1);}
   
printf("\nForneca a quantidade de numeros a ser escrita no arquivo: ");
 scanf( "%d",&n );

  for( i = 0; i < n; i++ ){
   fwrite( &i, sizeof(int), 1, fp );             //escreve no arquivo de nome numeros.dad
   fprintf(stdout,"%d\n",i);     //escreve na tela
  } 
 
  fprintf(stdout,"\n\n Arquivo Criado com Suucesso!!!\n");
  fclose(fp);//fecha o arquivo.
 
 
 system("pause");
 return(0); 
}           
