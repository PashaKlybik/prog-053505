#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "List.h"
#include "Container.h"

#define LIGHTRED 12
#define YELLOW 14
#define WHITE 15 
#define GREEN 2
#define RED 4
#define LIGHTGRAY 7
#define DARKGRAY 8
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ENTER 13

void showConsoleCursor(int showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void setXY(int x, int y)
{
	COORD cursorPosition;
	cursorPosition.X = x;
	cursorPosition.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void setToZero()
{
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void textColor(int color)
{
	static int __BACKGROUND;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (__BACKGROUND << 4));
}

void arrowPosition(int menuPosition, int arrowPos)
{
	if (arrowPos == menuPosition)
	{
		textColor(RED);
		printf_s("> ");
		textColor(WHITE);
	}
	else
	{
		textColor(DARKGRAY);
		printf_s("  ");
	}
}

int menu()
{
	int firstPosition = 1;
	int lastPosition = 10;
	int arrowPos = 1;
	int key = 0;
	while (key != ENTER)
	{
		showConsoleCursor(0);
		setToZero();
		textColor(WHITE); printf_s("menu:\n\n");
		arrowPosition(1, arrowPos); printf_s("1. Show employees\n");
		arrowPosition(2, arrowPos); printf_s("2. Search\n");
		arrowPosition(3, arrowPos); printf_s("3. Fire an employee\n");
		arrowPosition(4, arrowPos); printf_s("4. Hire an employee\n");
		arrowPosition(5, arrowPos); printf_s("5. Employees vacation\n");
		arrowPosition(6, arrowPos); printf_s("6. Employees birthday\n");
		arrowPosition(7, arrowPos); printf_s("7. Employees who are currently at work\n");
		arrowPosition(8, arrowPos); printf_s("8. Employees who are currently on vacation\n");
		arrowPosition(9, arrowPos); printf_s("9. Staff reduction\n");
		printf_s("\n");
		arrowPosition(10, arrowPos); printf_s("0. Exit\n");

		key = _getch();
		if (key == ARROW_UP)
		{
			arrowPos == firstPosition ? arrowPos = lastPosition : arrowPos--;
		}
		else if (key == ARROW_DOWN)
		{
			arrowPos == lastPosition ? arrowPos = firstPosition : arrowPos++;
		}
	}
	return arrowPos;
}

void PrintList(int* employeesNumber, int* arrowPos, Node* node)
{
	while (node != NULL)
	{
		arrowPosition((*employeesNumber), (*arrowPos)); printf_s("%d. %d\t %s %s\n", (*employeesNumber), node->employee.passport.passportNumber,
			node->employee.firstName, node->employee.lastName);
		(*employeesNumber)++;
		node = node->pNext;
	}
	printf_s("\n");
}

void MaskFunc(int moveToX, int moveToY, int pos, int arrowPos, const char* str)
{
	const char* mask = "                                                                                                          ";
	setXY(moveToX, moveToY);
	printf_s("%s", mask);
	setXY(moveToX, moveToY);
	arrowPosition(pos, arrowPos);
	printf_s("%s", str);
}

void OffSetCursor(int moveToX, int moveToY)
{
	setXY(moveToX, moveToY);
	showConsoleCursor(1);
}

void showEmployeeMenu(Node* node, const char* headline1, int edit)
{
	int xOffSet = 24;
	const int twoDigitNum = 10;
	int firstPosition = 1;
	int lastPosition = 16;
	int arrowPos = 1;
	int key = 0;
	int isFilled = 0;
	while (arrowPos != lastPosition)
	{
		system("cls");
		while (key != ENTER)
		{
			showConsoleCursor(0);
			setToZero();
			textColor(WHITE); printf_s(headline1);
			textColor(RED); printf_s("  Main:\n");
			arrowPosition(1, arrowPos); printf_s("First name:\t\t%s\n", node->employee.firstName);
			arrowPosition(2, arrowPos); printf_s("Last name:\t\t%s\n", node->employee.lastName);
			arrowPosition(3, arrowPos); printf_s("Date of birth:\t");
			node->employee.dateOfBirth.day < twoDigitNum ? printf_s("%d%d.", 0, node->employee.dateOfBirth.day) : printf_s("%d.", node->employee.dateOfBirth.day);
			node->employee.dateOfBirth.month < twoDigitNum ? printf_s("%d%d.", 0, node->employee.dateOfBirth.month) : printf_s("%d.", node->employee.dateOfBirth.month);
			printf_s("%d\n", node->employee.dateOfBirth.year);

			textColor(RED); printf_s("  Passport:\n");
			arrowPosition(4, arrowPos); printf_s("Number:\t\t%d\n", node->employee.passport.passportNumber);
			arrowPosition(5, arrowPos); printf_s("Date of issue:\t");
			node->employee.passport.issueDay < twoDigitNum ? printf_s("%d%d.", 0, node->employee.passport.issueDay) : printf_s("%d.", node->employee.passport.issueDay);
			node->employee.passport.issueMonth < twoDigitNum ? printf_s("%d%d.", 0, node->employee.passport.issueMonth) : printf_s("%d.", node->employee.passport.issueMonth);
			printf_s("%d\n", node->employee.passport.issueYear);
			arrowPosition(6, arrowPos); printf_s("Date of expiry:\t");
			node->employee.passport.expiryDay < twoDigitNum ? printf_s("%d%d.", 0, node->employee.passport.expiryDay) : printf_s("%d.", node->employee.passport.expiryDay);
			node->employee.passport.expiryMonth < twoDigitNum ? printf_s("%d%d.", 0, node->employee.passport.expiryMonth) : printf_s("%d.", node->employee.passport.expiryMonth);
			printf_s("%d\n", node->employee.passport.expiryYear);
			arrowPosition(7, arrowPos); printf_s("Nationality:\t\t%s\n", node->employee.passport.nationality);

			textColor(RED); printf_s("  Social security card:\n");
			arrowPosition(8, arrowPos); printf_s("Number:\t\t%d\n", node->employee.socialSecurityCard.cardNumber);

			textColor(RED); printf_s("  Education:\n");
			arrowPosition(9, arrowPos); printf_s("Degree:\t\t%s\n", node->employee.education.degree);

			textColor(RED); printf_s("  Work:\n");
			arrowPosition(10, arrowPos); printf_s("Position:\t\t%s\n", node->employee.position);
			arrowPosition(11, arrowPos); printf_s("Salary:\t\t%d$\n", node->employee.salary);
			arrowPosition(12, arrowPos); printf_s("Enrollment date:\t");
			node->employee.enrollmentDate.day < twoDigitNum ? printf_s("%d%d.", 0, node->employee.enrollmentDate.day) : printf_s("%d.", node->employee.enrollmentDate.day);
			node->employee.enrollmentDate.month < twoDigitNum ? printf_s("%d%d.", 0, node->employee.enrollmentDate.month) : printf_s("%d.", node->employee.enrollmentDate.month);
			printf_s("%d\n", node->employee.enrollmentDate.year);
			arrowPosition(13, arrowPos); printf_s("Encouragements:\t%s\n", node->employee.notes.encouragement);
			arrowPosition(14, arrowPos); printf_s("Penalties:\t\t%s\n", node->employee.notes.penalties);
			arrowPosition(15, arrowPos); printf_s("Status:\t\t%s\n", node->employee.status);

			printf_s("\n");

			arrowPosition(16, arrowPos); printf_s("0. Exit\n");

			key = _getch();
			if (key == ARROW_UP)
			{
				arrowPos == firstPosition ? arrowPos = lastPosition : arrowPos--;
			}
			else if (key == ARROW_DOWN)
			{
				arrowPos == lastPosition ? arrowPos = firstPosition : arrowPos++;
			}
		}
		key = 0;
		if (edit)
		{
			switch (arrowPos)
			{
			case 1: MaskFunc(0, 3, 1, arrowPos, "First name:"); OffSetCursor(xOffSet, 3); break;
			case 2: MaskFunc(0, 4, 2, arrowPos, "Last name:"); OffSetCursor(xOffSet, 4);  break;
			case 3: MaskFunc(0, 5, 3, arrowPos, "Date of birth:"); OffSetCursor(xOffSet, 5); break;
			case 4: MaskFunc(0, 7, 4, arrowPos, "Number:"); OffSetCursor(xOffSet, 7); break;
			case 5: MaskFunc(0, 8, 5, arrowPos, "Date of issue:"); OffSetCursor(xOffSet, 8); break;
			case 6: MaskFunc(0, 9, 6, arrowPos, "Date of expiry:"); OffSetCursor(xOffSet, 9); break;
			case 7: MaskFunc(0, 10, 7, arrowPos, "Nationality:"); OffSetCursor(xOffSet, 10); break;
			case 8: MaskFunc(0, 12, 8, arrowPos, "Number:"); OffSetCursor(xOffSet, 12); break;
			case 9: MaskFunc(0, 14, 9, arrowPos, "Degree:"); OffSetCursor(xOffSet, 14); break;
			case 10: MaskFunc(0, 16, 10, arrowPos, "Position:"); OffSetCursor(xOffSet, 16); break;
			case 11: MaskFunc(0, 17, 11, arrowPos, "Salary:"); OffSetCursor(xOffSet, 17); break;
			case 12: MaskFunc(0, 18, 12, arrowPos, "Enrollment date:"); OffSetCursor(xOffSet, 18); break;
			case 13: MaskFunc(0, 19, 13, arrowPos, "Encouragements:"); OffSetCursor(xOffSet, 19); break;
			case 14: MaskFunc(0, 20, 14, arrowPos, "Penalties:"); OffSetCursor(xOffSet, 20); break;
			case 15: MaskFunc(0, 21, 15, arrowPos, "Status:"); OffSetCursor(xOffSet, 21); break;
			default: break;
			}
			if (arrowPos != lastPosition)
			{
				isFilled = dataInput(node, arrowPos);
			}
			showConsoleCursor(0);
		}
	}
}

void FireEmployeemenu(Node* node, const char* headline1, int edit)
{
	int firstPosition = 1;
	int lastPosition = 2;
	int arrowPos = 1;
	int key = 0;
	system("cls");
	while (key != ENTER)
	{
		showConsoleCursor(0);
		setToZero();
		textColor(WHITE); printf_s(headline1);
		arrowPosition(1, arrowPos); printf_s("Yes\n");
		arrowPosition(2, arrowPos); printf_s("No\n");

		key = _getch();
		if (key == ARROW_UP)
		{
			arrowPos == firstPosition ? arrowPos = lastPosition : arrowPos--;
		}
		else if (key == ARROW_DOWN)
		{
			arrowPos == lastPosition ? arrowPos = firstPosition : arrowPos++;
		}
	}
	if (arrowPos != lastPosition && edit)
	{
		deleteNode(node, &employeeList);
	}
}

void employeeListMenu(const char* headline1, const char* headline2, int edit, void (*funPtr)(Node*, const char*, int), List* list)
{
	int key = 0;
	int employeesNumber = 1;
	int arrowPos = 1;
	int firstPosition = 1;
	int lastPosition = 2;
	Node* node;
	Node* mainNode;
	while (arrowPos != lastPosition)
	{
		mainNode = list->head;
		system("cls");
		while (key != ENTER)
		{
			showConsoleCursor(0);
			setToZero();
			textColor(WHITE); printf_s(headline1);
			textColor(LIGHTGRAY); printf_s("No.  ID:\t Full name:\n");
			PrintList(&employeesNumber, &arrowPos, mainNode);
			lastPosition = employeesNumber;
			arrowPosition(lastPosition, arrowPos); printf_s("0. Exit\n");
			employeesNumber = 1;

			key = _getch();
			if (key == ARROW_UP)
			{
				arrowPos == firstPosition ? arrowPos = lastPosition : arrowPos--;
			}
			else if (key == ARROW_DOWN)
			{
				arrowPos == lastPosition ? arrowPos = firstPosition : arrowPos++;
			}
		}
		key = 0;
		if (arrowPos != lastPosition)
		{
			node = GetNodeAt(list, arrowPos);
			(*funPtr)(node, headline2, edit);
		}
		showConsoleCursor(0);
	}
}

void searchEmployeeMenu()
{
	int xOffSet = 24;
	int key = 0;
	int employeesNumber = 1;
	int arrowPos = 1;
	int firstPosition = 1;
	int lastPosition = 16;
	int isFilled = 0;
	int isFound = 0;
	Node* node = buffList.tail;
	while (arrowPos != lastPosition)
	{
		system("cls");
		while (key != ENTER)
		{
			showConsoleCursor(0);
			setToZero();
			textColor(WHITE); printf_s("Search by:\n\n");
			textColor(RED); printf_s("  Main:\n");
			arrowPosition(1, arrowPos); printf_s("First name\n");
			arrowPosition(2, arrowPos); printf_s("Last name\n");
			arrowPosition(3, arrowPos); printf_s("Date of birth\n");
			textColor(RED); printf_s("  Passport:\n");
			arrowPosition(4, arrowPos); printf_s("Number\n");
			arrowPosition(5, arrowPos); printf_s("Date of issue\n");
			arrowPosition(6, arrowPos); printf_s("Date of expiry\n");
			arrowPosition(7, arrowPos); printf_s("Nationality\n");
			textColor(RED); printf_s("  Social security card:\n");
			arrowPosition(8, arrowPos); printf_s("Number\n");
			textColor(RED); printf_s("  Education:\n");
			arrowPosition(9, arrowPos); printf_s("Degree\n");
			textColor(RED); printf_s("  Work:\n");
			arrowPosition(10, arrowPos); printf_s("Position\n");
			arrowPosition(11, arrowPos); printf_s("Salary\n");
			arrowPosition(12, arrowPos); printf_s("Enrollment date\n");
			arrowPosition(13, arrowPos); printf_s("Encouragements\n");
			arrowPosition(14, arrowPos); printf_s("Penalties\n");
			arrowPosition(15, arrowPos); printf_s("Status\n");
			printf_s("\n");
			arrowPosition(16, arrowPos); printf_s("0. Exit\n");
			textColor(WHITE);

			key = _getch();
			if (key == ARROW_UP)
			{
				arrowPos == firstPosition ? arrowPos = lastPosition : arrowPos--;
			}
			else if (key == ARROW_DOWN)
			{
				arrowPos == lastPosition ? arrowPos = firstPosition : arrowPos++;
			}
		}
		key = 0;
		switch (arrowPos)
		{
		case 1: OffSetCursor(xOffSet, 3); break;
		case 2: OffSetCursor(xOffSet, 4); break;
		case 3: OffSetCursor(xOffSet, 5); break;
		case 4: OffSetCursor(xOffSet, 7); break;
		case 5: OffSetCursor(xOffSet, 8); break;
		case 6: OffSetCursor(xOffSet, 9); break;
		case 7: OffSetCursor(xOffSet, 10); break;
		case 8: OffSetCursor(xOffSet, 12); break;
		case 9: OffSetCursor(xOffSet, 14); break;
		case 10: OffSetCursor(xOffSet, 16); break;
		case 11: OffSetCursor(xOffSet, 17); break;
		case 12: OffSetCursor(xOffSet, 18); break;
		case 13: OffSetCursor(xOffSet, 19); break;
		case 14: OffSetCursor(xOffSet, 20); break;
		case 15: OffSetCursor(xOffSet, 21); break;
		default: break;
		}
		if (arrowPos != lastPosition)
		{
			isFilled = dataInput(node, arrowPos);
			showConsoleCursor(0);
			if (isFilled)
			{
				isFound = searchEmployee(employeeList.head, node, arrowPos);
				if (isFound)
				{
					employeeListMenu("Search result:\n\n", "Employee information:\n\n", 0, &showEmployeeMenu, &searchResultList);
					clear(&searchResultList);
				}
				else
				{
					system("cls");
					textColor(WHITE); printf_s("Search result:\n\n Nothing was found!");
					_getch();
				}
			}
		}
	}
}

void HireEmployeeMenu(const char* headline1, List* list)
{
	addNode(list);
	setDefaultValues((*list).tail);
	showEmployeeMenu((*list).tail, headline1, 1);
}

void PrintVacationList(Node* node)
{
	const int twoDigitNum = 10;
	int employeesNumber = 1;
	int daysAtWork = 0;
	int vacationDays = 14;
	int workDays = 181;
	int vStartDay = 0, vStartMonth = 0, vStartYear = 0;
	int vEndDay = 0, vEndMonth = 0, vEndYear = 0;
	while (node != NULL)
	{
		daysAtWork = getDifferenceDates(node->employee.enrollmentDate.day, node->employee.enrollmentDate.month, node->employee.enrollmentDate.year);
		addDays(node->employee.enrollmentDate.day, node->employee.enrollmentDate.month, node->employee.enrollmentDate.year,
			workDays, &vStartDay, &vStartMonth, &vStartYear);
		addDays(vStartDay, vStartMonth, vStartYear, vacationDays, &vEndDay, &vEndMonth, &vEndYear);

		textColor(WHITE); printf_s("%d", employeesNumber);
		textColor(RED); printf_s(".\n");

		textColor(LIGHTGRAY); printf_s("  ID");
		textColor(RED); printf_s(": ");
		textColor(DARKGRAY); printf_s("%d\n", node->employee.passport.passportNumber);

		textColor(LIGHTGRAY); printf_s("  Full name");
		textColor(RED); printf_s(": ");
		textColor(DARKGRAY); printf_s("%s %s\n", node->employee.firstName, node->employee.lastName);

		textColor(LIGHTGRAY); printf_s("  Enrollment date");
		textColor(RED); printf_s(": ");
		textColor(DARKGRAY);
		node->employee.enrollmentDate.day < twoDigitNum ? printf_s("%d%d.", 0, node->employee.enrollmentDate.day) : printf_s("%d.", node->employee.enrollmentDate.day);
		node->employee.enrollmentDate.month < twoDigitNum ? printf_s("%d%d.", 0, node->employee.enrollmentDate.month) : printf_s("%d.", node->employee.enrollmentDate.month);
		printf_s("%d\n", node->employee.enrollmentDate.year);

		textColor(LIGHTGRAY); printf_s("  At work for");
		textColor(RED); printf_s(": ");
		daysAtWork > workDays ? textColor(RED) : textColor(GREEN); printf_s("%d", daysAtWork);
		textColor(LIGHTGRAY); printf_s(" days\n");

		textColor(LIGHTGRAY); printf_s("  Start of vacation");
		textColor(RED); printf_s(": ");
		textColor(DARKGRAY);
		vStartDay < twoDigitNum ? printf_s("%d%d.", 0, vStartDay) : printf_s("%d.", vStartDay);
		vStartMonth < twoDigitNum ? printf_s("%d%d.", 0, vStartMonth) : printf_s("%d.", vStartMonth);
		printf_s("%d\n", vStartYear);

		textColor(LIGHTGRAY); printf_s("  The end of vacation");
		textColor(RED); printf_s(": ");
		textColor(DARKGRAY);
		vEndDay < twoDigitNum ? printf_s("%d%d.", 0, vEndDay) : printf_s("%d.", vEndDay);
		vEndMonth < twoDigitNum ? printf_s("%d%d.", 0, vEndMonth) : printf_s("%d.", vEndMonth);
		printf_s("%d\n", vEndYear);
		printf_s("\n");
		employeesNumber++;
		node = node->pNext;
	}
	printf_s("\n");
}

void showVacation()
{
	int key = 0;
	int employeesNumber = 1;
	int isFound = 0;
	Node* node = buffList.tail;
	node->employee.status = _strdup("At work");
	isFound = searchEmployee(employeeList.head, node, 15);
	if (isFound)
	{
		system("cls");
		textColor(WHITE); printf_s("Employees vacation:\n\n");
		PrintVacationList(searchResultList.head);
		arrowPosition(0, 0); printf_s("0. Exit\n");
		while (key != ENTER)
		{
			key = _getch();
		}
		clear(&searchResultList);
	}
	else
	{
		system("cls");
		textColor(WHITE); printf_s("Nobody is at work!");
		_getch();
	}
}

void showStatusMenu(const char* headline1, const char* headline2, const char* status)
{
	int isFound = 0;
	Node* node = buffList.tail;
	node->employee.status = _strdup(status);
	showConsoleCursor(0);
	isFound = searchEmployee(employeeList.head, node, 15);
	if (isFound)
	{
		employeeListMenu(headline1, "Employee information:\n\n", 0, &showEmployeeMenu, &searchResultList);
		clear(&searchResultList);
	}
	else
	{
		system("cls");
		textColor(WHITE); printf_s(headline2);
		_getch();
	}
}

void PrintBirthdayList(Node* node)
{
	const int twoDigitNum = 10;
	int employeesNumber = 1;
	int bDay = 0, bMonth = 0, bYear = 0;
	int daysToBday = 0;
	while (node != NULL)
	{
		daysToBday = getDaysToBday(node->employee.dateOfBirth.day, node->employee.dateOfBirth.month);

		textColor(WHITE); printf_s("%d", employeesNumber);
		textColor(RED); printf_s(".\n");

		textColor(LIGHTGRAY); printf_s("  ID");
		textColor(RED); printf_s(": ");
		textColor(DARKGRAY); printf_s("%d\n", node->employee.passport.passportNumber);

		textColor(LIGHTGRAY); printf_s("  Full name");
		textColor(RED); printf_s(": ");
		textColor(DARKGRAY); printf_s("%s %s\n", node->employee.firstName, node->employee.lastName);

		textColor(LIGHTGRAY); printf_s("  Birthday");
		textColor(RED); printf_s(": ");
		textColor(DARKGRAY);
		node->employee.dateOfBirth.day < twoDigitNum ? printf_s("%d%d.", 0, node->employee.dateOfBirth.day) : printf_s("%d.", node->employee.dateOfBirth.day);
		node->employee.dateOfBirth.month < twoDigitNum ? printf_s("%d%d.", 0, node->employee.dateOfBirth.month) : printf_s("%d.", node->employee.enrollmentDate.month);
		printf_s("%d\n", node->employee.dateOfBirth.year);

		textColor(LIGHTGRAY); printf_s("  Age");
		textColor(RED); printf_s(": ");
		textColor(DARKGRAY); printf_s("%d\n", getAge(node->employee.dateOfBirth.day, node->employee.dateOfBirth.month, node->employee.dateOfBirth.year));

		textColor(LIGHTGRAY); printf_s("  Days to birthday");
		textColor(RED); printf_s(": ");
		if (daysToBday <= 7)
		{
			textColor(GREEN);
		}
		else if (7 < daysToBday && daysToBday <= 30)
		{
			textColor(YELLOW);
		}
		else
		{
			textColor(LIGHTRED);
		}
		printf_s("%d\n", daysToBday);

		printf_s("\n");
		employeesNumber++;
		node = node->pNext;
	}
	printf_s("\n");
}

void showBirthday()
{
	int key = 0;
	system("cls");
	textColor(WHITE); printf_s("Employees birthday:\n\n");
	PrintBirthdayList(employeeList.head);
	arrowPosition(0, 0); printf_s("0. Exit\n");
	while (key != ENTER)
	{
		key = _getch();
	}
}

void printStaffReduction(Node* node, int retirementAge, int PreRetirementAge)
{
	int employeesNumber = 1;
	int age = 0;
	while (node != NULL)
	{
		age = getAge(node->employee.dateOfBirth.day, node->employee.dateOfBirth.month, node->employee.dateOfBirth.year);
		textColor(LIGHTGRAY); printf_s("%d", employeesNumber);
		textColor(RED); printf_s(".");
		textColor(LIGHTGRAY); printf_s(" %d\t %s %s", node->employee.passport.passportNumber, node->employee.firstName, node->employee.lastName);
		if (age <= PreRetirementAge)
		{
			textColor(GREEN);
		}
		else if (PreRetirementAge < age && age < retirementAge)
		{
			textColor(YELLOW);
		}
		else
		{
			textColor(LIGHTRED);
		}
		printf_s("\t %d\n", age);
		employeesNumber++;
		node = node->pNext;
	}
	printf_s("\n");
}

int confirmmenu()
{
	int firstPosition = 1;
	int lastPosition = 2;
	int arrowPos = 1;
	int key = 0;
	system("cls");
	while (key != ENTER)
	{
		showConsoleCursor(0);
		setToZero();
		textColor(WHITE); printf_s("You sure?\n\n");
		arrowPosition(1, arrowPos); printf_s("Yes\n");
		arrowPosition(2, arrowPos); printf_s("No\n");

		key = _getch();
		if (key == ARROW_UP)
		{
			arrowPos == firstPosition ? arrowPos = lastPosition : arrowPos--;
		}
		else if (key == ARROW_DOWN)
		{
			arrowPos == lastPosition ? arrowPos = firstPosition : arrowPos++;
		}
	}
	if (arrowPos != lastPosition)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void showStaffReductionMenu()
{
	int retirementAge = 62;
	int PreRetirementAge = 60;
	int key = 0;
	int employeesNumber = 1;
	int arrowPos = 1;
	int firstPosition = 1;
	int lastPosition = 3;
	Node* node;
	Node* mainNode;
	int confirm = 0;
	while (arrowPos != lastPosition)
	{
		mainNode = employeeList.head;
		system("cls");
		while (key != ENTER)
		{
			showConsoleCursor(0);
			setToZero();
			textColor(WHITE); printf_s("Staff reduction:\n\n");
			arrowPosition(1, arrowPos); printf_s("1. Fire retirement age employees\n");
			arrowPosition(2, arrowPos); printf_s("2. Fire pre-retirement age employees\n");
			printf_s("\n");
			arrowPosition(3, arrowPos); printf_s("0. Exit\n\n");
			textColor(LIGHTGRAY); printf_s("No.  ID:\t Full name:\t Age:\n");
			printStaffReduction(mainNode, retirementAge, PreRetirementAge);
			employeesNumber = 1;

			key = _getch();
			if (key == ARROW_UP)
			{
				arrowPos == firstPosition ? arrowPos = lastPosition : arrowPos--;
			}
			else if (key == ARROW_DOWN)
			{
				arrowPos == lastPosition ? arrowPos = firstPosition : arrowPos++;
			}
		}
		key = 0;
		if (arrowPos != lastPosition)
		{
			confirm = confirmmenu();
			if (confirm)
			{
				switch (arrowPos)
				{
				case 1: fireByAge(&employeeList, retirementAge, 1000); break;
				case 2: fireByAge(&employeeList, PreRetirementAge, retirementAge); break;
				default: break;
				}
			}
		}
	}
}