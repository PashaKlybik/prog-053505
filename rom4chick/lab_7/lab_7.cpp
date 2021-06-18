#include "menu.h"
#include "Container.h"
#include "List.h"

int main()
{
	addNode(&buffList);
	setDefaultValues(buffList.tail);
	readFile();
	int functionNumber = 0;
	int exit = 10;
	while (functionNumber != exit)
	{
		system("cls");
		functionNumber = menu();
		switch (functionNumber)
		{
		case 1: employeeListMenu("Employee list:\n\n", "Employee information:\n\n", 1, &showEmployeeMenu, &employeeList); break;
		case 2: searchEmployeeMenu(); break;
		case 3: employeeListMenu("Choose who to fire:\n\n", "You sure?\n\n", 1, &FireEmployeemenu, &employeeList); break;
		case 4: HireEmployeeMenu("Enter information about the new employee:\n\n", &employeeList); break;
		case 5: showVacation(); break;
		case 6: showBirthday(); break;
		case 7: showStatusMenu("Employees who are currently at work:\n\n", "Employees who are currently at work:\n\n Nobody is at work!", "At work"); break;
		case 8: showStatusMenu("Employees who are currently on vacation:\n\n", "Employees who are currently on vacation:\n\n Nobody on vacation!", "On vacation"); break;
		case 9: showStaffReductionMenu(); break;
		case 10: system("cls"); writeFile();  clear(&employeeList); clear(&buffList); clear(&searchResultList); break;
		default: break;
		}
	}
	printf_s(" ");
	return 0;
}