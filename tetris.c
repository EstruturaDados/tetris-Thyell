#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_FILA 5

// Estrutura para representar uma peça do Tetris
typedef struct {
    int id;
    char nome;
} Peca;

// Estrutura da fila circular
typedef struct {
    Peca pecas[TAMANHO_FILA];
    int frente;
    int tras;
    int quantidade;
} FilaCircular;

// Função para gerar uma nova peça automaticamente
Peca gerarPeca(int id) {
    char tipos[] = {'I', 'O', 'T', 'L', 'J', 'S', 'Z'};
    Peca nova;
    nova.id = id;
    nova.nome = tipos[rand() % 7]; // escolhe um tipo aleatório
    return nova;
}

// Inicializa a fila com 5 peças
void inicializarFila(FilaCircular *fila) {
    fila->frente = 0;
    fila->tras = TAMANHO_FILA - 1;
    fila->quantidade = TAMANHO_FILA;
    for (int i = 0; i < TAMANHO_FILA; i++) {
        fila->pecas[i] = gerarPeca(i + 1);
    }
}

// Exibe o estado atual da fila
void exibirFila(FilaCircular *fila) {
    printf("\n===== Fila Atual =====\n");
    if (fila->quantidade == 0) {
        printf("Fila vazia!\n");
        return;
    }
    int i = fila->frente;
    for (int count = 0; count < fila->quantidade; count++) {
        printf("Pos %d -> ID: %d | Tipo: %c\n", count + 1, fila->pecas[i].id, fila->pecas[i].nome);
        i = (i + 1) % TAMANHO_FILA;
    }
    printf("======================\n");
}

// Remove a peça da frente (dequeue)
void jogarPeca(FilaCircular *fila) {
    if (fila->quantidade == 0) {
        printf("Não há peças para jogar!\n");
        return;
    }
    Peca removida = fila->pecas[fila->frente];
    printf("Peça jogada: ID %d | Tipo %c\n", removida.id, removida.nome);
    fila->frente = (fila->frente + 1) % TAMANHO_FILA;
    fila->quantidade--;
}

// Insere uma nova peça no final (enqueue)
void inserirPeca(FilaCircular *fila, int *contadorIds) {
    if (fila->quantidade == TAMANHO_FILA) {
        printf("Fila cheia! Não é possível inserir nova peça.\n");
        return;
    }
    fila->tras = (fila->tras + 1) % TAMANHO_FILA;
    (*contadorIds)++;
    fila->pecas[fila->tras] = gerarPeca(*contadorIds);
    fila->quantidade++;
    printf("Nova peça inserida: ID %d | Tipo %c\n", fila->pecas[fila->tras].id, fila->pecas[fila->tras].nome);
}

int main() {
    srand(time(NULL));

    FilaCircular fila;
    int contadorIds = 5;
    int opcao;

    inicializarFila(&fila);

    do {
        printf("\n===== MENU TETRIS STACK =====\n");
        printf("1 - Visualizar fila\n");
        printf("2 - Jogar peça (remover da frente)\n");
        printf("3 - Inserir nova peça (adicionar no final)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                exibirFila(&fila);
                break;
            case 2:
                jogarPeca(&fila);
                exibirFila(&fila);
                break;
            case 3:
                inserirPeca(&fila, &contadorIds);
                exibirFila(&fila);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;

// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.

int main() {

    // 🧩 Nível Novato: Fila de Peças Futuras
    //
    // - Crie uma struct Peca com os campos: tipo (char) e id (int).
    // - Implemente uma fila circular com capacidade para 5 peças.
    // - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
    // - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
    // - Exiba a fila após cada ação com uma função mostrarFila().
    // - Use um menu com opções como:
    //      1 - Jogar peça (remover da frente)
    //      0 - Sair
    // - A cada remoção, insira uma nova peça ao final da fila.



    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha


    return 0;
}

