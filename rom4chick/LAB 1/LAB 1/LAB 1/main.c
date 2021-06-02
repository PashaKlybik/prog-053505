#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int countArgumentLength(int arg) {
	int argLength = 1;
	while (arg / 10 > 0) {
		argLength++;
		arg /= 10;
	}
	return argLength;
}

void generateMultiplication (int firstArg, int secondArg) {
	double n = 0;
	int secondArgLength = countArgumentLength(secondArg);
	char str[255];
	for (int i = 0; i < strlen(str); i++) {
		
	}

int main()
{
	printf("Please initialize two input variables\n");
	int firstArg, secondArg;
	scanf_s("%d", &firstArg);
	scanf_s("%d", &secondArg);
	printf("Fist argument: %d\nSecond argument: %d\n", firstArg, secondArg);
	printf("==================\n");
	printf("\t\t%d\n", firstArg);
	printf("\t\t%d\n", secondArg);
	printf("------------------\n");
	generateMultiplication(firstArg, secondArg);

	return 0;
}