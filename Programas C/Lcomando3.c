#include <stdio.h>
#include <stdlib.h>

int main(int arg_c, char *arg_v[]) {
int i=1,		// nao somar o primeiro parametro
 soma = 0;
	      
	      
 for (; i<arg_c;i++)  
  printf("Argumento(%d) = %s \n\n",i, *(arg_v + i) );
    
 printf("Numero de argumentos em argv[] = %d \n",arg_c);
 for (; i<arg_c;i++) soma += atoi( arg_v[i] );  
  
printf("\nForam passados %d valores a serem somados", --arg_c);
printf("\n\n Soma Obtida = %d \n\n",soma);

system("Pause");  
return(0);
}

