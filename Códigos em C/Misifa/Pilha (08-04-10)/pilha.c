/* -----------------------------------------------------------------------------
@copyright Luiz Paulo Rabachini @file: lista.c
Release: 1.5 - Updated: 21/04/2010
--------------------------------------------------------------------------------
Resume: Algorítimos do arquivo pilha.h
------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

#define MSGOK "Operacao realizada com sucesso\n"
#define MSGERROR "Erro durante operacao\n"

void Menu(Pilha *P)
{
 int op=0, info=0, aux=-1;
 
 do{
    system("cls");
    printf("\n\n----------------------------------------------------------------\n\n");
    printf(":: Pilha (V1.5) ::\n\n");
    printf("[0] Sair\n");
    printf("[1] Inserir elemento na pilha\n");
    printf("[2] Remover elemento da pilha\n");
    printf("[3] Buscar posicao do elemento na pilha\n");
    printf("[4] Imprimir pilha\n");
    printf("[5] Tamanho da pilha\n");
    printf("\nOpcao: [ ]\b\b"); scanf("%d",&op);
        switch (op){
               case 0: return;
               break;
               case 1: printf("\n[1] Inserir elemento na pilha\n");
                       printf("Insira o elemento: "); scanf("%d",&info);
                       if(!Insert(P,info)) printf(MSGERROR);
                       else printf(MSGOK); 
               break;
               case 2: printf("\n[2] Remover elemento da pilha\n");
                       if(!Remove(P,&aux)) printf(MSGERROR);
                       else{
                            printf(MSGOK);
                            printf("Elemento: %d\n",aux);
                       }
               break;
               case 3: printf("\n[3] Buscar posicao do elemento na pilha\n");
                       printf("Insira o elemento: "); scanf("%d",&info);
                       if ((aux=Search(P,info))!=-1){
                          printf(MSGOK);
                          printf("Elemento: %d - Posicao: %d\n",info,aux);
                       }
                       else printf(MSGERROR);
               break;
               case 4: printf("\n[4] Imprimir pilha\n");
                       Print(P);
               break;
               case 5: printf("\n[5] Tamanho da pilha\n");
                       printf("Tamanho: %d\n",Size(P));
               break;
               default: printf("\nOpcao nao encontrada\n");       
      }
      system("pause");
     } while(1);
}
// Inicializa a pilha
void Start(Pilha *P)
{
 P->topo=-1;
 P->base=0;
 return;     
}
//------------------------------------------------------------------------------
// Função de inserção
short Insert(Pilha *P, int Info)
{
 if ((P->topo+1)<MAX){
    P->Pilha[P->topo+1]=Info;
    P->topo+=1;
    return 1;
 }
 else return 0;
}
//------------------------------------------------------------------------------

// Função de remoção
short Remove(Pilha *P, int *Info)
{
 if (P->topo!=-1){
    *Info=P->Pilha[P->topo];
    P->topo-=1;
    return 1;   
 }
 else return 0;
}
//------------------------------------------------------------------------------

// Função de verificação do tamanho
int Size(Pilha *P)
{
 return (P->topo+1);
}
//------------------------------------------------------------------------------

// Função de busca
int Search(Pilha *P, int Info)
{
 int i;
 
 for (i=P->topo;i>=0;i--){
     if (P->Pilha[i]==Info)
        return (i+1);
 return -1;
 }
}
//------------------------------------------------------------------------------

// Função de impressão
void Print(Pilha *P)
{
 int i;
 
 for (i=0;i<=P->topo;i++)
     printf("| %d  ",P->Pilha[i]);
 return;
}
//------------------------------------------------------------------------------

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

// Interpreta a string de entrada e acumula os valores na pilha
short StrIn(Pilha *P, char *Funcao, int *Res)
{
 int a=0, b=0;
 char num[5], c;
 
 for (a=0;*(Funcao+a)!="/0";a++){
     if (*(Funcao+a)==" "){
        strcat(num,"/0");
        if (!Insert(P,atoi(num))) return 0;
        num[0]="/0";
     }
     else if (Operacao(P,*(Funcao+a)));
          else{
               c=*(Funcao+a);
               strcat(num,c);
          }
     puts(num);
        
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

