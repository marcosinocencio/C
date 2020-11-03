#include <stdio.h>


// Observe que a função não preserva os valores entre as chamadas consecutivas

void Exemplo_Nao_Static(void){ 
int static a = 2;

  printf("\n\n %d \n ", a++);

  return;
}	 // Simples

 

int main(void){

    printf("\n\n SEM uso da Classe de armazenamento static");
    Exemplo_Nao_Static();
    Exemplo_Nao_Static();
    Exemplo_Nao_Static();
    Exemplo_Nao_Static();
    Exemplo_Nao_Static();
    Exemplo_Nao_Static();


system("Pause");
return(0);
}
 
