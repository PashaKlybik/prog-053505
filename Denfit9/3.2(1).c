#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int m, n
	double* a;
	int i, j, rang;
	printf("m= ");
	scanf_s("%d", &m);
	while (m <= 0)           //исправим возможно создание "невозможной" матрицы
	{
		printf("Very funny");
		scanf_s("%d", &m);
	}
	printf("n=");
	scanf_s("%d", &n);
	while (n <= 0)                          
	{
		printf("Very funny");
		scanf_s("%d", &n);
	}
	a = (double*)malloc(m * n * sizeof(double));
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("Enter element of matrix [%d][%d]  ", i + 1, j + 1);
			scanf_s("%lf", &(a[i * n + j]));
		}
	}
	printf("\n\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.1lf   ", a[i * n + j]);
		}
		printf("\n");
	}
	printf("\n\n");
	rang = gaussMethod(m, n, a);
	printf("Rang=%d\n", rang);
	free(a);
	return 0;
}

int gaussMethod(int m, int n, double* a) {
	int i, j;
	int zero = 0;
	double processedEl;
	int  k, maxRows;

	i = 0; j = 0;
	while (i < m && j < n) {
		processedEl = 0.0;                                 
		for (k = i; k < m; k++) 
		{
			if (fabs(a[k * n + j]) > processedEl)
			{
				maxRows = k;
				processedEl = fabs(a[k * n + j]);
			}
		}
		if (processedEl <= 0.001) 
		{                  			 //приравниваем погрешность к нулю
			for (k = i; k < m; k++) 
			{
				a[k * n + j] = 0.0;
			}
			j++;
			continue;
		}

		if (maxRows != i)               // сравним строки  и поменяем местами
		{
			for (k = j; k < n; k++) 
			{
				processedEl = a[i * n + k];
				a[i * n + k] = a[maxRows * n + k];
				a[maxRows * n + k] = (-processedEl);      //соответственно поменяем и знак
			}
		}
		for (k = i + 1; k < m; k++)            // обнуляем столбец 
		{
			processedEl = (-a[k * n + j] / a[i * n + j]);
			a[k * n + j] = 0.0;                     //исправляем возможную погрешность
			for (maxRows = j + 1; maxRows < n; maxRows++)
			{
				a[k * n + maxRows] += processedEl * a[i * n + maxRows];
			}
		}
		i++; j++;           
	}
	for (int i = 0; i < n; i++)                //на всякий случай проверим на ноль отдельно
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i * j] == 0)
			{
				zero++;
			}
		}
	}
	if (zero == n * m) {
		i = 0;
	}
	return i;
}
