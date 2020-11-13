#ifndef _STACKLISTAENCADEADA_H_
#define _STACKLISTAENCADEADA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct stack Stack;

Stack * stackCreate(int info);
int stackIsEmpty(Stack* st);
int stackSize(Stack* st);
int stackPush(Stack* st, int info);
int stackPop(Stack** st);
void stackClear(Stack** st);

#endif
