/*******************************************************************************
  Estrutura de Dados: �rvore B
  Autor: Luiz Paulo Rabachini
  Cria��o: 19 de outubro de 2010
  Atualiza��o: 19 de outubro de 2010
  Vers�o: 0.1
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
