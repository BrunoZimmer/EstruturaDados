#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lababp.h"

pNodoA* InicializaArvore(void){
    return NULL;
}

pNodoA* InsereArvore(pNodoA *nodo, int chave){
    if (!nodo){
        nodo = (pNodoA*) malloc(sizeof(pNodoA));
        nodo->chave = chave;
        nodo->esq = NULL;
        nodo->dir = NULL;
    }
    else if (chave < nodo->chave)
        nodo->esq = InsereArvore(nodo->esq,chave);
    else
        nodo->dir = InsereArvore(nodo->dir,chave);
    return nodo;
}

void PrintPreFixadoEsquerda(pNodoA *nodo){
    if (nodo){
        printf("%d ",nodo->chave);
        PrintPreFixadoEsquerda(nodo->esq);
        PrintPreFixadoEsquerda(nodo->dir);
    }
}

void PrintComNivel(pNodoA *nodo, int nivel){
    int i;
    if (nodo){
        nivel+=1;
        for(i = nivel; i>0; i--)
            printf("=");

        printf("%d\n",nodo->chave);
        PrintComNivel(nodo->esq, nivel);
        PrintComNivel(nodo->dir, nivel);
    }
}


int ContadorNodos(pNodoA *nodo, int nivel){
    int a, b;
    if(nivel == 0){
        a = 0;
        b = 0;
    }

    if (nodo){
        if(nodo->esq)
            a += ContadorNodos(nodo->esq, nivel);
        if(nodo->dir)
            b += ContadorNodos(nodo->dir, nivel);
    }

    return a+b+1;
}
