
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    	// toupper

#define PULA  "\n\n\n"

//====================================================================
// Protótipos das funções
int    Menu(void);
short  Continua(void);
void   Leitura_Valor_Inteiro(int *Ptr);
int    Mdc(int A, int B);
//====================================================================


//====================================================================

// Elaborar comentários internos associados a cada uma das funções a exemplo
// dos primeiros códigos que foram passados a vocês.

int    Mdc(int A, int B){
int resto = 0;

    while ( B ) {
      resto = A%B;
      A = B;
      B = resto;
    } 
return(A);

}
//====================================================================

// Melhorar esse codigo

int Menu(void) {
int opcao;

	 

  return(opcao);
}


short Continua(void) {
int ch;

  do {
		system("cls");
        printf("\n\n\n      Voce deseja executar outra funcao? [S,N] : ");
		ch = getchar();
		ch= toupper(ch);
  }
  while( (ch != 'S') && (ch != 'N') );

  if(ch == 'S') return(1);
  else return(0);
}

int main(void) {
int a, b, op = 0;


 do {
	op = Menu();
	system("cls");
	printf("\n\n Opção escolhida foi: %c\n\n", op);
	
    switch(op)  {
	case'1':
		 printf("MDC ENTRE DOIS NUMEROS INTEIROS.\n\n");
         printf("Introduza um valor inteiro: ");
         scanf("%d",&a);
		 printf("Introduza um valor inteiro: ");
         scanf("%d",&b);
		 
		// printf("\n\n A= %d  B= %d",a, b);
		 printf("\n\n  MDC(%d,%d) = %d",a,b,Mdc(a,b));
		 printf(PULA);
         system("Pause");
         break;

	case'2':
		 printf("REVERSO DE UM NUMERO INTEIRO.");
		 system("pause");
         break;

	case'3':
		 printf("QUANTIDADE DE ALGARISMOS DE UM NUMERO INTEIRO.");
		 system("Pause");
		 break;

	case'4':
		 printf("K-ESIMO DIGITO DA DIREITA PARA A ESQUERDA.");
		 break;

	case'5':
		 printf("QUANTIDADE DE PRIMOS NUM INTERVALO.");
		 break;

	case'6':
		 printf("VERIFICAR SE UM NUMERO INTEIRO E PALINDROME.");
		 break;

	case'7':
		 printf("VERIFICAR SE EXISTEM DOIS DIGITOS ADJACENTES IGUAIS.");
		 break;

	case'8':
		 printf("ENCONTRAR A RAIZ CUBICA E UM NUMERO REAL.");
		 break;
	case'9': printf("OUTRAS FUNCOES....");
		break;

	}	//switch

  } while ( Continua() );

 printf(PULA);
 system("Pause");
 return(0);

}   // main
