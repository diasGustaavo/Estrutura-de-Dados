#ifndef CONJUNTO_INTEIROS_C
#define CONJUNTO_INTEIROS_C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "conjuntoInteiros.h"

struct conjInt
{
    int num;
    struct conjInt* prox;  
};

ConjInt * uniao(ConjInt** headConjunto1, ConjInt** headConjunto2)
{
    if(conjuntoEhVazio(*headConjunto2))
        return *headConjunto1;

    if(conjuntoEhVazio(*headConjunto1))
        return *headConjunto2;

    ConjInt* lHeadUnion = NULL;
    ConjInt* smallerLHead = NULL;

    if(tamanho(*headConjunto1) < tamanho(*headConjunto2)){
        smallerLHead = *headConjunto1;
        lHeadUnion = clone(*headConjunto2);
    }
    else
    {
        smallerLHead = *headConjunto2;
        lHeadUnion = clone(*headConjunto1);
    }

    while(smallerLHead != NULL)
    {
        if (!(pertenceAoConjunto(lHeadUnion, smallerLHead->num))){
            inserirEl(&lHeadUnion, smallerLHead->num);
        }

        smallerLHead = smallerLHead->prox;
    }

    free(smallerLHead);
    return lHeadUnion;
}

ConjInt * criarConjVazio()
{
    ConjInt* aux = NULL;
    return aux;
}

int inserirEl(ConjInt** headConjunto, int num) 
{ 
    if(pertenceAoConjunto(*headConjunto, num))
        return 1;

    ConjInt* novoElemento = (ConjInt*) malloc(sizeof(ConjInt));
    if(novoElemento)
    {
        novoElemento->num = num;
        novoElemento->prox = NULL;
        ConjInt* elementoAtual; 
        // Caso especial
        if (*headConjunto == NULL || (*headConjunto)->num >= novoElemento->num) { 
            novoElemento->prox = *headConjunto; 
            *headConjunto = novoElemento; 
        } 
        else { 
            // Localiza o nó antes do ponto de insercao 
            elementoAtual = *headConjunto; 
            while (elementoAtual->prox != NULL && elementoAtual->prox->num < novoElemento->num)
            { 
                elementoAtual = elementoAtual->prox; 
            } 

            novoElemento->prox = elementoAtual->prox; 
            elementoAtual->prox = novoElemento; 
        } 

        return 1;
    }

    return 0;
} 

int remover(ConjInt** headConjunto, int num)
{
     ConjInt* headConjuntoCpy = *headConjunto;
     ConjInt* elemAnterior = NULL;
     int foiAchado = 0;

     // itera pelo conjunto ate acabar ou achar um numero = num
     while(headConjuntoCpy != NULL)
     {
         if(headConjuntoCpy->num == num)
         {
             foiAchado = 1;
             break;
         }
          elemAnterior = headConjuntoCpy;
          headConjuntoCpy = headConjuntoCpy->prox;
     }
     
     if(foiAchado)
     {

         if(elemAnterior == NULL)
         {
             *headConjunto = headConjuntoCpy->prox;
             free(headConjuntoCpy);
             return 1;
         }
         
         elemAnterior->prox = headConjuntoCpy->prox;
         free(headConjuntoCpy);
         return 1;
     }
     
     return 0;         
}

ConjInt * intersecao(ConjInt** headConj1, ConjInt** headConj2)
{
    // Se um dos conjuntos forem vazios, retorna um conjunto vazio
    if(conjuntoEhVazio(*headConj2) || conjuntoEhVazio(*headConj1))
    {   
        return criarConjVazio();
    }

    ConjInt* lHeadUnion = NULL;
    ConjInt* biggerLHead = NULL;
    ConjInt* smallerLHead = NULL;

    // define qual o maior conjunto
    if(tamanho(*headConj1) > tamanho(*headConj2)){
        biggerLHead = *headConj1;
    }
    else
    {
        biggerLHead = *headConj2;
    }

    // itera pelo maior conjunto
    while(biggerLHead != NULL)
    {
        // define qual o menor conjunto 
        if(tamanho(*headConj1) > tamanho(*headConj2)){
            smallerLHead = *headConj2;
        }
        else
        {
            smallerLHead = *headConj1;
        }

        // itera pelo menor conjunto
        while(smallerLHead != NULL)
        {
            // se os numeros forem iguais, verifica se o numero ja existe na lista
            // se nao existir, adiciona
            if(biggerLHead->num == smallerLHead->num){
                if(pertenceAoConjunto(lHeadUnion, smallerLHead->num) == 0)
                    inserirEl(&lHeadUnion, smallerLHead->num);
                break;
            }
            smallerLHead = smallerLHead->prox;
        }

        biggerLHead = biggerLHead->prox;
    }

    return lHeadUnion;
}

ConjInt * diferencaDeConj(ConjInt** headConj1, ConjInt** headConj2)
{   
    // A - B = {x | x E A e x /e B}
    // se em x - y, y = 0, x - y = x
    if(conjuntoEhVazio(*headConj2))
    {
        return(*headConj1);
    }

    // { } - {1, 2, ...} = { }
    if(conjuntoEhVazio(*headConj1))
    {
        return(criarConjVazio());
    }

    ConjInt * headConj1Cpy = clone(*headConj1);
    ConjInt * diferenca = criarConjVazio();

    // itera pelo conjunto 1
    while(headConj1Cpy != NULL)
    {
        // se achar um item do conjunto 1 que nao pertence ao conj 2, insere
        if (!pertenceAoConjunto(*headConj2, headConj1Cpy->num)){
            inserirEl(&diferenca, headConj1Cpy->num);
        }

        headConj1Cpy = headConj1Cpy->prox;
    }

    free(headConj1Cpy);
    return diferenca;
}

int pertenceAoConjunto(ConjInt* headConj, int num)
{
     if(conjuntoEhVazio(headConj))
          return 0;
     
     while(headConj != NULL)
     {
         if(headConj->num == num)
             return 1;
         
         headConj = headConj->prox;
     }
     
     return 0;
}

int menorValor(ConjInt* headDoConjunto)
{
    return headDoConjunto->num;
}

int maiorValor(ConjInt* headDoConjunto)
{
    ConjInt* headDoConjuntoCpy = clone(headDoConjunto);
    ConjInt* headDoConjuntoCpyAnterior = clone(headDoConjunto);

    // itera por todo o conjunto ate chegar ao final
    while(headDoConjuntoCpy != NULL){
        headDoConjuntoCpyAnterior = clone(headDoConjuntoCpy);
        headDoConjuntoCpy = headDoConjuntoCpy->prox;
    }

    free(headDoConjuntoCpy);
    return (headDoConjuntoCpyAnterior->num);
}

int saoIguais(ConjInt* headConj1, ConjInt* headConj2)
{
    if (tamanho(headConj1) != tamanho(headConj2))
        return 0;

    ConjInt* cloneHeadConj1 = clone(headConj1);
    ConjInt* cloneHeadConj2 = clone(headConj2);

    // itera verificando um por um de cada lista
    while(cloneHeadConj1 != NULL){
        // se observar algum com valores diferentes, retorna 0
        if (cloneHeadConj1->num != cloneHeadConj2->num){
            free(cloneHeadConj1);
            free(cloneHeadConj2);
            return 0;
        }
        cloneHeadConj2 = cloneHeadConj2->prox;
        cloneHeadConj1 = cloneHeadConj1->prox;
    }

    free(cloneHeadConj1);
    free(cloneHeadConj2);

    return 1;
}

int conjuntoEhVazio(ConjInt* headDoConjunto)
{
    return (headDoConjunto == NULL);
}

int tamanho(ConjInt* headDoConjunto)
{
    int contador = 0;    
    while(headDoConjunto != NULL)
    {
        ++contador;
        headDoConjunto = headDoConjunto->prox;
    }
    
    return contador;      
}

ConjInt * clone(ConjInt * conjunto)
{
    // Retornara NULL se a o conjunto passado for vazio
    if (conjunto == NULL)
        return NULL;

    // Criar o head e designar valor
    ConjInt* newHead = (ConjInt*) malloc(sizeof(ConjInt));
    newHead->num = conjunto->num;

    // Atualizar o resto da lista
    ConjInt *p = newHead;
    conjunto = conjunto->prox;

    while(conjunto != NULL)
    {
        p->prox = malloc(sizeof(ConjInt));
        p = p->prox;
        p->num = conjunto->num;
        conjunto = conjunto->prox;
    }

    p->prox = NULL;

    return newHead;
}

void printarConjunto(char* mensagem, ConjInt* headDoConjunto)
{
    printf("%s ", mensagem);
    while(headDoConjunto != NULL)
    {
        printf("%d ", headDoConjunto->num);
        headDoConjunto = headDoConjunto->prox;
    }
    printf("\n");
}

void limparConjunto(ConjInt** headDoConjunto)
{
    ConjInt * aux = *headDoConjunto;
    ConjInt* prox = NULL;

    // percorre o codigo, limpando aux
    while(aux != NULL)
    {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }
    
    *headDoConjunto = NULL;
}

#endif
