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
        r->esq = insere(r->esq, v);
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
    int balancingFactor = (heightEsq - heightDir);
    printf("balacing factor: %d\n", balancingFactor);

    if (balancingFactor < -1 || balancingFactor > 1){
        // printf("teste\n");
        return r;
    }
    else if(r->dir != NULL){
        // printf("teste2\n");
        return retracing(r->dir);
    }
    else if(r->esq != NULL){
        // printf("teste3\n");
        return retracing(r->esq);
    }
    else
        return NULL;
}

ArvNo *rotateLeft(ArvNo *r){
    printf("ROTATING LEFT!\n");
    int infoRaiz = r->info;
    r = r->esq;
    r->dir = insere(r->dir, infoRaiz);
    printf("exiting!\n");
    return r;
}

ArvNo *rotateRight(ArvNo *r){
    printf("ROTATING RIGHT!\n");
    int infoRaiz = r->info;
    r = r->dir;
    r->esq = insere(r->esq, infoRaiz);
    printf("exiting!\n");
    return r;
}

ArvNo *retracingDireita(ArvNo *r){
    printf("entrou funcao!\n");
    int heightEsq = getHeight(r->esq);
    printf("heightEsq: %d\n", heightEsq);
    int heightDir = getHeight(r->dir);
    printf("heightDir: %d\n", heightDir);
    int balancingFactor = (heightEsq - heightDir);
    printf("balacing factor: %d\n", balancingFactor);

    if (balancingFactor > 1){
        printf("entrou if(1)!\n");
        // if (r->dir == NULL){
        //     printf("dir == NULL!\n");
        // }
        if (r->esq == NULL){
            printf("esq == NULL!\n");
        }
        else if (getHeight(r->esq->esq) > getHeight(r->esq->dir)){
            return rotateLeft(r);
        }
        else {
            r->dir = rotateRight(r);
            return rotateLeft(r);
            printf("rotate left n right!\n");
        }
        // printf("entrou funcao!\n");
        printf("saiu if(1)!\n");
    }
    else if(balancingFactor < -1){
        printf("entrou if(2)!\n");
        // if (r->dir == NULL){
        //     printf("dir == NULL!\n");
        // }
        if (r->dir == NULL){
            printf("esq == NULL!\n");
        }
        else if (getHeight(r->dir->dir) > getHeight(r->dir->esq)){
            return rotateRight(r);
        }
        else {
            r->esq = rotateLeft(r);
            return rotateRight(r);
            printf("rotate right n left!\n");
        }
        // printf("entrou funcao!\n");
        printf("saiu if(2)!\n");
    }
    else{
        return false;
    }
}

void abb_insere(Arv *a, int v)
{
    a->raiz = insere(a->raiz, v);
    ArvNo *rr = retracing(a->raiz);

    if (rr != NULL){
        a->raiz = retracingDireita(rr);
    }
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
    ArvNo *rr = retracing(a->raiz);

    if (rr != NULL){
        a->raiz = retracingDireita(rr);
    }
}

#endif