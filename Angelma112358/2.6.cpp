#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

double factInit(int n){
	double prod = 1;
	for (int i = 1; i <= n; i++)
		prod *= i;
	return prod;
}

double factRect(int n){
	if (n == 0 || n == 1) return 1;
	return n * factRect(n - 1);
}

void factEffective(double x, double epsylon){
	int n = 0;
	double sum = 0;
	while (epsylon == 0){
		printf("Epsylon cannot be equal to zero. Try again: ");
		scanf_s("%lf", &epsylon);
	}
	epsylon = fabs(epsylon);
	x = fabs(x);
	double sinValue = sin(x);
	while (x >= 2 * PI) {
		x -= 2 * PI;
	}
	int i = 1;
	while (1) {
		sum += (pow(-1, i - 1) * pow(x, 2 * i - 1)) / factInit(2 * i - 1);
		if (fabs(sinValue - sum) < epsylon){
			n = i;
			break;
		}
		i++;
	}
	printf("sin(x): %f\nFact, counted by function: %f\nn: %d", sin(x), sum, n);
}

void main(){
	double x, epsylon;
	printf("Enter x: ");
	scanf_s("%lf", &x);
	double sinValue = sin(x);
	printf("Enter epsylon: ");
	scanf_s("%lf", &epsylon);
	factEffective(x, epsylon);
}