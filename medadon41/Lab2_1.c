#include <stdio.h>
#include <locale.h>

int countDuration(int d_from, int m_from, int y_from, int d_to, int m_to, int y_to) {
	int	totaldur = (d_to + m_to * 30  + y_to * 356) - (d_from + m_from * 30 + y_from * 356);
	printf("������������ ������� (����������� ���): %d \n", totaldur);
	int workdur;
	if (totaldur >= 7) {
		workdur = totaldur * 0.7;
	}
	else {
		workdur = totaldur;
	}
	printf("������������ ������� (������� ���): %d \n", workdur);
	return workdur;
}

double countHdays(int workdur, int devs) {
	double result = ((8 * workdur) * devs) / 8;
	printf("���������� ��������-����: %f \n", result);
	return result;
}

int countHhours(int workdur, int devs) {
	int result = devs * 8 * workdur;
	printf("���������� ��������-�����: %d \n", result);
	return result;
}

double countFinParams(int Hhours, int devs, int workdur) {
	int totalCost = Hhours * 9;
	printf("��������� �������: %d \n", totalCost);

	double salaries = ((400 / 30) * workdur) * devs;
	printf("�������� �������������: %f \n", salaries);

	double overheads = salaries * 2.5;
	printf("��������� �������: %f \n", overheads);

	double profit = totalCost - (salaries + overheads);
	printf("������� ��������: %f \n", profit);

	return profit;
}

void makeDes(double profit) {
	if (profit > 1000) {
		printf("�������������� ������� ������ ������, �.� ������� ����� %f", profit);
	}
	else {
		printf("�� �������������� ��������� ������ ������, �.� ������� ����� %f", profit);
	}
}

void main() {

		setlocale(LC_ALL, "Rus");

		int isEnd = 1;

		int d_from = 0, m_from = 0, y_from = 0;
		int d_to = 0, m_to = 0, y_to = 0;
		int devs = 0;
		int worktime = 0;
		int humanHours = 0;
		double profit = 0;

		while (isEnd == 1) {
			system("cls");
			puts("�������� ��������:");
			puts("0. ���� ���� ������ � ���� ��������� �������.");
			puts("1. ���� ���������� �������������");
			puts("2. ����� ������������ �������.");
			puts("3. ������ ������������ �������.");
			puts("4. ������ ���������� ����������.");
			puts("5. �������� ������� � ���������������� �������� �������.");
			puts("6. ���������� � ������ � ������ ���������.");
			puts("7. �����.");
			int pick;
			while (scanf_s("%d", &pick) != 1 || pick > 7) {
				puts("������������ ����. ��������� �������: ");
				scanf_s("%*[^\n]");
			}
			if (pick == 0) {
				printf("�������� ���� ������ ������� (� ������� ��/��/����): ");
				while(scanf_s("%d%*1[.]%d%*1[.]%d", &d_from, &m_from, &y_from) != 3 || d_from <= 0 || d_from > 31 || m_from <= 0 || m_from > 12) {
					puts("������������ ����. ��������� �������: ");
					scanf_s("%*[^\n]");
				}

				printf("�������� ���� ��������� ������� (� ������� ��/��/����): ");
				while (scanf_s("%d%*1[.]%d%*1[.]%d", &d_to, &m_to, &y_to) != 3 || d_to <= 0 || d_to > 31 || m_to <= 0 || m_to > 12) {
					puts("������������ ����. ��������� �������: ");
					scanf_s("%*[^\n]");
				}
			}

			if (pick == 1) {

				printf("�������� ���������� �������������: ");
				scanf_s("%d", &devs);
			}

			if (pick == 2) {

				if (d_from == 0 || devs == 0) {

					system("cls");
					puts("��� ������ ����� ��������� ���������� � �������");
					puts("������� ����� �������, ����� ����������...");
					getch();
				}
				else {

					worktime = countDuration(d_from, m_from, y_from, d_to, m_to, y_to);

				}
			}

			if (pick == 3) {
				if (d_from == 0 || devs == 0) {

					system("cls");
					puts("��� ������ ����� ��������� ���������� � �������");
					puts("������� ����� �������, ����� ����������...");
					getch();
				}
				else {

					countHdays(worktime, devs);

					humanHours = countHhours(worktime, devs);

					puts("������� ����� �������, ����� ����������...");
					getch();
				}
			}

			if (pick == 4) {

				if (d_from == 0 || devs == 0) {

					system("cls");
					puts("��� ������ ����� ��������� ���������� � �������");
					puts("������� ����� �������, ����� ����������...");
					getch();
				}
				else {

					profit = countFinParams(humanHours, devs, worktime);
					puts("������� ����� �������, ����� ����������...");
					getch();
				}

			}

			if (pick == 5) {

				if (d_from == 0 || devs == 0) {

					system("cls");
					puts("��� ������ ����� ��������� ���������� � �������");
					puts("������� ����� �������, ����� ����������...");
					getch();
				}
				else {

					makeDes(profit);
					puts("������� ����� �������, ����� ����������...");
					getch();
				}
			}

			if (pick == 6) {

				system("cls");
				puts("Project Manager v1.0 by mddn41\n04.2021 (c) all rights may be reserved");
				puts("������� ����� �������, ����� ��������� �����.");
				getch();
			}

			if (pick == 7) {

				exit(0);

			}
		}
}