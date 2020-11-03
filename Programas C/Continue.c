#include <stdio.h>
#include <stdlib.h>


#define MAX 5000
#define IMPAR(x) ( (x%2 != 0) ? 1: 0)

int i;

int main(void) {

for(i=1; i <= MAX; i++)
   if ( i == 100) break;
   else {
     if ( IMPAR(i) ) continue;
     printf("%d \n ",i);
   }

system("Pause");
return(0);

}
