#include <stdio.h>
#include <stdlib.h>
#include "Hash_functions.h"
#include <string.h>

FILE *Open_file(const char *nome_arquivo){
    FILE *arquivo;
    int zero=0, menos_um = -1, gate=0;

	arquivo = fopen(nome_arquivo,"w+b");

	if(arquivo == NULL){//caso haja problemas em abrir o arquivo

		printf("fclose\n");
		fclose(arquivo);
		return NULL;

		}

    rewind(arquivo);
	while(gate < (TABLESIZE + 100)*8){//preenche o arquivo com -1 para poder trabalhar com ele depois

		fwrite(&zero, sizeof(int), 1, arquivo);
		fwrite(&menos_um, sizeof(int), 1, arquivo);
		gate++;

		}

	//printf("foi arquivo\n");
	return arquivo;

	}

int Nome_arquivo(char *nome_arq){
	int i=0, posicao;

	printf("Entre com o nome do arquivo: ");
	fgets(nome_arq, 15, stdin);

	posicao = strlen(nome_arq) - 1;

	if (nome_arq[posicao] == '\n')
		nome_arq[posicao] = '\0';

	for(i=posicao; i<15; i++)
		nome_arq[i] = '\0';

	return 1;

	}

void Hash_funcao(FILE *hash, int *dispo, int opcao){
	int gate = 0, dispo_copy;
	long int pos;//posição onde será colocda a entrada no arquivo
	Hash meu_hash;

	//printf("yo\n");

	if(hash == NULL)
		return ;

	printf("Entre com o elemento a ser inscrito no arquivo: ");
	scanf("%d", &meu_hash.elem);
	//printf("\npeguei\n");
	if(opcao == 1)//opcao de utilizar o hash de dobra
        pos = Funcao_dobra(meu_hash.elem);
    else if(opcao == 2)//lugar caso o usuario escolha hash por divisao
        pos = Funcao_divisao(meu_hash.elem);
    else{//caso o usuario entre com um numero diferente do numero devido

        printf("\nPor favor entre com uma escolha valida.\n");
        return ;

        }
	//rewind(hash);//debug
	//fread(&gate, sizeof(meu_hash.elem), 1, hash);
	//printf("%d\n", gate);
	//system("pause");
    //printf("antes rewind\n");
    rewind(hash);
    //printf("depis rewind\n");
	fseek(hash, pos*(2*sizeof(int)), 0);
	fread(&gate, sizeof(meu_hash.elem), 1, hash);

    //printf("verifica\n");

	if(gate != 0){//verifica se a posicao nao esta ocupada

	    //printf("oi\n");
	    fread(&meu_hash.file_adress, sizeof(meu_hash.file_adress), 1, hash);
        //printf("%ld\n", meu_hash.file_adress);

        while(meu_hash.file_adress != -1){//caça uma posicao livre para insercao do elemento

            //printf("aqui\n");
            //fread(&gate_2, sizeof(meu_hash.elem), 1, hash);
            rewind(hash);
            fseek(hash, meu_hash.file_adress*(2*sizeof(int)), 0);
            fread(&gate, sizeof(meu_hash.elem), 1, hash);
            fread(&meu_hash.file_adress, sizeof(int), 1, hash);

            }

        dispo_copy = *dispo;
        //printf("Posicao: %ld\n", ftell(hash));
        fseek(hash, ftell(hash)-4, 0);//volta posicao para impressao
        //printf("Posicao: %ld\n", ftell(hash));
        fwrite(&dispo_copy, sizeof(int), 1, hash);

        if(feof(hash)){

            printf("O final do arquivo foi foi atingido.\n");
            exit (1);

            }

        //printf("%d", *dispo);
        pos = *dispo;//posicao onde o valor sera inserido
        *dispo = *dispo + 1;//aponta para a proxima area livre

        }



    rewind(hash);
	fseek(hash, pos*(2*sizeof(int)), 0);/* Anda de bloco em bloco de modo que aloca um espaço de 4
										   bytes para a entrada do numero e 4 bytes para apontar caso
										   necessário para o próximo endereço fisico no arquivo onde estará
										   o próximo numero(na região do overflow) que caiu nessa mesma posição*/



	fwrite(&meu_hash.elem, sizeof(meu_hash.elem), 1, hash);

	//rewind(hash);
	//fseek(hash, pos*(2*sizeof(int)), 0);
	//fread(&gate, sizeof(meu_hash.elem), 1, hash);
	//printf("%d\n", gate);
	//system("pause");
	//printf("\nhihi\n");



	return ;

	}

int Funcao_dobra(int key){
		int aux[8], copy_key, q, key_2 = key;
		int i=0, p, acc=0;
		long int  numero_pos = 0;

		for(i=0; i<8; i++)//zera array que recebera os numeros para a dobra
			aux[i] = 0;

		copy_key = key_2;

		if(copy_key < 0)//se o numero for negativo a conta será feita como se ele fosse positivo
			copy_key *= (-1);

		do{//inicio do laço de geração de posição para o hashing
            numero_pos = 0;
			q=0;
			while(copy_key){//verifica quantos algarismos tem o numero

				copy_key /= 10;
				q++;

				}

			copy_key = key_2;
			if(q%2 != 0){//se quantidade de algarismo for impar sera incluido um 0 a esquerda para facilitar a dobra
				aux[0]=0;
				q++;
				for(i=q-1; i>=1; i--){

					p = copy_key%10;
					aux[i] = p;
					copy_key /= 10;

					}

				}
			else{//se o numero de algarismos for par entao os algarismos serao apenas colocados no array

				for(i=q-1; i>=0; i--){

					p = copy_key%10;
					aux[i] = p;
					copy_key /= 10;

					}

				}

			copy_key = key_2;
			acc = q;//para nao perder o valor de q que sera usado mais a frente
			p = q/2;//metade de q
			q--;//para faciliatar na hora da soma de extremos
			for(i=0; i<p; i++){

				aux[i] = aux[i] + aux[q];

				if(aux[i]>10)
					aux[i] = aux[i]%10;

				numero_pos = (numero_pos*10) + aux[i];//cria a posicao para hash
				q--;

				}

			for(i=p; i<acc; i++){//zera metade do array que nao sera mais usada

				aux[i] = 0;

				}

			key_2 = numero_pos;
			copy_key = key_2;

            //printf("Posicao: %d\n", numero_pos);

			}while(numero_pos > TABLESIZE);//se o a posicao for maior que as posicoes disponiveis o ciclo se repetira

			return numero_pos;//retorna a posicao
	}

int Funcao_divisao(int key){
    int sobra;

    sobra = key%TABLESIZE;

    return sobra;
}

