#include <stdio.h>
#include <stdlib.h>
#include "LDE.h"


PtNo* Inicializa(void){
    return NULL;
}

PtNo* Destroi(PtNo* PtLista){
    PtNo *PtAux;

    while(PtLista){
        PtAux = PtLista;
        PtLista = PtLista->prox;
        free(PtAux);
    }
    free(PtLista);
    return NULL;
}

PtNo* Remover(PtNo *PtLista, int codigo){
    PtNo *PtAux = PtLista;

    while(PtAux->info.codigo != codigo){
        PtAux = PtAux->prox;
    }
    if(PtAux->prox)
        PtAux->prox->ant = PtAux->ant;
    if(PtAux->ant)
        PtAux->ant->prox = PtAux->prox;
    else{
        free(PtAux);
        return PtLista->prox;
    }


    free(PtAux);

    return PtLista;
}

void Imprime(PtNo* PtLista){
    PtNo *PtAux = PtLista;

    if(PtLista==NULL)
        puts("lista vazia");
    else{
        printf("****************************************\n");
        do {
            printf("Codigo=%d \nNome=%s \nPreco=%.2f \n\n",
                PtAux->info.codigo,
                PtAux->info.nome,
                PtAux->info.preco);
            PtAux = PtAux->prox;
        }while(PtAux!=NULL);
    }
}

void ImprimeInvertida(PtNo* PtLista){
    PtNo *PtAux = PtLista;

    if(PtLista==NULL)
        puts("lista vazia");
    else{
        while(PtAux->prox!=NULL)
            PtAux=PtAux->prox;
        printf("****************************************\n");
        while(PtAux) {
            printf("Codigo=%d \n Nome=%s \nPreco=%.2f \n\n",
                PtAux->info.codigo,
                PtAux->info.nome,
                PtAux->info.preco);
            PtAux = PtAux->ant;
        }
    }
}

PtNo* InsereFinal(PtNo* PtLista, InfoNo Dado){
    PtNo *novo, *PtAux;

    novo = (PtNo*)malloc(sizeof(PtNo));
    novo->info = Dado;
    novo->prox = NULL;

    if(PtLista == NULL){
        PtLista = novo;
        novo->ant=NULL;
    }else {
        PtAux = PtLista;
        while (PtAux->prox)
            PtAux=PtAux->prox;
        PtAux->prox=novo;
        novo->ant=PtAux;
    }
    return PtLista;
}

PtNo* InsereOrdenado(PtNo* PtLista, InfoNo Dado){
    PtNo *novo, *PtAux = PtLista;

    novo = (PtNo*)malloc(sizeof(PtNo));
    novo->info = Dado;

    if(!PtAux){
        novo->prox=NULL;
        novo->ant=NULL;
        PtLista = novo;
        return novo;
    }

    while(PtAux && PtAux->prox && novo->info.codigo >= PtAux->info.codigo) {
        PtAux = PtAux->prox;
    }
    if (PtAux->ant && PtAux && novo->info.codigo <= PtAux->info.codigo) { //no meio
        novo->ant = PtAux->ant;
        PtAux->ant->prox = novo;
        PtAux->ant = novo;
        novo->prox = PtAux;
    } else if (!PtAux->prox && PtAux && novo->info.codigo >= PtAux->info.codigo) {// no final
        novo->prox = NULL;
        PtAux->prox = novo;
        novo->ant = PtAux;
    } else { // no inicio
        novo->prox = PtAux;
        novo->ant = NULL;
        PtAux->ant = novo;
        PtLista = novo;
    }

    return PtLista;
}



