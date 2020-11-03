#include <stdio.h>
#include <stdlib.h>


int Reverso(long int Nr, int N) {         // num >= 0


    if (N == 0) return(Nr);  // números entre 0 e 9.
    else return( Reverso(Nr*10+N%10, N/10) );


}  // Reverso


//=================================================================
//==============================================================

int Num_Algarismos(long int N) {         // num >= 0

    if (N <= 9) return(1);  // números entre 0 e 9.
    else return(1 + Num_Algarismos(N/10));

}  // Num_Algarismos



int main() {
long int num, n = 0;

    printf("Introduza um numero inteiro positivo: ");
    scanf("%ld",&num);
    printf("\n\n Numero_Algarismos(%ld) = %ld\n\n",num, Num_Algarismos(num));
        
    printf("\n\n Reverso(%ld) = %ld\n\n",num, Reverso(0,num));
    
        
    system("Pause");
return(0);
} 
