#include "Interface.h"


int op,op2,op3,v,v2,v3,d,continua,cont,i,f;//variaveis de controle dos switches.
float n,n2;
char s[50];

void Interface (void){
     
printf("############################################################################\n");
printf("############################################################################\n");
printf("#####                         Trabalho Final                           #####\n");
printf("#####                                                                  #####\n");
printf("#####         Alunos:    Marcos Vinicius Inocencio   RA: 1295357       #####\n");
printf("#####                    Luis Felipe L. Santos       RA: 1295900       #####\n");
printf("#####                    Haroldo S. Teruya           RA: 1305301       #####\n");
printf("#####                                                                  #####\n");
printf("############################################################################\n");
printf("############################################################################\n");
printf("\n\n");
system("pause");
system("cls");

printf("############################################################################\n");
printf("############################################################################\n");
printf("#####                                                                  #####\n");
printf("#####                                                                  #####\n");
printf("#####                      Cadastro de Alunos                          #####\n");
printf("#####                                                                  #####\n");
printf("#####                                                                  #####\n");
printf("#####                                                                  #####\n");
printf("############################################################################\n");
printf("############################################################################\n");
printf("\n\n");
system("pause");
system("cls");


FILE *c;       // variável ponteiro de arquivo

 if ( (c=fopen("classe","r+b")) == NULL ) {
    printf("Erro na abertura da base de dados dos alunos\n\n");
    printf("O programa sera fechado\n\n");
    system("pause");
    exit(1);      // saída incondicional do programa
}
     


do{
     system("cls");
     continua = 1;             
     printf("O que deseja fazer?\n\n");
     
     printf("1 - Cadastrar um Aluno.\n"); 
     printf("2 - Listar relacao de alunos.\n");    
     printf("3 - Media aritmetica da classe em uma dada disciplina.\n");    
     printf("4 - Alterar (Cadastro de um aluno).\n");    
     printf("5 - Buscar (Aluno).\n");    
     printf("6 - Sair.\n\n");   
     
     printf("Opcao:");
     fflush(stdin);
     scanf("%d",&op);          
    
     switch(op) {
                case 1: system("cls");
                        fseek(c,0,SEEK_END);
                        fread(&classe,sizeof(ALUNO),1,c);
                        if(ftell(c)/sizeof(ALUNO) > 39){
                        printf("Classe cheia!, Nao e mais possivel cadastrar alunos.\n\n");
                        system("pause");
                        system("cls");               
                        }//Verifica se o arquivo tem mais do que 40 alunos.
                        else Cadastrar(c);
                        break;
                         
                case 2: do{
                         v = 1;
                         system("cls");
                         printf("1 - Por ordem alfabetica.\n"); 
                         printf("2 - Por ordem decrescente de nota.\n"); 
                         printf("3 - Aprovados e Reprovados.\n");
                         printf("4 - Notas obtidas nas provas e trabalhos.\n");
                         printf("5 - Com nota maior do que certo valor.\n");
                         printf("6 - Com nota menor do que certo valor.\n");
                         printf("7 - Com nota num intervalo.\n");
                         printf("8 - Voltar.\n");
                         printf("\n");
                         printf("Opcao:");  
                         fflush(stdin);                  
                         scanf("%d",&op2);
                                          switch(op2) {
                                                      case 1: Listar_Alfabetica(c);
                                                              op2=0;
                                                              break;
                                                      case 2: 
                                                           do{
                                                           v2=1;
                                                           system("cls");
                                                           printf("Escolha a materia:\n");
                                                           printf("\n");
                                                           printf("1 - Matematica.\n");
                                                           printf("2 - Portugues.\n");
                                                           printf("3 - Historia.\n");
                                                           printf("4 - Geografia.\n"); 
                                                           printf("5 - Voltar.\n");
                                                           printf("\n");
                                                           printf("Opcao:");  
                                                           fflush(stdin);                  
                                                           scanf("%d",&op3);
                                                                            switch (op3) {
                                                                                   case 1: Decrescente_Nota(c,0,"MATEMATICA");
                                                                                           op3=0;
                                                                                           break;
                                                                                           
                                                                                   case 2: Decrescente_Nota(c,1,"PORTUGUES");
                                                                                           op3=0;
                                                                                           break;
                                                                                           
                                                                                   case 3: Decrescente_Nota(c,2,"HISTORIA");
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 4: Decrescente_Nota(c,3,"GEOGRAFIA");
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 5: v2=0;
                                                                                           op=0;
                                                                                           op2=0;
                                                                                           op3=0;
                                                                                           break;
                                                                                   default: system("cls");
                                                                                            printf("Opcao invalida!");
                                                                                            puts("\n\n");
                                                                                            system("pause");
                                                                                            break;
                                                                                            } //switch 3                                    
                                                                                   
                                                                                   
                                                                                   
                                                           }while(v2);                                             
                                                           break;
                                                      case 3: 
                                                           do{
                                                           v2 = 1;
                                                           system("cls");
                                                           printf("Escolha a materia:\n");
                                                           printf("\n");
                                                           printf("1 - Matematica.\n");
                                                           printf("2 - Portugues.\n");
                                                           printf("3 - Historia.\n");
                                                           printf("4 - Geografia.\n"); 
                                                           printf("5 - Voltar.\n");
                                                           printf("\n");
                                                           printf("Opcao:");  
                                                           fflush(stdin);                  
                                                           scanf("%d",&op3);
                                                                            switch (op3) {
                                                                                   case 1: Aprovado_Reprovado(c, 0,"MATEMATICA");
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 2: Aprovado_Reprovado(c, 1,"PORTUGUES");
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 3: Aprovado_Reprovado(c, 2,"HISTORIA");
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 4: Aprovado_Reprovado(c, 3,"GEOGRAFIA");
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 5: v2=0;
                                                                                           op=0;
                                                                                           op2=0;
                                                                                           op3=0;
                                                                                        break;
                                                                                   default: system("cls");
                                                                                            printf("Opcao invalida!");
                                                                                            puts("\n\n");
                                                                                            system("pause");
                                                                                            break;
                                                                                            }//switch 3
                                                           }while(v2);
                                                           break;
                                                           
                                                      case 4: system("cls");
                                                              printf("Digite o nome do aluno para visualizar suas notas:");
                                                              fflush(stdin);
                                                              fgets(s,50,stdin);
                                                              Elimina(s);
                                                              if (Buscar_Nome(c,s) != 0){
                                                                  op=0;
                                                                  op2=0;                 
                                                                  system("cls");
                                                                  printf("Aluno encontrado!\n\n");
                                                                  system("pause");
                                                                  Visualiza_Notas_PT(c,Buscar_Nome(c,s));
                                                                  }
                                                               else {
                                                                    op=0;
                                                                    op2=0;
                                                                    system("cls");
                                                                    printf("Aluno NAO encontrado!\n\n");
                                                                    system("pause");
                                                                    }     
                                                                                          
                                                              break;
                                                      case 5: 
                                                           do { 
                                                           v2=1;     
                                                           system("cls");
                                                           printf("Escolha a materia:\n");
                                                           printf("\n");
                                                           printf("1 - Matematica.\n");
                                                           printf("2 - Portugues.\n");
                                                           printf("3 - Historia.\n");
                                                           printf("4 - Geografia.\n"); 
                                                           printf("5 - Voltar.\n");
                                                           printf("\n");
                                                           printf("Opcao:");  
                                                           fflush(stdin);                  
                                                           scanf("%d",&op3);
                                                                            switch (op3) {
                                                                                   case 1: do{
                                                                                           v3=1;
                                                                                           n=-1;
                                                                                           system("cls");
                                                                                           printf("\nDigite o valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n);
                                                                                           if (n>=0 && n<=10){
                                                                                                  v3=0;
                                                                                                  Nota_Maior(c,0,n,"MATEMATICA");                                                                                                    
                                                                                                  }
                                                                                           else {
                                                                                           system("cls");
                                                                                           printf("\nValor nao esta entre 0 a 10!, por favor digite novamente\n\n");  
                                                                                           system("pause"); 
                                                                                           }
                                                                                           }while(v3);             
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 2:do{
                                                                                           v3=1;
                                                                                           n=-1;
                                                                                           system("cls");
                                                                                           printf("\nDigite o valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n);
                                                                                           if (n>=0 && n<=10){
                                                                                                  v3=0;
                                                                                                  Nota_Maior(c,1,n,"PORTUGUES");                                                                                                    
                                                                                                  }
                                                                                           else {
                                                                                           system("cls");
                                                                                           printf("\nValor nao esta entre 0 a 10!, por favor digite novamente\n\n");  
                                                                                           system("pause"); 
                                                                                           }
                                                                                           }while(v3);             
                                                                                           op3=0;
                                                                                           break;;
                                                                                   case 3:do{
                                                                                           v3=1;
                                                                                           n=-1;
                                                                                           system("cls");
                                                                                           printf("\nDigite o valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n);
                                                                                           if (n>=0 && n<=10){
                                                                                                  v3=0;
                                                                                                  Nota_Maior(c,2,n,"HISTORIA");                                                                                                    
                                                                                                  }
                                                                                           else {
                                                                                           system("cls");
                                                                                           printf("\nValor nao esta entre 0 a 10!, por favor digite novamente\n\n");  
                                                                                           system("pause"); 
                                                                                           }
                                                                                           }while(v3);             
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 4:do{
                                                                                           v3=1;
                                                                                           n=-1;
                                                                                           system("cls");
                                                                                           printf("\nDigite o valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n);
                                                                                           if (n>=0 && n<=10){
                                                                                                  v3=0;
                                                                                                  Nota_Maior(c,3,n,"GEOGRAFIA");                                                                                                    
                                                                                                  }
                                                                                           else {
                                                                                           system("cls");
                                                                                           printf("\nValor nao esta entre 0 a 10!, por favor digite novamente\n\n");  
                                                                                           system("pause"); 
                                                                                           }
                                                                                           }while(v3);             
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 5: v2=0;
                                                                                           op=0;
                                                                                           op2=0;
                                                                                           op3=0;
                                                                                        break;
                                                                                   default: system("cls");
                                                                                            printf("Opcao invalida!");
                                                                                            puts("\n\n");
                                                                                            system("pause");
                                                                                            break;
                                                                                            }//switch 3
                                                           }while(v2);                                 
                                                           break;
                                                      case 6:
                                                           do{
                                                           v2=1; 
                                                           system("cls");
                                                           printf("Escolha a materia:\n");
                                                           printf("\n");
                                                           printf("1 - Matematica.\n");
                                                           printf("2 - Portugues.\n");
                                                           printf("3 - Historia.\n");
                                                           printf("4 - Geografia.\n"); 
                                                           printf("5 - Voltar.\n");
                                                           printf("\n");
                                                           printf("Opcao:"); 
                                                           fflush(stdin);                   
                                                           scanf("%d",&op3);
                                                                            switch (op3) {
                                                                                   case 1: do{
                                                                                           v3=1;
                                                                                           n=-1;
                                                                                           system("cls");
                                                                                           printf("\nDigite o valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n);
                                                                                           if (n>=0 && n<=10){
                                                                                                  v3=0;
                                                                                                  Nota_Menor(c,0,n,"MATEMATICA");                                                                                                    
                                                                                                  }
                                                                                           else {
                                                                                           system("cls");
                                                                                           printf("\nValor nao esta entre 0 a 10!, por favor digite novamente\n\n");  
                                                                                           system("pause"); 
                                                                                           }
                                                                                           }while(v3);             
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 2: do{
                                                                                           v3=1;
                                                                                           n=-1;
                                                                                           system("cls");
                                                                                           printf("\nDigite o valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n);
                                                                                           if (n>=0 && n<=10){
                                                                                                  v3=0;
                                                                                                  Nota_Menor(c,1,n,"PORTUGUES");                                                                                                    
                                                                                                  }
                                                                                           else {
                                                                                           system("cls");
                                                                                           printf("\nValor nao esta entre 0 a 10!, por favor digite novamente\n\n");  
                                                                                           system("pause"); 
                                                                                           }
                                                                                           }while(v3);             
                                                                                           op3=0;
                                                                                           break;;
                                                                                   case 3: do{
                                                                                           v3=1;
                                                                                           n=-1;
                                                                                           system("cls");
                                                                                           printf("\nDigite o valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n);
                                                                                           if (n>=0 && n<=10){
                                                                                                  v3=0;
                                                                                                  Nota_Menor(c,2,n,"HISTORIA");                                                                                                    
                                                                                                  }
                                                                                           else {
                                                                                           system("cls");
                                                                                           printf("\nValor nao esta entre 0 a 10!, por favor digite novamente\n\n");  
                                                                                           system("pause"); 
                                                                                           }
                                                                                           }while(v3);             
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 4: do{
                                                                                           v3=1;
                                                                                           n=-1;
                                                                                           system("cls");
                                                                                           printf("\nDigite o valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n);
                                                                                           if (n>=0 && n<=10){
                                                                                                  v3=0;
                                                                                                  Nota_Menor(c,3,n,"GEOGRAFIA");                                                                                                    
                                                                                                  }
                                                                                           else {
                                                                                           system("cls");
                                                                                           printf("\nValor nao esta entre 0 a 10!, por favor digite novamente\n\n");  
                                                                                           system("pause"); 
                                                                                           }
                                                                                           }while(v3);             
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 5: v2=0;
                                                                                           op=0;
                                                                                           op2=0;
                                                                                           op3=0;
                                                                                        break;
                                                                                   default: system("cls");
                                                                                            printf("Opcao invalida!");
                                                                                            puts("\n\n");
                                                                                            system("pause");
                                                                                            break;
                                                                                            }//switch 3
                                                           }while(v2);                                 
                                                           break;
                                                      case 7: 
                                                           do{
                                                           v2=1;
                                                           system("cls");
                                                           printf("Escolha a materia:\n");
                                                           printf("\n");
                                                           printf("1 - Matematica.\n");
                                                           printf("2 - Portugues.\n");
                                                           printf("3 - Historia.\n");
                                                           printf("4 - Geografia.\n"); 
                                                           printf("5 - Voltar.\n");
                                                           printf("\n");
                                                           printf("Opcao:");  
                                                           fflush(stdin);                  
                                                           scanf("%d",&op3);
                                                                            switch (op3) {
                                                                                   case 1: do{
                                                                                           v3=1;
                                                                                           n=-1;
                                                                                           n2=-1;
                                                                                           system("cls");
                                                                                           printf("\nDigite um valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n);
                                                                                           printf("\nDigite outro valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n2);
                                                                                           if ((n>=0 && n<=10) && (n2>=0 && n2<=10)){
                                                                                                  v3=0;
                                                                                                  Nota_Intervalo(c,0,n,n2,"MATEMATICA");                                                                                                    
                                                                                                  }
                                                                                           else {
                                                                                           system("cls");
                                                                                           printf("\nValores nao estao entre 0 a 10!, por favor digite novamente\n\n");  
                                                                                           system("pause"); 
                                                                                           }
                                                                                           }while(v3);             
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 2: do{
                                                                                           v3=1;
                                                                                           n=-1;
                                                                                           n2=-1;
                                                                                           system("cls");
                                                                                           printf("\nDigite um valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n);
                                                                                           printf("\nDigite outro valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n2);
                                                                                           if ((n>=0 && n<=10) && (n2>=0 && n2<=10)){
                                                                                                  v3=0;
                                                                                                  Nota_Intervalo(c,1,n,n2,"PORTUGUES");                                                                                                    
                                                                                                  }
                                                                                           else {
                                                                                           system("cls");
                                                                                           printf("\nValores nao estao entre 0 a 10!, por favor digite novamente\n\n");  
                                                                                           system("pause"); 
                                                                                           }
                                                                                           }while(v3);             
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 3: do{
                                                                                           v3=1;
                                                                                           n=-1;
                                                                                           n2=-1;
                                                                                           system("cls");
                                                                                           printf("\nDigite um valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n);
                                                                                           printf("\nDigite outro valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n2);
                                                                                           if ((n>=0 && n<=10) && (n2>=0 && n2<=10)){
                                                                                                  v3=0;
                                                                                                  Nota_Intervalo(c,2,n,n2,"HISTORIA");                                                                                                    
                                                                                                  }
                                                                                           else {
                                                                                           system("cls");
                                                                                           printf("\nValores nao estao entre 0 a 10!, por favor digite novamente\n\n");  
                                                                                           system("pause"); 
                                                                                           }
                                                                                           }while(v3);             
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 4: do{
                                                                                           v3=1;
                                                                                           n=-1;
                                                                                           n2=-1;
                                                                                           system("cls");
                                                                                           printf("\nDigite um valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n);
                                                                                           printf("\nDigite outro valor(entre 0 a 10):");
                                                                                           fflush(stdin);
                                                                                           scanf("%f",&n2);
                                                                                           if ((n>=0 && n<=10) && (n2>=0 && n2<=10)){
                                                                                                  v3=0;
                                                                                                  Nota_Intervalo(c,3,n,n2,"GEOGRAFIA");                                                                                                    
                                                                                                  }
                                                                                           else {
                                                                                           system("cls");
                                                                                           printf("\nValores nao estao entre 0 a 10!, por favor digite novamente\n\n");  
                                                                                           system("pause"); 
                                                                                           }
                                                                                           }while(v3);             
                                                                                           op3=0;
                                                                                           break;
                                                                                   case 5: v2=0;
                                                                                           op=0;
                                                                                           op2=0;
                                                                                           op3=0;
                                                                                           break;
                                                                                   default: system("cls");
                                                                                            printf("Opcao invalida!");
                                                                                            puts("\n\n");
                                                                                            system("pause");
                                                                                            break;
                                                                                            } //switch 3
                                                           }while(v2);                               
                                                           break;
                                                      case 8: v = 0;
                                                              op=0;
                                                              op2=0;
                                                              break;
                                                      default: system("cls");
                                                               printf("Opcao invalida!");
                                                               puts("\n\n");
                                                               system("pause");
                                                               break;
                                                      
                                                      
                                                      }// switch 2    
                          
                      }while(v);      
                      break;
                case 3: 
                        do{
                        v=1;
                        system("cls");
                        printf("Escolha a materia:\n");
                        printf("\n");
                        printf("1 - Matematica.\n");
                        printf("2 - Portugues.\n");
                        printf("3 - Historia.\n");
                        printf("4 - Geografia.\n"); 
                        printf("5 - Voltar.\n");
                        printf("\n");
                        printf("Opcao:"); 
                        fflush(stdin);                   
                        scanf("%d",&op2);
                                                     switch (op2) {
                                                                case 1: system("cls");
                                                                        printf("Media Aritmetica da classe em Matematica e: %5.2f\n\n",Media_Aritmetica_Classe_Disciplina(c,op2));
                                                                        system("pause");
                                                                        op2=0;                                                                                                                                                                                              
                                                                        break;
                                                                case 2: system("cls");
                                                                        printf("Media Aritmetica da classe em Portugues e: %5.2f\n\n",Media_Aritmetica_Classe_Disciplina(c,op2));
                                                                        system("pause");
                                                                        op2=0; 
                                                                        break;
                                                                case 3: system("cls");
                                                                        printf("Media Aritmetica da classe em Historia e: %5.2f\n\n",Media_Aritmetica_Classe_Disciplina(c,op2));
                                                                        system("pause");
                                                                        op2=0; 
                                                                        break;
                                                                case 4: system("cls");
                                                                        printf("Media Aritmetica da classe em Geografia e: %5.2f\n\n",Media_Aritmetica_Classe_Disciplina(c,op2));
                                                                        system("pause");
                                                                        op2=0;
                                                                        break;
                                                                case 5: v=0;
                                                                        op=0;
                                                                        op2=0;
                                                                     break;
                                                                default: system("cls");
                                                                         printf("Opcao invalida!");
                                                                         puts("\n\n");
                                                                         system("pause");
                                                                         break;
                                                                         }//switch 2
                      }while(v);   
                      break;
                      
                case 4: system("cls");
                        printf("Digite o nome do aluno que deseja alterar o cadastro:");
                        fflush(stdin);
                        gets(s);
                                if (Buscar_Nome(c,s) != 0){
                                   system("cls");
                                   printf("Aluno encontrado!\n\n");
                                   system("pause");
                                   Visualizar(c,Buscar_Nome(c,s));
                                   d = Buscar_Nome(c,s);
                                          do{        
                                                     op=0;                                            
                                                     v=1; 
                                                     system("cls");            
                                                     printf("O que deseja alterar?\n\n");
     
                                                     printf("1 - Nome do aluno.\n"); 
                                                     printf("2 - Sexo do aluno.\n");
                                                     printf("3 - Data de nascimento do aluno.\n");
                                                     printf("4 - Nome do pai.\n");    
                                                     printf("5 - Profissao do pai.\n");    
                                                     printf("6 - Nome da mae.\n");    
                                                     printf("7 - Profissao da mae.\n"); 
                                                     printf("8 - RG do aluno.\n");
                                                     printf("9 - CPF do aluno.\n");
                                                     printf("10 - Celular do aluno.\n");
                                                     printf("11 - Estado civil do aluno.\n");
                                                     printf("12 - Cor dos olhos do aluno.\n");
                                                     printf("13 - Cor dos cabelos do aluno.\n");
                                                     printf("14 - Notas de provas ou trabalhos.\n");
                                                     printf("15 - Voltar.\n\n");
                                                     
                                                     puts("\n");
                                                     printf("Opcao:");   
                                                     fflush(stdin);                 
                                                     scanf("%d",&op);
                                                     switch(op){
                                                                case 1:  Alterar(c,d,1);                                                                       
                                                                         break;//case 1
                                                                         
                                                                case 2:  Alterar(c,d,2); 
                                                                         break;//case 2
                                                                         
                                                                case 3:  Alterar(c,d,3); 
                                                                         break;//case 3
                                                                         
                                                                case 4:  Alterar(c,d,4); 
                                                                         break;//case 4
                                                                         
                                                                case 5:  Alterar(c,d,5); 
                                                                         break;//case 5
                                                                         
                                                                case 6:  Alterar(c,d,6); 
                                                                         break;//case 6
                                                                         
                                                                case 7:  Alterar(c,d,7); 
                                                                         break;//case 7
                                                                         
                                                                case 8:  Alterar(c,d,8); 
                                                                         break;//case 8
                                                                         
                                                                case 9:  Alterar(c,d,9); 
                                                                         break;//case 9
                                                                         
                                                                case 10:  Alterar(c,d,10); 
                                                                         break;//case 10
                                                                         
                                                                case 11:  Alterar(c,d,11); 
                                                                         break;//case 11
                                                                         
                                                                case 12:  Alterar(c,d,12); 
                                                                         break;//case 12
                                                                         
                                                                case 13:  Alterar(c,d,13); 
                                                                          break;//case 13
                                                                                                                                                  
                                                                case 14:  do{
                                                                          v2=1; 
                                                                          system("cls");            
                                                                          printf("1 - Provas.\n"); 
                                                                          printf("2 - Trabalhos.\n");
                                                                          printf("3 - Voltar.\n\n");
                                                                          
                                                                          puts("\n");
                                                                          printf("Opcao:");   
                                                                          fflush(stdin);                 
                                                                          scanf("%d",&op2);
                                                                          
                                                                          switch(op2){
                                                                                      case 1: do{
                                                                                                v3=1;
                                                                                                system("cls");
                                                                                                printf("Escolha a materia:\n");
                                                                                                printf("\n");
                                                                                                printf("1 - Matematica.\n");
                                                                                                printf("2 - Portugues.\n");
                                                                                                printf("3 - Historia.\n");
                                                                                                printf("4 - Geografia.\n"); 
                                                                                                printf("5 - Voltar.\n");
                                                                                                printf("\n");
                                                                                                printf("Opcao:");  
                                                                                                fflush(stdin);                  
                                                                                                scanf("%d",&op3);
                                                                                                                 switch (op3) {
                                                                                                                        case 1: Alterar(c,d,14);
                                                                                                                                op3=0;//Altera notas das provas de matematica
                                                                                                                                break;
                                                                                                                        case 2: Alterar(c,d,15);
                                                                                                                                op3=0;//Altera notas das provas de português 
                                                                                                                                break;
                                                                                                                        case 3: Alterar(c,d,16);
                                                                                                                                op3=0;//Altera notas das provas de história
                                                                                                                                break;
                                                                                                                        case 4: Alterar(c,d,17);
                                                                                                                                op3=0;//Altera notas das provas de geografia
                                                                                                                                break;
                                                                                                                        case 5: v3=0;
                                                                                                                                op=0;
                                                                                                                                op2=0;
                                                                                                                                op3=0;
                                                                                                                                break;
                                                                                                                        default: system("cls");
                                                                                                                                 printf("Opcao invalida!");
                                                                                                                                 puts("\n\n");
                                                                                                                                 system("pause");
                                                                                                                                 break;
                                                                                                                                 } //switch 3
                                                                                                                                                                   
                                                                                               }while(v3);
                                                                                               break;
                                                                                               
                                                                                      case 2:   do{
                                                                                                v3=1;
                                                                                                system("cls");
                                                                                                printf("Escolha a materia:\n");
                                                                                                printf("\n");
                                                                                                printf("1 - Matematica.\n");
                                                                                                printf("2 - Portugues.\n");
                                                                                                printf("3 - Historia.\n");
                                                                                                printf("4 - Geografia.\n"); 
                                                                                                printf("5 - Voltar.\n");
                                                                                                printf("\n");
                                                                                                printf("Opcao:");  
                                                                                                fflush(stdin);                  
                                                                                                scanf("%d",&op3);
                                                                                                                 switch (op3) {
                                                                                                                        case 1: Alterar(c,d,18);
                                                                                                                                op3=0;//Altera notas dos trabalhos de matematica
                                                                                                                                break;
                                                                                                                        case 2: Alterar(c,d,19);
                                                                                                                                op3=0;//Altera notas dos trabalhos de português
                                                                                                                                break;
                                                                                                                        case 3: Alterar(c,d,20);
                                                                                                                                op3=0;//Altera notas dos trabalhos de história
                                                                                                                                break;
                                                                                                                        case 4: Alterar(c,d,21);
                                                                                                                                op3=0;//Altera notas dos trabalhos de geografia
                                                                                                                                break;
                                                                                                                        case 5: v3=0;
                                                                                                                                op=0;
                                                                                                                                op2=0;
                                                                                                                                op3=0;
                                                                                                                                break;
                                                                                                                        default: system("cls");
                                                                                                                                 printf("Opcao invalida!");
                                                                                                                                 puts("\n\n");
                                                                                                                                 system("pause");
                                                                                                                                 break;
                                                                                                                                  } //switch 3
                                                                                                                                                                   
                                                                                               }while(v3);
                                                                                               break;
                                                                                      case 3: v2=0;
                                                                                              op=0;
                                                                                              op2=0;
                                                                                              break;
                                                                                      default:  system("cls");
                                                                                                printf("Opcao invalida!");
                                                                                                puts("\n\n");
                                                                                                system("pause");
                                                                                                break;
                                                                                      }//switch 2
                                                                          }while(v2);
                                                                          break;//case 14
                                                                          
                                                                case 15:  v=0;
                                                                          op=0;
                                                                          break;
                                                                
                                                                default:  system("cls");
                                                                          printf("Opcao invalida!");
                                                                          puts("\n\n");
                                                                          system("pause");
                                                                          break;
                                                                
                                                                
                                                                }//switch
                                            }while(v); 
                                   }//if
                                else {
                                   op=0;
                                   system("cls");
                                   printf("Aluno NAO encontrado!\n\n");
                                   system("pause");
                                   }  
                    
                        
                        break;
                      
                case 5:  
                         do{
                         v2=1;
                         system("cls");
                         printf("1 - Por nome.\n"); 
                         printf("2 - Por RA.\n"); 
                         printf("3 - Voltar.");
                         puts("\n");
                         printf("Opcao:");   
                         fflush(stdin);                 
                         scanf("%d",&op2);
                         
                         switch(op2){
                                     case 1: op2=0;
                                             system("cls");
                                             printf("Digite o nome do aluno:");
                                             fflush(stdin);
                                             gets(s);
                                             if (Buscar_Nome(c,s) != 0){
                                                     system("cls");
                                                     printf("Aluno encontrado!\n\n");
                                                     system("pause");
                                                     Visualizar(c,Buscar_Nome(c,s));
                                                     }
                                                     else {
                                                     system("cls");
                                                     printf("Aluno NAO encontrado!\n\n");
                                                     system("pause");
                                                     }  
                                             break;
                                     case 2: d=0;
                                             op2=0;
                                             do{
                                             system("cls");
                                             cont=1;    
                                             printf("Digite o numero do RA(entre 1 a 40):"); 
                                             fflush(stdin);
                                             scanf("%d",&d);
                                             if (d>0 && d<41){
                                             i = 0;
                                             fseek(c,0,SEEK_END); 
                                             f = ftell(c)/sizeof(ALUNO);
                                             cont = 0;
                                                  if (Buscar_RA(c,d,i,f) == 1){
                                                     system("cls");
                                                     printf("Aluno encontrado!\n\n");
                                                     system("pause");
                                                     Visualizar(c,d);
                                                     }
                                                     else {
                                                     system("cls");
                                                     printf("Aluno NAO encontrado!\n\n");
                                                     system("pause");
                                                     }
                                             }//if do verifica continua
                                             else {
                                                  system("cls");
                                                  printf("Numero de RA invalido!, Por favor digite novamente.");
                                                  puts("\n\n");
                                                  system("pause");
                                                  }
                                             }while(cont);
                                             break;
                                          
                                     case 3: v2=0;
                                             op=0;
                                             op2=0;
                                             break;
                                     default:  system("cls");
                                               printf("Opcao invalida!");
                                               puts("\n\n");
                                               system("pause");
                                               break;  //switch 2   
                                     }
                      }while(v2);               
                      break;
                      
                case 6:  system("cls");
                         fflush(stdin);
                         printf("Deseja realmente sair(S/N)?");
                         op = getchar();
                         if ( op == 'S' || op == 's') {
                         continua = 0;
                         fclose(c);
                         }
                         break;
                     
                default: system("cls");
                         printf("Opcao invalida!");
                         puts("\n\n");
                         system("pause");
                         break;
                }// switch 1
     
              
     }while(continua);
     
}
