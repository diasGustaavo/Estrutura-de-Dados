#include "arvoreBinariaAVL.h"

int main(){
    Arv* arv1 = abb_cria();
    abb_insere(arv1, 6);
    abb_imprime_especial(arv1);
    printf("\n");
    abb_insere(arv1, 2);
    abb_imprime_especial(arv1);
    printf("\n");
    abb_insere(arv1, 8);
    abb_imprime_especial(arv1);
    printf("\n");
    // abb_insere(arv1, 1);
    // abb_insere(arv1, 4);
    // abb_insere(arv1, 3);

}