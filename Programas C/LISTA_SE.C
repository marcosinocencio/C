#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NEXT(p) (p)->next
#define MAX     10

typedef enum res {
	      FAILURE = 0,
	      SUCCESS = 1
	  } RES;

typedef struct no *No;
typedef struct no {
	  int info;
	  No  next;
	 }NO;

RES Insere_Novo_Elemento_Lista(No *Ll, int Info);
RES Remove_Lista_Inteira(No *L1);
int Conta_Numero_Elementos_Lista(No *Ll);
No Ultimo_Elemento_Lista(No *L1);
No Concatenando_Duas_Listas1(No *L1, No *L2);
void Concatenando_Duas_Listas2(No *L, No *L1, No *L2);


RES Remove_Lista_Inteira(No *L1) {
No p = NULL;

 while (*L1 != NULL) {
    p = *L1;
    *L1 = p->next;
    
    NEXT(p) = NULL;
    free(p);
   }
   return(SUCCESS);

} // Remove_Lista_Inteira


RES Insere_Novo_Elemento_Lista(No *Ll, int Info) {
No  p = NULL;

   p = (No)malloc(sizeof(NO));
   if ( p == NULL ){
      printf("Memoria esgotada!!!");
      exit(1);
   }


  printf("\n\n %p", p);

   NEXT(p) = NULL; // preenchendo os campos do no
   p->info = Info;

   if (*Ll == NULL) *Ll = p;
   else { NEXT(p) = *Ll; *Ll = p; } // insercao antes do primeiro

   return(SUCCESS);
} // Insere_Novo_Elemento_Lista


int Conta_Numero_Elementos_Lista(No *Ll) {
int cont = 0;
No p;

  for (p=*Ll; p != NULL; p=NEXT(p)) cont++;
  return(cont);
} // Conta_Numero_Elementos_Lista




No Ultimo_Elemento_Lista(No *L1) {
No p;

 for (p=*L1; p != NULL; p=p->next)
     if (p->next == NULL ) return(p);
} // Ultimo_Elemento_Lista

No Concatenando_Duas_Listas1(No *L1, No *L2) {
No p = NULL;

   p = Ultimo_Elemento_Lista(L1);
   printf("\n (CONCATENA)Ultimo elemento LISTA1 --> %d ", (p)->info);
   p->next = *L2;
   return(*L1);

} // Concatenando_Duas_Listas

void Concatenando_Duas_Listas2(No *L, No *L1, No *L2) {

No p = NULL;

   p = Ultimo_Elemento_Lista(L1);
   printf("\n (CONCATENA)Ultimo elemento LISTA1 --> %d ", (p)->info);
   p->next = *L2;
   *L = *L1;
   return;

} // Concatenando_Duas_Listas


void Cria_Nova_Lista(No *L, int Num) {

int i = 0;
time_t t;

 srand((unsigned) time(&t));
 
 for (;i<Num;i++) {	// gerando MAX numeros no intervalo [0,100]
   t = rand();
   printf("\n- %d --> %d   ",i, t);
   Insere_Novo_Elemento_Lista(L,t);

 }


}    // Cria_Nova_Lista



int main(void) {
int cont = 0, i, dd  = 0;
No p = NULL, q = NULL;
No Lista = NULL;             // Criacao de uma Lista vazia
No Par = NULL, Impar = NULL; // Criacao de duas listas vazias

No Lista1, Lista2 = NULL, Lista3 = NULL;

  
  
 Cria_Nova_Lista(&Lista,3);
 
 dd = Conta_Numero_Elementos_Lista(&Lista);
  printf("\n\n -->%d\n\n", dd);


  //Cria_Nova_Lista(&Lista1,10);


   for (p=Lista; p != NULL; p=p->next)     // passeando pela Lista
    if ( (p->info)%2 == 0 )
       Insere_Novo_Elemento_Lista(&Par,p->info);
    else Insere_Novo_Elemento_Lista(&Impar,p->info);

  for (p=Par; p!=NULL; p=p->next)                   // transverse na Lista de pares
    printf("\n --> %d   ",p->info);
 printf("\n\n #ElementosPar-->%d",Conta_Numero_Elementos_Lista(&Par));

 printf("\n\n");
 for (p=Impar; p!=NULL; p=p->next)                                    // transverse na Lista de impares
    printf("\n --> %d   ",p->info);
 printf("\n\n #ElementosPar-->%d",Conta_Numero_Elementos_Lista(&Impar));


 Remove_Lista_Inteira(&Par);
 printf("\n\n #ElementosPar-->%d",Conta_Numero_Elementos_Lista(&Par));


 Remove_Lista_Inteira(&Impar);
 printf("\n\n #ElementosPar-->%d",Conta_Numero_Elementos_Lista(&Impar));


  for (p=Lista1; p!=NULL; p=p->next)                   // transverse na Lista de pares
    printf("\n --> %d   ",p->info);

 //Lista1 = Concatenando_Duas_Listas1(&Par, &Impar);
// Concatenando_Duas_Listas2(&Lista1, &Par, &Impar);


 //Impar = NULL;
 //printf("\n\n <<< Listas Concatenadas >>>");
// for (p=Lista1; p!=NULL; p=p->next)
 //   printf("\n --> %d   ",p->info);



 // Percorrendo os elementos da lista

/* for (p=Lista; p != NULL; p=p->next)
    printf("\n --> %d   ",p->info);
 getch();
  Remove_Lista_Inteira(&Lista);
  printf("\n\n -->%d",Conta_Numero_Elementos_Lista(&Lista));
  printf("\n\n -->%d",Conta_Numero_Elementos_Lista(&Lista));
  p = Ultimo_Elemento_Lista(&Lista);
  printf("\n Ultimo elemento da Lista --> %d   ",p->info);

// Percorrendo os elementos da lista dos pares e contando o numero de elementos


 getch();

// Percorrendo os elementos da lista dos pares e contando o numero de elementos
 for (p=Impar; p!=NULL; p=p->next)
    printf("\n --> %d   ",p->info);
 printf("\n\n #ElementosImpar-->%d",Conta_Numero_Elementos_Lista(&Impar));

 p = Ultimo_Elemento_Lista(&Par);
 printf("\n Ultimo elemento da Lista --> %d   ",p->info);

// p = Ultimo_Elemento_Lista(&Impar);
// printf("\n Ultimo elemento da Lista --> %d   ",p->info);

 getch();
*/

  printf("\n\n\n\n");
system("PAUSE");
return(0);
}
