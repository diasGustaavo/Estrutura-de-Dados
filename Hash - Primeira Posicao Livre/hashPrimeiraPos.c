#ifndef _HASH_PRIMEIRA_POS_C_
#define _HASH_PRIMEIRA_POS_C_

#include "hashPrimeiraPos.h"

unsigned int hash(unsigned long int cpf, Hash* tab){
    return(cpf % tab->dim);
}

Hash* initHashTable(){
    Hash* tab = (Hash*)malloc(sizeof(Hash));
    tab->n = 0;
    tab->dim = 10;
    tab->folk = (person**)malloc(tab->dim*sizeof(person*));
    for(int i = 0; i < tab->dim; i++){
        tab->folk[i] = NULL;
    }
    return tab;
}

void printTable(Hash* tab){
    printf("\n\n----START----\n");
    for(int i = 0; i < tab->dim; i++){
        if(tab->folk[i] == NULL){
            printf("\t%i\t----\n", i);
        }
        else if(tab->folk[i] == DELETED_NODE){
            printf("\t%i\t<DELETED>\n", i);
        }
        else{
            printf("\t%i\t%s\n", i, tab->folk[i]->name);
        }
    }
    printf("----END----\n");
}

bool hashTableInsert(Hash *tab, person *v_folk){
    if(v_folk == NULL)
        return false;
    if(tab->dim == tab->n)
        hashTableResize(tab);
    int index = hash(v_folk->cpf, tab);
    for(int i = 0; i < tab->dim; i++){
        int try = (i + index) % tab->dim;
        if(tab->folk[try] == NULL || tab->folk[try] == DELETED_NODE){
            tab->folk[try] = v_folk;
            tab->n++;
            return true;
        }
    }
    return false;
}

static void hashTableResize(Hash *tab){
    int max_ant = tab->dim;
    person **folkAnt = tab->folk;
    tab->n = 0;
    tab->dim *= 2;
    tab->folk = (person**)malloc(tab->dim*sizeof(person*));
    for (int i = 0; i < tab->dim; ++i)
        tab->folk[i] = NULL;
    for (int i = 0; i < max_ant; ++i)
    {
        if (folkAnt[i])
        {
            hashTableInsert(tab, folkAnt[i]);
        }
    }
    free(folkAnt);
}

person *hashTableLookup(Hash *tab, unsigned long int cpf){
    int index = hash(cpf, tab);
    for(int i = 0; i < tab->dim; i++){
        int try = (index + i) % tab->dim;
        if(tab->folk[try] == NULL){
            return false;
        }
        if(tab->folk[try] == DELETED_NODE){
            continue;
        }
        if(tab->folk[try] != NULL && tab->folk[try]->cpf == cpf){
            return tab->folk[try];
        }
    }
    return NULL;
}

bool hashTableDelete(Hash *tab, person *v_folk){
    int index = hash(v_folk->cpf, tab);
    for(int i = 0; i < tab->dim; i++){
        int try = (index + i) % tab->dim;
        if(tab->folk[try] == NULL){
            return NULL;
        }
        if(tab->folk[try] == DELETED_NODE){
            continue;
        }
        if(tab->folk[try] != NULL && (v_folk->cpf == tab->folk[try]->cpf)){
            tab->folk[try] = DELETED_NODE;
            tab->n--;
            return true;
        }
    }
    return false;
}

#endif