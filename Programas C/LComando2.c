#include <stdio.h>
#include <stdlib.h>



int main(int arg_c, char *arg_v[], char *arg_vv[] );


// Observe que agora a funcao main() possui um terceiro parametro

int main(int arg_c, char *arg_v[], char *arg_vv[]) {
int i=0;
	      
  printf("Numero de argumentos em argv[] = %d \n",arg_c);
  
  for (; i<arg_c;i++)  
    printf("Argumento(%d) = %s \n\n",i, *(arg_v + i) );
    

  // Imprimindo todas as variaveis de ambiente de sua máquina
  for ( ; *arg_vv != NULL; arg_vv++)  
    printf(" %s \n\n", *(arg_vv) );



system("Pause"); 
return(0);
}

