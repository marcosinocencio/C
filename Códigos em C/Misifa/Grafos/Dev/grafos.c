#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grafos.h"

// Inicia grafo ----------------------------------------------------------------
void ClearDigraph(Grafo *G)
{
     G->qntn = 0;
     return;    
}

// Captura os dados para inserção ----------------------------------------------
short CreatNode(Grafo *G)
{
     int node = 1, dist = 0, v = 0, a = 0;
     short sentido = 0;
     NodeDist nd[MAXVIZ];
     Digraph NewNode;
     char name[MAXSTR];
     
     system("cls");
     if (G->qntn + 1 >= MAXNODES){
        printf("O grafo esta cheio!!! \n\n");
        return 0;
     }
     printf("=> Menu de insercao <=\n\n");
     printf(":(!): Numero do novo no: %d\n\n", G->qntn + 1);
     printf("-> Insira o nome a ser armazenado: ");
     fflush(stdin);
     gets(name);
     printf("-> Insira as adjacencias do novo no (Ex.: 1 + Enter torna o novo no adjacente ao no 1\n)");
     printf(":(!): Para sair utilize 0 + Enter ::\n\n");
     for (v = 0, a = 0; ;){
           printf("Adjacente ao no: ");
           scanf("%d",&node);
           if (node < 1) break;
           if (node > G->qntn) printf ("O no %d nao existe\n", node);
           else{
                if (node == G->qntn + 1)
                   a++;
                printf("Distancia ao no %d: ", node);
                scanf("%d",&dist);
                printf("Sentido em relacao ao no %d (0: Entrada. 1: Saida): ", node);
                scanf("%d",&sentido);
                nd[v].nodev = node;
                nd[v].dist = dist;
                nd[v].sentido = sentido;
                v++;
           }         
     }
     NewNode.a = a;
     NewNode.v = v;
     NewNode.vis = 0;
     NewNode.ver = NULL;
     strcpy(NewNode.nome, name);
     if (InsertNodeG(&(*G), NewNode, nd)){
        printf("Caracteristicas do novo no:\n");
        printf("Nome %s\nNumero de vertices: %dNumero de Arcos: %d\n", name, v, a);
        for (;v >= 0; v--)
            printf("Adjacente a %d com distancia %d e sentido %d", nd[v].nodev, nd[v].dist, nd[v].sentido);
     }
     return 1;
}

// Insere elemento -------------------------------------------------------------
short InsertNodeG(Grafo *G, Digraph D, NodeDist *Nd)
{
      int a = 0, b = 0;
      Vertice **v = NULL;
      
      a = G->qntn;
      if (a == 0){
         G->grafo[0] = D;
         G->qntn++;
      }
      else{
         G->grafo[a++] = D;
         G->qntn++;     
      }
      (*v) = G->grafo[a].ver;
      for (b = 0; b < G->grafo[a].v; b++){
          (*v) = (Vertice*)malloc(sizeof(Vertice));
          (*v)->prox = NULL;
          (*v)->nodev = (Nd + b)->nodev;
          (*v)->dist = (Nd + b)->dist;
          (*v)->sentido = (Nd + b)->sentido;
          (*v) = &((*v)->prox);
      }
      return 1;
}

// Remove elemento -------------------------------------------------------------
// Busca em profundidade -------------------------------------------------------
// Busca em largura ------------------------------------------------------------
// Verifica gráfico acíclico ---------------------------------------------------
// Caminho mais curto ----------------------------------------------------------
