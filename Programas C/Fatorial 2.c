#include <stdio.h>
#include <stdlib.h>

#define MSG "ERRO DE ENTRADA!!!!"

long int i = 1,  num;

double ab, fat = 1.0;

int main() {

   printf("Introduza um valor estritamente positivo: ");
   scanf("%lu",&num);
   if ( num >= 0) {
     for ( ; i<=num; i++){
      fat = fat*(double)i;
    }
    printf("\n\nFatorial(%lu) = %f \n\n",num,fat);
   }
   else printf(MSG);



system("Pause");
return(0);
}

