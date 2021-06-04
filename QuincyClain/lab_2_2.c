#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
int fact(int n)
{
	if (n == 0) {
		return  1;
	}
	else {
		return n * fact(n - 1);
	}
}
int  iteration(double Sin, double summa, int n, double e, double x)
{
	while (fabs(Sin - summa) > e)
	{
		++n;
		summa += pow(-1, n - 1) * pow(x, 2 * n - 1) / fact(2 * n - 1);
	}
	return n;

}
int  rec(double Sin, double summa, int n, double e, double x)
{
	++n;
	summa += pow(-1, n - 1) * pow(x, 2 * n - 1) / fact(2 * n - 1);
	if (fabs(Sin - summa) > e) {
		return rec(Sin, summa, n, e, x);
	}
	else {
		return n, Sin, summa;
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	double x, Sin, summa, e;
	int n = 0;
	printf("Введите икс:");
	while (scanf("%lf", &x) != 1)
	{
		printf("try again");
		while (getchar() != '\n');
	}
	printf("\n");
	printf("Введите погрешность :");
	scanf("%lf", &e);
	Sin = sin(x);
	summa = 0;
    n=  iteration(Sin,summa,n,e,x);
	//n = rec(Sin, summa, n, e, x);
	printf("При n = %d sin() отличается от разложения меньше чем на e = %.10lf\n", n, e);
	printf("%.12f\n", Sin);
	_getch();
	return 0;
}