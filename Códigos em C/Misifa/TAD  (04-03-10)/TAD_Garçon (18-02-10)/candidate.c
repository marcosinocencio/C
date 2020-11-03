/*
********************************************************************************
Def.: Funções para manipulação de estrutura do tipo Candidate
********************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidate.h"

// Limpa todos os campos de um candidato.
void ClearCandidate(candidate *Can){
     (*Can).RG=0;
     strcpy((*Can).Name,"\0");
     strcpy((*Can).Telephone,"\0");
     strcpy((*Can).Address,"\0");
     return;
}
// Limpa todos os campos de todos os candidatos do vetor.
void ClearArrayCand(candidate *C, int DIM){
     int i;
     
     for (i=0;i<DIM;i++)
         ClearCandidate(C+i);
     return;
}
// Pesquisa candidato no vetor. Retorna -1 em caso de falha e a posição do vetor em caso de êxito.
// LEMBRAR DE IMPLEMENTAR BUSCA BINÁRIA !!!
int Search(candidate *C, int RG, int DIM){
     int i;
     
     for (i=0;i<DIM;i++)
         if((*(C+i)).RG==RG) return(i);
     return(-1);
}
// Pesquisa posição vazia do vetor.
int SearchNull(candidate *C, int DIM){
     int i;
     
     for (i=0;i<DIM;i++)
         if((*(C+i)).RG==0) return(i);
     return(-1);
}
// Insere candidato no vetor. Retorna 0 em caso de falha e 1 em caso de êxito.
short Insert(candidate *C, candidate *Can, int DIM){
     int index=-1;
     
     if(Search(C,(*Can).RG,DIM)!=-1) return(0);
     index=SearchNull(C,DIM);
     if(index==-1) return(0);
     else{
          (*(C+index)).RG=(*Can).RG;
          strcpy((*(C+index)).Name,(*Can).Name);
          strcpy((*(C+index)).Telephone,(*Can).Telephone);
          strcpy((*(C+index)).Address,(*Can).Address);  
     }
     return(1); 
}
// Remove candidato do vetor. Retorna 0 em caso de falha e 1 em caso de êxito.
short Remove(candidate *C, int RG, int DIM){
     int index=-1;
     
     index=Search(C,RG,DIM);
     if(index==-1) return(0);
     else ClearCandidate(C+index);
     return(1);
}
// Altera candidato do vetor. Retorna 0 em caso de falha e 1 em caso de êxito.
short Alter(candidate *C, candidate *Can, int RG, int DIM){
     int index=-1;
     
     index=Search(C,RG,DIM);
     if(index==-1) return(0);
     else{
          (*(C+index)).RG=(*Can).RG;
          strcpy((*(C+index)).Name,(*Can).Name);
          strcpy((*(C+index)).Telephone,(*Can).Telephone);
          strcpy((*(C+index)).Address,(*Can).Address);          
     }
     return(1);
}
// Fim -------------------------------------------------------------------------
