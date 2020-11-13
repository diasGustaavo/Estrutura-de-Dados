#ifndef _QUEUEVETORDINAMICO_H_
#define _QUEUEVETORDINAMICO_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct queue Queue;

Queue* queueCreate();
int queueIsEmpty(Queue* p);
int queueSize(Queue* st);
void queuePush(Queue* queue, int v);
int queuePop(Queue* p);
void queueClear(Queue* p);

int queueSize(Queue* p);

#endif
