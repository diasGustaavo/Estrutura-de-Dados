#ifndef MATRIZ_ESPARSA_H
#define MATRIZ_ESPARSA_H

typedef struct elemento Elemento;

// funcoes requeridas

Elemento * criarMatrizEsparsa(); //
void removerMatriz(Elemento ** headMatriz);
int inserirValorNaPosicao(Elemento ** headMatriz, int linha, int coluna, double valor); //
void imprimirMatriz(Elemento* headMatriz); //
double retornarValorNaPosicao(Elemento * headMatriz, int linha, int coluna); //
int removerValorNaPosicao(Elemento * headMatriz, int linha, int coluna); //

// funcao adicional 

int getNumeroDeCasas(double num);

#endif
