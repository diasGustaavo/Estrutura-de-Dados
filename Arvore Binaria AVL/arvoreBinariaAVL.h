#ifndef _ARVORE_BUSCA_H
#define _ARVORE_BUSCA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void imprime(ArvNo *r);
void abb_imprime(Arv *a);
ArvNo *busca(ArvNo *r, int v);
ArvNo *abb_busca(Arv *a, int v);
Arv *abb_cria();
ArvNo *insere(ArvNo *r, int v);
void abb_insere(Arv *a, int v);
ArvNo *retira(ArvNo *r, int v);
void abb_retira(Arv *a, int v);

void imprimeEspecial(ArvNo *r);
void abb_imprime_especial(Arv *a);
ArvNo *balanceia(ArvNo *r, int v);
bool pertence(ArvNo *r, int v);
ArvNo *retracing(ArvNo *r);
int getHeight(ArvNo *r);

#endif