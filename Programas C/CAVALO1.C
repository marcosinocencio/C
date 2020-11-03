#include <stdio.h>
#include <stdlib.h>

#define MAX1 12
#define MAX2 10

void Inicializa_Tabuleiro(void);
void Atualiza_Nova_Posicao(int Visita, int Mov, int *Posx, int *Posy);
int Proximo_Movimento(int y, int x);
void Leitura_Posicao_Inicial(int *Posi, int *Posj);
void Imprime_Tabuleiro(void);

int Tabuleiro[MAX1][MAX1];


void Inicializa_Tabuleiro(void){
  int i,j;

  for(i=0; i < MAX1; i++)  // todas as casas ja visitadas
    for(j=0; j < MAX1; j++) Tabuleiro[i][j] = 1;

  for(i=2; i < MAX2; i++) // atualizando corretamente as casas visitadas
    for(j=2; j < MAX2; j++) Tabuleiro[i][j] = 0;

  return;
}


void Imprime_Tabuleiro(void) {
int i = 0, j;

  for (; i < MAX1; i++)
    {
      for (j=0; j < MAX1; j++) printf("%4d", Tabuleiro[i][j]);
      printf("\n");
    }
  return;
}



int Proximo_Movimento( int Posx, int Posy) {
 int pos=0;

 if(Tabuleiro[Posx-2][Posy+1] == 0) pos=1;
 else if (Tabuleiro[Posx-1][Posy+2] == 0) pos=2;
 else if (Tabuleiro[Posx+1][Posy+2] == 0) pos=3;
 else if (Tabuleiro[Posx+2][Posy+1] == 0) pos=4;
 else if (Tabuleiro[Posx+2][Posy-1] == 0) pos=5;
 else if (Tabuleiro[Posx+1][Posy-2] == 0) pos=6;
 else if (Tabuleiro[Posx-1][Posy-2] == 0) pos=7;
 else if (Tabuleiro[Posx-2][Posy-1] == 0) pos=8;

 return(pos);
}  // Proximo_Movimento

void Atualiza_Nova_Posicao(int Visita, int Mov, int *Posx, int *Posy) {
  switch( Mov ) {
      case 1: *Posx-=2; *Posy+=1; break;
      case 2: *Posx-=1; *Posy+=2; break;
      case 3: *Posx+=1; *Posy+=2; break;
      case 4: *Posx+=2; *Posy+=1; break;
      case 5: *Posx+=2; *Posy-=1; break;
      case 6: *Posx+=1; *Posy-=2; break;
      case 7: *Posx-=1; *Posy-=2; break;
      case 8: *Posx-=2; *Posy-=1;
    }

  Tabuleiro[*Posx][*Posy] = Visita;
  return;
}

void Leitura_Posicao_Inicial(int *Posi, int *Posj) {
 
 printf(" Introduza a linha da POSICAO INICIAL>> ");
 scanf("%d",Posi);    //  1 <= Posi <= 8
 printf("\n\n");
 printf(" Introduza a coluna da POSICAO INICIAL>> ");
 scanf("%d",Posj);    //  1 <= Posj <= 8

 (*Posi)++;  // atualizando as posicoes para o tabuleiro real (12x12)
 (*Posj)++;

 return;
}  // Leitura_Posicao_Inicial


int main(void) {
int pi, pj, continua_loop = 1, ordem_visita = 1;
int prox_mov = 0;

 Inicializa_Tabuleiro();
 Leitura_Posicao_Inicial(&pi, &pj);
 Tabuleiro[pi][pj] = 1;
 do
  {
   prox_mov = Proximo_Movimento(pi,pj);
   if ( prox_mov )
      {
       ordem_visita++;
       Atualiza_Nova_Posicao(ordem_visita, prox_mov, &pi, &pj);
      }
   else continua_loop = 0;
  } while (continua_loop);
  
  printf("\n\n\n");
  Imprime_Tabuleiro();

  printf("\n\n\nNumero de casas visitadas >>> %d \n\n", ordem_visita);
 
  system("Pause");
  return(0);
} // main
