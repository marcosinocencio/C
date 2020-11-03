// EXEMPLOS DE DEFINIÇÃO DE TIPOS ENUMERÁVEIS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long double Real;
typedef char Str50[50];
typedef char Str20[20];
typedef char Str10[10];
typedef char Str2[2];


typedef enum meses {janeiro = 1,fevereiro,marco,abril,maio,junho,julho,agosto,setembro,outubro,novembro,dezembro} MES;
typedef enum sexo {feminino, masculino} SEXO;
typedef enum est_civil {solteiro, desquitado, divorciado, casado, viuvo} EST_CIVIL;
typedef enum cor_olhos {azul, verde, castanho} COR_OLHOS;
typedef enum cor_cabelo {loiro, moreno, ruivo,outros} COR_CABELO;


typedef enum localizacao {
	  nenhuma  = 0,
	  fronteira = 1,             // localiza-se na fronteira do polígono
	  interior = 2               // localiza-se no interior do polígono
	} LOCATION;
	
	
// EXEMPLOS DE DEFINIÇÃO DE ESTRUTURAS BÁSICAS
	
typedef struct point_2D {
	        Real             coord_x;       // variavel para armazenar a coordenada x de um ponto 2D
	        Real             coord_y;       // variavel para armazenar a coordenada y de um ponto 2D
  	      } POINT_2D;
	
	
typedef struct segmento {
	        int              id;         // indicador do segmento
	        POINT_2D         p1;         // ponto inicial do segmento 
	        POINT_2D         p2;         // ponto final do segmento 
	      } SEGMENTO;
 	
	
typedef struct box {
	 POINT_2D         p1,     // canto esquerdo superior
			          p2;     // canto direito inferior
	} BOX;
 
   
typedef struct endereco {
            Str50 logradouro;
            int  numero;
            Str10 complemento;
			Str20 bairro,
				  cidade;
      		Str2  estado;
        	Str10 cep;
 		  }ENDERECO;

typedef struct data  {
			int dia;
			MES mes;
			int ano;
		   }DATA;

typedef struct dados_pessoais {
		    DATA data_nasc;
		    Str20  tel_res;
		    Str20  rg, cpf;
		    SEXO   sexo;			// estes últimos quatro atributos poderiam estar
		    EST_CIVIL est_civil;    // agrupados numa única estrutura
		    COR_OLHOS cor_olhos;
		    COR_CABELO cor_cabelo;
		  } DADOS_PESSOAIS;

typedef struct filiacao {
            Str50 pai, mae;
			Str50 prof_pai, prof_mae;
          } FILIACAO;
          
typedef struct notas {
              		   float not_prova[5];
                       float not_traba[6];
                       float med_final_pr;
                       float med_final_tr; 				
					 } NOTAS;

typedef struct disciplina {
	        Str20   nome_dis;  // Nome da Disciplina
	        int    codigo_dis;
			NOTAS  res;
          } DISCIPLINA;


typedef struct aluno {
			int ra; 	// variando entre 01 e 50
			Str50 nome;
			ENDERECO endereco;
			DADOS_PESSOAIS dados_pessoais;
			FILIACAO filiacao;
			DISCIPLINA   disc1, disc2, disc3, disc4, disc5;		// 5 disciplinas
		  } ALUNO;



int main(void){

ALUNO a[100];


   printf("\n\n Tamanho do inteiro : %d", sizeof(int));
   
   printf("\n\n Tamanho do registro Disciplina: %d", sizeof(DISCIPLINA));
   printf("\n\n Tamanho do registro Notas: %d", sizeof(NOTAS));
   printf("\n\n Tamanho do registro Alunos: %d", sizeof(ALUNO));
   printf("\n\n Tamanho do registro DATA: %d", sizeof(DATA));
   printf("\n\n Tamanho do Array de Notas: %d", sizeof(a));


   printf("\n\n");
system("Pause");
return(0);
}
	
	
