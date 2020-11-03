#include <stdio.h>
#include <stdlib.h>

#include "stringdinamica.h"

// Inicializa o texto
void Start(Text *T)
{
 T->prim=NULL;
 T->ult=NULL;
 return;
}
//------------------------------------------------------------------------------

// Finaliza o texto
short ClearText(Text *T)
{
 No *c, *b;
 
 if (!T->prim) return 0;
 for (c=T->prim; c; c=b){
     b=c->prox;
     free(c);    
 }
 Start(T);
 return 1;
}
//------------------------------------------------------------------------------

// Imprime o texto
short PrintText(Text *T)
{
 No *c;
 
 if (!T->prim) return 0;
 for (c=T->prim; c; c=c->prox)
     printf("%c",c->info);    
 return 1;
}
//------------------------------------------------------------------------------

// Obtém o tamanho do texto
int SizeText(Text *T)
{
 int cont;
 No *c;
 
 if (!T->prim) return 0;
 for (c=T->prim, cont=0; c; cont++, c=c->prox);    
 return cont;
}
//------------------------------------------------------------------------------

// Insere caracter
//------------------------------------------------------------------------------

// Copia string
short CopyText(Text *T1, Text *T2)
{
 No *c;
 
 ClearText(T2);
 for (c=T1->prim; c; c=c->prox){
     //
 }
}
//------------------------------------------------------------------------------

// Concatenar string
//------------------------------------------------------------------------------

// Remove da string
//------------------------------------------------------------------------------

// Concatenar string no meio
//------------------------------------------------------------------------------

// Comparação de tamanho das strings
//------------------------------------------------------------------------------

// Compara a igualdade entre strings
//------------------------------------------------------------------------------

// Busca string dentro da string
//------------------------------------------------------------------------------
