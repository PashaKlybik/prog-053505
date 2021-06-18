#include <stdio.h>
#include <math.h>

int n = 0;
float x, eps;

double sinRecursion(double);
double sinIter();

int main()
{
    printf("Enter X: ");
    scanf_s("%f", &x);
    printf("Enter eps: ");
    scanf_s("%f", &eps);

    printf("Math sin(x): %f\n", sin(x));
    printf("Recursion sin(x):  %f\n", sinRecursion(x));
    printf("Number of stacks: %d\n", ++n);

    printf("Iteration sin(x): %f\n", sinIter());
    printf("Number of iterations: %d\n", n);

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


double sinIter()
{
    double p, sum;
    sum = p = x;

    n = 1;
    while (fabs(p) > eps)
    {
        p *= -x * x / (2 * n) / (2 * n + 1);
        sum += p;
        n++;
    }
    return sum;

}