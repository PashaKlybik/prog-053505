#include <stdio.h>
#include <math.h>

int n = 0;
float x, eps;

double sinRecursion(double);

int main()
{
    n = 0;
    printf("Enter X: ");
    scanf_s("%f", &x);
    printf("Enter eps: ");
    scanf_s("%f", &eps);

    printf("Math sin(x): %f\n", sin(x));
    printf("Recursion sin(x):  %f\n", sinRecursion(x));
    printf("Number of stacks: %d\n", n);

    return 0;
}

double sinRecursion(double p)
{
    if (fabs(p) < eps) return p;
    else
    {
        n++;
        return p + sinRecursion(-p * x * x / (2 * n) / (2 * n + 1));
    }
}
