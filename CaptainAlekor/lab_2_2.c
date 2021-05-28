#include <stdio.h>
#include <math.h>

double InitFact(int n)
{
	double prod = 1;
	for (int i = 1; i <= n; i++)
	{
		prod *= i;
	}
	return prod;
}

double RecFact(int n)
{
	if (n == 0 || n == 1) return 1;
	return n * RecFact(n - 1);
}

void FindMErrorNumber(double x, double merror)
{
	const double PI = 3.14159265359;
	int n = 0;
	double func = 0;
	while (merror == 0)
	{
		printf("Measurement error can't be equal to zero. Try again: ");
		scanf_s("%lf", &merror);
	}
	merror = fabs(merror);
	x = fabs(x);
	double sinf = sin(x);
	while (x >= 2 * PI) x -= 2 * PI;
	for (int i = 1; ; i++)
	{
		func += (pow(-1, i - 1) * pow(x, 2 * i - 1)) / InitFact(2 * i - 1);
		printf("%lf\n", func);
		if (fabs(sinf - func) < merror)
		{
			n = i;
			break;
		}
	}
	printf("sin(x): %f\nFunction: %f\nThe difference between function values is less than measurement error when n is equal to %d", sin(x), func, n);
}

void main()
{
	double x, merror;
	printf("Enter x: ");
	scanf_s("%lf", &x);
	double sinf = sin(x);
	printf("Enter measurement error: ");
	scanf_s("%lf", &merror);
	FindMErrorNumber(x, merror);
}	