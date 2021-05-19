#include <stdio.h>
#include <stdlib.h>
#include "lababp.h"

int main(){
    pNodoA *arvore, *arvore2, *arvore3, *arvore4, *arvore5;
    int fator, fator2, ok;

    arvore = InicializaArvore();

    arvore = InsereArvore(arvore, 35);
    arvore = InsereArvore(arvore, 2);
    arvore = InsereArvore(arvore, 71);
    arvore = InsereArvore(arvore, 6);
    arvore = InsereArvore(arvore, 49);
    arvore = InsereArvore(arvore, 73);
    arvore = InsereArvore(arvore, 28);
    arvore = InsereArvore(arvore, 44);
    arvore = InsereArvore(arvore, 50);

//    printf("\nFator da Arvore A\n###########################\n");
//    PrintComNivel(arvore, 0);
//    printf("###########################\n");
//    fator = FatorArvore(arvore);
//    printf("O fator e %d\n", fator);
//    printf("###########################\n");

//    printf("\n####################### ABP #####################\n");
    arvore2 = InicializaArvore();

    arvore2 = InsereArvore(arvore2, 1);
    arvore2 = InsereArvore(arvore2, 2);
    arvore2 = InsereArvore(arvore2, 3);
    arvore2 = InsereArvore(arvore2, 4);
    arvore2 = InsereArvore(arvore2, 5);
    arvore2 = InsereArvore(arvore2, 6);
    arvore2 = InsereArvore(arvore2, 7);

//    PrintComNivel(arvore2, 0);
    printf("\n#################### AVL BALANCEADA ########################\n");

    arvore5 = InicializaArvore();

    arvore5 = InsereAVL(arvore5, 3, &ok);
    arvore5 = InsereAVL(arvore5, 4, &ok);
    arvore5 = InsereAVL(arvore5, 5, &ok);
    arvore5 = InsereAVL(arvore5, 6, &ok);
    arvore5 = InsereAVL(arvore5, 7, &ok);
    arvore5 = InsereAVL(arvore5, 8, &ok);
    arvore5 = InsereAVL(arvore5, 9, &ok);
    arvore5 = InsereAVL(arvore5, 10, &ok);
    arvore5 = InsereAVL(arvore5, 11, &ok);
    arvore5 = InsereAVL(arvore5, 12, &ok);
    arvore5 = InsereAVL(arvore5, 13, &ok);
    arvore5 = InsereAVL(arvore5, 14, &ok);
    arvore5 = InsereAVL(arvore5, 1, &ok);
    arvore5 = InsereAVL(arvore5, 2, &ok);
    arvore5 = InsereAVL(arvore5, 15, &ok);
    arvore5 = InsereAVL(arvore5, 16, &ok);
    arvore5 = InsereAVL(arvore5, 17, &ok);
    arvore5 = InsereAVL(arvore5, 18, &ok);

    PrintCentralEsquerda(arvore5);

//    printf("\nFator da Arvore B\n###########################\n");
    PrintComNivel(arvore5, 0);
//    printf("###########################\n");
//    fator = FatorArvore(arvore2);
//    printf("O fator e %d\n", fator);
//    printf("###########################\n");


    arvore3 = InicializaArvore();

    arvore3 = InsereArvore(arvore3, 30);
    arvore3 = InsereArvore(arvore3, 20);
    arvore3 = InsereArvore(arvore3, 10);
    arvore3 = InsereArvore(arvore3, 15);
    arvore3 = InsereArvore(arvore3, 25);
    arvore3 = InsereArvore(arvore3, 23);
    arvore3 = InsereArvore(arvore3, 39);
    arvore3 = InsereArvore(arvore3, 35);
    arvore3 = InsereArvore(arvore3, 42);

//    printf("\nFator da Arvore A\n###########################\n");
//    PrintComNivel(arvore3, 0);
//    printf("###########################\n");
//    fator = FatorArvore(arvore3);
//    printf("O fator e %d\n", fator);
//    printf("###########################\n");

    arvore4 = InicializaArvore();
//    intersect(arvore, arvore2, &arvore4);

//    printf("\nFator da Arvore 4\n###########################\n");
//    PrintComNivel(arvore4, 0);

//    fator = Compara(arvore3, arvore3);
//    printf("Elas sao iguais = %d\n", fator);

//    PrintPreFixadoEsquerda(arvore3);
//    fator2 = Fator(arvore3);
//    printf("\n############################################\n");



//    PrintPosFixadoEsquerda(arvore3);
//    fator = xxx(arvore3);
//    printf("\n\nRESPOSTAAA = %d", fator);


//    printf("\n############################################\n");
//    PrintComNivel(arvore, 0);
//    printf("\n############################################\n");
//    PrintIntervalo(arvore2, 10, 50);
//    printf("\n############################################\n");
//    PrintIntervalo(arvore2, 5, 30);
//    printf("\n############################################\n");
//    PrintIntervalo(arvore2, 1, 4);
//    printf("\n############################################\n");
//    PrintIntervalo(arvore2, 0, 100);


//    printf("\n############################################\n");
//    PrintComNivel(arvore2, 0);
//    printf("\n############################################\n");
//    PosicaoNodo(arvore2, 0, 0);
//    fator = imprime_maior(arvore2, 6);
//
//    arvore3 = rotacao_dupla_direita(arvore3);
//    PrintComNivel(arvore3, 0);
//    fator = FatorArvore(arvore3);
//    printf("\nFATOR = %d\n############################################\n", fator);

//    PrintComNivel(arvore2, 0);
//    fator2 = Fator(arvore2);
//    printf("\nFATOR = %d\n############################################\n", fator2);
//
//    arvore2->dir = rotacao_esquerda(arvore2->dir);
//    PrintComNivel(arvore2, 0);
//    fator = FatorArvore(arvore2);
//    printf("\nFATOR = %d\n############################################\n", fator);
//    return 0;

//    PrintPreFixadoEsquerda(arvore);
//    printf("\n############################################\n");
//    PrintCentralDireita(arvore);
//    printf("\n############################################\n");
//    PrintPosFixadoEsquerda(arvore);

    fator = FatorArvore(arvore);
    printf("%d\n", fator);
}

