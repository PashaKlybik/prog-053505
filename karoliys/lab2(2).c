//lab2 task 2.2.6
#include <stdio.h>
#include <math.h>
#include <locale.h>

long double fact(int n) {
	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}
void SinXIt(long double X, long double E)
{
	long double sinx = 0;
	for (int n = 1; ; n++)
	{
		sinx += pow(-1, n - 1) * pow(X, 2 * n - 1) / fact(2 * n - 1);
		if (fabs(sin(X) - sinx) < E)
		{
			printf("sin(x) by iterrarion:%f n: %d\n", sinx, n);
			break;
		}
	}
}
double SinXRec(double x, double e, int* n)
{
	double sinx = (pow(-1, *n - 1) * pow(x, 2 * (*n) - 1) / fact(2 * (*n) - 1));
	if (fabs(sinx) <= e)
	{
		(*n)--;
		return 0;
	}
	(*n)++;
	return (sinx + SinXRec(x, e, n));
}

int main()
{
	setlocale(LC_ALL, "Rus");
	long double X = 0, E;
	int n = 1;
	printf("Enter X in radians:"); scanf_s("%lf", &X);
	int TempX = 0;
	if (X / 2 * 3.1415926535 > 0) // grow > 2P
	{
		TempX = X / (2 * 3.1415926535);
		X = X - 2 * 3.1415926535 * TempX;
	}
	printf("Enter error:"); scanf_s("%lf", &E);
	printf("sin(x):%f\n", sin(X));
	SinXIt(X, E);
	printf("sin(x) by recursion: %lf ", SinXRec(X, E, &n)); printf("n: %d\n", n);

	return 0;
}