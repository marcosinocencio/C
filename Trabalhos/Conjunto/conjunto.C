#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/*Alunos:    Marcos Vinicius Inocencio   RA: 1295357
                Luis Felipe L. Santos       RA: 1295900       #####\n");
                   Haroldo S. Teruya           RA: 1305301       #####\n");     */


FILE *f1, *f2, *f3;

typedef struct{
        char *str;
        int tamanho[1];
        } NOME;

void troca( int *a , int *b );
void bubble( int *A , int n );
void Array( int *A, int n );
void cria( int *A , int arg_c , int n , char *nome );
void cria_b( int *A , int arg_c , int n , char *nome );
int verif_parametro( char *elemento );
int operacao( int *A , int arg_c , char *arg_v , NOME *vetor );
void instrucao();
void file_to_memory( int *B , int *C , NOME *nome , int *tamanho );
int str_array( int *A , char *C );
int interseccao(int *a, int *b, int *c, int n1, int n2  );
int uniao(int *a, int *b, int *c, int n1, int n2 );
void novo_conjunto( int *A , int n , char *nome );
int diferenca( int *a , int *b , int *c, int n1, int n2 );
void imprime_t( char *nome );
void novo_conjuntob( int *A, int n , char *nome );
void fileb_to_memory( int *B , int *C , NOME *nome , int *tamanho );
void imprime_b( char *nome );

//==============================================================================
void troca( int *a, int *b ){
int aux;
     aux = *a;
     *a = *b;
     *b = aux;
}
//==============================================================================
//< BUBBLE >====================================================================
//Função de ordenação de um
void bubble( int *A, int n ){
int i=1, cont=1;

while( cont==1 ){
       cont=0;
       for( i=1 ; i<n ; i++ )
              if( *(A+i-1) > *(A+i) ){
                  cont=1;
                  troca(A+i-1,A+i);
              }
}      
}
//==============================================================================
//< ARRAY com os 'n' elementos arbitrários gerados randomicamente >=============
void Array( int *A, int n ){
int i=0; //variável de contagem
time_t t;

  srand((unsigned) time(&t));
  for (; i<n ; i++ )*(A+i)=rand()%10;

bubble(A,n);//chama uma função de ordenação
}//void

//==============================================================================
//< CRIA um arquivo do tipo texto com 'n' elemento arbitrário >=================
void cria( int *A , int arg_c , int n , char *nome ){
int i;//variavel contadora

//cria ou sobrepoe caso ja exista...............................................
if( (f1=fopen(nome,"w"))==NULL ){ printf("Erro na abertura do arquivo %s",nome); exit(1); }
//..............................................................................
Array(A,n);//chama uma função onde insere os 'n' elementos arbitrarios gerados randomicamente

for( i=0; i<n; i++ ){ fprintf(f1," %d",*(A+i)); }
fprintf(f1,"%c",' ');

fclose(f1);//salva e fecha o arquivo
printf("\nO arquivo %s foi gerado com sucesso !!! \n",nome);
}//void

//==============================================================================
//< VERIFICA "NOME" >===========================================================
//Essa função verifica se o nome do arquivo é válido, ou seja, o primeiro caracter
//não deve ser um numero.
int verif_parametro( char *elemento ){
int aux = ((int)*(elemento))-48;//verifica o valor ordinal de acordo com a tabela
if( aux>=0 && aux<=9 )return(1);
else return(0);
}//int

//==============================================================================
//< IMPRIME_T >=================================================================
//Imprime na tela o conteúdo de um arquivo com o nome "arbitrario" do tipo texto
void imprime_t( char *nome ){
int i; 
//abre um arquivo para ler......................................................
if( (f1=fopen(nome,"r"))==NULL  ){ printf("\nErro na abertura do arquivo %s\n",nome); system("pause"); exit(1); } 
//..............................................................................  

printf("\n\n");
while( fscanf(f1,"%d",&i)!= EOF ) //enquanto não for fim do arquivo
       printf(" [%d]",i);         //imprime na tela

printf("\nArquivo %s lido com sucesso!\n",nome);
system("pause");
exit(0);//fecha o programa
}//void

//==============================================================================
//< IMPRIME_b >=================================================================
//Imprime na tela o conteúdo de um arquivo com o nome "arbitrario" do tipo binario
void imprime_b( char *nome ){
int i; 
//abre um arquivo para ler......................................................
if( (f1=fopen(nome,"rb"))==NULL  ){ printf("\nErro na abertura do arquivo %s\n",nome); system("pause"); exit(1); } 
//..............................................................................  

printf("\n\n");

fseek( f1 , 0 , SEEK_SET ); //posiciona-se no 'começo' do arquivo o ponteiro 'f1'
while( !feof(f1) ){         //enquanto não for o fim do arquivo
fread( &i , sizeof(int) , 1 , f1 );
     if ( !feof(f1) ){
            printf(" [%d]",i);
     }
}

printf("\nArquivo %s lido com sucesso!\n",nome);
system("pause");
exit(0);//fecha o programa
}//void

//==============================================================================
//< OPERACAO >==================================================================
//Essa função seleciona a operação em que o programa deve executar de acordo com
//os parametros inseridos pelo usuario
int operacao( int *A , int arg_c , char *arg_v , NOME *vetor ){                 

         //if( arg_c==3 && (*arg_v=='t' || *arg_v=='T') ){ leiturat(&vetor[0].str[0]); }return(0);
         if( arg_c==1 )instrucao();
    else if( arg_c==3 && (*arg_v=='t' || *arg_v=='T') )imprime_t( arg_v+3 );
    else if( arg_c==3 && (*arg_v=='b' || *arg_v=='B') )imprime_b( arg_v+3 );
    else if( arg_c==4 && (*arg_v=='t' || *arg_v=='T') && verif_parametro(&vetor[0].str[0])==1 )return(1);
    else if( arg_c==6 && (*arg_v=='t' || *arg_v=='T') && *(arg_v+2)=='1' && verif_parametro(&vetor[0].str[0])==0 && verif_parametro(&vetor[1].str[0])==0 && verif_parametro(&vetor[2].str[0])==0 )return(2);
    else if( arg_c==6 && (*arg_v=='t' || *arg_v=='T') && *(arg_v+2)=='2' && verif_parametro(&vetor[0].str[0])==0 && verif_parametro(&vetor[1].str[0])==0 && verif_parametro(&vetor[2].str[0])==0 )return(3);
    else if( arg_c==6 && (*arg_v=='t' || *arg_v=='T') && *(arg_v+2)=='3' && verif_parametro(&vetor[0].str[0])==0 && verif_parametro(&vetor[1].str[0])==0 && verif_parametro(&vetor[2].str[0])==0 )return(4);
    else if( arg_c==4 && (*arg_v=='b' || *arg_v=='B') && verif_parametro(&vetor[0].str[0])==1 )return(5);
    else if( arg_c==6 && (*arg_v=='b' || *arg_v=='B') && *(arg_v+2)=='1' && verif_parametro(&vetor[0].str[0])==0 && verif_parametro(&vetor[1].str[0])==0 && verif_parametro(&vetor[2].str[0])==0 )return(6);
    else if( arg_c==6 && (*arg_v=='b' || *arg_v=='B') && *(arg_v+2)=='2' && verif_parametro(&vetor[0].str[0])==0 && verif_parametro(&vetor[1].str[0])==0 && verif_parametro(&vetor[2].str[0])==0 )return(7);
    else if( arg_c==6 && (*arg_v=='b' || *arg_v=='B') && *(arg_v+2)=='3' && verif_parametro(&vetor[0].str[0])==0 && verif_parametro(&vetor[1].str[0])==0 && verif_parametro(&vetor[2].str[0])==0 )return(8);

return(0);//case nenhuma opção não seja selecionado
}//void
//==============================================================================
//< INSTRUCAO essa funcao mostra na tela a instruçoes para o so desse programa >
void instrucao(){
printf("Instrucoes Gerais de uso:\n\n");
printf("Para utilizar o programa, e necessario passar para ele os parametros da operacao desejada. Segue abaixo a lista dos parametros, e uma breve explicacao sobre cada um deles:\n\n");

//criando um arquivo
printf("Criando um arquivo: \nOs parametros serao - tipo nome n - onde: \ntipo  - define o tipo de arquivo. Usa-se t para texto e b para binario. \nnome  - define o nome do arquivo a ser criado. \nn     - define o numero de elementos que o arquivo ira conter. \n");

//intersecção
printf("\nInterseccao entre arquivos: \nOs parametros serao - tipo 1 nome1 nome2 nome3 - onde: \ntipo      - define o tipo de arquivo. Usa-se t para texto e b para binario. \n1         - numero que define a operacao, nesse caso a interseccao. \nnome1     - nome do primeiro arquivo escolhido (o arquivo deve existir). \nnome2     - nome do segundo arquivo escolhido (o arquivo deve existir). \nnome3     - nome do arquivo onde ficara armazenada a interseccao(o arquivo deve existir). \n");

//uniao
printf("\nUniao entre arquivos: \nOs parametros serao - tipo 2 nome1 nome2 nome3 - onde: \ntipo      - define o tipo de arquivo. Usa-se t para texto e b para binario. \n1         - numero que define a operacao, nesse caso a uniao. \nnome1     - nome do primeiro arquivo escolhido (o arquivo deve existir). \nnome2     - nome do segundo arquivo escolhido (o arquivo deve existir). \nnome3     - nome do arquivo onde ficara armazenada a uniao(o arquivo deve existir). \n");

//subtracao
printf("\nSubtracao entre arquivos: \nOs parametros serao - tipo 3 nome1 nome2 nome3 - onde: \ntipo      - define o tipo de arquivo. Usa-se t para texto e b para binario. \n1         - numero que define a operacao, nesse caso a subtracao. \nnome1     - nome do primeiro arquivo escolhido (o arquivo deve existir). \nnome2     - nome do segundo arquivo escolhido (o arquivo deve existir). \nnome3     - nome do arquivo onde ficara armazenada a subtracao(o arquivo deve existir). \n");

//impressao
printf("\nImpressao de um arquivo: \nOs parametros serao - tipo nome - onde: \ntipo      - define o tipo de arquivo. Usa-se t para texto e b para binario. \nnome      - nome do arquivo a ser impresso. \n");

puts("\n\n");
printf("#####         Alunos:    Marcos Vinicius Inocencio   RA: 1295357       #####\n");
printf("#####                    Luis Felipe L. Santos       RA: 1295900       #####\n");
printf("#####                    Haroldo S. Teruya           RA: 1305301       #####\n");

system("pause"); exit(0);
}//void
//==============================================================================
//< DE STRING PARA ARRAY >======================================================
int str_array( int *A , char *C ){
int i=0, j=0;//variavei contadora

for(  i=0 , j=0 ; *(C+i)!='\0' ; i++ , j++ ){
      if( *(C+i)==' ' )i++;      
      while( *(C+i)!=' ' && *(C+j)!='\0' ){
           *(A+j) =  (*(A+j))*10 + (((int)*(C+i))-48);
           i++;
      }//while
}//for
return(j);//retorna o tamanho do array
}//int

//==============================================================================
//< ARQUIVO PARA A MEMORIA >====================================================
//Essa função armazena os dados do arquivo e insere em um array
void file_to_memory( int *B , int *C , NOME *nome , int *tamanho ){
char aux1[100], aux2[100], aux3[100];
int i=0, n1, n2, n3;

//leitura do arquivo caso exista................................................
if( (f1=fopen(nome[0].str,"r"))==NULL  ){ printf("Erro na abertura do arquivo %s",nome[0].str); exit(1); }
if( (f2=fopen(nome[1].str,"r"))==NULL  ){ printf("Erro na abertura do arquivo %s",nome[1].str); exit(1); } 
//..............................................................................  

while ( !feof(f1) ){
     *(aux1+i) = fgetc(f1);   
     if( !feof(f1) )i++;
}
*(aux1+i) = '\0';

i=0;
while ( !feof(f2) ){
     *(aux2+i) = fgetc(f2);   
     if( !feof(f2) )i++;
}
*(aux2+i) = '\0';

//Passa os dados da string para um array e armazena o tamanho do arrays.........
*(tamanho) = str_array( B , aux1 );
*(tamanho+1) = str_array( C , aux2 );
//..............................................................................

fclose(f1);//salva e fecha o arquivo
printf("Arquivo criado com sucesso!\n");
fclose(f2);//salva e fecha o arquivo
printf("Arquivo criado com sucesso!\n");
}
//==============================================================================
//< NOVO CONJUNTO TIPO TEXTO >==================================================
//Cria um arquivo do tipo texto, caso ele já exista com o mesmo nome ele sobrepoe;
void novo_conjunto( int *A , int n , char *nome ){
int i;     

//cria o arquivo................................................................
if( (f3=fopen(nome,"w"))==NULL ){ printf("Erro na abertura do arquivo %s",nome); exit(1); }
//..............................................................................

for( i=0; i<n; i++ ){ fprintf(f3," %d",*(A+i)); }//componente por componente é inserido no arquivo
fprintf(f1,"%c",' ');

fclose(f1);//salva e fecha o arquivo
printf("\nO arquivo %s foi gerado com sucesso !!! \n",nome);
}

//==============================================================================
//< NOVO CONJUNTO BINARIO >=====================================================
//Cria um arquivo do tipo binário, caso ele já exista com o mesmo nome ele sobrepoe;
void novo_conjuntob( int *A, int n , char *nome ){
int i;//variavel contadora

//cria o arquivo ...............................................................
if( (f3=fopen(nome,"wb"))==NULL ){ printf("Erro na abertura do arquivo %s",nome); exit(1); }
//...............................................................................

for( i=0 ; i<n ; i++ ){ //componente por componente é inserido no arquivo
     fwrite( &(*(A+i)) , sizeof(int) , 1 , f1 ); 
     fprintf(stdout,"%d\n",*(A+i));               //mostra na tela os valores
     }  

fclose(f1);//salva e fecha o arquivo ligado ao ponteiro 'f1'
printf("\nO arquivo %s foi gerado com sucesso !!! \n",nome);
}

//==============================================================================
//< INTERSECÇÂO >===============================================================
//Essa função cria o novo conjunto onde o conjunto 'a' e 'b' tem em comum
int interseccao(int *a, int *b, int *c, int n1, int n2 ) {
int  j, i, k=0;//variaveis contadora

for( i=0; i<n1 ; i++ ){
    for( j=0 ; j<n2 ; j++ ){  
        if( *(a+j) == *(b+i)){  
            *(c+k)= *(a+j);
            k++;
        }
    }
}
return(k);//retorna o valor do tamanho do novo conjunto
}

//==============================================================================
//< UNIÃO >=====================================================================
//Essa função recebe o conjunto 'a' e o conjunto 'b', onde a resultante é a 'c'
int uniao(int *a, int *b, int *c, int n1, int n2 ) {
int  j, i, k=0;//variaveis contadora

for( i=0 ; i<n2 ; i++ ){ *(c+k)=*(a+i); k++; }
for( j=0 ; j<n1 ; j++ ){ *(c+k)=*(b+j); k++; }

return(k);//retorna o valor do tamanho do novo resultante
}//void

//==============================================================================
//< FUNÇÂO DIFERENÇA >==========================================================
//Essa função recebe o conjunto 'a' e o conjunto 'b', onde a resultante é o conjunto 'c', 'a'-'b'='c'.
int diferenca( int *a , int *b , int *c, int n1, int n2 ){
int  j, i, k=0, cont=0;//variaveis contadora

for( i=0 ; i<n1 ; i++ ){
    for( j=0 ; j<n2 ; j++ ){
        if( *(a+i)!=*(b+j ))cont=1;
        else{
            cont=0;
            j=n2;
        }//else
    }//for
    if( cont==1 ){
        *(c+k)= *(a+i);
        k++;
    }//if
}//for
return(k);//retorn o tamanho do novo conjunto resultante
}//void

//==============================================================================
//< FUNÇÂO CRIA_B >=============================================================
//cria um arquivo binario resultante da operação
void cria_b( int *A , int arg_c , int n , char *nome ){
int i;

//abertura dos arquivos ........................................................
if( (f1=fopen(nome,"wb"))==NULL ){ printf("Erro na abertura do arquivo %s",nome); system("pause>nul"); exit(1); }
//..............................................................................

Array(A,n);//chama a função onde passara valores inteiros randomicos

//inseri no arquivo os 'n' valores inteiros
for( i=0 ; i<n ; i++ ){ 
     fwrite( &(*(A+i)) , sizeof(int) , 1 , f1 ); //insere no arquivo componente por componente
     fprintf(stdout," [%d]",*(A+i));             //mostra na tela os dados inseridos
     }            

fclose(f1);//salva e fecha o arquivo ligado a esse ponteiro
printf("\nO arquivo %s foi gerado com sucesso !!! \n",nome);
}

//==============================================================================
//< DE ARQUIVO BINARIO PARA A MEMORIA >=========================================
void fileb_to_memory( int *B , int *C , NOME *nome , int *tamanho ){
int i=0, n1=0, n2=0, j=0, k=0;

//abertura dos arquivos ........................................................
if( (f1=fopen(nome[0].str,"rb"))==NULL  ){ printf("Erro na abertura do arquivo %s",nome[0].str); exit(1); }
if( (f2=fopen(nome[1].str,"rb"))==NULL  ){ printf("Erro na abertura do arquivo %s",nome[1].str); exit(1); }    
//..............................................................................

fseek( f1 , 0 , SEEK_SET ); //posiciona-se no 'começo' do arquivo o ponteiro 'f1'
while( !feof(f1) ){         //enquanto não for o fim do arquivo
     if ( !feof(f1) ){
            fread( &n1 , sizeof(int) , 1 , f1 );
            *(B+i) = n1;
	        i++;
     }
}
*(tamanho) = i-1;  //quantidade de elementos 'f1'

puts("\n");

fseek( f2 , 0 , SEEK_SET ); //posiciona-se no 'começo' do arquivo o ponteiro 'f2'
while( !feof(f2) ){         //enquanto não for o fim do arquivo
     if ( !feof(f2) ){
            fread( &n2 , sizeof(int) , 1 , f2 );
            *(C+k) = n2;
	        k++;
     }
}
*(tamanho+1) = k-1; //quantidade de elementos 'f2'

fclose(f1); //salva e fecha o arquivo ligado a esse ponteiro
printf("\nO arquivo foi gerado com sucesso!\n");
fclose(f2); //salva e fecha o arquivo ligado a esse ponteiro
printf("\nO arquivo foi gerado com sucesso!");
}

//==============================================================================
//< MAIN >======================================================================
int main( 
    int arg_c ,      //argumento contadora: quantidade componentes itroduzidos pelo usuário via linha de comando
    char *arg_v[] )  //argumento vetor: um vetor onde cada componente armazena um dado. condição de finalizção é 'NULL' 
    {                //início


//declaração de arrays, struct e de uma variável para utilizar nas operaçoes
int A[1000]={0}, 
    B[1000]={0},
    C[1000]={0}, 
    i,             //variável contadora e utilizado para aritmética de ponteiros
    k;             //variavel usada para armazenar o "tamanho" do array resultante
NOME nome[3];      //usado como auxiliar para armazenar os nomes dos arquivos e o 'tamanho' dos arrays 


//..............................................................................
//varre todo os componentes introduzidos pelo usuario armazenando os nomes e con-
//contando as componenes, facilitando as operações sobre os arquivos
for( i=0 ; i<arg_c ; i++ ){                                                     
//   printf("\n=[ %d,%s ]",i,*(arg_v+i));                                       //esse comando "mostra" na tela bloco por bloco os componentes de arg_v
     if( i==2 )nome[0].str=*(arg_v+i);
     else if( i==3 )nome[1].str=*(arg_v+i); //>>> facilida na manipulação do arquivo.
     else if( i==4 )nome[2].str=*(arg_v+i); //>>> armazena os nomes na memória usan-
     else if( i==5 )nome[3].str=*(arg_v+i); //>>> 'struct'(s) 
}
//..............................................................................

printf("\n==%d==\n",operacao( A , arg_c , arg_v[1] , &nome[1] ));        //agr_v 1
system("pause");

switch( operacao(A,arg_c,arg_v[1], &nome[1]) ){                                 //permite selecionar a operação válida que o programa irá executar de acordo com oque o usuário introduzio
/*..............................................................................
        case 1: cria um arquivo com o nome de acordo que o usuario inserio.
                Cria 'N' elementos com o valor inteiro randomicamente em um array 
                e então passa para o arquivo                                    */
        case 1: cria( A , arg_c , atoi(*(arg_v+3)), //quantidade de elementos
                                  &nome[0].str[0]); //nome do arquivo a ser criado
                break; 

/*..............................................................................
        case 2: cria um arquivo resultante da interseccao entre dois arquivos já
                criados. Primeiro ele faz a leitura dos dois arquivos e converte
                seus valores em inteiros passando para um array e entao fazer a
                operação de interseccao                                         */                     
        case 2: file_to_memory( B , C , &nome[1] , &nome[0].tamanho[0] ); 
                k = interseccao( C , B , A , 
                         nome[0].tamanho[0],                     //tamanho do arquivo 'C'
                         nome[0].tamanho[1]);                    //tamanho do arquivo 'B'
                novo_conjunto( A , k , &nome[3].str[0] );        //cria o um novo arquivo de acordo com o novo conjunto
                break;
             
             
/*..............................................................................
        case 3: cria um arquivo resultante da união de dois arquivos já criados.
                Primeiro ele faz a leitura dos dois arquivos e converte seus va-
                lores em inteiros caracter por caracter passando para um array e
                entao executar a operação de união                              */ 
        case 3: file_to_memory( B , C , &nome[1] , &nome[0].tamanho[0] );       
                k = uniao( C , B , A , nome[0].tamanho[0],  //tamanho da função 'B'
                                       nome[0].tamanho[1]); //tamanho da função 'C'
                bubble(A,k);                                //chama a função de ordenaçãp 'bubble'                
                novo_conjunto( A , k , &nome[3].str[0] );   //chama a função que cria o novo arquivo de acordo com o conjunto'c'
                break;
                                
/*..............................................................................
        case 4: cria um arquivo resultante da subtração de dois arquivos já cri-
                ados. Primeiro ele faz a leitura dos dois arquivos e converte 
                seus valores em inteiros caracter por caracter passando para um 
                array e entao executar a operação de subtração.                 */ 
        case 4: file_to_memory( B , C , &nome[1] , &nome[0].tamanho[0] );
                k = diferenca( B , C , A , nome[0].tamanho[0],  //tamanho do array 'B'
                                           nome[0].tamanho[1]); //tamanho do array 'C'
                bubble(A,k);                                    //chama a função de ordenaçãp 'bubble'
                novo_conjunto( A , k , &nome[3].str[0] );       //chama a função que cria o novo arquivo de acordo com o conjunto'c'
                break;
                                
/*..............................................................................
        case 5: cria um arquivo binário de acordo com o nome introduzido pelo
                usuário com 'n' elementos inseridos arbitrariamente             */ 
        case 5: cria_b( A , arg_c , atoi(*(arg_v+3)), //quantidade de elementos a serem inseridos
                                    &nome[0].str[0]); //nome do arquivo a ser criado
                break; 
                  
/*..............................................................................
        case 4: cria um arquivo binário resultante da interscçãoção de dois 
                arquivos já criados. Primeiro ele faz a leitura dos dois arquivos
                e converte seus valores em para um array e entao executar a 
                operação de subtração.                                          */ 
        case 6: fileb_to_memory( B , C , &nome[1] , &nome[0].tamanho[0] );
                k = interseccao( C , B , A , nome[0].tamanho[0] , //tamanho do array 'B'
                                             nome[0].tamanho[1]); //tamanho do array 'C'
                bubble(A,k);                                      //chama a função de ordenação 'bubble'
                novo_conjuntob( A , k , &nome[3].str[0] );     
                break;
        
/*..............................................................................
        case 7: cria um arquivo resultante da união de dois arquivos já criados. 
                Primeiro ele faz a leitura dos dois arquivos e converte valores 
                array e entao executar a operação de subtração.                 */ 
        case 7: fileb_to_memory( B , C , &nome[1] , &nome[0].tamanho[0] );
                k = uniao( C , B , A , nome[0].tamanho[0] , nome[0].tamanho[1] );
                bubble(A,k);                                    //chama a função de ordenação 'bubble'
                novo_conjuntob( A , k , &nome[3].str[0] ); 
                break;

/*..............................................................................
        case 8: cria um arquivo resultante da diferença de dois arquivos já criados. 
                Primeiro ele faz a leitura dos dois arquivos e converte valores 
                em array e entao executar a operação de subtração.                 */                
        case 8: fileb_to_memory( B , C , &nome[1] , &nome[0].tamanho[0] );
                k = diferenca( B , C , A , nome[0].tamanho[0] , nome[0].tamanho[1]  );
                bubble(A,k);                                    //chama a função de ordenação 'bubble'
                novo_conjuntob( A , k , &nome[3].str[0] ); 
                break;                
}
system("pause");
return(0);
}//fim
//==============================================================================
