# Implementação de Árvores Balanceadas (AVL e Rubro-Negra)

Projeto desenvolvido para a disciplina de Estruturas de Dados Básicas II, focado na implementação e análise comparativa de duas estruturas de árvore de busca auto-balanceada: a Árvore AVL e a Árvore Rubro-Negra.

O sistema foi desenvolvido em C++ e permite ao usuário, em tempo de execução, escolher qual das estruturas de árvore deseja criar e manipular.

## Funcionalidades (Operações Realizadas)

O programa implementa todas as funcionalidades obrigatórias para ambas as árvores:

* **Menu Interativo:** Permite ao usuário escolher entre criar uma Árvore AVL ou uma Árvore Rubro-Negra.
* **Árvore AVL:**
    * `Inserção`: Insere novos elementos e aplica rotações (LL, RR, LR, RL) para manter a propriedade de altura da AVL.
    * `Remoção`: Remove elementos e aplica rotações para rebalancear a árvore após a remoção[cite: 30].
    * `Busca`: Verifica se um elemento existe na árvore.
    * `Impressão`: Exibe a estrutura da árvore no console, incluindo a altura e o fator de balanceamento (fb) de cada nó.
* **Árvore Rubro-Negra:**
    * `Inserção`: Insere novos elementos e aplica recolorações e rotações (`fixInserir`) para manter as 5 propriedades da árvore.
    * `Remoção`: Remove elementos e aplica a complexa lógica de balanceamento (`fixRemover`) para restaurar as propriedades.
    * `Busca`: Verifica se um elemento existe na árvore (usando o nó sentinela `T_NIL`)[cite: 31].
    * `Impressão`: Exibe a estrutura da árvore, mostrando o dado e a cor (V para Vermelho, P para Preto) de cada nó.

## Dependências

Para compilar e executar este projeto, você precisará apenas de:

* Um compilador C++ com suporte ao padrão C++. Exemplos: `g++` ou `clang++`.

Nenhuma biblioteca externa é necessária.

## Como Compilar e Executar

O projeto está modularizado em arquivos `.h` e `.cpp`. Para compilar, todos os arquivos de implementação (`.cpp`) devem ser linkados juntos.

1.  Clone este repositório:
    ```bash
    git clone [https://github.com/jerbao/projeto-EDB2.git](https://github.com/jerbao/EDBII-Trab1.git)
    cd projeto-EDB2
    ```

2.  Compile o programa usando `g++`:
    ```bash
    g++ -o executavel main.cpp ArvoreAVL.cpp ArvoreRubroNegra.cpp -std=c++20
    ```
    *Isso criará um executável chamado `executavel`.*

3.  Execute o programa:
    ```bash
    ./executavel
    ```

## Exemplo de Uso (Estrutura de Entrada/Saída)

Ao executar o programa, você será recebido pelo menu principal.

```bash
$ ./executavel

*** TRABALHO DE ESTRUTURA DE DADOS II ***
   [ Arvores Balanceadas (AVL e RN) ]
-----------------------------------------
Escolha o tipo de arvore para criar:
1. Arvore AVL
2. Arvore Rubro-Negra
0. Sair
Opcao: 1