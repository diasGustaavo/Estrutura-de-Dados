#ifndef _QUEUELISTAENCADEADA_C_
#define _QUEUELISTAENCADEADA_C_

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue
{
    int info;
    struct queue* elProx;
};

Queue * queue_create(int info)
{
    Queue * st = (Queue*) malloc(sizeof(Queue));
    if(st){
        st->info = info;
        st->elProx = NULL;
    }
    return st;
}

int queue_is_empty(Queue* st)
{
    return (st == NULL);
}

int queue_size(Queue* st)
{
    int counter = 0;
    Queue* stCpy = (Queue*) malloc(sizeof(Queue));
    if(st && stCpy){
        stCpy->info = st->info;
        stCpy->elProx = st->elProx;

        while(stCpy != NULL){
            counter++;
            stCpy = stCpy->elProx;
        }

        free(stCpy);
        return counter;
    }
    return 0;
}

int enqueue(Queue* st, int info)
{
    if(st)
    {
        Queue * cpyQueue = (Queue*) malloc(sizeof(Queue));
        if(cpyQueue){
            cpyQueue->elProx = st->elProx;
            cpyQueue->info = st->info;

            while(st->elProx != NULL){
                st = st->elProx;
            }

            Queue * novaQueue2 = (Queue*) malloc(sizeof(Queue));
            if(novaQueue2){
                novaQueue2->elProx = NULL;
                novaQueue2->info = info;
                st->elProx = novaQueue2;
                st = cpyQueue;
                free(cpyQueue);
                return 1;
            }
        }
    }
    
    return 0;
}

int dequeue(Queue** st)
{
    if(st)
    {
        Queue* stTemp = (Queue*) malloc(sizeof(Queue));
        *st = (*st)->elProx;
        free(stTemp);
        return 1;
    }
    
    return 0;
}

void queue_clear(Queue** st)
{
    while(*st)
        dequeue(st);
}

#endif
