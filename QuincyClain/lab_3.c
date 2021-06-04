#include<stdio.h>
#include<Windows.h>
#include <conio.h>
int main() {
	int n, m, r, i, z;
	printf("Vvedite razmer: ");
	scanf("%d", &n);
	scanf("%d", &m);
	int** mas;
	mas = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		mas[i] = (int*)calloc(m, sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("mas[%d][%d] = ", i, j);
			scanf("%d", &mas[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", mas[i][j]);
		}
		printf("\n");
	}
	int a = 0;
	for (int x = 0; a < m; a++) {
		for (int i = x, j = a; i < n && j < m; i++, j++) {
			for (int k = j + 1, z = i + 1; z < n && k < m; k++, z++) {              
				if (mas[i][j] > mas[z][k]) 
				{
					r = mas[z][k];
					mas[z][k] = mas[i][j];
					mas[i][j] = r;
				}
			}

		}
	}
	a = 0;
	for (int x = 0; x < n; x++) {
		for (int i = x + 1, j = a; i < n && j < m; i++, j++) {
			for (int k = j + 1, z = i + 1; z < n && k < m; k++, z++) {             
				if (mas[i][j] > mas[z][k])
				{
					r = mas[z][k];
					mas[z][k] = mas[i][j];
					mas[i][j] = r;
				}
			}

		}
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", mas[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++)
		free(mas[i]);
	free(mas);
	getch();
	return 0;
}
