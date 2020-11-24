#ifndef _ARVORE_BUSCA_H
#define _ARVORE_BUSCA_H

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

void imprime(ArvNo *r);
void abb_imprime(Arv *a);
ArvNo *busca(ArvNo *r, int v);
ArvNo *abb_busca(Arv *a, int v);
Arv *abb_cria(void);
ArvNo *insere(ArvNo *r, int v);
void abb_insere(Arv *a, int v);
ArvNo *retira(ArvNo *r, int v);
void abb_retira(Arv *a, int v);

//EXERCICIO 6
int nfolhas_maiores(ArvNo* r, int x);
int abb_nfolhas_maiores(Arv* a, int x);

//EXERCICIO 7
int soma_xy(ArvNo* r, int x, int y);
int abb_soma_xy(Arv* a, int x, int y);

//EXERCICIO 8
int nivel(ArvNo *r, int x);
int abb_nivel(Arv *a, int x);

#endif