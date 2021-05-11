//Lab1 var 9
#include<stdio.h>

void main() 
{
	float n;
	int x, k;
	printf ("Vvedite chislo:");
	scanf_s ("%f", &n);
	x = (int)n;
	k = (100 * (n - x));
	printf("%d rub ", x);
	printf("%d kop", k);
	return 0;
}
