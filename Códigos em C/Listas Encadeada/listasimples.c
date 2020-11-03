#include "tad.h"

void IniciaLista(TLista *PtrLista){
int i;

PtrLista->Dispo =  0; //Diz que o próximo  a ser inserido é o 0 visto que a lista está vazia
PtrLista->Ini   = -1; //Como não foi inserido nada ainda o Ini recebe uma posição não existente como -1

     //O laço seta corretamente todos os ligs antes das operações na lista
     for(i=0;i<99;i++){
     PtrLista->Lista[i].Valor = 0;
     PtrLista->Lista[i].Lig   = i+1;
     }
     
     PtrLista->Lista[i].Valor=-1;
     
}

int InsereLista(TLista *PtrLista, int Elemento){//Retorna 1 para Erro e 0 para Sucesso
                       
     if(PtrLista->Ini == -1)PtrLista->Ini = 0;//Ini setado como -1 significa que o Ini ainda não está setado e será setado agora
     
     if(PtrLista->Dispo == -1) return 1; //Dispo setado como -1 significa que a lista esta cheia
     else{
     PtrLista->Lista[PtrLista->Dispo].Valor = Elemento; //Insere o elemento na lista
     PtrLista->Fim = PtrLista->Dispo; 
     PtrLista->Dispo = PtrLista->Lista[PtrLista->Dispo].Lig; //Coloca o próximo a ser inserido no Lig
       
     }
     return 0;
     
}

int DeletaLista(TLista *PtrLista, int Elemento){
int Posi,Anterior;

    Posi = AchaLista(PtrLista,Elemento,&Anterior);
    if (PtrLista->Ini == -1) printf("\nLista Vazia");
    else if (Posi == -2) printf("\nElemento nao existe") ;
    else{
         
         if(Posi == PtrLista->Ini){ //Entra aqui somente se for deletar o ini, ou seja PtrLista->Ini é equivalente a Posi
         PtrLista->Ini = PtrLista->Lista[Posi].Lig;
         PtrLista->Lista[Posi].Lig = PtrLista->Dispo;
         PtrLista->Dispo = Posi;
         }else{
         PtrLista->Lista[Anterior].Lig = PtrLista->Lista[Posi].Lig;
         PtrLista->Lista[Posi].Lig = PtrLista->Dispo;
         PtrLista->Dispo = Posi;
         }
         
    }
    
}

int AchaLista(TLista *PtrLista, int Elemento,int *Anterior){//Retorna -1 para Erro, -2 Para não achou e a posição se achou
int i=-1;
    
    if(PtrLista->Ini == -1) return -1; //Dispo setado como -1 significa que a lista esta vazia
   
   do{
   *Anterior = i;
   i++;
   if (PtrLista->Lista[i].Valor == Elemento) return i;
   }while(i != PtrLista->Fim);
   
   return -2;  
    
}

int ImprimeLista(TLista *PtrLista){
int i;
    
    if(PtrLista->Ini == -1) return -1; //Ini setado como -1 significa que a lista esta vazia
   
   printf("INI=%d     FIM=%d     DISPO=%d",PtrLista->Ini,PtrLista->Fim,PtrLista->Dispo);
   printf("\n\nPOSI     VALOR     LIG\n");
   
   i = PtrLista->Ini;
   
   do{
   printf("  %d      %d      %d\n",i,PtrLista->Lista[i].Valor,PtrLista->Lista[i].Lig);
   i = PtrLista->Lista[i].Lig;
   }while(i != PtrLista->Lista[PtrLista->Fim].Lig);
   
}

int ImprimeListaCompleta(TLista *PtrLista){
int i=-1,ibk;
    
    if(PtrLista->Ini == -1) return -1; //Ini setado como -1 significa que a lista esta vazia
   
   printf("INI=%d     FIM=%d     DISPO=%d",PtrLista->Ini,PtrLista->Fim,PtrLista->Dispo);
   printf("\n\nPOSI     VALOR     LIG\n");
   
   i = PtrLista->Ini;
   
  do{
   printf("  %d  ->",i);
   //system("pause");
   ibk =i;
   i = PtrLista->Lista[i].Lig;
   }while(i != PtrLista->Lista[PtrLista->Fim].Lig);
   
}

/*

if(PtrLista->Ini == -1) return -1; //Ini setado como -1 significa que a lista esta vazia
   
   printf("INI=%d     FIM=%d     DISPO=%d",PtrLista->Ini,PtrLista->Fim,PtrLista->Dispo);
   printf("\n\nPOSI     VALOR     LIG\n");
   
   do{
   i++;
   printf("  %d      %d      %d\n",i,PtrLista->Lista[i].Valor,PtrLista->Lista[i].Lig);
   }while(i != 4);
   
   */

