#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAXCHAR 1000

int comp;

struct TNodoA{
    char lema[31];//lema em formato de string pra alocar espaço na memoria
    char palavra[31];//palavra em formato de string pra alocar espaço na memoria
    int fator;
    struct TNodoA *esq;
    struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

//Inicializa a arvore
pNodoA* InicializaArvoreAVL(void);
//insere um novo nó na arvore
pNodoA* InsereAVL(pNodoA *nodo, char* chave, char* palavra, int *ok);
//retorna a altura do nodo A
int AlturaAVL (pNodoA *a);
//fator da arvore AVL
int FatorAVL(pNodoA *a);
//retorna 1 se a lista estiver equilibrada e se não estiver retorna 0
int EquilibradaAVL (pNodoA *a);
//consulta para procurar lema na arvore AVL
char* ConsultaAVL(pNodoA *a, char* chave, int *comp);

//##################ROTACOES AVL####################
pNodoA* rotacao_direita(pNodoA* a);

pNodoA* rotacao_esquerda(pNodoA *a);

pNodoA* rotacao_dupla_esquerda (pNodoA *a);

pNodoA* rotacao_dupla_direita (pNodoA* a);

//Caso 1 de inserção
pNodoA* Caso1 (pNodoA *a, int *ok);
//Caso 2 de inserção
pNodoA* Caso2 (pNodoA *a, int *ok);
