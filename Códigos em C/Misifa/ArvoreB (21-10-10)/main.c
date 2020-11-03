/*******************************************************************************
  Estrutura de Dados: Árvore B
  Autor: Luiz Paulo Rabachini
  Criação: 19 de outubro de 2010
  Atualização: 19 de outubro de 2010
  Versão: 0.1
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

int main(void)
{
  ArvoreB ArvB;
  
  IniciarArvoreB(&ArvB);
  Menu(&ArvB.raiz);
  
  //system("pause");	
  return 0;
}
