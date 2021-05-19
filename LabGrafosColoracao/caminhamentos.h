#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define max 7
#define true 1
#define false 0

struct sTipoVertice{
    int visitado;
    int cor;
};typedef struct sTipoVertice TipoVertice;

void DFS (int grafo[max+1][max+1], int v, TipoVertice vis[max+1]);
void BFS (int grafo[max+1][max+1], int v, TipoVertice vis[max+1]);

TipoVertice* ColorirDFS(int grafo[max+1][max+1], int v, TipoVertice vis[max+1]);
TipoVertice* ColorirBFS(int grafo[max+1][max+1], int v, TipoVertice vis[max+1]);

int FonteOuSumidouro(int grafo[max][max], int v);
