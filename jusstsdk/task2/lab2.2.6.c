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

double RecursiveComputing(double x, double e, int *i, double sum) {
    if (fabs(sum - sinf(x)) < e)
        return sum;

    sum += pow(x, 2 * (*i) - 1) / fact(2 * (*i) - 1) * pow(-1, (*i) - 1);
    (*i)++;

    return RecursiveComputing(x, e, i, sum);
}

int main() {
    double x, epsilon;

    printf("Enter x: ");
    scanf_s("%lf", &x);
    printf("Enter epsilon: ");
    scanf_s("%lf", &epsilon);

    double cycleSum = 0;
    int i;

    for (i = 1; fabs(cycleSum - sinf(x)) > epsilon; i++) {
        cycleSum += pow(x, 2 * i - 1) / fact(2 * i - 1) * pow(-1, i - 1);
    }

    printf("%s%lf\n", "sin(x) = ", sinf(x));
    printf("%s%lf\t\t%s%d\n", "Cycle result: ", cycleSum, "n = ", i);

    i = 1;
    double recursiveSum = RecursiveComputing(x, epsilon, &i, 0);

    printf("%s%lf\t%s%d\n", "Recursive result: ", recursiveSum, "n = ", i);

    return 0;
}   