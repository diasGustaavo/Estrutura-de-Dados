#ifndef _QUEUELISTAENCADEADA_H_
#define _QUEUELISTAENCADEADA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct queue Queue;

Queue * queueCreate(int info);
int queueIsEmpty(Queue* st);
int queueSize(Queue* st);
int enqueue(Queue* st, int info);
int dequeue(Queue** st);
void queueClear(Queue** st);

#endif
