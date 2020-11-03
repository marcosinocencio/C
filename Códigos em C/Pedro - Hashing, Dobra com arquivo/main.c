/*
 * @author Pedro Daniel de Cerqueira Gava
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "Hash_functions.h"
#include <string.h>

int main(int argc, char **argv){
	FILE *hash_arq;
	char nome[15];
	int i, dispo = TABLESIZE + 1, opcao, j;

	Nome_arquivo(nome);//nomeia o arquivo
	hash_arq = Open_file(nome);//abre o arquivo em modo binário de escrita e leitura
	//printf("antes do hash\n");
	//system("pause");
    j=0;

    do{

        i=0;

        system("cls");
        printf("Entre com a opcao desejada.\n\n");
        printf("\n\t\t1. Hashing por dobra.");
        printf("\n\t\t2. Hashing por divisao.\n");
        puts("\n\t\t");
        scanf("%d", &opcao);

        while(i<5){
            //printf("while\n");
            Hash_funcao(hash_arq, &dispo, opcao);
            if(hash_arq == NULL)
                break;
            i++;
            fflush(stdin);
            }

        j++;

        }while(j < 2);

        if(hash_arq != NULL)//para garantir que o arquivo nao seje fechado duas vezes
            fclose(hash_arq);

	system("pause");
	return 0;

}
