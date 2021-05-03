#include <stdio.h>
#include <math.h>

double x, e;
int n = 0;

double Recursive(double p) {
    if (fabs(p) < e) {
        return p;
    }
    else {
        n++;
        return p + Recursive(-p * x * x / (2 * n) / (2 * n + 1));
    }
}

double Iterative() {
    double v, sum;
    sum = v = x;
    n = 1;
    while (fabs(v) > e) {
        v *= -x * x / (2 * n) / (2 * n + 1);
        sum += v;
        n++;
    }
    return sum;
}

int main()
{
    printf("Enter x: ");
    scanf_s("%lf", &x);
    printf("Enter e: ");
    scanf_s("%lf", &e);

    printf("Recursive: %.10lf\n", Recursive(x));
    printf("n1: %d\n", ++n);
    printf("Iterative: %.10lf\n", Iterative());
    printf("n2: %d\n", n);
    printf("Sinus: %.10lf\n", sin(x));
}