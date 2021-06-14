#include<stdio.h>
#include <locale.h> 
#include <math.h>

void AllEdgeLength(int lengthEdge) {
		int allLength = lengthEdge * 6;
		printf("Общая длина всех ребер:%d\n", allLength);
	}
void Square(int lengthEdge) {
		double square = pow(3, 0.5) * lengthEdge * lengthEdge;
		printf("Площадь полной поверхности тетраэдра: %f\n", square);
	}
void Volume(int lengthEdge) {
		double volume = lengthEdge * lengthEdge / (6 * pow(2, 0.5));
		printf("Объем тетраэдра: %f\n", volume);
	}
void Height(int lengthEdge) {
		double height = lengthEdge * pow(2, 0.5) / pow(3, 0.5);
		printf("Высота тетраэдра:%f\n", height);
	}
void InscribedSphereRadius(int lengthEdge) {
		double radius = lengthEdge * pow(6, 0.5) / 12;
		printf("Радиус шара, вписанного в тетраэдр:%f\n", radius);
	}

int main() {
	setlocale(LC_ALL, ".1251");
	int lengthEdge;
	printf("Введите длину ребра: ");
	while (1) {
		if (!scanf("%d", &lengthEdge) || getchar() != '\n')
			while (getchar() != '\n');
		else 
			break;
		printf("Длина ребра введена некорректно. Повторите ввод: ");
	}
	int number;
	while (1) {
		printf("\n\n1. Ввод длины ребра тетраэдра\n");
		printf("2. Вывод общей длины ребер тетраэдра\n");
		printf("3. Вывод площади всех граней тетраэдра\n");
		printf("4. Вывод объема тетраэдра\n");
		printf("5. Вывод высоты тетраэдра\n");
		printf("6. Вывод радиуса вписанного шара\n");
		printf("7. Информация о версии и авторе программы\n");
		printf("8. Выход из программы\n");
		printf("Введите номер операции: \n");
		while (1) {
			if (!scanf("%d", &number) || getchar() != '\n')
				while (getchar() != '\n');
			else
				break;
			printf("Повторите ввод: ");
		}
		system("cls");
		switch (number)
		{
		case 1:
			while (1) {
				if (!scanf("%d", &lengthEdge) || getchar() != '\n')
					while (getchar() != '\n');
				else
					break;
				printf("Длина ребра введена некорректно. Повторите ввод: ");
			}
			break;
		case 2:
			AllEdgeLength(lengthEdge);
			break;
		case 3:
			Square(lengthEdge);
			break;
		case 4:
			Volume(lengthEdge);
			break;
		case 5:
			Height(lengthEdge);
			break;
		case 6:
			InscribedSphereRadius(lengthEdge);
			break;
		case 7:
			printf("автор норм");
			break;
		case 8:
			return 0;
		default:
			printf("Введен несоответствующий символ");
			break;
		}
	}
}