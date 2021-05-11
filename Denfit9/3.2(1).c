#include <stdio.h>
#include <malloc.h>
#include <math.h>
int main() {
	int n = 0;
	int m = 0;
	int zero = 0;
	float correct = 0.00000001;
	printf("n=");
	scanf_s("%d", &n);
	printf("m=");
	scanf_s("%d", &m);
	float** A = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++) {
		A[i] = (float*)malloc(m * sizeof(float));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{   
			printf("Enter element of matrix [%d][%d]  ",i+1,j+1);
			scanf_s("%f", &A[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%.0f ", A[i][j]);
		}
		printf("\n");
	}
	int maxrows = -1;
	float processedEl;
	int rang = -1;
	for (int i = 0, j = 0; i < n && j < m;)
	{
		processedEl = 0.0;
		for (int k = i; k < n; k++)
		{
			if (fabs(A[k][j]) > processedEl)
			{
				maxrows = k;
				processedEl = fabsf(A[k][j]);
			}
		}
		if (processedEl <= correct) {
			for (int k = i; k < n; k++) {
				A[k][j] = 0.0;
			}
			j++;
			continue;
		}

		if (maxrows != i)
		{
			for (int k = j; k < m; k++)
			{
				processedEl = A[i][k];
				A[i][k] = A[maxrows][k];
				A[maxrows][k] = -processedEl;
			}
		}

		for (int k = i + 1; k < n; k++)
		{
			processedEl = -A[k][j] / A[i][j];
			A[k][j] = 0.0;
			for (maxrows = j + 1; maxrows < m; maxrows++)
			{
				A[k][maxrows] += processedEl * A[i][maxrows];
			}
		}
		i++; j++;
		rang = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == 0) {
				zero++;
			}
		}
	}
	if (zero == n * m) {
		rang = 0;
	}
	printf("Rang is %d", rang);
	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);
}
