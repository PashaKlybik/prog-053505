#include <malloc.h>
#include "Functions.h"


int main()
{
	int ROWS, COLS;
	float ESP = powf(10.0, -9.0);
	printf("Enter the number or rows:");
	scanf_s("%d", &ROWS);
	printf("Enter the number of cols:");
	scanf_s("%d", &COLS);
	float** matrix = (float**)malloc(ROWS * sizeof(float*));
	for (int i = 0; i < ROWS; i++)
	{
		matrix[i] = (float*)malloc(COLS * sizeof(float));
	}
	FillMatrix(matrix, ROWS, COLS);
	system("cls");
	PrintMatrix(matrix, ROWS, COLS);
	printf("The Rang of Matrix is:%d",GaussMethod(matrix, ROWS, COLS, ESP));
	for (int i = 0; i < ROWS; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}