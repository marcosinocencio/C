#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>      // toupper



int ch, continua;

int main(void){
unsigned int p, primo, mult=0;  
      
      do {    
        printf("Insira o numero a ser fatorado: ");
        fflush(stdin);
        scanf ("%d",&p);
        printf("\n\n\n%d = ",p);
        system("cls");
        printf("\n\n  FATORES        MULTIPLICIDADE: \n");
        for(primo=2;primo <= p; primo++) {
          while( p%primo == 0){
             mult = mult+1;
             p = p/primo;
          }   // while
          if (mult != 0){
              printf("\n  %4d     \t     %4d ",primo,mult);
              mult=0;
          }
          if (p == 0) primo=p;
                                 }
       printf("\n\n*******************************\n\n");
       system("pause");
       do {
		  system("cls");
          printf("Deseja continuar executando?  <S,N>: ");
          fflush(stdin);
		  ch = getchar();
		  ch= toupper(ch);
       } while( (ch != 'S') && (ch != 'N') );

       if (ch == 'S') continua = 1;
       else continua = 0; 
     } while ( continua );
     
      
system("pause");
return(0);
}
                                 
    
