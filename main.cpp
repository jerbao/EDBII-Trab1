#include <iostream>
#include <string>
#include "ArvoreAVL.h"
#include "ArvoreRubroNegra.h"

using namespace std;

void menuAVL() {
    ArvoreAVL avl;
    int escolha, valor;

    while (true) {
        cout << "\n=== Menu Arvore AVL ===" << endl;
        cout << "1. Inserir elemento" << endl;
        cout << "2. Remover elemento" << endl;
        cout << "3. Buscar elemento" << endl;
        cout << "4. Imprimir arvore" << endl; 
        cout << "0. Voltar ao menu principal" << endl;
        cout << "Escolha: ";
        
        if (!(cin >> escolha)) {
            cout << "Entrada invalida. Por favor, insira um numero." << endl;
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }

        switch (escolha) {
            case 1:
                cout << "Digite o valor para inserir: ";
                if (!(cin >> valor)) {
                     cout << "Entrada invalida." << endl;
                     cin.clear(); 
                     while (cin.get() != '\n');
                     continue;
                }
                avl.inserir(valor);
                break;
            case 2:
                cout << "Digite o valor para remover: ";
                if (!(cin >> valor)) {
                     cout << "Entrada invalida." << endl;
                     cin.clear(); 
                     while (cin.get() != '\n');
                     continue;
                }
                avl.remover(valor);
                break;
            case 3:
                cout << "Digite o valor para buscar: ";
                 if (!(cin >> valor)) {
                     cout << "Entrada invalida." << endl;
                     cin.clear(); 
                     while (cin.get() != '\n');
                     continue;
                }
                avl.buscar(valor);
                break;
            case 4:
                avl.imprimir();
                break;
            case 0:
                return;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
}

void menuRubroNegra() {
    ArvoreRubroNegra rn;
    int escolha, valor;

    while (true) {
        cout << "\n=== Menu Arvore Rubro-Negra ===" << endl;
        cout << "1. Inserir elemento" << endl;
        cout << "2. Remover elemento" << endl;
        cout << "3. Buscar elemento" << endl;
        cout << "4. Imprimir arvore" << endl;
        cout << "0. Voltar ao menu principal" << endl;
        cout << "Escolha: ";

        if (!(cin >> escolha)) {
            cout << "Entrada invalida. Por favor, insira um numero." << endl;
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }

        switch (escolha) {
            case 1:
                cout << "Digite o valor para inserir: ";
                if (!(cin >> valor)) {
                     cout << "Entrada invalida." << endl;
                     cin.clear(); 
                     while (cin.get() != '\n');
                     continue;
                }
                rn.inserir(valor);
                break;
            case 2:
                cout << "Digite o valor para remover: ";
                if (!(cin >> valor)) {
                     cout << "Entrada invalida." << endl;
                     cin.clear(); 
                     while (cin.get() != '\n');
                     continue;
                }
                rn.remover(valor);
                break;
            case 3:
                cout << "Digite o valor para buscar: ";
                if (!(cin >> valor)) {
                     cout << "Entrada invalida." << endl;
                     cin.clear(); 
                     while (cin.get() != '\n');
                     continue;
                }
                rn.buscar(valor);
                break;
            case 4:
                rn.imprimir();
                break;
            case 0:
                return;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
}


int main() {
    int escolha;

    while (true) {
        cout << "\n*** TRABALHO DE ESTRUTURA DE DADOS II ***" << endl;
        cout << "   [ Arvores Balanceadas (AVL e RN) ]" << endl; //
        cout << "-----------------------------------------" << endl;
        cout << "Escolha o tipo de arvore para criar:" << endl; //
        cout << "1. Arvore AVL" << endl;                 //
        cout << "2. Arvore Rubro-Negra" << endl;           //
        cout << "0. Sair" << endl;
        cout << "Opcao: ";
        
        if (!(cin >> escolha)) {
            cout << "Entrada invalida. Por favor, insira um numero." << endl;
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }

        switch (escolha) {
            case 1:
                menuAVL();
                break;
            case 2:
                menuRubroNegra();
                break;
            case 0:
                cout << "Encerrando o programa." << endl;
                return 0;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}