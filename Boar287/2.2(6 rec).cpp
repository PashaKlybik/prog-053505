#include "Functions.h"
int fact(int n)
{
	if (n == 1)
		return 1;
	return n * fact(n - 1);
}

long double CountingNumbers(const long double x, const long double n)
{
	return powl(-1, n - 1) * powl(x, 2 * n - 1) / fact(2 * n - 1);
}

long double CountingSum(long double FisrtProblem,long double AdmissibleError, long double x,long double sum,long double n)
{
	if (fabs(CountingNumbers(x, n + 1) - CountingNumbers(x, n)) < AdmissibleError)
	{
		printf("\tThe n is:%.0lf\n", n);
		return 0;
	}
	return CountingNumbers(x, n) + CountingSum(FisrtProblem, AdmissibleError, x, sum, n+1);
}