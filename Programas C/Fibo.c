#include <stdio.h>
#include <stdlib.h>

long int Fibonacci(long int F);



long int Fibonacci(long int F){
  
  if ((F == 1) || (F == 2)) return(1);
  else {   
   long int pen = 1, ant = 1, atual = 0, i = 3;     
    for( ; i <= F; i++) {                           
      atual = pen + ant;
      pen = ant;
      ant = atual;
    }
   return(atual);   
  } // else
 
} 	// Fibonacci



int main(int argc, int *argv[]) { 
long int num;
          
  if (argc != 2) {
      printf("Erro na entrada de Dados!!!\n");
      printf("Obedeca a sintaxe: < Fibonacci n1 > \n");
      printf("Tente novamente!!!");
      puts("\n\n\n"); 
      system("Pause");
      exit(1); 		// termino incondicional do programa
  }
          
          
          
  num = atol( argv[1] ); 
  printf("\n\n %ld \n\n", Fibonacci( num ));  
  
  
  
        
  puts("\n\n\n");      
system("Pause");
return(0);
} 
