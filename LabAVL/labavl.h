struct TNodoA
{
    int chave;
    int fator;
    struct TNodoA *esq;
    struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

//Inicializa a arvore
pNodoA* InicializaArvore(void);
//insere um novo nó na arvore
pNodoA* InsereArvore(pNodoA *nodo, int chave);

pNodoA* Caso1(pNodoA *a, int *ok);

pNodoA* Caso2(pNodoA *a, int *ok);

void verificaAVL(pNodoA *a);

pNodoA* InsereAVL(pNodoA *nodo, int chave, int *ok);
//printa os elementos da arvore no caminhamento pre fixado a esquerda
void PrintPreFixadoEsquerda(pNodoA *nodo);

void PrintPosFixadoEsquerda(pNodoA *nodo);

void PrintCentralDireita(pNodoA *nodo);

void PrintCentralEsquerda(pNodoA *nodo);
//print pre fixado a esquerda só que com "=" mostrando o nivel do nó
void PrintComNivel(pNodoA *nodo, int nivel);
//conta quantidade de elementos na arvore
int ContadorNodos(pNodoA *nodo, int nivel);
//retorna a altura do nodo A
int Altura (pNodoA *a);
//retorna o fator do nodo A
int Fator(pNodoA *a);
//retorna o fator da arvore
int FatorArvore(pNodoA *a);
//retorna 1 se a lista estiver equilibrada e se não estiver retorna 0
int Equilibrada(pNodoA *a);

pNodoA* consultaABP(pNodoA* a, int chave);

pNodoA* ArvoreInterseccao(pNodoA *a, pNodoA *a2);

void intersect (pNodoA* a, pNodoA *b,  pNodoA **c);

int Compara (pNodoA *a, pNodoA *b);

//##################ROTACOES AVL####################
pNodoA* rotacao_direita(pNodoA* a);

pNodoA* rotacao_esquerda(pNodoA *a);

pNodoA* rotacao_dupla_esquerda (pNodoA *a);

pNodoA* rotacao_dupla_direita (pNodoA* a);

int xxx(pNodoA *a);

void PrintIntervalo(pNodoA *nodo, int menor, int maior);

void PosicaoNodo(pNodoA *nodo, int n, int k);

int imprime_nesimo(pNodoA *a, int n);

void fatorizaArvore(pNodoA **a);
