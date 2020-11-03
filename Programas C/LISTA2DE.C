// favor revisar o codigo.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NEXT(p) (p)->next
#define LAST(p) (p)->last
#define INFO(p) (p)->info
#define MAX     10

typedef enum res {
	      FAILURE = 0,
	      SUCCESS = 1
	  } RES;

typedef struct no *No;
typedef struct no {
	  int info;
	  No  last, next;
	 }NO;


// Variaveis globais
//==============================
No ini_lista = NULL, ult_lista = NULL;      // Criacao de uma Lista vazia

//==============================


//Prototipos de Funcoes
//==============================

RES 	Insere_Novo_Elemento_LDE(int Info);
RES 	Insere_Novo_Elemento_LDEO(int Info);
void 	Remover_Elemento_LDE(int Info);
void 	Transverse_LDE_Ini_Fim(void);
void 	Transverse_LDE_Fim_Ini(void);
RES 	Remover_LDE(void);
//==============================


RES Insere_Novo_Elemento_LDE(int Info) {
No  p = NULL;

   p = (No)malloc(sizeof(NO));
   if ( p == NULL ) return(FAILURE);
   else
    {
     LAST(p) = NEXT(p) = NULL; // inicializando componentes
     p->info = Info;

     if (ini_lista == NULL) ini_lista = p;  // primeiro elemento da lista
     else { NEXT(ult_lista) = p; LAST(p) = ult_lista; }

     ult_lista = p;
    }
   return(SUCCESS);
} // Insere_Novo_Elemento_LDE


// Observem que na Aula anterior eu forneci códigos mais genéricos
// para manipular Listas arbitrarias. Logo, os códigos aqui podem ser alterados
// para inserir elementos em LDE quaisquer.

RES Insere_Novo_Elemento_LDEO(int Info) {
No  p = NULL;
No  q = NULL;

   p = (No)malloc(sizeof(NO));
   if ( p == NULL ) return(FAILURE);
   else {
     LAST(p) = NEXT(p) = NULL; // inicializando componentes
     p->info = Info;

     if (ini_lista == NULL) ini_lista = ult_lista = p;// CASO 01: primeiro elemento da lista
     else {
	   if (Info <= ini_lista->info ) {    // CASO 02: inserir antes do inicio
	     NEXT(p) = ini_lista;
	     LAST(ini_lista) = p;
	     ini_lista = p;
	   } // if
	   else if (Info >= ult_lista->info) {  // CASO 03: inserir depois do final
		      NEXT(ult_lista) = p;
		      LAST(p) = ult_lista;
		      ult_lista = p;
            }
	        else     // inserir em posicao intermediaria
		    for (q = ini_lista; q != ult_lista; q=NEXT(q)) {
		       if (Info <= (NEXT(q))->info ) {
			     NEXT(p) = NEXT(q);
			     LAST(p) = q;
			     LAST(NEXT(q)) = p;
			     NEXT(q) = p;
			     break;
               }  // if
		    } // for
       }  // else Lista nao vazia
    }  // 1º else
   return(SUCCESS);
} // Insere_Novo_Elemento_LDEO


void Remover_Elemento_LDE(int Info) {
No p = NULL, q = NULL;

if (ini_lista != NULL)
  if ( ini_lista->info == Info )  // remover primeiro elemento
    {
     p = ini_lista;
     ini_lista = NEXT(p);
     LAST(NEXT(p)) = NULL;
     NEXT(p) = NULL;
     free(p);
    }
  else if ( ult_lista->info == Info )  // remover ultimo elemento
	  {
	   p = ult_lista;
	   ult_lista = LAST(p);
	   NEXT(ult_lista) = NULL;
	   LAST(p) = NULL;
	   free(p);
	  }
      else // remover elemento intermediario
	{
	  for (q=NEXT(ini_lista); q != ult_lista; q = NEXT(q))
	      {
		if ( q->info == Info )
		   {
		    NEXT(LAST(q)) = NEXT(q);
		    LAST(NEXT(q)) = LAST(q);
		    NEXT(q)=LAST(q)=NULL;
		    free(p);break;
		   }
	      }
	}
  return;
} // void Remover_Elemento_LDE

void Transverse_LDE_Ini_Fim() {
No p = ini_lista;

  if (ini_lista)
   for(; p != NULL; p=NEXT(p))
     printf(" %4d \n ", p->info);
}  // Transverse_LDE_Ini_Fim

void Transverse_LDE_Fim_Ini(){
No p = ult_lista;

 if (ini_lista)
   for(; p != NULL; p=LAST(p))
     printf("%4d \n", p->info);
}

RES Remover_LDE(){
No p = NULL;

 printf("\n Removendo elementos -->");

 if (ini_lista != NULL)
   {
    p = ult_lista;
    while (p != NULL )
     {
      ult_lista = LAST(p);
      NEXT(ult_lista) = LAST(p) = NULL;
      free(p);
      p = ult_lista;
     }
   }
  ini_lista = ult_lista = NULL;
  return(SUCCESS);
}

int main(void) {
int  i;
time_t t;

 
 ini_lista = ult_lista = NULL;      // Criacao de uma Lista vazia 
 srand((unsigned) time(&t));
 for (i=0;i<MAX;i++) {
  t = rand();
 // printf("%d,  ", t);
  Insere_Novo_Elemento_LDEO(t);
  //Insere_Novo_Elemento_LDE(t); 
}
 printf("\n\n Inicio--> Final\n\n");
 Transverse_LDE_Ini_Fim();
 system("PAUSE");

// printf("\n- --> Elemento a remover --> ");
// scanf("%d",&t);
// Remover_Elemento_LDE(t);
 printf("\n\n");
//  Transverse_LDE_Ini_Fim();
 
 printf("\n\n Final --> Inicio\n\n");
 Transverse_LDE_Fim_Ini();
 system("PAUSE");
// if ( Remover_LDE() )
//   printf("\n Lista removida com sucesso!!!");
  printf("\n\n");

printf("\n\n\n\n");
system("PAUSE");
return(0);
}

// Depois voces poderao testar outras funcoes
// Lembrem-se dos protótipos passados na Aula anterior.
// Todos eles podem ser reescritos usando uma LDE.
// Bom Trabalho!!!!
