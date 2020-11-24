#include "arvore.h"

ArvNo *arv_criano(int c, ArvNo *esq, ArvNo *dir)
{
    ArvNo *p = (ArvNo *)malloc(sizeof(ArvNo));
    p->info = c;
    p->esq = esq;
    p->dir = dir;
    return p;
}

Arv *arv_cria(ArvNo *r)
{
    Arv *a = (Arv *)malloc(sizeof(Arv));
    a->raiz = r;
    return a;
}

void imprime(ArvNo *r)
{
    printf("<");
    if (r != NULL)
    {
        printf("%i", r->info);
        imprime(r->esq);
        imprime(r->dir);
    }

    printf(">");
}

void arv_imprime(Arv *a)
{
    imprime(a->raiz);
}

void libera(ArvNo *r)
{
    if (r != NULL)
    {   
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

void arv_libera(Arv *a)
{
    libera(a->raiz);
    if (a != NULL)
        free(a);
}

///////// EXERCICIO 1 

// maneira preferivel
int imprimeQuantidadePares(ArvNo *r, int prev){
    if(r != NULL){
        if(r->info % 2 == 0)
            prev++;
        prev = imprimeQuantidadePares(r->esq, prev);
        prev = imprimeQuantidadePares(r->dir, prev);
    }
    return prev;
}

int pares(Arv *a){
    return (imprimeQuantidadePares(a->raiz, 0));
}

// maneira determinada pelo exercicio
// int pares(Arv* a){
//     int qtde = 0;
//     if(a->raiz != NULL){
//         if(a->raiz->info % 2 == 0)
//             qtde++;
//         Arv* arvEsquerda = arv_cria(a->raiz->esq);
//         qtde += pares(arvEsquerda);
//         Arv* arvDireita = arv_cria(a->raiz->dir);
//         qtde += pares(arvDireita);
//     }
//     return qtde;
// }

///////// EXERCICIO 2

//maneira preferivel
int imprimeQuantidadeFolhas(ArvNo *r, int prev){
    if(r != NULL){
        prev++;
        prev = imprimeQuantidadeFolhas(r->esq, prev);
        prev = imprimeQuantidadeFolhas(r->dir, prev);
    }
    return prev;
}

int folhas(Arv *a){
    return (imprimeQuantidadeFolhas(a->raiz, 0));
}

// maneira determinada pelo exercicio
// int folhas(Arv* a){
//     int qtde = 0;
//     if(a->raiz != NULL){
//         qtde++;
//         Arv* arvEsquerda = arv_cria(a->raiz->esq);
//         qtde += folhas(arvEsquerda);
//         Arv* arvDireita = arv_cria(a->raiz->dir);
//         qtde += folhas(arvDireita);
//     }
//     return qtde;
// }

///////// EXERCICIO 3

int um_filho(Arv* a){
    int qtdeFilhos = 0;
    int ocorrencias = 0;
    if(a->raiz->dir != NULL){
        qtdeFilhos++;
        Arv* arvoreDir = arv_cria(a->raiz->dir);
        ocorrencias += um_filho(arvoreDir);
    }
    if(a->raiz->esq != NULL){
        qtdeFilhos++;
        Arv* arvoreEsq = arv_cria(a->raiz->esq);
        ocorrencias += um_filho(arvoreEsq);
    }
    if(qtdeFilhos == 1)
        ocorrencias++;

    return ocorrencias;
}