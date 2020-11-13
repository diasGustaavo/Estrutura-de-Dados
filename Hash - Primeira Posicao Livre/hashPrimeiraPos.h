#ifndef _HASH_PRIMEIRA_POS_H_
#define _HASH_PRIMEIRA_POS_H_
#define MAX_NAME 256
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct{
    char name[MAX_NAME];
    int age;
    unsigned long int cpf;
}person;

typedef struct{
    int n;
    int dim;
    person** folk;
}Hash;

unsigned int hash(unsigned long int cpf, Hash* tab);
Hash* initHashTable();
void printTable(Hash* tab);
bool hashTableInsert(Hash *tab, person *v_folk);
static void hashTableResize(Hash *tab);
person *hashTableLookup(Hash *tab, unsigned long int cpf);
bool hashTableDelete(Hash *tab, person *v_folk);

#endif
