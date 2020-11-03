#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX   51



int main(void) {
 
char string[MAX], 
     *str = "Maria Amelia .kjkjkkkjkjkjkjkjkjkjj..", 
     string2[MAX], 
     str2[MAX] = "fjdkjfkjsdkjfklsjdkjfdklsjjdfk";

int d;


	printf("Introduza uma < string >: "); 
    scanf("%s",string);
    printf("String introduzida: %s",string);

    fflush(stdin);
    printf("\n\n\n");
    printf("Introduza uma < string >: "); 
    gets(string2);
    
    printf("\n\n\n");
    d = puts(string2);
    printf("\n %d\n\n", d);
    
    
    d = puts(str);
    
    printf("\n %d", strlen(str));

  printf("\n\n\n");
  
  puts(str2);
  system("Pause");
  return(0);
}
