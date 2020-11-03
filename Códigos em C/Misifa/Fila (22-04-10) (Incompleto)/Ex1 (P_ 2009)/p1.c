#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p1.h"

// Cria arquivo
void NewFile()
{
 int i;
 RegArq novo;
 FILE *fptr;
 
 fptr=fopen("teste.reg","wb");
 strcpy(novo.nome,"Joao");
 for (i=1;i<=10;i++){
     novo.prd=i;
     novo.prox=i;
     fwrite(&novo,sizeof(RegArq),1,fptr);
     strcpy(novo.nome,"Jose");
 }
 fclose(fptr);
 return;
}
//------------------------------------------------------------------------------

// Inicia a Fila
void Start(Fila *F)
{
 F->prim=NULL;
 F->ult=NULL;
 return;
}
//------------------------------------------------------------------------------
// Leitura do novo elemento
short ReadNew(Fila *F) //short ReadNew(char *Arq, Fila *F)
{
 No *novo;
 RegArq reg;
 FILE *fptr;
 
 novo=(No*)malloc(sizeof(No));
 if (!(fptr=fopen("teste.reg","rb"))) return 0;
 while (fread(&reg,sizeof(RegArq),1,fptr)){
    strcpy(novo->nome,reg.nome);
    novo->prd=reg.prd;
    //printf("%s - %d\n",novo->nome,novo->prd);
    if (!IncludeReg(novo,F)) return 0;
    fseek(fptr,(reg.prox)*(sizeof(RegArq)),0);
 }   
 free(novo);
 fclose(fptr);
 return 1;
}
//------------------------------------------------------------------------------

// Inclusão de novo elemento
short IncludeReg(No *Novo, Fila *F)
{
 short set=1;
 int i=1;
 No *novo, *aux1, *aux2;
 
 novo=(No*)malloc(sizeof(No));
 Copy(Novo,&novo);
 printf("\n:: Novo :: nome: %s prd: %d\n",novo->nome,novo->prd); system("pause");
 if (!F->prim){
    Insert(novo,F);
    Print(F); system("pause");
    return 1;
 }
 //printf("Novo:%d  Ult:%d",novo->prd,F->ult->prd); system("pause");
 if ((novo->prd)<=(F->ult->prd)){
    Insert(novo,F);
    Print(F); system("pause");
    return 1;
 }
 aux1=(No*)malloc(sizeof(No));
 if (!aux1) return 0;
 aux2=(No*)malloc(sizeof(No));
 aux2=F->prim;
 i=0;
 for (set=1;;i++){
     Remove(&aux1,F);
     Print(F); system("pause");
     if (((novo->prd)>=(aux1->prd))&&(set)){
        Insert(novo,F);
        Insert(aux1,F);
        Print(F); system("pause");
        set=0;
     }
     else Insert(aux1,F);
     //if ((int)&aux1==(int)&aux2) break;
     Print(F); system("pause");      
 }
 Print(F); system("pause");
 return 1;
}
//------------------------------------------------------------------------------

// Função para inserção na fila
short Insert(No *Novo, Fila *F)
{
 if (!F->prim){
    Novo->prox=NULL;
    Novo->ant=NULL;
    F->prim=Novo;
    F->ult=Novo;
    return 1;
 }
 F->ult->prox=Novo;
 Novo->ant=F->ult;
 Novo->prox=NULL;
 F->ult=Novo;
 return 1;
}
//------------------------------------------------------------------------------

// Função para remoção da fila
short Remove(No **Exc, Fila *F)
{
 No *ex, ;
 
 if (!F->prim) return 0;
 ex=(No*)malloc(sizeof(No));
 Copy(F->prim,&ex);
 *Exc=ex;
 F->prim=F->prim->prox;
 if (F->prim) F->prim->ant=NULL;
 else Start(F);
 free(ex);
 return 1;
}
//------------------------------------------------------------------------------

// Copia uma estrutura para outra
void Copy(No *Est1, No **Est2)
{
 strcpy((*Est2)->nome, Est1->nome);
 (*Est2)->prd=Est1->prd;
 return;
}
//------------------------------------------------------------------------------

// Imprime a fila
void Print(Fila *F)
{
 No *aux;
 
 aux=(No*)malloc(sizeof(No));
 for (aux=F->prim;aux;aux=aux->prox)
     printf("| %s |\n",aux->nome);
 free(aux);
 return;
}
//------------------------------------------------------------------------------
// printf("prd: %d - nome: %s",novo->prd,novo->nome);
// printf("prd: %d - nome: %s - prox: %d",reg.prd,reg.nome,reg.prox);
