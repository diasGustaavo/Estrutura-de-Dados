#ifndef _ARVORE_BUSCA_C
#define _ARVORE_BUSCA_C

#include "arvoreBusca.h"

void imprime(ArvNo *r)
{
    if (r != NULL)
    {
        imprime(r->esq);
        printf("%d\n", r->info);
        imprime(r->dir);
    }
}

void abb_imprime(Arv *a)
{
    return imprime(a->raiz);
}

ArvNo *busca(ArvNo *r, int v)
{
    if (r == NULL)
        return NULL;
    else if (r->info > v)
        return busca(r->esq, v);
    else if (r->info < v)
        return busca(r->dir, v);
    else
        return r;
}

ArvNo *abb_busca(Arv *a, int v)
{
    return busca(a->raiz, v);
}

Arv *abb_cria(void)
{
    Arv *a = (Arv *)malloc(sizeof(Arv));
    a->raiz = NULL;
    return a;
}

ArvNo *insere(ArvNo *r, int v)
{
    if (r == NULL)
    {
        r = (ArvNo *)malloc(sizeof(ArvNo));
        r->info = v;
        r->esq = r->dir = NULL;
    }
    else if (v < r->info)
        r->esq = insere(r->esq, v);
    else
        r->dir = insere(r->dir, v);
    return r;
}

void abb_insere(Arv *a, int v)
{
    a->raiz = insere(a->raiz, v);
}

ArvNo *retira(ArvNo *r, int v)
{
    if (r == NULL)
        return NULL;
    else if (r->info > v)
        r->esq = retira(r->esq, v);
    else if (r->info < v)
        r->dir = retira(r->dir, v);
    else
    {
        if (r->esq == NULL && r->dir == NULL)
        {
            free(r);
            r = NULL;
        }
        else if (r->esq == NULL)
        {
            ArvNo *t = r;
            r = r->dir;
            free(t);
        }
        else if (r->dir == NULL)
        {
            ArvNo *t = r;
            r = r->esq;
            free(t);
        }
        else
        {
            ArvNo *f = r->esq;
            while (f->dir != NULL)
            {

                f = f->dir;
            }
            r->info = f->info;
            f->info = v;
            r-> esq = retira(r->esq ,v);
        }
    }
    return r;
}

void abb_retira(Arv *a, int v)
{
    a->raiz = retira(a->raiz, v);
}


////////// EXERCICIO 6

int nfolhas_maiores(ArvNo* r, int x){
    int contador = 0;
    if(r != NULL){
        if(r->info > x)
            contador++;
        contador += nfolhas_maiores(r->dir, x);
        contador += nfolhas_maiores(r->esq, x);
    }
    return contador;
}

int abb_nfolhas_maiores(Arv* a, int x){
    nfolhas_maiores(a->raiz, x);
}

//////// EXERCICIO 7

int soma_xy(ArvNo* r, int x, int y){
    int contador = 0;
    if(r != NULL){
        if(r->info > y && r->info < x)
            contador++;
        contador += soma_xy(r->dir, x, y);
        contador += soma_xy(r->esq, x, y);
    }
    return contador;
}

int abb_soma_xy(Arv* a, int x, int y){
    soma_xy(a->raiz, x, y);
}

//////// EXERCICIO 8

int nivel(ArvNo *r, int x)
{
    int value = 0;
    if (r == NULL){
        return 0;
    }
    else if (r->info > x){
        value += nivel(r->esq, x);
        return (++value);
    }
    else if (r->info < x){
        value += nivel(r->dir, x);
        return (++value);
    }
    else
        return (++value);
}

int abb_nivel(Arv *a, int x){
    return nivel(a->raiz, x);
}

#endif