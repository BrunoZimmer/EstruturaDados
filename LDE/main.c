#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LDE.h"

int main()
{
    PtNo *PtLista;
    InfoNo dado;

    PtLista = Inicializa();

    dado.codigo=3;
    strcpy(dado.nome, "caneta");
    dado.preco=2.5;

    PtLista = InsereOrdenado(PtLista, dado);
//    Imprime(PtLista);
//    ImprimeInvertida(PtLista);

    dado.codigo=1;
    strcpy(dado.nome, "lapis");
    dado.preco=1.5;

    PtLista = InsereOrdenado(PtLista, dado);
//    Imprime(PtLista);
//    ImprimeInvertida(PtLista);

    dado.codigo=4;
    strcpy(dado.nome, "teclado");
    dado.preco=100;

    PtLista = InsereOrdenado(PtLista, dado);
//    Imprime(PtLista);
//    ImprimeInvertida(PtLista);

    dado.codigo=2;
    strcpy(dado.nome, "mouse");
    dado.preco=55;

    PtLista = InsereOrdenado(PtLista, dado);
    Imprime(PtLista);
    ImprimeInvertida(PtLista);

    PtLista = Remover(PtLista, 3);
    Imprime(PtLista);
    PtLista = Remover(PtLista, 1);
    Imprime(PtLista);
    PtLista = Remover(PtLista, 2);
    Imprime(PtLista);
    PtLista = Remover(PtLista, 4);
    Imprime(PtLista);

    printf("Fim!");
    return 0;
}
