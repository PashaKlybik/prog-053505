#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool check_square(int** matrix, int i, int *j, int square_side, int n) {
	for (int square_i = i; square_i < i + square_side; square_i++) {
		for (int square_j = *j; square_j < *j + square_side; square_j++) {
			if (matrix[square_i][square_j] != 0) {
				if (square_j + 1 < n) {
					*j = square_j;
				}
				return false;
			}
		}
	}
	return true;
}

void make_square(int** matrix_square, int i, int j, int square_side) {
	for (int square_i = i; square_i < i + square_side; square_i++) {
		for (int square_j = j; square_j < j + square_side; square_j++) {
			matrix_square[square_i][square_j] = 0;
		}
	}
}

int main() {

	int n = 10, m = 20;
	int square_side = 2;
	srand(time(NULL));

	printf("print n:");
	scanf_s("%d", &n);
	printf("print m:");
	scanf_s("%d", &m);
	printf("print square size:");
	scanf_s("%d", &square_side);
	printf("\n");

	int** matrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		matrix[i] = (int*)malloc(m * sizeof(int));
	}

	int** matrix_square = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		matrix_square[i] = (int*)malloc(m * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix[i][j] = rand() % 2;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix_square[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < n - square_side + 1; i++) {
		for (int j = 0; j < m - square_side + 1; j++) {
			if (check_square(matrix, i, &j, square_side, n)) {
				printf("x = %d, y = %d\n", j + 1, i + 1);
				make_square(matrix_square, i, j, square_side);
			}
		}
	}

	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", matrix_square[i][j]);
		}
		printf("\n");
	}



	for (int i = 0; i < n; i++) {
		free(matrix[i]);
	}
	free(matrix);

	for (int i = 0; i < n; i++) {
		free(matrix_square[i]);
	}
	free(matrix_square);

	_getch();
	return 0;
}