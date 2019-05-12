#include <stdbool.h>
#include <stdio.h>

void initialBoard(char board[][26], int n)
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = 'U';

            if(i == (n / 2) - 1 && j == (n / 2) - 1)
                board[i][j] = 'W';

            if(i == (n / 2) - 1 && j == (n / 2))
                board[i][j] = 'B';

            if(i == (n / 2) && j == (n / 2) - 1)
                board[i][j] = 'B';

            if(i == (n / 2) && j == (n / 2))
                board[i][j] = 'W';
        }
    }
}

void printBoard(char board[][26], int n)
{
    for(int i = -1; i < n; i++) {
        for(int j = -1; j < n; j++) {

            if(i == -1 && j == -1)
                printf("  "); // top left space
            else if(i == -1)  // coloumns letterings
                printf("%c", 'a' + j);
            else if(j == -1) // row letterings
                printf("%c ", 'a' + i);

            if(i >= 0 && j >= 0)
                printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void config(char board[][26], int n)
{
    char a = 0, b = 0, c = 0;

    while(a != '!' && b != '!' && c != '!') {
        scanf(" %c%c%c", &a, &b, &c);

        if(a != '!' && b != '!' && c != '!')
            board[b - 97][c - 97] = a;
    }
}

bool positionInBounds(int n, int row, int col)
{
    return ((row >= 0 && row < n) && (col >= 0 && col < n));
}

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol)
{
    int i = row + deltaRow, j = col + deltaCol;
    while(positionInBounds(n, i, j) && (board[i][j] != 'U' && board[i][j] != colour)) {

        if(board[i + deltaRow][j + deltaCol] == colour && positionInBounds(n, i + deltaRow, j + deltaCol))
            return true;

        i = i + deltaRow;
        j = j + deltaCol;
    }

    return false;
}

void availableMoves(char board[][26], int n, char colour)
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'U') {
                if(checkLegalInDirection(board, n, i, j, colour, 0, -1)) // west
                    printf("%c%c\n", 97 + i, 97 + j);
                else if(checkLegalInDirection(board, n, i, j, colour, 1, -1)) // southwest
                    printf("%c%c\n", 97 + i, 97 + j);
                else if(checkLegalInDirection(board, n, i, j, colour, 1, 0)) // south
                    printf("%c%c\n", 97 + i, 97 + j);
                else if(checkLegalInDirection(board, n, i, j, colour, 1, 1)) // southeast
                    printf("%c%c\n", 97 + i, 97 + j);
                else if(checkLegalInDirection(board, n, i, j, colour, 0, 1)) // east
                    printf("%c%c\n", 97 + i, 97 + j);
                else if(checkLegalInDirection(board, n, i, j, colour, -1, 1)) // northeast
                    printf("%c%c\n", 97 + i, 97 + j);
                else if(checkLegalInDirection(board, n, i, j, colour, -1, 0)) // north
                    printf("%c%c\n", 97 + i, 97 + j);
                else if(checkLegalInDirection(board, n, i, j, colour, -1, -1)) // northwest
                    printf("%c%c\n", 97 + i, 97 + j);
            }
        }
    }
}

bool checkValid(char board[][26], int n, int b, int c, char a)
{
    if(positionInBounds(n, b, c) && (board[b][c] == 'U')){
        return (checkLegalInDirection(board, n, b, c, a, 0, -1) || checkLegalInDirection(board, n, b, c, a, 1, -1) ||
            checkLegalInDirection(board, n, b, c, a, 1, 0) || checkLegalInDirection(board, n, b, c, a, 1, 1) ||
            checkLegalInDirection(board, n, b, c, a, 0, 1) || checkLegalInDirection(board, n, b, c, a, -1, 1) ||
            checkLegalInDirection(board, n, b, c, a, -1, 0) || checkLegalInDirection(board, n, b, c, a, -1, -1));
    }
    else
        return false;
}

void flipTiles(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol)
{
    board[row][col]=colour;
    int i = row + deltaRow, j = col + deltaCol;
    while(positionInBounds(n, i, j) && board[i][j] != colour) {

        board[i][j] = colour;

        i = i + deltaRow;
        j = j + deltaCol;
    }
}

void flipboard(char board[][26], int n, int i, int j, char colour)
{
    if(checkLegalInDirection(board, n, i, j, colour, 0, -1)) // west
        flipTiles(board, n, i, j, colour, 0, -1);
    if(checkLegalInDirection(board, n, i, j, colour, 1, -1)) // southwest
        flipTiles(board, n, i, j, colour, 1, -1);
    if(checkLegalInDirection(board, n, i, j, colour, 1, 0)) // south
        flipTiles(board, n, i, j, colour, 1, 0);
    if(checkLegalInDirection(board, n, i, j, colour, 1, 1)) // southeast
        flipTiles(board, n, i, j, colour, 1, 1);
    if(checkLegalInDirection(board, n, i, j, colour, 0, 1)) // east
        flipTiles(board, n, i,j, colour, 0, 1);
    if(checkLegalInDirection(board, n, i, j, colour, -1, 1)) // northeast
        flipTiles(board, n, i, j, colour, -1, 1);
    if(checkLegalInDirection(board, n, i, j, colour, -1, 0)) // north
        flipTiles(board, n, i, j, colour, -1, 0);
    if(checkLegalInDirection(board, n, i, j, colour, -1, -1)) // northwest
        flipTiles(board, n, i, j, colour, -1, -1);
}

int main(int argc, char** argv)
{
    int n;
    char board[26][26], a, b, c;
    
    printf("Enter the board dimension: ");
    scanf("%d", &n);

    initialBoard(board, n);
    printBoard(board, n);

    printf("Enter board configuration:\n");
    config(board, n);
    printBoard(board, n);

    printf("Available moves for W:\n");
    availableMoves(board, n, 'W');

    printf("Available moves for B:\n");
    availableMoves(board, n, 'B');

    printf("Enter a move:\n");
    scanf(" %c%c%c", &a, &b, &c);

    if(checkValid(board, n,  b - 97, c - 97,a)){
        printf("Valid move.\n");
        flipboard(board, n,  b - 97, c - 97,a);
    }
    else
        printf("Invalid move.\n");

    printBoard(board, n);

    return 0;
}
