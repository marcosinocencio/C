#include <stdio.h>
#include <stdlib.h>
#include "pilhasmult.h"

// Cria o menu de opcoes
void Menu(PilhaM *Pm)
{
 int op=0, info=0, base;
     
 system("cls");
 printf("Bases: ");
 PrintIndex(Pm);
 printf("Estado das pilhas:\n");
 Print(Pm);
 printf("\n");
 printf(":: Pilhas multiplas ::\n\n");
 printf("[0] Sair\n");
 printf("[1] Inserir na pilha\n");
 printf("[2] Remover da pilha\n");
 printf("[3] Imprimir as pilhas\n");
 printf("Opcao: "); scanf("%d",&op);
 switch (op){
        case 0: return;
        break;
        case 1: printf("Insira o elemento: "); scanf("%d",&info);
                SetPilha(Pm,&base);
                if(Insert(Pm,info,base)) printf("OK\n");
                else printf("Erro\n");
        break;
        case 2: SetPilha(Pm,&base);
                if(Remove(Pm,base)) printf("OK\n");
                else printf("Erro\n");
        break;
        case 3: Print(Pm);
        break;
 }
 return;
}
//------------------------------------------------------------------------------

// Inicializa a pilha
void Start(PilhaM *Pm)
{
 int i=0, a=0;
 
 for (i=0;i<MAX;i++){
     Pm->index[i]=0;
     Pm->pilha[i]=0;
 }
 Pm->index[0]=0;
 for (i=0, a=1;i<MAX;i++)
     if (!((i)%Pm->tp)){
        Pm->index[a]=i;
        ++a;
     }
 return;
 }
//------------------------------------------------------------------------------
// Define o numero de pilhas
void SetBase(PilhaM *Pm)
{
 int i=0;
 
 system("cls");
 do{
    if (i>MAX) printf("Nao e possivel alocar espaco para %d pilhas. Configure novamente\n\n",i);
    printf(":: Configurar numero de pilhas ::\n");
    printf("\nPosicoes disponiveis: %d. De preferencia a divisores deste numero\n",MAX);
    printf("\nQuantidade de pilhas: "); scanf("%d",&i);
 }while(i>MAX);
 Pm->tp=(int)(MAX/i);
 Start(Pm);
 return;
}
//------------------------------------------------------------------------------

// Seta a pilha
short SetPilha(PilhaM *Pm, int *Base)
{
 int p;     
      
 printf("Pilha numero: "); scanf("%d",&p);
 if (p*Pm->tp>MAX) return 0;
 *Base=p*Pm->tp;
 return 1;
}
//------------------------------------------------------------------------------

// Insere na pilha
short Insert(PilhaM *Pm, int Info, int Base)
{
 int topo=0;
 
 topo=Pm->index[Base/Pm->tp];
 if (topo==Base+Pm->tp) return 0;
 Pm->pilha[Base+topo]=Info;
 Pm->index[Base/Pm->tp]+=1;
 return 1; 
}
//------------------------------------------------------------------------------

// Remove da pilha
short Remove(PilhaM *Pm, int Base)
{
 int topo=0;
 
 topo=Pm->index[Base/Pm->tp];
 if (topo<Base) return 0;
 Pm->index[Base/Pm->tp]-=1;
 return 1; 
}
//------------------------------------------------------------------------------

// Imprime as pilhas
void Print(PilhaM *Pm)
{
 int i=0, a=-1;
 
 printf("\n--------------------------------------------------------------\n");
 if(!Pm->tp) return;
 printf("\nPilha: %d\n",++a);
 for (i=0;i<MAX;i++){
     if (!((i+1)%Pm->tp))
        printf("\nPilha: %d\n",++a);
     printf("| %d |",Pm->pilha[i]);
 }
 printf("\n--------------------------------------------------------------\n");
 return;
}
//------------------------------------------------------------------------------

// Imprime 
void PrintIndex(PilhaM *Pm)
{
 int i=0;
 
 printf("\n--------------------------------------------------------------\n");
 for (i=0;i<MAX;i++)
     printf("| %d |",Pm->index[i]);
 printf("\n--------------------------------------------------------------\n");
 return;
}
//------------------------------------------------------------------------------
