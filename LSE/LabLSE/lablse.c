#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lselab.h"

//Inicializar a lista
TypeLinkedData* InitList( void )
{
    return NULL;
}

//Insert a product in numerical order
TypeLinkedData* InsertProduct ( TypeLinkedData* list, TypeInfoData data ){
    TypeLinkedData *new, *auxPrev = NULL, *aux = list;

    new = (TypeLinkedData *)malloc(sizeof(TypeLinkedData));
    new->info = data;

    if ( !aux ) {
        new->next = NULL;
        aux = new;
        return new;
    }

    aux = list;
    while( aux->next && new->info.codigo >= aux->info.codigo ){
        auxPrev = aux;
        aux = aux->next;
    }

    if (auxPrev && aux && new->info.codigo <= aux->info.codigo) { //no meio
        auxPrev->next = new;
        new->next = aux;
    } else if (!aux->next && new->info.codigo >= aux->info.codigo) {// no final
        new->next = NULL;
        aux->next = new;
    } else { // no inicio
        new->next = aux;
        list = new;
    }

    return list;
};

void ReadData( TypeInfoData *data ){
    printf("Codigo: ");
    scanf("%d", &data->codigo);
    printf("Nome: ");
    fflush(stdin);
    gets(data->nome);
    printf("Preco: ");
    scanf("%d", &data->preco);
    printf("\n");
}

//Print all items of the list
void PrintList (  TypeLinkedData* list )
{
    TypeLinkedData *aux = list;
    if(!list)
        puts("lista vazia");
    else{
        for(aux = list; aux ; aux = aux->next){
            printf("***************************************************************************\n");
            printf(" Codigo: %d\n Nome: %s\n Preco: %d\n \n Endereco: %d\n\n ",
                   aux->info.codigo,
                   aux->info.nome,
                   aux->info.preco,
                   aux);
        }
    }
}

