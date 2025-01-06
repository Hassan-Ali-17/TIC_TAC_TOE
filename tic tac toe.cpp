#include <iostream>

using namespace std;

const int SIZE = 3;

void initializeBoard(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(const char board[SIZE][SIZE]) {
    cout << "Current board:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
        }
        cout << endl;
        if (i < SIZE - 1) cout << "-|-|-";
        cout << endl;
    }
}

bool makeMove(char board[SIZE][SIZE], int row, int col, char currentPlayer) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
        cout << "Invalid move! Try again.\n";
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

bool checkWin(const char board[SIZE][SIZE], char currentPlayer)
{
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) || (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) || (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool isDraw(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void Computer(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                cout << "AI has made its move at (" << i << ", " << j << ").\n";
                return;
            }
        }
    }
}

void playGame() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    char currentPlayer = 'X';
    int row, col;

    while (true) {
        printBoard(board);
        if (currentPlayer == 'X') {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (makeMove(board, row, col, currentPlayer)) {
                if (checkWin(board, currentPlayer)) {
                    printBoard(board);
                    cout << "Player " << currentPlayer << " wins!\n";
                    break;
                }
                if (isDraw(board)) {
                    printBoard(board);
                    cout << "It's a draw!\n";
                    break;
                }
                currentPlayer = 'O';
            }
        }
        else {
            Computer(board);
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (isDraw(board)) {
                printBoard(board);
                cout << "It's a draw!\n";
                break;
            }
            currentPlayer = 'X';
        }
    }
}

int main() {
    playGame();
    return 0;
}