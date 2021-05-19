#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lababp.h"

pNodoA* InicializaArvore(void){
    return NULL;
}

pNodoA* InsereArvore(pNodoA *nodo, int chave){
    if (!nodo){
        nodo = (pNodoA*) malloc(sizeof(pNodoA));
        nodo->chave = chave;
        nodo->fator = 0;
        nodo->esq = NULL;
        nodo->dir = NULL;
    }
    else if (chave < nodo->chave){
        nodo->esq = InsereArvore(nodo->esq,chave);
    }
    else{
        nodo->dir = InsereArvore(nodo->dir,chave);
    }
    return nodo;
}

pNodoA* InsereAVL(pNodoA *nodo, int chave, int *ok){

    if (!nodo){
        nodo = (pNodoA*) malloc(sizeof(pNodoA));
        nodo->chave = chave;
        nodo->fator = 0;
        nodo->esq = NULL;
        nodo->dir = NULL;

        *ok = 1;
    }
    else if(chave < nodo->chave){
        nodo->fator = Fator(nodo);
        nodo->esq = InsereAVL(nodo->esq, chave, ok);
        if(*ok){
            switch (nodo->fator) {
                case -1: nodo->fator = 0; *ok = 0; break;
                case 0: nodo->fator = 1; break;
                case 1: nodo=Caso1(nodo,ok); break;
            }
        }
    }else{
        nodo->fator = Fator(nodo);
        nodo->dir = InsereAVL(nodo->dir, chave, ok);
        if(*ok){
            switch (nodo->fator) {
                case 1: nodo->fator = 0; *ok = 0; break;
                case 0: nodo->fator = -1; break;
                case -1: nodo=Caso2(nodo,ok); break;
            }
        }
    }
    return nodo;
};

pNodoA* Caso1 (pNodoA *a, int *ok){
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

pNodoA* Caso2 (pNodoA *a, int *ok){
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

void fatorizaArvore(pNodoA **a){
        printf("FATORIZA\nnodo=%d\nfator=%d\n\n", (*a)->chave, (*a)->fator+1);
    if(a){
        (*a)->fator = Fator(a);
        printf("FATORIZA");

        (*a)->esq = FatorArvore((*a)->esq);
        (*a)->dir = FatorArvore((*a)->dir);
    }
}

void verificaAVL(pNodoA *a){
    if(a){
//        printf("VERIFICA\nnodo = %d\nfator = %d\n\n", a->chave, a->fator);
        if (abs(a->fator) >= 2){
            if(a->fator == -2){
                if(a->dir->fator == 1)
                    a = rotacao_dupla_esquerda(a);
                if(a->dir->fator == -1)
                    a = rotacao_esquerda(a);
            }
            if(a->fator == 2){
                if(a->esq->fator == -1)
                    a = rotacao_dupla_direita(a);
                if(a->esq->fator == 1)
                    a = rotacao_direita(a);

            }
        }
        verificaAVL(a->esq);
        verificaAVL(a->dir);
    }
}

void PrintComNivel(pNodoA *nodo, int nivel){
    int i;
    if (nodo){
        nivel+=1;
        for(i = nivel; i>0; i--)
            printf("=");

        printf("%d\n",nodo->chave);
        PrintComNivel(nodo->esq, nivel);
        PrintComNivel(nodo->dir, nivel);
    }
};

int ContadorNodos(pNodoA *nodo, int nivel){
    int a, b;
    if(nivel == 0){
        a = 0;
        b = 0;
    }

    if (nodo){
        if(nodo->esq)
            a += ContadorNodos(nodo->esq, nivel);
        if(nodo->dir)
            b += ContadorNodos(nodo->dir, nivel);
    }

    return a+b+1;
};

int Altura (pNodoA *a){
    int Alt_Esq, Alt_Dir;

    if (!a)
        return 0;

    Alt_Esq = Altura (a->esq);
    Alt_Dir = Altura (a->dir);

    if(Alt_Dir > Alt_Esq)
        return Alt_Dir +1;
    else
        return Alt_Esq +1;

};

int Fator(pNodoA *a){
    return (Altura(a->esq) - Altura(a->dir));
};

int FatorArvore(pNodoA *a){
    int fatorDir, fatorEsq, fator;

    if (a)
    {
        fatorEsq = FatorArvore(a->esq);
        fatorDir = FatorArvore(a->dir);

        fator = Fator(a);
        a->fator = fator;
//        printf("nodo=%d\nfator=%d\n\n", a->chave, a->fator);

        if(abs(fatorEsq) > abs(fator) && abs(fatorEsq) > abs(fatorDir))
            return fatorEsq;
        else{
            if(abs(fatorDir)>abs(fator))
                return fatorDir;
            else
                return fator;
        }
    }
    else
        return 0;
};

int Equilibrada(pNodoA *a){
    int alt_esq, alt_dir;
    if (a!=NULL)
    {
        alt_esq = Altura(a->esq);
        alt_dir = Altura(a->dir);
        return ( (alt_esq - alt_dir <2) && (alt_dir - alt_esq <2) &&
                 (Equilibrada (a->esq)) && (Equilibrada (a->dir)) );
    }
    else
        return 1;
};

void PrintPreFixadoEsquerda(pNodoA *nodo){
    if (nodo){
        printf("%d ",nodo->chave);
        PrintPreFixadoEsquerda(nodo->esq);
        PrintPreFixadoEsquerda(nodo->dir);
    }
};

void PrintPosFixadoEsquerda(pNodoA *nodo){
    if (nodo){
        PrintPosFixadoEsquerda(nodo->esq);
        PrintPosFixadoEsquerda(nodo->dir);
        printf("%d ",nodo->chave);
    }
};

void PrintCentralDireita(pNodoA *nodo){
    if (nodo){
        PrintCentralDireita(nodo->dir);
        printf("%d ",nodo->chave);
        PrintCentralDireita(nodo->esq);
    }
};

void PrintCentralEsquerda(pNodoA *nodo){
    if (nodo){
        PrintCentralEsquerda(nodo->esq);
        printf("%d ",nodo->chave);
        PrintCentralEsquerda(nodo->dir);
    }

}

void PrintIntervalo(pNodoA *nodo, int menor, int maior){
  if (nodo){//Se o nodo existe verifica a função
    //fazer caminhamento central a esquerda para printar números em sequencia, print entre a recursão pra direita e a pra            esquerda faz com que seja esse caminhamento

    PrintIntervalo(nodo->esq, menor, maior);

    if (nodo->chave >= menor && nodo->chave <= maior)//Se o valor do nodo ta entre os limites, [menor, maior], printa
      printf("%d ",nodo->chave);

    PrintIntervalo(nodo->dir, menor, maior);
  }
};

pNodoA* ArvoreInterseccao(pNodoA *a, pNodoA *a2){
    pNodoA *a3;

    a3 = InicializaArvore();

    if (a && a2){
        printf("1 = %d\n2 = %d\n\n", a->chave, a2->chave);//printa as chaves só para ver em que estado está

        if (a->chave == a2->chave){//quando encontra duas chaves iguais
            a3 = InsereArvore(a3, a->chave);//insere na arvore nova
            printf("##########CHAVE = %d\n\n", a->chave);//printa o item inserido
            return a3;
        }
        //colocando a condicao antes da recursividade e a primeira recursividade é pra esquerda eu tenho um pré fixado esquerda

        //eu percorro toda a arvore 'a' com caminhamento pre fixado a esquerda
        a3 = ArvoreInterseccao(a->esq, a2);
        a3 = ArvoreInterseccao(a->dir, a2);
        //Depois de percorrer a arvore 'a' eu percorro a arvore 1 com o mesmo caminhamento
        //Toda vez q eu andar um elemnto na  arvore 'a2' eu vou percorrer toda a arvore 'a'
        a3 = ArvoreInterseccao(a, a2->esq);
        a3 = ArvoreInterseccao(a, a2->dir);

        //retorno o a3 pra deixar ele salvo
        return a3;
    }else {
        return 0;//retorno 0 quando chegar no fim da arvore
    }
}

pNodoA* consultaABP(pNodoA* a, int chave){

    while (a!=NULL){
        if (a->chave == chave )
            return a; //achou então retorna o ponteiro para o nodo
        else if (a->chave > chave)
            a = a->esq;
        else
            a = a->dir;
    }
    return NULL; //se não achou
}

void intersect (pNodoA* a, pNodoA* b,  pNodoA **c){
        if (a && b){
          if ( consultaABP(b,a->chave) )
             *c = InsereArvore(*c,a->chave);
          intersect (a->esq, b, c);
          intersect (a->dir, b, c);
        }

}

int Compara(pNodoA *a, pNodoA *b){
//    if(!a && !b)
//        return 1;
//    if(a && b)
//        return (
//                Compara(a->dir, b->dir) &&
//                Compara(a->esq, b->esq) &&
//                (a->chave == b->chave)
//                );
//
//    return 0;
    int comp=1;

    if(!a && !b)
        return 1;
    if(a && b){
        comp = Compara(a->dir, b->dir);
        comp = Compara(a->esq, b->esq);

        if (a->chave != b->chave || comp == 0){
            return 0;
        }
        else
            return 1;
    }
    return 0;
}

pNodoA* rotacao_direita(pNodoA* a){
    pNodoA *aux;

    aux = a->esq;
    a->esq = aux->dir;
    aux->dir = a;
    //Trocar o fator de a para 0 pq agr ele ficou equilibrado.
    a = aux;
    return a;
}

pNodoA* rotacao_esquerda(pNodoA *a){
    pNodoA *aux;

    aux = a->dir;
    a->dir = aux->esq;
    aux->esq = a;
    //Trocar o fator de a para 0 pq agr ele ficou equilibrado.
    a = aux;
    return a;
}

pNodoA* rotacao_dupla_esquerda (pNodoA *a){
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

pNodoA* rotacao_dupla_direita (pNodoA* a){
//TESTE
    a->esq = rotacao_esquerda(a->esq);
    a = rotacao_direita(a);

//    a->esq = rotacao_esquerda(a->esq);
//    a = rotacao_direita(a);

    return a;
}

int xxx(pNodoA *a){
  if (a!= NULL)
  {
     if (!a->esq && !a->dir)
        return 1;
     return xxx(a->esq) + xxx(a->dir);
  }
   return 0;
}

void PosicaoNodo(pNodoA *nodo, int n, int k){
    //  if (nodo){
//
//    if(!nodo->dir && !nodo->esq && n>0){
//        n = n*-1;
//    }
//
//    if(n>0){
//        printf("chave ANTES = %d\n",nodo->chave);
//        PosicaoNodo(nodo->dir, n);
//    }
//    if(n>=0){
//        printf("chave DEPOIS = %d\n",nodo->chave);
//        PosicaoNodo(nodo->dir, n+1);
//        PosicaoNodo(nodo->esq, n+1);
//
//        printf("n = %d\n",n);
//        if (n == -1)
//          printf("RESPOSTA%d\n",nodo->chave);
//    }
//
//  }
    if(nodo){
        PosicaoNodo(nodo->dir, n-1, k+1);
        printf("n = %d\n",n);
        printf("k = %d\n",k);
        printf("chave = %d\n\n",nodo->chave);
        if(n+k == 1)
            printf("RESPOSTA = %d\n\n",nodo->chave);
        PosicaoNodo(nodo->esq, n+4, k-4);

    }

};

int imprime_nesino(pNodoA *a, int n){
    if(a!=NULL){
        n = imprime_nesino(a->dir, n);
        printf("pos = %d\n",n);
        printf("chave = %d\n\n",a->chave);
        n--;
        if(n==0)
            printf("%d", a->chave);
        else if (n>0){
            printf("pos = %d\n",n);
            printf("chave = %d\n\n",a->chave);
            n = imprime_nesino(a->esq, n);
        }
    }
    return n;
}
