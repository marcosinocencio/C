#include <stdio.h>
#include <stdlib.h>
#include "candidate.h"

#define MAX 200
#define MSG_OK "\nOperacao realizada com sucesso\n"
#define MSG_ERROR "\nErro durante a operacao\n"
#define MSG_CAN_NOT_FOUND "\nCandidato nao encontrado\n"

short Print(candidate *Can);
int Menu();
void Exec(int OP, candidate *Can, int DIM);

//------------------------------------------------------------------------------
// Imprime o conteúdo de determinado candidato.
short Print(candidate *Can){
      
      if ((*Can).RG){
         printf("\nRG: %d",(*Can).RG);
         printf("\nNome: ");
         puts((*Can).Name);
         printf("Telefone: ");
         puts((*Can).Telephone);
         printf("Endereço: ");
         puts((*Can).Address);
         return(1);
      }
      else return(0);
}
//------------------------------------------------------------------------------
// Imprime o menu de confirguração
int Menu(){
     int i=0;
     short aux=0;
     
     do{
        system("cls");
        printf(":: Escolha a operacao desejada ::\n\n");
        printf("[1] Pesquisa de candidato\n");
        printf("[2] Insercao de candidato\n");
        printf("[3] Remocao de candidato\n");
        printf("[4] Alteracao de candidato\n");
        printf("[5] Sair\n\n");
        scanf("%d",&i);
        if ((i<1)||(i>5)){
           aux=1;
           printf("Opcao nao encontrada\n\n");
           system("pause");
        }
        else aux=0;
     }while(aux);
     return(i);
}
//------------------------------------------------------------------------------
// Executa as operações
void Exec(int OP, candidate *Can, int DIM){
      int rg=0, index=0;
      short aux=0;
      candidate can1;
      
      ClearCandidate(&can1);
      switch (OP){
             case 0: return;
             case 1: printf("\n:: [1] Pesquisa de candidato ::\n\n");
                     printf("RG(somente numeros): ");
                     scanf("%d",&rg);
                     index=Search(Can,rg,DIM);
                     if(index!=-1) Print(Can+index);
                     else printf(MSG_CAN_NOT_FOUND); 
             break;
             case 2: printf("\n:: [2] Insercao de candidato ::\n");
                     printf("\nRG(somente numeros): ");
                     scanf("%d",&(can1.RG));
                     printf("Nome: ");
                     fflush(stdin);
                     gets(can1.Name);
                     //puts(can1.Name);
                     printf("Telefone: ");
                     fflush(stdin);
                     gets(can1.Telephone);
                     printf("Endereço: ");
                     fflush(stdin);
                     gets(can1.Address);
                     if(Insert(Can,&can1,DIM)) printf(MSG_OK);
                     else printf(MSG_ERROR); 
             break;
             case 3: printf("\n:: [3] Remocao de candidato ::\n\n");
                     printf("RG(somente numeros): ");
                     scanf("%d",&rg);
                     index=Search(Can,rg,DIM);
                     if (index>=0){
                        Print(Can+index);
                        printf("\nConfirmar exclusao? ");
                        scanf("%hd",&aux);
                        if(aux) Remove(Can,rg,DIM);
                     }
                     else printf(MSG_CAN_NOT_FOUND);
             break;
             case 4: printf("\n:: [4] Alteracao de candidato ::\n");
                     printf("\nRG(somente numeros): ");
                     scanf("%d",&rg);
                     index=Search(Can,rg,DIM);
                     if (index==-1) printf(MSG_CAN_NOT_FOUND);  
                     else{
                          Print(Can+index);
                          printf("\nObs.: Preencha todos os campos.\n\n");
                          printf("RG(somente numeros): ");
                          scanf("%d",&(can1.RG));
                          printf("Nome: ");
                          fflush(stdin);
                          gets(can1.Name);
                          printf("Telefone: ");
                          fflush(stdin);
                          gets(can1.Telephone);
                          printf("Endereço: ");
                          fflush(stdin);
                          gets(can1.Address);
                          printf("Salvar? ");
                          scanf("%hd",&aux);
                          if (aux){
                             (*(Can+index)).RG=0;
                             if(Insert(Can+index,&can1,DIM)) printf(MSG_OK);
                             else printf(MSG_ERROR);
                          }
                     }
             break;
      }
      return;
}
//------------------------------------------------------------------------------
// Função Main
int main(void){
    candidate C[200];
    short aux=0;
    
    ClearArrayCand(C,MAX);   
    do{
       Exec(Menu(),C,MAX);
       printf("\nSair? (0:Sair  1:Reiniciar) ");
       scanf("%hd",&aux);
    }while(aux);
    return(0);
}
