#include "cruzada.h"


void coloca_valor(int valor, int i, int j, Lista *Linha, Lista *Coluna){
     Lista novo, aux, aux2;
     novo=(Lista)malloc(sizeof(struct elemento));
     novo->i=i; novo->j=j; novo->valor=valor;
     if(Linha[i]==NULL && Coluna[j]==NULL){
                         *(Linha + i)=novo;
                        *(Coluna + j)=novo;
                         novo->pc=NULL; novo->pl=NULL;
                         }
    else{

         if(Linha[i]==NULL && Coluna[j]!=NULL){
                           Linha[i]=novo; //Como nao tem ninguem na linha, recebe o endereco do novo
                           aux=Coluna[j]; //aux vai receber o endereco do primeiro elemento da coluna
                            novo->pl=NULL; //aterro a proxima linha do elemento novo
                           if(aux->i > i){ //o valor da linha é maior do q a linha atual, significa q o novo no sera coloca antes
                                     novo->pc=aux; //o novo vai apontar para o primeiro elemento achado, montando o encadeamento
                                     Coluna[j]=novo; //a coluna aponta para o novo
                                     }else{ while(aux->i < i){//o laco while pega o endereco do anterior ao no
                                           aux2=aux; //aux2 e o anterior do aux
                                           aux=aux->pc;
                                           if(aux==NULL)break; //Nao existe
                                           }
                                           if(aux!=NULL){novo->pc=aux2->pc;//Monta o encadeamento entre dois nos
                                           aux2->pc=novo;}
                                           else{novo->pc=NULL;
                                                aux2->pc=novo;

                                                }

                                           }
                           }

         else {
              if(Linha[i]!=NULL && Coluna[j]==NULL){
                Coluna[j]=novo;
                           aux=Linha[i];
                            novo->pc=NULL;
                           if(aux->j > j){
                                     novo->pl=aux;
                                     Linha[i]=novo;
                                     }else{ while(aux->j < j){
                                           aux2=aux;
                                           aux=aux->pl;
                                           if(aux==NULL)break;
                                           }
                                           if(aux!=NULL){novo->pl=aux2->pl;
                                           aux2->pl=novo;}
                                           else{novo->pl=NULL;
                                                aux2->pl=novo;
                                                }

                                           }
              }

         else {if(Linha[i]!=NULL && Linha[j]!=NULL){

                           aux=Linha[i];

                           if(aux->j > j){
                                     novo->pl=aux;
                                     Linha[i]=novo;
                                     }else{ while(aux->j < j){
                                           aux2=aux;
                                           aux=aux->pl;
                                           if(aux==NULL)break;
                                           }
                                           if(aux!=NULL){novo->pl=aux2->pl;
                                           aux2->pl=novo;}
                                           else{novo->pl=NULL;
                                                aux2->pl=novo;
                                                }

                                           }


                           aux=Coluna[j];

                           if(aux->i > i){
                                     novo->pc=aux;
                                     Coluna[j]=novo;
                                     }else{ while(aux->i < i){
                                           aux2=aux;
                                           aux=aux->pc;
                                           if(aux==NULL)break;
                                           }
                                           if(aux!=NULL){novo->pc=aux2->pc;
                                           aux2->pc=novo;}
                                           else{novo->pc=NULL;
                                                aux2->pc=novo;

                                                }

                                           }}

         }}}

     return;}

void Inicializar_Lista(Lista *linCol){
     int i=0;
     while(i<MAX){
     *(linCol+i) = NULL; i++;
     }
     return;}



void imprimir_matriz(Lista *Linha){
     int i=0, total=0;
     Lista aux;
     while(i<MAX){
                   if(Linha[i]==NULL){ while(total<MAX){printf(" 0 ");total++;}total=0;}
                   else{
                        aux=Linha[i];
                        while(total<MAX){
                                 if(aux!=NULL){if(total==aux->j) {printf(" %d ", aux->valor);aux=aux->pl;total++;}
                                               else{printf(" 0 ");total++;}}
                                 if(aux==NULL){ printf(" 0 ");
                                      total++;}
                                       } total=0;

                                          }
                   printf("\n");i++;
                   }
     return;}


int busca_elem(Lista *Linha, int busca){
     int i=0;
     Lista Elem;
     while(i<MAX){
                  if(*(Linha + i)!=NULL){
                             Elem=*(Linha + i);
                  while(Elem!=NULL){
                                    if(Elem->valor=busca) return(1);
                                    Elem=Elem->pl;
                                    }

                  }

                  i++;}
     return(0);}
