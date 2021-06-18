#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <limits.h>

void input()
{
	FILE* fp;
	int minyear, minmonth, minday;
	int maxyear, maxmonth, maxday;
	bool date_read = false;
	char filename[1024] = { '\0' };
	while (true)
	{
		system("cls");
		fflush(stdin);
		puts("Enter filename: ");
		scanf_s("%s", filename, 1023);
		if (!(fp = fopen(filename, "rt")))
		{
			puts("File doesn't exist or unable to open file, re-enter the full path");
			_getch();
			continue;
		}
		break;
	}
	wchar_t str[1026];
	while (!feof(fp))
	{
		fgetws(str, 1025, fp);
		for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++)
		{
			if (isdigit(str[i]) && isdigit(str[i + 1]) && str[i + 2] == 46 && isdigit(str[i + 3]) && isdigit(str[i + 4]) &&
			    str[i + 5] == 46 && isdigit(str[i + 6]) && isdigit(str[i + 7]) && isdigit(str[i + 8]) && isdigit(str[i + 9]))
			{
				int current_day = (str[i] - 48) * 10 + (str[i + 1] - 48);
				int current_month = (str[i + 3] - 48) * 10 + (str[i + 4] - 48);
				int current_year = (str[i + 6] - 48) * 1000 + (str[i + 7] - 48) * 100 + (str[i + 8] - 48) * 10 + (str[i + 9] - 48);
				bool is_leap = false;
				if ((current_year % 400 == 0) || (current_year % 4 == 0 && current_year % 100 != 0))
					is_leap = true;
				if ((current_month >= 1 && current_month <= 12) && current_day >= 0 && ((current_day <= 28 && !is_leap) || (current_day <= 31 &&
					current_month == 1) || (current_day <= 31 && current_month == 3) || (current_day <= 30 && current_month == 4) || 
					(current_day <= 31 && current_month == 5) || (current_day <= 30 && current_month == 6) || (current_day <= 31 && current_month == 7) || 
					(current_day <= 31 && current_month == 8) || (current_day <= 30 && current_month == 9) || (current_day <= 31 && current_month == 10) || 
					(current_day <= 30 && current_month == 11) || (current_day <= 31 && current_month == 12) || (current_day <= 29 && is_leap)))
				{
					if (!date_read)
					{
						minday = maxday = current_day;
							minmonth = maxmonth = current_month;
							minyear = maxyear = current_year;
							date_read = true;
					}
					else
					{
						if (current_year > maxyear || (current_year == maxyear && current_month > maxmonth) ||
						    (current_year == maxyear && current_month == maxmonth && current_day > maxday))
						{
							maxyear = current_year;
							maxmonth = current_month;
							maxday = current_day;
						}
						else if (current_year < minyear || (current_year == minyear && current_month < minmonth) ||
							(current_year == minyear && current_month == minmonth && current_day < minday))
						{
							minyear = current_year;
							minmonth = current_month;
							minday = current_day;
						}
					}
				}
				i += 9;
			}
		}
	}
	if (date_read)
	{
		printf("Min date -- %d.%d.%d\n", minday, minmonth, minyear);
		printf("Max date -- %d.%d.%d", maxday, maxmonth, maxyear);
	}
	else
		puts("Wrong date format in the text (DD.MM.YEAR) or no date at all");
	fclose(fp);
}

int main(void)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	input();
	_getch();
	return 0;
}
