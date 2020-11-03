/**************************************************************/
/*     EDITOR DE TEXTO - TRABALHO DE ESTRUTURA DE DADOS 1     */
/*     Gustavo da Mota Ramos e  Fernando Matias de Oliveira   */
/*     Professor: Ronaldo Celso Messias Correia               */
/*     Data de entrega: 03/07/2011                            */
/**************************************************************/

#include "main.h"
#include "editor.h"



int main(void)
{
  Tno *primlinha, *l_atual;
  Tfila *f, *copia;
  Teditor *editor;

  Apresentacao();

  
  Inicializa (&primlinha, &l_atual);
  Inicializa_Editor(&editor);

  //Inicializa_Fila(&f);
  //Inicializa_Fila(&copia);
  
  system("color f1");
  
  
  Leitura(&l_atual, &primlinha, &f, &copia, &editor);


  return 0;
}
