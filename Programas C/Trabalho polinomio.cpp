#include <stdio.h>
#include <stdlib.h>
#include <math.h>  
#define MAX 100


  int soma(int A[],int B[],int C[]){
      int a,x;
        if(a=3)
                        {for(x=0;x<MAX;x++)
                         printf("\nArray[%d]=%dx^%d\n",x,A[x]+B[x]+C[x],x);
                        }
                 else {
                        {for(x=0;x<MAX;x++)
                        printf("\nArray[%d]=%dx^%d\n",x,A[x]+B[x],x);
                        }
                        }
                         
                         return(0);}
                         
int derivada(int A[]){
    int i,b[MAX];
    for(i=1;i<MAX;i++){
     b[i-1]=A[i]*i;
     printf("\n\nA derivada de A[%d]=%d",i-1,b[i-1]);
                        }
     return(0);
     }
     
                         
     int multi(int A[],int B[],int C[],int a){
      int y,x,c[MAX];
       y=a;
        switch(y){
                case 3:  for(x=0;x<MAX;x++){
                         printf("\nArray[%d]=%dx^%d\n",x,A[x]*B[x]*C[x],x);}
                         break;
                          
                case 2:
                          for(x=0;x<MAX;x++){
                          printf("\nArray[%d]=%dx^%d\n",x,A[x]*B[x]*1,x);}        
                          break;         
                          
              case 1:  printf("Erro nos dados de entrada\n\n");break;
                       }
                         return(0);}
          
          
      int constante(int A[],int B[],int C[],int a){
       int z,i,y,x;
        printf(" Coloque o valor da contante desejada:");
        scanf("%d",&z);
         y=a;
        switch(y){
                case 3:  for(x=0;x<MAX;x++)
                         printf("\nArray[%d]=%d^%d\n",x,A[x]*z,x);
                         for(x=0;x<MAX;x++)
                         printf("\nArray[%d]=%d^%d\n",x,B[x]*z,x);
                         for(x=0;x<MAX;x++)
                         printf("\nArray[%d]=%d^%d\n",x,C[x]*z,x);
                         break;
                          
                case 2:                                            
                         for(x=0;x<MAX;x++)
                         printf("\nArray[%d]=%d^%d\n",x,A[x]*z,x);
                         for(x=0;x<MAX;x++)
                         printf("\nArray[%d]=%d^%d\n",x,B[x]*z,x);
                         break;        
                          
              case 1:  for(x=0;x<MAX;x++)
                         printf("\nArray[%d]=%d^%d\n",x,A[x]*z,x);
                         break;
                         }
                         return(0);}
                           

     int valor_especi(int A[],int B[],int C[],int a){
       int i,c,d,e,y,z,x;
      
     
      switch(a){
            case 1:   printf("Coloque o valor do especifico de x:");
                      scanf("%d",&x);
                      for(i=0;i<MAX;i++){
                      c=pow(x,i);
                      printf("\n\nArray[%d]=%d",i,A[i]*c);
                                        }
                      break;
         case 2:      printf("Coloque o valor do especifico de x do polinomio 1:");
                      scanf("%d",&x);
                      for(i=0;i<MAX;i++){
                      c=pow(x,i);
                      printf("\n\nArray[%d]=%d",i,A[i]*c);
                                        }
                      
                      printf("\n\nColoque o valor do especifico de x do polinomio 2:");
                      scanf("%d",&d);
                      for(i=0;i<MAX;i++){
                      c=pow(d,i);
                      printf("\n\nArray[%d]=%d",i,B[i]*c);
                                        }
         
                        break;
           case 3:    printf("Coloque o valor do especifico de x do polinomio 1:");
                      scanf("%d",&x);
                      for(i=0;i<MAX;i++){
                      c=pow(x,i);
                      printf("\n\nArray[%d]=%d",i,A[i]*c);
                                        }
                      
                      printf("\n\nColoque o valor do especifico de x do polinomio 2:");
                      scanf("%d",&d);
                      for(i=0;i<MAX;i++){
                      c=pow(d,i);
                      printf("\n\nArray[%d]=%d",i,B[i]*c);
                                        }
                                 
                      printf("\n\nColoque o valor do especifico de x do polinomio 2:");
                      scanf("%d",&d);
                      for(i=0;i<MAX;i++){
                      c=pow(d,i);
                      printf("\n\nArray[%d]=%d",i,C[i]*c);
                                        }                  
                                        
                                        break;
            }
            return(0);
            }





int main (void){
 int g;
 
 printf("Douglas Panacho Ferreira Lima  R.A:1295268\n");
 printf("Luis Felipe L. dos Santos      R.A:1295900\n");
 printf("Marcus Vinicius Inocencio      R.A:1295387\n\n");
  
  system("pause");
  system("CLS");
  
  
 g=1;
 while(g==1){
             
 int a,b,c,d=0,e=0,f=0,i,j,k,l,array[MAX]={0},array1[MAX]={0},array2[MAX]={0},opcao,cont,var[MAX]={0},var1[MAX]={0},var2[MAX]={0};
 int t=0,m=0,n=0;

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 printf("*********************************************************************************************");
 printf("*********************************************************************************************");
 printf("******OPERACAO COM POLINOMIOS********************************");
 printf("*********************************************************************************************");
 printf("************************************************************\n\n\n");
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

 printf("O programa é capaz de realizar operaçoes aritmeticas com um,\ndois e tres polinomios somente!\n\n\n\n\n\n\n\n\n");
    system("pause");  system("CLS");
 printf("Coloque a quantidade de polinomios desejados:");

 scanf("%d",&a);
 
 

 i=0;t=0; m=0;
 
 switch(a){
           
           case 1: printf("Coloque a quantidade de termos do polinomio:");
                   scanf("%d",&d);
                     for(j=1;j<=d;j++){ 
                     printf("Coloque o valor da base desejada:");
                     scanf("%d",&b);
                     printf("Coloque o valor do expoente:");
                     scanf("%d",&c);
                      for(i=1;i<=d;i++)
                         if(var[i]==c){printf("Esse expoente ja foi utilizado!!!\n\n");printf("Se utilizado novamente o mesmo exponte,a base sera substituida!\n");
                                       printf("\nColoque um novo expoente:");scanf("%d",&c);var[j]=c;break;}
                     var[j]=c; 
                    if(c>=t)t=c;
                     array[c]=b; 
                        
                                       }
             break;
             
             case 2:printf("Coloque a quantidade de termos do polinomio:");
                   scanf("%d",&d);
                     for(j=1;j<=d;j++){ 
                     printf("Coloque o valor da base desejada:");
                     scanf("%d",&b);
                     printf("Coloque o valor do expoente:");
                     scanf("%d",&c);
                      for(i=1;i<=d;i++)
                         if(var[i]==c){printf("Esse expoente ja foi utilizado!!!\n\n");printf("Se utilizado novamente o mesmo exponte,a base sera substituida!\n");
                                       printf("\nColoque um novo expoente:");scanf("%d",&c);var[j]=c;break;}
                     var[j]=c; 
                    if(c>=t)t=c;
                     array[c]=b; 
                        
                                       }
                                    
                    printf("Coloque a quantidade de termos do polinomio 2:");
                    scanf("%d",&e);
                      for(k=1;k<=e;k++){
                        printf("Coloque o valor da base desejada:");
                        scanf("%d",&b);
                        printf("Coloque o valor do expoente:");
                        scanf("%d",&c);
                        for(i=1;i<=d;i++)
                         if(var1[i]==c){printf("Esse expoente ja foi utilizado!!!\n\n");printf("Se utilizado novamente o mesmo exponte,a base sera substituida!\n");
                                       printf("\nColoque um novo expoente:");scanf("%d",&c);var1[k]=c;break;}
                        var1[k]=c; 
                        if(c>=m)m=c;
                        array1[c]=b;
                      
                                       }
                        break;
                        
             case 3: printf("Coloque a quantidade de termos do polinomio 1:");
                    scanf("%d",&d);
                     for(j=1;j<=d;j++){
                        printf("Coloque o valor da base desejada:");
                        scanf("%d",&b);
                        printf("Coloque o valor do expoente:");
                        scanf("%d",&c);
                        for(i=1;i<=d;i++)
                         if(var[i]==c){printf("Esse expoente ja foi utilizado!!!\n\n");printf("Se utilizado novamente o mesmo exponte,a base sera substituida!\n");
                                       printf("\nColoque um novo expoente:");scanf("%d",&c);var[j]=c;break;}
                        var[j]=c; 
                        if(c>=t)t=c;
                        array[c]=b;
                         }
                  
                    printf("Coloque a quantidade de termos do polinomio 2:");
                    scanf("%d",&e);
                      for(k=1;k<=e;k++){
                        printf("Coloque o valor da base desejada:");
                        scanf("%d",&b);
                        printf("Coloque o valor do expoente:");
                        scanf("%d",&c);
                        for(i=1;i<=d;i++)
                         if(var1[i]==c){printf("Esse expoente ja foi utilizado!!!\n\n");printf("Se utilizado novamente o mesmo exponte,a base sera substituida!\n");
                                       printf("\nColoque um novo expoente:");scanf("%d",&c);var1[k]=c;break;}
                        var1[k]=c; 
                        if(c>=m)m=c;
                        array1[c]=b;
                               }
                        
                    printf("Coloque a quantidade de termos do polinomio 3:");
                    scanf("%d",&f);
                     for(l=1;l<=f;l++){
                        printf("Coloque o valor da base desejada:");
                        scanf("%d",&b);
                        printf("Coloque o valor do expoente:");
                        scanf("%d",&c);
                        for(i=1;i<=d;i++)
                         if(var2[i]==c){printf("Esse expoente ja foi utilizado!!!\n\n");printf("Se utilizado novamente o mesmo exponte,a base sera substituida!\n");
                                       printf("\nColoque um novo expoente:");scanf("%d",&c);var2[l]=c;break;}
                        var2[l]=c; 
                        if(c>=n)n=c;
                        array2[c]=b;
                              }
                      break;
                      
                      }
                   
 
    
 system("CLS");
    
    printf("Escolha a operaçao deseaja:\n\n\n");
    printf("1-Soma de polinomios.\n2-Multiplicacao de polinomios.\n3-Calcular o valor de um polinômio num valor x especifico.\n4-Multiplicar o polinomio por uma constante.\n5-Derivar o polinomio.\n6-Determinar o grau e termo do polinomio.\n\n");
    scanf("%d",&opcao);

system("CLS");

    switch(opcao){
      case 1: soma(array,array1,array2);break;
      case 2: multi(array,array1,array2,a) ;break;
      case 3: valor_especi(array,array1,array2,a);break;
      case 4: constante(array,array1,array2,a);break;
      case 5: switch(a){
                case 1:derivada(array);break;
                case 2:derivada(array);derivada(array1);break;
                case 3:derivada(array);derivada(array1);derivada(array2);break;
                              }       break;
      case 6: if(a==1)printf("O polinomio é de grau %d e o maior termo é %d\n\n",t,array[t]);
              else if(a==2){printf("O polinomio é de grau %d e o maior termo é %d\n\n",t,array[t]);printf("O polinomio é de grau %d e o maior termo é %d\n\n",m,array1[m]);}
              else if(a==3){printf("O polinomio é de grau %d e o maior termo é %d\n\n",t,array[t]);printf("O polinomio é de grau %d e o maior termo é %d\n\n",m,array1[m]);printf("O polinomio é de grau %d e o maior termo é %d\n\n",n,array2[n]);}
             
      
      break;
              
               }
               system("pause");
               system("CLS");
   printf("Deseja fazer uma nova operacao:\n1:Sim\n2:Nao\n");
   scanf("%d",&g);
   system("CLS");
  
  }

   
 system("pause");   
 
 
}  
