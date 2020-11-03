#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX2 1000    // numero maximo de numeros aleatorios


void Associa_Valores_Arquivo(FILE *F1,int Dim) {

int i = 0, num;   // indice para percorrer o array
time_t t;
   
   
   fseek(F1,0,0);
   srand((unsigned) time(&t));
   for( i = 0; i < Dim; i++ ){
      num = rand();
      fwrite(&num,sizeof(int),1,F1);        //escreve no arquivo de nome numeros.dad
      //fprintf(stdout,"%d\n",num);     //escreve na tela
  }  
return; 
} // Associando_Valores_Array

int Leitura_NComponentes_Arquivo(void) { 
int dim, continua;
    
  do
   {
     continua = 0; 
     printf("Insira o numero de componentes do arquivo (>= 1 && <= 1000): ");
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX2) ) continua = 1;
   }
  while ( continua ); 

return(dim);
} // Leitura_Dimensao_Array





/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
void Imprimir_Valores_Arquivo(FILE *F1) {

long int ncomp = 0;	      // numero de componentes
int i, num;
 
  fseek(F1,0,2);
  ncomp = ftell(F1)/sizeof(int);
  
  
 //fseek(F1,0,0);
 for (i=0; i < ncomp; i++) {   
    fseek(F1,sizeof(int)*i,0);
    fread(&num,sizeof(int),1,F1);
    printf(" %d \n ",num);    
  }
 
} // Imprimir_Valores_Arquivo

/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/

void Ordenar_Arquivo(FILE *F1){
long int i = 1, ncomp = 0;
int j, continua=1, exp1;
int num1, num2, aux;

  fseek(F1,0,2);
  ncomp = ftell(F1)/sizeof(int);
 
  //printf("NComp: %ld\n\n",ncomp);
 
 while ( (i < ncomp ) && continua ) { // controla o numero de varreduras
     continua = 0;
     exp1 = ncomp - i;     
     for (j = 0; j < exp1; j++)   {   // aponta para as posicoes do array
      fseek(F1,j*sizeof(int),0);
      fread(&num1,sizeof(int),1,F1);
      fseek(F1,(j+1)*sizeof(int),0);
      fread(&num2,sizeof(int),1,F1);     

      if (num1 > num2) {  // permutando elementos de posicao
         aux = num1;
         num1 = num2;
         num2 = aux;
         fseek(F1,j*sizeof(int),0);
         fwrite(&num1,sizeof(int),1,F1);
         fwrite(&num2,sizeof(int),1,F1);
         continua = 1;          // realizou uma troca
      }  //if

	 }  //for
     i++;
   }  //while


}



/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/

int main(){
int 	i,              // indice para percorrer o array
	    n1;             // tamanho real do array vetor1
	    
FILE    *fp;



  n1 = Leitura_NComponentes_Arquivo();
  
  if( ( fp = fopen( "numeros1.dad","wb+" ) ) == NULL ){
   printf( "\nEsse arquivo nao pode ser aberto!\n" );
   system("pause>nul");
   exit(1);
  }
  
  Associa_Valores_Arquivo(fp,n1);
  Imprimir_Valores_Arquivo(fp);
  puts("\n\n\n");
  Ordenar_Arquivo(fp);
  Imprimir_Valores_Arquivo(fp);
  fclose(fp);
  
  
  
    puts("\n\n\n");
   
  //Ordenacao_Bolha2(vetor1,n1);
  //Imprimindo_Valores_Array(vetor1,n1);   
  
 
  
  printf("\n\n Acabou!!!"); 
  puts("\n\n\n");
  system("Pause");
  return(0);
}
