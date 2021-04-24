#include <stdio.h>
#include <math.h>

float x, e;
int n = 0;

double Rec(double p) {
    if (fabs(p) < e){
        return p;
    } else {
        n++;
        return p + Rec(-p * x * x / (2 * n) / (2 * n + 1));
    }
}

double Iter() {
    double v, sum;
    sum = v = x;
    n = 1;
    while (fabs(v) > e) {
        v *= -x * x / (float )(2 * n) / (float )(2 * n + 1);
        sum += v;
        n++;
    }
    return sum;
}

int main()
{
    printf("Enter x:");
    scanf_s("%f", &x);
    printf("Enter e:");
    scanf_s("%f", &e);

    printf("Rec: %f\n", Rec(x));
    printf("n1:%d\n", ++n);
    printf("Iter:%f\n", Iter());
    printf("n2:%d\n", n);
    printf("Math:%f\n", sinf(x));
}
