/*
	* Grafos.h
	* Autor: Luiz Paulo Rabachini
	* Last Update: 25/11/10
*/
// ==================================================================================================

#define MAXNODES 20 // Define o número máximo de nós que podem ser armazenados
#define MAXVIZ 10 // Define o número máximo de vizinhos de um nó
#define MAXSTR 21 // Define o tamanho máximo da string dos nomes

typedef struct RegVertice Vertice; // Estrutura que conecta os nós em uma mesma posição da lista

struct RegVertice{
        int nodev; // Define o nó vizinho
	      int dist; // Define a distância ao nó vizinho
	      short sentido; // Define o sentido da aresta ao nó vizinho (0:Entrada 1: Saída)
        Vertice *prox;
};

// Estrutura do elemento do grafo -------------------------------------------------------------------
typedef struct{
        int v; // Número de vértices do nó
	      int a; // Número de arcos do nó
	      char nome[MAXSTR]; // Nome armazenado
	      Vertice *ver; // Nó adjacente na lista
	      short vis;
} Digraph;

// Estrutura de grafo -------------------------------------------------------------------------------
typedef struct{
	      int qntn; // Quantidade de nós armazenados no grafo
	      Digraph grafo[MAXNODES]; // Nós armazenados no grafo
} Grafo;

typedef struct{
        int nodev;
        int dist;
        short sentido;        
} NodeDist;

// Declaração das funções ===========================================================================

// Deleta grafo -------------------------------------------------------------------------------------

// Insere elemento ----------------------------------------------------------------------------------
short InsertNodeG(Grafo *G, Digraph D, NodeDist *Nd);
// Remove elemento ----------------------------------------------------------------------------------

// Busca em profundidade ----------------------------------------------------------------------------

// Busca em largura ---------------------------------------------------------------------------------

// Verifica gráfico acíclico ------------------------------------------------------------------------

// Caminho mais curto -------------------------------------------------------------------------------
