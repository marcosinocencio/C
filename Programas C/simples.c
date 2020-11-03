#include <stdio.h>

 
void Simples(void){
static int a = 2;

     printf("\n\n %d \n ", a++);
return;
}	 // Simples


int main(void){

  Simples();
  Simples();
  Simples();
  Simples();
  Simples();
  
  

system("Pause");
return(0);
}
 
