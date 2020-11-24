#include "arvore.h"

int main(){
    ArvNo* xen = arv_criano(9, NULL, NULL);
    ArvNo* zen = arv_criano(8, xen, NULL);
    ArvNo* ze = arv_criano(7, zen, NULL);
    ArvNo* xe = arv_criano(6, NULL, NULL);
    ArvNo* ye = arv_criano(5, NULL, NULL);
    ArvNo* ve = arv_criano(4, NULL, NULL);
    ArvNo* be = arv_criano(2, ze, xe);
    ArvNo* ce = arv_criano(3, ve, ye);
    ArvNo* aa = arv_criano(1, be, ce);
    Arv* arvore1 = arv_cria(aa);
    arv_imprime(arvore1);
    printf("\nnumero de numeros pares: %i\n", pares(arvore1));
    printf("numero de numeros folhas: %d\n", folhas(arvore1));
    printf("numero de numeros filhos: %d\n", um_filho(arvore1));
}