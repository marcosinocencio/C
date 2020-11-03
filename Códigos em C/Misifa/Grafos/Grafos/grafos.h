/*
	* Grafos.h
	* Autor: Luiz Paulo Rabachini
	* Last Update: 25/11/10
*/

#define MAXNODES 20 // Define o n�mero m�ximo de n�s que podem ser armazenados
#define MAXVIZ 10 // Define o n�mero m�ximo de vizinhos de um n�
#define MAXSTR 21 // Define o tamanho m�ximo da string dos nomes

typedef struct RegAdjNode AdjNode; // Estrutura que conecta os n�s em uma mesma posi��o da lista

struct RegAdjNode{
	int nodev; // Define o n� vizinho
	int dist; // Define a dist�ncia ao n� vizinho
	short sentido; // Define o sentido da aresta ao n� vizinho (0:Entrada 1: Sa�da)
	AdjNode *prox;
};

// Estrutura do elemento do grafo -------------------------------------------------------------------
typedef struct{
	int v; // N�mero de v�rtices do n�
	int a; // N�mero de arcos do n�
	char nome[MAXSTR]; // Nome armazenado
	AdjNode *adj; // N� adjacente na lista
} Digraph;

// Estrutura de grafo -------------------------------------------------------------------------------
typedef struct{
	int qntg; // Quantidade de n�s armazenados no grafo
	Digraph grafo[MAXNODES]; // N�s armazenados no grafo
} Grafo;

// Declara��o das fun��es ===========================================================================
// Deleta grafo -------------------------------------------------------------------------------------
// Insere elemento ----------------------------------------------------------------------------------
// Remove elemento ----------------------------------------------------------------------------------
// Busca em profundidade ----------------------------------------------------------------------------
// Busca em largura ---------------------------------------------------------------------------------
// Verifica gr�fico ac�clico ------------------------------------------------------------------------
// Caminho mais curto -------------------------------------------------------------------------------