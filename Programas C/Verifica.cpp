#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////
int Verifica (int N);
int Primo (int M);
int Palindrome (int A);
long int Reverso (long int Nr, int M);
////////////////////////////////////////////////////////////
int Verifica (int N){
  
  if ((N%2) == 0)
  printf("\n\nO numero %d e par\n\n", N);
  else printf("\n\nO numero %d e impar\n\n", N);
}
////////////////////////////////////////////////////////////
int Primo (int M){
    int k = 0, i;
    
     for (i = 1; i <= M; i++){
         if ((M%i) == 0)
         k++; 
     }
     if (k == 2) printf("\nO numero e primo\n\n");
     else printf("\nO numero NAO e primo\n\n");
}
////////////////////////////////////////////////////////////

 int Palindrome (int A){
   int nc = A; 
        
   if ((Reverso(0,A)) == nc)
   printf("\nO numero e palindrome\n\n");
   else printf("\nO numero NAO e palindrome\n\n");
  
}

////////////////////////////////////////////////////////////

long int Reverso (long int Nr, int M){
  
 if (M == 0) return(Nr);
 else return (Reverso(Nr*10+M%10, M/10));


}
/////////////////////////////////////////////////////////////

int main (void){
    
    int x;
    
    printf("Insira um numero inteiro positivo:");
    scanf("%d", &x);
    
    Verifica(x);
    Primo(x);
    Palindrome(x);
    
    
system("pause");    
}
