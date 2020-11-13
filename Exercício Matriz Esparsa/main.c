#include "matrizEsparsa.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    Elemento* matriz1= criarMatrizEsparsa();
    inserirValorNaPosicao(&matriz1, 0, 0, 1);
    inserirValorNaPosicao(&matriz1, 1, 1, 2);
    inserirValorNaPosicao(&matriz1, 2, 2, 6);
    inserirValorNaPosicao(&matriz1, 3, 3, 4);
    inserirValorNaPosicao(&matriz1, 4, 4, 5);
    imprimirMatriz(matriz1);

    printf("\nexpandindo esta diagonal até o item 10...\n");

    inserirValorNaPosicao(&matriz1, 5, 5, 6);
    inserirValorNaPosicao(&matriz1, 6, 6, 7);
    inserirValorNaPosicao(&matriz1, 7, 7, 8);
    inserirValorNaPosicao(&matriz1, 8, 8, 9);
    inserirValorNaPosicao(&matriz1, 9, 9, 10);
    imprimirMatriz(matriz1);

    printf("\n Qual o numero na linha 9 e na coluna 9?...: %.2f\n", retornarValorNaPosicao(matriz1, 9, 9));
    printf("Excluir-lo-emos!...\n");
    removerValorNaPosicao(matriz1, 9, 9);
    printf("Agora a matriz está assim:");
    imprimirMatriz(matriz1);

    printf("\nAgora vamos adicionar outro numero no lugar do excluido...\n");
    printf("Que tal 12345678.9?...\n");
    printf("OBS: SE A MATRIZ APARECER DESPROPORCIONAL FAVOR ABRIR O TERMINAL EM TELA CHEIA\n");
    inserirValorNaPosicao(&matriz1, 9, 9, 12345678.9);
    imprimirMatriz(matriz1);
    
    removerMatriz(&matriz1);
  
    return 0;

}
