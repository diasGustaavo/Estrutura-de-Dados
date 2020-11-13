#include "stackVetorDinamico.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  Stack *st = stackCreate();

  stackPush(st, 2);
  printf("push valor: %d\n", 2);

  printf("tamanho da stack: %d\n", stackSize(st));

  stackPush(st, 3);
  printf("push valor: %d\n", 3);

  printf("tamanho da stack: %d\n", stackSize(st));

  stackPush(st, 4);
  printf("push valor: %d\n", 4);

  printf("tamanho da stack: %d\n", stackSize(st));

  stackPush(st, 5);
  printf("push valor: %d\n", 5);

  printf("tamanho da stack: %d\n", stackSize(st));

  stackPush(st, 6);
  printf("push valor: %d\n", 6);

  printf("tamanho da stack: %d\n", stackSize(st));

  stackClear(st);

  Stack *st2 = stackCreate(1);

  printf("\n\ntamanho: %d\n", stackSize(st2));

  stackPush(st2, 2);
  printf("push valor: %d\n", 2);

  printf("tamanho da stack: %d\n", stackSize(st2));

  stackPush(st2, 3);
  printf("push valor: %d\n", 3);

  printf("tamanho da stack: %d\n", stackSize(st2));

  stackPush(st2, 4);
  printf("push valor: %d\n", 4);

  printf("tamanho da stack: %d\n", stackSize(st2));

  stackPush(st2, 5);
  printf("push valor: %d\n", 5);

  printf("tamanho da stack: %d\n", stackSize(st2));

  stackPush(st2, 6);
  printf("push valor: %d\n", 6);

  printf("tamanho da stack: %d\n", stackSize(st2));

  int i;
  for (i = 1; i < 6; i++)
  {
      printf("popping %d\n", stackPop(st2));
      printf("tamanho: %d\n\n", stackSize(st2));
  }

  return 0;
}