/*
@copyright Luiz Paulo Rabachini @file: main.c
Release: 1.8 - Updated: 15/04/2010
---
Resume: Fun��o main (Lista Encadeada din�mica. Projeto: Lista_DE)
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista_de.h"

int main(int argc, char *argv[])
{
    Lista L;
    StartLista(&L);
    Menu(&L);	
    return (0);
}
