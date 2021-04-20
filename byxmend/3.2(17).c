// lab_3 task 3.2 option 17

/*
Черный квадрат. В матрице a(m, n), состоящей из нулей и единиц, 
найти квадрат заданного размера (квадратную подматрицу), 
состоящий целиком из нулей.
*/

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

int main( )
{
    int stringFirstMatrix, stringSecondMatrix;
    int columnFirstMatrix, columnSecondMatrix;
    int i, j, k, w, a, b, x, y;

    srand(time(0));

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

    printf("Size matrix:\n");
    printf("String:");
    scanf_s("%d", &stringFirstMatrix);
    printf("Column:");
    scanf_s("%d", &columnFirstMatrix);

    int** array = (int**)malloc(sizeof(int*) * stringFirstMatrix);
    for(i = 0; i < stringFirstMatrix; i++)
        array[i] = (int*)malloc(sizeof(int*) * columnFirstMatrix);

    printf("Random matrix:\n");

    for (i = 0; i < stringFirstMatrix; i++) {
        for (j = 0; j < columnFirstMatrix; j++) {
            array[i][j] = rand() % 2;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    printf("Size matrix (all 0):\n");
    printf("String:");
    scanf_s("%d", &stringSecondMatrix);
    printf("Column:");
    scanf_s("%d", &columnSecondMatrix);

    printf("Find matrix:\n");

    x = columnFirstMatrix - columnSecondMatrix;
    y = stringFirstMatrix - stringSecondMatrix;
    w = 0;

    for (b = 0; b < y + 1; b++)
    {
        for (a = 0; a < x + 1; a++)
        {
            k = 0;

            for (i = b; i < stringSecondMatrix + b; i++)
            {
                for (j = a; j < columnSecondMatrix + a; j++)
                {
                    if (array[i][j] == 0)
                        k++;
                }
            }

            if (k == stringSecondMatrix * columnSecondMatrix)
            {
                w++;

                printf("Case:%d\n", w);

                for (x = 0; x < stringFirstMatrix; x++)
                {
                    for (y = 0; y < columnFirstMatrix; y++)
                    {
                        if (((x >= b) && (x < i)) && ((y >= a) && (y < j)))
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                            printf("%d ", array[x][y]);
                        }
                        else
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                            printf("%d ", array[x][y]);
                        }
                    }

                    printf("\n");
                }
            }
        }
    }

    for(int i = 0; i < stringFirstMatrix; i++)
        free(array[i]);
    free(array);

    return 0;
}