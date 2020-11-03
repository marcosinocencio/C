#include "matriz_esparca.h"

// Função de Menu --------------------------------------------------------------
void Menu(Matriz *M)
{
 int l = 0, op = 0, info = 0, saida = 0, k = 0;
 PosCel pos;
 char cont;
 
 do{
    pos.i = pos.j = 0;
    saida = 0;
    system("cls");
    printf(":: Matriz Esparca v1.9 Beta ::\n\n");
    printf("-> Selecione uma opcao\n\n");
    printf("[1] Inserir elemento\n");
    printf("[2] Remover elemento\n");
    printf("[3] Buscar elemento por posicao\n");
    printf("[4] Somar linha\n");
    printf("[5] Somar coluna\n");
    printf("[6] Somar diagonal principal\n");
    printf("[7] Somar diagonal secundaria\n");
    //---
    printf("[8] Multiplicar linha por escalar\n");
    printf("[9] Multiplicar coluna por escalar\n");
    printf("[10] Permutar linhas\n");
    printf("[11] Permutar colunas\n");
    printf("[12] Imprimir matriz\n");
    printf("[0] Sair\n\n");
    printf("Opcao: ");
    scanf("%d", &op);
    switch (op){
           case 1: system("cls");
                   printf("-> Definir posicao de insercao\n\n");
                   fflush(stdin);
                   printf("Linha: "); scanf("%d", &pos.i);
                   printf("Coluna: "); scanf("%d", &pos.j);
                   printf("Valor: "); scanf("%d", &info);
                   if(Inserir_No(&(*M), info, pos));
                   else printf("Falha durante operacao");
           break;
           case 2: system("cls");
                   printf("-> Definir posicao de remocao\n\n");
                   fflush(stdin);
                   printf("Linha: "); scanf("%d", &pos.i);
                   printf("Coluna: "); scanf("%d", &pos.j);
                   if(Remover_No(&(*M), pos));
                   else printf("Falha durante operacao");
           break;
           case 3: system("cls");
                   printf("-> Definir posicao de busca\n\n");
                   fflush(stdin);
                   printf("Linha: "); scanf("%d", &pos.i);
                   printf("Coluna: "); scanf("%d", &pos.j);
                   if (Buscar_No(&(*M), pos, &saida))
                      printf("Elemento: %d | Posicao: i = %d. j = %d", saida, pos.i, pos.j);
                   else printf("Elemento nao encontrado");
           break;
           case 4: system("cls");
                   printf("-> Definir linha a ser somada\n");
                   printf("Linha: "); scanf("%d", &pos.i);
                   pos.j = 0;
                   Somar_Matriz(M, pos, 1, &saida);
                   printf("Soma da linha %d = %d", pos.i, saida);
           break;
           case 5: system("cls");
                   printf("-> Definir coluna a ser somada\n");
                   printf("Coluna: "); scanf("%d", &pos.j);
                   pos.i = 0;
                   Somar_Matriz(M, pos, 2, &saida);
                   printf("Soma da linha %d = %d", pos.j, saida);
           break;
           case 6: system("cls");
                   printf("-> Soma diagonal principal\n");
                   Somar_Matriz(M, pos, 3, &saida);
                   printf("Soma = %d", saida);
           break;
           case 7: system("cls");
                   printf("-> Soma diagonal secundaria\n");
                   Somar_Matriz(M, pos, 4, &saida);
                   printf("Soma = %d", saida);
           break;
           case 8: system("cls");
                   printf("-> Definir linha a ser multiplicada\n");
                   printf("Linha: "); scanf("%d", &pos.i); pos.j = 0;
                   printf("Escalar: "); scanf("%d", &k);
                   Mult_LC_Matriz(&(*M), 2, pos, k); 
           break;
           case 9: system("cls");
                   printf("-> Definir coluna a ser multiplicada\n");
                   printf("Linha: "); scanf("%d", &pos.j); pos.i = 0;
                   printf("Escalar: "); scanf("%d", &k);
                   Mult_LC_Matriz(&(*M), 1, pos, k);
           break;
           case 10: system("cls");
                    printf("-> Definir linhas a aerem permutadas\n");
                    printf("Linha1: "); scanf("%d", &pos.i);
                    printf("Linha2: "); scanf("%d", &pos.j);
                    Perm_LC_Matriz(&(*M), 2, pos);
           break;
           case 11: system("cls");
                    printf("-> Definir colunas a aerem permutadas\n");
                    printf("Coluna1: "); scanf("%d", &pos.i);
                    printf("Coluna2: "); scanf("%d", &pos.j);
                    Perm_LC_Matriz(&(*M), 1, pos);
           break;
           case 12: Imprimir_Matriz(M);
           break;
           case 0: return;
           }
    printf("\nDeseja continuar? (s/n)");
    fflush(stdin);
    cont = getchar();
 }while((cont=='s')||(cont=='S'));
 return;
}

// Função de inicialização completa --------------------------------------------
void Iniciar_Matriz(Matriz *M)
{
 int a = 0;
 
 for (a = 0; a < OM; a++)
     M->Col[a].prim = M->Col[a].ult = NULL;
 for (a = 0; a < OM; a++)
     M->Lin[a].prim = M->Lin[a].ult = NULL;
 return;      
}

// Função para inserção --------------------------------------------------------
short Inserir_No(Matriz *M, int Info, PosCel Pos)
{
 int a = 0, i = 0, j = 0;
 No *novo_no = NULL;
 No *aux_no1 = NULL;
 No *aux_no2 = NULL;
 
 if ((!Pos.i)||(!Pos.j)) // Inserções em posições 0 serão descartadas.
    return 0;
 novo_no = (No*)malloc(sizeof(No));
 if (!novo_no)
    return 0;
 novo_no->prox_dir = NULL;
 novo_no->prox_inf = NULL;
 novo_no->Info = Info;
 novo_no->Pos = Pos;
 i = Pos.i - 1;
 j = Pos.j - 1;
 
 if (M->Col[j].prim == NULL){
    M->Col[j].prim = novo_no;
    M->Col[j].ult = novo_no;
 }
 else{
      if (novo_no->Pos.i < M->Col[j].prim->Pos.i){
         novo_no->prox_inf = M->Col[j].prim;
         M->Col[j].prim = novo_no;      
      }
      else if (novo_no->Pos.i > M->Col[j].ult->Pos.i){
              M->Col[j].ult->prox_inf = novo_no;
              M->Col[j].ult = novo_no;  
           }
           else for (aux_no1 = M->Col[j].prim, aux_no2 = aux_no1; aux_no1; aux_no2 = aux_no1, aux_no1 = aux_no1->prox_inf){
                    if (aux_no1->Pos.i > novo_no->Pos.i){
                       aux_no2->prox_inf = novo_no;
                       novo_no->prox_inf = aux_no1;
                    }
                    if (aux_no1->Pos.i == novo_no->Pos.i){
                       aux_no1->Info += novo_no->Info;
                       free(novo_no);
                    }
                }
 }
 if (M->Lin[i].prim == NULL){
    M->Lin[i].prim = novo_no;
    M->Lin[i].ult = novo_no;
 }
 
 else{
      if (novo_no->Pos.j < M->Lin[i].prim->Pos.j){
         novo_no->prox_dir = M->Lin[i].prim;
         M->Lin[i].prim = novo_no;      
      }
      else if (novo_no->Pos.j > M->Lin[i].ult->Pos.j){
              M->Lin[i].ult->prox_dir = novo_no;
              M->Lin[i].ult = novo_no;  
           }
           else for (aux_no1 = M->Lin[i].prim, aux_no2 = aux_no1; aux_no1; aux_no2 = aux_no1, aux_no1 = aux_no1->prox_dir){
                    if (aux_no1->Pos.j > novo_no->Pos.j){
                       aux_no2->prox_dir = novo_no;
                       novo_no->prox_dir = aux_no1;
                    }
                }
 }
 return 1; 
}
// Função para remoção ---------------------------------------------------------
short Remover_No(Matriz *M, PosCel Pos)
{
 int i = 0, j = 0;
 short vlrm = 0;
 No *no_aux1 = NULL;
 No *no_aux2 = NULL;
 No *no_aux3 = NULL;
 
 i = Pos.i - 1;
 j = Pos.j - 1;     
 if ((!M->Col[j].prim)||(!M->Lin[i].prim))
    return 0;
 for (no_aux1 = M->Col[j].prim, no_aux2 = no_aux1; no_aux1; no_aux2 = no_aux1, no_aux1 = no_aux1->prox_inf)
     if (no_aux1->Pos.i == Pos.i){
        if (no_aux1 == M->Col[j].prim)
           M->Col[j].prim = no_aux1->prox_inf;    
        else
            no_aux2->prox_inf = no_aux1->prox_inf;
        vlrm = 1;
        break;
     }
 for (no_aux2 = M->Lin[i].prim, no_aux3 = no_aux2; no_aux2; no_aux3 = no_aux2, no_aux2 = no_aux2->prox_dir)
     if (no_aux2->Pos.i == Pos.i){
        if (no_aux2 == M->Lin[i].prim)
           M->Lin[i].prim = no_aux2->prox_dir;
        else   
           no_aux3->prox_inf = no_aux2->prox_dir;
        vlrm = 1;
        break;
     }
 if (vlrm){
    free(no_aux1);
    return 1;
 }
 else
     return 0;
}
// Função para busca -----------------------------------------------------------
short Buscar_No(Matriz *M, PosCel Pos, int *S)
{
 int i = 0, j = 0;
 No *no_aux1 = NULL;
 
 i = Pos.i - 1;
 j = Pos.j - 1;
 if ((!M->Col[j].prim)||(!M->Lin[i].prim))
    return 0;
 for (no_aux1 = M->Col[j].prim; no_aux1; no_aux1 = no_aux1->prox_inf)
     if (no_aux1->Pos.i == Pos.i){
        *S = no_aux1->Info;
        return 1;  
     }
 *S = 0;
 return 0;  
}
// Função para soma ------------------------------------------------------------
void Somar_Matriz(Matriz *M, PosCel Pos, int Op, int *S)
{
 int i = 0, j = 0, s = 0;
 No *no_aux1 = NULL;
 PosCel aux;
 
 *S = 0;
 i = Pos.i - 1;
 j = Pos.j - 1;
 switch (Op){
        case 1: if (!M->Lin[i].prim)
                   *S = 0;
                else
                    for (no_aux1 = M->Lin[i].prim; no_aux1; no_aux1 = no_aux1->prox_dir)
                        *S += no_aux1->Info;   
        break;
        case 2: if (!M->Col[j].prim)
                   *S = 0;
                else
                    for (no_aux1 = M->Col[j].prim; no_aux1; no_aux1 = no_aux1->prox_inf)
                        *S += no_aux1->Info;
        break;
        case 3: aux.i = 1; aux.j = 1;
                for (aux.i = 1, aux.j = 1; aux.j <= OM; aux.i++, aux.j++){
                    if (Buscar_No(M, aux, &s))
                       *S += s;
                }
        break;
        case 4: aux.i = 1; aux.j = 1;
                for (aux.i = 1, aux.j = OM; aux.j >= 1; aux.i++, aux.j--){
                    if (Buscar_No(M, aux, &s))
                       *S += s;
                }
        break;
        }
 return;
}

// Função de permutação entre linhas -------------------------------------------
void Perm_LC_Matriz(Matriz *M, int Op, PosCel Pos)
{
 int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
 No *no_aux1 = NULL;
 Cel aux1;
 
 switch (Op){
        case 1: j1 = Pos.i - 1; j2 = Pos.j - 1;
                for (no_aux1 = M->Col[j1].prim; no_aux1; no_aux1 = no_aux1->prox_inf)
                    no_aux1->Pos.j = j2 + 1;
                for (no_aux1 = M->Col[j2].prim; no_aux1; no_aux1 = no_aux1->prox_inf)
                    no_aux1->Pos.j = j1 + 1;
                aux1 = M->Col[j1];
                M->Col[j1] = M->Col[j2];
                M->Col[j2] = aux1;     
        break;
        case 2: i1 = Pos.i - 1; i2 = Pos.j - 1;
                for (no_aux1 = M->Lin[i1].prim; no_aux1; no_aux1 = no_aux1->prox_dir)
                    no_aux1->Pos.i = i2 + 1;
                for (no_aux1 = M->Lin[i2].prim; no_aux1; no_aux1 = no_aux1->prox_dir)
                    no_aux1->Pos.i = i1 + 1;
                aux1 = M->Lin[i1];
                M->Lin[i1] = M->Lin[i2];
                M->Lin[i2] = aux1;
        break;
 }
 return;
}

// Função de multiplicação de linha ou coluna por escalar ----------------------
void Mult_LC_Matriz(Matriz *M, int Op, PosCel Pos, int K)
{
 int i = 0, j = 0;
 No *no_aux1 = NULL;
 
 i = Pos.i - 1;
 j = Pos.j - 1;
 switch (Op){
        case 1: if (!M->Col[j].prim)
                   return;
                for (no_aux1 = M->Col[j].prim; no_aux1; no_aux1 = no_aux1->prox_inf)
                    no_aux1->Info *= K;
        break;
        case 2: if (!M->Lin[i].prim)
                   return;
                for (no_aux1 = M->Lin[i].prim; no_aux1; no_aux1 = no_aux1->prox_dir)
                    no_aux1->Info *= K;
        break;
 }
 return;
}

// Função para impressão -------------------------------------------------------
void Imprimir_Matriz(Matriz *M)
{
 int a = 0, b = 0, c = 0;
 No *aux_no1;
 
 for (a = 0; a < OM; a++){
     printf("\n");
     if (M->Lin[a].prim == NULL)
        for (b = 1; b <= OM; b++)
            printf("| X |");
     else{
          for (b = 1, aux_no1 = M->Lin[a].prim; aux_no1; aux_no1 = aux_no1->prox_dir, b++){
                    for ( ; b < aux_no1->Pos.j; b++)
                        printf("| X |");
                printf("| %d |", aux_no1->Info);
          }
          for (; b <= OM; b++)
              printf("| X |");
     }
 }
 return;
}
