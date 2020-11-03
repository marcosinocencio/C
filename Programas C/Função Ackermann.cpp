#include <stdio.h>
#include <stdlib.h>
////////////////////////////////////////////////////////

int Funcao_Ackermann (int M, int N){

 if (M == 0) return(N+1);
 else if (N == 0) return(Funcao_Ackermann(M-1,1));
 else return(Funcao_Ackermann(M-1,Funcao_Ackermann(M,N-1)));
 

}
/////////////////////////////////////////////////////////


int main (void){
  
int x,y;  
    
printf("/////////////////////////////////////////////\n");    
printf("//                                         //\n");
printf("//          Funcao de Ackermann            //\n");    
printf("//                                         //\n");    
printf("/////////////////////////////////////////////\n");    
    
printf("\nInsira dois numeros inteiros positivos:");    
scanf("%d %d", &x , &y); 

printf("\n\nA funcao de Ackermann de (%d,%d) e: %d\n\n" , x, y, Funcao_Ackermann(x,y));    
    
    
system("pause");    
}
