#include "queueListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Queue* st = queueCreate(1);

    if(enqueue(st, 2))
      printf("push valor: %d\n", 2);

    printf("tamanho da queue: %d\n", queueSize(st));

    if(enqueue(st, 3))
      printf("push valor: %d\n", 3);

    printf("tamanho da queue: %d\n", queueSize(st));

    if(enqueue(st, 4))
      printf("push valor: %d\n", 4);

    printf("tamanho da queue: %d\n", queueSize(st));

    if(enqueue(st, 5))
      printf("push valor: %d\n", 5);

    printf("tamanho da queue: %d\n", queueSize(st));

    if(enqueue(st, 6))
      printf("push valor: %d\n", 6);

    printf("tamanho da queue: %d\n", queueSize(st));

    queueClear(&st);

    Queue* st2 = queueCreate(1);

    printf("\n\ntamanho: %d\n", queueSize(st2));

    if(enqueue(st2, 2))
      printf("push valor: %d\n", 2);

    printf("tamanho da queue: %d\n", queueSize(st2));

    if(enqueue(st2, 3))
      printf("push valor: %d\n", 3);

    printf("tamanho da queue: %d\n", queueSize(st2));

    if(enqueue(st2, 4))
      printf("push valor: %d\n", 4);

    printf("tamanho da queue: %d\n", queueSize(st2));

    if(enqueue(st2, 5))
      printf("push valor: %d\n", 5);

    printf("tamanho da queue: %d\n", queueSize(st2));

    if(enqueue(st2, 6))
      printf("push valor: %d\n", 6);

    printf("tamanho da queue: %d\n", queueSize(st2));


   int i;
    for(i=1; i <=6; i++){
      if(dequeue(&st2))
            printf("valor: %d tamanho: %d\n", i, queueSize(st2));
    }

 return 0;   
}
