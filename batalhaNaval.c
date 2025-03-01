// Desafio Batalha Naval - MateCheck
// Aluno: Douglas Alves Costa

#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define AGUA 0

// Função para inicializar o tabuleiro preenchendo todas as posições com água
void inicializar_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para validar se um navio pode ser colocado em determinada posição
int validar_posicao(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, int direcao) {
    for (int i = 0; i < tamanho; i++) {
        int nova_linha = linha, nova_coluna = coluna;
        
        // Define a direção do navio: horizontal, vertical ou diagonal
        if (direcao == 0) nova_coluna += i; // Horizontal
        else if (direcao == 1) nova_linha += i; // Vertical
        else if (direcao == 2) { nova_linha += i; nova_coluna += i; } // Diagonal principal
        else { nova_linha += i; nova_coluna -= i; } // Diagonal secundária

        // Verifica se a posição está dentro dos limites do tabuleiro e se não há sobreposição
        if (nova_linha < 0 || nova_linha >= TAMANHO || nova_coluna < 0 || nova_coluna >= TAMANHO || tabuleiro[nova_linha][nova_coluna] == NAVIO) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar um navio no tabuleiro
void posicionar_navio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, int direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 0) tabuleiro[linha][coluna + i] = NAVIO;
        else if (direcao == 1) tabuleiro[linha + i][coluna] = NAVIO;
        else if (direcao == 2) tabuleiro[linha + i][coluna + i] = NAVIO;
        else tabuleiro[linha + i][coluna - i] = NAVIO;
    }
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%c ", letras[j]);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializar_tabuleiro(tabuleiro);
    
    // Define quatro navios com suas coordenadas iniciais e direções
    int navios[4][3] = {
        {2, 3, 0},  // Horizontal
        {5, 6, 1},  // Vertical
        {1, 1, 2},  // Diagonal principal
        {6, 8, 3}   // Diagonal secundária
    };
    
    // Posiciona os navios no tabuleiro, verificando se a posição é válida
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int direcao = navios[i][2];
        
        if (validar_posicao(tabuleiro, linha, coluna, NAVIO, direcao)) {
            posicionar_navio(tabuleiro, linha, coluna, NAVIO, direcao);
        }
    }
    
    exibir_tabuleiro(tabuleiro);
    return 0;
}

// Nível Mestre - Habilidades Especiais com Matrizes
// Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
// Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
// Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

// Exemplos de exibição das habilidades:
// Exemplo para habilidade em cone:
// 0 0 1 0 0
// 0 1 1 1 0
// 1 1 1 1 1

// Exemplo para habilidade em octaedro:
// 0 0 1 0 0
// 0 1 1 1 0
// 0 0 1 0 0

// Exemplo para habilidade em cruz:
// 0 0 1 0 0
// 1 1 1 1 1
// 0 0 1 0 0