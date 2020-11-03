#ifndef FUNCOES_H
#define FUNCOES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {masculino=1,feminino}SEXO;
typedef enum {solteiro=1,casado,divorciado,viuvo}ESTADO_CIVIL;
typedef enum {castanho=1,azul,verde}COR_OLHOS;
typedef enum {preto=1,loiro,ruivo,outro}COR_CABELO;        
typedef enum {janeiro=1,fevereiro,marco,abril,maio,junho,julho,agosto,setembro,outubro,novembro,dezembro}MESES;

typedef struct{
        MESES mes;
        int dia;
        int ano;
}DATA;


typedef struct{
        float provas[4];
        float trabalho[6];
        float mf;       
}DISCIPLINA;

typedef struct{
        char Nome[50];
        DATA data;
        char Npai[50];
        char Ppai[30];
        char Nmae[50];
        char Pmae[30];
        char Celular[15];
        char RG[15];
        char CPF[20];
        int RA;
        SEXO sexo;
        ESTADO_CIVIL estado_civil;
        COR_OLHOS cor_olhos;  
        COR_CABELO cor_cabelo;
        DISCIPLINA disciplina[4];
}ALUNO;

static ALUNO classe;

void Cadastrar(FILE *f);
void Visualizar(FILE *f, int RA);
void Listar_Alfabetica(FILE *f);
void Decrescente_Nota(FILE *f, int Materia,const char *str);
void Aprovado_Reprovado(FILE *f, int Materia,const char *Nome_Materia);
void Visualiza_Notas_PT(FILE *f, int RA);
void Nota_Maior(FILE *f,int Materia, float valor,const char *Nome_materia);
void Nota_Menor(FILE *f,int Materia, float valor,const char *Nome_materia);
void Nota_Intervalo(FILE *f,int Materia, float valor1,float valor2,const char *Nome_materia);
float Media_Aritmetica_Classe_Disciplina(FILE *f,int Numero_materia);
void Alterar(FILE *f, int posicao, int opcao);
short int Buscar_Nome(FILE *f, char *Nome);
short int Buscar_RA(FILE *f, int RA, int ini, int fim);
void Gravacao(FILE *f);
void Elimina (char *str);
void Altera_Nota_Prova(FILE *f,int Posicao,int Materia);
void Altera_Nota_Prova2(FILE *f,int Posicao, int Materia,int Prova);
void Altera_Nota_Trabalho(FILE *f,int Posicao,int Materia);
void Altera_Nota_Trabalho2(FILE *f,int Posicao, int Materia,int Trabalho);
short int Verifica_String_Numeros(const char *str);
short int Verifica_String_Letras(const char *str);




#endif
