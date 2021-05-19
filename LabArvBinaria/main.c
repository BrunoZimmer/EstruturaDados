#include <stdio.h>
#include <stdlib.h>
#include "lababp.h"


int main(){
    pNodoA *arvore;
    int quantidade;

    arvore = InicializaArvore();

    arvore = InsereArvore(arvore, 8);
    arvore = InsereArvore(arvore, 4);
    arvore = InsereArvore(arvore, 9);
    arvore = InsereArvore(arvore, 2);
    arvore = InsereArvore(arvore, 6);
    arvore = InsereArvore(arvore, 1);

    printf("\n###########################\n");
    PrintPreFixadoEsquerda(arvore);
    printf("\n###########################\n");
    PrintComNivel(arvore, 0);
    printf("###########################\n");
    quantidade = ContadorNodos(arvore, 0);
    printf("Existem %d\ nodos\n", quantidade);
    printf("###########################\n");


    return 0;
}
