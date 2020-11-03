#include "Funcoes.h"


//----------------------------------------------------------//
void Construir (float pol[]){
     
 int g, i,continua; 
 static int p = 0;
 p++; 
 
  for (i = MAX-1; i > 0; i--)
    pol[i] = 0; 
 
 do { 
 continua = 1;     
 printf("\nDigite o grau do polinomio %d (Entre 1 a 100):",p);
 scanf("%d", &g);
 if (g >= 1 && g <= 100)
 continua = 0;
 } 
 while (continua);
 
 for (i=0; i<=g ;i++){
 printf("\nInsira o coeficiente do expoente x^%d:",i);
 scanf("%f", &pol[i]);  
 } 
 
 if (pol[g] == 0)
 do{
 continua = 1;
 printf("\nO grau do polinomio nao e %d, insira o coeficiente do expoente x^%d",g,g);
 printf(" diferente de 0:");
 scanf("%f", &pol[g]);  
 if (pol[g] != 0 )
  continua = 0;
 } while (continua);
 
 
 printf("\nPolinomio %d:", p);
 printf("\n\n");
  
 for (i = g;i > 0; i--)
  printf("%6.2fx^%d +  ", pol[i],i);
  printf("%6.2f  ", pol[i]);
  printf("= 0"); 
  printf("\n");   
 
}
//---------------------------------------------------------//
int Numero_Termos (float pol[]){
  int t = 0, i;  
  for (i = 0 ; i < MAX; i++){
     if (pol[i] != 0 )
     t++;
  }
  return t;
}

//---------------------------------------------------------//
int Grau (float pol[]){
   int g = 0, i;
   
    for (i = MAX-1; i > 0; i--){
        if(pol[i] != 0 && i > g)
        g = i; 
    }
   
   return g;
     
}
//---------------------------------------------------------//
void Imprimir (float pol[]){
 int g,i;
 
 g = Grau(pol); 
 
   
 for (i = g;i >= 0; i--){
     if ( pol[i] != 0)
     printf("%6.2fx^%d +  ", pol[i],i);
     
  }
  printf("\b\b\b");
  printf("= 0"); 
  printf("\n");   
 
}     
     
//----------------------------------------------------------//
float Calcula_x (float pol[], float val){
    int i,x;
    float v = 0, pot= 1, soma = 0;
    
    for (i = MAX-1; i > 0; i--){  
       if (pol[i] != 0){
         for (x = 0; x < i; x++)          
                pot  = val*pot;
                }
                              
                soma = pol[i]*pot;
                v = v + soma; 
                pot = 1;     
    }
    v = v + pol[0];
    
return v;      
}
//----------------------------------------------------------//
void Multiplica_Constante(float pol[], float k){
     
   int i;
   for ( i = MAX-1; i >= 0; i--){  
   pol[i] = pol[i]*k;     
     
   }
          
}
//----------------------------------------------------------//
void Somar (float pol1[], float pol2[], float polr[]){
    int i; 
               
    for(i = 0; i < MAX; i++)
      polr[i] = 0;      
    for(i = 0; i < MAX; i++){  
        polr[i] = pol1[i] + pol2[i];  
     }
}
//----------------------------------------------------------//
void Subtrair (float pol1[], float pol2[], float polr[]){
    int i; 
               
    for(i = 0; i < MAX; i++)
      polr[i] = 0;      
    for(i = 0; i < MAX; i++){  
        polr[i] = pol1[i] - pol2[i];  
     }
}

//----------------------------------------------------------//
void Multiplicar (float pol1[], float pol2[], float polr[]){
    int i,j;
    
               
    for (i = MAX-1; i >= 0; i--)
     polr[i] = 0; 
      
    for(i = 0; i < MAX; i++){
       for (j = 0; j < MAX; j++){
           if ((pol1[i] != 0) && (pol2[j] != 0) && (i+j<=100))
           polr[i+j] = polr[i+j] + pol1[i]*pol2[j];
       }   
          
      }
                                         
}
//----------------------------------------------------------//
void Integrar (float pol[]){
    int i; 
    float aux;   
        
    for(i = MAX-1; i >= 0; i--){
       if (pol[i] != 0){
        aux = pol[i];
        aux = aux/(i+1); 
        pol[i+1] = aux;
        }          
        pol[i] = 0;
     } 
}
//----------------------------------------------------------//
void Derivar (float pol[]){
     
    int i; 
    float aux;   
         
    pol[0] = 0;     
    for(i = 1; i <= MAX-1; i++){
        aux = pol[i];  
        aux = aux*i;
        pol[i-1] = aux;
        }
     pol[i] = 0;
         
}
//----------------------------------------------------------//
int Dividir (float pol1[], float pol2[], float polr[]){

     int i,j,k;
     float   aux[MAX];
    
     for (i = MAX; i >= 0; i--)
     aux[i] = 0; 
     
     for (i = MAX; i >= 0; i--)
     polr[i] = 0; 
     
     i = Grau(pol1);
     j = Grau(pol2);
    
     
     if(i<j)
            return (0);
     else{
          for (k = MAX; k >= 0; k--)
          aux[k] = pol1[k]; 
          
     do{
            polr[i-j] = aux[i]/pol2[j];
            for (k = j; k >= 0; k--)
                 aux[i-j+k] = aux[i-j+k] + (-1)*( polr[i-j]*pol2[k]);  
                 i--;                   
        } while(i >= j);
    }
    return(1);
}
     
//----------------------------------------------------------//
