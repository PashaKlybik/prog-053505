#include "Functions.h"

void FillMatrix(float** arr, int ROWS, int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			scanf_s("%f", &arr[i][j]);
		}
	}
}
void  PrintMatrix(float** arr, int ROWS, int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%.0f  ", arr[i][j]);
		}
		printf("\n");
	}
}
int GaussMethod(float** arr, int ROWS, int COLS, float EPS)
{
	int NumberOfMaxROW = -1;
	float Element;
	int Rang = -1;
	for (int i = 0, j = 0; (i < ROWS && j < COLS);)
	{
		Element = 0.0;
		for (int k = i; k < ROWS; k++)
		{
			if (fabs(arr[k][j]) > Element)
			{
				NumberOfMaxROW = k;
				Element = fabsf(arr[k][j]);
			}
		}
		if (Element <= EPS)//Значит все элементы j-го столбца равны 0, но из за погрешности их нельзя сравнивать с нулём
		{
			for (int k = i; k < ROWS; k++)
			{
				arr[k][j] = 0.0;
			}
			j++;
			continue;
		}
		if (NumberOfMaxROW != i)//Сравниваем с текущей строкой
		{
			for (int k = j; k < COLS; k++)
			{
				Element = arr[i][k];
				arr[i][k] = arr[NumberOfMaxROW][k];
				arr[NumberOfMaxROW][k] = -Element;
			}
		}

		for (int k = i + 1; k < ROWS; k++)
		{
			Element = -arr[k][j] / arr[i][j];
			arr[k][j] = 0.0;//Опять же из-за погрешности
			for (NumberOfMaxROW = j + 1; NumberOfMaxROW < COLS; NumberOfMaxROW++)
			{
				arr[k][NumberOfMaxROW] += Element * arr[i][NumberOfMaxROW];
			}
		}
		i++; j++;
		Rang = i;
	}
	return Rang;
}