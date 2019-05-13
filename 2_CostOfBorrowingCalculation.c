/*
This program calculates the cost of borrowing and monthly payment when a certain amount of money is borrowed on credit 
and is to be repayed with a certain monthly interest rate over a certain duration.
*/


#include <stdio.h>
#include <math.h>

int main(int argc, char** argv)
{
    double originalCost, interest, numMonths, payment;

    printf("Enter the purchase price of the item: "); 
    scanf("%lf", &originalCost);

    printf("Enter the interest rate per year as a percentage: "); 
    scanf("%lf", &interest);

    printf("Enter the number of months for repayment: "); 
    scanf("%lf", &numMonths); 

    interest = (interest / 100) / 12; // calculates interest rate for months

    payment = originalCost * interest / (1 - (pow(1 + interest, -1 * (numMonths)))); // calculates the monthly payment amount

    printf("The monthly payment is: %.2lf\n", payment); // displays the payment amount
    printf("The total cost of the purchase is: %.2lf\n", payment * numMonths); 
    return 0;
}
