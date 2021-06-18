/*lab2.2 var#6 
 Численно убедиться в справедливости равенства, для чего для
заданного значения х вычислить его левую часть и разложение,
стоящее в правой части. При каком n исследуемое выражение
отличается от sin x менее, чем на заданную погрешность ε?
Испытать разложение на сходимость при разных значениях х.*/
#include <stdio.h>
#include <math.h>

int Factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * Factorial(n - 1);
    }
}

void Iteration(float x, float epsilon)
{
    int count = 0;
    float sinus = 0, math = sinf(x);

    do
    {
        count++;
        sinus += pow(-1, count - 1) * pow(x, 2 * count - 1) / Factorial(2 * count - 1);
    } while (math - epsilon > sinus || math + epsilon < sinus);

    printf_s("Math sin(x): %lf\nsin(x) using iterations = %lf\nn2:%d\n", math, sinus,count);
}

float Recursion(float x, float eps, int* n)
{
    float recs = (pow(-1, *n - 1) * pow(x, 2 * (*n) - 1) / Factorial(2 * (*n) - 1));
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