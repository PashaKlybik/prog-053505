//lab#7 var#26
/*Отдел кадров. Содержит полный список сотрудников организации: 
ФИО, дата рождения, паспортные данные, карточка соц. 
страхования, образование, должность, оклад, дата поступления на
© Кафедра информатики БГУИР, Мелещенко А.А. 96
работу, примечание (поощрения и взыскания). Программа
осуществляет поиск сотрудника по любому полю. Функции
увольнения и принятия на работу. Показывает срок работы
сотрудника и подыскивает время отпуска (после полугода работы
полагается 2 недели отпуска). Сообщения о приближающихся днях
рождения сотрудников. Списки работников, которые находятся на
работе и в отпуске. Сокращение штатов: выбор для увольнения лиц
пенсионного и предпенсионного возраста, подготовка приказа.*/


#include "Menu.h"
#include "Container.h"
#include "List.h"

#define bool int
#define true 1
#define false 0 

int main()
{
	AddNode(&buffList);
	SetDefaultValues(buffList.tail);
	ReadFile();
	int functionNumber = 0;
	int exit = 10;
	while (functionNumber != exit)
	{
		system("cls");
		functionNumber = Menu();
		switch (functionNumber)
		{
		case 1: EmployeeListMenu("Employee list:\n\n", "Employee information:\n\n", true, &ShowEmployeeMenu, &employeeList); break;
		case 2: SearchEmployeeMenu(); break;
		case 3: EmployeeListMenu("Choose who to fire:\n\n", "You sure?\n\n", true, &FireEmployeeMenu, &employeeList); break;
		case 4: HireEmployeeMenu("Enter information about the new employee:\n\n", &employeeList); break;
		case 5: ShowVacation(); break;
		case 6: ShowBirthday(); break;
		case 7: ShowStatusMenu("Employees who are currently at work:\n\n", "Employees who are currently at work:\n\n Nobody is at work!", "At work"); break;
		case 8: ShowStatusMenu("Employees who are currently on vacation:\n\n", "Employees who are currently on vacation:\n\n Nobody on vacation!", "On vacation"); break;
		case 9: ShowStaffReductionMenu(); break;
		case 10: system("cls"); WriteFile();  Clear(&employeeList); Clear(&buffList); Clear(&searchResultList); break;
		default: break;
		}
	}
	printf_s(" ");
	return 0;
}