#ifndef _STACKLISTAENCADEADA_C_
#define _STACKLISTAENCADEADA_C_

#include "stackListaEncadeada.h"

struct stack
{
    int info;
    struct stack* elAnterior;
};

Stack * stackCreate(int info)
{
    Stack * st = (Stack*) malloc(sizeof(Stack));
    if(st){
        st->info = info;
        st->elAnterior = NULL;
    }
    return st;
}

int stackIsEmpty(Stack* st)
{
    return (st == NULL);
}

int stackSize(Stack* st)
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

int stackPush(Stack* st, int info)
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

int stackPop(Stack** st)
{
    if(st)
    {
        *st = (*st)->elAnterior;
        return 1;
    }
    
    return 0;
}

void stackClear(Stack** st)
{
    while(*st)
        stackPop(st);
}

#endif
