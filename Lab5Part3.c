#include <stdio.h>

void inputDate(int* day, int* month, int* year) // recieves input for the data
{
    printf("Please enter a date: ");
    scanf("%d/%d/%d", day, month, year);
}

void calculateDay(int day, int month, int year) // calculates the day of the week using zellers algorithm
{

    int A = month, B = day, C = year % 100, D = year / 100;
    int W, X, Y, Z, R;
    A = A - 2;
    if (A < 1) {
        A += 12;
        C = (year - 1) % 100;
        D = (year - 1) / 100;
    }

    W = (13 * A - 1) / 5;
    X = C / 4;
    Y = D / 4;
    Z = W + X + Y + B + C - 2 * D;
    R = Z % 7;

    if (R < 0)
        R += 7;

    if (R == 0)
        printf("The day %d/%d/%d is a Sunday.\n", day, month, year);
    if (R == 1)
        printf("The day %d/%d/%d is a Monday.\n", day, month, year);
    if (R == 2)
        printf("The day %d/%d/%d is a Tuesday.\n", day, month, year);
    if (R == 3)
        printf("The day %d/%d/%d is a Wednesday.\n", day, month, year);
    if (R == 4)
        printf("The day %d/%d/%d is a Thursday.\n", day, month, year);
    if (R == 5)
        printf("The day %d/%d/%d is a Friday.\n", day, month, year);
    if (R == 6)
        printf("The day %d/%d/%d is a Saturday.\n", day, month, year);
}
