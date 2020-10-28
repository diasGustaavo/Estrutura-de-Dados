#include "stackListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Stack* st = stack_create(1);

    if(stack_push(st, 2))
      printf("push valor: %d\n", 2);

    printf("tamanho da stack: %d\n", stack_size(st));

    if(stack_push(st, 3))
      printf("push valor: %d\n", 3);

    printf("tamanho da stack: %d\n", stack_size(st));

    if(stack_push(st, 4))
      printf("push valor: %d\n", 4);

    printf("tamanho da stack: %d\n", stack_size(st));

    if(stack_push(st, 5))
      printf("push valor: %d\n", 5);

    printf("tamanho da stack: %d\n", stack_size(st));

    if(stack_push(st, 6))
      printf("push valor: %d\n", 6);

    printf("tamanho da stack: %d\n", stack_size(st));

    stack_clear(&st);

    Stack* st2 = stack_create(1);

    printf("\n\ntamanho: %d\n", stack_size(st2));

    if(stack_push(st2, 2))
      printf("push valor: %d\n", 2);

    printf("tamanho da stack: %d\n", stack_size(st2));

    if(stack_push(st2, 3))
      printf("push valor: %d\n", 3);

    printf("tamanho da stack: %d\n", stack_size(st2));

    if(stack_push(st2, 4))
      printf("push valor: %d\n", 4);

    printf("tamanho da stack: %d\n", stack_size(st2));

    if(stack_push(st2, 5))
      printf("push valor: %d\n", 5);

    printf("tamanho da stack: %d\n", stack_size(st2));

    if(stack_push(st2, 6))
      printf("push valor: %d\n", 6);

    printf("tamanho da stack: %d\n", stack_size(st2));


   int i;
    for(i=1; i <=6; i++){
      if(stack_pop(&st2))
            printf("valor: %d tamanho: %d\n", i, stack_size(st2));
    }

 return 0;   
}
