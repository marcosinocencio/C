#include "Interface.h"

int p, o, o2, continua, continua2;
float k, x;
char op;

void Interface (void){
     
printf("############################################################################\n");
printf("############################################################################\n");
printf("#####                      Trabalho Polinomios                         #####\n");
printf("#####                                                                  #####\n");
printf("#####         Alunos:    Marcos Vinicius Inocencio   RA: 1295357       #####\n");
printf("#####                    Luis Felipe L. Santos       RA: 1295900       #####\n");
printf("#####                                                                  #####\n");
printf("############################################################################\n");
printf("############################################################################\n");
printf("\n\n");
system("pause");
system("cls");

printf("Para iniciar, insira  tres polinomios: \n\n");
     printf("Polinomio 1:\n");
     Construir(p1);
     printf("\n\n");
     system("pause");
     system("cls");
     printf("Polinomio 2:\n");
     Construir(p2);
     printf("\n\n");
     system("pause");
     system("cls");
     printf("Polinomio 3:\n");
     Construir(p3);
     printf("\n\n");
     system("pause");
     
     
     do{
     system("cls");
     continua = 1;             
     printf("O que deseja fazer?\n\n");
     
     printf("1  - Visualizar um polinomio.\n"); 
     printf("2  - Visualizar o grau de um polinomio.\n");    
     printf("3  - Calcula o numero de termos de um polinomio.\n");    
     printf("4  - Calcular o valor de um polinomio dado um x.\n");    
     printf("5  - Calcular a soma entre dois polinomios.\n");    
     printf("6  - Calcular a subtracao entre dois polinomios.\n");    
     printf("7  - Calcular a multiplicacao entre dois polinomios.\n");    
     printf("8  - Calcular a divisao entre dois polinomios.\n");    
     printf("9  - Polinomio multiplicado por uma constante.\n");    
     printf("10 - Calcular a derivada de um polinomio.\n");    
     printf("11 - Calcular a integral de um polinomio.\n"); 
     printf("12 - Sair.\n\n");    
     
     printf("Opcao:");                   
     scanf("%d",&p);
     
     switch (p){
     case 1 : system("cls");
              continua2 = 1;
              do{
              printf("Qual polinomio deseja visualizar(1,2 ou 3)?:");
              scanf("%d", &o);
              if ( o < 1 || o > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2); 
              
              if(o == 1){
              system("cls");
              printf("Polinomio %d:\n\n",o);
              Imprimir(p1);
              printf("\n\n");
              system("pause");
              }
              
              else if (o == 2){
              system("cls");
              printf("Polinomio %d:\n\n",o);
              Imprimir(p2);
              printf("\n\n");
              system("pause");
              }
              
              else if (o == 3){
              system("cls");
              printf("Polinomio %d:\n\n",o);
              Imprimir(p3);
              printf("\n\n");
              system("pause");
              }
              
              break; 
              
     case 2 : system("cls");
              continua2 = 1;
              do{
              printf("Qual polinomio deseja ver seu Grau(1,2 ou 3)?:");
              scanf("%d", &o);
              if ( o < 1 || o > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2); 
              
              if(o == 1){
              system("cls");
              printf("O grau do Polinomio %d e: %d\n\n",o,Grau(p1));
              system("pause");
              }
              
              else if (o == 2){
              system("cls");
              printf("O grau do Polinomio %d e: %d\n\n",o,Grau(p2));
              system("pause");
              }
              
              else if (o == 3){
              system("cls");
              printf("O grau do Polinomio %d e: %d\n\n",o,Grau(p3));
              system("pause");
              }
              
              break;
              
     case 3 : system("cls");
              continua2 = 1;
              do{
              printf("Qual polinomio deseja visualizar a quantidade de termos(1,2 ou 3)?:");
              scanf("%d", &o);
              if ( o < 1 || o > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2); 
              
              if(o == 1){
              system("cls");
              printf("O numero de termos do Polinomio %d e: %d\n\n",o, Numero_Termos(p1));
              system("pause");
              }
              
              else if (o == 2){
              system("cls");
              printf("O numero de termos do Polinomio %d e: %d\n\n",o, Numero_Termos(p2));
              system("pause");
              }
              
              else if (o == 3){
              system("cls");
              printf("O numero de termos do Polinomio %d e: %d\n\n",o, Numero_Termos(p3));
              system("pause");
              }
              
              break; 
              
      case 4 : system("cls");
              continua2 = 1;
              do{
              printf("Qual polinomio deseja calcular seu valor num dado x(1,2 ou 3)?:");
              scanf("%d", &o);
              if ( o < 1 || o > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2); 
              
              system("cls");
              printf("Qual valor de x?:");
              scanf("%f", &x);
              
              if(o == 1){
              system("cls");
              printf("O valor do Polinomio %d em %6.2f e: %12.2f\n\n",o,x,Calcula_x(p1,x));
              system("pause");
              }
              
              else if (o == 2){
              system("cls");
              printf("O valor do Polinomio %d em %6.2f e: %12.2f\n\n",o,x,Calcula_x(p2,x));
              system("pause");
              }
              
              else if (o == 3){
              system("cls");
              printf("O valor do Polinomio %d em %6.2f e: %12.2f\n\n",o,x,Calcula_x(p3,x));
              system("pause");
              }
              
              break;     
                  
     case 5 : system("cls");
              continua2 = 1;
              do{
              printf("Escolha o primeiro polinomio para realizar a soma(1,2 ou 3):");
              scanf("%d", &o);
              if ( o < 1 || o > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2); 
              
              continua2 = 1;
              do{
              printf("\nEscolha o segundo polinomio para realizar a soma(1,2 ou 3):");
              scanf("%d", &o2);
              if ( o2 < 1 || o2 > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2); 
     
              if ( o == 1 && o2 == 1){
              system("cls");
              Somar(p1,p1,pr);
              printf("A soma do Polinomio %d com o Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 1 && o2 == 2){
              system("cls");
              Somar(p1,p2,pr);
              printf("A soma do Polinomio %d com o Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 1 && o2 == 3){
              system("cls");
              Somar(p1,p3,pr);
              printf("A soma do Polinomio %d com o Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 2 && o2 == 2){
              system("cls");
              Somar(p2,p2,pr);
              printf("A soma do Polinomio %d com o Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 2 && o2 == 1){
              system("cls");
              Somar(p2,p1,pr);
              printf("A soma do Polinomio %d com o Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 2 && o2 == 3){
              system("cls");
              Somar(p2,p3,pr);
              printf("A soma do Polinomio %d com o Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 3 && o2 == 3){
              system("cls");
              Somar(p3,p3,pr);
              printf("A soma do Polinomio %d com o Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 3 && o2 == 1){
              system("cls");
              Somar(p3,p1,pr);
              printf("A soma do Polinomio %d com o Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 3 && o2 == 2){
              system("cls");
              Somar(p3,p2,pr);
              printf("A soma do Polinomio %d com o Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              
              break;
              
     case 6 : system("cls");
              continua2 = 1;
              do{
              printf("Escolha o primeiro polinomio para realizar a subtracao(1,2 ou 3):");
              scanf("%d", &o);
              if ( o < 1 || o > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2); 
              
              continua2 = 1;
              do{
              printf("\nEscolha o segundo polinomio para realizar a subtracao(1,2 ou 3):");
              scanf("%d", &o2);
              if ( o2 < 1 || o2 > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2); 
     
              if ( o == 1 && o2 == 1){
              system("cls");
              Subtrair(p1,p1,pr);
              printf("A subtracao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 1 && o2 == 2){
              system("cls");
              Subtrair(p1,p2,pr);
              printf("A subtracao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 1 && o2 == 3){
              system("cls");
              Subtrair(p1,p3,pr);
              printf("A subtracao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 2 && o2 == 2){
              system("cls");
              Subtrair(p2,p2,pr);
              printf("A subtracao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 2 && o2 == 1){
              system("cls");
              Subtrair(p2,p1,pr);
              printf("A subtracao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 2 && o2 == 3){
              system("cls");
              Subtrair(p2,p3,pr);
              printf("A subtracao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 3 && o2 == 3){
              system("cls");
              Subtrair(p3,p3,pr);
              printf("A subtracao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 3 && o2 == 1){
              system("cls");
              Subtrair(p3,p1,pr);
              printf("A subtracao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 3 && o2 == 2){
              system("cls");
              Subtrair(p3,p2,pr);
              printf("A subtracao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              
              break; 
              
     case 7 : system("cls");
              continua2 = 1;
              do{
              printf("Escolha o primeiro polinomio para realizar a multiplicacao(1,2 ou 3):");
              scanf("%d", &o);
              if ( o < 1 || o > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2); 
              
              continua2 = 1;
              do{
              printf("\nEscolha o segundo polinomio para realizar a multiplicacao(1,2 ou 3):");
              scanf("%d", &o2);
              if ( o2 < 1 || o2 > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2); 
     
              if ( o == 1 && o2 == 1){
              system("cls");
              Multiplicar(p1,p1,pr);
              printf("A multiplicacao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if ((o == 1 && o2 == 2) ||(o == 2 && o2 == 1)){
              system("cls");
              Multiplicar(p1,p2,pr);
              printf("A multiplicacao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if ((o == 1 && o2 == 3) || (o == 3 && o2 == 1)){
              system("cls");
              Multiplicar(p1,p3,pr);
              printf("A multiplicacao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 2 && o2 == 2){
              system("cls");
              Multiplicar(p2,p2,pr);
              printf("A multiplicacao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if (o == 3 && o2 == 3){
              system("cls");
              Multiplicar(p3,p3,pr);
              printf("A multiplicacao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              else if ((o == 2 && o2 == 3)||(o == 3 && o2 == 2)){
              system("cls");
              Multiplicar(p2,p3,pr);
              printf("A multiplicacao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
                        
              break;  
              
     case 8 : system("cls");
              continua2 = 1;
              do{
              printf("Escolha o primeiro polinomio para realizar a divisao(1,2 ou 3):");
              scanf("%d", &o);
              if ( o < 1 || o > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2); 
              
              continua2 = 1;
              do{
              printf("\nEscolha o segundo polinomio para realizar a divisao(1,2 ou 3):");
              scanf("%d", &o2);
              if ( o2 < 1 || o2 > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2); 
     
              if ( (o == 1 && o2 == 1) && (Dividir(p1,p1,pr)) == 1 ){
              system("cls");
              printf("A divisao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
                                       
              else if ((o == 1 && o2 == 2) && (Dividir(p1,p2,pr)) == 1){
              system("cls");
              Dividir(p1,p2,pr);
              printf("A divisao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
                           
              else if ((o == 1 && o2 == 3) && (Dividir(p1,p3,pr))== 1){
              system("cls");
              Dividir(p1,p3,pr);
              printf("A divisao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
                            
              else if ((o == 2 && o2 == 2)&& (Dividir(p2,p2,pr))== 1){
              system("cls");
              Dividir(p2,p2,pr);
              printf("A divisao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
                           
              else if ((o == 2 && o2 == 1)&&(Dividir(p2,p1,pr))== 1){
              system("cls");
              Dividir(p2,p1,pr);
              printf("A divisao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
                           
              else if ((o == 2 && o2 == 3) && (Dividir(p2,p3,pr))== 1){
              system("cls");
              Dividir(p2,p3,pr);
              printf("A divisao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
                          
              else if ((o == 3 && o2 == 3)&&(Dividir(p3,p3,pr))== 1){
              system("cls");
              Dividir(p3,p3,pr);
              printf("A divisao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
                          
              else if ((o == 3 && o2 == 1)&&(Dividir(p3,p1,pr))== 1){
              system("cls");
              Dividir(p3,p1,pr);
              printf("A divisao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
                          
              else if ((o == 3 && o2 == 2)&&(Dividir(p3,p2,pr))== 1){
              system("cls");
              Dividir(p3,p2,pr);
              printf("A divisao do Polinomio %d pelo Polinomio %d e o Polinomio: \n\n", o,o2);
              Imprimir(pr);
              printf("\n\n");
              system("pause");
              }
              
              else { 
              system("cls"); 
              printf("O Grau do polinomio dividendo e menor que o divisor.\n\n");
              printf("\n\n");
              system("pause");
              }
              break;          
                                            
     case 9 : system("cls");
              continua2 = 1;
              do{
              printf("Qual polinomio deseja multiplicar por uma constante k(1,2 ou 3)?:");
              scanf("%d", &o);
              if ( o < 1 || o > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2); 
              
              system("cls");
              printf("Por qual constante deseja multiplicar o polinomio %d:", o);
              scanf("%f", &k);
              
              if(o == 1){
              Multiplica_Constante(p1, k);
              system("cls");
              printf("Polinomio %d multiplicado por %f:\n\n",o,k);
              Imprimir(p1);
              printf("\n\n");
              system("pause");
              }
              
              else if (o == 2){
              Multiplica_Constante(p2, k);
              system("cls");
              printf("Polinomio %d multiplicado por %f:\n\n",o,k);
              Imprimir(p2);
              printf("\n\n");
              system("pause");
              }
              
              else if (o == 3){
              Multiplica_Constante(p3, k);
              system("cls");
              printf("Polinomio %d multiplicado por %f:\n\n",o,k);
              Imprimir(p3);
              printf("\n\n");
              system("pause");
              }
              
              break;   
              
                  
     case 10: system("cls");
              continua2 = 1;
              do{
              printf("Qual polinomio deseja derivar(1,2 ou 3)?:");
              scanf("%d", &o);
              if ( o < 1 || o > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2);
              
              if(o == 1){
              Derivar(p1);
              system("cls");
              printf("Polinomio %d derivado:\n\n",o);
              Imprimir(p1);
              printf("\n\n");
              system("pause");
              }
              
              else if (o == 2){
              Derivar(p2);
              system("cls");
              printf("Polinomio %d derivado:\n\n",o);
              Imprimir(p2);
              printf("\n\n");
              system("pause");
              }
              
              else if (o == 3){
              Derivar(p3);
              system("cls");
              printf("Polinomio %d derivado:\n\n",o);
              Imprimir(p3);
              printf("\n\n");
              system("pause");
              }
              
              break;        
            
     case 11: system("cls");
              continua2 = 1;
              do{
              printf("Qual polinomio deseja integrar(1,2 ou 3)?:");
              scanf("%d", &o);
              if ( o < 1 || o > 3)
              printf("\nEsse polinomio nao existe!\n\n");
              else continua2 = 0;
              }while (continua2);
              
              if(o == 1){
              Integrar(p1);
              system("cls");
              printf("Polinomio %d integrado:\n\n",o);
              Imprimir(p1);
              printf("\n\n");
              system("pause");
              }
              
              else if (o == 2){
              Integrar(p2);
              system("cls");
              printf("Polinomio %d integrado:\n\n",o);
              Imprimir(p2);
              printf("\n\n");
              system("pause");
              }
              
              else if (o == 3){
              Integrar(p3);
              system("cls");
              printf("Polinomio %d integrado:\n\n",o);
              Imprimir(p3);
              printf("\n\n");
              system("pause");
              }
              
              break; 
                    
     case 12: system("cls");
              fflush(stdin);
              printf("Deseja realmente sair(S/N)?");
              op = getchar();
              if ( op == 'S' || op == 's') 
              continua = 0;
              break;
              
     default: system("cls");
              printf("Opcao invalida!\n");
              printf("\n\n");
              system("pause");
              break;                
     }    //switch
     } while(continua);   //do-while
}



     
