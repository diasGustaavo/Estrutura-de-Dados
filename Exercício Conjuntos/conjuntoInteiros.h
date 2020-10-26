#ifndef CONJUNTO_INTEIROS_H
#define CONJUNTO_INTEIROS_H

typedef struct conjInt ConjInt;

// Funcoes requeridas pelo exercicio

ConjInt * uniao(ConjInt** headConjunto1, ConjInt** headConjunto2); //
ConjInt * criarConjVazio(); //
int inserirEl(ConjInt** headConjunto, int num); //
int remover(ConjInt** headConjunto, int num); //
ConjInt * intersecao(ConjInt** headConj1, ConjInt** headConj2); // 
ConjInt * diferencaDeConj(ConjInt** headConj1, ConjInt** headConj2); //
int pertenceAoConjunto(ConjInt* headConj, int num); //
int menorValor(ConjInt* headDoConjunto); //
int maiorValor(ConjInt* headDoConjunto); //
int saoIguais(ConjInt* headConj1, ConjInt* headConj2); 
int tamanho(ConjInt* headDoConjunto); //
int conjuntoEhVazio(ConjInt* headDoConjunto); //

// Funcoes Extras

ConjInt * clone(ConjInt * conjunto);
void printarConjunto(char* mensagem, ConjInt* headDoConjunto);
void limparConjunto(ConjInt** headDoConjunto);

#endif
