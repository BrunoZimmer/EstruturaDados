#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"


int main (){
    TipoPilha *p1, *p2, *p3, *p4;
    TipoInfo dado;

    int resultado;

    p1 = InicializaPilha();
//  declaração dos items da pilha 1

    dado = 1;
    p1 = PushPilha(p1,dado);
    dado = 2;
    p1 = PushPilha(p1,dado);
    dado = 3;
    p1 = PushPilha(p1,dado);
    dado = 4;
    p1 = PushPilha(p1,dado);

//    ImprimirPilha(p1);

    p2 = InicializaPilha();
//  declaração dos items da pilha 2

    dado = 2;
    p2 = PushPilha(p2,dado);
    dado = 3;
    p2 = PushPilha(p2,dado);
    dado = 4;
    p2 = PushPilha(p2,dado);

//    ImprimirPilha(p2);

    p3 = InicializaPilha();
//  declaração dos items da pilha 3

    dado = 4;
    p3 = PushPilha(p3,dado);
    dado = 3;
    p3 = PushPilha(p3,dado);
    dado = 2;
    p3 = PushPilha(p3,dado);
    dado = 1;
    p3 = PushPilha(p3,dado);

//    ImprimirPilha(p3);

    p4 = InicializaPilha();
//  declaração dos items da pilha 4

    dado = 4;
    p4 = PushPilha(p4,dado);
    dado = 3;
    p4 = PushPilha(p4,dado);
    dado = 2;
    p4 = PushPilha(p4,dado);
    dado = 1;
    p4 = PushPilha(p4,dado);

//    ImprimirPilha(p4);

    resultado = Compara(p1, p2);
    if(resultado)
        printf("p1 e p2:\nIguais\n\n");
    else
        printf("p1 e p2:\nNao iguais\n\n");


    resultado = Compara(p3, p4);
    if(resultado)
        printf("p3 e p4:\nIguais\n\n");
    else
        printf("p3 e p4:\nNao iguais\n\n");

    return 0;
}
