#include "data.h"

pNodoA* InicializaArvoreAVL(void){
    return NULL;
}

pNodoA* InsereAVL(pNodoA *nodo, char *chave, char *palavra, int *ok){
    if (nodo == NULL){

        nodo = (pNodoA*) malloc(sizeof(pNodoA));
        strcpy(nodo->lema, chave);
        strcpy(nodo->palavra, palavra);
        nodo->fator = 0;
        nodo->esq = NULL;
        nodo->dir = NULL;

        *ok = 1;
    }
    else if(strcmp(nodo->palavra,palavra)>0){
        nodo->fator = FatorAVL(nodo);
        nodo->esq = InsereAVL(nodo->esq, chave, palavra, ok);
        if(*ok){//condicao de continuidade dada quando encontra o lugar de inserir
            switch (nodo->fator) {//condições de altura pra inserção
                case -1:
                    nodo->fator = 0;
                    *ok = 0;
                    break;
                case 0:
                    nodo->fator = 1;
                    break;
                case 1:
                    nodo=Caso1(nodo,ok);
                    break;
            }
        }
    }else{
        nodo->fator = FatorAVL(nodo);
        nodo->dir = InsereAVL(nodo->dir, chave, palavra, ok);
        if(*ok){
            switch (nodo->fator) {
                case 1:
                    nodo->fator = 0;
                    *ok = 0;
                    break;
                case 0:
                    nodo->fator = -1;
                    break;
                case -1:
                    nodo = Caso2(nodo,ok);
                    break;
            }
        }
    }
    return nodo;
};

pNodoA* Caso1 (pNodoA *a, int *ok){//primeiro caso especial de insercao na arvore pra fazer rotações a fim de deixar equilibrada
    pNodoA *aux;
    aux = a->esq;
    if (aux->fator == 1)
        a = rotacao_direita(a);
    else
        a = rotacao_dupla_direita(a);
    a->fator = 0;
    *ok = 0;
    return a;
}

pNodoA* Caso2 (pNodoA *a, int *ok){//segundo caso especial de insercao na arvore pra fazer rotações a fim de deixar equilibrada
    pNodoA *aux;
    aux = a->dir;
    if (aux->fator == -1)
        a = rotacao_esquerda(a);
    else
        a = rotacao_dupla_esquerda(a);
    a->fator = 0;
    *ok = 0;
    return a;
}

int AlturaAVL(pNodoA *a){//retorna altura
    int Alt_Esq, Alt_Dir;

    if (!a)
        return 0;

    Alt_Esq = AlturaAVL (a->esq);
    Alt_Dir = AlturaAVL (a->dir);

    if(Alt_Dir > Alt_Esq)//logica recursiva de aumento da altura
        return Alt_Dir +1;
    else
        return Alt_Esq +1;
};

int FatorAVL(pNodoA *a){//retorna fator do nodo
    return (AlturaAVL(a->esq) - AlturaAVL(a->dir));
};

int EquilibradaAVL(pNodoA *a){//funcao de verificar equilibrio da arvore
    int alt_esq, alt_dir;
    if (a!=NULL)//percorrer arvore enquanto existir
    {
        alt_esq = AlturaAVL(a->esq);
        alt_dir = AlturaAVL(a->dir);
        return ( (alt_esq - alt_dir <2) && (alt_dir - alt_esq <2) &&
                 (EquilibradaAVL (a->esq)) && (EquilibradaAVL (a->dir)) );//condição pra ver se ta equilibrada
    }
    else
        return 1;
};

char* ConsultaAVL(pNodoA *a, char* chave, int *comp){
    while (a!=NULL){

        *comp+=1;
        //percorre a arvore até encontrar o nodo
        if (strcmp(a->palavra,chave)==0){
            *comp+=1;//conta uma operação toda vez que avança um nodo ou quando encontra o requerido
            return a->lema;
        }
        else {
            *comp+=1;
            if (strcmp(a->palavra,chave)>0)
                a = a->esq;
            else
                a = a->dir;
        }
    }
    return chave;
}

pNodoA* rotacao_direita(pNodoA* a){//logica de rotacao a direita
    pNodoA *aux;

    aux = a->esq;
    a->esq = aux->dir;
    aux->dir = a;
    //Trocar o fator de a para 0 pq agr ele ficou equilibrado.
    a = aux;
    return a;
}

pNodoA* rotacao_esquerda(pNodoA *a){//logica de rotacao a esquerda
    pNodoA *aux;

    aux = a->dir;
    a->dir = aux->esq;
    aux->esq = a;
    //Trocar o fator de a para 0 pq agr ele ficou equilibrado.
    a = aux;
    return a;
}

pNodoA* rotacao_dupla_esquerda (pNodoA *a){//logica de rotacao dupla a esquerda
    pNodoA *aux1, *aux2;

    aux1 = a->dir;
    aux2 = aux1->esq;
    aux1->esq = aux2->dir;
    aux2->dir = aux1;
    a->dir = aux2->esq;
    aux2->esq = a;

    a = aux2;
    return a;
}

pNodoA* rotacao_dupla_direita (pNodoA* a){//logica de rotacao dupla a direita
    pNodoA *aux1, *aux2;

    aux1 = a->esq;
    aux2 = aux1->dir;
    aux1->dir = aux2->esq;
    aux2->esq = aux1;
    a->esq = aux2->dir;
    aux2->dir = a;

    a = aux2;
    return a;
}
