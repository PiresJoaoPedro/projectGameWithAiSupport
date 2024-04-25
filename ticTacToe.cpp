#include <iostream>
#include <vector>

using namespace std;

// Função para imprimir o tabuleiro
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Função para verificar o estado do jogo
char checkWin(const vector<vector<char>>& board) {
    // Verificar linhas e colunas
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    // Verificar diagonais
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];
    // Verificar empate
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return ' ';
        }
    }
    return 'T'; // Empate
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Inicializar tabuleiro vazio
    int row, col;
    char currentPlayer = 'X';

    // Loop principal do jogo
    while (true) {
        // Imprimir tabuleiro
        cout << "Tabuleiro atual:" << endl;
        printBoard(board);

        // Solicitar jogada
        cout << "Jogador " << currentPlayer << ", insira a linha e coluna (1-3): ";
        cin >> row >> col;

        // Verificar se a jogada é válida
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            cout << "Jogada inválida! Tente novamente." << endl;
            continue;
        }

        // Realizar jogada
        board[row-1][col-1] = currentPlayer;

        // Verificar o resultado do jogo
        char result = checkWin(board);
        if (result != ' ') {
            // Imprimir resultado do jogo
            cout << "Tabuleiro final:" << endl;
            printBoard(board);
            if (result == 'T')
                cout << "Empate!" << endl;
            else
                cout << "Jogador " << result << " venceu!" << endl;
            break; // Fim do jogo
        }

        // Alternar jogador
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
