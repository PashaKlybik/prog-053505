#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <conio.h>


int i, j, a, max_size, max_i, max_j;

int is_square(int x, int y, int size, int** matrix)
{
    int i1, j1, s = 0;
    for (i1 = x; i1 < x + size; i1++)
    {
        for (j1 = y; j1 < y + size; j1++)
        {
            s += matrix[i1][j1];
        }
    }
    return s;
}

int main()
{
    srand(time(NULL));
    int N, M;
    int** matrix;
    printf("Enter size of matrix : N/M\n");
    scanf_s("%d %d", &N, &M);
    matrix = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
    {
        matrix[i] = (int*)malloc(M * sizeof(int));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%2d", matrix[i][j]);
        }
        printf("\n");
    }
    max_size = 0;
    max_i = max_j = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (a = j; a < M; a++)
                {
                    if (matrix[i][a] != 0) break;
                }
                a -= j; 
                if (i + a >= N) a = N - i;
                if (is_square(i, j, a, matrix) != 0) continue;
                if (a > max_size)
                {
                    max_size = a;
                    max_i = i;
                    max_j = j;
                }
            }
        }
    }

    printf("Max size %d * %d in [%d] [%d]\t", max_size, max_size, max_i + 1, max_j + 1);
    for (int i = 0; i < N; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}