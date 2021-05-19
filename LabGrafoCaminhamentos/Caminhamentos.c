#include "Fila.h"

void DFS(int grafo[tamanho][tamanho], int visitados[tamanho], int vertice){
    int i;

    visitados[vertice] = 1;
    printf("Visitado %d\n", vertice+1);

    for(i=0;i<tamanho; i++){
        if (visitados[i] != 1 && grafo[vertice][i] == 1) {
            DFS(grafo, visitados, i);
        }
    }
}


void BFS(int grafo[tamanho][tamanho], int vertice, int *visitados, TipoDFila *Fila){
    int i;

    visitados[vertice]=1;
    InserirFila(&Fila, vertice);

    while(!VaziaFila(Fila)){
        RemoverFila(&Fila, &vertice);
        printf("Visitado %d\n", vertice+1);

        for ( i=0; i<tamanho; i++){
            if(grafo[vertice][i]==1 && visitados[i]==0){
                InserirFila(&Fila, i);
                visitados[i]=1;
            }
        }
    }
}
