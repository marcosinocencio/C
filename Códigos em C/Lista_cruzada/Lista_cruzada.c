#include <stdlib.h>
#include <stdio.h>
#include "Lista_cruzada.h"

void Opcao ( int *op ){
    
  printf("\n****************************************************");
  printf("\n               Escolha o que deseja fazer:          ");
  printf("\n****************************************************");
  printf("\n[1] Inicializar a lista cruzada ");  
  printf("\n[2] Inserir elemento ");
  printf("\n[3] Remover elemento ");
  printf("\n[4] Imprimir lista cruzada - Matriz Esparsa ");
  printf("\n[0] Sair \n ->");
      *op = getchar();

return;
}
//------------------------------------------------------------------------------
void inicializa (struct lista_cruzada *lista){
    int i = 0;
    
      for( ; i < lista->n ; i++ ){
       lista->VC[i] = NULL;
       lista->VL[i] = NULL;    
    }

}
//------------------------------------------------------------------------------
void insere (struct lista_cruzada *lista, int elem, int linha, int coluna){
     No novoNo;
     No aux, ant;
     
     novoNo = (No)malloc(sizeof(struct no));
     novoNo->elem = elem;
     novoNo->coluna = coluna;
     novoNo->linha = linha;
     novoNo->proxC = NULL;
     novoNo->proxL = NULL;
     
     
     // Atualizando os ponteiros do índice coluna
     ant = NULL;
     aux = lista->VC[coluna];
          
      if( aux == NULL ) lista->VC[coluna] = novoNo;
        else{   
          while( aux != NULL && aux->linha < linha){
           ant = aux;
           aux = aux->proxL;
          }
          if(ant == NULL) 
          { 
                 lista->VC[coluna] = novoNo; 
                 novoNo->proxL = aux; 
          }
          
            else if (aux != NULL) {    
               ant->proxL = novoNo;
               novoNo->proxL = aux;
               }
               else ant->proxL = novoNo;
            } 
            
       // Atualizando os ponteiros do índice linha
       ant = NULL;
       aux = lista->VL[linha];
       
       if( aux == NULL ) 
       lista->VL[linha] = novoNo;
         else{
             while (aux != NULL && aux->coluna < coluna ){
               ant = aux;
               aux = aux->proxC;
              }
               if(ant == NULL) { 
                      lista->VL[linha] = novoNo;
                      novoNo->proxC = aux; 
                      }  // no começo
                else if(aux != NULL){ 
                  ant->proxC = novoNo;
                  novoNo->proxC = aux;    
                 }          
                 else ant->proxC = novoNo; 
            }                
     
return;     
}     
//------------------------------------------------------------------------------
void remove (struct lista_cruzada *lista, int linha, int coluna){
    No aux, ant; 
     
     ant = NULL;
     aux = lista->VL[linha];
       while( aux->coluna != coluna && aux != NULL){
         ant = aux; 
         aux = aux->proxC;  
        }
         if (aux == NULL) printf("\n ELEMENTO NAO ENCONTRADO \n");
          else if(ant == NULL) lista->VL[linha] = NULL; 
           else ant->proxC = aux->proxC;
          
      ant = NULL;    
      aux = lista->VC[coluna];
         while ( aux->linha != linha && aux != NULL){
            ant = aux;
            aux = aux->proxL;        
           }            
         if(aux == NULL) printf("\n ELEMENTO NAO ENCONTRADO \n");
          else if(ant == NULL) lista->VL[coluna] = NULL;
            else ant->proxL = aux->proxL; 
               
      free(aux);       
     

return;
}
//------------------------------------------------------------------------------
void imprime (struct lista_cruzada *lista){
    int i, j; 
    No aux;
      
      for ( i = 0 ; i < lista->n ; i++ ){
          printf("\n");
          aux = lista->VL[i];
          j = 0;          
            while (j < lista->n ){  
             if (aux != NULL) {
              if(aux->coluna == j){
               printf("%3d  ", aux->elem);
               aux = aux->proxC;     
               }
              else printf("%3d  ",0); 
             } 
             else printf("%3d  ",0);
             j++;    
            }
          } // for 
          
return;     
}   
//------------------------------------------------------------------------------  
