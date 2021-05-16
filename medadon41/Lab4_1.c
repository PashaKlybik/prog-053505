#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	char num1[21];
	char num2[21];

	puts("¬ведите первое число (не более 19 цифр):");
	fgets(num1, 21, stdin);
	puts("¬ведите второе число (не более 19 цифр):");
	fgets(num2, 21, stdin);

	long long number1 = atoll(num1);
	long long number2 = atoll(num2);

	puts("»х сумма:");
	unsigned long long number3 = number1 + number2;

	if (number3 == 18446744073709551614) {
		puts("„исло выходит за пределы возможных значений типа unsigned long long.");
	}
	else {
		printf("%llu", number3);
	}
}