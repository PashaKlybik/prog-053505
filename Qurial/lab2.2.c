#include <stdio.h>
#include "math.h"
#define PI 3.1415926535

int main()
{
    int n = 1;
    long double epsilon, x, factorial = 1, rightSide = 0, leftSide;

    printf("Enter x = ");
    while (!scanf_s("%lf", &x)) {
        printf("Wrong input! Try again\n");
        while (getchar() != '\n');
        printf("x = ");
    }
    while (x > 360) { x = x - 360; }
    x = (x * PI) / 180;

    printf("Enter epsilon = ");
    while (!scanf_s("%lf", &epsilon) || !(epsilon > 0 && epsilon < 1))
    {
        printf("Wrong input! Try again\n");
        while (getchar() != '\n');
        printf("epsilon = ");
    }

    leftSide = sin(x);
    printf("\nLeft Side: %lf", leftSide);
    while (0 == 0) {

        rightSide += ((pow(x, ((2 * n) - 1))) / factorial) * pow(-1, (n - 1));
        if (fabs(leftSide - rightSide) <= epsilon) { break; }
        if (rightSide == 0.000000) { break; }
        if (fabs(leftSide) < 0.000001) { break; }
        if (n == 200) { break; }

        n++;
        factorial *= (2 * n - 1) * (2 * n - 2);
    }
    printf("\nRight Side: %lf", rightSide);
    printf("\nThe number of n: %d", n);
}