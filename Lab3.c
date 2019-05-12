#include <stdio.h>

int main(int argc, char** argv)
{
    double coffeeCost, availableMoney, moneyLeft, averagePrice;
    int couponsRequired , purchasableCoffee, freeCoffee=0, numCoupons;

    printf("How much does a coffee cost?\n");
    scanf("%lf", &coffeeCost);

    if(coffeeCost < 0.01){
        printf("Invalid Input.\n");
        return 0;
    }

    printf("How many coupons does it take to get a free coffee?\n");
    scanf("%d", &couponsRequired);

    if(couponsRequired <= 1){
        printf("Invalid Input.\n");
        return 0;
    }

    printf("How much money do you have to spend on coffee this month?\n");
    scanf("%lf", &availableMoney);

    if(availableMoney < 0){
        printf("Invalid Input.\n");
        return 0;
    }

    purchasableCoffee = ((int)(availableMoney / coffeeCost)); //calultes the amount of purchasable coffee
    numCoupons=purchasableCoffee;
    printf("This month, you can purchase %d coffees at $%.2lf each.\n", purchasableCoffee, coffeeCost);

    while(numCoupons/couponsRequired >=1){ //calcuates the number of free coffee and coupons
        freeCoffee = (numCoupons/couponsRequired)+freeCoffee;
        numCoupons=purchasableCoffee-(freeCoffee* couponsRequired)+freeCoffee;
    }
    
    if(freeCoffee == 0)
        printf("You will not be able to redeem any additional coffees from coupons this month.\n");
    else
        printf("You will be able to redeem an additional %d coffee(s) from coupons.\n", freeCoffee);
            
    moneyLeft = availableMoney - (purchasableCoffee * coffeeCost);
    printf("At the end of the month, you will have $%.2lf and %d coupon(s) remaining.\n", moneyLeft, numCoupons);

    averagePrice = (purchasableCoffee *coffeeCost) / (purchasableCoffee + freeCoffee);
    if(availableMoney<=coffeeCost || availableMoney==0 )
        printf("On average, you spent $0.00 on each cup of coffee this month.\n");   
    else
        printf("On average, you spent $%.2lf on each cup of coffee this month.\n", averagePrice);
}

