#include <stdio.h>
#include <math.h>

int main() {
	int number = 0;
	const int size = 4;
	int remainder;
	int thousHund;
	while (1) {
		if (!scanf("%d", &number) || number <= 0 || getchar() != '\n')
			while (getchar() != '\n');
		else
			break;
		printf("Ввод некорректен. Повторите ввод: ");
	}
	int power = pow(10, size / 2);
	remainder = number % power;
	thousHund = number/power;
	number = remainder*power + thousHund;
	printf("\n%d", number);
	return 0;
}