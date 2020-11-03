#include "main.h"
#include "editor.h"
#include <windows.h>

#define MAX 12

int x=0,y=0, seta =0, ultima_insercao, teste;
Tno *recorta_in = NULL, *recorta_fim = NULL;

/*____________________Imprime um cabecalho____________________*/
void ImprimeCabecalho(char nome[100]){
system("cls");
printf("________________________________________________________________________________");
printf("\n %c %s %c \n\n",254,nome,254);
printf("________________________________________________________________________________\n\n");
                                      
}

/*____________________Posiciona Cursor____________________*/
void Cursor(int X,int Y){

    HANDLE stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = X;
    position.Y = Y;
    SetConsoleCursorPosition(stdoutHandle, position);
}


/*____________________Inicializacao____________________*/
void Inicializa(Tlinha **Estrutura, Tlinha **Atual){

     *Estrutura = (Tlinha*)malloc(sizeof(Tlinha));
     (*Estrutura)->inicio = (Tno*)malloc(sizeof(Tno));
     (*Estrutura)->fim = (Tno*)malloc(sizeof(Tno));

     (*Estrutura)->inicio->prox = (*Estrutura)->fim;
     (*Estrutura)->inicio->ant = NULL;
     (*Estrutura)->fim->prox = NULL;
     (*Estrutura)->fim->ant = (*Estrutura)->inicio;
     (*Estrutura)->prox = NULL;
     (*Estrutura)->ant = NULL;
     (*Estrutura)->atual = (*Estrutura)->inicio;               //Pode servir para identificar se a lista está vazia

     *Atual = *Estrutura;
}

void Inicializa_Editor(Teditor **editor){
     (*editor)->qtdletras =  0;
     (*editor)->qtdp      =  0;
     (*editor)->cor_letra =  1;
     (*editor)->cor_fundo = 15;
}




/*____________________Leitura____________________*/
void Leitura (Tlinha **Atual, Tlinha **Estrutura, Tfila **F, Tfila **Copia, Teditor **edt){
     char car,procurardnovo,palavra_procurada[MAX],substituicao[MAX];
     short insert = -1;
     int cor;
     register int cont=0;            //conta quantos caracteres exixtem na linha no total
     int quantcar = 0, setad, ativa_busca = 0,i=0;               //conta quantos caracteres existem na linha até atual

     char busca[10];

     *Atual = *Estrutura;

     do{
              quantcar = Contacar_Atual(*Atual);
              cont = Contacar_Final(*Atual);

              car = getch();

              switch(car){//switch 1
                     case -32://tecla especial
                          car = getch();
                          if(car != 83 && car != 115 && car != 116){
                                 Atualiza_Selecao(Atual);
                                 recorta_fim = NULL;
                                 recorta_in = NULL;
                          }
                          switch(car){//switch 2
                                 case 75://Seta Esquerda
                                         Setaesquerda(Atual);
                                         if(quantcar > 0)quantcar--;
                                         if(x>0 && quantcar<79)--x;
                                         else if(x!=0) x = 79;   //existe scroll
                                         seta =0;
                                         break;

                                 case 71: //home
                                          (*Atual)->atual = (*Atual)->inicio;
                                          quantcar = 0;
                                          x=0;
                                          seta =0;
                                          break;
                                 case 72: // Seta cima
                                          Setacima(Atual, *Estrutura);
                                          quantcar = x;
                                          seta =0;
                                          break;
                                 case 77: //Seta Direita
                                          Setadireita(Atual);
                                          quantcar = Contacar_Atual(*Atual);
                                          x = quantcar;
                                          //     else
                                          //*if* se todos os caracteres cabem na tela, o cursor deverá mover-se para direita, caso contrário o cursor permanece na última posição(79)
                                          seta =0;
                                          break;
                                 case 79: //end
                                          (*Atual)->atual = (*Atual)->fim->ant;
                                          //*if* Se houve scroll, quando pressionamos a tecla end o cursor deve posicionar-se no fim da tela(posição 79)
                                          if(cont>79){
                                             x = 79;
                                             quantcar = cont;         //preciso atualiza quantcar, pois o caracter atual mudou
                                          }
                                          else x = Contacar_Atual(*Atual);//caso contrário o cursor irá se posicionar na útima posição da lista
                                          seta =0;
                                          break;
                                 case 80: //Seta baixo
                                          Setabaixo(Atual);
                                          quantcar = x;
                                          seta =0;
                                          break;
                                 case 82: //insert
                                          insert *= -1;   //ativando/desativando (1=ativado, -1=desativado)
                                          seta =0;
                                          break;
                                 case 83: //delete;
                                          if(seta){
                                            system("cls");
                                            Concatena(Atual);
                                          }
                                          else{
                                           Atualiza_Selecao(Atual);
                                           Delete(Atual);
                                          }
                                          seta =0;
                                          recorta_in = NULL;
                                          recorta_fim = NULL;
                                          break;


                                 case 117://ctrl+end
                                          while((*Atual)->prox != NULL){
                                             y++;
                                             (*Atual) = (*Atual)->prox;
                                          }
                                         (*Atual)->atual = (*Atual)->fim->ant;
                                          quantcar = cont = Contacar_Final(*Atual);
                                          if(cont>79)x = 79;
                                          else x = Contacar_Atual(*Atual);
                                          seta = 0;

                                 break;


                                 case 119:
                                          y = x = quantcar = 0;
                                          (*Atual) = (*Estrutura);
                                          (*Atual)->atual = (*Atual)->inicio;
                                          seta = 0;
                                 break;

                          }//switch 2
                    break;//case -32

                    case 0:
                    car = getch();
                       switch(car){//switch 3
                                 case 63://SALVAR
                                      Salvar(*Estrutura);
                                      fclose(fp);
                                      break;
                                 case 60:
                                      cor =(*edt)->cor_letra;
                                      do{
                                      system("cls");
                                      ImprimeCabecalho("TROCAR COR DA LETRA");
                                      printf("Insira a cor:");
                                      textbackground(15);
                                      textcolor(0); printf("\n0a");
                                      textcolor(1); printf(" - 1");
                                      textcolor(2); printf("\n2");
                                      textcolor(3); printf(" - 3");
                                      textcolor(4); printf("\n4");
                                      textcolor(5); printf(" - 5");
                                      textcolor(6); printf("\n6");
                                      textcolor(7); printf(" - 7");
                                      textcolor(8); printf("\n8");
                                      textcolor(9); printf(" - 9");
                                      textcolor(10); printf("\n10");
                                      textcolor(11); printf(" - 11");
                                      textcolor(12); printf("\n12");
                                      textcolor(13); printf(" - 13");
                                      textcolor(14); printf("\n14");
                                      textcolor(15); printf(" - 15\n\n");
                                      textcolor(1);

                                      printf("NOVA COR:");
                                      scanf("%d",&cor);

                                      if ((cor<0) || (cor>15)){}
                                      else (*edt)->cor_letra = cor;

                                      }while((cor<0) || (cor>15));
                                         break;

                                 case 61://Buscar novamente
                                         if(ativa_busca){
                                                   Atualiza_Selecao(Atual);
                                                   if (Busca_Palavra(busca, Atual, &(*Atual)->atual, F)== 1 ){
                                                                        seta = 1 ;
                                                                        x = quantcar = Contacar_Atual(*Atual);
                                                   }
                                                   else seta = 0;
                                                   }
                                        break;


                                 case 64://ABRIR
                                      Abrir(Estrutura, Atual,1);
                                      quantcar = cont = 0;
                                      seta =0;
                                      recorta_in = NULL;
                                      recorta_fim = NULL;
                                      break;
                                 
                                 case 67://QUANTIDADE DE LINHAS
                                 system("cls");
                                 (*edt)->qtdlinhas = 0;
                                 ContaLinhas(*Estrutura,quantcar,*edt);
                                 ImprimeCabecalho("CONTAGEM DE LINHAS");
                                 printf("Quantidade de linhas %d",(*edt)->qtdlinhas);
                                 getch();     
                                 break;
                                     
                                 case 66://QUANTIDADE DE PALAVRAS
                                 system("cls");
                                 (*edt)->qtdp = 0;
                                 ContaP(*Estrutura,quantcar,*edt);
                                 ImprimeCabecalho("CONTAGEM DE PALAVRAS");
                                 printf("Quantidade de palavras %d",(*edt)->qtdp);
                                 getch();     
                                 break;
                                 
                                 case 62://QUANTIDADE DE LETRAS
                                 system("cls");
                                 (*edt)->qtdletras = 0;
                                 ContaL(*Estrutura,quantcar,*edt);
                                 ImprimeCabecalho("CONTAGEM DE LETRAS");
                                 printf("Quantidade de letras %d",(*edt)->qtdletras);
                                 getch();     
                                 break;
                                      
                                  case 59:

                                       Ajuda();
                                       break;
                       }//switch 3
                   break;//case 0



                   case 6://BUSCA
                   
                        //Posiciona o cursor no inicio
                        (*Atual)->atual = (*Atual)->inicio;
                                          quantcar = 0;
                                          x=0;
                                          seta =0;
                        //Termina o cursor
                        
                        Atualiza_Selecao(Atual);
                        system("cls");
                        ImprimeCabecalho("BUSCA DE PALAVRAS");
                        printf("\n Insira a palavra: ");
                        gets(busca);
                        if ((busca[0] != '\0') && Busca_Palavra(busca, Atual, &(*Atual)->atual, F)== 1)
                            seta = 1 ;
                        else{
                             seta = 0;
                             printf("\n\t\t\t(!)Palavra NAO encontrada!");
                             system("pause>null");
                        }
                        ativa_busca =1;
                        x = quantcar = Contacar_Atual(*Atual);
                   break;

                  

                   default:
                           
                           if (Tratamento(Atual, Estrutura, F, Copia, car)){
                              Atualiza_Selecao(Atual);
                              if(insert == -1) {
                                               if(seta){
                                                        Concatena(Atual);
                                                        }
                                               Insere(Atual, car);
                                               (*edt)->qtdletras++;
                                               seta = 0;
                                               }
                              else {
                                     if(seta){
                                             Concatena(Atual);
                                             }
                                              Sobrescreve(Atual, car);
                                               seta = 0;
                                  }
                                x = quantcar = Contacar_Atual(*Atual);
                           }//if3
                           else{
                           
                           
                           
                              quantcar = Contacar_Atual(*Atual);
                              cont = Contacar_Final(*Atual);
                              if(car==13){
                                  y++;
                                  quantcar = cont = 0;
                              }
                              
                           }//else
                   break;
              }//switch 1

              if(x<79 && (cont+1 == quantcar)){
                                    printf("%c",car);
                                    }
              else {
                   Impressao(*Estrutura,quantcar,*edt);
                   }
              if(y>=21)
                       if(x>=79)
                               Cursor(79,20);
                       else Cursor(x,20);

              else if(x>=79)
                         Cursor(79,y);
                    else Cursor(x,y);
     }while (car != 27);

     do{
       system("cls");
       printf("\n\n\t\t\tDeseja salvar o arquivo atual?[S,N]");
       car = getche();
       car = toupper(car);
     }while(car != 'S' && car != 'N');

     if(car == 'S')Salvar(*Estrutura);

return;
}


/*____________________Insercao____________________*/
void Insere(Tlinha **Atual, char Elem){

     Tno *novo;

     novo = (Tno*)malloc(sizeof(Tno));
     novo->prox = NULL;
     novo->selecao = 0;
     novo->link[0] = '\0';
     novo->letra = Elem;

     if (Vazia(*Atual)){
          //sim, está vazia
          (*Atual)->fim->ant = novo;
          novo->prox = (*Atual)->fim;
          (*Atual)->inicio->prox = novo;
          novo->ant = (*Atual)->inicio;
          (*Atual)->atual = novo;

     }
     else if((*Atual)->atual == (*Atual)->fim->ant || (*Atual)->atual == (*Atual)->fim){//final

              novo->prox = (*Atual)->fim;
              novo->ant = (*Atual)->atual;
              (*Atual)->fim->ant = novo;
              (*Atual)->atual->prox = novo;
              (*Atual)->atual = novo;
          }
          else {

              novo->ant = (*Atual)->atual;
              novo->prox = (*Atual)->atual->prox;;
              (*Atual)->atual->prox->ant = novo;
              (*Atual)->atual->prox = novo;
              (*Atual)->atual = novo;
          }


}// Insere


/*____________________Linha Vazia____________________*/
short Vazia(Tlinha *Atual){

      if (Atual->inicio->prox == Atual->fim)
         return 1;
      else return 0;

}// Vazia


/*____________________Estruturas para percorrer a estrutura____________________*/
void Impressao (Tlinha *Estrutura,int Cont, Teditor *edt){
 system("color f1");
     register int i = 0,linhas = 0;//28/07
     Tlinha *ajd;
     Tno *aux;

     ajd = (Estrutura);
     system("cls");
     
     if(y>=21)while(i<=y-21){
                ajd = ajd->prox;
                i++;
              }
     i=0;
     do{
        aux = ajd->inicio->prox;
            
             while(i<(Cont-79) && (aux!=ajd->fim)){     
               aux=aux->prox;
               i++;
             }//while
             i=0;
            
             while(aux!=ajd->fim && i<79){
            
               if(aux->selecao == 1){
                  textbackground(9);
                  textcolor(15);
               }
                         else{
                            textbackground(edt->cor_fundo);
                            textcolor(edt->cor_letra);
                         }
               printf("%c",aux->letra);
               aux = aux->prox;
               i++;
             }//while
             textbackground(edt->cor_fundo);
             textcolor(edt->cor_letra);

        ajd = ajd->prox;             //mudando de linha
        linhas++;
        printf("\n");
        i=0;
     }while (ajd!= NULL && linhas!=21);

}// Impressao




void ContaL (Tlinha *Estrutura,int Cont, Teditor *edt){
 system("color f1");
 edt->qtdletras = 0;
     register int i = 0,linhas = 0;
     Tlinha *ajd;
     Tno *aux;

     ajd = (Estrutura);

     
     if(y>=21)while(i<=y-21){
                ajd = ajd->prox;
                i++;
              }
     i=0;
     do{
        aux = ajd->inicio->prox;

             
             while(i<(Cont-79) && (aux!=ajd->fim)){     
               aux=aux->prox;
               i++;
             }//while
             i=0;


             while(aux!=ajd->fim && i<79){

             if((aux->letra != 32) && (aux->letra != 44) && (aux->letra != 46)&& (aux->letra != 59)&& (aux->letra != 58)&& (aux->letra != 92)&& (aux->letra != 124)&& (aux->letra != 45)&& (aux->letra != 95)&& (aux->letra != 33)&& (aux->letra != 34)&& (aux->letra != 39)&& (aux->letra != 64))
             edt->qtdletras ++;

               aux = aux->prox;
               i++;
             }
             textbackground(edt->cor_fundo);
             textcolor(edt->cor_letra);

        ajd = ajd->prox;             //mudando de linha
        linhas++;
        printf("\n");
        i=0;
     }while (ajd!= NULL && linhas!=21);
}


void ContaLinhas (Tlinha *Estrutura,int Cont, Teditor *edt){
 system("color f1");
 edt->qtdletras = 0;
     register int i = 0,linhas = 0;
     Tlinha *ajd;
     Tno *aux;

     ajd = (Estrutura);

     
     if(y>=21)while(i<=y-21){
                ajd = ajd->prox;
                i++;
              }
     i=0;
     do{
        aux = ajd->inicio->prox;

            
             while(i<(Cont-79) && (aux!=ajd->fim)){     
               aux=aux->prox;
               i++;
             }
             i=0;


             while(aux!=ajd->fim && i<79){
               aux = aux->prox;
               i++;
             }
             textbackground(edt->cor_fundo);
             textcolor(edt->cor_letra);

        ajd = ajd->prox;             //mudando de linha
        linhas++;
        edt->qtdlinhas ++;
        printf("\n");
        i=0;
     }while (ajd!= NULL && linhas!=21);
}

void ContaP (Tlinha *Estrutura,int Cont, Teditor *edt){
 system("color f1");
 edt->qtdletras = 0;
     register int i = 0,linhas = 0;
     Tlinha *ajd;
     Tno *aux;
     char c, cant, cprox;
     
     ajd = (Estrutura);

    
     if(y>=21)while(i<=y-21){
                ajd = ajd->prox;
                i++;
              }
     i=0;
     do{
        aux = ajd->inicio->prox;

            
             while(i<(Cont-79) && (aux!=ajd->fim)){      //cont-79 é o excesso de caracteres
               aux=aux->prox;
               i++;
             }//while
             i=0;


             while(aux!=ajd->fim && i<79){
             
             cant  = (aux->ant)->letra;
             c     = aux->letra;
             cprox = (aux->prox)->letra;
             
             if ((c == 32) && ((cant != 32) && (cprox != 32))){
             
             if((c == 32) && (aux->ant != ajd->fim) && (cant != 32) && (cprox != 32)) edt->qtdp ++;
             else if ((c == 32) && (aux->ant != ajd->fim)&& (aux->prox != ajd->fim && (cant != 32) && (cprox != 32))) edt->qtdp ++;
             else if ((c == 32) && (aux != ajd->fim) && (aux->prox != ajd->fim) && (cant != 32) && (cprox != 32)) edt->qtdp ++;
             }
            
             
             if((c != 32) && (aux != ajd->fim) && (aux->prox == ajd->fim))edt->qtdp ++;
             
             
               aux = aux->prox;
               i++;
             }
             //textbackground(edt->cor_fundo);
             //textcolor(edt->cor_letra);

        ajd = ajd->prox;             //mudando de linha
        linhas++;
        printf("\n");
        i=0;
     }while (ajd!= NULL && linhas!=21);
}


/*____________________Tratamento____________________*/
int Tratamento(Tlinha **Atual, Tlinha **Estrutura, Tfila **F, Tfila **Copia, int Elem){
short caracteresp =0, aux;

    switch(Elem){
                 
                 case 8: //BackSpace
                        Atualiza_Selecao(Atual);
                        aux = Remove(Atual, Estrutura);
                        
                        if(Contacar_Atual(*Atual)<79 && x>0)x--;    
                        else if(Contacar_Atual(*Atual)>=79)x = 79;
                        seta = 0;
                        return 0;
                        break;
                 case 13://ENTER
                         Pula_Linha(Atual,Estrutura);
                         seta =0;
                         Atualiza_Selecao(Atual);
                         return 0 ;
                         break;
                 default:
                         return 1;
                 }

}


/*____________________Remocao____________________*/
short Remove(Tlinha **Atual, Tlinha **Estrutura){

      Tno *aux2, *guarda_novo_atual;

      Tlinha *aux;

      if(!Vazia(*Atual)){
                     if((*Atual)->inicio->prox == (*Atual)->atual && (*Atual)->inicio->prox != (*Atual)->fim){ //Esta apontando para a primeira letra, sendo q tem outras letras depois dela
                                    aux2 = (*Atual)->inicio->prox;
                                    (*Atual)->inicio->prox= aux2->prox;
                                    aux2->prox->ant = (*Atual)->inicio;
                                    free(aux2);
                                    (*Atual)->atual = (*Atual)->inicio;
                                    return 0;
                     }
                     else if((*Atual)->fim->ant == (*Atual)->atual){    //O caracter que será removido é o ultimo da linha
                               aux2 = (*Atual)->atual;
                               aux2->ant->prox = (*Atual)->fim;
                               (*Atual)->fim->ant = aux2->ant;
                               free(aux2);
                               (*Atual)->atual = (*Atual)->fim->ant;
                               return 0;
                               }
                               else if((*Atual)->inicio == (*Atual)->atual && (*Atual)== *Estrutura) //Não terá caracter a ser removido e está na primeira linha
                                          return 0;
                                    else if((*Atual)->inicio == (*Atual)->atual && (*Atual) != *Estrutura){   //Não terá caracter a ser removido, mas o conteúdo da linha atual deverá subir para linha anterior
                                              aux = (*Atual)->ant;
                                              guarda_novo_atual = (*Atual)->ant->fim->ant;
                                              aux->fim->ant->prox = (*Atual)->inicio->prox;
                                              (*Atual)->inicio->prox->ant = aux->fim->ant;
                                              aux->fim = (*Atual)->fim;
                                              aux->prox = (*Atual)->prox;
                                              if((*Atual)->prox!=NULL)
                                                                     (*Atual)->prox->ant = aux;
                                              free(Atual);
                                              (*Atual) = aux;
                                              (*Atual)->atual = guarda_novo_atual;
                                              x = Contacar_Atual(*Atual)+1;
                                              y--;
                                              return 1;
                                             }
                                    else{
                                         aux2 = (*Atual)->atual;
                                         aux2->ant->prox = aux2->prox;
                                         aux2->prox->ant = aux2->ant;
                                         free(aux2);
                                         (*Atual)->atual = (*Atual)->atual->ant;
                                         }
      }//if(!Vazia(Estrutura))
      else {
           if((*Atual)->ant != NULL){    //Se a linha atual estiver vazia e tiver uma linha antes dela
               (*Atual)->ant->prox = (*Atual)->prox;
               if((*Atual)->prox !=NULL) //Se depois da linha atual ainda tiver outra linha.
                     (*Atual)->prox->ant = (*Atual)->ant;
               aux = (*Atual)->ant;

               aux->fim->ant->prox = (*Atual)->fim;
               (*Atual)->fim->ant = aux->fim->ant;

               aux->fim = (*Atual)->fim;

               free(Atual);
               (*Atual) = aux;

               (*Atual)->atual = aux->fim->ant;//(*Atual)->fim->ant;
               y--;
               x = Contacar_Atual(*Atual)+1;

               return 1;
           }//if
           else return 0;
      }//else
}// Remove


/*____________________Direcionais____________________*/
short Setaesquerda(Tlinha **Atual){

     Tlinha *aux;
     aux = *Atual;

     if(aux->atual != (*Atual)->inicio){
                   aux->atual = (*Atual)->atual->ant;
                   return 1;
                   }
     else return 0;

}


short Setadireita(Tlinha **Atual){

       Tlinha *aux;
       aux = *Atual;

     if(aux->atual->prox != (*Atual)->fim){
                   aux->atual = (*Atual)->atual->prox;
                   return 1;
                   }
     else return 0;


}

void Setacima(Tlinha **Atual, Tlinha *Estrutura){

     Tno*aux;
     int cont =0;

     if((*Atual)!= Estrutura){
         (*Atual) = (*Atual)->ant;
         aux = (*Atual)->inicio;

         while ((aux->prox!= (*Atual)->fim) && (cont < x)){
               cont++;
               aux = aux->prox;
               }

         if(cont == x){
                   (*Atual)->atual = aux;
                   }
         else{
                    (*Atual)->atual = aux;
                    x = cont;
                    }

     y--;
         }
}

void Setabaixo(Tlinha **Atual){

     Tno*aux;
     int cont =0;

     if((*Atual)->prox!= NULL){
         (*Atual) = (*Atual)->prox;
          aux = (*Atual)->inicio;

         while ((aux->prox!= (*Atual)->fim) && (cont < x)){
               cont++;
               aux = aux->prox;
               }

         if(cont == x){
                   (*Atual)->atual = aux;
                   }
         else{
                    (*Atual)->atual = aux;
                    x = cont;

                    }

     y++;
         }//if
}


/*____________________Sobrescrever____________________*/
void Sobrescreve(Tlinha **Atual,char Elem){

  Tno *AtNo;

  (*Atual)->atual = (*Atual)->atual->prox;
  (*Atual)->atual->letra = Elem;

  if((*Atual)->atual == (*Atual)->fim){                     
           AtNo = (Tno*)malloc(sizeof(Tno));    
           AtNo->prox = NULL;
           AtNo->ant = (*Atual)->atual;                
           (*Atual)->fim = AtNo;
           (*Atual)->atual->prox = AtNo;
  }// if
}// Sobrescreve

/*__________________Delete____________________*/

void Delete(Tlinha **Atual){

     Tno *aux2;
     Tlinha *ajd;




     if((*Atual)->atual != (*Atual)->fim->ant){
                 aux2 = (*Atual)->atual->prox;
                 (*Atual)->atual->prox = aux2->prox;
                 aux2->prox->ant = (*Atual)->atual;
                 free(aux2);
                 }
     else if ((*Atual)->prox != NULL){
             ajd = (*Atual)->prox;
             aux2 = ajd->inicio;
             (*Atual)->atual->prox = ajd->inicio->prox;
             ajd->inicio->prox->ant = (*Atual)->atual;
             free(aux2);
             aux2 = (*Atual)->fim;
             free(aux2);
             (*Atual)->fim = ajd->fim;
             (*Atual)->prox = (*Atual)->prox->prox;
             if(ajd->prox != NULL)
               ajd->prox->ant = *Atual;

              free(ajd);
              }

}// Delete

/*__________________Contacar Atual____________________*/

int Contacar_Atual(Tlinha *Estrutura){

  Tno *percorre = Estrutura->inicio;
  register int cont = 0,diferenca = 0;

  
           while(percorre!=Estrutura->atual){
             cont++;
             percorre = percorre->prox;
           }//while
return cont;
}

/*__________________Contacar Final____________________*/

int Contacar_Final(Tlinha *Atual){

    Tno *percorre = Atual->inicio->prox;
    register int cont = 0;

    while(percorre!=Atual->fim){
       cont++;
       percorre = percorre->prox;
    }
return cont;
}

/*____________________Manipulacao de Arquivos____________________*/
void Salvar(Tlinha *Estrutura){

     Tno *aux;
     char ch,nomearq[MAX];

     system("cls");
     ImprimeCabecalho("SALVAR ARQUIVO");
     printf("\n Obs:Lembre-se de especificar o formato!\n\n Nome do arquivo a ser salvo:");
     gets(nomearq);

     if( (fp = fopen(nomearq,"w+"))==NULL){
        printf("Erro na abertura do arquivo!!!");
        system("pause>null");
        exit(1);
     }

     while(Estrutura!=NULL){
       aux = Estrutura->inicio->prox;
       while(aux!=Estrutura->fim){
         ch = aux->letra;
         fputc(ch,fp);
         aux=aux->prox;
       }
       if(Estrutura->prox!=NULL){
                  ch = '\n';
                  fputc(ch,fp);
                  }
       Estrutura = Estrutura->prox;
     }
     printf("\n\n\t\t\tSalvando em arquivo!");
     fflush(fp);
     system("pause>null");
}


void Abrir(Tlinha **Estrutura, Tlinha **Atual,int Op){

     register int i=0;
     char ch,nomearq[MAX];

     system("cls");
     if(Op == 1){
       ImprimeCabecalho("ABRIR ARQUIVO");
       printf("\n Obs:NAO se esqueca de especificar o formato\n\n Digite o nome do arquivo:");
       gets(nomearq);
     }
     
     printf("nomearq = %s",nomearq);
     if( (fp = fopen(nomearq,"r+"))==NULL){
        printf("Erro na abertura do arquivo!!!");
        system("pause>null");
        return;
     }
     Inicializa (Estrutura, Atual);

     system("cls");
     x = y = 0;
     while(!feof(fp)){
          ch = fgetc(fp);
          if(ch != '\n'){
                Insere(Atual, ch);
          }
          else{
               Pula_Linha(Atual, Estrutura);
               }
     }//while

     (*Atual) = (*Estrutura);
     (*Atual)->atual = (*Estrutura)->inicio;

fclose(fp);

}

/*__________________Pula Linha____________________*/
void Pula_Linha(Tlinha **Atual, Tlinha **Estrutura){

Tlinha *nova;
Tno *ajd, *ajd1;

    
                         x=0;

                         nova = (Tlinha*)malloc(sizeof(Tlinha));                   
                         nova->inicio = (Tno*)malloc(sizeof(Tno));
                         nova->fim = (Tno*)malloc(sizeof(Tno));

                         nova->atual = nova->inicio;
                         nova->inicio->prox = nova->fim;
                         nova->fim->ant = nova->inicio;
                         nova->fim->prox = NULL;
                         nova->inicio->ant = NULL;


                         if((*Atual)->inicio->prox == (*Atual)->fim){ //vazia
                                             nova->prox = (*Atual)->prox;
                                             (*Atual)->prox = nova;
                                             nova->ant = (*Atual);
                                             (*Atual)->fim->prox = nova->inicio;
                                             nova->inicio->ant = (*Atual)->fim;
                                             (*Atual) = nova;
                                             }
                         else{
                                             if ((*Atual)->atual == (*Atual)->inicio){ //atual incio
                                                                  if((*Atual)->ant == NULL){
                                                                                   (*Atual)->ant = nova;
                                                                                   nova->prox = (*Atual);
                                                                                   nova->ant= NULL;
                                                                                   nova->inicio->ant = NULL;
                                                                                   nova->fim->prox = (*Atual)->inicio;
                                                                                   (*Atual)->inicio->ant = nova->fim;

                                                                                   if(nova->ant == NULL)
                                                                                          (*Estrutura) = nova;
                                                                   }//if
                                                                   else {
                                                                                   nova->ant= (*Atual)->ant;
                                                                                   nova->inicio->ant = (*Atual)->ant->fim;
                                                                                   (*Atual)->ant->fim->prox = nova->inicio;
                                                                                   (*Atual)->ant->prox = nova;
                                                                                   (*Atual)->ant = nova;
                                                                                   nova->prox = (*Atual);
                                                                                   nova->fim->prox = (*Atual)->inicio;
                                                                                   (*Atual)->inicio->ant = nova->fim;
                                                                          }
                                                }
                                                else if((*Atual)->atual == (*Atual)->fim || (*Atual)->atual == (*Atual)->fim->ant){  //fim
                                                                    nova->prox = (*Atual)->prox;
                                                                    nova->ant = (*Atual);
                                                                    if((*Atual)->prox!=NULL){
                                                                                           (*Atual)->prox->ant = nova;
                                                                                           (nova)->fim->prox = (*Atual)->prox->inicio;
                                                                                           }

                                                                    (*Atual)->prox = nova;


                                                                    (nova)->inicio->ant = (*Atual)->fim;
                                                                    (*Atual)->fim->prox = (nova)->inicio;                     /*Esse trecho faz a linkagem da linha anterior com a nova linha criada*/


                                                                    (*Atual) = nova;
                                                                    }
                                                      else {
                                                           nova->prox = (*Atual)->prox;

                                                           nova->inicio->prox = (*Atual)->atual->prox;
                                                           (*Atual)->atual->prox->ant = nova->inicio;

                                                           nova->fim->ant = (*Atual)->fim->ant;
                                                           (*Atual)->fim->ant->prox = nova->fim;


                                                           (*Atual)->fim->ant = (*Atual)->atual;
                                                           (*Atual)->atual->prox = (*Atual)->fim;

                                                           (*Atual)->fim->prox = nova->inicio;
                                                           nova->inicio->ant = (*Atual)->fim;

                                                           if((*Atual)->prox!=NULL){
                                                               (*Atual)->prox->ant = nova;
                                                               (nova)->fim->prox = (*Atual)->prox->inicio;
                                                           }

                                                           (*Atual)->prox = nova;
                                                           nova->ant= (*Atual);

                                                           (*Atual) = nova;
                                                           (*Atual)->atual = (*Atual)->inicio;

                                                           }
                             }
return;
}

/*____________________Busca____________________*/
int Busca_Palavra(char *p, Tlinha **Atual, Tno **car_atual, Tfila **F)
{
   int i,j,aux;
   int n=strlen(p);


   int guarda_x = x, guarda_y = y, cont =0;


   Tlinha *guarda_linha = (*Atual);
   Tno *guarda_lista = *car_atual, *aux2_lista;


   if((*car_atual)== (*Atual)->inicio){
                     (*car_atual) = (*Atual)->inicio->prox;
                     }

   while ((*Atual) != NULL)
       {
	    for(j=0;j<n && *car_atual!= (*Atual)->fim;j++)
	       {
		    if ((*car_atual)->letra!= p[j]){
                cont++;
		        break;
            }//if
            
             if(j==0){
                  cont--;
	              aux2_lista = *car_atual;
	              recorta_in = *car_atual;
             }//if

	        *car_atual = (*car_atual)->prox;

	   }//for
	   if (j == n){
             seta =1;
             ultima_insercao = 1;
             recorta_fim = (*car_atual)->ant;
             Seleciona(aux2_lista, (*car_atual)->ant, Atual);
             (*Atual)->atual = (*car_atual)->ant;
             ultima_insercao = 1;
             x += cont;
        return 1;
        }//if
                else {
                     (*car_atual) = (*car_atual)->prox;
                     }
       }//else
   
   
   return -1;
}



void Ajuda(){
       
       ImprimeCabecalho("AJUDA DO EDITOR DE TEXTO");
       printf("\n%c F1: Ajuda\n",254);
       printf("%c F2: Trocar cor da letra\n",254);
       printf("%c F4: Contar letras\n",254);
       printf("%c F5: Salvar arquivo\n",254);
       printf("%c F6: Abrir arquivo\n",254);
       printf("%c F8: Contar palavras\n",254);
       printf("%c F9: Contar Linhas\n",254);
       printf("%c CTRL + F: Procurar palavra a partir da posicao do cursor\n",254);
       printf("%c CTRL + HOME: Ir para o inicio do texto\n",254);
       printf("%c CTRL + END: Ir para o fim do arquivo\n",254);
       printf("%c ESC: Fechar o editor\n",254);
       system("pause>null");
       system("cls");

}



/*__________________Concatena____________________*/
void Concatena(Tlinha **Atual){

     Tlinha *aux = (*Atual);
     Tno *aux2;

     aux2 = recorta_in;

     aux->atual = recorta_in->ant;

     while (aux2!=recorta_fim){
           aux2 = aux2->prox;
           if(ultima_insercao && recorta_in != aux->inicio)
                               x--;
           Delete(&aux);
           }

     if(ultima_insercao && recorta_in != aux->inicio)
                        x--;
                         Delete(&aux);

}


/*__________________Atualiza_Selecao____________________________________*/
void Atualiza_Selecao(Tlinha **Atual){

     Tno *aux = (*Atual)->inicio->prox;

     while (aux!= (*Atual)->fim){
           if(aux->selecao == 1)
              aux->selecao = 0;
           aux = aux->prox;
     }

return;
}

/*__________________Seleciona____________________*/
void Seleciona (Tno *Ini, Tno *Fim, Tlinha **Atual){

     Tno *aux;
     Tlinha *linha;

     aux = (Ini);

     while (aux!=(Fim)){
           aux->selecao = 1;
           aux =  aux->prox;
           }

     aux->selecao = 1;

     }
