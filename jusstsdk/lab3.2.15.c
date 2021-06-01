#include <stdio.h>

const int L = 3;
const int M = 3;
const int N = 3;

int*** create_3D(int X_size, int Y_size, int Z_size) {

    int*** ptr = (int***)malloc(X_size * sizeof(int**));
    int i, j;

    for (i = 0; i < X_size; i++) {
        ptr[i] = (int**)malloc(Y_size * sizeof(int*));
        for (j = 0; j < Y_size; j++) {
            ptr[i][j] = (int*)malloc(Z_size * sizeof(int));
        }
    }

    return ptr;
}

int** create_2D(int x, int y) {

    int** array_2D = (int**)malloc(x * sizeof(int*));

    for (int i = 0; i < x; i++) {
        array_2D[i] = (int*)malloc(y * sizeof(int));
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            array_2D[i][j] = 0;
        }
    }

    return array_2D;
}

void show_2D(int** arr, int x, int y) {

    int i, j;
    for (i = 0; i < x; i++) {

        for (j = 0; j < y; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void delete_2D(int** arr, int x) {

    int i;
    for (i = 0; i < x; i++) {
        free(arr[i]);
    }

    free(arr);
}

void delete_3D(int*** arr, int x, int y) {

    int i, j;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++)
            free(arr[i][j]);
        free(arr[i]);
    }

    free(arr);
}

int main() {

    int*** XYZ = NULL;

    XYZ = create_3D(L, M, N);

    int** XY = create_2D(L, M);
    int** XZ = create_2D(L, N);
    int** YZ = create_2D(M, N);

    XYZ[0][0][0] = 1;
    XYZ[1][1][0] = 1;
    XYZ[0][2][1] = 1;
    XYZ[2][1][0] = 1;

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {

                if (XYZ[i][j][k] == 1) {

                    if (XY[i][j] == 0) XY[i][j] = 1;
                    if (XZ[i][k] == 0) XZ[i][k] = 1;
                    if (YZ[j][k] == 0) YZ[j][k] = 1;
                }

            }
        }
    }

    printf("XY projection\n");
    show_2D(XY, L, M);

    printf("\n\nXZ projection\n");
    show_2D(XZ, L, N);

    printf("\n\nYZ projection\n");
    show_2D(YZ, M, N);

    delete_2D(XY, L);
    delete_2D(XZ, L);
    delete_2D(YZ, M);
    delete_3D(XYZ, L, M);

    return 0;
}
