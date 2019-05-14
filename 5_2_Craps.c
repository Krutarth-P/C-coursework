/*
    This code is used to generate the popular game of craps.
*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int rollDice(void) // calculates sum of rolled dice
{
    int roll1 = 0, roll2 = 0;

    roll1 = rand() % 6 + 1;
    roll2 = rand() % 6 + 1;

    return (roll1 + roll2);
}

bool playGame(void) // simulates the game of craps
{
    int roll = rollDice(), point;

    printf("You rolled: %d\n", roll);
    if (roll == 7 || roll == 11) {
        printf("You win!\n");
        return true;
    } else if (roll == 2 || roll == 3 || roll == 12) {
        printf("You lose!\n");
        return false;
    } else {
        point = roll;
        printf("Your point is: %d\n", point);
    }
    do {
        roll = rollDice();
        printf("You rolled: %d\n", roll);
        if (roll == point) {
            printf("You win!\n");
            return true;
        }
    } while (roll != 7);
    printf("You lose!\n");
    return false;
}

void winLoss(void) // keeps track of wins and losses
{
    int wins = 0, losses = 0;
    char response = ' ';
    do {
        if (playGame())
            wins++;
        else
            losses++;

        printf("Play again? ");
        scanf(" %c", &response); //
    } while (response == 'Y' || response == 'y');

    printf("\nWins: %d\n", wins);
    printf("Losses: %d\n", losses);
}
