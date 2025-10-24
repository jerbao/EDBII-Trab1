# Implementação de Árvores Balanceadas (AVL e Rubro-Negra)

[cite_start]Projeto desenvolvido para a disciplina de Estruturas de Dados Básicas II, focado na implementação e análise comparativa de duas estruturas de árvore de busca auto-balanceada: a Árvore AVL e a Árvore Rubro-Negra.

[cite_start]O sistema foi desenvolvido em C++ e permite ao usuário, em tempo de execução, escolher qual das estruturas de árvore deseja criar e manipular.

## [cite_start]Funcionalidades (Operações Realizadas)

[cite_start]O programa implementa todas as funcionalidades obrigatórias para ambas as árvores:

* [cite_start]**Menu Interativo:** Permite ao usuário escolher entre criar uma Árvore AVL [cite_start]ou uma Árvore Rubro-Negra.
* **Árvore AVL:**
    * [cite_start]`Inserção`: Insere novos elementos e aplica rotações (LL, RR, LR, RL) para manter a propriedade de altura da AVL.
    * [cite_start]`Remoção`: Remove elementos e aplica rotações para rebalancear a árvore após a remoção[cite: 30].
    * [cite_start]`Busca`: Verifica se um elemento existe na árvore.
    * [cite_start]`Impressão`: Exibe a estrutura da árvore no console, incluindo a altura e o fator de balanceamento (fb) de cada nó.
* **Árvore Rubro-Negra:**
    * [cite_start]`Inserção`: Insere novos elementos e aplica recolorações e rotações (`fixInserir`) para manter as 5 propriedades da árvore.
    * [cite_start]`Remoção`: Remove elementos e aplica a complexa lógica de balanceamento (`fixRemover`) para restaurar as propriedades.
    * [cite_start]`Busca`: Verifica se um elemento existe na árvore (usando o nó sentinela `T_NIL`)[cite: 31].
    * [cite_start]`Impressão`: Exibe a estrutura da árvore, mostrando o dado e a cor (V para Vermelho, P para Preto) de cada nó.

## [cite_start]Dependências

Para compilar e executar este projeto, você precisará apenas de:

* Um compilador C++ com suporte ao padrão C++11 (ou superior). Exemplos: `g++` ou `clang++`.

Nenhuma biblioteca externa é necessária.

## [cite_start]Como Compilar e Executar

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

## [cite_start]Exemplo de Uso (Estrutura de Entrada/Saída)

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