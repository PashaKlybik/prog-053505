#include <stdio.h>
#include <locale.h>

int countDuration(int d_from, int m_from, int y_from, int d_to, int m_to, int y_to) {
	int	totaldur = (d_to + m_to * 30  + y_to * 356) - (d_from + m_from * 30 + y_from * 356);
	printf("Длительность проекта (календарные дни): %d \n", totaldur);
	int workdur;
	if (totaldur >= 7) {
		workdur = totaldur * 0.7;
	}
	else {
		workdur = totaldur;
	}
	printf("Длительность проекта (рабочие дни): %d \n", workdur);
	return workdur;
}

double countHdays(int workdur, int devs) {
	double result = ((8 * workdur) * devs) / 8;
	printf("Количество человеко-дней: %f \n", result);
	return result;
}

int countHhours(int workdur, int devs) {
	int result = devs * 8 * workdur;
	printf("Количество человеко-часов: %d \n", result);
	return result;
}

double countFinParams(int Hhours, int devs, int workdur) {
	int totalCost = Hhours * 9;
	printf("Стоимость проекта: %d \n", totalCost);

	double salaries = ((400 / 30) * workdur) * devs;
	printf("Зарплаты разработчикам: %f \n", salaries);

	double overheads = salaries * 2.5;
	printf("Накладные расходы: %f \n", overheads);

	double profit = totalCost - (salaries + overheads);
	printf("Прибыль компании: %f \n", profit);

	return profit;
}

void makeDes(double profit) {
	if (profit > 1000) {
		printf("Рекоммендуется принять данный проект, т.к прибыль равна %f", profit);
	}
	else {
		printf("Не рекоммендуется принимать данный проект, т.к прибыль равна %f", profit);
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
			puts("Выберите действие:");
			puts("0. Ввод даты начала и даты окончания проекта.");
			puts("1. Ввод количества разработчиков");
			puts("2. Вывод длительности проекта.");
			puts("3. Расчет трудоемкости проекта.");
			puts("4. Расчет финансовых параметров.");
			puts("5. Принятие решения о целесообразности принятия проекта.");
			puts("6. Информация о версии и авторе программы.");
			puts("7. Выход.");
			int pick;
			while (scanf_s("%d", &pick) != 1 || pick > 7) {
				puts("Некорректный ввод. Повторите попытку: ");
				scanf_s("%*[^\n]");
			}
			if (pick == 0) {
				printf("Ввведите дату начала проекта (в формате дд/мм/гггг): ");
				while(scanf_s("%d%*1[.]%d%*1[.]%d", &d_from, &m_from, &y_from) != 3 || d_from <= 0 || d_from > 31 || m_from <= 0 || m_from > 12) {
					puts("Некорректная дата. Повторите попытку: ");
					scanf_s("%*[^\n]");
				}

				printf("Ввведите дату окончания проекта (в формате дд/мм/гггг): ");
				while (scanf_s("%d%*1[.]%d%*1[.]%d", &d_to, &m_to, &y_to) != 3 || d_to <= 0 || d_to > 31 || m_to <= 0 || m_to > 12) {
					puts("Некорректная дата. Повторите попытку: ");
					scanf_s("%*[^\n]");
				}
			}

			if (pick == 1) {

				printf("Ввведите количество разработчиков: ");
				scanf_s("%d", &devs);
			}

			if (pick == 2) {

				if (d_from == 0 || devs == 0) {

					system("cls");
					puts("Для начала нужно заполнить информацию о проекте");
					puts("Нажмите любую клавишу, чтобы продолжить...");
					getch();
				}
				else {

					worktime = countDuration(d_from, m_from, y_from, d_to, m_to, y_to);

				}
			}

			if (pick == 3) {
				if (d_from == 0 || devs == 0) {

					system("cls");
					puts("Для начала нужно заполнить информацию о проекте");
					puts("Нажмите любую клавишу, чтобы продолжить...");
					getch();
				}
				else {

					countHdays(worktime, devs);

					humanHours = countHhours(worktime, devs);

					puts("Нажмите любую клавишу, чтобы продолжить...");
					getch();
				}
			}

			if (pick == 4) {

				if (d_from == 0 || devs == 0) {

					system("cls");
					puts("Для начала нужно заполнить информацию о проекте");
					puts("Нажмите любую клавишу, чтобы продолжить...");
					getch();
				}
				else {

					profit = countFinParams(humanHours, devs, worktime);
					puts("Нажмите любую клавишу, чтобы продолжить...");
					getch();
				}

			}

			if (pick == 5) {

				if (d_from == 0 || devs == 0) {

					system("cls");
					puts("Для начала нужно заполнить информацию о проекте");
					puts("Нажмите любую клавишу, чтобы продолжить...");
					getch();
				}
				else {

					makeDes(profit);
					puts("Нажмите любую клавишу, чтобы продолжить...");
					getch();
				}
			}

			if (pick == 6) {

				system("cls");
				puts("Project Manager v1.0 by mddn41\n04.2021 (c) all rights may be reserved");
				puts("Нажмите любую клавишу, чтобы вернуться назад.");
				getch();
			}

			if (pick == 7) {

				exit(0);

			}
		}
}