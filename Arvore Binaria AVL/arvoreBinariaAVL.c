#ifndef _ARVORE_BUSCA_C
#define _ARVORE_BUSCA_C

#include "arvoreBinariaAVL.h"

void imprime(ArvNo *r)
{
    if (r != NULL)
    {
        imprime(r->esq);
        printf("%d\n", r->info);
        imprime(r->dir);
    }
}

void imprimeEspecial(ArvNo *r)
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

void abb_imprime_especial(Arv *a)
{
    return imprimeEspecial(a->raiz);
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

Arv *abb_cria()
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
    else
        r->dir = insere(r->dir, v);
    return r;
}

bool pertence(ArvNo *r, int v){
    if (&(r->info) == NULL)
        return false;
    else if (r->info == v)
        return true;
    else if (pertence(r->esq, v) || pertence(r->dir, v))
        return true;
    else
        return false;
}

ArvNo *balanceia(ArvNo *r, int v)
{
    if (r == NULL)
    {
        printf("erro! cadeia passada eh NULL\n");
    }
    else {

        int heightEsq = getHeight(r->esq);
        int heightDir = getHeight(r->dir);
        int balancingFactor = heightEsq - heightDir;
        printf("balacing factor: %i\n", balancingFactor);
        // r = retracing(r);
        if (r != NULL){
            printf("cadeia desbalanceada!\n");
            // if (balancingFactor == -2){
            //     printf("ROTACAO RR!\n");
            //     int infoRaiz = r->info;
            //     r = r->dir;
            //     r->esq = insere(r->esq, v);
            //     balanceia(r, v);
            // }
            // else if (balancingFactor == 2){
            //     printf("ROTACAO LL!\n");
            //     int infoRaiz = r->info;
            //     r = r->esq;
            //     r->dir = insere(r->dir, v);
            //     balanceia(r, v);
            // }
            // else if(heightEsq > heightDir){

            // }
        }
        else
            printf("cadeia balanceada!\n");
    }
    return r;
}

int getHeight(ArvNo *r){
    if (r == NULL){
        return 0;
    }
    else{
        if ((r->esq != NULL) && (r->dir != NULL)){
            // printf("contem duas folhas\n");
            int heightEsq = getHeight(r->esq);
            int heightDir = getHeight(r->dir);
            if (heightEsq > heightDir)
                return heightEsq + 1;
            else
                return heightDir + 1;
        }
        else if(r->esq != NULL){
            // printf("contem folha a esquerda\n");
            return (1 + getHeight(r->esq));
        }
        else if(r->dir != NULL){
            // printf("contem folha a direita\n");
            return (1 + getHeight(r->dir));
        }
        else{
            // printf("node sem folhas!\n");
            return 1;
        }
    }
}

ArvNo *retracing(ArvNo *r){
    int heightEsq = getHeight(r->esq);
    printf("heightEsq: %d\n", heightEsq);
    int heightDir = getHeight(r->dir);
    printf("heightDir: %d\n", heightDir);
    int balancingFactor = heightEsq - heightDir;
    printf("balacing factor: %d", balancingFactor);

    // if (balancingFactor < -1 || balancingFactor > 1){
    //     printf("teste\n");
    //     return r;
    // }
    // else if(retracing(r->dir) != NULL){
    //     printf("teste\n");
    //     return retracing(r->dir);
    // }
    // else if(retracing(r->esq) != NULL){
    //     printf("teste\n");
    //     return retracing(r->esq);
    // }
    // else
    //     return NULL;
    return r;
}

void abb_insere(Arv *a, int v)
{
    a->raiz = insere(a->raiz, v);
    ArvNo *rr = retracing(a->raiz);
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

#endif