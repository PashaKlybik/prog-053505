#include <stdio.h>
#include <math.h>

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

void Iteration(float x, float eps)
{
    int count = 0;
    float itsin = 0, math = sinf(x);

    do
    {
        count++;
        itsin += pow(-1, count - 1) * pow(x, 2 * count - 1) / fact(2 * count - 1);
    } while (math - eps > itsin || math + eps < itsin);

    printf_s("Math sin(x): %lf\nsin(x) using iterations = %lf\nn2: %d\n", math, itsin, count);
}

float Recursion(float x, float eps, int* n)
{
    float recs = (pow(-1, *n - 1) * pow(x, 2 * (*n) - 1) / fact(2 * (*n) - 1));
    if (fabs(recs) <= eps)
    {
        (*n)--;
        return 0;
    }
    (*n)++;
    return (recs + Recursion(x, eps, n));
}

int main()
{
    float epsilon, radian;
    int x, period, cycles = 1;

    printf_s("Enter X:");
    scanf_s("%d", &x);
    if (x > 180)
    {
        period = x / 180;
        x -= 180 * period;
    }
    printf_s("Enter epsilon: ");
    scanf_s(" %f", &epsilon);
    radian = (float)x / 180 * 3.14;
    printf_s("sin(x) using recursion = %lf\n", Recursion(radian, epsilon, &cycles));
    printf_s("n1: %d\n\n", cycles);
    Iteration(radian, epsilon);
    return 0;
}
