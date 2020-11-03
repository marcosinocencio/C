#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEZ   10
#define NULA  "\0"
#define  PULA_LINHA printf("\n\n\n")

typedef char Cadeia[200];
typedef char Cadeia1[300];

short Verifica_Unidade(int Valor, char *Str);
short Verifica_Dezena(int Valor, char *Str);
void Verifica_Centavos(int Valor, char *Str_cent);
void Leitura_Valor_Numerico(long int *Valor);

Cadeia str_cent;
Cadeia1 str_final;

/****************************************************************/
/****************************************************************/
/* Verifica_Unidade: Funcao que processa o algarismo da unidade */
/* ================= e devolve a string correspondente.         */
/****************************************************************/
/****************************************************************/

short Verifica_Unidade(int Valor, char *Str) {
int uni = Valor % DEZ;
  if (uni) {
       switch (uni) {
         case 1 : strcat(Str," um ");     break;
	     case 2 : strcat(Str," dois ");   break;
	     case 3 : strcat(Str," tres ");   break;
	     case 4 : strcat(Str," quatro "); break;
	     case 5 : strcat(Str," cinco ");  break;
	     case 6 : strcat(Str," seis ");   break;
	     case 7 : strcat(Str," sete ");   break;
	     case 8 : strcat(Str," oito ");   break;
	     case 9 : strcat(Str," nove ");   break;
	   } // switch
       return(1);
  }
 else return(0);
}

/****************************************************************/
/****************************************************************/
/* Verifica_Dezena:  Funcao que processa o algarismo da dezena  */
/* ================= e devolve a string correspondente. Observem*/
/* que existe uma particularidade quando o algarismo da dezena e*/
/* igual a 1.                                                   */
/****************************************************************/
/****************************************************************/
short Verifica_Dezena(int Valor, char *Str)
{
int uni,     // algarismo da unidade
    deze;    // algarismo da dezena

  deze = (Valor/DEZ)%DEZ;
  if (!deze) return(0);
  else
   if ( deze == 1) {
	  uni = Valor % DEZ;
	  switch (uni) {
	    case 0 : strcat(Str," dez");       break;
	    case 1 : strcat(Str," onze");      break;
	    case 2 : strcat(Str," doze");      break;
	    case 3 : strcat(Str," treze");     break;
	    case 4 : strcat(Str," catorze");   break;
	    case 5 : strcat(Str," quinze");    break;
	    case 6 : strcat(Str," dezesseis"); break;
	    case 7 : strcat(Str," dezessete"); break;
	    case 8 : strcat(Str," dezoito");   break;
	    case 9 : strcat(Str," dezenove");  break;
      } // switch
	  return(1);
    } // if
   else {
       switch (deze) {
	     case 2 : strcat(Str," vinte ");     break;
	     case 3 : strcat(Str," trinta ");    break;
	     case 4 : strcat(Str," quarenta ");  break;
	     case 5 : strcat(Str," cinquenta "); break;
	     case 6 : strcat(Str," sessenta ");  break;
	     case 7 : strcat(Str," setenta ");   break;
	     case 8 : strcat(Str," oitenta ");   break;
	     case 9 : strcat(Str," noventa ");   break;
	   } // switch
       return(2);
   } // else
}  // Verifica_Dezena

/****************************************************************/
/****************************************************************/
/* Verifica_Centavos:  Funcao que contrói a string dos centavos */
/* ==================  a partir da  analise  dos  algarismos da */
/* da unidade e da dezena (1º e 2º da esquerda para a direita) e*/
/* devolve a string correspondente. 				            */
/****************************************************************/
/****************************************************************/

void Verifica_Centavos(int Valor, char *Str_cent) {

int  num = (Valor%100);
Cadeia str_u,    // string associada a unidade
       str_d;    // string associada a dezena

 strcpy(Str_cent,NULA);
 strcpy(str_u,NULA);
 strcpy(str_d,NULA);

 if ( !Verifica_Dezena(num, str_d) )      // algarismo da dezena e igual a zero
    {
      if ( Verifica_Unidade(num, str_u) )
	     if ( num%10 == 1) strcat(str_u," centavo");
	     else strcat(str_u," centavos");
      
      strcpy(str_cent,str_u);
    }
 else   // algarismo da dezena diferente de zero
   {
	 strcpy(str_u,NULA);
	 if ( Verifica_Unidade(Valor, str_u) == 0 ){   // algarismo da unidade igual a zero
	     strcat(str_u,"  centavos");
	     strcat(str_d , str_u);
	     strcpy(Str_cent,str_d);
	    } //if
	 else {
	    if ( num/10 != 1) {     // algarismo da dezena diferente de 1
		   strcat(str_d, " e ");
		   strcat(str_d, str_u);
        }
	    strcat(str_d," centavos");
	    strcpy(Str_cent,str_d);
     }	// else mais interno
  }	// else mais externo

}  // Verifica_Centavos


// Melhorar esta função de leitura para ler caractere a caractere. Assim, você
// poderá verificar possíveis erros de entrada. Se você ler uma string, poderá convertê-la
// para o valor numérico correspondente através da função atoi() atoif(). Verifique os manuais.

void Leitura_Valor_Numerico(long int *Valor) {
 do
  {
    printf("Introduza um valor entre 1 e 99 999 99: ");
    scanf("%ld",Valor);
  }
 while (*Valor < 1 || *Valor > 9999999);
 return;
} // Leitura_Valor_Numerico

int main(void) {
 long int value;

 Leitura_Valor_Numerico(&value);
 Verifica_Centavos(value,str_cent);
 strcat(str_final,str_cent);
 PULA_LINHA;
 puts(str_final);
 PULA_LINHA;
 
 system("Pause");
 return(0);
}
