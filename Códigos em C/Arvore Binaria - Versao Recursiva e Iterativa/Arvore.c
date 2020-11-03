#include "Arvore.h"

//-------------------------------------------------coloca de forma recursiva--------------------------
void coloca(PontNo *primeiro,int valorz){
     PontNo aux;
    
     if(*primeiro==NULL){
     aux=(PontNo)malloc(sizeof(struct No));
     aux->valor=valorz;
     aux->direita=NULL;
     aux->esquerda=NULL;
     *primeiro=aux;}
     else{
          if((*primeiro)->valor > valorz){coloca(&(*primeiro)->esquerda,valorz);}
          else if((*primeiro)->valor < valorz){coloca(&(*primeiro)->direita,valorz);}
          }
     return;}

//------------------------------------------------coloca de forma interativa-------------------------
void coloca_it(PontNo *primeiro, int valor){
     PontNo aux,aux2=(*primeiro),aux3;
     aux=(PontNo)malloc(sizeof(struct No));
     aux->direita=NULL;
     aux->esquerda=NULL;
     aux->valor=valor;
     if((*primeiro)==NULL){(*primeiro)=aux;}
     else{
        while(aux2!=NULL){ aux3=aux2; 
        if(aux2->valor>valor) aux2=aux2->esquerda;
        else if(aux2->valor<valor) aux2=aux2->direita;}
     if(aux3->valor<valor){aux3->direita=aux;}
     else if(aux3->valor>valor){aux3->esquerda=aux;}
     
}
     
     return;}

//-----------------------------ELIMINAR ELEMENTO!!! ITERATIVO!--------------------------------
     
void  elemina_elemento(PontNo *pontraiz,int valor){
     PontNo aux,aux2=NULL,aux3; 
     char lado;
     aux=(*pontraiz);
     if(aux->valor==valor){ 
                          if(aux->esquerda!=NULL){aux2=aux;aux=aux->esquerda;if(aux->direita==NULL){aux->direita==(*pontraiz)->direita;free((*pontraiz));(*pontraiz)=aux;}
                          while(aux->direita!=NULL){aux2=aux;aux=aux->direita;}
                          aux2->direita=aux->esquerda;
                          aux->direita=(*pontraiz)->direita;
                          aux->esquerda=(*pontraiz)->esquerda;
                          free(*pontraiz);
                          (*pontraiz)=aux; }
                          else{ aux2=aux;aux=aux->direita; if(aux->esquerda==NULL){aux->esquerda==(*pontraiz)->esquerda;free((*pontraiz));(*pontraiz)=aux;}
                               while(aux->esquerda!=NULL){aux2=aux;aux=aux->esquerda;}
                                aux2->esquerda=aux->direita;
                                aux->esquerda=(*pontraiz)->esquerda;
                                aux->direita=(*pontraiz)->direita;
                                free((*pontraiz));
                                (*pontraiz)=aux;}
                               }                          
     else{  
                                      while(1){ aux2=aux; 
                                      if(aux->valor > valor){ aux=aux->esquerda;lado='2';}
                                      else if(aux->valor < valor){ aux=aux->direita;lado='3';}
                                      if(aux->valor==valor){if(aux->esquerda==NULL && aux->direita==NULL){  
                                                                                   if(lado=='2'){aux2->esquerda=NULL;}else aux2->direita=NULL;
                                                                                   free(aux);
                                                                                   }
                                                            else if(aux->esquerda==NULL){
                                                                  if(lado=='2'){aux2->esquerda=aux->direita;}else aux2->direita=aux->direita;
                                                                  free(aux);
                                                                 
                                                                 }
                                                            else if(aux->direita==NULL){
                                                                 if(lado=='2'){aux2->esquerda=aux->esquerda;}else aux2->direita=aux->esquerda;
                                                                  free(aux);
                                                                 } 
                                                            else { 
                                                                 if(lado=='2'){
                                                                 while(aux->direita!=NULL){aux3=aux;aux=aux->direita;}
                                                                 if(aux->esquerda!=NULL){aux3->direita=aux->esquerda;}
                                                                 else{aux3->direita=NULL;}
                                                                 aux3=aux2->esquerda;
                                                                 aux2->esquerda=aux;
                                                                 aux->direita=aux3->direita;
                                                                 aux->esquerda=aux3->esquerda;
                                                                 free(aux3);}
                                                                 else{while(aux->esquerda!=NULL){aux3=aux;aux=aux->esquerda;}
                                                                      if(aux->direita!=NULL){aux3->esquerda=aux->direita;}
                                                                       else{aux3->esquerda=NULL;}
                                                                       aux3=aux2->direita;
                                                                       aux2->direita=aux;
                                                                       aux->esquerda=aux3->esquerda;
                                                                       aux->direita=aux3->direita;
                                                                       free(aux3);
                                                                       }
                                                                 }                          
                                                            break;}
                                    }
                                    
                                    }                      
     
     
     return;}
     
//-----------------------------IMPRESAO! PRE--------------------------------
     
void Imprimir_pre(PontNo raiz){
     if(raiz!=NULL){
     printf(" %d ",raiz->valor);
     Imprimir_pre(raiz->esquerda);
     Imprimir_pre(raiz->direita);
     }
     
     return;}
     
//-----------------------------IMPRESAO! EM--------------------------------
     
void Imprimir_em(PontNo raiz){
      if(raiz!=NULL){
     Imprimir_pre(raiz->esquerda);
     printf(" %d ",raiz->valor);
     Imprimir_pre(raiz->direita);
     }
     
     return;}
//-----------------------------IMPRESAO! POS--------------------------------
void Imprimir_pos(PontNo raiz){
      if(raiz!=NULL){
     Imprimir_pre(raiz->esquerda);
     printf(" %d ",raiz->valor);
     Imprimir_pre(raiz->direita);
     }
     
     return;}

//--------------------------PROCURA DE FORMA RECURSIVA!-----------------------
void procurar(PontNo raiz, int valor,char inicio){
     if(raiz!=NULL){
     if(raiz->valor==valor){printf("O elemento ESTA contido!!!!!");return;}
     procurar(raiz->esquerda,valor,'0');
     procurar(raiz->direita,valor,'0');}
   
     return;}
     
//---------------------------Procura de forma iterativa!!!!-----------------
void procura_it(PontNo *raiz,int valor){
PontNo aux;
aux=(*raiz);
while(aux!=NULL){
 if(aux->valor==valor){printf("O elemento Foi encontrado!!!!=D");return;}
 if(aux->valor>valor){aux=aux->esquerda;}
 else if(aux->valor<valor){aux=aux->direita;}
}
printf("O elemento NAO foi encontradoo :( ");
return;}

     
     
