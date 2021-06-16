/*Элементы массива a(n, m) ниже главной диагонали равны нулю.
Выше и на главной диагонали нулевых элементов нет.
Строки и столбцы случайным образом перемешаны.Перестановкой строк и столбцов восстановить исходный массив.*/


#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
void SwapRow(int** mass, int count, int row1, int row2)
{
    int* temp = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
    {
        temp[i] = mass[row1][i];
        mass[row1][i] = mass[row2][i];
        mass[row2][i] = temp[i];
    }
    free(temp);
}

void SwapColumn(int** mass, int count, int column1, int column2)
{
    int* temp = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
    {
        temp[i] = mass[i][column1];
        mass[i][column1] = mass[i][column2];
        mass[i][column2] = temp[i];
    }
    free(temp);
}

void ShowArray(int** mass, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            printf("%d  ", mass[i][k]);
        }
        printf("\n");
    }
}
void SwapRow(int** mass, int count, int row1, int row2);
void SwapColumn(int** mass, int count, int column1, int column2);
void ShowArray(int** mass, int n, int m);
int main()
{
    srand(0);
    int n, m;
    printf("Enter array size: n, m: ");
    scanf_s("%d %d", &n, &m);
    int** mass = (int**)malloc(n * sizeof(int*));
    int** massCopy = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        mass[i] = (int*)malloc(m * sizeof(int));
        massCopy[i] = (int*)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            if (i > k)
            {
                mass[i][k] = 0;
            }
            else
            {
                mass[i][k] = rand() % 9 + 1;
            }
            massCopy[i][k] = mass[i][k];
            printf("%d  ", mass[i][k]);
        }
        printf("\n");
    }
    printf("\nMix rows and columns\n");
    for (int i = 0; i < rand() % 100 + 200; i++)
    {
        SwapColumn(mass, n, rand() % m, rand() % m);
        SwapRow(mass, m, rand() % n, rand() % n);
    }
    printf("\n");
    ShowArray(mass, n, m);
    printf("\nRestoring the array\n");
    for (int i = 0; i < n; i++)
    {
        int zeroCount = 0;
        for (int k = 0; k < m; k++)
        {
            if (mass[i][k] == 0)
            {
                if (k > zeroCount)
                {
                    SwapColumn(mass, n, k, zeroCount);
                }
                zeroCount++;
            }
        }
        if (i > zeroCount && zeroCount != m)
        {
            SwapRow(mass, m, i, zeroCount);
            i--;
        }
    }
    ShowArray(mass, n, m);
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            if (mass[i][k] != 0)
            {
                if (mass[i][k] != massCopy[i][k])
                {
                    for (int l = 0; l < m; l++)
                    {
                        if (mass[i][k] == massCopy[i][l] && mass[i][k] != mass[i][l])
                        {
                            SwapColumn(mass, n, k, l);
                         
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        free(mass[i]);
        free(massCopy[i]);
    }
    free(mass);
    free(massCopy);
}

