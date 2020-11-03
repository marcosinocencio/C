#ifndef _FUNCOES
#define _FUNCOES
#define MAX 101
#include <stdio.h>
#include <stdlib.h>

float p1[MAX],p2[MAX],p3[MAX], pr[MAX];

void Construir (float pol[]);
int Numero_Termos (float pol[]);
int Grau (float pol[]);
void Somar (float pol1[], float pol2[], float polr[]);
void Subtrair (float pol1[], float pol2[], float polr[]);
void Multiplicar (float pol1[], float pol2[], float polr[]);
float Calcula_x (float pol[], float val);
void Multiplica_Constante(float pol[], float k);
void Derivar (float pol[]);
void Integrar (float pol[]);
int Dividir (float pol1[], float pol2[], float polr[]);
void Imprimir (float pol[]);


#endif
