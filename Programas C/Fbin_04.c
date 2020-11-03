// Exemplo: Leitura dos dados de um arquivo existente e criacao
// ======== de um outro arquivo com os dados invertidos (termos de posicao).


#include<stdio.h>
#include<stdlib.h>


FILE *fp,*f1;

/***************************************************************/
/*********** Le o arquivo apontado por *fp,**********************/
/********** inverte-o e escreve no arquivo apontado por *f1 ****/
/***************************************************************/
/***************************************************************/

Inverte_Dados_Arquivo(FILE *fp, FILE *f1, size_t tam) {
int valor ;
long int nc,pos,t;

   fseek(fp,0, SEEK_END);            // Posiciona o ponteiro no final do arquivo
   
   nc = ftell(fp)/tam;               //encontra o numero de componentes do arquivo
   
   
   pos = (nc-1) ;                    //posicoes variando de 0 a pos (ultimo elemento)
 
 while( pos >= 0 ) {

   fseek(fp,pos*tam,SEEK_SET);       //posiciona o ponteiro na posicao a ser lida
   fread(&valor,sizeof(int),1,fp);   //le o valor
   fwrite(&valor,sizeof(int),1,f1);  // escreve no outro arquivo
   fprintf(stdout,"%d\n",valor);     //escreve na tela
   pos --; 
   }  //while
   
} //Inverte_Dados_Arquivo


int main(void){

   if( ( fp=fopen( "numeros.dad","rb+" ) ) == NULL ){
      printf("\nEsse arquivo nao pode ser aberto!\n");
      system("Pause");
      exit(1);
   }
   
   if( ( f1=fopen( "invertido.dad","wb" ) ) == NULL ){
      printf("\nEsse arquivo nao pode ser aberto!\n");
      system("Pause");
      exit(1);
   }

   Inverte_Dados_Arquivo(fp, f1,(long)sizeof(int) );

   fclose(f1);
   fclose(fp);
   
system("Pause");
return(0);

}

// Exercicio: Elabore uma funcao para imprimir os dados (conteudo)
// de um arquivo binario. 
