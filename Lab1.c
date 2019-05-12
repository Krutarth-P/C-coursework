#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    double num1, num2, product, difference, sum;
	printf("Enter two positive numbers: ");
    scanf("%lf %lf",&num1, &num2);

    product=num1*num2;
    difference= num1-num2;
    sum=sqrt(num1)+ sqrt(num2);
    
    printf("The product is: %.2lf, the difference is: %.2lf and the sum of roots is: %.2lf\n",product, difference, sum);
	return 0;
}