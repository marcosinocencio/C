/* -----------------------------------------------------------------------------
@copyright Luiz Paulo Rabachini @file: pilha.h
Release: 1.0 - Updated: 21/04/2010
--------------------------------------------------------------------------------
Resume: TAD Pilha
------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_pos_fixada.h"
//#include "pilha.h"

// Captura da string de entrada
void CapFunc(char *Funcao)
{
 system("cls");
 printf(":: Calculadora pos fixada (Ver.: 1.0) ::\n\n");
 printf("Insira a função: ");
 fflush(stdin);
 gets(Funcao);
 return;
}
//------------------------------------------------------------------------------
//StrIn(&P,funcao,&resultado);
// Interpreta a string de entrada e acumula os valores na pilha
short StrIn(Pilha *P, char *Funcao, int *Res)
{
 int a=0, b=0;
 char num[5];
 
 num[0]="/0";
 for (a=0;((int)*(Funcao+a))!=((int)"/0");a++){
     if (((int)*(Funcao+a))==((int)" ")){
        strcat(num,"/0");
        if (!Insert(P,atoi(num))) return 0;
        num[0]="/0";
     }
     else if (Operacao(P,*(Funcao+a)));
          else strcat(num,*(Funcao+a));
        
 }
 *Res=0;
 for (a=P->topo;a>=0;a--)
     *Res+=P->Pilha[a];
 return 1; 
}
//------------------------------------------------------------------------------

// Interpreta a operação
short Operacao(Pilha *P, char C)
{
 int nchar;
 nchar=((int)C)%48;
 switch (nchar){
        case 42: if(!Operar(P,1)) return 0;
                 else return 1; 
        case 43: if(!Operar(P,2)) return 0;
                 else return 1;
        case 45: if(!Operar(P,3)) return 0;
                 else return 1;
        case 47: if(!Operar(P,4)) return 0;
                 else return 1;
        default: return 0;        
 } 
}
//------------------------------------------------------------------------------

// Realiza a operação
short Operar(Pilha *P, int Set)
{
 int info=0, res=0;      

 switch (Set){
        // Multiplicação
        case 1: res=1;
                for (;P->topo>=P->base;)
                    if (!Remove(P,&info)) return 0;
                    else res*=info;
                P->Pilha[P->base]=res;
                P->base+=1;
                return 1;
        // Adição
        case 2: res=0;
                for (;P->topo>=P->base;)
                    if (!Remove(P,&info)) return 0;
                    else res+=info;
                P->Pilha[P->base]=res;
                P->base+=1;
                return 1;
        // Subtração
        case 3: res=0;
                for (;P->topo>=P->base;)
                    if (!Remove(P,&info)) return 0;
                    else res-=info;
                P->Pilha[P->base]=res;
                P->base+=1;
                return 1;
        // Divisão
        case 4: if (!Remove(P,&info)) return 0;
                    else res=info;
                for (;P->topo>=P->base;)
                    if (!Remove(P,&info)) return 0;
                    else res/=info;
                P->Pilha[P->base]=res;
                P->base+=1;
                return 1;
        default: return 0;
 } 
}
//------------------------------------------------------------------------------
