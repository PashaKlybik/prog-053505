#include <stdio.h>
#include <math.h>

float leftSight(float x) {
    float a = sinf(x);
    return a;
}

float fact(int n) {
    return n < 0 ? 0 : n == 0 ? 1 : n * fact(n - 1);
}

float rightSight(float x, int n) {
    float b = 0;
    for (int i = 1; i <= n; i++)
    {
        b = b + powf(-1, i - 1) * (powf(x, 2 * i - 1) / fact(2 * i - 1));
    }
    return b;
}

int main()
{
    float x = 0, e = 0, a, b;
    int n = 0;

    printf("Enter x:");
    scanf_s("%f", &x);

    printf("Enter n:");
    scanf_s("%d", &n);

    printf("Enter the margin of error 'e':");
    scanf_s("%f", &e);

    a = leftSight(x);
    b = rightSight(x, n);

    printf("The left part of the expression is equal to:%f\n", a);
    printf("The right part of the expression is equal to:%f\n", b);

    if (fabsf(a - b) <= e)
        printf("The expression under study converges at n=%d\n", n);
    else
        printf("The expression under study does not converge\n");
}