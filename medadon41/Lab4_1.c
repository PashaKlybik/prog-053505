#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	char num1[21];
	char num2[21];

	puts("������� ������ ����� (�� ����� 19 ����):");
	fgets(num1, 21, stdin);
	puts("������� ������ ����� (�� ����� 19 ����):");
	fgets(num2, 21, stdin);

	long long number1 = atoll(num1);
	long long number2 = atoll(num2);

	puts("�� �����:");
	unsigned long long number3 = number1 + number2;

	if (number3 == 18446744073709551614) {
		puts("����� ������� �� ������� ��������� �������� ���� unsigned long long.");
	}
	else {
		printf("%llu", number3);
	}
}