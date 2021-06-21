#include <stdio.h>
#include <math.h>

double fact(int n) {
    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    else
        return n * fact(n - 1);
}

double recursion(double x, double eps, int n) {
    double recs = (pow(-1, (double)n - 1) * pow(x, (double)2 * n - 1) / fact(2 * n - 1));

    if (fabs(recs) <= eps)
    {
        n--;
        return 0;
    }
    n++;
    return (recs + recursion(x, eps, n));
}

double iterative(double x) {
    double n = x;
    double sum = 0.0;
    int counter = 1;

    do
    {
        sum += n;
        n *= -1.0 * x * x / ((2 * (double)counter) * (2 * (double)counter + 1));
        counter++;
    } while ((n > 0.0 ? n : -n) > 1E-12);

    return sum;
}

int main()
{
    double x, sum = 0.0, epsylon;
    int i = 1;
    printf("Enter x: ");
    scanf_s("%lf", &x);
    printf("Enter epsylon: ");
    scanf_s("%lf", &epsylon);

    while (x > 6.28f) {
        x -= 6.28f;
    }
    
    printf("Recursion = %f\n", recursion(x, epsylon, 1));
    printf("Iterative = %f\n", iterative(x));
    printf("Sinus = %f\n", sin(x));
    return 0;
}
