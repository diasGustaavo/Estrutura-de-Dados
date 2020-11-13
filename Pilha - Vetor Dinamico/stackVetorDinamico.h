#ifndef _STACKVETORDINAMICO_H_
#define _STACKVETORDINAMICO_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct stack Stack;

Stack* stackCreate();
int stackIsEmpty(Stack* p);
int stackSize(Stack* st);
void stackPush(Stack* stack, int v);
int stackPop(Stack* p);
void stackClear(Stack* p);

int stackSize(Stack* p);

#endif
