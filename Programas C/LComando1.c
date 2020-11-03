#include <stdio.h>
#include <stdlib.h>



int main(int arg_c, char *arg_v[]);



int main(int arg_c, char *arg_v[]) {
int i=0;
	      
  printf("Numero de argumentos em argv[] = %d \n",arg_c);
  
  for (; i<arg_c;i++)  
    printf("Argumento(%d) = %s \n\n",i, *(arg_v + i) );

system("Pause"); 
return(0);
}

