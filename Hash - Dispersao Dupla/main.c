#include "hashDispersaoDupla.h"

int main(){

    Hash* tab = init_hash_table();
    print_table(tab);

    person Joao = {.name="Joao", .age=256, .cpf=66774};
    person Katia = {.name="Katia", .age=27, .cpf=39596};
    person Mpho = {.name="Mpho", .age=14, .cpf=12386};
    person Lara = {.name="Lara", .age=54, .cpf=37859};
    person Deive = {.name="Edna", .age=74, .cpf=51378};
    person Felipe = {.name="Maren", .age=10, .cpf=12375};
    person Eduardo = {.name="Eliza", .age=27, .cpf=23457};
    person Lambda = {.name="Robert", .age=53, .cpf=98765};
    person Jussara = {.name="Jane", .age=22, .cpf=41376};

    if(hash_table_insert(tab, &Joao))
        printf("Inserting %s\n", Joao.name);
    else
        printf("Not able to insert %s\n", Joao.name);
    if(hash_table_insert(tab, &Katia))
        printf("Inserting %s\n", Katia.name);
    else
        printf("Not able to insert %s\n", Katia.name);
    if(hash_table_insert(tab, &Mpho))
        printf("Inserting %s\n", Mpho.name);
    else
        printf("Not able to insert %s\n", Mpho.name);
    if(hash_table_insert(tab, &Lara))
        printf("Inserting %s\n", Lara.name);
    else
        printf("Not able to insert %s\n", Lara.name);
    if(hash_table_insert(tab, &Deive))
        printf("Inserting %s\n", Deive.name);
    else
        printf("Not able to insert %s\n", Deive.name);
    if(hash_table_insert(tab, &Felipe))
        printf("Inserting %s\n", Felipe.name);
    else
        printf("Not able to insert %s\n", Felipe.name);
    if(hash_table_insert(tab, &Eduardo))
        printf("Inserting %s\n", Eduardo.name);
    else
        printf("Not able to insert %s\n", Eduardo.name);
    if(hash_table_insert(tab, &Lambda))
        printf("Inserting %s\n", Lambda.name);
    else
        printf("Not able to insert %s\n", Lambda.name);
    if(hash_table_insert(tab, &Jussara))
        printf("Inserting %s\n", Jussara.name);
    else
        printf("Not able to insert %s\n", Jussara.name);

    print_table(tab);

    if(hash_table_lookup(tab, 66774) != NULL){
        printf("%s found!\n", "Joao");
    }
    else{
        printf("%s not found!\n", "Joao");
    }

    hash_table_delete(tab, &Joao);
    printf("Deleting Joao\n");

    if(hash_table_lookup(tab, 66774) != NULL){
        printf("%s found!\n", "Joao");
    }
    else{
        printf("%s not found!\n", "Joao");
    }

    print_table(tab);

    person Gustavo = {.name="Gustavo", .age=19, .cpf=66717};
    person Janaina = {.name="Janaina", .age=49, .cpf=28920};
    person Talita = {.name="Talita", .age=0, .cpf=99999};

    if(hash_table_insert(tab, &Gustavo))
        printf("Inserting %s\n", Gustavo.name);
    else
        printf("Not able to insert %s\n", Gustavo.name);
    if(hash_table_insert(tab, &Janaina))
        printf("Inserting %s\n", Janaina.name);
    else
        printf("Not able to insert %s\n", Janaina.name);

    print_table(tab);

    if(hash_table_insert(tab, &Talita))
        printf("Inserting %s\n", Talita.name);
    else
        printf("Not able to insert %s\n", Talita.name);

    print_table(tab);
}
