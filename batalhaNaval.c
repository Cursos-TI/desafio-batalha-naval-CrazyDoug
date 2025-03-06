// Desafio Batalha Naval - MateCheck
// Aluno: Douglas Alves Costa

#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 1

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
        
        if (direcao == 0) nova_coluna += i;
        else if (direcao == 1) nova_linha += i;
        else if (direcao == 2) { nova_linha += i; nova_coluna += i; }
        else { nova_linha += i; nova_coluna -= i; }

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

// Função para aplicar habilidades especiais ao tabuleiro
void aplicar_habilidade(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tipo) {
    int tamanho = 3;
    for (int i = -tamanho; i <= tamanho; i++) {
        for (int j = -tamanho; j <= tamanho; j++) {
            int nova_linha = linha + i;
            int nova_coluna = coluna + j;
            
            // Certifique-se que a posição está dentro dos limites do tabuleiro
            if (nova_linha >= 0 && nova_linha < TAMANHO && nova_coluna >= 0 && nova_coluna < TAMANHO) {
                int i_absoluto = (i < 0) ? -i : i;
                int j_absoluto = (j < 0) ? -j : j;
                
                switch (tipo) {
                    case 1: // Cone
                        // Ajustando para a lógica do cone invertido:
                        if (i >= 0) {
                            if (j == 0 || j_absoluto <= i) {
                                tabuleiro[nova_linha][nova_coluna] = HABILIDADE;
                            }
                        }
                        break;
                    case 2: // Cruz
                        if (i == 0 || j == 0) tabuleiro[nova_linha][nova_coluna] = HABILIDADE;
                        break;
                    case 3: // Octaedro
                        if (i_absoluto + j_absoluto <= tamanho) tabuleiro[nova_linha][nova_coluna] = HABILIDADE;
                        break;
                }
            }
        }
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
    
    int navios[4][3] = {
        {2, 3, 0},
        {5, 6, 1},
        {1, 1, 2},
        {6, 8, 3}
    };
    
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int direcao = navios[i][2];
        
        if (validar_posicao(tabuleiro, linha, coluna, NAVIO, direcao)) {
            posicionar_navio(tabuleiro, linha, coluna, NAVIO, direcao);
        }
    }
    
    int escolha;
    printf("\nEscolha uma habilidade:\n1) Cone\n2) Cruz\n3) Octaedro\nDigite um numero: ");
    scanf("%d", &escolha);
    
    switch (escolha) {
        case 1:
            aplicar_habilidade(tabuleiro, 4, 4, 1);  // Habilidade Cone
            break;
        case 2:
            aplicar_habilidade(tabuleiro, 4, 4, 2);  // Habilidade Cruz
            break;
        case 3:
            aplicar_habilidade(tabuleiro, 4, 4, 3);  // Habilidade Octaedro
            break;
        default:
            printf("\nNúmero digitado inválido!\n");  // Mensagem caso o número seja inválido
            printf("\n");
            break;
    }
    
    exibir_tabuleiro(tabuleiro);
    return 0;
}