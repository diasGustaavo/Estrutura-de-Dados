#ifndef _HASH_DISPERSAO_DUPLA_C_
#define _HASH_DISPERSAO_DUPLA_C_
#include "hashDispersaoDupla.h"

unsigned int hash(unsigned long int cpf, Hash* tab){
    return(cpf % tab->dim);
}

unsigned int hash2(unsigned long int cpf, Hash* tab){
    return tab->dim - 2 - cpf%(tab->dim -2);
}

Hash* init_hash_table(){
    Hash* tab = (Hash*)malloc(sizeof(Hash));
    tab->n = 0;
    tab->dim = 10;
    tab->folk = (person**)malloc(tab->dim*sizeof(person*));
    for(int i = 0; i < tab->dim; i++){
        tab->folk[i] = NULL;
    }
    return tab;
}

void print_table(Hash* tab){
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

bool hash_table_insert(Hash *tab, person *v_folk){
    if(v_folk == NULL)
        return false;
    if(tab->dim == tab->n)
        hash_table_resize(tab);

    int index = hash(v_folk->cpf, tab);
    int try = index % tab->dim;
    if(tab->folk[try] == NULL || tab->folk[try] == DELETED_NODE){
        tab->folk[try] = v_folk;
        tab->n++;
        return true;
    }

    int index2 = hash2(v_folk->cpf, tab);
    int try2 = index2 % tab->dim;
    if(tab->folk[try2] == NULL || tab->folk[try2] == DELETED_NODE){
        tab->folk[try2] = v_folk;
        tab->n++;
        return true;
    }

    return false;
}

static void hash_table_resize(Hash *tab){
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
            hash_table_insert(tab, folkAnt[i]);
        }
    }
    free(folkAnt);
}

person *hash_table_lookup(Hash *tab, unsigned int cpf){
    int index = hash(cpf, tab);
    int try = index % tab->dim;

    if(tab->folk[try] != NULL && tab->folk[try] != DELETED_NODE && cpf == tab->folk[try]->cpf){
        return tab->folk[try];
    }
    else{
        int index2 = hash2(cpf, tab);
        int try2 = index2 % tab->dim;
        if(tab->folk[try2] != NULL && tab->folk[try2] != DELETED_NODE && cpf == tab->folk[try2]->cpf){
            return tab->folk[try2];
        }
        return NULL;
    }
    return NULL;
}

bool hash_table_delete(Hash *tab, person *v_folk){
    int index = hash(v_folk->cpf, tab);
    int try = index % tab->dim;

    if(tab->folk[try] != NULL && tab->folk[try] != DELETED_NODE && v_folk->cpf == tab->folk[try]->cpf){
        tab->folk[try] = DELETED_NODE;
        tab->n--;
        return true;
    }
    else{
        int index2 = hash2(v_folk->cpf, tab);
        int try2 = index2 % tab->dim;
        if(tab->folk[try2] != NULL && tab->folk[try2] != DELETED_NODE && v_folk->cpf == tab->folk[try2]->cpf){
            tab->folk[try2] = DELETED_NODE;
            tab->n--;
            return true;
        }
        return NULL;
    }
    return NULL;
}

#endif