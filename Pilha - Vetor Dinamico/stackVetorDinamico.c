#ifndef _STACKVETORDINAMICO_C_
#define _STACKVETORDINAMICO_C_

#include "stackVetorDinamico.h"

struct stack
{
	int n;
	int dim;
	int * elem;
};

Stack* stackCreate(){
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->n = 0;
	stack->dim = 2;
	stack->elem = (int*)malloc(stack->dim*sizeof(int));
	return stack;
}

int stackIsEmpty(Stack* stack){
	return (stack->n == 0);
}

int stackSize(Stack* stack){
	return(stack->n);
}

void stackPush(Stack* stack, int num)
{
	if (stack->n == stack->dim){
		stack->dim++;
		stack->elem = (int*)realloc(stack->elem, stack->dim*sizeof(int));
	}

	stack->elem[stack->n++] = num;
}

int stackPop(Stack* stack){
	int num = stack->elem[--stack->n];
	return num;
}

void stackClear(Stack* stack){
	free(stack->elem);
	free(stack);
}

#endif
