#include "hashPrimeiraPos.h"

int main(){

    Hash* tab = initHashTable();
    printTable(tab);

    person Joao = {.name="Joao", .age=256, .cpf=66774};
    person Katia = {.name="Katia", .age=27, .cpf=39596};
    person Mpho = {.name="Mpho", .age=14, .cpf=12386};
    person Lara = {.name="Lara", .age=54, .cpf=37859};
    person Deive = {.name="Edna", .age=74, .cpf=51378};
    person Felipe = {.name="Maren", .age=10, .cpf=12375};
    person Eduardo = {.name="Eliza", .age=27, .cpf=23457};
    person Lambda = {.name="Robert", .age=53, .cpf=98765};
    person Jussara = {.name="Jane", .age=22, .cpf=41376};

    if(hashTableInsert(tab, &Joao))
        printf("Inserting %s\n", Joao.name);
    else
        printf("Not able to insert %s\n", Joao.name);
    if(hashTableInsert(tab, &Katia))
        printf("Inserting %s\n", Katia.name);
    else
        printf("Not able to insert %s\n", Katia.name);
    if(hashTableInsert(tab, &Mpho))
        printf("Inserting %s\n", Mpho.name);
    else
        printf("Not able to insert %s\n", Mpho.name);
    if(hashTableInsert(tab, &Lara))
        printf("Inserting %s\n", Lara.name);
    else
        printf("Not able to insert %s\n", Lara.name);
    if(hashTableInsert(tab, &Deive))
        printf("Inserting %s\n", Deive.name);
    else
        printf("Not able to insert %s\n", Deive.name);
    if(hashTableInsert(tab, &Felipe))
        printf("Inserting %s\n", Felipe.name);
    else
        printf("Not able to insert %s\n", Felipe.name);
    if(hashTableInsert(tab, &Eduardo))
        printf("Inserting %s\n", Eduardo.name);
    else
        printf("Not able to insert %s\n", Eduardo.name);
    if(hashTableInsert(tab, &Lambda))
        printf("Inserting %s\n", Lambda.name);
    else
        printf("Not able to insert %s\n", Lambda.name);
    if(hashTableInsert(tab, &Jussara))
        printf("Inserting %s\n", Jussara.name);
    else
        printf("Not able to insert %s\n", Jussara.name);

    printTable(tab);

    if(hashTableLookup(tab, 66774) != NULL){
        printf("%s found!\n", "Joao");
    }
    else{
        printf("%s not found!\n", "Joao");
    }

    hashTableDelete(tab, &Joao);
    printf("Deleting Joao\n");

    if(hashTableLookup(tab, 66774) != NULL){
        printf("%s found!\n", "Joao");
    }
    else{
        printf("%s not found!\n", "Joao");
    }

    printTable(tab);

    person Gustavo = {.name="Gustavo", .age=19, .cpf=66717};
    person Janaina = {.name="Janaina", .age=49, .cpf=28920};
    person Talita = {.name="Talita", .age=0, .cpf=99999};

    if(hashTableInsert(tab, &Gustavo))
        printf("Inserting %s\n", Gustavo.name);
    else
        printf("Not able to insert %s\n", Gustavo.name);
    if(hashTableInsert(tab, &Janaina))
        printf("Inserting %s\n", Janaina.name);
    else
        printf("Not able to insert %s\n", Janaina.name);

    printTable(tab);

    if(hashTableInsert(tab, &Talita))
        printf("Inserting %s\n", Talita.name);
    else
        printf("Not able to insert %s\n", Talita.name);

    printTable(tab);
}