#include <stdio.h>
#include <locale.h>
#include <math.h>

double rsin(double p, float eps, float x, int n)
{
    if (fabs(p) < eps) return p;
    else
    {
        n++;
        return p + rsin((-p * x * x / (2 * n) / (2 * n + 1)), eps, x, n);
    }
}


double isin(float eps, float x, int n)
{
    double p, res = p = x;

    n = 1;
    while (fabs(p) > eps)
    {
        p *= -x * x / (2 * n) / (2 * n + 1);
        res += p;
        n++;
    }
    return res;

}

int main()
{
    int n = 0;
    float x, eps;

    setlocale(LC_ALL, "Rus");

    printf("������� X: ");
    scanf_s("%f", &x);
    printf("������� �����������: ");
    scanf_s("%f", &eps);

    printf("sin(x): %f\n", sin(x));

    double rs = rsin(x, eps, x, n);
    printf("sin(x) (����������� �������):  %f\n", rs);
    printf("���-�� �����: %d\n", ++n);

    double is = isin(eps, x, n);
    printf("sin(x) (������������ �������): %f\n", is);
    printf("���������� ��������: %d\n", n);

    return 0;
}