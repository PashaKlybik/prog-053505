#include <stdio.h>
#include <locale.h>

void Add(int *width, int *depth, int *speed, int num) {
	printf("Ââåäèòå äàííûå %d òî÷êè: \n", num+1 );
	printf("Ââåäèòå øèðèíó %d òî÷êè: ", num + 1);
	while (1) {
		if (!scanf("%d", &width[num]) || width[num] <= 0 || getchar() != '\n')
			while (getchar() != '\n');
		else
			break;
		printf("Ââîä íåêîððåêòåí. Ïîâòîðèòå ââîä: ");
	}
	printf("Ââåäèòå ãëóáèíó %d òî÷êè: ", num + 1);
	while (1) {
		if (!scanf("%d", &depth[num]) || depth[num] <= 0 || getchar() != '\n')
			while (getchar() != '\n');
		else
			break;
		printf("Ââîä íåêîððåêòåí. Ïîâòîðèòå ââîä: ");
	}
	printf("Ââåäèòå ñêîðîñòü â %d òî÷êå: ", num + 1);
	while (1) {
		if (!scanf("%d", &speed[num]) || speed[num] <= 0 || getchar() != '\n')
			while (getchar() != '\n');
		else
			break;
		printf("Ââîä íåêîððåêòåí. Ïîâòîðèòå ââîä: ");
	}
	system("cls");
}
void Print(int* width, int* depth, int* speed, int num) {
	printf("Øèðèíà â %d òî÷êå: %d\n", num + 1, width[num]);
	printf("Ãëóáèíà â %d òî÷êå: %d\n", num + 1, depth[num]);
	printf("Ñêîðîñòü â %d òî÷êå: %d\n", num + 1, speed[num]);
	printf("\n");
}
int Measurement(int* width, int* depth, int* speed, int point) {
	return width[point - 1] * depth[point-1] * speed[point-1];
}
int main() {
	setlocale(LC_ALL, ".1251");
	int num, point;
	printf("Ââåäèòå êîëè÷åñòâî çàìåðîâ: ");
	while (1) {
		if (!scanf("%d", &num) || num <= 0 || getchar() != '\n' )
			while (getchar() != '\n');
		else
			break;
		printf("Ââîä íåêîððåêòåí. Ïîâòîðèòå ââîä: ");
	}
	int* width = (int*)malloc(sizeof(int) * num);
	int* depth = (int*)malloc(sizeof(int) * num);
	int* speed = (int*)malloc(sizeof(int) * num);
	for(int i = 0; i < num; i++)
		Add(width, depth, speed, i);
	for (int i = 0; i < num; i++)
		Print(width, depth, speed, i);
	printf("Ââåäèòå òî÷êó, â êîòîðîé íóæíî óçíàòü ðàñõîä âîäû: ");
	while (1) {
		if (!scanf("%d", &point) || point <= 0 || point > num || getchar() != '\n')
			while (getchar() != '\n');
		else
			break;
		printf("Ââîä íåêîððåêòåí. Ïîâòîðèòå ââîä: ");
	}
	printf("%d", Measurement(width, depth, speed, point));
}

