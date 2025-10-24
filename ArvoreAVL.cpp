#include "ArvoreAVL.h"
#include <iostream>

using namespace std;

NoAVL::NoAVL(int valor) {
    dado = valor;
    esquerda = nullptr;
    direita = nullptr;
    altura = 1;
}

int ArvoreAVL::getAltura(NoAVL *no) {
    if (no == nullptr)
        return 0;
    return no->altura;
}

int ArvoreAVL::getFatorBalanceamento(NoAVL *no) {
    if (no == nullptr)
        return 0;
    return getAltura(no->esquerda) - getAltura(no->direita);
}

void ArvoreAVL::atualizarAltura(NoAVL *no) {
    if (no != nullptr) {
        no->altura = 1 + max(getAltura(no->esquerda), getAltura(no->direita));
    }
}

NoAVL* ArvoreAVL::rotacaoDireita(NoAVL *y) {
    cout << " -> (Rotação Direita em " << y->dado << ")" << endl;
    NoAVL *x = y->esquerda;
    NoAVL *T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    atualizarAltura(y);
    atualizarAltura(x);

    return x;
}

NoAVL* ArvoreAVL::rotacaoEsquerda(NoAVL *x) {
    cout << " -> (Rotação Esquerda em " << x->dado << ")" << endl;
    NoAVL *y = x->direita;
    NoAVL *T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    atualizarAltura(x);
    atualizarAltura(y);

    return y;
}

NoAVL* ArvoreAVL::inserir(NoAVL *no, int dado) {
    if (no == nullptr) {
        return (new NoAVL(dado));
    }

    if (dado < no->dado) {
        no->esquerda = inserir(no->esquerda, dado);
    } else if (dado > no->dado) {
        no->direita = inserir(no->direita, dado);
    } else {
        cout << "Valor " << dado << " ja existe. Nao foi inserido." << endl;
        return no;
    }

    atualizarAltura(no);
    int fb = getFatorBalanceamento(no);

    if (fb > 1 && dado < no->esquerda->dado) {
        cout << "Desbalanceamento: Esquerda-Esquerda (LL) em " << no->dado << ".";
        return rotacaoDireita(no);
    }

    if (fb < -1 && dado > no->direita->dado) {
        cout << "Desbalanceamento: Direita-Direita (RR) em " << no->dado << ".";
        return rotacaoEsquerda(no);
    }

    if (fb > 1 && dado > no->esquerda->dado) {
        cout << "Desbalanceamento: Esquerda-Direita (LR) em " << no->dado << ".";
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    if (fb < -1 && dado < no->direita->dado) {
        cout << "Desbalanceamento: Direita-Esquerda (RL) em " << no->dado << ".";
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

bool ArvoreAVL::buscar(NoAVL *no, int dado) {
    if (no == nullptr) {
        return false;
    }
    if (dado == no->dado) {
        return true;
    }
    if (dado < no->dado) {
        return buscar(no->esquerda, dado);
    } else {
        return buscar(no->direita, dado);
    }
}

NoAVL* ArvoreAVL::getNoMinimo(NoAVL* no) {
    NoAVL* atual = no;
    while (atual->esquerda != nullptr) {
        atual = atual->esquerda;
    }
    return atual;
}

NoAVL* ArvoreAVL::remover(NoAVL* no, int dado) {
    if (no == nullptr) {
        cout << "Valor " << dado << " nao encontrado para remocao." << endl;
        return no;
    }

    if (dado < no->dado) {
        no->esquerda = remover(no->esquerda, dado);
    } else if (dado > no->dado) {
        no->direita = remover(no->direita, dado);
    } else {
        if ((no->esquerda == nullptr) || (no->direita == nullptr)) {
            NoAVL* noParaDeletar = no;
            NoAVL* filho = no->esquerda ? no->esquerda : no->direita;
            no = filho;
            delete noParaDeletar;
        } else {
            NoAVL* temp = getNoMinimo(no->direita);
            no->dado = temp->dado;
            no->direita = remover(no->direita, temp->dado);
        }
    }

    if (no == nullptr) {
        return no;
    }

    atualizarAltura(no);
    int fb = getFatorBalanceamento(no);

    if (fb > 1 && getFatorBalanceamento(no->esquerda) >= 0) {
        cout << "Rebalanceamento: Esquerda-Esquerda (LL) em " << no->dado << ".";
        return rotacaoDireita(no);
    }

    if (fb > 1 && getFatorBalanceamento(no->esquerda) < 0) {
        cout << "Rebalanceamento: Esquerda-Direita (LR) em " << no->dado << ".";
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    if (fb < -1 && getFatorBalanceamento(no->direita) <= 0) {
        cout << "Rebalanceamento: Direita-Direita (RR) em " << no->dado << ".";
        return rotacaoEsquerda(no);
    }

    if (fb < -1 && getFatorBalanceamento(no->direita) > 0) {
        cout << "Rebalanceamento: Direita-Esquerda (RL) em " << no->dado << ".";
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

void ArvoreAVL::imprimir(NoAVL *no, string prefixo, bool ehEsquerdo) {
    if (no == nullptr) {
        return;
    }
    if (no->direita) {
        imprimir(no->direita, prefixo + (ehEsquerdo ? "|   " : "    "), false);
    }
    cout << prefixo << (ehEsquerdo ? "|---" : "|---") << "[" << no->dado << "] (h=" << no->altura << ", fb=" << getFatorBalanceamento(no) << ")" << endl;
    if (no->esquerda) {
        imprimir(no->esquerda, prefixo + (ehEsquerdo ? "    " : "|   "), true);
    }
}

ArvoreAVL::ArvoreAVL() {
    raiz = nullptr;
}

void ArvoreAVL::inserir(int dado) {
    cout << "Inserindo " << dado << "..." << endl;
    raiz = inserir(raiz, dado);
    cout << "--------------------" << endl;
}

void ArvoreAVL::buscar(int dado) {
    if (buscar(raiz, dado)) {
        cout << "Valor " << dado << " ENCONTRADO na arvore." << endl;
    } else {
        cout << "Valor " << dado << " NAO ENCONTRADO na arvore." << endl;
    }
    cout << "--------------------" << endl;
}

void ArvoreAVL::remover(int dado) {
    cout << "Tentando remover " << dado << "..." << endl;
    raiz = remover(raiz, dado);
    cout << "--------------------" << endl;
}

void ArvoreAVL::imprimir() {
    if (raiz == nullptr) {
        cout << "(Arvore vazia)" << endl;
    } else {
        cout << "Estrutura da Arvore AVL:" << endl;
        imprimir(raiz, "", false);
    }
    cout << "--------------------" << endl;
}
