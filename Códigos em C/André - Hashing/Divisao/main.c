#include <stdlib.h>
#include "Hashing.h"


int main(int argc, char *argv[]){
    Linha Ponteiros[MAX];
    int valor;
    char op;
    Inicializar_Lista(&Ponteiros[0]); //inicializar ! TUDO VAI PARA NULL!!!!
    while(1){
             system("cls");
             ESP printf("           HASHING  \n\n\n\n");
             ESP printf("2)Colocar um Elemento\n\n");
             ESP printf("3)Renover um Elemento\n\n");
             ESP printf("4)Imprimir tudo!\n\n");
             ESP printf("5)Buscar elemento\n\n");
             ESP printf("6)Sair\n\n\n               ->");
             op=getchar(); fflush(stdin);
            
             if(op=='2') {
             system("cls"); //Introduzir um novo elemento
             printf("Coloque o Valor: ");scanf("%d",&valor);fflush(stdin);
             coloca_elemento(&Ponteiros[0],valor);
             }
             if(op=='3') {    //excluir um elemento
             system("cls");
             printf("Coloque o Valor: ");scanf("%d",&valor);fflush(stdin);
             Excluir(&Ponteiros[0],valor);
             }
             if(op=='4'){    //Imprimir tudo!!!
             system("cls");
             imprime_toda(&Ponteiros[0]);
             }
             if(op=='5'){system("cls");                    //Buscar um elemento
             printf("Coloque o Valor: ");scanf("%d",&valor);fflush(stdin);
             Busca(&Ponteiros[0],valor);
                         }
             if(op=='6')break;  }           //para sair
    
    
    system("PAUSE");
    return 0;
}
