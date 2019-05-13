/*
This program will help approximate a definite integral for a function using left, right, and mid-point Riemann sums.
*/


#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool validateInput(double left, double right, int n)
{
    return !(left < -10.0 || right > 10.0 || right <= left || n <= 0);
}

double evalFunc(double x)
{
    return (2 * (pow(x, 2)) - (7 * x) - 2);
}

int main(int argc, char** argv)
{
    double left, right, dx, mSum = 0, lSum = 0, rSum = 0;
    int n;

    do {
        printf("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use.\nTo exit enter 0 0 0\n");
        scanf("%lf %lf %d", &left, &right, &n);

        if (!validateInput(left, right, n))
            printf("Invalid inputs...\n\n");

        if (left == 0 && right == 0 && n == 0) {
            printf("Terminating main!\n");
            return 0;
        }
    } while (!validateInput(left, right, n));

    dx = (right - left) / n; //calculates the step size

    printf("With Step Size: %.4lf\n", dx);
    printf("The approximate integral of the f(x) = 2(x^2)-7x-2\n");
    printf("Bound between %.2lf and %.2lf, using %d rectangles is as follows\n\n", left, right, n);

    int i;
    for (i = 0; i < n; i++) {
        mSum += (evalFunc((dx / 2) + (i * dx + left))) * dx; // midpoint evaluation
        lSum += (evalFunc(i * dx + left)) * dx;              // leftpoint evaluation
    }

    for (i = 1; i <= n; i++) // rightpoint evaluation
        rSum += (evalFunc(i * dx + left)) * dx;

    printf("Mid point evaluation approximate: %.4lf\n", mSum);
    printf("Left point evaluation approximate: %.4lf\n", lSum);
    printf("Right point evaluation approximate: %.4lf\n", rSum);
    return 0;
}
