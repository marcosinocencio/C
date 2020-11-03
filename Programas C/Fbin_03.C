#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define  MAX 2

typedef char String[40];

typedef struct data {
	  int dia;
	  int mes;
	  int ano;
	 } DATA;

typedef struct dados {
	  String  nome;
	  int     idade;
	  DATA    nasc;
	} DADOS;




void Tamanho_Arquivo(FILE *Fp, long *Tam, long *Num_Reg, size_t Info) {
 char temp;
 //*Tam = *Num_Reg = 0; 
 
 int f = 0, ff = ftell(Fp);
 printf("\n....%d",ff);
 system("Pause");

 fseek(Fp,0,SEEK_SET);
 
 
 while (!feof(Fp)) {			//    *Tam = ftell(Fp);
    fread(&temp, 1, 1, Fp); 
     if ( !feof(Fp) ) (*Tam)++;
 }
 
 
 *Num_Reg = *Tam/Info;
} // Tamanho_Arquivo()




int main(void) {

DADOS d1;
String str;
int id, i = 0;
long int pos = 0, tamanho_arquivo = 0, num_reg=0;
FILE *fp1;

   if ( (fp1 = fopen("dados1.dad","wb+")) == NULL) {
      printf("Erro na abertura do arquivo dados.dad");
      exit(1);
     }

  // leitura dos dados
  for (; i < MAX; i++) {
      fflush(stdin);
      printf("Introduza o nome do aluno >>"); gets(str);
      strcpy(d1.nome,str);
      printf("Introduza a idade do aluno >>"); scanf("%d",&id );
      d1.idade = id;
      printf("Introduza o dia de nascimento do aluno >>"); scanf("%d",&id );
      d1.nasc.dia = id;
      printf("Introduza o mes de nascimento do aluno >>"); scanf("%d",&id );
      d1.nasc.mes = id;
      printf("Introduza o ano de nascimento aluno >>"); scanf("%d",&id );
      d1.nasc.ano = id;
      fwrite(&d1,sizeof(DADOS),1,fp1);
      printf("\nRegistro(%d) gravado com sucesso\n\n\n",i);
      system("Pause");
    }

   

    
    tamanho_arquivo = num_reg = 0;
    Tamanho_Arquivo(fp1,&tamanho_arquivo, &num_reg, sizeof(DADOS));
     
    printf("\n\n \n              DADOS DOS ALUNOS");
    
/*    
    for (i=0; i < num_reg; i++) {   
       fseek(fp1,sizeof(DADOS)*i,0 );
       fread(&d1,sizeof(DADOS),1,fp1);
       printf("\nNome do Aluno: %s ",d1.nome);
       printf("\nIdade do Aluno: %d ",d1.idade);
       printf("\nData de NAscimento do Aluno: %d/%d/%d \n",d1.nasc.dia, \
       d1.nasc.mes, d1.nasc.ano);          
     }

*/

  rewind(fp1);
  while ( !feof(fp1) ) {
       //fseek(fp1,sizeof(DADOS)*i,0 );
       fread(&d1,sizeof(DADOS),1,fp1);
       if ( !feof(fp1) ) {
           printf("\nNome do Aluno: %s ",d1.nome);
           printf("\nIdade do Aluno: %d ",d1.idade);
           printf("\nData de NAscimento do Aluno: %d/%d/%d \n",d1.nasc.dia, \
           d1.nasc.mes, d1.nasc.ano);  
       }
   }



    
     
 
     
 printf("\n\n\n\n\n");
 printf("\n Tamanho do registro DADOS: %d", sizeof(DADOS));
 printf("\n Tamanho do arquivo dados.dad: %ld",tamanho_arquivo );
 printf("\n Numero de Registros do arquivo dados.dad: %ld",num_reg);
 fclose(fp1);
 
 fprintf(stdout,"\n\n\n");
 system("Pause");
 return(0);

}
