#include <stdio.h>
#include <stdlib.h>
#include "tadexparsa.h"


int main(int argc, char *argv[])
{
Tmatriz matriz;

IniciarMatriz(&matriz);
InsereMatriz(&matriz,1,1,4);
InsereMatriz(&matriz,1,2,5);
ImprimeMatriz(&matriz);


  return 0;
}
