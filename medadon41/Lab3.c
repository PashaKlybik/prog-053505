#include <stdio.h>
#include <locale.h>

void fillArr(int **arr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 1;
			if (i == m - 1 && j == 0) {
				arr[i][j] = 2;
			}
		}
	}
}

void showArr(int** arr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}

void main() {

	setlocale(LC_ALL, "Rus");
	int m, n;

	printf("Введите размер пирога (m и n): ");
	while (scanf_s("%d %d", &m, &n) != 2) {
		puts("Некорректная размер. Повторите попытку: ");
		scanf_s("%*[^\n]");
	}

	int** pie = (int**)malloc(m * sizeof(int*));

	for (int i = 0; i < m; i++) {
		pie[i] = (int*)malloc(n * sizeof(int));
	}

	fillArr(pie, m, n);

	showArr(pie, m, n);

	int cont = 1;

	while (cont == 1) {
		int px = 0, py = 0;

		printf("Выберите клетку (x и y): ");
		while (scanf_s("%d %d", &px, &py) != 2 || px > n || py > m) {
			puts("Некорректная координаты. Повторите попытку: ");
			scanf_s("%*[^\n]");
		}

		pie[--py][--px] = 0;

		for (int i = py; i >= 0; i--) {
			for (int j = px; j < n; j++) {
				pie[i][j] = 0;
			}
		}

		showArr(pie, m, n);

		if (pie[m - 1][0] == 0) {
			printf("Вы проиграли!");
			cont = 0;
		}
	}

	for (int i = 0; i < n; i++)
		free(pie[i]);
	free(pie);
}