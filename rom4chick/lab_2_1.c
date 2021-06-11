#include <stdio.h>

int argumentLength(int arg) {
	int argLength = 1;
	while (arg / 10 > 0) {
		argLength++;
		arg /= 10;
	}
	return argLength;
}

void outputFraction(int numerator, int denomerator) {
	printf("%i\n--\n", numerator);
	printf("%i\n", denomerator);
}

void outputReciprocalFraction(int numerator, int denomerator) {
	printf("%i\n--\n", denomerator);
	printf("%i\n", numerator);
}

int selectAction(int numerator, int denomerator) {
	int choice = 0;
	printf("Select your action (1 - output fraction, 2 - output decimal fraction, 3 - output num in sciencific, 4 - output reciprocal fraction, 5 - output reciprocal decimal fractionr, 6 - reciprocal scientific notation\n, 7 - information about developer and version\n");
	scanf_s("%d", &choice);
	if (choice < 0 || choice > 7) {
		printf("You tryed to enter wrong value");
		exit();
	}
	switch (choice) {
	case 1:
		outputFraction(numerator, denomerator);
		break;
	case 2:
		printf("%f\n", (float)numerator / (float)denomerator);
		break;
	case 3:
		printf("%e\n", (float)numerator / (float)denomerator);
		break;
	case 4:
		outputReciprocalFraction(numerator, denomerator);
		break;
	case 5:
		printf("%f\n", (float)denomerator / (float)numerator);
		break;
	case 6:
		printf("%e\n", (float)denomerator / (float)numerator);
		break;
	case 7:
		printf("Developed by Freasy\nVersion 1.54\n");
		break;
	default:
		printf("Вы вышли из меню");
		break;
		return 0;
	}
	return 1;
}

int main() {
	int numerator = 0, denomerator = 0, choice = 0, action = 0;
	printf("Please enter numerator for rational fraction\n");
	scanf_s("%i", &numerator);
	printf("Please enter denomerator for rational fraction\n");
	scanf_s("%i", &denomerator);
	printf("Numerator = %i\n", numerator);
	printf("denomerator = %i\n", denomerator);
	action = selectAction(numerator, denomerator);
	while (action) {
		action = selectAction(numerator, denomerator);
	}
}