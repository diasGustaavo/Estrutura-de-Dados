#ifndef _QUEUELISTAENCADEADA_H_
#define _QUEUELISTAENCADEADA_H_

typedef struct queue Queue;

Queue * queue_create(int info);
int queue_is_empty(Queue* st);
int queue_size(Queue* st);
int enqueue(Queue* st, int info);
int dequeue(Queue** st);
void queue_clear(Queue** st);

#endif
