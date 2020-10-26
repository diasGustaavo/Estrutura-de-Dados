#include "conjuntoInteiros.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    ConjInt * conjunto1 = criarConjVazio();
    inserirEl(&conjunto1, 1);
    inserirEl(&conjunto1, 2);
    inserirEl(&conjunto1, 3);
    inserirEl(&conjunto1, 4);
    inserirEl(&conjunto1, 5);
    inserirEl(&conjunto1, 6);
    inserirEl(&conjunto1, 7);
    inserirEl(&conjunto1, 8);
    inserirEl(&conjunto1, 9);
    inserirEl(&conjunto1, 10);
    printarConjunto("O conjunto 1 é composto por:", conjunto1);

    ConjInt * conjunto2 = criarConjVazio();
    inserirEl(&conjunto2, 1);
    inserirEl(&conjunto2, 2);
    inserirEl(&conjunto2, 4);
    inserirEl(&conjunto2, 8);
    inserirEl(&conjunto2, 16);
    inserirEl(&conjunto2, 32);
    inserirEl(&conjunto2, 64);
    inserirEl(&conjunto2, 128);
    inserirEl(&conjunto2, 256);
    inserirEl(&conjunto2, 512);
    printarConjunto("O conjunto 2 é composto por:", conjunto2);

    ConjInt * conjuntoUniao = uniao(&conjunto1, &conjunto2);
    printarConjunto("\nA uniao do conjunto 1 e 2 eh:", conjuntoUniao);

    ConjInt * conjuntoIntersecao = intersecao(&conjunto1, &conjunto2);
    printarConjunto("A intersecao do conjunto 1 e 2 eh:", conjuntoIntersecao);

    ConjInt * conjuntoDiferenca = diferencaDeConj(&conjunto1, &conjunto2);
    printarConjunto("A diferenca do conjunto 1 pelo 2 eh:", conjuntoDiferenca);



    printarConjunto("\nO conjunto 2 é composto por:", conjunto2);
    printf("O menor valor do conjunto 2 é: %d\n", maiorValor(conjunto2));
    printf("O maior valor do conjunto 2 é: %d\n", menorValor(conjunto2));
    printf("O tamanho do conjunto é: %d\n", tamanho(conjunto2));

    if(pertenceAoConjunto(conjunto2, 1024))
        printf("o valor 1024 pertence ao conjunto 2\n");
    else
        printf("o valor 1024 nao pertence ao conjunto 2\n");

    printf("Inserindo o valor %d no conjunto 2...\n", 0);
    inserirEl(&conjunto2, 0);
    printarConjunto("\nO conjunto 2 é composto por:", conjunto2);
    printf("O menor valor do conjunto 2 é: %d\n", maiorValor(conjunto2));
    printf("O maior valor do conjunto 2 é: %d\n", menorValor(conjunto2));
    printf("O tamanho do conjunto é: %d\n", tamanho(conjunto2));

    if(pertenceAoConjunto(conjunto2, 1024))
        printf("o valor 1024 pertence ao conjunto 2\n");
    else
        printf("o valor 1024 nao pertence ao conjunto 2\n");

    printf("Inserindo o valor %d no conjunto 2...\n", 1024);
    inserirEl(&conjunto2, 1024);
    printarConjunto("\nO conjunto 2 é composto por:", conjunto2);
    printf("O menor valor do conjunto 2 é: %d\n", maiorValor(conjunto2));
    printf("O maior valor do conjunto 2 é: %d\n", menorValor(conjunto2));
    printf("O tamanho do conjunto é: %d\n", tamanho(conjunto2));

    if(pertenceAoConjunto(conjunto2, 1024))
        printf("o valor 1024 pertence ao conjunto 2\n");
    else
        printf("o valor 1024 nao pertence ao conjunto 2\n");


    printf("Removendo o valor %d no conjunto 2...\n", 1024);
    remover(&conjunto2, 1024);
    printarConjunto("\nO conjunto 2 é composto por:", conjunto2);
    printf("O menor valor do conjunto 2 é: %d\n", maiorValor(conjunto2));
    printf("O maior valor do conjunto 2 é: %d\n", menorValor(conjunto2));
    printf("O tamanho do conjunto é: %d\n", tamanho(conjunto2));

    if(pertenceAoConjunto(conjunto2, 1024))
        printf("o valor 1024 pertence ao conjunto 2\n");
    else
        printf("o valor 1024 nao pertence ao conjunto 2\n");
    printf("Removendo o valor %d no conjunto 2...\n", 0);
    remover(&conjunto2, 0);

    printarConjunto("\nO conjunto 2 é composto por:", conjunto2);
    printf("O menor valor do conjunto 2 é: %d\n", maiorValor(conjunto2));
    printf("O maior valor do conjunto 2 é: %d\n", menorValor(conjunto2));
    printf("O tamanho do conjunto é: %d\n", tamanho(conjunto2));
    if (conjuntoEhVazio(conjunto2))
        printf("O conjunto 2 é vazio\n");
    else
        printf("O conjunto 2 não é vazio\n");

    printf("\nCriando novo conjunto 3 vazio...\n");
    ConjInt * conjunto3 = criarConjVazio();
    printarConjunto("O conjunto 3 é composto por:", conjunto3);
    if (conjuntoEhVazio(conjunto2) == 0)
        printf("O conjunto 3 é vazio\n");
    else
        printf("O conjunto 3 não é vazio\n");

}
