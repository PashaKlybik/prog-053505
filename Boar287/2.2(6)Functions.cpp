#include "Functions.h"
int fact(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	return n * fact(n - 1);
}

long double CountingRow(long double x, long double n, long double sum)
{
	for (long double i = 1; i <= n; i++)
	{
		sum += pow(-1, i - 1) * pow(x, 2 * i - 1) / fact(2 * i - 1);
	}
	return sum;
}

void ErrorCalculation(long double n, long double FirstProblem, long double AdmissibleError, long double sum, long double x)
{
	while (!(fabsl(FirstProblem - sum) <= AdmissibleError))
	{
		sum += pow(-1, n - 1) * pow(x, 2 * n - 1) / fact(2 * n - 1);
		n++;
		if (n > 100)
		{
			printf("\tThe limits of these math functions is not the same");
			return;
		}
	}
	printf("\tThe sum is:%.10lf\n",sum);
	printf("\tThe n is:%.0lf", n);
}