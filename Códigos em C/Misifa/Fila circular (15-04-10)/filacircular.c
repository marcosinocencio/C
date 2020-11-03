#include <stdio.h> 
#include <stdlib.h>
#include "filacircular.h"

//#define MAX 10

// Cria o menu de opcoes
void Menu(FilaC *Fc)
{
 int op=0, info=0;
     
 system("cls");
 printf("Prim: %d - Ult: %d\n",Fc->prim,Fc->ult);
 printf("Estado da fila:\n");
 Print(Fc);
 printf("\n");
 printf(":: Fila circular ::\n\n");
 printf("[0] Sair\n");
 printf("[1] Inserir na fila\n");
 printf("[2] Remover da fila\n");
 printf("[3] Imprimir a fila\n");
 printf("Opcao: "); scanf("%d",&op);
 switch (op){
        case 0: return;
        break;
        case 1: printf("Insira o elemento: "); scanf("%d",&info);
                if(Insert(Fc,info)) printf("OK\n");
                else printf("Erro\n");
        break;
        case 2: if(Remove(Fc)) printf("OK\n");
                else printf("Erro\n");
        break;
        case 3: Print(Fc);
        break;
 }
 return;
}
//------------------------------------------------------------------------------
   
// Inicializa a fila
void Start(FilaC *Fc)
{
 int i=0;
     
 Fc->prim=-1;
 Fc->ult=-1;
 for (i=0; i<MAX; i++)
     Fc->fila[i]=0;
 return;
}
//------------------------------------------------------------------------------

// Verifica lista cheia ou vazia
int Check(FilaC *Fc)
{
 int i=0, cont=0;
    
 if (Fc->ult==-1) return 0;
 for (i=Fc->prim, cont=1; i!=Fc->ult; i++, cont++)
     if (i+1==MAX) i=-1;
 if (cont==MAX) return 1;
 else return 2;
}
//------------------------------------------------------------------------------

// Insere na fila
short Insert(FilaC *Fc, int Info)
{
 int aux=0;
 
 aux=Check(Fc);      
 if (aux==1) return 0;
 if (aux==0){
      Fc->fila[0]=Info;
      Fc->prim=Fc->ult=0;
      return 1;
 }
 if ((Fc->ult+1)==MAX){
    Fc->fila[0]=Info;
    Fc->ult=0;
    return 1;   
 }
 Fc->fila[Fc->ult+1]=Info;
 Fc->ult+=1;
 return 1;
}
//------------------------------------------------------------------------------

// Retira da fila
short Remove(FilaC *Fc)
{
 int aux=0;
 
 aux=Check(Fc); 
 if (aux==0) return 0;
 if (Fc->prim==Fc->ult){
    Start(Fc);
    return 1;
 }
 if ((Fc->prim+1)==MAX){
    Fc->fila[Fc->prim]=0;
    Fc->prim=0;
    return 1;   
 }
 Fc->fila[Fc->prim]=0;
 Fc->prim+=1;
 return 1;
}
//------------------------------------------------------------------------------

// Imprime a fila
void Print(FilaC *Fc)
{
 int i=0;
 
 printf("---------------------------------------------------\n");
 for (i=0; i<MAX; i++)
     printf("| %d |",Fc->fila[i]);
 printf("\n---------------------------------------------------\n");
 return;
}
//------------------------------------------------------------------------------
