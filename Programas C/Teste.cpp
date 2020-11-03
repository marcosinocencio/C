#include <stdio.h>
#include <stdlib.h>

int main (void){
    
    int n, m, i, j, k;
    
    n = 4; m = 5;
    for (k = 1; k <= n; k += 3)
       for (j = 0; j < m; j += 2)
           for (i = 3; i <= j; i += 1)
               printf(" %d, %d, %d\n\n", k, j, i);
    
    
    
system("pause");    
}
