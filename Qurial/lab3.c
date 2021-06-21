#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col;

    printf("Enter number of rows: ");
    while (!scanf_s("%i", &row)) {
        printf("wrong input! Try again.\n");
        while (getchar() != '\n');
        printf("Enter number of rows: ");
    }
    row += 2;

    printf("Enter number of collums: ");
    while (!scanf_s("%i", &col)) {
        printf("wrong input! Try again.\n");
        while (getchar() != '\n');
        printf("Enter number of collums: ");
    }
    col += 2;

    int* arr = (int*)malloc((row + 1) * (col + 1) * sizeof(int));
    int i, j, k = 0, l = 1;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            *(arr + i * col + j) = 0;
        }
    }
    for (i = 1; i < row - 1; i++) {
        for (j = 1; j < col - 1; j++) {
            while (k == 0) {
                *(arr + i * col + j) = l;
                //int temp = *(arr + i * col + j);
                if (l == *(arr + (i + 1) * col + j) || l == *(arr + (i - 1) * col + j)) {
                    k = 0;
                }
                else if (l == *(arr + i * col + (j + 1)) || l == *(arr + i * col + (j - 1))) {
                    k = 0;
                }
                else if (l == *(arr + (i + 1) * col + (j + 1)) || l == *(arr + (i - 1) * col + (j - 1))) {
                    k = 0;
                }
                else if (l == *(arr + (i + 1) * col + (j - 1)) || l == *(arr + (i - 1) * col + (j + 1))) {
                    k = 0;
                }
                else {
                    k = 1;
                }
                l++;
            }
            k = 0;
            l = 1;
        }
    }

    printf("The matrix elements are:\n");
    for (i = 1; i < row - 1; i++) {
        for (j = 1; j < col - 1; j++) {
            printf("%d ", *(arr + i * col + j));
        }
        printf("\n");
    }
    free(arr);
    return 0;
}