
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<locale.h>

void Iteration(float x, float eps)
{
    int count = 0;
    float itersin = 0, math = sinf(x);
    do
    {
        count++;
        itersin += pow(-1, count - 1) * pow(x, 2 * count - 1) / fact(2 * count - 1);
    } while (math - eps > itersin || math + eps < itersin);
    printf_s("Итерационный синус sin(x): %lf\nn2: %d\n", itersin, count);
    printf_s("\nМатематический синус sin(x): %lf\n", math);
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
int main()
{
    float epsilon, radian;
    int x, period, cycles = 1;
    char* locale = setlocale(LC_ALL, "ru");
    printf_s("Введите х:");
    scanf_s("%d", &x);
    if (x > 180)
    {
        period = x / 180;
        x -= 180 * period;
    }
    printf_s("Введите е: ");
    scanf_s(" %f", &epsilon);
    radian = (float)x / 180 * 3.14;
    printf_s("\nРекурсивный синус sin(x): %lf\n", Recursion(radian, epsilon, &cycles));
    printf_s("n1: %d\n\n", cycles);
    Iteration(radian, epsilon);
    return 0;
}
