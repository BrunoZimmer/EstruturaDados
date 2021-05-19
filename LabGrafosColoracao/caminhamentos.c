#include <stdio.h>
#include <stdlib.h>
#include "caminhamentos.h"


int FonteOuSumidouro(int grafo[max][max], int v){
    int i, ok;

    for( i=0, ok=0 ; i<max && ok==0 ; i++ )    //percorre os vértices adjacentes a v
      if (grafo[v][i] == 1)
        ok = 1;

    if(ok == 0)
        return 1;

    for( i=0, ok=0 ; i<max && ok==0 ; i++ )    //percorre os vértices adjacentes a v
      if (grafo[i][v] == 1)
        ok = 1;

    if(ok == 0)
        return -1;

    return 0;

}

TipoVertice* ColorirDFS(int grafo[max+1][max+1], int v, TipoVertice vis[max+1]){
    int cor[5], i;

    for(i=0;i<=5;i++)
        cor[i] = 0;

    for( i=1 ; i<=max ; i++ )    //percorre os vértices adjacentes a v
      if (grafo[v][i]== 1){
        cor[vis[i].cor] = 1;
      }

    for( i=1 ; i<=4 ; i++ ){
        if(cor[i] != 1){
            vis[v].cor = i;
            vis[v].visitado = true;
            break;
        }
    }
    return vis;
}

void DFS (int grafo[max+1][max+1], int v, TipoVertice vis[max+1])
{
    int w;
    printf("%d ",v);
    vis = ColorirDFS(grafo, v, vis);

    for(w = 1; w<=max ; w++)    //percorre os vértices adjacentes a v
      if ((grafo[v][w]== 1) && (vis[w].visitado ==false))  //encontra um vértice adjacente a v que ainda nao tenha sido visitado
         DFS(grafo, w, vis); //chamada recursiva para o vértice adjacente a v
}



void BFS (int grafo[max+1][max+1], int v, TipoVertice vis[max+1])
{
    int w;
    TipoFila *FV;

    FV = cria_fila();
    FV = insere(FV,v);
    vis[v].visitado  = true;
    while (!vazia(FV))
    {
        v = removeFila(&FV);
        printf("%d ",v);
        vis = ColorirDFS(grafo, v, vis);
        for(w = 1; w<=max ; w++)//percorre os vértices adjacentes a v
            if ((grafo[v][w]== 1) && (vis[w].visitado ==false))  //encontra um vértice adjacente a v que ainda nao tenha sido visitado
            {
                FV = insere(FV,w);
                vis[w].visitado = true;
            }

    }
}

