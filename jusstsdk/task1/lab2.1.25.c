#include <stdio.h>
#include <stdbool.h>

void ProgramMenu() {
	printf("1. Number input.\n2. Number output in different forms.\n3. Reverse number output.\n");
	printf("4. Reduced number output.\n5. Information about the program. \n6. Exit.\n\n");
}

void NumberInput(int* numerator, int* denominator) {

	printf("Enter the numerator of the rational number: ");
	scanf_s("%d", numerator);
	printf("Enter the denominator of the rational number: ");
	scanf_s("%d", denominator);
	printf("\n");
}

void NumberOutput(int numerator, int denominator) {

	printf("Fraction: %d\n\t  ___\n\t  %d\n", numerator, denominator);
	float divisionResult  = (float)numerator / (float)denominator;
	printf("Decimal form: %f\n", divisionResult);
	printf("Scientific notation: %E\n\n", divisionResult);
}

void ReverseNumber(int numerator, int denominator) {

	printf("Reverse fraction: %d\n\t\t  ___\n\t\t  %d\n", denominator, numerator);
	float reverseResult = (float)denominator / (float)numerator;
	printf("Reverse number in decimal form: %f\n\n", reverseResult);
	
}

void ReducedNumber(int numerator, int denominator) {
		
		for (int i = numerator; i >= 1; i--) {

			if(numerator % i == 0 && denominator % i == 0) {
				numerator /= i;
				denominator /= i;
			}
		}

		printf("Reduced fraction: %d\n\t\t  ___\n\t\t  %d\n", numerator, denominator);
}

void Information() {

	printf("Version: 1.0.0\nCreator: Angelina Tsareva. 2021.\n\n");
}


int main() {

	int numerator, denominator;
	bool exitCheck = 1;
	int selectAction, makeSure;

	NumberInput(&numerator, &denominator);
	
	ProgramMenu();

	do
	{
		printf("_____________________________________\n");
		printf("Select the action: ");
		scanf_s("%d", &selectAction);
		printf("\n");

		switch (selectAction)
		{
		case 1:
			NumberInput(&numerator, &denominator);
			break;

		case 2:
			NumberOutput(numerator, denominator);
			break;

		case 3:
			ReverseNumber(numerator, denominator);
			break;

		case 4:
			ReducedNumber(numerator, denominator);
			break;

		case 5:
			Information();
			break;

		case 6: 
			printf("Are you sure? Yes - 1. No - 0.\n");
			scanf_s("%d", &makeSure);
			printf("\n");

			if (makeSure == 1)
				exitCheck = 0;

			break;

		default:
			printf("Try again!\n\n\n");
			break;
		}
	
	} while (exitCheck);

	return 0;
}