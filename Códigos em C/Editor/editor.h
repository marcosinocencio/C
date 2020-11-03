#ifndef _EDITOR
#define _EDITOR

#define MAX 12

struct lista{
             char letra;
             struct lista *prox;
             struct lista *ant;
             short selecao;
             char link[MAX];
             };

struct linha{
            struct lista *inicio;
            struct lista *fim;
            struct lista *atual;
            struct linha *prox, *ant;
            };

struct editor{
              int qtdletras;
              int qtdp;
              int qtdlinhas;
              int cor_letra;
              int cor_fundo;
             };

struct fila{
       struct lista *inicio;
       struct lista *final;
       };


typedef struct lista  Tno;
typedef struct linha  Tlinha;
typedef struct fila   Tfila;
typedef struct editor Teditor;

FILE *fp;

void Inicializa(Tlinha **Estrutura, Tlinha **Atual);
void Inicializa_Editor(Teditor **editor);
void Leitura (Tlinha **Atual, Tlinha **Estrutura, Tfila **F, Tfila **Copia, Teditor **edt);
void Impressao (Tlinha *Estrutura,int Cont, Teditor *edt);
void ContaL (Tlinha *Estrutura,int Cont, Teditor *edt);
void ContaLinhas (Tlinha *Estrutura,int Cont, Teditor *edt);
void ContaP (Tlinha *Estrutura,int Cont, Teditor *edt);
short Vazia(Tlinha *Atual);
void Insere(Tlinha **Estrutura, char Elem);
int Tratamento(Tlinha **Atual, Tlinha **Estrutura, Tfila **F, Tfila **Copia , int Elem);
short Remove(Tlinha **Atual, Tlinha **Estrutura);
short Setaesquerda(Tlinha **Atual);
short Setadireita(Tlinha **Atual);
void Sobrescreve(Tlinha **Atual, char Elem);
void Delete(Tlinha **Atual);
int Contacar_Atual(Tlinha *Atual);
int Contacar_Final(Tlinha *Atual);

void Setacima(Tlinha **Atual, Tlinha *Estrutura);
void Setabaixo(Tlinha **Atual);
void Salvar(Tlinha *Estrutura);
void Abrir(Tlinha **Estrutura, Tlinha **Atual,int Op);
void Pula_Linha(Tlinha **Atual, Tlinha **Estrutura);
int  Busca_Palavra(char *p, Tlinha **Atual, Tno **car_atual, Tfila **F);

void Concatena(Tlinha **Atual);
void Ajuda();
short Item_Selecionado(Tlinha **Atual);


void Atualiza_Selecao(Tlinha **Atual);
void Seleciona (Tno *Ini, Tno *Fim, Tlinha **Atual);
#endif
