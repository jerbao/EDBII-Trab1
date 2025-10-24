#ifndef ARVORERUBRONEGRA_H
#define ARVORERUBRONEGRA_H

#include <string>

enum Cor { VERMELHO, PRETO };

struct NoRN {
    int dado;
    Cor cor;
    NoRN *pai;
    NoRN *esquerda;
    NoRN *direita;

    NoRN(int val) : dado(val), cor(VERMELHO), pai(nullptr), esquerda(nullptr), direita(nullptr) {}
};

class ArvoreRubroNegra {
private:
    NoRN* raiz;
    NoRN* T_NIL;

    void rotacaoEsquerda(NoRN* x);
    void rotacaoDireita(NoRN* x);
    void fixInserir(NoRN* k);
    void imprimir(NoRN* no, std::string prefixo, bool ehEsquerdo);
    NoRN* buscar(NoRN* no, int dado);
    void transplantar(NoRN* u, NoRN* v);
    void fixRemover(NoRN* x);
    NoRN* getNoMinimo(NoRN* no);

public:
    ArvoreRubroNegra();

    void inserir(int dado);
    void buscar(int dado);
    void remover(int dado);
    void imprimir();
};

#endif
