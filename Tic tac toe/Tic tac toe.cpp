#include <iostream>
#include <cstdlib>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentPlayer = 'X';

void drawBoard() {
    system("cls");  // Ganti "clear" dengan "cls" jika menggunakan sistem operasi Windows
    cout << "Tic Tac Toe Game\n";
    cout << "Player 1 (X) - Player 2 (O)\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n";
}

bool isMoveValid(int choice) {
    if (choice < 1 || choice > 9) {
        return false;
    }

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }

    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool checkForWin() {
    for(int i = 0; i < 3; ++i) {
        // Check baris dan kolom
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }

    // Check diagonal
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }

    return false;
}

bool checkForTie() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int choice;
    int currentPlayer = 1;
    int row, col;

    do {
        drawBoard();
        currentPlayer = (currentPlayer % 2) ? 1 : 2;

        cout << "Player " << currentPlayer << ", enter a number: ";
        cin >> choice;

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (isMoveValid(choice)) {
            board[row][col] = (currentPlayer == 1) ? 'X' : 'O';
            ++currentPlayer;
        } else {
            cout << "Invalid move! Try again.\n";
            continue;
        }

    } while (!checkForWin() && !checkForTie());

    drawBoard();

    if (checkForWin()) {
        cout << "Player " << ((currentPlayer == 1) ? 2 : 1) << " wins!\n";
    } else {
        cout << "It's a tie!\n";
    }

    return 0;
}

