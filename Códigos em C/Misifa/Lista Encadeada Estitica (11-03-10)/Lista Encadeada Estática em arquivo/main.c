#include <stdio.h>
#include <stdlib.h>

#include "listaencadeada.h"

int main (void){
    FILE *fptr;
    
    fptr=fopen(Arq,"rb+");
    CreatLista(fptr);
    while(Menu(fptr));
    fclose(fptr);
    
    system("pause");
    return(0);
}
