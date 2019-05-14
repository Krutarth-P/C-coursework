/*
This code is used to encypt numbers. It first adds 4 to each digit and then shifts each digit.
*/


#include <stdio.h>
#include <math.h>

void input(int* num) // recieves input
{
    do {
        printf("Please enter an integer greater than 99999: ");
        scanf("%d", num);
        if (*num <= 99999)
            printf("Incorrect input.\n");

    } while (*num <= 99999);
    printf("The number entered is %d\n", *num);
}
int add4(int num) // calulates add45 value
{
    int temp = 0, exp = 0;
    while (num > 0) {
        if ((num % 10) + 4 > 9)
            temp += (((num % 10) + 4) - 10) * pow(10, exp);
        else
            temp += ((num % 10) + 4) * pow(10, exp);

        num = num / 10;
        exp++;
    }
    return temp;
}
int shift(int num) // calculates the shifted value
{
    int temp = 0, exp = 1;
    while (num > 0) {

        if (num / 10 == 0)
            temp += num;
        else
            temp += ((num % 10) * pow(10, exp));

        num = num / 10;
        exp++;
    }
    return temp;
}

void printOutput(int encryptNum, int originalNum)
{
    printf("Original number: %d\n", originalNum);
    printf("Encrypted number: %d\n", encryptNum);
}

/*int main(int argc, char** argv)
{
    int num;

    input(&num);

    add4(num);

    shift(num);

    printOutput(shift(add4(num)),num);
    return 0;
}*/
