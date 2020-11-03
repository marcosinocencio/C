#include <stdlib.h>
#include "Arvore.h"


int main(int argc, char *argv[]){
    PontNo raiz=NULL;           //ponteiro q irá apontar para a raiz!
    int valor;
    char op;  //controla as opcoes do menu!
    while(1){
             system("cls");
             ESP printf("           Arvore \n\n\n\n");
             ESP printf("1)Verificar se a Arvore esta vazia\n\n");
             ESP printf("2)Colocar um Elemento\n\n");
             ESP printf("3)Remover um Elemento\n\n");
             ESP printf("4)Imprimir Arvore!\n\n");
             ESP printf("5)Buscar elemento\n\n");
             ESP printf("6)Sair\n\n\n               ->");
             op=getchar(); fflush(stdin);
             if(op=='1'){
                         if(raiz==NULL){printf("\nA Arvore esta vazia!!!\n");}
                         else{printf("\nA Arvore contem Elementos\n");}
                         getchar();
                         }
             if(op=='2') { scanf("%d",&valor);
                         coloca_it(&raiz, valor);}
                         
             if(op=='3') {    printf("Coloque O elemento que será procurado e removido:");
                         scanf("%d",&valor);
              elemina_elemento(&raiz,valor);
             }
             if(op=='4'){  system("cls");  
             printf("\nESCOLHA A FORMA:\n");
             printf("1)Pré-ordem!\n");      //
             printf("2)Em-ordem!\n");       //
             printf("3)Pos-ordem!\n");      //
             op=getchar();
             if(op=='1'){Imprimir_pre(raiz);}
             if(op=='2'){Imprimir_em(raiz);}
             if(op=='3'){Imprimir_pos(raiz);}system("PAUSE");}
             if(op=='5'){scanf("%d",&valor);
                         procura_it(&raiz,valor);
                        system("PAUSE");}
             if(op=='6')break;  
             fflush(stdin);
             }           
    
    
    system("PAUSE");
    return 0;
}
