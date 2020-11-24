#include "arvoreBusca.h"

int main(){
    Arv* arv1 = abb_cria();
    abb_insere(arv1, 6);
    abb_insere(arv1, 2);
    abb_insere(arv1, 8);
    abb_insere(arv1, 1);
    abb_insere(arv1, 4);
    abb_insere(arv1, 3);
    abb_imprime(arv1);
    printf("%d numeros maiores que %d e menores que %d\n", abb_soma_xy(arv1, 6, 2), 2, 6);
    printf("o numero %d esta no nivel %d\n", 3, abb_nivel(arv1, 3));
}