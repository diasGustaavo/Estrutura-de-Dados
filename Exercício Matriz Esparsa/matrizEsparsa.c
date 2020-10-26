#ifndef MATRIZ_ESPARSA_C
#define MATRIZ_ESPARSA_C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrizEsparsa.h"

struct elemento
{
    double num;
    int posicaoLinha;
    int posicaoColuna;
    Elemento* proximo;
};

Elemento * criarMatrizEsparsa()
{
    Elemento* aux = NULL;
    return aux;
}

void removerMatriz(Elemento ** headMatriz)
{
    Elemento * headMatrizCpy = *headMatriz;
    Elemento * proximo;
    while(headMatrizCpy != NULL)
    {
        proximo = headMatrizCpy->proximo;
        free(headMatrizCpy);
        headMatrizCpy = proximo;
    }     

    *headMatriz = NULL;
}

int inserirValorNaPosicao(Elemento ** headMatriz, int linha, int coluna, double valor) 
{ 
    Elemento* headMatrizCpy = *headMatriz; 
    if (headMatrizCpy == NULL) 
    { 
        headMatrizCpy = (Elemento*) malloc (sizeof(Elemento)); 

        headMatrizCpy->num = valor; 
        headMatrizCpy->posicaoLinha = linha; 
        headMatrizCpy->posicaoColuna = coluna; 
        headMatrizCpy->proximo = NULL; 
        *headMatriz = headMatrizCpy; 

        return 1;
    } 
    else
    { 
        while (headMatrizCpy->proximo != NULL) 
            headMatrizCpy = headMatrizCpy->proximo; 
  
        Elemento* elementoAdicionado = (Elemento*) malloc (sizeof(Elemento)); 

        elementoAdicionado->num = valor; 
        elementoAdicionado->posicaoLinha = linha; 
        elementoAdicionado->posicaoColuna = coluna; 
        elementoAdicionado->proximo = NULL; 
        headMatrizCpy->proximo = elementoAdicionado; 

        return 1;
    } 

    return 0;
}

double retornarValorNaPosicao(Elemento * headMatriz, int linha, int coluna)
{
    Elemento *headMatrizCpy = headMatriz;

    while(headMatrizCpy != NULL){
        if((headMatrizCpy->posicaoLinha == linha) && (headMatrizCpy->posicaoColuna == coluna))
            return headMatrizCpy->num;
        headMatrizCpy = headMatrizCpy->proximo; 
    }

    return 0;
}

int removerValorNaPosicao(Elemento * headMatriz, int linha, int coluna)
{
    Elemento *headMatrizCpy = headMatriz;
    Elemento *passado = NULL;

    while(headMatrizCpy != NULL){
        if((headMatrizCpy->posicaoLinha == linha) && (headMatrizCpy->posicaoColuna == coluna)){
            if(passado == NULL){
                headMatriz = headMatriz->proximo;
                return 1;
            }

            passado->proximo = headMatrizCpy->proximo;
            free(headMatrizCpy);
        }
        passado = headMatrizCpy;
        headMatrizCpy = headMatrizCpy->proximo; 
    }

    return 0;
}

int getNumeroDeCasas(double num){
    int casas = 1;
    
    while((num = num / 10.0) >= 1){
        casas++;
    }

    return casas;
}

void imprimirMatriz(Elemento * headMatriz) 
{ 
    Elemento *headMatrizCpy = headMatriz;

    // definindo ate onde percorrer em linha
    int indexMaxLinha = 0;
    while(headMatrizCpy != NULL)
    {
        if (headMatrizCpy->posicaoLinha > indexMaxLinha)
            indexMaxLinha = headMatrizCpy->posicaoLinha;
        headMatrizCpy = headMatrizCpy->proximo;
    }

    headMatrizCpy = headMatriz;

    // definindo ate onde percorrer em coluna
    int indexMaxColuna = 0;
    while(headMatrizCpy != NULL)
    {
        if (headMatrizCpy->posicaoColuna > indexMaxColuna)
            indexMaxColuna = headMatrizCpy->posicaoColuna;
        headMatrizCpy = headMatrizCpy->proximo;
    }

    headMatrizCpy = headMatriz;

    // definindo o maior num
    double maiorNum = 0;
    while(headMatrizCpy != NULL)
    {
        if (headMatrizCpy->num > maiorNum)
            maiorNum = headMatrizCpy->num;
        headMatrizCpy = headMatrizCpy->proximo;
    }

    int numeroDeCasas = getNumeroDeCasas(maiorNum);

    headMatrizCpy = headMatriz;

    printf("\n\n");

    int indexLinha = 0;
    while(indexLinha <= indexMaxLinha){
        int indexColuna = 0;
        while(indexColuna <= indexMaxColuna){
            //checando cada linha e coluna se acha algum elemento na lista encadeada
            int found = 0;
            double numEncontrado = 0;
            headMatrizCpy = headMatriz;
            while(headMatrizCpy != NULL){
            // se achar, found = 1 e num encontrado = headMatrizCpy->num
            if((headMatrizCpy->posicaoLinha == indexLinha) && (headMatrizCpy->posicaoColuna == indexColuna)){
                numEncontrado = headMatrizCpy->num;
                found = 1;
            }
                headMatrizCpy = headMatrizCpy->proximo;
            }

            if(found == 0){
                int index = 0;
                while(index < numeroDeCasas){
                    index++;
                    printf(" ");
                }
                // adiciona o espaco de ".xx"
                printf("   0");
            }
            if(found == 1){
                int numEncontradoCasas = getNumeroDeCasas(numEncontrado);
                int indetacao = (numeroDeCasas - numEncontradoCasas);
                int index = 0;
                while(index < indetacao){
                    index++;
                    printf(" ");
                }
                printf(" %.2f", numEncontrado);
            }

            ++indexColuna;
        }
        printf("\n");
        ++indexLinha;
    }
} 

#endif
