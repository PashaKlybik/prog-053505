#include <stdio.h>
#include <locale.h>

void Add(int *width, int *depth, int *speed, int num) {
	printf("Введите данные %d точки: \n", num+1 );
	printf("Введите ширину %d точки: ", num + 1);
	while (1) {
		if (!scanf("%d", &width[num]) || width[num] <= 0 || getchar() != '\n')
			while (getchar() != '\n');
		else
			break;
		printf("Ввод некорректен. Повторите ввод: ");
	}
	printf("Введите глубину %d точки: ", num + 1);
	while (1) {
		if (!scanf("%d", &depth[num]) || depth[num] <= 0 || getchar() != '\n')
			while (getchar() != '\n');
		else
			break;
		printf("Ввод некорректен. Повторите ввод: ");
	}
	printf("Введите скорость в %d точке: ", num + 1);
	while (1) {
		if (!scanf("%d", &speed[num]) || speed[num] <= 0 || getchar() != '\n')
			while (getchar() != '\n');
		else
			break;
		printf("Ввод некорректен. Повторите ввод: ");
	}
	system("cls");
}
void Print(int* width, int* depth, int* speed, int num) {
	printf("Ширина в %d точке: %d\n", num + 1, width[num]);
	printf("Глубина в %d точке: %d\n", num + 1, depth[num]);
	printf("Скорость в %d точке: %d\n", num + 1, speed[num]);
	printf("\n");
}
int Measurement(int* width, int* depth, int* speed, int point) {
	return width[point - 1] * depth[point-1] * speed[point-1];
}
int main() {
	setlocale(LC_ALL, ".1251");
	int num, point;
	printf("Введите количество замеров: ");
	while (1) {
		if (!scanf("%d", &num) || num <= 0 || getchar() != '\n' )
			while (getchar() != '\n');
		else
			break;
		printf("Ввод некорректен. Повторите ввод: ");
	}
	int* width = (int*)malloc(sizeof(int) * num);
	int* depth = (int*)malloc(sizeof(int) * num);
	int* speed = (int*)malloc(sizeof(int) * num);
	for(int i = 0; i < num; i++)
		Add(width, depth, speed, i);
	for (int i = 0; i < num; i++)
		Print(width, depth, speed, i);
	printf("Введите точку, в которой нужно узнать расход воды: ");
	while (1) {
		if (!scanf("%d", &point) || point <= 0 || point > num || getchar() != '\n')
			while (getchar() != '\n');
		else
			break;
		printf("Ввод некорректен. Повторите ввод: ");
	}
	printf("%d", Measurement(width, depth, speed, point));
}