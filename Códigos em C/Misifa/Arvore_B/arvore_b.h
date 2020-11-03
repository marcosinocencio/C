/*
*/

#define t 5

typedef RegAB NoAB;

struct RegAB{
       int n_chave;
       int chave[2*t - 1];
       NoAB filhos[2*t];
       bool folha; 
};
