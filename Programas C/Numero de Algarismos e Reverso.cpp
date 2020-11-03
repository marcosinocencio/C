#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////

long int Num_Alg (long int N){

 if (N <= 9) return(1);
 else return(1 + Num_Alg(N/10));


}

/////////////////////////////////////////////////


long int Reverso (long int Nr, int M){
  
 if (M == 0) return(Nr);
 else return (Reverso(Nr*10+M%10, M/10));


}
//////////////////////////////////////////////////

int main (void){
    
long int x;    
    
    
printf("Introduza um numero inteiro positivo:");
scanf("%ld", &x);    
    
printf("\nO numero reverso de (%ld) e: %ld\n\n",x, Reverso(0,x));    
printf("\nA quantidade de algarismos de (%ld) e: %ld\n\n",x, Num_Alg(x));   
    
    
system("pause");    
}
