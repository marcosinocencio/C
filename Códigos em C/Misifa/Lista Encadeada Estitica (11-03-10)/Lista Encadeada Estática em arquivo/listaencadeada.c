#include <stdio.h>
#include <stdlib.h>

#include "listaencadeada.h"

//#define MAX 20

RegIndex RI;

// Menu: Função para exibição do menu;
int Menu(FILE *fptr){
    int op=0, op2=0, indexop=-1, cont=0, valor=0;
         
     system("cls");
     printf("%d - %d\n\n",RI.prim,RI.dispo);
     op=0; op2=0; indexop=-1;
     printf("[0] Sair\n");
     printf("[1] Pesquisa\n");
     printf("[2] Insercao\n");
     printf("[3] Remocao\n");
     printf("[4] Prencher lista com zeros\n");
     printf("[5] Imprimir vetor\n\n");
     scanf("%d",&op);            
     switch (op){
            case 0: return(0);
            break;
            case 1: printf("Insira o valor: ");
                    scanf("%d",&valor);
                    printf("%d",Search(valor,fptr));
            break;
            case 2: printf("\nInserir: [1]Inicio [2]Fim [3]Apos: ");
                    scanf("%d",&op2);
                    switch (op2){
                           case 1: op2=1;
                           break;
                           case 2: op2=2;
                           break;
                           case 3: op2=3;
                                   printf("\nInserir apos o elemento: ");
                                   scanf("%d",&indexop);
                           break;
                           default: op2=2;
                 }
                 printf("Insira o valor: ");
                 scanf("%d",&valor);
                 if(Insert(valor,fptr,op2,indexop)) printf("Operacao realizada com sucesso\n\n");
                 else printf("Erro\n\n");
            break;
            case 3: printf("Insira o valor: ");
                    scanf("%d",&valor);
                    if(Remove(valor,fptr)) printf("Operacao realizada com sucesso\n\n");
                    else printf("Erro\n\n");
            break;
            case 4: printf("Insira a opcao: ");
                    int OP; scanf("%d",&OP);
                    Print(fptr,OP);
     }
     printf("\nReiniciar? ");
     scanf("%d",&cont);
     return(cont);
}


// Insert: Função de inserção na lista;
// Info: Informação a ser inserida; *L: Ponteiro p/ Lista; OP: Opção de inserção
// (início [1], fim [2] e após x [3]; Index: x de OP 3;
short Insert(int Info, FILE *fptr, int OP, int Index){
      int aux=-1, aux2=0, aux3=0;
      Reg R, RAux;
      
      fseek(fptr,0,0);
      switch (OP){
             case 1: if (RI.dispo==-1) return(0);
                     if (RI.prim==-1){
                        fseek(fptr,RI.dispo,0);
                        fread(&RAux,sizeof(Reg),1,fptr);
                        R.info=Info;
                        R.prox=RAux.prox;  
                        fseek(fptr,RI.dispo,0);
                        fwrite(&R,sizeof(Reg),1,fptr);
                        RI.prim=RI.dispo;
                        RI.dispo=RAux.prox;
                        return(1);
                     }
                     else{
                          Segmentar(fptr);
                          fseek(fptr,RI.dispo,0);
                          fread(&RAux,sizeof(Reg),1,fptr);
                          aux=RAux.prox;
                          R.info=Info;
                          R.prox=RI.prim;
                          fseek(fptr,RI.dispo,0);
                          fwrite(&R,sizeof(Reg),1,fptr);
                          RI.prim=RI.dispo;
                          RI.dispo=aux;
                          return(1);
                     }
                     break;
             case 2: if (RI.dispo==-1) return(0);
                     if (RI.prim==-1) RI.prim=0;
                     fseek(fptr,RI.dispo,0);
                     fwrite(&RAux,sizeof(Reg),1,fptr);
                     R.info=Info;
                     R.prox=RAux.prox;
                     fseek(fptr,RI.dispo,0);
                     fwrite(&R,sizeof(Reg),1,fptr);
                     RI.dispo=RAux.prox;
                     return(1);
                     break;
             case 3: if((RI.dispo==-1)||(RI.prim==-1)) return(0);
                     aux2=Search(Index,fptr);
                     if (aux2!=-1){
                        Segmentar(fptr);
                        fseek(fptr,RI.dispo,0);
                        fread(&RAux,sizeof(Reg),1,fptr);
                        aux3=RAux.prox;
                        fseek(fptr,aux2,0);
                        fread(&RAux,sizeof(Reg),1,fptr);
                        R.info=Info;
                        R.prox=RAux.prox;
                        fseek(fptr,RI.dispo,0);
                        fwrite(&R,sizeof(Reg),1,fptr);
                        RAux.prox=RI.dispo;
                        fseek(fptr,aux2,0);
                        fwrite(&RAux,sizeof(Reg),1,fptr);
                        RI.dispo=aux3;
                        return(1);
                     }
                     else return(0);
                     break;
      }
      return(0);
}
//------------------------------------------------------------------------------

// Segmentar: Arruma as coisas. Reseguimenta a Lista p/ não haver loop infinito;
// *L: Ponteiro p/ Lista;
void Segmentar(FILE *fptr){
     int index;
     Reg R, R2;
     
     index=RI.prim;
     fseek(fptr,index,0);
     while (!feof(fptr)){
           fread(&R,sizeof(Reg),1,fptr);
           if (R.prox==RI.dispo){
              fseek(fptr,RI.dispo,0);
              fread(&R2,sizeof(Reg),1,fptr);
              R.prox=R2.prox;
              fseek(fptr,index,0);
              fwrite(&R,sizeof(Reg),1,fptr);
              //i=R.prox
              break;
           }
     }
     return;
}
//------------------------------------------------------------------------------

// Remove: Remove o elemento da lista
// Info: elemento a ser retirado; *L: Ponteiro para Lista;
short Remove(int Info, FILE *fptr){
      int aux, index;
      Reg R, RAux;
      
      aux=index=RI.prim;
      fseek(fptr,index,0);
      while (!feof(fptr)){
            fread(&R,sizeof(Reg),1,fptr);
            if (R.info==Info){
              if(index==RI.prim) RI.prim=R.prox;
              fseek(fptr,aux,0);
              fread(&R,sizeof(Reg),1,fptr);
              fseek(fptr,index,0);
              fread(&RAux,sizeof(Reg),1,fptr);
              R.prox=RAux.prox;
              fseek(fptr,index,0);
              fwrite(&R,sizeof(Reg),1,fptr);
              fseek(fptr,SearchFinal(fptr),0);
              fread(&RAux,sizeof(Reg),1,fptr);
              RAux.prox=index;
              fseek(fptr,SearchFinal(fptr),0);
              fwrite(&RAux,sizeof(Reg),1,fptr);
              fseek(fptr,index,0);
              fread(&RAux,sizeof(Reg),1,fptr);
              RAux.prox=-1;
              fseek(fptr,index,0);
              fwrite(&RAux,sizeof(Reg),1,fptr);
              return(1);
           }
           aux=index;
           index=R.prox;
           if(index==-1) break;
           fseek(fptr,index,0);
     }
      return(0);
}
/*/------------------------------------------------------------------------------

// PreencherLista: Preenche as informações da Lista c/ determinado elemento;
// *L: Ponteiro para Lista; N: elemento a ser inserido em todas as informações;
void PreencherLista(FILE *fptr, int N){
     int index=-1;
     Reg R;
     
     RI.prim=RI.dispo;
     index=R.prim;
     fseek(fptr,index,0);
     while (!feof(fptr)){
           fread(&R,sizeof(Reg),1,fptr);
           R.info=N;
           fseek(fptr,index,0);
           fwrite(&R,sizeof(Reg),1,fptr);
           index=R.prox;
           fseek(fptr,index,0);
     }
     return;     
}
*///------------------------------------------------------------------------------

// Search: Busca determniado elemento na Lista. Retorna a posição, caso o elemento
// seja encontrado e -1, caso o elemento não seja encontrado;
// Info: Informação buscada; *L: Ponteiro p/ lista.
int Search(int Info, FILE *fptr){
     Reg R;
     int index=-1;
     
     index=RI.prim;
     fseek(fptr,index,0);
     while (!feof(fptr)){
           fread(&R,sizeof(Reg),1,fptr);
           if(R.info==Info) return(index);
           index=R.prox;
           if(index==-1) break;
           if(index==RI.dispo) return(-1);
           fseek(fptr,index,0);
     }
     return(-1);
}
//------------------------------------------------------------------------------

// SearchFinal: Retorna o conteúdo do último elemento da Lista;
// *L: Ponteiro p/ Lista;
int SearchFinal(FILE *fptr){
     int index=-1;
     Reg R;
     
     if(RI.prim==-1) return(-1);
     index=RI.prim;
     fseek(fptr,index,0);
     while (!feof(fptr)){
           fread(&R,sizeof(Reg),1,fptr);
           if(R.prox==-1) return(index);
           index=R.prox;
           if(index==-1) break;
           fseek(fptr,index,0);
     }
     return(index);
}
//------------------------------------------------------------------------------

// CreatLista: Cria a Lista p/ utilização;
void CreatLista(FILE *fptr){
     int i;
     Reg R;
     
     fptr=fopen(Arq,"wb");
     RI.dispo=0;
     RI.prim=-1;
     R.info=0;
     for (i=1;i<MAX;i++){
         R.prox=i;
         fwrite(&R,sizeof(Reg),1,fptr);
     }
     R.prox=-1;
     fwrite(&R,sizeof(Reg),1,fptr);
     //fwrite(&RI,sizeof(RegIndex),1,fptr);       
     fclose(fptr);
     return;    
}
//------------------------------------------------------------------------------

// Print: Imprime em ordem as informações armazenadas ou progressivamente, a
// partir de 0, os ponteiros armazenados em cada Reg;
// *L: Ponteiro p/ Lista; OP: Opção de impressão ([1] Ponteiros [2]Infromações)
void Print(FILE *fptr, int OP){
     int index=-1;
     Reg R;
     
     switch (OP){
            case 1: fseek(fptr,0,0);
                    while (!feof(fptr)){
                          fread(&R,sizeof(Reg),1,fptr);
                          printf("%d\n",R.prox);
                    }
            return;
            case 2: if(RI.prim==-1) break;
                    index=RI.prim;
                    fseek(fptr,index,0);
                    while (!feof(fptr)){
                          fread(&R,sizeof(Reg),1,fptr);
                          printf("%d\n",R.info);
                          index=R.prox;
                          if(index==-1) break;
                          fseek(fptr,index,0);
                    }
            return;
     }
}
//------------------------------------------------------------------------------
