#include "Funcoes.h"

///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
short int Verifica_String_Numeros(const char *str){
int i,cont=0;

   
for (i=0; *(str+i)!= '\0';i++){ 
      if( (*(str+i) > 47 && *(str+i) < 58) || (*(str+i)>44 && *(str+i)<47) || (*(str+i)>39 && *(str+i)<42) )
          cont=1;
      else cont=0;
      
      if (cont!=1)
          return(1);
   }
    
return(0);  //Verifica se a string só contém números ou os caracteres  . - ( ) 
} 
///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
short int Verifica_String_Letras(const char *str){
int i,cont=0;

   
for (i=0; *(str+i)!= '\0';i++){ 
      if( (*(str+i) > 64 && *(str+i) < 91) || (*(str+i) > 96 && *(str+i) < 123) || *(str+i)==32 )
          cont=1;
      else cont=0;
      
      if (cont!=1)
          return(1);
   }
    
return(0);  //Verifica se a string só contém letras e espaços
} 
///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void Altera_Nota_Trabalho(FILE *f,int Posicao,int Materia){

int v,op; 

do{
                     v=1;
                     system("cls");
                     printf("\nDigite qual o trabalho que deseja alterar a nota.\n\n");
                     printf("1 - Trabalho 1.\n");
                     printf("2 - Trabalho 2.\n");
                     printf("3 - Trabalho 3.\n");
                     printf("4 - Trabalho 4.\n");
                     printf("5 - Trabalho 5.\n");
                     printf("6 - Trabalho 6.\n"); 
                     printf("7 - Voltar.\n\n");
                     printf("Opcao:");  
                     fflush(stdin);                  
                     scanf("%d",&op);
                             switch(op){
                             case 1: Altera_Nota_Trabalho2(f,(Posicao-1),Materia,0);
                                     op=0;
                                     break;
                             case 2: Altera_Nota_Trabalho2(f,(Posicao-1),Materia,1);
                                     op=0;
                                     break;
                             case 3: Altera_Nota_Trabalho2(f,(Posicao-1),Materia,2);
                                     op=0;
                                     break;
                             case 4: Altera_Nota_Trabalho2(f,(Posicao-1),Materia,3);
                                     op=0;
                                     break;
                             case 5: Altera_Nota_Trabalho2(f,(Posicao-1),Materia,4);
                                     op=0;
                                     break;
                             case 6: Altera_Nota_Trabalho2(f,(Posicao-1),Materia,5);
                                     op=0;
                                     break;                              
                             case 7: v=0;
                                     op=0;
                                     break;         
                             default: system("cls");
                                      printf("Opcao invalida!");
                                      puts("\n\n");
                                      system("pause");
                                      break;
                                                
                             }                     
                     }while(v);   
}       
///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void Altera_Nota_Trabalho2(FILE *f,int Posicao,int Materia,int Trabalho){ 
int i,v; float n,mft,mfp;

do{
        fseek(f,sizeof(ALUNO)*(Posicao),SEEK_SET);
        fread(&classe,sizeof(ALUNO),1,f);
        fseek(f,sizeof(ALUNO)*(Posicao),SEEK_SET);
        n=-1;
        v=1;
                printf("\n\nNota do Trabalho %d:",Trabalho+1);
                fflush(stdin);
                scanf("%f", &n);
                        if(n >= 0 && n <= 10){
                            v=0;
                            classe.disciplina[Materia].trabalho[Trabalho] = n; 
                                                     
                            }
                        else {
                            printf("\n\nNota invalida!, Por favor digite novamente.\n\n");  
                            system("pause");
                            system("cls");
                            }                          
                                         
     }while(v);
     
     ////////////////////////////////////////////////////////////////////////////
     mft=0; 
     for (i=0;i<6;i++)
          mft += classe.disciplina[Materia].trabalho[i]; 
          mft = (mft/6)*0.3;
                                
     mfp=0; 
     for (i=0;i<4;i++)
          mfp += classe.disciplina[Materia].provas[i]; 
          mfp = (mfp/4)*0.7;
                                     
     classe.disciplina[Materia].mf = mft + mfp;  
     ////////////////////////////////////////////////////////////////////////////     
     //Recalcula a media final do aluno em uma matéria, quando é alterado a nota de algum trabalho.
     
     fwrite(&classe,sizeof(ALUNO),1,f);
     Gravacao(f);
}
///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void Altera_Nota_Prova(FILE *f,int Posicao,int Materia){

int v,op;

do{
                     v=1;
                     system("cls");
                     printf("\nDigite qual a prova que deseja alterar a nota.\n\n");
                     printf("1 - Prova 1.\n");
                     printf("2 - Prova 2.\n");
                     printf("3 - Prova 3.\n");
                     printf("4 - Prova 4.\n"); 
                     printf("5 - Voltar.\n\n");
                     printf("Opcao:");  
                     fflush(stdin);                  
                     scanf("%d",&op);
                             switch(op){
                             case 1: Altera_Nota_Prova2(f,(Posicao-1),Materia,0);
                                     op=0;
                                     break;
                             case 2: Altera_Nota_Prova2(f,(Posicao-1),Materia,1);
                                     op=0;
                                     break;
                             case 3: Altera_Nota_Prova2(f,(Posicao-1),Materia,2);
                                     op=0;
                                     break;
                             case 4: Altera_Nota_Prova2(f,(Posicao-1),Materia,3);
                                     op=0;
                                     break;                     
                             case 5: v=0;
                                     op=0;
                                     break;         
                             default: system("cls");
                                      printf("Opcao invalida!");
                                      puts("\n\n");
                                      system("pause");
                                      break;
                                                
                             }                     
                     }while(v);   
}       
///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void Altera_Nota_Prova2(FILE *f,int Posicao,int Materia,int Prova){ 
int v,i; float n,mft,mfp;

do{
        fseek(f,sizeof(ALUNO)*(Posicao),SEEK_SET);
        fread(&classe,sizeof(ALUNO),1,f);
        fseek(f,sizeof(ALUNO)*(Posicao),SEEK_SET);
        n=-1;
        v=1;
                printf("\n\nNota da Prova %d:",Prova+1);
                fflush(stdin);
                scanf("%f", &n);
                        if(n >= 0 && n <= 10){
                            v=0;
                            classe.disciplina[Materia].provas[Prova] = n;     
                            }
                        else {
                            printf("\n\nNota invalida!, Por favor digite novamente.\n\n");  
                            system("pause");
                            system("cls");
                            }                          
                                         
     }while(v);
     
     ////////////////////////////////////////////////////////////////////////////
     mft=0; 
     for (i=0;i<6;i++)
          mft += classe.disciplina[Materia].trabalho[i]; 
          mft = (mft/6)*0.3;
                                
     mfp=0; 
     for (i=0;i<4;i++)
          mfp += classe.disciplina[Materia].provas[i]; 
          mfp = (mfp/4)*0.7;
                                     
     classe.disciplina[Materia].mf = mft + mfp;  
     ////////////////////////////////////////////////////////////////////////////     
     //Recalcula a media final do aluno em uma matéria, quando é alterado a nota de alguma prova.
     
     fwrite(&classe,sizeof(ALUNO),1,f);
     Gravacao(f);
}
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void Elimina (char *str){
   if (*(str+(strlen(str)-1))=='\n')
      *(str+(strlen(str)-1))='\0';      
   //Elimina o caracter \n da função fgets.
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Gravacao(FILE *f){
 if(ferror(f)){
         system("cls");
         printf("\nErro na alteracao do cadastro do aluno!\n\n");
              }
 else {
         system("cls");
         printf("\nAlteracao feita com sucesso!\n\n");
      }
      system("pause");     
     
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Cadastrar (FILE *f){
int cont,d,i,j;
float n,mfp,mft;
char s[50];

do {
   do{
           d=1;    
           cont = 1;
           printf("\nInsira o nome do aluno (somente letras):");
           fflush(stdin);
           fgets(s,50,stdin);
           Elimina(s);
           system("cls");
                         if (Verifica_String_Letras(s)==1){
                             printf("\nO nome digitado contem caracteres diferentes de letras!");
                             printf("\n\nPor favor, digite novamente.\n\n");
                             system("pause");
                             system("cls");
                         }
                         else d=0; 
      }while(d);//do-while interno

                         
              if (Buscar_Nome(f,s) != 0){
                    printf("\nEsse nome ja existe na base de dados!, por favor digite outro nome.\n\n");
                    system("pause");
                    system("cls");
                    
               }
                           
              else {
               cont=0;
               strcpy(classe.Nome,s);
              }
                    
}while(cont); //do-while externo

fseek(f,0,SEEK_END);
classe.RA = (ftell(f)/sizeof(ALUNO))+1;


do{
cont=1;
d=0;
printf("\nDigite o sexo do aluno.");
printf("\n\n1 - Masculino.\n2 - Feminino.\n\n");
printf("Opcao:");
fflush(stdin);
scanf("%d", &d);
system("cls");
              if (d > 0 && d < 3){
                 cont = 0;
                 switch(d){
                           case 1: classe.sexo = masculino;
                                   break;
                           case 2: classe.sexo = feminino;
                                   break;
                           }//switch
                 }//if
                 else {
                       printf("\nOpcao invalida!, Por favor digite novamente.\n\n");
                       system("pause");
                       system("cls");
                       }
}while(cont);

do{  
cont=1;
d=0;
printf("\nDigite a data de nascimento do aluno.");
printf("\n\nDia:");
fflush(stdin);
scanf("%d", &d);
system("cls");
              if (d > 0 && d < 32){
                 cont = 0;
                 classe.data.dia = d;
                 }
              else {
                       printf("\nDia invalido!, Por favor digite novamente.\n\n");
                       system("pause");
                       system("cls");
              }
}while(cont);

do{   
cont=1;
d=0;
printf("\nDigite a data de nascimento do aluno.");
printf("\n\nMes:");
fflush(stdin);
scanf("%d", &d);
system("cls");
              if (d > 0 && d < 13){
              cont = 0;
              switch (d){
                     case 1: classe.data.mes = janeiro;
                             break;
                     case 2: classe.data.mes = fevereiro;
                             break; 
                     case 3: classe.data.mes = marco;
                             break;
                     case 4: classe.data.mes = abril;
                             break;   
                     case 5: classe.data.mes = maio;
                             break;
                     case 6: classe.data.mes = junho;
                             break;  
                     case 7: classe.data.mes = julho;
                             break;
                     case 8: classe.data.mes = agosto;
                             break; 
                     case 9: classe.data.mes = setembro;
                             break;
                     case 10: classe.data.mes = outubro;
                              break; 
                     case 11: classe.data.mes = novembro;
                              break;
                     case 12: classe.data.mes = dezembro;
                              break;     
                              }//switch
                     }//if
                     else {
                       printf("\nMes invalido!, Por favor digite novamente.\n\n");
                       system("pause");
                       system("cls");
                     }
}while(cont); //do-while

do{   
cont=1;
d=0;
printf("\nDigite a data de nascimento do aluno.");
printf("\n\nAno(1950 a 2100):");
fflush(stdin);
scanf("%d", &d);
system("cls");
              if (d > 1949 && d < 2101){
                 cont = 0;
                 classe.data.ano = d;
              }
               else {
                       printf("\nAno invalido!, Por favor digite novamente.\n\n");
                       system("pause");
                       system("cls");
                   }
}while(cont);

do{   
d=1;      
printf("\nDigite o nome completo do Pai (somente letras):");
fflush(stdin);
fgets(classe.Npai,50,stdin);
Elimina(classe.Npai);
system("cls");
                        if(Verifica_String_Letras(classe.Npai)==1){
                             printf("\nO nome digitado contem caracteres diferentes de letras!");
                             printf("\n\nPor favor, digite novamente.\n\n");
                             system("pause");
                             system("cls");
                        }
                        else d=0;                         
}while(d); 

do{   
d=1;
printf("\nDigite a profissao do Pai (somente letras):");
fflush(stdin);
fgets(classe.Ppai,30,stdin);
Elimina(classe.Ppai);
system("cls");
                        if(Verifica_String_Letras(classe.Ppai)==1){
                             printf("\nA profissao digitada contem caracteres diferentes de letras!");
                             printf("\n\nPor favor, digite novamente.\n\n");
                             system("pause");
                             system("cls");
                        }
                        else d=0;                         
}while(d);

do{   
d=1;
printf("\nDigite o nome completo da Mae (somente letras):");
fflush(stdin);
fgets(classe.Nmae,50,stdin);
Elimina(classe.Nmae); 
system("cls");
                        if(Verifica_String_Letras(classe.Nmae)==1){
                             printf("\nO nome digitado contem caracteres diferentes de letras!");
                             printf("\n\nPor favor, digite novamente.\n\n");
                             system("pause");
                             system("cls");
                        }
                        else d=0;                         
}while(d); 
 
 
do{   
d=1;   
printf("\nDigite a profissao da Mae (somente letras):");
fflush(stdin);
fgets(classe.Pmae,30,stdin);
Elimina(classe.Pmae);
system("cls");
                   if(Verifica_String_Letras(classe.Pmae)==1){
                             printf("\nA profissao digitada contem caracteres diferentes de letras!");
                             printf("\n\nPor favor, digite novamente.\n\n");
                             system("pause");
                             system("cls");
                        }
                        else d=0;                         
}while(d);

do{   
d=1;
printf("\nDigite o RG do aluno (somente numeros, ponto e hifen):");
fflush(stdin);
fgets(classe.RG,15,stdin);
Elimina(classe.RG);
system("cls");
                       if(Verifica_String_Numeros(classe.RG)==1){
                             printf("\nO RG digitado contem caracteres diferentes de numeros, ponto e hifen!");
                             printf("\n\nPor favor, digite novamente.\n\n");
                             system("pause");
                             system("cls");
                        }
                        else d=0;                         
}while(d);  
  
do{   
d=1;   
printf("\nDigite o CPF do aluno (somente numeros, ponto e hifen):");
fflush(stdin);
fgets(classe.CPF,20,stdin);
Elimina(classe.CPF);
system("cls");
                       if(Verifica_String_Numeros(classe.CPF)==1){
                             printf("\nO CPF digitado contem caracteres diferentes de numeros, ponto e hifen!");
                             printf("\n\nPor favor, digite novamente.\n\n");
                             system("pause");
                             system("cls");
                        }
                        else d=0;                         
}while(d); 


do{   
d=1;   
printf("\nDigite o Celular do aluno (somente numeros, parenteses e hifen):");
fflush(stdin);
fgets(classe.Celular,15,stdin);
Elimina(classe.Celular);
system("cls");
                        if(Verifica_String_Numeros(classe.Celular)==1){
                             printf("\nO Celular digitado contem caracteres diferentes de numeros, parenteses e hifen!");
                             printf("\n\nPor favor, digite novamente.\n\n");
                             system("pause");
                             system("cls");
                        }
                        else d=0;                         
}while(d); 

do{
cont=1;
d=0;
printf("\nDigite o estado civil do aluno.");
printf("\n\n1 - Solteiro.\n2 - Casado.\n3 - Divorciado.\n4 - Viuvo.\n\n");
printf("Opcao:");
fflush(stdin);
scanf("%d", &d);
system("cls");
              if(d > 0 && d < 5){
              cont = 0;
                   switch (d){
                          case 1: classe.estado_civil = solteiro;
                                  break;
                          case 2: classe.estado_civil = casado;
                                  break; 
                          case 3: classe.estado_civil = divorciado;
                                  break;
                          case 4: classe.estado_civil = viuvo;
                                  break;   
                          }//switch
                   }//if
                   else {
                       printf("\nOpcao invalida!, Por favor digite novamente.\n\n");
                       system("pause");
                       system("cls");
                   }
}while(cont);

do{
cont=1;
d=0;
printf("\nDigite a cor dos olhos do aluno.");
printf("\n\n1 - Castanho.\n2 - Azul.\n3 - Verde.\n\n");
printf("Opcao:");
fflush(stdin);
scanf("%d", &d);
system("cls");
              if(d > 0 && d < 4){
                   cont = 0;
                        switch (d){
                               case 1: classe.cor_olhos = castanho;
                                       break;
                               case 2: classe.cor_olhos = azul;
                                       break; 
                               case 3: classe.cor_olhos = verde;
                                       break;
                               }//switch
                        }//if
                       else {
                       printf("\nOpcao invalida!, Por favor digite novamente.\n\n");
                       system("pause");
                       system("cls");
                       }
}while(cont);

do{
cont=1;
d=0;
printf("\nDigite a cor do cabelo do aluno.");
printf("\n\n1 - Preto.\n2 - Loiro.\n3 - Ruivo.\n4 - Outro.\n\n");
printf("Opcao:");
fflush(stdin);
scanf("%d", &d);
system("cls");
              if(d > 0 && d < 5){
              cont = 0;
                   switch (d){
                          case 1: classe.cor_cabelo = preto;
                                  break;
                          case 2: classe.cor_cabelo = loiro;
                                  break; 
                          case 3: classe.cor_cabelo = ruivo;
                                  break;
                          case 4: classe.cor_cabelo = outro;
                                  break;   
                          }//switch
                   }//if
                   else {
                       printf("\nOpcao invalida!, Por favor digite novamente.\n\n");
                       system("pause");
                       system("cls");
                   }
}while(cont);

system("cls");

printf("\nDigite as notas das Provas de Matematica."); 

for (i=0;i<4;i++){   
  do{  
     n=-1;
     cont=1;                                                                    
     printf("\n\nNota da Prova %d:",i+1);
     fflush(stdin);
     scanf("%f", &n);
            if(n >= 0 && n <= 10){
            cont=0;
            classe.disciplina[0].provas[i] = n;     
            }
            else {
            printf("\n\nNota invalida!, Por favor digite novamente.\n\n");  
            system("pause");
            system("cls");
            }
  }while(cont);
}//for 

system("cls");

printf("\nDigite as notas dos Trabalhos de Matematica."); 

for (i=0;i<6;i++){   
  do{  
     n=-1;
     cont=1;                                                                    
     printf("\n\nNota do Trabalho %d:",i+1);
     fflush(stdin);
     scanf("%f", &n);
            if(n >= 0 && n <= 10){
            cont=0;
            classe.disciplina[0].trabalho[i]=n;     
            }
            else {
            printf("\n\nNota invalida!, Por favor digite novamente.\n\n");  
            system("pause");
            system("cls");
            }
  }while(cont);
}//for 

system("cls");

printf("\nDigite as notas das Provas de Portugues."); 

for (i=0;i<4;i++){   
  do{  
     n=-1;
     cont=1;                                                                    
     printf("\n\nNota da Prova %d:",i+1);
     fflush(stdin);
     scanf("%f", &n);
            if(n >= 0 && n <= 10){
            cont=0;
            classe.disciplina[1].provas[i]=n;     
            }
            else {
            printf("\n\nNota invalida!, Por favor digite novamente.\n\n");  
            system("pause");
            system("cls");
            }
  }while(cont);
}//for

system("cls");

printf("\nDigite as notas dos Trabalhos de Portugues."); 

for (i=0;i<6;i++){   
  do{  
     n=-1;
     cont=1;                                                                    
     printf("\n\nNota do Trabalho %d:",i+1);
     fflush(stdin);
     scanf("%f", &n);
            if(n >= 0 && n <= 10){
            cont=0;
            classe.disciplina[1].trabalho[i]=n;     
            }
            else {
            printf("\n\nNota invalida!, Por favor digite novamente.\n\n");  
            system("pause");
            system("cls");
            }
  }while(cont);
}//for 

system("cls");

printf("\nDigite as notas das Provas de Historia."); 

for (i=0;i<4;i++){   
  do{  
     n=-1;
     cont=1;                                                                    
     printf("\n\nNota da Prova %d:",i+1);
     fflush(stdin);
     scanf("%f", &n);
            if(n >= 0 && n <= 10){
            cont=0;
            classe.disciplina[2].provas[i]=n;     
            }
            else {
            printf("\n\nNota invalida!, Por favor digite novamente.\n\n");  
            system("pause");
            system("cls");
            }
  }while(cont);
}//for

system("cls");

printf("\nDigite as notas dos Trabalhos de Historia."); 

for (i=0;i<6;i++){   
  do{  
     n=-1;
     cont=1;                                                                    
     printf("\n\nNota do Trabalho %d:",i+1);
     fflush(stdin);
     scanf("%f", &n);
            if(n >= 0 && n <= 10){
            cont=0;
            classe.disciplina[2].trabalho[i]=n;     
            }
            else {
            printf("\n\nNota invalida!, Por favor digite novamente.\n\n");  
            system("pause");
            system("cls");
            }
  }while(cont);
}//for 

system("cls");

printf("\nDigite as notas das Provas de Geografia."); 

for (i=0;i<4;i++){   
  do{  
     n=-1;
     cont=1;                                                                    
     printf("\n\nNota da Prova %d:",i+1);
     fflush(stdin);
     scanf("%f", &n);
            if(n >= 0 && n <= 10){
            cont=0;
            classe.disciplina[3].provas[i]=n;     
            }
            else {
            printf("\n\nNota invalida!, Por favor digite novamente.\n\n");  
            system("pause");
            system("cls");
            }
  }while(cont);
}//for

system("cls");

printf("\nDigite as notas dos Trabalhos de Geografia."); 

for (i=0;i<6;i++){   
  do{  
     n=-1;
     cont=1;                                                                    
     printf("\n\nNota do Trabalho %d:",i+1);
     fflush(stdin);
     scanf("%f", &n);
            if(n >= 0 && n <= 10){
            cont=0;
            classe.disciplina[3].trabalho[i]=n;     
            }
            else {
            printf("\n\nNota invalida!, Por favor digite novamente.\n\n");  
            system("pause");
            system("cls");
            }
  }while(cont);
}//for 
 
system("cls");

for(j=0; j < 4; j++){
mfp=0; 
       for (i=0;i<4;i++)
           mfp += classe.disciplina[j].provas[i]; 
           mfp = (mfp/4)*0.7;

mft=0; 
        for (i=0;i<6;i++)
           mft += classe.disciplina[j].trabalho[i]; 
           mft = (mft/6)*0.3;

           classe.disciplina[j].mf = mfp + mft; 
} // calcula media das disciplinas


fwrite(&classe,sizeof(ALUNO),1,f);

if(ferror(f))
     printf("\nErro ao cadastrar aluno!\n\n");
else 
     printf("\nAluno cadastrado com sucesso!\n\n");
     
     system("pause");
     
puts("\n");

}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Visualizar (FILE *f, int RA){
char s[15];
int d;
fseek(f,sizeof(ALUNO)*(RA-1),SEEK_SET);       
fread(&classe,sizeof(ALUNO),1,f); 
system("cls");   
printf("##########################################################################\n"); 
printf("##########################################################################");
printf("\n\n");
printf("                          CADASTRO DO ALUNO           RA: %d",classe.RA);
printf("\n\n");
printf("##########################################################################");
printf("\n\n");
printf("   Nome completo: %s   ", classe.Nome);
printf("\n\n");
d = classe.sexo;   
if (d == 1)
    strcpy(s,"Masculino");       
else strcpy(s,"Feminino"); 
printf("   Sexo: %s", s); //imprimir o sexo da struct que é um enum;                                                             
printf("\n\n");
printf("   Data de Nascimento: %d/%d/%d",classe.data.dia,classe.data.mes,classe.data.ano);
printf("\n\n");
printf("   RG: %s", classe.RG);
printf("\n\n");  
printf("   CPF: %s", classe.CPF);   
printf("\n\n");                            
printf("   Nome do Pai: %s", classe.Npai);
printf("\n\n");
printf("   Profissao do Pai: %s", classe.Ppai);
printf("\n\n");
printf("   Nome da Mae: %s", classe.Nmae);
printf("\n\n");
printf("   Profissao da Mae: %s", classe.Pmae);
printf("\n\n");
d = classe.cor_olhos;
switch(d){
          case 1:strcpy(s,"Castanho"); 
                 break;
          case 2:strcpy(s,"Azul"); 
                 break;
          case 3: strcpy(s,"Verde"); 
                  break;    
          }
printf("   Cor dos olhos: %s",s);//imprimir a cor dos olhos da struct que é um enum; 
printf("\n\n");
d = classe.cor_cabelo;
switch(d){
          case 1:strcpy(s,"Preto"); 
                 break;
          case 2:strcpy(s,"Loiro"); 
                 break;
          case 3: strcpy(s,"Ruivo"); 
                  break;   
          case 4: strcpy(s,"Outro"); 
                  break;  
          }
printf("   Cor dos cabelos: %s",s);//imprimir a cor dos cabelos da struct que é um enum; 
printf("\n\n");
d = classe.estado_civil;
switch(d){
          case 1:strcpy(s,"Solteiro"); 
                 break;
          case 2:strcpy(s,"Casado"); 
                 break;
          case 3: strcpy(s,"Divorciado"); 
                  break;   
          case 4: strcpy(s,"Viuvo"); 
                  break;  
          }
printf("   Estado Civil: %s",s);//imprimir o estado civil da struct que é um enum; 
printf("\n\n");
printf("   Celular: %s",classe.Celular);
printf("\n\n");
printf("##########################################################################\n");
printf("\n");
system("pause");     
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
short int Buscar_RA (FILE *f,int RA, int ini, int fim){

int meio = (ini+fim)/2;
   
    if (ini>fim)
       return(0);
      else if(RA==meio)
         return(1);
        else if (RA < meio)
            return(Buscar_RA (f,RA, ini, meio-1));
         else return(Buscar_RA (f,RA, meio+1, fim));
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
short int Buscar_Nome(FILE *f, char *Nome){

fseek(f,0,SEEK_SET); 
do{
       
      fread(&classe,sizeof(ALUNO),1,f);
      
      if(stricmp(classe.Nome, Nome) == 0)
           return(ftell(f)/sizeof(ALUNO));
      
}while(!feof(f));
return(0);     
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
float Media_Aritmetica_Classe_Disciplina(FILE *f, int Numero_materia){
     
int s,i; float mf=0;
    
    fseek(f,0,SEEK_END);
    i = ftell(f)/sizeof(ALUNO);
    fseek(f,0,SEEK_SET);
    
        for(s=0; s < i; s++){
                fread(&classe,sizeof(ALUNO),1,f);
                mf += classe.disciplina[Numero_materia-1].mf;
          } 
      mf = mf/s;
      return(mf);    
}
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////// 
void Alterar(FILE *f, int posicao, int opcao){

int op,d,v,v2; float n; char s[50];

fseek(f,sizeof(ALUNO)*(posicao-1),SEEK_SET);
fread(&classe,sizeof(ALUNO),1,f);
fseek(f,sizeof(ALUNO)*(posicao-1),SEEK_SET);

switch(opcao){
           case 1: do{
                      do{
                         d=1;    
                         v=1;
                         system("cls");
                         printf("\nInsira o nome do aluno (somente letras):");
                         fflush(stdin);
                         fgets(s,50,stdin);
                         Elimina(s);
                         system("cls");
                                       if (Verifica_String_Letras(s)==1){
                                           printf("\nO nome digitado contem caracteres diferentes de letras!");
                                           printf("\n\nPor favor, digite novamente.\n\n");
                                           system("pause");
                                           system("cls");
                                           }
                                       else d=0; 
                         }while(d);//do-while interno
                   
                    if (Buscar_Nome(f,s) != 0){
                       system("cls");                  
                       printf("\nEsse nome ja existe na base de dados!, por favor digite outro nome.\n\n");
                       system("pause");
                       }
                
                
                    else{
                         v=0;
                         fseek(f,sizeof(ALUNO)*(posicao-1),SEEK_SET);
                         fread(&classe,sizeof(ALUNO),1,f);
                         fseek(f,sizeof(ALUNO)*(posicao-1),SEEK_SET);
                         strcpy(classe.Nome,s);
                         fwrite(&classe,sizeof(ALUNO),1,f);
                         Gravacao(f);       
                         }//else
                                                    
                      }while(v); //do-while externo
                    break;
                       
                       
               case 2: do{
                       v=1;
                       system("cls");
                       printf("\nDigite o sexo do aluno.");
                       printf("\n\n1 - Masculino.\n2 - Feminino.\n\n");
                       printf("Opcao:");
                       fflush(stdin);
                       scanf("%d", &d);
                       if (d > 0 && d < 3){
                       v=0;
                                switch(d){
                                          case 1: classe.sexo = masculino;
                                                  fwrite(&classe,sizeof(ALUNO),1,f);
                                                  Gravacao(f);    
                                                  break;
                                                       
                                          case 2: classe.sexo = feminino;
                                                  fwrite(&classe,sizeof(ALUNO),1,f);
                                                  Gravacao(f);
                                                  break;
                                           }//switch
                                 }//if
                       else {
                              system("cls");     
                              printf("\nOpcao invalida!, Por favor digite novamente.\n\n");
                              system("pause");
                            }
                       }while(v);
                       break; 
                       
               case 3: do{
                       v=1;
                       system("cls");
                       printf("\nDigite a data de nascimento.");
                       do {
                           v2=1;
                           printf("\n\nDia:");
                           fflush(stdin);
                           scanf("%d", &d);
                           if (d > 0 && d < 32){
                                v2=0;
                                classe.data.dia = d;
                                }
                           else {
                                printf("\n\nDia invalido!, Por favor digite novamente.\n\n");
                                system("pause");
                                system("cls");
                                }
                           }while(v2);
                           
                       do {
                           v2=1;
                           system("cls");
                           printf("\n\nMes:");
                           fflush(stdin);
                           scanf("%d", &d);
                           system("cls");
                                          if (d > 0 && d < 13){
                                          v2 = 0;
                                          switch (d){
                                                     case 1: classe.data.mes = janeiro;
                                                             break;
                                                     case 2: classe.data.mes = fevereiro;
                                                             break; 
                                                     case 3: classe.data.mes = marco;
                                                             break;
                                                     case 4: classe.data.mes = abril;
                                                             break;   
                                                     case 5: classe.data.mes = maio;
                                                             break;
                                                     case 6: classe.data.mes = junho;
                                                             break;  
                                                     case 7: classe.data.mes = julho;
                                                             break;
                                                     case 8: classe.data.mes = agosto;
                                                             break; 
                                                     case 9: classe.data.mes = setembro;
                                                             break;
                                                     case 10: classe.data.mes = outubro;
                                                              break; 
                                                     case 11: classe.data.mes = novembro;
                                                              break;
                                                     case 12: classe.data.mes = dezembro;
                                                               break;     
                                                     }//switch
                                                   }//if
                                           else {
                                                printf("\n\nMes invalido!, Por favor digite novamente.\n\n");
                                                system("pause");
                                                system("cls");
                                                }
                                     }while(v2);
                           do{
                               v2=1;
                               printf("\n\nAno(1950 a 2100):");
                               fflush(stdin);
                               scanf("%d", &d);
                               system("cls");
                                              if (d > 1949 && d < 2101){
                                                   v2 = 0;
                                                   classe.data.ano = d;
                                                   }
                                              else {
                                                   printf("\n\nAno invalido!, Por favor digite novamente.\n\n");
                                                   system("pause");
                                                   system("cls");
                                                   }          
                             }while(v2);  
                             v=0;        
                             fwrite(&classe,sizeof(ALUNO),1,f);
                             Gravacao(f);
                       }while(v);
                       break; //case 3
                       
             case 4: do{
                     d=1;
                     system("cls");
                     printf("\nDigite o nome completo do Pai (somente letras):");
                     fflush(stdin);
                     fgets(classe.Npai,50,stdin);
                     Elimina(classe.Npai);
                          if(Verifica_String_Letras(classe.Npai)==1){
                                          printf("\nO nome digitado contem caracteres diferentes de letras!");
                                          printf("\n\nPor favor, digite novamente.\n\n");
                                          system("pause");
                                          system("cls");
                               }
                           else d=0;                         
                     }while(d);
                     fwrite(&classe,sizeof(ALUNO),1,f);
                     Gravacao(f);
                     break;  //case 4 
                     
             case 5: do{   
                       d=1;
                       system("cls");
                       printf("\nDigite a profissao do Pai (somente letras):");
                       fflush(stdin);
                       fgets(classe.Ppai,30,stdin);
                       Elimina(classe.Ppai);
                       system("cls");
                           if(Verifica_String_Letras(classe.Ppai)==1){
                                printf("\nA profissao digitada contem caracteres diferentes de letras!");
                                printf("\n\nPor favor, digite novamente.\n\n");
                                system("pause");
                                system("cls");
                            }
                        else d=0;                         
                     }while(d);
                     fwrite(&classe,sizeof(ALUNO),1,f);
                     Gravacao(f);
                     break; //case 5
              
             case 6: do{
                     d=1;
                     system("cls");
                     printf("\nDigite o nome completo da Mae (somente letras):");
                     fflush(stdin);
                     fgets(classe.Nmae,50,stdin);
                     Elimina(classe.Nmae); 
                     system("cls");
                        if(Verifica_String_Letras(classe.Nmae)==1){
                             printf("\nO nome digitado contem caracteres diferentes de letras!");
                             printf("\n\nPor favor, digite novamente.\n\n");
                             system("pause");
                             system("cls");
                        }
                        else d=0;                         
                     }while(d);
                     fwrite(&classe,sizeof(ALUNO),1,f);
                     Gravacao(f);
                     break; //case 6
                     
             case 7: do{
                     d=1;
                     system("cls");
                     printf("\nDigite a profissao da Mae (somente letras):");
                     fflush(stdin);
                     fgets(classe.Pmae,30,stdin);
                     Elimina(classe.Pmae);
                     system("cls");
                         if(Verifica_String_Letras(classe.Pmae)==1){
                               printf("\nA profissao digitada contem caracteres diferentes de letras!");
                               printf("\n\nPor favor, digite novamente.\n\n");
                               system("pause");
                              system("cls");
                          }
                         else d=0;                         
                     }while(d);
                     fwrite(&classe,sizeof(ALUNO),1,f);
                     Gravacao(f);
                     break; //case 7
                     
             case 8: do{
                     d=1;
                     system("cls");
                     printf("\nDigite o RG do aluno (somente numeros, ponto e hifen):");
                     fflush(stdin);
                     fgets(classe.RG,15,stdin);
                     Elimina(classe.RG);
                     system("cls");
                        if(Verifica_String_Numeros(classe.RG)==1){
                              printf("\nO RG digitado contem caracteres diferentes de numeros, ponto e hifen!");
                              printf("\n\nPor favor, digite novamente.\n\n");
                              system("pause");
                              system("cls");
                         }
                        else d=0;                         
                     }while(d);
                     fwrite(&classe,sizeof(ALUNO),1,f);
                     Gravacao(f);
                     break; //case 8
              
             case 9: do{
                     d=1;
                     system("cls");
                     printf("\nDigite o CPF do aluno (somente numeros, ponto e hifen):");
                     fflush(stdin);
                     fgets(classe.CPF,20,stdin);
                     Elimina(classe.CPF);
                     system("cls");
                         if(Verifica_String_Numeros(classe.CPF)==1){
                               printf("\nO CPF digitado contem caracteres diferentes de numeros, ponto e hifen!");
                               printf("\n\nPor favor, digite novamente.\n\n");
                               system("pause");
                               system("cls");
                          }
                        else d=0;                         
                     }while(d); 
                     fwrite(&classe,sizeof(ALUNO),1,f);
                     Gravacao(f);
                     break; //case 9
                     
             case 10: do{
                      d=1;
                      system("cls");
                      printf("\nDigite o Celular do aluno (somente numeros, parenteses e hifen):");
                      fflush(stdin);
                      fgets(classe.Celular,15,stdin);
                      Elimina(classe.Celular);
                      system("cls");
                          if(Verifica_String_Numeros(classe.Celular)==1){
                               printf("\nO Celular digitado contem caracteres diferentes de numeros, parenteses e hifen!");
                               printf("\n\nPor favor, digite novamente.\n\n");
                               system("pause");
                               system("cls");
                           }
                         else d=0;                         
                      }while(d);
                      fwrite(&classe,sizeof(ALUNO),1,f);
                      Gravacao(f);
                      break; //case 10
                     
             case 11: do{
                      v=1;
                      system("cls");
                      printf("\nDigite o estado civil do aluno.");
                      printf("\n\n1 - Solteiro.\n2 - Casado.\n3 - Divorciado.\n4 - Viuvo.\n\n");
                      printf("Opcao:");
                      fflush(stdin);
                      scanf("%d", &d);
                      system("cls");
                                    if(d > 0 && d < 5){
                                         v=0;
                                               switch (d){
                                                      case 1: classe.estado_civil = solteiro;
                                                              break;
                                                      case 2: classe.estado_civil = casado;
                                                              break; 
                                                      case 3: classe.estado_civil = divorciado;
                                                              break;
                                                      case 4: classe.estado_civil = viuvo;
                                                              break;   
                                                          }//switch
                                                        }//if
                                    else {
                                         printf("\n\nOpcao invalida!, Por favor digite novamente.\n\n");
                                         system("pause");
                                         system("cls");
                                         }  
                      }while(v);
                      fwrite(&classe,sizeof(ALUNO),1,f);
                      Gravacao(f);  
                      break;  //case 11
                      
           case 12: do{
                      v=1;
                      system("cls");
                      printf("\nDigite a cor dos olhos do aluno.");
                      printf("\n\n1 - Castanho.\n2 - Azul.\n3 - Verde.\n\n");
                      printf("Opcao:");
                      fflush(stdin);
                      scanf("%d", &d);
                      system("cls");
                                    if(d > 0 && d < 4){
                                         v=0;
                                               switch (d){
                                                      case 1: classe.cor_olhos = castanho;
                                                              break;
                                                      case 2: classe.cor_olhos = azul;
                                                              break; 
                                                      case 3: classe.cor_olhos = verde;
                                                              break;   
                                                          }//switch
                                                }//if
                                    else {
                                         printf("\n\nOpcao invalida!, Por favor digite novamente.\n\n");
                                         system("pause");
                                         system("cls");
                                         }  
                      }while(v);
                      fwrite(&classe,sizeof(ALUNO),1,f);
                      Gravacao(f);  
                      break;  //case 12
                      
           case 13: do{
                      v=1;
                      system("cls");
                      printf("\nDigite cor dos cabelos do aluno.");
                      printf("\n\n1 - Preto.\n2 - Loiro.\n3 - Ruivo.\n4 - Outro.\n\n");
                      printf("Opcao:");
                      fflush(stdin);
                      scanf("%d", &d);
                      system("cls");
                                    if(d > 0 && d < 5){
                                         v=0;
                                               switch (d){
                                                      case 1: classe.cor_cabelo = preto;
                                                              break;
                                                      case 2: classe.cor_cabelo = loiro;
                                                              break; 
                                                      case 3: classe.cor_cabelo = ruivo;
                                                              break;
                                                      case 4: classe.cor_cabelo = outro;
                                                              break;   
                                                          }//switch
                                                      }//if
                                    else {
                                         printf("\n\nOpcao invalida!, Por favor digite novamente.\n\n");
                                         system("pause");
                                         system("cls");
                                         }  
                      }while(v);
                      fwrite(&classe,sizeof(ALUNO),1,f);
                      Gravacao(f);  
                      break;  //case 13
                      
           case 14:  Altera_Nota_Prova(f,posicao,0);
                     opcao=0; //Altera notas das provas de matematica                   
                     break;
           case 15:  Altera_Nota_Prova(f,posicao,1);
                     opcao=0; //Altera notas das provas de português                   
                     break;  
           case 16:  Altera_Nota_Prova(f,posicao,2);
                     opcao=0; //Altera notas das provas de história                   
                     break;
           case 17:  Altera_Nota_Prova(f,posicao,3);
                     opcao=0; //Altera notas das provas de geografia                   
                     break;
           case 18:  Altera_Nota_Trabalho(f,posicao,0);
                     opcao=0; //Altera notas dos trabalhos de matematica                   
                     break;
           case 19:  Altera_Nota_Trabalho(f,posicao,1);
                     opcao=0; //Altera notas dos trabalhos de português                   
                     break;  
           case 20:  Altera_Nota_Trabalho(f,posicao,2);
                     opcao=0; //Altera notas dos trabalhos de história                   
                     break;
           case 21:  Altera_Nota_Trabalho(f,posicao,3);
                     opcao=0; //Altera notas dos trabalhos de geografia                   
                     break;                                                         
           }//switch externo                    
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Visualiza_Notas_PT(FILE *f, int RA){

int d;
fseek(f,sizeof(ALUNO)*(RA-1),SEEK_SET);       
fread(&classe,sizeof(ALUNO),1,f);

system("cls");      
printf("##########################################################################");
printf("\n\n");
printf("    RA: %d",classe.RA);
printf("\n\n");
printf("    NOME: %s",classe.Nome);
printf("\n\n");
printf("##########################################################################");
printf("\n\n");
printf("                               MATEMATICA ");
printf("\n\n\n\n");                                             
printf("                             PROVAS  NOTAS");
printf("\n\n\n");
printf("    Prova 1: %5.2f",classe.disciplina[0].provas[0]);
printf("\n\n");
printf("\n    Prova 2: %5.2f",classe.disciplina[0].provas[1]);
printf("\n\n");
printf("\n    Prova 3: %5.2f",classe.disciplina[0].provas[2]);
printf("\n\n");
printf("\n    Prova 4: %5.2f",classe.disciplina[0].provas[3]);
printf("\n\n\n");
printf("                             TRABALHOS NOTAS");
printf("\n\n\n");
printf("    Trabalho 1: %5.2f",classe.disciplina[0].trabalho[0]);
printf("\n\n");
printf("\n    Trabalho 2: %5.2f",classe.disciplina[0].trabalho[1]);
printf("\n\n");
printf("\n    Trabalho 3: %5.2f",classe.disciplina[0].trabalho[2]);
printf("\n\n");
printf("\n    Trabalho 4: %5.2f",classe.disciplina[0].trabalho[3]);
printf("\n\n");
printf("\n    Trabalho 5: %5.2f",classe.disciplina[0].trabalho[4]);
printf("\n\n");
printf("\n    Trabalho 6: %5.2f",classe.disciplina[0].trabalho[5]);
printf("\n\n\n");
printf("                              MEDIA FINAL: %5.2f",classe.disciplina[0].mf);
printf("\n\n\n");
printf("**************************************************************************");
printf("\n\n");
printf("                               PORTUGUES ");
printf("\n\n\n\n");                                             
printf("                             PROVAS  NOTAS");
printf("\n\n\n");
printf("    Prova 1: %5.2f",classe.disciplina[1].provas[0]);
printf("\n\n");
printf("\n    Prova 2: %5.2f",classe.disciplina[1].provas[1]);
printf("\n\n");
printf("\n    Prova 3: %5.2f",classe.disciplina[1].provas[2]);
printf("\n\n");
printf("\n    Prova 4: %5.2f",classe.disciplina[1].provas[3]);
printf("\n\n\n");
printf("                             TRABALHOS NOTAS");
printf("\n\n\n");
printf("    Trabalho 1: %5.2f",classe.disciplina[1].trabalho[0]);
printf("\n\n");
printf("\n    Trabalho 2: %5.2f",classe.disciplina[1].trabalho[1]);
printf("\n\n");
printf("\n    Trabalho 3: %5.2f",classe.disciplina[1].trabalho[2]);
printf("\n\n");
printf("\n    Trabalho 4: %5.2f",classe.disciplina[1].trabalho[3]);
printf("\n\n");
printf("\n    Trabalho 5: %5.2f",classe.disciplina[1].trabalho[4]);
printf("\n\n");
printf("\n    Trabalho 6: %5.2f",classe.disciplina[1].trabalho[5]);
printf("\n\n\n");
printf("                              MEDIA FINAL: %5.2f",classe.disciplina[1].mf);
printf("\n\n\n");
printf("**************************************************************************");
printf("\n\n");
printf("                               HISTORIA ");
printf("\n\n\n\n");                                             
printf("                             PROVAS  NOTAS");
printf("\n\n\n");
printf("    Prova 1: %5.2f",classe.disciplina[2].provas[0]);
printf("\n\n");
printf("\n    Prova 2: %5.2f",classe.disciplina[2].provas[1]);
printf("\n\n");
printf("\n    Prova 3: %5.2f",classe.disciplina[2].provas[2]);
printf("\n\n");
printf("\n    Prova 4: %5.2f",classe.disciplina[2].provas[3]);
printf("\n\n\n");
printf("                             TRABALHOS NOTAS");
printf("\n\n\n");
printf("    Trabalho 1: %5.2f",classe.disciplina[2].trabalho[0]);
printf("\n\n");
printf("\n    Trabalho 2: %5.2f",classe.disciplina[2].trabalho[1]);
printf("\n\n");
printf("\n    Trabalho 3: %5.2f",classe.disciplina[2].trabalho[2]);
printf("\n\n");
printf("\n    Trabalho 4: %5.2f",classe.disciplina[2].trabalho[3]);
printf("\n\n");
printf("\n    Trabalho 5: %5.2f",classe.disciplina[2].trabalho[4]);
printf("\n\n");
printf("\n    Trabalho 6: %5.2f",classe.disciplina[2].trabalho[5]);
printf("\n\n\n");
printf("                              MEDIA FINAL: %5.2f",classe.disciplina[2].mf);
printf("\n\n\n");
printf("**************************************************************************");
printf("\n\n");
printf("                               GEOGRAFIA ");
printf("\n\n\n\n");                                             
printf("                             PROVAS  NOTAS");
printf("\n\n\n");
printf("    Prova 1: %5.2f",classe.disciplina[3].provas[0]);
printf("\n\n");
printf("\n    Prova 2: %5.2f",classe.disciplina[3].provas[1]);
printf("\n\n");
printf("\n    Prova 3: %5.2f",classe.disciplina[3].provas[2]);
printf("\n\n");
printf("\n    Prova 4: %5.2f",classe.disciplina[3].provas[3]);
printf("\n\n\n");
printf("                             TRABALHOS NOTAS");
printf("\n\n\n");
printf("    Trabalho 1: %5.2f",classe.disciplina[3].trabalho[0]);
printf("\n\n");
printf("\n    Trabalho 2: %5.2f",classe.disciplina[3].trabalho[1]);
printf("\n\n");
printf("\n    Trabalho 3: %5.2f",classe.disciplina[3].trabalho[2]);
printf("\n\n");
printf("\n    Trabalho 4: %5.2f",classe.disciplina[3].trabalho[3]);
printf("\n\n");
printf("\n    Trabalho 5: %5.2f",classe.disciplina[3].trabalho[4]);
printf("\n\n");
printf("\n    Trabalho 6: %5.2f",classe.disciplina[3].trabalho[5]);
printf("\n\n\n");
printf("                              MEDIA FINAL: %5.2f",classe.disciplina[3].mf);
printf("\n\n\n");
printf("##########################################################################\n"); 
printf("##########################################################################\n\n");     
system("pause");     
}  
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////   
void Decrescente_Nota(FILE *f, int Materia, const char *str){

typedef struct{  
    float media;
    char nome[50];
    int RA;       
}info;

int i,j; info a[40], temp;


fseek(f,0,SEEK_SET);   
       system("cls");
       
       for (i=0; !feof(f);i++){
         fread(&classe,sizeof(ALUNO),1,f);             
         a[i].media = classe.disciplina[Materia].mf;
         strcpy(a[i].nome ,classe.Nome);
         a[i].RA = classe.RA;
       } //array com todos os alunos e suas médias 
       
    
      for(i=1; i < ftell(f)/sizeof(ALUNO);i++)
         for(j=0; j <((ftell(f)/sizeof(ALUNO))-i); j++){
             if (a[j].media < a[j+1].media) { 
                 temp.media = a[j].media ;          
                 strcpy (temp.nome ,a[j].nome);
                 temp.RA = a[j].RA;
                 
                 a[j].media = a[j+1].media;         
                 strcpy (a[j].nome, a[j+1].nome);
                 a[j].RA = a[j+1].RA;
                 
                 a[j+1].media = temp.media;       
                 strcpy (a[j+1].nome , temp.nome);
                 a[j+1].RA = temp.RA;
             }  //if
         }//Bubblesort        
     
        
      printf("#############################################################################");
      printf("\n\n");
      printf("            NOTA DOS ALUNOS EM ORDEM DECRESCENTE EM %s", str);
      printf("\n\n");
      printf("#############################################################################\n");
      
      
       for(i=0; i < ftell(f)/sizeof(ALUNO);i++){
         printf("\nRA: %d\n\n", a[i].RA);  
         printf("Nome: %s\n\n", a[i].nome);
         printf("Nota: %5.2f\n\n", a[i].media);
         printf("-----------------------------------------------------------------------------\n");
      }    
      system("pause");  
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Nota_Maior(FILE *f,int Materia, float valor, const char *Nome_materia){

int i,j,v=0;   

system("cls"); 
      printf("#############################################################################");
      printf("\n\n");
      printf("            ALUNOS EM %s COM NOTA MAIOR QUE %5.2f",Nome_materia, valor);
      printf("\n\n");
      printf("#############################################################################\n");

fseek(f,0,SEEK_END);
j=ftell(f)/sizeof(ALUNO);
fseek(f,0,SEEK_SET);

for(i=0; i < j;i++){
    fread(&classe,sizeof(ALUNO),1,f);
       if(classe.disciplina[Materia].mf > valor){
         printf("\nRA: %d\n\n", classe.RA);  
         printf("Nome: %s\n\n", classe.Nome);
         printf("Nota: %5.2f\n\n", classe.disciplina[Materia].mf);
         printf("-----------------------------------------------------------------------------\n");
         v=1;
         }
    } 
    if (v==0)
    printf("\n\n\nNenhum aluno teve nota maior que %5.2f em %s\n\n\n", valor,Nome_materia);
system("pause");       
     
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Nota_Menor(FILE *f,int Materia, float valor, const char *Nome_materia){

int i,j,v=0;    

system("cls"); 
      printf("#############################################################################");
      printf("\n\n");
      printf("            ALUNOS EM %s COM NOTA MENOR QUE %5.2f",Nome_materia, valor);
      printf("\n\n");
      printf("#############################################################################\n");

fseek(f,0,SEEK_END);
j=ftell(f)/sizeof(ALUNO);
fseek(f,0,SEEK_SET);

for(i=0; i < j;i++){
    fread(&classe,sizeof(ALUNO),1,f);
       if(classe.disciplina[Materia].mf < valor){
         printf("\nRA: %d\n\n", classe.RA);  
         printf("Nome: %s\n\n", classe.Nome);
         printf("Nota: %5.2f\n\n", classe.disciplina[Materia].mf);
         printf("-----------------------------------------------------------------------------\n");
         v=1;
         }
    } 
    if (v==0)
    printf("\n\n\nNenhum aluno teve nota menor que %5.2f em %s\n\n\n", valor,Nome_materia);
system("pause");       
     
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
void Nota_Intervalo(FILE *f,int Materia, float valor1,float valor2,const char *Nome_materia){
     
int i,j,v=0; float temp;
     
     if(valor1 > valor2){
     temp = valor1;
     valor1 = valor2;
     valor2 = temp;
     }//troca valores 
     
    system("cls"); 
      printf("#############################################################################");
      printf("\n\n");
      printf("       ALUNOS EM %s COM NOTA NO INTERVALO DE %5.2f A %5.2f",Nome_materia,valor1,valor2);
      printf("\n\n");
      printf("#############################################################################\n");

fseek(f,0,SEEK_END);
j=ftell(f)/sizeof(ALUNO);
fseek(f,0,SEEK_SET);

for(i=0; i < j;i++){
    fread(&classe,sizeof(ALUNO),1,f);
       if((classe.disciplina[Materia].mf > valor1) && (classe.disciplina[Materia].mf < valor2)){
         printf("\nRA: %d\n\n", classe.RA);  
         printf("Nome: %s\n\n", classe.Nome);
         printf("Nota: %5.2f\n\n", classe.disciplina[Materia].mf);
         printf("-----------------------------------------------------------------------------\n");
         v=1;
         }
    } 
    if (v==0)
    printf("\n\n\nNenhum aluno teve nota no intervalo de %5.2f a %5.2f em %s\n\n\n", valor1,valor2,Nome_materia);
system("pause");       
     
} 
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
void Listar_Alfabetica(FILE *f){

typedef struct{  
    char nome[50];
    int RA;       
}info;

int i,j; info a[40], temp;


fseek(f,0,SEEK_SET);   
       system("cls");
       
       for (i=0; !feof(f);i++){
         fread(&classe,sizeof(ALUNO),1,f);             
         strcpy(a[i].nome ,classe.Nome);
         a[i].RA = classe.RA;
       } //array com todos os alunos e suas médias 
       
    
      for(i=1; i < ftell(f)/sizeof(ALUNO);i++)
         for(j=0; j <((ftell(f)/sizeof(ALUNO))-i); j++){
             if (stricmp(a[j].nome , a[j+1].nome)==1) { 
                          
                 strcpy (temp.nome ,a[j].nome);
                 temp.RA = a[j].RA;
                 
                          
                 strcpy (a[j].nome, a[j+1].nome);
                 a[j].RA = a[j+1].RA;
                 
                        
                 strcpy (a[j+1].nome , temp.nome);
                 a[j+1].RA = temp.RA;
             }  //if
         }//Bubblesort        
     
        
      printf("#############################################################################");
      printf("\n\n");
      printf("                       ALUNOS EM ORDEM ALFABETICA ");
      printf("\n\n");
      printf("#############################################################################\n");
      
      
       for(i=0; i < ftell(f)/sizeof(ALUNO);i++){
         printf("\nRA: %d\n\n", a[i].RA);  
         printf("Nome: %s\n\n", a[i].nome);
         printf("-----------------------------------------------------------------------------\n\n");
      }    
      system("pause");  
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
void Aprovado_Reprovado(FILE *f, int Materia,const char *Nome_Materia){

int i,j,a=0,b=0;    float valor = 5,p=0,p2=0;

system("cls"); 
      printf("#############################################################################");
      printf("\n\n");
      printf("            ALUNOS APROVADOS E REPROVADOS EM %s",Nome_Materia);
      printf("\n\n");
      printf("#############################################################################\n");

fseek(f,0,SEEK_END);
j=ftell(f)/sizeof(ALUNO);
fseek(f,0,SEEK_SET);

for(i=0; i < j;i++){
    fread(&classe,sizeof(ALUNO),1,f);
       if(classe.disciplina[Materia].mf >= valor){
         printf("\nRA: %d\n\n", classe.RA);  
         printf("Nome: %s\n\n", classe.Nome);
         printf("Nota: %5.2f\n\n", classe.disciplina[Materia].mf);
         printf("APROVADO\n\n");
         printf("-----------------------------------------------------------------------------\n");
         a++;
         }
         else{
         printf("\nRA: %d\n\n", classe.RA);  
         printf("Nome: %s\n\n", classe.Nome);
         printf("Nota: %5.2f\n\n", classe.disciplina[Materia].mf);
         printf("REPROVADO\n\n");
         printf("-----------------------------------------------------------------------------\n");
         b++;  
         }
    } 
   j=ftell(f)/sizeof(ALUNO);
   p = (a*100)/j;
   p2 = (b*100)/j;
   printf("\n\n"); 
   printf("    %d ALUNOS APROVADOS EM %s (%5.1f%c)",a,Nome_Materia,p,37);
   printf("\n\n"); 
   printf("    %d ALUNOS REPROVADOS EM %s (%5.1f%c)",b,Nome_Materia,p2,37);
   printf("\n\n");       
   system("pause"); 
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
