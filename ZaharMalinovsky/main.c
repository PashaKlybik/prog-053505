#include <stdio.h>
#include <stdlib.h>

void clear_matrix(int **matrix, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free((matrix[i]));
    }
    free(matrix);
}

int **allocate_matrix(int n, int m) {
    int **matrix = (int **)malloc(n * sizeof(int *));
    if (matrix == NULL) {
        return NULL;
    }
    int i;
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
        if (matrix[i] == NULL) {
            clear_matrix(matrix, i);
            return NULL;
        }
    }
    return matrix;
}

void get_validated_int(int *variable, int min_value, int max_value) {
    int good_input = 0;
    while (!good_input) {
        int result = scanf("%d", variable);
        good_input = (result == 1 && *variable >= min_value && *variable <= max_value);
        char divider;
        // clear buffer
        do {
            divider = getchar();
        } while (divider != ' ' && divider != '\n');
    }
}

int cmp(const int **x, const int **y) { return (*x)[0] - (*y)[0]; }

int restore_matrix(int **matrix, int n) {
    int m = n;
    int **rows, **cols;
    // count of non-zero elements in each row and each column
    // first element - count, second - index of row or column
    // example:
    // matrix is
    /*        1 0 1 0
     *        1 1 1 0
     *        1 1 1 1
     *        1 0 0 0
     */
    // then "rows" will be
    //        2 0
    //        3 1
    //        4 2
    //        1 3
    // if we'll sort them by first value, we'll get right order for rows
    //        4 2
    //        3 1
    //        2 0
    //        1 3
    // now we know that right order of rows is 2 1 0 3
    // we also can sort columns, and restore all matrix
    // memory allocation
    rows = allocate_matrix(n, 2);
    if (rows == NULL) {
        printf("Memory error");
        return 0;
    }
    cols = allocate_matrix(m, 2);
    if (cols == NULL) {
        clear_matrix(rows, n);
        printf("Memory error");
        return 0;
    }

    // count rows and cols
    int i, j;
    for (i = 0; i < n; i++) {
        rows[i][0] = 0;
        rows[i][1] = i;
        for (j = 0; j < m; j++) {
            rows[i][0] += (matrix[i][j] == 0);
        }
    }
    for (j = 0; j < m; j++) {
        cols[j][0] = 0;
        cols[j][1] = j;
        for (i = 0; i < n; i++) {
            cols[j][0] += (matrix[i][j] != 0);
        }
    }

    // sort them
    qsort(rows, n, sizeof(int *), cmp);
    qsort(cols, m, sizeof(int *), cmp);
    int **new_matrix = allocate_matrix(n, m);
    if (new_matrix == NULL) {
        clear_matrix(rows, n);
        clear_matrix(cols, m);
        printf("Memory error");
        return 0;
    }
    // now we have right positions, we just need to restore them
    // we'll use new matrix, and then copy values to initial
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            new_matrix[i][j] = matrix[rows[i][1]][cols[j][1]];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            matrix[i][j] = new_matrix[i][j];
        }
    }
    clear_matrix(rows, n);
    clear_matrix(cols, m);
    clear_matrix(new_matrix, n);
    return 1;
}

int main() {
    printf("Enter N between 1 and 1000: ");
    int n;
    get_validated_int(&n, 1, 1000);
    int i, j;
    int **matrix = allocate_matrix(n, n);
    if (matrix == NULL) {
        printf("ERROR: Unable to allocate memory.");
        return 1;
    }
    printf("Enter matrix %dx%d (incorrect symbols will be ignored): \n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            get_validated_int(&matrix[i][j], 0, 100000);
        }
    }
    int result = restore_matrix(matrix, n);
    if (!result) {
        printf("Error\n");
        return 1;
    }
    printf("Restored matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}