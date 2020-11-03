#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef int vetor[MAX];

void PrintVet(vetor V, int i, int n);
void PV(vetor *V);

void PrintVet(vetor V, int i, int n){

     if (i<n){
        printf("%d\n",V[i]);
        PrintVet(V,i+1,n);
     }
     return;        
}

void PV(vetor V){
     int i=0, uax=1;
     
     for (i=0;i<MAX;i++){
         V[i]=uax;
         uax*=2;
     }
     return;     
}

int main (void){
    vetor V;
    
    PV(V);
    PrintVet(V,0,MAX);
    system("pause");
    return(0);    
}
