#include "arvoreBinariaAVL.h"

int main(){
    printf("_----------------------------------\n");
    Arv* arv1 = abb_cria();
    abb_insere(arv1, 6);
    // abb_imprime_especial(arv1);
    printf("\n");
    abb_insere(arv1, 2);
    // abb_imprime_especial(arv1);
    printf("\n");
    abb_insere(arv1, 8);
    // abb_imprime_especial(arv1);
    printf("\n");
    printf("raiz: %d\nesq: %d\ndir: %d\n", arv1->raiz->info, arv1->raiz->esq->info, arv1->raiz->dir->info);
    // printf("raiz: %d\n", arv1->raiz->esq->info);

    // abb_insere(arv1, 1);
    // abb_insere(arv1, 4);
    // abb_insere(arv1, 3);

    return 0;
}