#include "ArvoreRubroNegra.h"
#include <iostream>
#include <string>

using namespace std;

ArvoreRubroNegra::ArvoreRubroNegra() {
    T_NIL = new NoRN(0);
    T_NIL->cor = PRETO;
    T_NIL->esquerda = nullptr;
    T_NIL->direita = nullptr;
    raiz = T_NIL;
}

void ArvoreRubroNegra::rotacaoEsquerda(NoRN* x) {
    NoRN* y = x->direita;
    x->direita = y->esquerda;
    if (y->esquerda != T_NIL) {
        y->esquerda->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == nullptr) {
        this->raiz = y;
    } else if (x == x->pai->esquerda) {
        x->pai->esquerda = y;
    } else {
        x->pai->direita = y;
    }
    y->esquerda = x;
    x->pai = y;
}

void ArvoreRubroNegra::rotacaoDireita(NoRN* x) {
    NoRN* y = x->esquerda;
    x->esquerda = y->direita;
    if (y->direita != T_NIL) {
        y->direita->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == nullptr) {
        this->raiz = y;
    } else if (x == x->pai->direita) {
        x->pai->direita = y;
    } else {
        x->pai->esquerda = y;
    }
    y->direita = x;
    x->pai = y;
}

void ArvoreRubroNegra::inserir(int dado) {
    NoRN* novoNo = new NoRN(dado);
    novoNo->pai = nullptr;
    novoNo->esquerda = T_NIL;
    novoNo->direita = T_NIL;
    novoNo->cor = VERMELHO;

    NoRN* y = nullptr;
    NoRN* x = this->raiz;

    while (x != T_NIL) {
        y = x;
        if (novoNo->dado < x->dado) {
            x = x->esquerda;
        } else if (novoNo->dado > x->dado) {
            x = x->direita;
        } else {
            cout << "Valor " << dado << " ja existe. Nao foi inserido." << endl;
            delete novoNo;
            return;
        }
    }

    novoNo->pai = y;
    if (y == nullptr) {
        raiz = novoNo;
    } else if (novoNo->dado < y->dado) {
        y->esquerda = novoNo;
    } else {
        y->direita = novoNo;
    }

    if (novoNo->pai == nullptr){
        novoNo->cor = PRETO;
        return;
    }

    if (novoNo->pai->pai == nullptr) {
        return;
    }

    fixInserir(novoNo);
}

void ArvoreRubroNegra::fixInserir(NoRN* k) {
    NoRN* u;
    while (k->pai->cor == VERMELHO) {
        if (k->pai == k->pai->pai->direita) { 
            u = k->pai->pai->esquerda;
            if (u->cor == VERMELHO) {
                u->cor = PRETO;
                k->pai->cor = PRETO;
                k->pai->pai->cor = VERMELHO;
                k = k->pai->pai;
            } else {
                if (k == k->pai->esquerda) {
                    k = k->pai;
                    rotacaoDireita(k);
                }
                k->pai->cor = PRETO;
                k->pai->pai->cor = VERMELHO;
                rotacaoEsquerda(k->pai->pai);
            }
        } else {
            u = k->pai->pai->direita;
            if (u->cor == VERMELHO) {
                u->cor = PRETO;
                k->pai->cor = PRETO;
                k->pai->pai->cor = VERMELHO;
                k = k->pai->pai;
            } else {
                if (k == k->pai->direita) {
                    k = k->pai;
                    rotacaoEsquerda(k);
                }
                k->pai->cor = PRETO;
                k->pai->pai->cor = VERMELHO;
                rotacaoDireita(k->pai->pai);
            }
        }
        if (k == raiz) {
            break;
        }
    }
    raiz->cor = PRETO;
}

NoRN* ArvoreRubroNegra::buscar(NoRN* no, int dado) {
    if (no == T_NIL || dado == no->dado) {
        return no;
    }
    if (dado < no->dado) {
        return buscar(no->esquerda, dado);
    }
    return buscar(no->direita, dado);
}

void ArvoreRubroNegra::buscar(int dado) {
    NoRN* resultado = buscar(this->raiz, dado);
    if (resultado != T_NIL) {
        cout << "Valor " << dado << " ENCONTRADO na arvore." << endl;
    } else {
        cout << "Valor " << dado << " NAO ENCONTRADO na arvore." << endl;
    }
}

NoRN* ArvoreRubroNegra::getNoMinimo(NoRN* no) {
    while (no->esquerda != T_NIL) {
        no = no->esquerda;
    }
    return no;
}

void ArvoreRubroNegra::transplantar(NoRN* u, NoRN* v) {
    if (u->pai == nullptr) {
        raiz = v;
    } else if (u == u->pai->esquerda) {
        u->pai->esquerda = v;
    } else {
        u->pai->direita = v;
    }
    v->pai = u->pai;
}

void ArvoreRubroNegra::remover(int dado) {
    NoRN* z = buscar(this->raiz, dado);
    if (z == T_NIL) {
        cout << "Valor " << dado << " nao encontrado para remocao." << endl;
        return;
    }

    NoRN* x;
    NoRN* y = z;
    Cor y_cor_original = y->cor;

    if (z->esquerda == T_NIL) {
        x = z->direita;
        transplantar(z, z->direita);
    } else if (z->direita == T_NIL) {
        x = z->esquerda;
        transplantar(z, z->esquerda);
    } else {
        y = getNoMinimo(z->direita);
        y_cor_original = y->cor;
        x = y->direita;
        if (y->pai == z) {
            x->pai = y;
        } else {
            transplantar(y, y->direita);
            y->direita = z->direita;
            y->direita->pai = y;
        }
        transplantar(z, y);
        y->esquerda = z->esquerda;
        y->esquerda->pai = y;
        y->cor = z->cor;
    }
    delete z;
    if (y_cor_original == PRETO) {
        fixRemover(x);
    }
}

void ArvoreRubroNegra::fixRemover(NoRN* x) {
    NoRN* s;
    while (x != raiz && x->cor == PRETO) {
        if (x == x->pai->esquerda) {
            s = x->pai->direita;
            if (s->cor == VERMELHO) {
                s->cor = PRETO;
                x->pai->cor = VERMELHO;
                rotacaoEsquerda(x->pai);
                s = x->pai->direita;
            }

            if (s->esquerda->cor == PRETO && s->direita->cor == PRETO) {
                s->cor = VERMELHO;
                x = x->pai;
            } else {
                if (s->direita->cor == PRETO) {
                    s->esquerda->cor = PRETO;
                    s->cor = VERMELHO;
                    rotacaoDireita(s);
                    s = x->pai->direita;
                }

                s->cor = x->pai->cor;
                x->pai->cor = PRETO;
                s->direita->cor = PRETO;
                rotacaoEsquerda(x->pai);
                x = raiz;
            }
        } else {
            s = x->pai->esquerda;
            if (s->cor == VERMELHO) {
                s->cor = PRETO;
                x->pai->cor = VERMELHO;
                rotacaoDireita(x->pai);
                s = x->pai->esquerda;
            }

            if (s->direita->cor == PRETO && s->esquerda->cor == PRETO) {
                s->cor = VERMELHO;
                x = x->pai;
            } else {
                if (s->esquerda->cor == PRETO) {
                    s->direita->cor = PRETO;
                    s->cor = VERMELHO;
                    rotacaoEsquerda(s);
                    s = x->pai->esquerda;
                }

                s->cor = x->pai->cor;
                x->pai->cor = PRETO;
                s->esquerda->cor = PRETO;
                rotacaoDireita(x->pai);
                x = raiz;
            }
        }
    }
    x->cor = PRETO;
}

void ArvoreRubroNegra::imprimir(NoRN* no, string prefixo, bool ehEsquerdo) {
    if (no != T_NIL) {
        if(no->direita) {
            imprimir(no->direita, prefixo + (ehEsquerdo ? "|   " : "    "), false);
        }
        cout << prefixo;
        cout << (ehEsquerdo ? "|---" : "|---" );
        cout << "[" << no->dado << "," << (no->cor == VERMELHO ? "V" : "P") << "]" << endl;
        if (no->esquerda) {
            imprimir(no->esquerda, prefixo + (ehEsquerdo ? "    " : "|   "), true);
        }
    }
}

void ArvoreRubroNegra::imprimir() {
    if (raiz == T_NIL) {
        cout << "(Arvore vazia)" << endl;
    } else {
        imprimir(this->raiz, "", true);
    }
}
