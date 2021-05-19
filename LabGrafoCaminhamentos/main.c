#include "Fila.h"


int main(){
    int i,j, k, n=tamanho, inicial = 1;
    int vetorVisitadoDFS[tamanho]= {0, 0, 0, 0, 0, 0, 0, 0};
    int vetorVisitadoBFS[tamanho]= {0, 0, 0, 0, 0, 0, 0, 0};

    TipoDFila *Fila;
    int matrizBFS[tamanho][tamanho] ={
    {0,1,1,0,0,0,0,0},
    {0,0,0,1,0,0,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,0,1,1,0,1},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0},
    {0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0},
    };
//DFS 1 2 4 5 6 8 7 3
//BFS 1 2 3 4 5 6 8 7

    printf("\nDFS\n");
    DFS(matrizBFS, vetorVisitadoDFS, 0);

    Fila = InicializaFila(Fila);
    printf("\n\nBFS\n");
    BFS(matrizBFS,0, vetorVisitadoBFS, Fila);

    return 0;
}
