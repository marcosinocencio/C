#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRNULA "                          "

typedef char Str1[50];


typedef enum mes {janeiro = 1,fevereiro,marco,abril,maio,junho,julho,
                  agosto,setembro,outubro,novembro,dezembro} MES;

typedef struct data {
			          int dia;
			          MES mes;
			          int ano;
		             }DATA;

typedef struct notas {
              		   float not_prova[5];
                       float not_traba[6];
                       float med_final; 				
					 } NOTAS;

typedef struct dados_pessoais {
					    Str1 nome;
					    DATA nasc;
		                NOTAS notas;
                        } DADOS_PESSOAIS;


int main() {

 DADOS_PESSOAIS  alunos[40];
 DADOS_PESSOAIS  aluno1, *ptral;
 MES m1;
  
    // preenchimento básico de alguns dados só para ilustrar acesso e outros detalhes.
    // Observem que voces terão que fazer a consistência dos dados de entrada. Por exemplo, 
    // você deve garantir que o dia de aniversário do aluno deve estar entre 1 e 31.
  
  strcpy(aluno1.nome, "Jose Joao da Silva");
  aluno1.nasc.dia = 12; 
  aluno1.nasc.mes = fevereiro;		
  aluno1.nasc.ano = 1985;
  aluno1.notas.not_prova[0] = 7.5;
  aluno1.notas.not_prova[1] = 7.0;
  aluno1.notas.not_prova[2] = 8.5;
  aluno1.notas.not_prova[3] = 7.0;
  aluno1.notas.not_prova[4] = 7.8;
  aluno1.notas.med_final =   7.56;   // chamar função para calcular a média
  
  ptral = &aluno1;
  
  // impressao das componentes por meio de uma variavel
  
  printf("==========================================================================\n\n");
 
  printf("ALUNO: %s ",aluno1.nome); printf(STRNULA); 
  printf(" NASC: %2d / %2d / %4d  \n",aluno1.nasc.dia, aluno1.nasc.mes, aluno1.nasc.ano);
  printf("\nProvas (P1,P2,P3,P4) = (%3.1f,%3.1f,%3.1f,%3.1f)\n\n",aluno1.notas.not_prova[0],
  aluno1.notas.not_prova[1],aluno1.notas.not_prova[2],aluno1.notas.not_prova[3]);
  
  
  printf("==========================================================================\n\n");
  
  // impressao das componentes por meio de um ponteiro para a variavel (ptra1)
    
  printf("==========================================================================\n\n");
 
  printf("ALUNO: %s ",(*ptral).nome); printf(STRNULA); 
  printf(" NASC: %2d / %2d / %4d  \n",ptral->nasc.dia, aluno1.nasc.mes, aluno1.nasc.ano);
 
  printf("==========================================================================\n\n");
  
  
  
  
  
  puts("\n\n\n");
  printf("Tamanho em bytes da estrutura DADOS_PESSOAIS : %d \n\n\n", sizeof(DADOS_PESSOAIS));
  printf("Tamanho em bytes da estrutura DADOS_PESSOAIS : %d \n\n\n", sizeof(alunos));
  
  system("Pause");
  return(0);
}
