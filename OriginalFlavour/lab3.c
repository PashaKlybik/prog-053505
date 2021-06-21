#include <stdio.h>
#include <stdlib.h>
#include "safe_input.h"

void spiral_output(int** array, int n) {
    int x = n / 2, y = n / 2, step = 1, i, j;
    printf("%d ", array[x][y]);
    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < step; j++)
            printf("%d ", array[x][--y]);
        for (j = 0; j < step; j++)
            printf("%d ", array[--x][y]);
        step++;
        for (j = 0; j < step; j++)
            printf("%d ", array[x][++y]);
        for (j = 0; j < step; j++)
            printf("%d ", array[++x][y]);
        step++;
    }
    for (j = 0; j < step - 1; j++)
        printf("%d ", array[x][--y]);
}

int main() {
    int n;
    while (1) {
        n = get_int();
        if (n % 2 == 1) break;
        puts("Number should be odd");
    }

    int i;
    int** array = (int**)malloc(n * sizeof(int*));
    if (array == NULL) {
        printf("Not enough memory!");
        return;
    }
    for (i = 0; i < n; ++i) {
        array[i] = (int*)malloc(n * sizeof(int*));
        if (array[i] == NULL) {
            printf("Not enough memory!");
            return;
        }
        array[i] = get_n_ints(n);
    }

    spiral_output(array, n);
    return 0;
}