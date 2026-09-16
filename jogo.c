#include <stdio.h>

void desenhaTabuleiro(char mat[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", mat[0][0], mat[0][1], mat[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", mat[1][0], mat[1][1], mat[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", mat[2][0], mat[2][1], mat[2][2]);
    printf("\n");
}

// Checa se alguém ganhou (linhas, colunas e diagonais)
int temGanhador(char mat[3][3], char p) {
    int i;

    // Conferindo as linhas
    for (i = 0; i < 3; i++) {
        if (mat[i][0] == p && mat[i][1] == p && mat[i][2] == p)
            return 1;
    }

    for (i = 0; i < 3; i++) {
        if (mat[0][i] == p && mat[1][i] == p && mat[2][i] == p)
            return 1;
    }
    
    if (mat[0][0] == p && mat[1][1] == p && mat[2][2] == p)
        return 1;

    // Diagonal secundária
    if (mat[0][2] == p && mat[1][1] == p && mat[2][0] == p)
        return 1;

    return 0;
}

int main() {
    // Declarando as variáveis no começo (estilo clássico de faculdade/curso)
    char jogo[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    
    int vez = 0;
    int escolha;
    int linha, coluna;
    char atual = 'X';

    printf("--- JOGO DA VELHA ---\n");
    // O jogo roda no máximo 9 vezes (preenchendo todas as posições)
    while (vez < 9) {
        desenhaTabuleiro(jogo);

        printf("Vez do jogador %c. Digite uma posicao (1-9): ", atual);
        scanf("%d", &escolha);

        // Validando se o número tá no intervalo certo
        if (escolha < 1 || escolha > 9) {
            printf("\n[Erro] Escolha um numero de 1 a 9!\n");
            continue;
        }

        linha = (escolha - 1) / 3;
        coluna = (escolha - 1) % 3;

        // Vendo se o lugar já tá ocupado
        if (jogo[linha][coluna] == 'X' || jogo[linha][coluna] == 'O') {
            printf("\n[Erro] Esse lugar ja ta ocupado, manolo! Escolha outro.\n");
            continue;
        }

        // Fazendo a jogada
        jogo[linha][coluna] = atual;
        vez++;

        if (temGanhador(jogo, atual)) {
            desenhaTabuleiro(jogo);
            printf("PARABENS! O jogador %c ganhou o jogo!\n", atual);
            break;
        }

        // Troca o jogador
        if (atual == 'X') {
            atual = 'O';
        } else {
            atual = 'X';
        }
    }

    if (vez == 9 && !temGanhador(jogo, 'X') && !temGanhador(jogo, 'O')) {
        desenhaTabuleiro(jogo);
        printf("Deu velha! Empate!\n");
    }

    return 0;
}
