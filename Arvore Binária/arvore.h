#ifndef _ARVORE_H_
#define _ARVORE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct arvno ArvNo;
struct arvno
{
    int info;
    ArvNo *esq;
    ArvNo *dir;
};

typedef struct arv Arv;
struct arv
{
    ArvNo *raiz;
};

ArvNo *arv_criano(int c, ArvNo *esq, ArvNo *dir);
Arv *arv_cria(ArvNo *r);
void imprime(ArvNo *r);
void arv_imprime(Arv *a);
void libera(ArvNo *r);
void arv_libera(Arv *a);

//EXERCICIO 1
int imprimeQuantidadePares(ArvNo *r, int prev);
int pares(Arv *a);

//EXERCICIO 2
int imprimeQuantidadeFolhas(ArvNo *r, int prev);
int folhas(Arv *a);

//EXERCICIO 3
int um_filho(Arv* a);

#endif