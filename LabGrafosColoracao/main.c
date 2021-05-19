#include "caminhamentos.h"
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int i,j;
    int grafo[max+1][max+1];
    TipoVertice vis[max+1];


    //para inicializar o gráfo com 0
    for(i=1;i<=max;i++)
        for(j=1;j<=max;j++)
          grafo[i][j]=0;

//    //############################################################################
//    //NUMERO 1 e 2 DA PROVA
//    grafo[1][2]=1;
//    grafo[1][3]=1;
//
//    grafo[2][1]=1;
//    grafo[2][4]=1;
//
//    grafo[3][1]=1;
//    grafo[3][4]=1;
//    grafo[3][5]=1;
//
//    grafo[4][2]=1;
//    grafo[4][3]=1;
//    grafo[4][5]=1;
//    grafo[4][6]=1;
//
//    grafo[5][3]=1;
//    grafo[5][4]=1;
//    grafo[5][6]=1;
//    grafo[5][7]=1;
//
//    grafo[6][4]=1;
//    grafo[6][5]=1;
//    grafo[6][7]=1;
//
//    grafo[7][5]=1;
//    grafo[7][6]=1;
//    //############################################################################
//############################################################################
    //NUMERO 5 DA PROVA
    grafo[1][2]=1;
    grafo[1][3]=1;
    grafo[1][4]=1;

    grafo[2][1]=1;
    grafo[2][4]=1;
    grafo[2][5]=1;

    grafo[3][1]=1;
    grafo[3][4]=1;
    grafo[3][6]=1;

    grafo[4][1]=1;
    grafo[4][2]=1;
    grafo[4][3]=1;
    grafo[4][5]=1;
    grafo[4][7]=1;

    grafo[5][2]=1;
    grafo[5][4]=1;
    grafo[5][7]=1;

    grafo[6][3]=1;
    grafo[6][7]=1;

    grafo[7][4]=1;
    grafo[7][5]=1;
    grafo[7][6]=1;
    //############################################################################
//    grafo[1][2]=1;
//    grafo[1][3]=1;
//    grafo[1][4]=1;
//
//    grafo[2][1]=1;
//    grafo[2][3]=1;
//    grafo[2][6]=1;
//    grafo[2][8]=1;
//
//    grafo[3][1]=1;
//    grafo[3][2]=1;
//    grafo[3][4]=1;
//    grafo[3][6]=1;
//
//    grafo[4][1]=1;
//    grafo[4][3]=1;
//    grafo[4][5]=1;
//
//    grafo[5][4]=1;
//    grafo[5][6]=1;
//    grafo[5][7]=1;
//    grafo[5][9]=1;
//
//    grafo[6][2]=1;
//    grafo[6][3]=1;
//    grafo[6][5]=1;
//    grafo[6][7]=1;
//    grafo[6][8]=1;
//
//    grafo[7][5]=1;
//    grafo[7][6]=1;
//    grafo[7][8]=1;
//    grafo[7][9]=1;
//
//    grafo[8][2]=1;
//    grafo[8][6]=1;
//    grafo[8][7]=1;
//    grafo[8][9]=1;
//
//    grafo[9][4]=1;
//    grafo[9][5]=1;
//    grafo[9][7]=1;
//    grafo[9][8]=1;
//    grafo[1][2]=1;
//    grafo[1][6]=1;
//    grafo[2][1]=1;
//    grafo[2][3]=1;
//    grafo[2][4]=1;
//    grafo[3][2]=1;
//    grafo[3][5]=1;
//    grafo[3][4]=1;
//    grafo[4][3]=1;
//    grafo[4][2]=1;
//    grafo[4][6]=1;
//    grafo[4][5]=1;
//    grafo[5][4]=1;
//    grafo[5][3]=1;
//    grafo[5][6]=1;
//    grafo[6][1]=1;
//    grafo[6][5]=1;
//    grafo[6][4]=1;
    //#########################DFS#############################
    for (i=1;i<=max;i++){
        vis[i].visitado=false; //inicializando vetor de vertices visitados
        vis[i].cor=false; //inicializando vetor de cores de vertices visitados
    }
    i=1;
    puts("DFS");
    DFS(grafo,i, vis);


    printf("\n\nCores\n");
    for (i=1;i<=max;i++)
        printf("%d - %d\n", i,vis[i].cor); //inicializando vetor de vertices visitados

    //#########################BFS#############################
    for (i=1;i<=max;i++){
        vis[i].visitado=false; //inicializando vetor de vertices visitados
        vis[i].cor=false; //inicializando vetor de cores de vertices visitados
    }

    puts("\n\nBFS");
    i=7;
    BFS(grafo,i, vis);


    printf("\n\nCores\n");
    for (i=1;i<=max;i++)
        printf("%d - %d\n", i,vis[i].cor); //inicializando vetor de vertices visitados
    return 0;
}
