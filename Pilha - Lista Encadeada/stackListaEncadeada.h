#ifndef _STACKLISTAENCADEADA_H_
#define _STACKLISTAENCADEADA_H_

typedef struct stack Stack;

Stack * stack_create(int info);
int stack_is_empty(Stack* st);
int stack_size(Stack* st);
int stack_push(Stack* st, int info);
int stack_pop(Stack** st);
void stack_clear(Stack** st);

#endif
