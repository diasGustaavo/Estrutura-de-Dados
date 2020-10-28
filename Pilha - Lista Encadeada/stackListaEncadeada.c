#ifndef _STACKLISTAENCADEADA_C_
#define _STACKLISTAENCADEADA_C_

#include <stdio.h>
#include <stdlib.h>
#include "stackListaEncadeada.h"

struct stack
{
    int info;
    struct stack* elAnterior;
};

Stack * stack_create(int info)
{
    Stack * st = (Stack*) malloc(sizeof(Stack));
    if(st){
        st->info = info;
        st->elAnterior = NULL;
    }
    return st;
}

int stack_is_empty(Stack* st)
{
    return (st == NULL);
}

int stack_size(Stack* st)
{
    int counter = 0;
    Stack* stCpy = (Stack*) malloc(sizeof(Stack));
    if(st && stCpy){
        stCpy->info = st->info;
        stCpy->elAnterior = st->elAnterior;

        while(stCpy != NULL){
            counter++;
            stCpy = stCpy->elAnterior;
        }

        free(stCpy);
        return counter;
    }
    return 0;
}

int stack_push(Stack* st, int info)
{
    if(st)
    {
        Stack * novaSt = (Stack*) malloc(sizeof(Stack));
        if(novaSt){
            novaSt->info = st->info;
            novaSt->elAnterior = st->elAnterior;

            st->info = info;
            st->elAnterior = novaSt;

            return 1;
        }
    }
    
    return 0;
}

int stack_pop(Stack** st)
{
    if(st)
    {
        Stack* stTemp = (Stack*) malloc(sizeof(Stack));
        *st = (*st)->elAnterior;
        free(stTemp);
        return 1;
    }
    
    return 0;
}

void stack_clear(Stack** st)
{
    while(*st)
        stack_pop(st);
}

#endif
