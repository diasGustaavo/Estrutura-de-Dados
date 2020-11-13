#ifndef _HASH_DISPERSAO_DUPLA_H_
#define _HASH_DISPERSAO_DUPLA_H_
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
unsigned int hash2(unsigned long int cpf, Hash* tab);
Hash* init_hash_table();
void print_table(Hash* tab);
bool hash_table_insert(Hash *tab, person *v_folk);
static void hash_table_resize(Hash *tab);
person *hash_table_lookup(Hash *tab, unsigned int cpf);
bool hash_table_delete(Hash *tab, person *v_folk);

#endif