#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int i=1,j,k;
int main(void) {
 
 for ( ;i <= MAX; i++ ) {
     if (i%2 == 0 ) continue;
     printf(" %d  ",i);
     printf("\n");
    }
 printf("\n Sai do Loop");

system("Pause");
return(0);
}
