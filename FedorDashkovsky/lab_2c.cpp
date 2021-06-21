#include <stdio.h>
#include <math.h>
#include <locale.h>


float area = 0;
int quant = 0;

void ShowMenu()
{
	printf("1. ���� ����� � ������ �������(�)\n");
	printf("2. ���� ���������� ����\n");
	printf("3. ���� ���������� ������� �������\n");
	printf("4. ���� ��������� ������� ������($)\n");
	printf("5. ������ ������� �������(��.�)\n");
	printf("6. ������ ������������ ���������� ������� ������ \n");
	printf("7. ������ ��������� ��������(� ������ ����)\n");
	printf("8. ����� �� ���������\n");
}

void Area(float len, float d, int win, int door)       //������� ������� ������� � ������� �� �������� �� �����
{
	area = (5.2 * (len + d)) - (3.225 * win) - (1.845 * door);
	printf("������� �������: %.2f �^2", area);
}

void Pipes()         //����������� ����������� ���������� ������� ������ � ������� �� �����
{
	quant = area / 5;
	float kolvo1 = area / 5;
	if ((kolvo1 - quant) != 0) quant++;
	printf("����������� ���������� ������: %d ", quant);
}

void Cost(float cost)          //����������� ��������� �������� � ������ ���� � ������� �������� �� �����
{
	float gencost;
	gencost = (area / 5 * cost) + (area / 10);
	printf("��������� �������� (� ������ ����): %.2f$", gencost);
}



int main(void)
{
	setlocale(LC_ALL, "Rus");
	float dl = 0, sh = 0, cost = 0;
	int win = -1, door = 0;
	int operation, a = 1;
	ShowMenu();
	do
	{
		do
		{
			printf("\n");
			rewind(stdin);
		} while (!(scanf_s("%d", &operation)));
		switch (operation)
		{
		case 1:
			{
				do { printf("�����(�): "); rewind(stdin); } while (!(scanf_s("%f", &dl)) || dl <= 0); do { printf("������(�): "); rewind(stdin); } while (!(scanf_s("%f", &sh)) || sh <= 0);
			} break;
		case 2:
			{
				do { printf("���������� ����: "); rewind(stdin); } while (!(scanf_s("%d", &win)) || win <= -1);
			} break;
		case 3:
			{
				do { printf("���������� ������� �������: "); rewind(stdin); } while (!(scanf_s("%d", &door)) || door <= 0);
			} break;
		case 4:
			{
				do { printf("��������� ������� ������($): "); rewind(stdin); } while (!(scanf_s("%f", &cost)) || cost <= 0);
			} break;
		case 5:
			{
				if (dl == 0 || sh == 0 || win == -1 || door == 0) { printf("������� ��� ����������� ������!"); break; }Area(dl, sh, win, door);
			} break;
		case 6:
			{
				if (area == 0) { printf("��������/��������� ��� ����������� ������! "); break; }Pipes();
			} break;
		case 7:
			{
				if (quant == 0 || cost == 0) { printf("��������/��������� ��� ����������� ������!"); break; } Cost(cost);
			} break;
		case 8: a = 0; break;
		default: printf("������� ����� �� 1 �� 8\n");
		}
	} while (a);
	return 0;
}
