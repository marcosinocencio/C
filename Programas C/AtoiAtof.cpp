// Exemplo do uso de atoi(), atol() e atof().

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef char string[MAX];

int main() {
    
    printf("\n\n\t\tCONVERSAO DE STRINGS PARA VALORES NUMERICOS INTEIROS\n\n");
    printf("\n  %10s \t = %10d", "123",    atoi("123"));
    printf("\n  %10s \t = %10d", "-123",   atoi("-123"));
    printf("\n  %10s \t = %10d", "12abc3", atoi("12abc3"));
    printf("\n  %10s \t = %10d", "abs123", atoi("abs123"));
    printf("\n  %10s \t = %10d", "1.23",   atoi("1.23"));

    printf("\n\n\t\tCONVERSAO DE STRINGS PARA VALORES NUMERICOS INTEIROS LONGOS\n\n");
    printf("\n  %10s \t = %10ld", "89035",    atol("89035"));
    printf("\n  %10s \t = %10ld", "-89035",   atol("-89035"));
    printf("\n  %10s \t = %10ld", "89035  ",  atol("89035  "));
    printf("\n  %10s \t = %10ld", "ab4567",   atol("ab4567"));
    printf("\n  %10s \t = %10ld", "1982.23",  atol("1982.23"));

    printf("\n\n\t\tCONVERSAO DE STRINGS PARA VALORES NUMERICOS DO TIPO DOUBLE \n\n");
    printf("\n  %10s \t = %15lf", "890.35",   atof("890.35"));
    printf("\n  %10s \t = %15lf", "-890e3",   atof("-890e3"));
    printf("\n  %10s \t = %15lf", "8903e-5",  atof("8903e-5"));
    printf("\n  %10s \t = %15lf", "ab4567",   atof("ab4567"));
    printf("\n  %10s \t = %15.10lf", "1982.23",  atof("1982.23"));
    printf("\n  %10s \t = %15lf", "123456e-05",atof("123456e-05"));

puts("\n\n");
system("Pause");
return(0);
}
