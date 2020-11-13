#include "queueVetorDinamico.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  Queue *que = queueCreate();

  queuePush(que, 2);
  printf("push valor: %d\n", 2);

  printf("tamanho da queue: %d\n", queueSize(que));

  queuePush(que, 3);
  printf("push valor: %d\n", 3);

  printf("tamanho da queue: %d\n", queueSize(que));

  queuePush(que, 4);
  printf("push valor: %d\n", 4);

  printf("tamanho da queue: %d\n", queueSize(que));

  queuePush(que, 5);
  printf("push valor: %d\n", 5);

  printf("tamanho da queue: %d\n", queueSize(que));

  queuePush(que, 6);
  printf("push valor: %d\n", 6);

  printf("tamanho da queue: %d\n", queueSize(que));

  queueClear(que);

  Queue *que2 = queueCreate();

  printf("push valor: %d\n", 2);
  queuePush(que2, 2);
  printf("tamanho da queue: %d\n", queueSize(que2));

  printf("push valor: %d\n", 3);
  queuePush(que2, 3);
  printf("tamanho da queue: %d\n", queueSize(que2));

  printf("push valor: %d\n", 4);
  queuePush(que2, 4);
  printf("tamanho da queue: %d\n", queueSize(que2));

  queuePush(que2, 5);
  printf("push valor: %d\n", 5);

  printf("tamanho da queue: %d\n", queueSize(que2));

  queuePush(que2, 6);
  printf("push valor: %d\n", 6);

  printf("tamanho da queue: %d\n", queueSize(que2));

  int i;
  for (i = 1; i < 6; i++)
  {
      printf("popping %d\n", queuePop(que2));
      printf("tamanho da queue: %d\n\n", queueSize(que2));
  }

  return 0;
}