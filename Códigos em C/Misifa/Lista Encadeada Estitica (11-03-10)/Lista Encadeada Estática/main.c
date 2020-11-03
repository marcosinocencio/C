#include <stdio.h>
#include <stdlib.h>

#include "listaencadeada.h"

int main (void){
    Lista lista;
    
    Start(&lista);
    while(Menu(&lista));
    
    system("pause");
    return(0);
}
