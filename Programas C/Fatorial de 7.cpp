#include <stdio.h>
#include <stdlib.h>

#define MSG "\n\nNao e um numero inteiro positivo\n\n!!!!"

int i = 1,  num, fat = 1;


int main() {

   printf("Introduza um valor inteiro e positivo: ");
   scanf("%d",&num);
   if ( num >= 0) {
     for ( ; i<=num; i++){
      fat = fat*i;
    }
    printf("\n\nFatorial(%d) = %d \n\n",num,fat);
   }
   else printf(MSG);



system("Pause");
return(0);
}
