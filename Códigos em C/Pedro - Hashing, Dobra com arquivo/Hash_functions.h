#ifndef HASH_FUNCTIONS_H_INCLUDED
#define HASH_FUNCTIONS_H_INCLUDED



#endif //HASH_FUNCTIONS_H

#define TABLESIZE 383
#define OVERFLOW 100

typedef struct {

	int elem;
	long int file_adress;

	}Hash ;

extern void Hash_funcao(FILE *hash, int *dispo, int opcao);
extern FILE *Open_file(const char *nome_arquivo);
extern int Nome_arquivo(char *nome_arq);
extern int Funcao_dobra(int key);
extern int Funcao_divisao(int key);
