#ifndef _QUEUEVETORDINAMICO_C_
#define _QUEUEVETORDINAMICO_C_

#include "queueVetorDinamico.h"

struct queue
{
	int n;
	int ini;
	int dim;
	int * elem;
};

Queue* queueCreate(){
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->n = 0;
	queue->ini = 0;
	queue->dim = 2;
	queue->elem = (int*)malloc(queue->dim*sizeof(int));
	return queue;
}

int queueIsEmpty(Queue* queue){
	return (queue->n == 0);
}

int queueSize(Queue* queue){
	return(queue->n);
}

void queuePush(Queue* queue, int num)
{
	if (queue->n == queue->dim){
		queue->dim++;
		queue->elem = (int*)realloc(queue->elem, (queue->dim)*sizeof(int));
	}

	queue->elem[queue->n++] = num;
}

int queuePop(Queue* queue){
	int num = queue->elem[queue->ini];
	queue->ini++;
	queue->n--;
	return num;
}

void queueClear(Queue* queue){
	free(queue->elem);
	free(queue);
}

#endif
