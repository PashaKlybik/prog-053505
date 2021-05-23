#include "Functions.h"


int main()
{
	long double x, sum = 0, FirstProblem, AdmisibleError,n=1.0;
	printf("sin(x)=x-x^3/3!+x^5/5!-...+(-1)^(n-1)*x^(2n-1)/(2n-1)!\n");
	printf("Enter the x:");
	scanf_s("%lf", &x);
	FirstProblem = sin(x);
	printf("Enter the admisseble error (pogreshnost'):");
	scanf_s("%lf", &AdmisibleError);
	printf("\tThe sum is:%.10lf", CountingSum(FirstProblem, AdmisibleError, x, sum, n));
	return 0;
}