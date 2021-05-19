#include <stdio.h>
#include <stdlib.h>

#define tamanho 8

typedef int TipoInfo;
typedef struct s_TipoDFila TipoDFila;

TipoDFila* InicializaFila (TipoDFila *PtDFila);
TipoInfo ConsultaFila (TipoDFila *PtDFila);
void ImprimirFila (TipoDFila *PtDFila);
int InserirFila(TipoDFila **PtDFila, TipoInfo Dado);
int RemoverFila(TipoDFila **PtDFila, TipoInfo *Dado);
void DestroiFila (TipoDFila **PtDFila);
int VaziaFila(TipoDFila *PtDFila);


void DFS(int grafo[tamanho][tamanho], int visitados[tamanho], int inicial);

//void BFS(int grafo[8][8], int visitados[8], int vertice, TipoDFila *Fila);
void BFS(int grafo[tamanho][tamanho], int v, int *visitados, TipoDFila *PtDFila);
