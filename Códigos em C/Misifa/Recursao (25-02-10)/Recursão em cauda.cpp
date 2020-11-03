#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct{
       int C[MAX];
} vetor;

void PrintVet(vetor V, int i, int n);
void PV(vetor *V);

void PrintVet(vetor V, int i, int n){

     if (i<n){
        printf("%d\n",V.C[i]);
        PrintVet(V,i+1,n);
     }
     return;        
}

void PV(vetor *V){
     int i=0;
     
     for (i=0;i<MAX;i++)
         V->C[i]=1;
     return;     
}

int main (void){
    vetor V;
    
    PV(&V);
    PrintVet(V,0,MAX);
    system("pause");
    return(0);    
}
