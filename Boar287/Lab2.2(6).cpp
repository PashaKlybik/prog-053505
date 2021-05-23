#include <stdio.h>
#include "Functions.h"

int fact(int n);
long double CountingRow(long double x, long double n, long double sum);
void ErrorCalculation(long double n, long double FirstProblem, long double AdmissibleError, long double sum, long double x);

int main()
{
	long double x, sum = 0, FirstProblem, AdmisibleError, n;
	printf("sin(x)=x-x^3/3!+x^5/5!-...+(-1)^(n-1)*x^(2n-1)/(2n-1)!\n");
	printf("Enter the x:");
	scanf_s("%lf", &x);
	FirstProblem = sin(x);
	printf("Enter the number of numeric rows:");
	scanf_s("%lf", &n);
	sum = CountingRow(x, n, sum);
	printf("\tThe first part is:%.10lf\n", FirstProblem);
	printf("\tThe numberic row:%.10lf\n", sum);

	sum = 0;
	n = 1;
	printf("Enter the admisseble error (pogreshnost'):");
	scanf_s("%lf", &AdmisibleError);

	ErrorCalculation(n,FirstProblem,AdmisibleError,sum,x);
	return 0;
}



