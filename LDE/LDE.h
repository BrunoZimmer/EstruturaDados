struct TipoInfoNo{
    int codigo;
    char nome[20];
    float preco;
};
typedef struct TipoInfoNo InfoNo;

struct TipoPtNo{
	InfoNo info;
	struct TipoPtNo* ant;
	struct TipoPtNo* prox;
};
typedef struct TipoPtNo PtNo;

PtNo* Inicializa(void);
PtNo* Destroi(PtNo* PtLista);
PtNo* Remover(PtNo *PtLista, int codigo);

PtNo* InsereFinal(PtNo* PtLista, InfoNo Dado);
PtNo* InsereOrdenado(PtNo* PtLista, InfoNo Dado);

void Imprime(PtNo* PtLista);
void ImprimeInvertida(PtNo* PtLista);
