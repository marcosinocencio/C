#include <stdio.h>
#include <stdlib.h>

int main (void){
    
    int  x = 0, i, j, k;
    
    
    for (k = 1; k <= 128; k += 1)
       for (j = 0; j < 512; j += 2)
           for (i = 1; i <= 1024; i += 4)
               x += 1;
               printf("%d\n\n", x);
    
    
system("pause");    
}
