#include <stdio.h>
#include <stdlib.h>

#define MAX   51



int main(void) {
 
char string[MAX], *str, string2[MAX];


	printf("Introduza uma < string >: "); 
    scanf("%s",string);
    printf("String introduzida: %s",string);

    fflush(stdin);
    printf("\n\n\n");
    printf("Introduza uma < string >: "); 
    str = gets(string2);
    
    printf("\n\n\n");
    puts(string2);
    puts(str);

  printf("\n\n\n");
  system("Pause");
  return(0);
}
