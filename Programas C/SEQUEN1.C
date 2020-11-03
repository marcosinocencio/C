#include <stdio.h>
#include <stdlib.h>

#define MSG1 "Introduza o numero de termos da sequencia : "
#define MSG2 "Introduza o %d-esimo termo da sequencia : "
#define MSG4 "\n\nPor favor, introduza um numero MAIOR OU IGUAL a 1"
#define MSG5 "\nPressione uma tecla para continuar!!!! "
#define MSG6 "\n\n\n Pressione a tecla 's' ou 'S' para executar o programa novamente ou "
#define MSG7 "\nqualquer outra tecla para finalizar. "

int  sp = 0, sn = 0, qp = 0, qn = 0, i = 1, n, num;
int continua = 1;
char ch;
int main(void) {
 
 do
  {

   do {
     system("cls");
     printf(MSG1);
     scanf("%d", &n);
     if ( n < 1 ) {
        printf(MSG4); 
        printf("\n\n");
	    system("Pause");
	 }
   } while (n < 1);
   
  sp = sn = qp = qn = 0; i = 1;
  for ( ;i <= n; i++) {
       printf("\n");
       printf(MSG2, i);
       scanf("%d", &num);
       if ( num >= 0 ) { sp += num; qp++;}
       else { sn += num; qn++; }
  }  // for

  printf("\nA soma dos numeros positivos e igual a %d",sp);
  printf("\nA quantidade de termos positivos e igual a %d",qp);
  printf("\n\nA soma dos numeros negativos e igual a %d",sn);
  printf("\nA quantidade de termos negativos e igual a %d",qn);

  printf(MSG6);   printf(MSG7);
  fflush(stdin);  // esvaziando o buffer de entrada associado ao teclado
  ch = getchar();
  if ( (ch == 's') || (ch == 'S') ) continua = 1;
  else continua = 0;
 }
 while ( continua ); // do-while mais externo

 printf("\n\n\n");
system("Pause");
return(0);
}
