#include "Hashing.h"


int gera_valor( int valor){
 return(valor%MAX);}

void coloca_elemento(Linha *Ponteiros,int valor){
                             Linha aux, aux2;
                             int i;
                             i=gera_valor(valor);      
                                     aux=(Linha)malloc(sizeof(struct no));
                                     aux->prox=NULL;
                                     aux->valor=valor;
                                     if(*(Ponteiros+i)==NULL){ *(Ponteiros+i)=aux;}
                                     else{ aux2=*(Ponteiros+i); 
                                          while(aux2->prox!=NULL){
                                                                  aux2=aux2->prox;
                                                                  }
                                          aux2->prox=aux;
                      
                                          }
                                     
                                     return;}


void Inicializar_Lista(Linha *linCol){
     int i=0;
     while(i<MAX){
     *(linCol+i) = NULL; i++;
     }
     return;}
     

void imprime_toda(Linha *Ponteiro){
     int i=0;
     Linha aux;
     while(i<MAX){
     if(*(Ponteiro + i )==NULL){printf("%d)",i);}
     else{ printf("%d)",i); aux= *(Ponteiro + i );
           while(aux!=NULL){
            printf(" %d! ", aux->valor);
            aux=aux->prox;
            }
          }
          i++;printf("\n");}
          getchar();
     
    return;}
    
void Excluir(Linha *Ponteiro,int valor){
     Linha aux, aux2;
     aux=*(Ponteiro+gera_valor(valor));
     if(aux->valor==valor){ *(Ponteiro+gera_valor(valor))=aux->prox; aux=aux->prox;}
     else{if(aux->prox!=NULL){ 
                   if(aux->valor==valor){aux2=aux->prox;
                                                aux->prox=aux->prox->prox;
                                                free(aux2);             
                                               }
                   aux=aux->prox;}}
     return;}
     
void Busca(Linha *Ponteiro,int valor){
     char auxc='1';
     int i=0;
     Linha aux;
     while(i<MAX){
     aux= *(Ponteiro + i );
           while(aux!=NULL){
            if(valor==aux->valor) auxc='0';
            aux=aux->prox;
            }
          i++;}
          if(auxc=='0') printf("\n ELEMENTO ESTA CONTIDO");
          else printf("Elemento NAO está contido!!");
          getchar();
     return;}

