#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

using namespace std;

void input_check(int& num) 
{
	bool flg = 1;
	char* num_arr = (char*) malloc (10*sizeof(char));
	while (flg)
	{
		num = 0;
		printf("Print x (integer from -999'999'999 to 999'999'999): ");
		if (!scanf_s("%s", num_arr, 10)) {
			printf("Wrong input, re-enter\n---------------------\n");
			rewind(stdin);
			continue;
		}

		int i = 0;
		if (num_arr[i] == '-')
		{
			i++;
		}

		for (flg = 0; num_arr[i]; i++) 
		{
			if (!isdigit(num_arr[i])) {
				printf("Wrong input, re-enter\n---------------------\n");
				flg = 1;
				break;
			}
		}

		if (!flg) 
		{
			if (!num_arr[i]) {
				i--;
			}
			int dec_place = 1;
			for (; i >= 0 && isdigit(num_arr[i]); i--)
			{
				num += (num_arr[i] - 48) * dec_place;
				dec_place *= 10;
			}
			if (num_arr[0] == '-') {
				num *= -1;
			}
		}
	}
	free(num_arr);
	num_arr = NULL;
}

void input_check(double& num) 
{
	while (true) {
		printf("Print epsilon (double from 1 to 0.0000000001): ");
		if (!scanf_s("%lf", &num)) {

		}

		else if (num>= 0.0000000001 && num <= 1)
		{
			break;
		}

		printf("Wrong input, re-enter\n---------------------\n");
		rewind(stdin);
	}
}

double minus_period(double &x)
{
	while (x > 2 * 3.14159265) 
	{
		x -= 2 * 3.14159265;
	}
	return x;
}

double power(double base, short pwr) 
{
	if (pwr == 0) 
	{
		return 1.0;
	}
	else
	{
		double res = base;
		unsigned short n = 1;
		while (n < pwr)
		{
			res *= base;
			n++;
		}
		return res;
	}
}

double factorial(int num) 
{
	double fact = 1;
	for (int i = num; i>0; i--)
	{
		fact *= i;
	}
	return fact;
}

double t_series(double &x, double& epsilon, short& n)
{
	x = minus_period(x);
	double series = x;
	while (fabs(sin (x) - series) >= epsilon)
	{
		n++;
		switch (n%2)
		{
		case 0:
			series -= power(x, n + n - 1) / factorial(n + n - 1);
			break;
		case 1:
			series += power(x, n + n - 1) / factorial(n + n - 1);
			break;
		}
	}
	return series;
}

int main(void) 
{
	printf("\t\t\tComparison of sin(x) and Taylor series\n");
	int x1;
	double epsilon;
	input_check(x1);
	input_check(epsilon);
	double x = x1;
	short n = 1;
	printf("|     sin(x)    | Taylor series |\n");
	printf("| %.10lf | %.10lf |\n", sin(x), t_series(x,epsilon, n));
	printf("\nAt number Taylor series' members = %hd\n", n);
	system("pause");
	return 0;
}
