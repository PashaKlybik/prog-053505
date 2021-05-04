#include <stdio.h>
#include <math.h>
float n = 0;
float x, epsilon;

double Recursion(double p)
{
    if (fabs(p) < epsilon) return p;
    else
    {
        n++;
        return p + Recursion(-p * x * x / (2 * n) / (2 * n + 1));
    }
}

double Iter()
{
    double p, sum;
    sum = p = x;

    n = 1;
    while (fabs(p) > epsilon)
    {
        p *= -x * x / (2 * n) / (2 * n + 1);
        sum += p;
        n++;
    }
    return sum;

}
int main()
{
    printf("Enter X: ");
    scanf_s("%f", &x);
    printf("Enter epsilon value: ");
    scanf_s("%f", &epsilon);
    printf("Math sin(x): %f\n", sin(x));
    printf("sin(x) using recursion =  %f\n", Recursion(x));
    printf("n1: %f\n", ++n);
    printf("sin(x) using iterations = %f\n", Iter());
    printf("n2: %f\n", n);
    return 0;
}