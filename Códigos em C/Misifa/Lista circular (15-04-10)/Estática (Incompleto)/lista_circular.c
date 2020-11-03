#include "lista_circular.h"

void Menu(Lista *L){
     int op=0, info=0;
     
     printf("[1] Inserir na fila\n");     
     printf("[2] Retirar da fila\n");
     printf("[3] Imprimir fila\n");
     printf("[4] Sair\n");
     printf("Op: "); scanf("%d",&op);
     switch (op){
            case 1: printf("[1] Inserir na fila\n");
                    printf("Elemento: "); scanf("%d",info);
                    Insert(L,info);
            break;
            case 2: printf("[2] Retirar da fila\n");
                    if(Remove(L,info)) printf("Elemento retirado: %d", info);
            break;
            case 3: printf("[3] Imprimir fila\n");
                    Print(L);
            break;
            case 4: exit(0);
     }
}

void Start(Lista *L){
     L->inicio=-1;
     L->fim=-1;
     return;
}

short Insert(Lista *L, int Info){
      if (L->fim==-1) L->inicio=L->fim=0;
      if ((((L->fim)+1)%10)!=L->inicio){
         L->Lista[L->fim]=Info;
         if (L->fim==MAX-1) L->fim=0;
         else L->fim+=1;
         return(1);
      }
      return(0);
}

short Remove(Lista *L, int Info){
      if (L->inicio!=-1){
         Info=L->Lista[L->inicio];
         L->inicio+=1;
      }
      else return(0);
}

void Print(Lista *L){
   int i=0;
   
   for (i=L->inicio; i!=(L->fim); i++)
       printf("%d",L->Lista[i]); 
   return;
}
