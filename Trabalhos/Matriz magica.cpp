#include <stdio.h>
#include <stdlib.h>

#define MAX 500

void Impre(int *A, int n){    
	 int i, j;
   	printf("\n\n Matriz Magica de Ordem : %d \n\n", n);
        
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        printf("  %3d ", *(A+n*i+j));
        printf("\n");    
    }
}


int Veri(int *A,int n){
 int i,j,a,b,c;
 a=b=c=0;
 
  for(i=0;i<n;i++) a+=*(A+i); 
  for(i=0;i<n;i++) b+=*(A+n*i); 
  for(i=0;i<n;i++) c+=*(A+i*n+i); 
  if((a==b)&&(b==c))return(a);
  else return(0);
}


void Matriz_impar(int *A, int n){  
    int i=0, j=n/2, k, np, vs=0,a,x=0;;
    for(k=1; k<=n*n; ++k){
              *(A + i*n + j) = k;
              i--;
              j++;
              if (k%n == 0){
			       i += 2;
			       j--;
		                   }
		       else{
		            if(j==n)
                      j -= n;
		            else if(i<0)
		              i += n;
		           }
    }
    a=Veri(A, n);
	np=(n*(n*n)+n)/2;
    if(np==a){Impre(A, n);puts("\n"); printf("\n Numero planetario:%d\n", np); }
    else { printf("\nErro na construcao da matriz!\n"); }
    for(x=0;x<=n*n;x++)vs+=x;
           printf(" Valor secreto:%d\n\n",vs);
return;
}


int Matriz_par(int *A,int n){
    int a,num=1,i,j,k,aux,m=n/2,np,vs=0,x=0;
        
  while(num<=n*n){
    k = ((m/2)-1);                   
       for(i=0;i<n;i++){//for externo
          if( ( i<=k ) || (i>=(m+(k+1))) ) {//if 1
               for(j=0;j<n;j++){//for 1
                 *(A+n*i+j) = num;
                  num++;       }//for 1
      	                                        }//if 1
          else{
                for(j=(n-1);j>=0;j--){//for 2
                  *(A+n*i+j) = num;                                    
                  num++;            }//for 2
		      }//else
        }//for externo
    }//while         
    i=0;                        
      while(((n-(i+1))-i)>=1){
            for(j=m/2;j<=m+k;j++){
               aux =*(A+n*i+j);
               *(A+n*i+j) = *(A+(n*(n-(i+1)))+j);
               *(A+(n*(n-(i+1)))+j) = aux;
                                     }
                      i++;
                              }                                           
    a=Veri(A,n);                         
    np=(n*(n*n)+n)/2;
    if(np==a){Impre(A, n);puts("\n"); printf("\n Numero planetario:%d\n", np); }
    else { printf("\n Matriz nao multipla de 4!\n"); }
    for(x=0;x<=n*n;x++)vs+=x;
    printf(" Valor secreto:%d\n\n",vs);
return(0);
             
       return(0); 
                     }
    
int main(void){
    int A[MAX][MAX] ,x,i;
    while(i=1){
   printf("                  MATRIZES MAGICAS\n\n");
    
    printf("\n\n Coloque a ordem da matriz desejada");
    scanf("%d",&x);
    if(x%2!=0)Matriz_impar(*A,x);
     else {Matriz_par(*A,x);}
    
    system("pause");
    system("CLS");
    printf("Deseja fazer uma nova operacao:\n1:Sim\n2:Nao\n");
    scanf("%d",&i);
    system("CLS");
    if(i==1)continue;
    else break;

    
   }
    
    return(0);
    
}
