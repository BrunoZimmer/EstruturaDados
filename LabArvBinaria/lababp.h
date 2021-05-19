struct TNodoA
{
    int chave;
    struct TNodoA *esq;
    struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

//Inicializa a arvore
pNodoA* InicializaArvore(void);
//insere um novo n� na arvore
pNodoA* InsereArvore(pNodoA *nodo, int chave);
//printa os elementos da arvore no caminhamento pre fixado a esquerda
void PrintPreFixadoEsquerda(pNodoA *nodo);
//print pre fixado a esquerda s� que com "=" mostrando o nivel do n�
void PrintComNivel(pNodoA *nodo, int nivel);
//conta quantidade de elementos na arvore
int ContadorNodos(pNodoA *nodo, int nivel);
