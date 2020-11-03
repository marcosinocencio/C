#include "graficos.h"
#include "windows.h"
  
  void Desenha_Logo_Unesp2(void){
    textcolor(9);
    printf("\n\n\n %c    %c %c%c   %c %c%c%c%c%c %c%c%c%c%c %c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("\n %c    %c %c %c  %c %c     %c     %c   %c",219,219,219,219,219,219,219,219,219);
    printf("\n %c    %c %c  %c %c %c%c%c%c%c %c%c%c%c%c %c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("\n %c    %c %c   %c%c %c         %c %c",219,219,219,219,219,219,219,219);
    printf("\n %c%c%c%c%c%c %c    %c %c%c%c%c%c %c%c%c%c%c %c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    printf("\n");
    printf("\n");
    textcolor(15); 
}

  void Apresentacao(){
  int j;
  
   SetConsoleTitle("TRABALHO DE ESTRUTURAS DE DADOS - Gustavo da Mota Ramos e Fernando Matias de Oliveira");
       
   system("color 0f");
   
   Cursor(0,0);
   for(j=0;j<70;j++) {textbackground (8); printf(" ");}
   Cursor(0,0);
   textcolor(15); 
   printf("F1-Ajuda  Pressione qualquer tecla para iniciar o editor");
   textbackground (0);
   
   Cursor(3,0);    
   
       
       
       Desenha_Logo_Unesp2();
   
       printf("\n\n Disciplina: Estrutura de Dados 1\n Trabalho: EDITOR DE TEXTO\n Curso: Ciencia da Computacao\n");
       printf("\n\n Alunos:\n %c Gustavo da Mota Ramos\n %c Fernando Matias de Oliveira ",254,254);
       printf("\n\n Professor:\n %c Ronaldo Celso Messias Correia",254,254);
       
       getch();
       system("cls");
       
       printf("\n\n EDITOR DE TEXTO\n\n\n");
       printf("\n%c F1: Ajuda\n",254);
       printf("%c F2: Trocar cor da letra\n",254);
       printf("%c F4: Contar letras\n",254);
       printf("%c F5: Salvar arquivo\n",254);
       printf("%c F6: Abrir arquivo\n",254);
       printf("%c F8: Contar palavras\n",254);
       printf("%c F9: Contar linhas\n",254);
       printf("%c CTRL + F: Procurar palavra a partir da posicao do cursor\n",254);
       printf("%c CTRL + HOME: Ir para o inicio do texto\n",254);
       printf("%c CTRL + END: Ir para o fim do arquivo\n",254);
       
       printf("%c ESC: Fechar o editor\n",254);
       getch();
       system("cls");
  }
