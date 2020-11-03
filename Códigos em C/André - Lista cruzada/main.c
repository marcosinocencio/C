#include "cruzada.h"


int main(void){
    int valor,i,j;  //valor(o valor da posicao) i(linha) j(coluna)
    char op;
    Lista Linha[MAX],Coluna[MAX];   
    Inicializar_Lista(&Linha[0]);   
    Inicializar_Lista(&Coluna[0]);
  
    while(1){system("cls");
            ESP printf("           MATRIZ  \n\n\n\n");
            ESP printf("1)Limpar a Matriz\n\n");
            ESP printf("2)Colocar um Elemento\n\n");
            ESP printf("3)Renover um Elemento\n\n");
            ESP printf("4)Imprimir a matriz\n\n");
            ESP printf("5)Buscar elemento\n\n");
            ESP printf("6)Sair\n\n\n               ->");
            op=getch();
             if(op=='1') {system("cls");
             Inicializar_Lista(&Linha[0]);    // Tudo apontará para NULL!!
             Inicializar_Lista(&Coluna[0]);   //tudo apontará para NULL!!
             
             }
             if(op=='2') {system("cls");
             printf("\n\n        Linha: ");scanf("%d",&i);i--;
             printf("\n        Coluna"); scanf("%d",&j); j--;
             printf("\n        Valor"); scanf("%d",&valor); 
             coloca_valor(valor,i,j,&Linha[0],&Coluna[0]);
             }
             if(op=='3') {system("cls");
             printf("\n      Linha:");scanf("%d",&i);
             printf("Coluna:");scanf("%d",&j);
             
             }
             if(op=='4') {system("cls");
             imprimir_matriz(&Linha[0]);
             getch();
             
             }
             if(op=='5'){system("cls");
                           printf("\n        Valor"); scanf("%d",&valor); 
                         if(busca_elem(&Linha[0],valor)) printf("Elemento está contido");
                         else printf("Elemento Nao está contido");
                         getch();
                         }
             if(op=='6')break; 
            fflush(stdin); }
   
return 0;}
