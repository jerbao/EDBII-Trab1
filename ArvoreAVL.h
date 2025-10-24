#ifndef ARVOREAVL_H
#define ARVOREAVL_H

#include <string>
#include <algorithm>

struct NoAVL {
    int dado;
    NoAVL *esquerda;
    NoAVL *direita;
    int altura;

    NoAVL(int valor);
};

class ArvoreAVL {
private:
    NoAVL *raiz;

    int getAltura(NoAVL *no);
    int getFatorBalanceamento(NoAVL *no);
    void atualizarAltura(NoAVL *no);
    NoAVL* rotacaoDireita(NoAVL *y);
    NoAVL* rotacaoEsquerda(NoAVL *x);
    NoAVL* inserir(NoAVL *no, int dado);
    bool buscar(NoAVL *no, int dado);
    NoAVL* getNoMinimo(NoAVL* no);
    NoAVL* remover(NoAVL* no, int dado);
    void imprimir(NoAVL *no, std::string prefixo, bool ehEsquerdo);

public:
    ArvoreAVL();
    void inserir(int dado);
    void buscar(int dado);
    void remover(int dado);
    void imprimir();
};

#endif
