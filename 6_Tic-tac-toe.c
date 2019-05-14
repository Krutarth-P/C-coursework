/*
    This program is used to allows the users to play Tic-tac-toe against each other.
*/


#include <stdio.h>
void printBoard(int board[], int playerA, int playerB)
{
    printf("\n");
    for (int i = 0; i < 9; i++) {

        if (board[i] == playerA) {
            printf(" A");
        } else if (board[i] == playerB) {
            printf(" B");
        } else
            printf(" %d", board[i]);

        if ((i + 1) % 3 == 0)
            printf("\n");
    }
    printf("\n");
}

int requestValidInput(int board[], int playerA, int playerB)
{
    int input = 0;

    printf("Please enter a valid position to play.\n");
    scanf("%d", &input);
    while (!(input >= 1 && input <= 9) || (board[input - 1] == playerA) || (board[input - 1] == playerB)) {

        if (!(input >= 1 && input <= 9)) { // out of bounds condition
            printf("Invalid input, please try again.\n");
            scanf("%d", &input);
        }

        if ((board[input - 1] == playerA) || (board[input - 1] == playerB)) { // already used index condition
            printf("That position has already been played, please try again.\n");
            scanf("%d", &input);
        }
    }
    return (input - 1);
}

int checkForWinner(int board[], int playerA, int playerB)
{
    int status = 0;

    if ((board[0] == 11 && board[1] == 11 && board[2] == 11) || (board[3] == 11 && board[4] == 11 && board[5] == 11) ||
        (board[6] == 11 && board[7] == 11 && board[8] == 11) || (board[0] == 11 && board[3] == 11 && board[6] == 11) ||
        (board[1] == 11 && board[4] == 11 && board[7] == 11) || (board[2] == 11 && board[5] == 11 && board[8] == 11) ||
        (board[0] == 11 && board[4] == 11 && board[8] == 11) || (board[2] == 11 && board[4] == 11 && board[6] == 11)) {
        return 11;
    }
    if ((board[0] == 12 && board[1] == 12 && board[2] == 12) || (board[3] == 12 && board[4] == 12 && board[5] == 12) ||
        (board[6] == 12 && board[7] == 12 && board[8] == 12) || (board[0] == 12 && board[3] == 12 && board[6] == 12) ||
        (board[1] == 12 && board[4] == 12 && board[7] == 12) || (board[2] == 12 && board[5] == 12 && board[8] == 12) ||
        (board[0] == 12 && board[4] == 12 && board[8] == 12) || (board[2] == 12 && board[4] == 12 && board[6] == 12)) {
        return 12;
    }

    for (int i = 0; i < 9; i++) {
        if (board[i] != 11 && board[i] != 12) // check for unmarked
            status = 1;
    }

    return status;
}

int main(void)
{
    int board[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int playerA = 11, playerB = 12;
    int currentPlayer = 0;

    while (checkForWinner(board, playerA, playerB) == 1) {
        if (currentPlayer == 0)
            currentPlayer = 11;
        else if (currentPlayer == 11)
            currentPlayer = 12;
        else if (currentPlayer == 12)
            currentPlayer = 11;
        printf("The current state of the Tic-Tac-Toe Board:\n");
        printBoard(board, playerA, playerB);

        printf("It is Player %c's turn.\n", (currentPlayer == 11 ? 'A' : 'B'));
        board[requestValidInput(board, playerA, playerB)] = currentPlayer;
    }

    if (checkForWinner(board, playerA, playerB) != 1 && checkForWinner(board, playerA, playerB) != 0)
        printf("Player %c wins!\n", (currentPlayer == 11 ? 'A' : 'B'));
    else if (checkForWinner(board, playerA, playerB) == 0)
        printf("It's a draw!\n");

    printBoard(board, playerA, playerB);

    return 0;
}
