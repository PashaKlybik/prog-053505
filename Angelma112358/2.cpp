#include<stdio.h>
#include <locale.h> 
#include <math.h>

void AllEdgeLength(int lengthEdge) {
		int allLength = lengthEdge * 6;
		printf("����� ����� ���� �����:%d\n", allLength);
	}
void Square(int lengthEdge) {
		double square = pow(3, 0.5) * lengthEdge * lengthEdge;
		printf("������� ������ ����������� ���������: %f\n", square);
	}
void Volume(int lengthEdge) {
		double volume = lengthEdge * lengthEdge / (6 * pow(2, 0.5));
		printf("����� ���������: %f\n", volume);
	}
void Height(int lengthEdge) {
		double height = lengthEdge * pow(2, 0.5) / pow(3, 0.5);
		printf("������ ���������:%f\n", height);
	}
void InscribedSphereRadius(int lengthEdge) {
		double radius = lengthEdge * pow(6, 0.5) / 12;
		printf("������ ����, ���������� � ��������:%f\n", radius);
	}

int main() {
	setlocale(LC_ALL, ".1251");
	int lengthEdge;
	printf("������� ����� �����: ");
	while (1) {
		if (!scanf("%d", &lengthEdge) || getchar() != '\n')
			while (getchar() != '\n');
		else 
			break;
		printf("����� ����� ������� �����������. ��������� ����: ");
	}
	int number;
	while (1) {
		printf("\n\n1. ���� ����� ����� ���������\n");
		printf("2. ����� ����� ����� ����� ���������\n");
		printf("3. ����� ������� ���� ������ ���������\n");
		printf("4. ����� ������ ���������\n");
		printf("5. ����� ������ ���������\n");
		printf("6. ����� ������� ���������� ����\n");
		printf("7. ���������� � ������ � ������ ���������\n");
		printf("8. ����� �� ���������\n");
		printf("������� ����� ��������: \n");
		while (1) {
			if (!scanf("%d", &number) || getchar() != '\n')
				while (getchar() != '\n');
			else
				break;
			printf("��������� ����: ");
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
				printf("����� ����� ������� �����������. ��������� ����: ");
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
			printf("����� ����");
			break;
		case 8:
			return 0;
		default:
			printf("������ ����������������� ������");
			break;
		}
	}
}