#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX1 500    // numero maximo de numeros aleatorios
#define MAX2 1000    // numero maximo de numeros aleatorios


/*--------------------------------------------------------*/
int Leitura_Dimensao_Array(void) { 
int dim, continua;
  do
   {
     continua = 0; 
     printf("Insira o numero de componentes do array (>= 1 && <= 1000): ");
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX2) ) continua = 1;
   }
  while ( continua ); 

return(dim);
} // Leitura_Dimensao_Array

/*--------------------------------------------------------*/
void Associa_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array
time_t t;
  
  srand((unsigned) time(&t));
  for ( ; i < Dim; i++) *(Ptr+i) = rand();
 
return; 
} // Associando_Valores_Array

/*--------------------------------------------------------*/
void Imprimindo_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array
 
 for (; i < Dim; i++) 
   printf("\n [%d] = %d ",i,*(Ptr+i));
} // Associando_Valores_Array


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

// Qual e o metodo utilizado ???


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
long int pos;
int 	i,              // indice para percorrer o array
	    n1,             // tamanho real do array vetor1
	    n2,             // tamanho real do array vetor2
	    n3,             // tamanho real do array vetor3
	    vetor1[MAX1],   // array vetor1 para armazenar os elementos   
        vetor2[MAX2],
        vetor3[MAX1],
        maior1, x;	    
FILE    *fp;

  n1 = Leitura_Dimensao_Array();
  Associa_Valores_Array(vetor1,n1);
  printf("\n\n Valores do Vetor1"); 
  Imprimindo_Valores_Array(vetor1,n1);


  if( ( fp = fopen( "num1.dad","wb+" ) ) == NULL ){
    printf( "\nEsse arquivo nao pode ser aberto!\n" );
    system("pause>nul");
    exit(1);
  }
  
  
  //for(i=0;i<n1;i++) fwrite( (vetor1+i),sizeof(int),1,fp); // elemento a elemento

  if ( fwrite(vetor1,sizeof(int),n1,fp) != n1 )
    // printf("Nao foram escritos todos os 10 elementos!!!! \n ");

  puts("\n\n\n");
  rewind(fp);
  fread(vetor2,sizeof(int),n1,fp);// LENDO N1 COMPONENTES DE UMA UNICA VEZ
  printf("\n\n Valores do Vetor2"); 
  Imprimindo_Valores_Array(vetor2,n1);


  printf("\n Qual componente voce gostaria de acessar [1...%d] : ",n1);  
  scanf("%d",&pos); //0 <= pos < n1

  fseek ( fp, (long)(pos)*sizeof(float), SEEK_SET); 	// posicionamento/deslocamento em bytes
  fread ( &x, sizeof(float),1,fp); 			// leitura
  printf( "\n\n Posicao( %d ) = %d   \n\n", pos, x );


    puts("\n\n\n");
  
 
  fclose(fp);
  printf("\n\n Acabou!!!"); 
  puts("\n\n\n");
  system("Pause");
  return(0);
}
