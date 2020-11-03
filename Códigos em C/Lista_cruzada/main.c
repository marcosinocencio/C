#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Lista_cruzada.h"

int main(int argc, char *argv[]){
    
   struct lista_cruzada lista;
   int op, elem, control = 1, aux, linha, coluna;
   
    do { 
     system("cls");     
     Opcao(&op);    
     fflush(stdin);
   
       switch(op){
        case '1': 
         printf("\n Insira a dimensao da lista cruzada: ");
         scanf("%d", &lista.n);        
         inicializa(&lista);
         system("pause");
         break;
       
        case '2': 
         printf("\n Insira a linha: ");
         scanf("%d", &linha);
         printf("\n Insira a coluna: ");
         scanf("%d", &coluna);
         printf("\n Elemento: ");
         scanf("%d", &elem);
         insere (&lista,elem,linha,coluna);     
         system("pause");
         break;
        
        
        case '3':  
          printf("\n Insira a linha do elemento: ");
          scanf("%d", &linha);   
          printf("\n Insira a coluna do elemento: ");
          scanf("%d", &coluna);
          remove(&lista,linha,coluna);
          system("pause");
         break;
         
         
        case '4':  
         imprime(&lista);
         puts("\n\n");
         system("pause");
         break;
         
          
         case '0':
            do{
           system("cls");
           printf("\n Deseja realmente sair? [S,N]");
           op = getchar();
           op = toupper(op);
           fflush(stdin);
          } while ((op!='N') && (op!='S')); 
           if( op == 'S' )control = 0;   
          break;
         
        }  
     } while ( control ); 
    
    
    
system("pause");
return(0);
}
