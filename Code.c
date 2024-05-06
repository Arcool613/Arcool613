#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3
#define CELLS_PER_ROW BOARD_SIZE

char board[BOARD_SIZE][BOARD_SIZE];
const char playerX = 'X';
const char playerO = 'O';
const char emptyCell = ' ';

void initialize() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = emptyCell;
        }
    }
}

void printBoard() {
    printf("\n-------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("|%c| %c | %c | \n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

bool checkWin(char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Check rows
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Player has won
        }
        // Check columns
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Player has won
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true; // Player has won
    }
    return false; // No win yet
}

bool getInput(char player, int *row, int *col) {
    printf("\nPlayer %c (%s), enter your move (row column): ", player, (player == playerX) ? "X" : "O");
    if (scanf("%d %d", row, col) != 2) {
        printf("Invalid input, try again.\n");
        return false;
    }
    if (*row < 0 || *row >= BOARD_SIZE || *col < 0 || *col >= BOARD_SIZE || board[*row][*col] != emptyCell) {
        printf("Invalid move, try again.\n");
        return false;
    }
    return true;
}

int main() {
    int row, col;
    char currentPlayer = playerX; // Player X starts the game
    bool gameRunning = true;
    char userNameX[100];
    char userNameO[100];
    initialize();

    printf("Enter name for Player X: ");
    scanf("%s", userNameX);

    printf("Enter name for Player O: ");
    scanf("%s", userNameO);

    while (gameRunning) {
        printBoard();

        if (!getInput(currentPlayer, &row, &col)) {
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(currentPlayer)) {
            if (currentPlayer == playerX) {
                printf("\nPlayer X (%s) wins!\n", userNameX);
            } else {
                printf("\nPlayer O (%s) wins!\n", userNameO);
            }
            printBoard();
            break;
        }

        currentPlayer = (currentPlayer == playerX) ? playerO : playerX; // Switch players
    }

    return 0;
}
