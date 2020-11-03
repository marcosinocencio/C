#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <windows.h>

#define DEZ 10
#define NULA " "

typedef char Cadeia[200];
typedef char Cadeia1[300];

/////////////////////////////////////////////////////////////////////////////////////////
void cabecalho (void);
void instrucoes (void);
void cheque ();
void data (void);
void imprime(void);
short Unidade(long int Valor, char *A);
short Dezena(long int Valor, char *A);
short Centena(long int Valor, char *A);
short CentenaR(long int Valor, char *A);
short CentenaM(long int Valor, char *A);
short Centavos(long int Valor, char *Str_cent);
short Reais(long int Valor, char *Str_cent);
short Milhar(long int Valor, char *Str_cent);
void gotoxy(int x, int y);
void limpalinha(void);
int verifica_mes(char *A);
void Leitura_Valor(long int *Valor);
void imprime_cheque(long int value);
////////////////////////////////////////////////////////////////////////////////////////////////
int main (void){
    
    int enter;
    char valor_cheque[100];
    
     
    instrucoes();
    
    
    cabecalho();
    puts("\n\n");
    cheque();
    
    imprime();
        
return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
void cabecalho (void){
    
    int i; 
     

    printf (" %c",201);
    for(i=0;i<98;i++) printf ("%c",205);
    printf ("%c\n",187);    
    
    
    printf (" %c",186);
    printf ("                                                                                                  ");
    printf ("%c\n",186);
    
    
    printf (" %c",186);
    printf ("                             ALGORITMO PARA PREENCHIMENTO DE CHEQUES                              ");
    printf ("%c\n",186);
    
    
    printf (" %c",186);
    printf ("                                                                                                  ");
    printf ("%c\n",186);
    
    
    printf (" %c",200);
    for(i=0;i<98;i++) printf ("%c",205);
    printf ("%c\n",188);

return;
}

/////////////////////////////////////////// ///////////////////////////////////////////////////////
void instrucoes (void){
    
    int enter,infor;
    
    puts ("\n\n\n");
    
    printf ("                               ATEN%c%cO USU%cRIO\n\n",128,199,181);
    printf ("    PARA QUE O PROGRAMA SEJA VISUALIZADO PERFEITAMENTE EM SEU COMPUTADOR,\n");
    printf ("                      FA%cA O SEGUINTE PROCESSO:\n\n\n\n",128,210); 
    
    printf ("     1 - PRESSIONE AS TECLAS ALT + BARRA DE ESPA%cOS + P\n",128);  
    printf ("     2 - TAMANHO DO BUFFER DA JANELA \n");
    printf ("         LARGURA = 102 ALTURA = 300\n");
    printf ("     3 - LARGURA DA JANELA\n");
    printf ("         LARGURA = 102 ALTURA = 42\n");
    printf ("     4 - CLIQUE NO BOT%cO \"OK\"\n\n\n",199);
    printf("                             INFORMACOES ADICIONAIS\n\n");
    printf("            O PROGRAMA CONSEGUE MANIPULAR DE 0 A 999.999,99 REAIS\n");
    printf("            PARA QUE O PROGRAMA MANIPIULE AS STRINGS DE MANEIRA CORRETA\n");
    printf("            INSIRA SOMENTE NUMEROS SEM PONTO NEM VIRGULA!\n\n");
     printf ("\n\n       PARA QUE O PROGRAMA SEJA EXECUTADO PRESSIONE QUALQUER TECLA                     ");
                
                 
    
    enter = getchar();
    fflush(stdin);
    system ("cls");

return;
}
////////////////////////////////////////////////////////////////////////////////
short Unidade(long int Valor, char *A) {
int uni = Valor % DEZ;
  if (uni) {
       switch (uni) {
         case 1 : strcat(A," UM");     break;
	     case 2 : strcat(A," DOIS");   break;
	     case 3 : strcat(A," TRES");   break;
	     case 4 : strcat(A," QUATRO"); break;
	     case 5 : strcat(A," CINCO");  break;
	     case 6 : strcat(A," SEIS");   break;
	     case 7 : strcat(A," SETE");   break;
	     case 8 : strcat(A," OITO");   break;
	     case 9 : strcat(A," NOVE");   break;
	   } // switch
       return(1);
  }
 else return(0);
}
////////////////////////////////////////////////////////////////////////////////
short Dezena(long int Valor, char *A) {
int uni,    
    deze; 
  deze = (Valor/DEZ)%DEZ;
  if (!deze) return(0);
  else
   if ( deze == 1) {
	  uni = Valor % DEZ;
	  switch (uni) {
	    case 0 : strcat(A," DEZ");       break;
	    case 1 : strcat(A," ONZE");      break;
	    case 2 : strcat(A," DOZE");      break;
	    case 3 : strcat(A," TREZE");     break;
	    case 4 : strcat(A," CATORZE");   break;
	    case 5 : strcat(A," QUINZE");    break;
	    case 6 : strcat(A," DEZESSEIS"); break;
	    case 7 : strcat(A," DEZESSETE"); break;
	    case 8 : strcat(A," DEZOITO");   break;
	    case 9 : strcat(A," DEZENOVE");  break;
      } 
	  return(1);
    } 
   else {
       switch (deze) {
	     case 2 : strcat(A," VINTE");     break;
	     case 3 : strcat(A," TRINTA");    break;
	     case 4 : strcat(A," QUARENTA");  break;
	     case 5 : strcat(A," CINQUENTA"); break;
	     case 6 : strcat(A," SESSENTA");  break;
	     case 7 : strcat(A," SETENTA");   break;
	     case 8 : strcat(A," OITENTA");   break;
	     case 9 : strcat(A," NOVENTA");   break;
	   } 
       return(2);
   } 
} 
////////////////////////////////////////////////////////////////////////////////
short Centena(long int Valor, char *A) {
int cent = (Valor/100) % DEZ;
  if (cent) {
       switch (cent) {
         case 1 : strcat(A," CENTO E");        return 1;
	     case 2 : strcat(A," DUZENTOS E");     return 2;
	     case 3 : strcat(A," TREZENTOS E");    return 3;
	     case 4 : strcat(A," QUATROCENTOS E"); return 4;
	     case 5 : strcat(A," QUINHENTOS E");   return 5;
	     case 6 : strcat(A," SEISCENTOS E");   return 6;
	     case 7 : strcat(A," SETECENTOS E");   return 7;
	     case 8 : strcat(A," OITOCENTOS E");   return 8;
	     case 9 : strcat(A," NOVECENTOS E");   return 9;
	   }
       return 0;
}
}
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

short Centavos(long int Valor, char *Str_cent) {
 Cadeia str_uni = "",  
 
	    str_dez = "";    
 
int m;
 strcpy(Str_cent,NULA);
 strcpy(str_uni,NULA);
 strcpy(str_dez,NULA);
 m=Dezena(Valor, str_dez);
 if ( !m )     
    {
      if ( Unidade(Valor, str_uni) ){
	     if ( Valor%10 == 1){ strcat(str_uni," CENTAVO");}
	     else strcat(str_uni," CENTAVOS");

      strcpy(Str_cent,str_uni);
	  return 1;}
    }
 else   
   {
	 strcpy(str_uni,NULA);
	 if ( Unidade(Valor, str_uni) == 0 ){
	     strcat(str_uni," CENTAVOS");
	     strcat(str_dez , str_uni);
	     strcpy(Str_cent,str_dez);
	     return 1;
		} 
	 else {
	    if ((Valor/10 != 1)&&(m==2)) {
		   strcat(str_dez, " E");
		   strcat(str_dez, str_uni);
		}
        strcat(str_dez," CENTAVOS");
	    strcpy(Str_cent,str_dez);
	    return 1;
     }
  }
return 0;
} 
////////////////////////////////////////////////////////////////////////////////
short Reais(long int Valor, char *Str_cent) {
 Cadeia str_uni = "",  
	    str_dez = "",    
	    str_cen = "";   
int m=0, n=0;
 strcpy(Str_cent,NULA);
 strcpy(str_uni,NULA);
 strcpy(str_dez,NULA);
 strcpy(str_cen,NULA);
 if((Valor/DEZ)%DEZ){ n=Centena(Valor, str_cen); }
 m=Dezena(Valor, str_dez);
 if((!n)&&((Valor%DEZ)%DEZ==0)){ CentenaR(Valor, str_cen); strcpy(Str_cent, str_cen); 
 return 1;}
 else if ( !m )      
    {
      if ( Unidade(Valor, str_uni) ){
	     if ( Valor%10 == 1){ strcat(str_uni," REAL");}
	     else strcat(str_uni," REAIS");

      strcpy(Str_cent,str_uni);}
      return 1;
    }
 else   
   {
	 strcpy(str_uni,NULA);
	 if ( Unidade(Valor, str_uni) == 0 ){
	     strcat(str_uni," REAIS");
	     strcat(str_dez , str_uni);
	     strcat(str_cen,str_dez);
	     strcpy(Str_cent,str_cen);
	     return 1;
		} 
	 else {
	    if ((Valor/10 != 1)&&(m==2)) {
		   strcat(str_dez, " E");
		   strcat(str_dez, str_uni);
		}
        strcat(str_dez," REAIS");
        strcat(str_cen,str_dez);
	    strcpy(Str_cent,str_cen);
	    return 1;
     }
  }
return 0;
} 
////////////////////////////////////////////////////////////////////////////////
short Milhar(long int Valor, char *Str_cent){
 Cadeia str_uni = "",    
	    str_dez = "",   
	    str_cen = "";    
int m=0, n=0;
 strcpy(Str_cent,NULA);
 strcpy(str_uni,NULA);
 strcpy(str_dez,NULA);
 strcpy(str_cen,NULA);
 if((Valor/DEZ)%DEZ){ n=Centena(Valor, str_cen); }
 m=Dezena(Valor, str_dez);
 if((!n)&&((Valor%DEZ)%DEZ==0)){ CentenaM(Valor, str_cen); strcpy(Str_cent, str_cen); 
 return 1;}
 else if ( !m )     
    {
      if ( Unidade(Valor, str_uni) ){
	     if ( Valor%10 == 1){ strcat(str_uni," MIL");}
	     else strcat(str_uni," MIL");

      strcpy(Str_cent,str_uni);}
      return 1;
    }
 else   
   {
	 strcpy(str_uni,NULA);
	 if ( Unidade(Valor, str_uni) == 0 ){
	     strcat(str_uni," MIL");
	     strcat(str_dez , str_uni);
	     strcat(str_cen,str_dez);
	     strcpy(Str_cent,str_cen);
	     return 1;
		} 
	 else {
	    if ((Valor/10 != 1)&&(m==2)) {
		   strcat(str_dez, " E");
		   strcat(str_dez, str_uni);
		}
        strcat(str_dez," MIL");
        strcat(str_cen,str_dez);
	    strcpy(Str_cent,str_cen);
	    return 1;
     }
  }
return 0;
} 
////////////////////////////////////////////////////////////////////////////////
short CentenaR(long int Valor, char *A) {
int cent = (Valor/100) % DEZ;
  if (cent) {
       switch (cent) {
         case 1 : strcat(A," CEM REAIS");          return 1;
	     case 2 : strcat(A," DUZENTOS REAIS");     return 1;
	     case 3 : strcat(A," TREZENTOS REAIS");    return 1;
	     case 4 : strcat(A," QUATROCENTOS REAIS"); return 1;
	     case 5 : strcat(A," QUINHENTOS REAIS");   return 1;
	     case 6 : strcat(A," SEISCENTOS REAIS");   return 1;
	     case 7 : strcat(A," SETECENTOS REAIS");   return 1;
	     case 8 : strcat(A," OITOCENTOS REAIS");   return 1;
	     case 9 : strcat(A," NOVECENTOS REAIS");   return 1;
	   }
       return 0;
}
}
////////////////////////////////////////////////////////////////////////////////
short CentenaM(long int Valor, char *A) {
int cent = (Valor/100) % DEZ;
  if (cent) {
       switch (cent) {
         case 1 : strcat(A," CEM MIL");          return 1;
	     case 2 : strcat(A," DUZENTOS MIL");     return 1;
	     case 3 : strcat(A," TREZENTOS MIL");    return 1;
	     case 4 : strcat(A," QUATROCENTOS MIL"); return 1;
	     case 5 : strcat(A," QUINHENTOS MIL");   return 1;
	     case 6 : strcat(A," SEISCENTOS MIL");   return 1;
	     case 7 : strcat(A," SETECENTOS MIL");   return 1;
	     case 8 : strcat(A," OITOCENTOS MIL");   return 1;
	     case 9 : strcat(A," NOVECENTOS MIL");   return 1;
	   }
       return 0;
}
}


//////////////////////////////////////////////////////////////////////////////////////////
void cheque (){
    
    char mes[4], dia[3], ano[5], benef[72];
    int a, i, num, comp, banco, agencia, c1, c2, conta, numcheque;
    long int Valor;
    
    
    time_t t;    
    srand((unsigned) time(&t));
    
    
    printf (" %c",250);
    for(i=0;i<98;i++) printf ("%c",250);
    printf ("%c\n",250);    
    

    printf (" %c",250);
    printf ("                                                                                                  ");
    printf ("%c\n",250);
   
    printf (" %c",250);
    printf ("  %cCOMP   %cBANCO   %cAGENCIA   %cC1  %cCONTA           %cC2  %c    %cCHQUE No.   %cC3  %cR$               ",179,179,179,179,179,179,179,179,179,179);
    printf ("%c\n",250);
    
   
    printf (" %c",250);
    printf ("  %c       %c        %c          %c    %c                %c    %c    %c            %c    %c                 ",179,179,179,179,179,179,179,179,179,179);
    printf ("%c\n",250);
    
    
    printf (" %c",250);
    printf ("  %c       %c        %c          %c    %c                %c    %c    %c            %c    %c                 ",179,179,179,179,179,179,179,179,179,179);
    printf ("%c\n",250);
    
   
    printf (" %c",250);
    printf ("                                                                                                  ");
    printf ("%c\n",250);
    
 
    printf (" %c",250);
    printf ("                                                                                                  ");
    printf ("%c\n",250);  
       
  
    printf (" %c",250); printf ("  Pago por este cheque");
    printf ("                                                                          ");
    printf ("  %c\n",250); 
    
 
    printf (" %c",250); printf ("  a quantia de"); printf ("         ");
    for(i=0;i<73;i++) printf ("_");
    printf ("  %c\n",250);
    
    
    printf (" %c",250);
    printf ("                                                                                                  ");
    printf ("%c\n",250);
    
    
    printf (" %c",250);
    printf ("                                                                                                  ");
    printf ("%c\n",250);  
    

    printf (" %c",250);printf ("  ");
    for(i=0;i<94;i++) printf ("_");
    printf ("  %c\n",250);
    
   
    printf (" %c",250);
    printf ("                                                                                                  ");
    printf ("%c\n",250);  
    
  
    printf (" %c",250);
    printf ("                                                                                                  ");
    printf ("%c\n",250);
    
    
    printf (" %c",250);printf ("  a ");
    for(i=0;i<77;i++) printf ("_"); printf (" ou a sua ordem");
    printf ("  %c\n",250);
    
 
    printf (" %c",250);
    printf ("                                                                                                  ");
    printf ("%c\n",250);  
         
    strcpy(mes, "");
    strcpy(dia, "");
    strcpy(ano, "");
    strncat(mes, __DATE__ , 3);
    strncat(dia, __DATE__ +4, 2);
    strncat(ano, __DATE__ +7, 4);  
    
    a = verifica_mes(mes); 
         
    
    printf (" %c",250);printf ("                                              ");
    printf ("PRESIDENTE PRUDENTE, %s          %s         %s   ", dia, mes, ano);
    printf ("%c\n",250);
    
    
    printf (" %c",250);printf ("                                              ");
        for(i=0;i<42;i++){        
             printf ("_");
             if (i == 22) printf (" de ");
             if (i == 35) printf (" de ");
        }
    printf ("  %c\n",250);
    
    
    printf (" %c",250);
    printf ("       ========================                                                                   ");
    printf ("%c\n",250);
    
    
    printf (" %c",250);printf ("            BANCO BCCUNESP                    ");
    printf ("            PARANGARICO TIRIMICO ARO                  ");
    printf ("%c\n",250);   
    
    
    printf (" %c",250);printf ("       ========================               ");
        for(i=0;i<50;i++) printf ("_");
    printf ("  %c\n",250);
    
    
    printf (" %c",250);
    printf ("                                                                                                  ");
    printf ("%c\n",250);
    
    printf (" %c",250);printf ("                                              ");
    printf ("PARANGARICO T. ARO          CLIENTE DESDE:  ");
    printf ("%c\n",250);
    
  
    printf (" %c",250);printf ("                                              ");
    printf ("CPF : 153.286.575-712                1900           ");
    printf ("%c\n",250);  
    
    printf (" %c",250);
    printf ("                                                                                                  ");
    printf ("%c\n",250);
    

    printf (" %c",250);
    for(i=0;i<98;i++) printf ("%c",250);
    printf ("%c\n",250);
    
      
    do{  
        comp= rand()%201;
        banco = rand()%1000;
        agencia = rand()%1000;
        c1 = rand()%10;
        c2 = rand()%10;
        conta = rand(); 
        numcheque = rand();   
    }while ((comp==0) || (banco==0) || (agencia==0) || (c1==0) || (conta ==0) || (numcheque==0));   
     
     gotoxy(85,11); Leitura_Valor(&Valor);
     fflush(stdin);   
     
     
     gotoxy(5,11);printf("%d",comp);
     gotoxy(13,11);printf("%d",banco);
     gotoxy(22,11);printf("%d",agencia);
     gotoxy(33,11);printf("%d",c1);
     gotoxy(38,11);printf("%d",conta);
     gotoxy(55,11);printf("%d",c2);
     gotoxy(65,11);printf("%d",numcheque);     
     gotoxy(24,15);imprime_cheque(Valor);
     
       switch (a) {    
           case 1: {gotoxy(77,24);printf ("JANEIRO");}break;           
           case 2: {gotoxy(77,24);printf ("FEVEREIRO");}break;           
           case 3: {gotoxy(77,24);printf ("MAR%cO",128);}break;           
           case 4: {gotoxy(77,24);printf ("ABRIL");}break;           
           case 5: {gotoxy(77,24);printf ("MAIO");}break;           
           case 6: {gotoxy(77,24);printf ("JUNHO");}break;           
           case 7: {gotoxy(77,24);printf ("JULHO");}break;           
           case 8: {gotoxy(77,24);printf ("AGOSTO");}break;           
           case 9: {gotoxy(77,24);printf ("SETEMBRO");}break;           
           case 10:{gotoxy(77,24);printf ("OUTUBRO");}break;           
           case 11:{gotoxy(77,24);printf ("NOVEMBRO");}break;           
           case 12:{gotoxy(77,24);printf ("DEZEMBRO");}break;    
    }
	 gotoxy(8,21);fgets(benef,72,stdin);
     fflush(stdin);
     gotoxy(8,21);limpalinha();
     gotoxy(8,21);printf("%s",benef);     
     gotoxy(0,35);

return;
}

///////////////////////////////////////////////////////////////////////////////////////////////
void imprime (void){
     int op;
     
     do{
     printf ("                                      DESEJA IMPRIMIR? <S,N>: ");      
     op = getchar();
     op = toupper(op);
     }while ((op != 'S') && (op != 'N'));
     
     if (op=='S') printf("\n                                     IMPRESSORA N%cO DETECTADA!!!",199);     
     if (op=='N')return;
    
     puts("\n");
     printf("                            ");system("pause");
return;
}

//////////////////////////////////////////////////////////////////////////////////////////////
void gotoxy(int x, int y)
{
    HANDLE hOut;
    int i;
    COORD Position;
    
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    
    Position.X = x;
    Position.Y = y;
    SetConsoleCursorPosition(hOut,Position);
}

////////////////////////////////////////////////////////////////////////////////////////
void limpalinha (void){
     printf("                                                                                            ");
return;
}

//////////////////////////////////////////////////////////////////////////////////////
int verifica_mes(char *A){
    
    int i=0;
    

    if ( *(A+i) == 'J'){
       i++;
       if ( *(A+i) == 'a'){
            i=0;
            return 1;
       }
       else if ( *(A+i) == 'u'){
            i++;
            if (*(A+i) == 'n'){
                i=0;
                return 6;
            }
            else if (*(A+i) == 'l'){
                i=0;
                return 7;
            }            
       }    
    }
    
  
    else if ( *(A+i) == 'F')return 2;
    

    else if ( *(A+i) == 'M'){       
       i=i+2;
       if ( *(A+i) == 'r'){
            i=0;
            return 3;
       }
       else if ( *(A+i) == 'y'){
            i=0;
            return 5;
       }
    }
    

    else if ( *(A+i) == 'A'){
       i++;
       if ( *(A+i) == 'p'){
            i=0;
            return 4;
       }
       else if ( *(A+i) == 'u'){
            i=0;
            return 8;
       }    
    }
    
    
    else if ( *(A+i) == 'S')return 9;
    
  
    else if ( *(A+i) == 'O')return 10;
    
    
    else if ( *(A+i) == 'N')return 11;
    
  
    else if ( *(A+i) == 'D')return 12;     
}
////////////////////////////////////////////////////////////////////////////////
void imprime_cheque(long int value){
	char str_cent[200], str_real[300], str_milh[300], tot[800];
	int i=0, tam1, tam2, tam3, tamt, n1, n2, n3;
 strcpy(tot,NULA);
 n1=Centavos(value,str_cent);
 value/=100;
 n2=Reais(value,str_real);
 value/=1000;
 n3=Milhar(value,str_milh);
 tam1=strlen(str_milh);
 tam2=strlen(str_real);
 tam3=strlen(str_cent);
 if((tam1+tam2+tam3)<=73){
 for(i=0;i<tam1;i++){ printf("%c", *(str_milh+i)); }
 for(i=0;i<tam2;i++){ printf("%c", *(str_real+i)); }
 if(n1){ printf(" E"); }
 for(i=0;i<tam3;i++){ printf("%c", *(str_cent+i)); }}
 else{
 	  tamt=tam1+tam2+tam3;
 	  strcat(tot,str_milh);
 	  strcat(tot,str_real);
 	  if(n1){ strcat(tot," E"); }
 	  strcat(tot,str_cent);
 	  for(i=0;i<73;i++){ printf("%c", *(tot+i));}
 	  gotoxy(4,18);
 	  for(i=73;i<=tamt+2;i++){ printf("%c", *(tot+i)); }
 	  }
return;
}

void Leitura_Valor(long int *Valor) {
 do
  {
    scanf("%ld",Valor);
  }
 while (*Valor < 1 || *Valor > 99999999);
 return;
} 
////////////////////////////////////////////////////////////////////////////////
