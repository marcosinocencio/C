#include <stdio.h>
#include <stdlib.h>
#include <string.h>
////////////////////////////////////////////////////////////////////////////////
long int  Tamanho (char *str){

long int tamanho = 0;       
 
while(*(str +tamanho)!= '\0') 
    tamanho++;
       
return tamanho;       
}


////////////////////////////////////////////////////////////////////////////////
void Elimina (char *str){
 
int t;

t = Tamanho(str)-1;

if(*(str+t) == '\n')
    *(str+t) = '\0'; 

}
////////////////////////////////////////////////////////////////////////////////
char *Copia (char *destino, const char *origem){

int i=0; char *iniciodestino = destino;

while(*(origem+i) != '\0'){
     *(destino+i) = *(origem+i);         
     i++;
     }  
     *(destino+i) = '\0';
          
return iniciodestino;
}
////////////////////////////////////////////////////////////////////////////////
char *Concatena (char *destino, const char *origem){

int i=0, j = Tamanho(destino); char *iniciodestino = destino;
 
while(*(origem+i) != '\0'){
     *(destino+j) = *(origem+i);
     i++;
     j++;
     } 
     *(destino+j) = '\0';  
         
return iniciodestino;
}
////////////////////////////////////////////////////////////////////////////////
void Transforma (const char *origem){

int i;
 
i = *(origem+0);
    switch(i){
              
      case 48: printf("\n\nZero");
               break;        
      case 49: printf("\n\nUm");
               break;
      case 50: printf("\n\nDois");
               break;
      case 51: printf("\n\nTres");
               break;
      case 52: printf("\n\nQuatro");
               break;
      case 53: printf("\n\nCinco");
               break;
      case 54: printf("\n\nSeis");
               break;
      case 55: printf("\n\nSete");
               break;
      case 56: printf("\n\nOito");
               break;
      case 57: printf("\n\nNove");
               break;
      }
}
////////////////////////////////////////////////////////////////////////////////
void Ocorrenciachar (const char *str, int Ch,int *Pri, int *Ult, int *Qtd){

int i,j=0;
 
                 for(i=0; *(str+i) != '\0'; i++){
                    if(*(str+i) == Ch){
                        j++; 
                        
                    if (j>0 && j <2)
                      *Pri = i;
                              
                    else  *Ult = i;
                    }
                 }
if (j==0){
 *Pri = 0;
 *Ult = 0;
}

*Qtd = j;

}
////////////////////////////////////////////////////////////////////////////////
int Ocorrencia (const char *str, const char *str2, int M, int N){
     
int i,j;

if(N<=M){

         for(i=0; i <= M-N; i++){
                j=0;
                    while(j < N && *(str+i+j) == *(str2+j))
                      j++;
         if (j==N)
         return(1);
         }
       }
return (0);     
}
////////////////////////////////////////////////////////////////////////////////
int main (void){
    
int i,m,n;   char s[50], s2[50],c;    
    
      
printf("Insira uma string:");
fgets(s,50,stdin);    
Elimina(s); 
printf("\nInsira um char:");
scanf("%c" ,&c);
Ocorrenciachar(s,c,&i,&m,&n);
printf("\n\nO caracter %c aparece %d vezes na string %s. A primeira vez e na posicao %d",c,n,s,i);
printf("\n\nA ultima e na posicao %d",m);
system("pause");
return 0;    
}
