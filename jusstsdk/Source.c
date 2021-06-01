#include <stdio.h>
#include <stdbool.h>

int main() {
	
	int arabicNumber;
	bool checkOfInput = true;
	bool checkExit;
	int consoleInput;

	do
	{
		do {
			printf("Enter the number from 1 to 3999: ");
			scanf_s("%d", &arabicNumber);
			
			if (arabicNumber < 1 || arabicNumber > 3999) {
				printf("Try again!\n\n");
				checkOfInput = true;
			}
			else {
				checkOfInput = false;
			}

		} while (checkOfInput);

		char romanNumber[20] = { 0 };

 		switch (arabicNumber / 1000) {
		case 3:
			romanNumber[0] = 'M';
			romanNumber[1] = 'M';
			romanNumber[2] = 'M';
			arabicNumber -= 3000;
			break;
		case 2:
			romanNumber[0] = 'M';
			romanNumber[1] = 'M';
			arabicNumber -= 2000;
			break;
		case 1:
			romanNumber[0] = 'M';
			arabicNumber -= 1000;
			break;
		}

		switch (arabicNumber / 100) {
		case 1:
			romanNumber[3] = 'C';
			arabicNumber -= 100;
			break;
		case 2:
			romanNumber[3] = 'C';
			romanNumber[4] = 'C';
			arabicNumber -= 200;
			break;
		case 3:
			romanNumber[3] = 'C';
			romanNumber[4] = 'C';
			romanNumber[5] = 'C';
			arabicNumber -= 300;
			break;
		case 4:
			romanNumber[3] = 'C';
			romanNumber[4] = 'D';
			arabicNumber -= 400;
			break;
		case 5:
			romanNumber[3] = 'D';
			arabicNumber -= 500;
			break;
		case 6:
			romanNumber[3] = 'D';
			romanNumber[4] = 'C';
			arabicNumber -= 600;
			break;
		case 7:
			romanNumber[3] = 'D';
			romanNumber[4] = 'C';
			romanNumber[5] = 'C';
			arabicNumber -= 700;
			break;
		case 8:
			romanNumber[3] = 'D';
			romanNumber[4] = 'C';
			romanNumber[5] = 'C';
			romanNumber[6] = 'C';
			arabicNumber -= 800;
			break;
		case 9:
			romanNumber[3] = 'C';
			romanNumber[4] = 'M';
			arabicNumber -= 900;
			break;
		}

		switch (arabicNumber / 10) {
		case 1:
			romanNumber[7] = 'X';
			arabicNumber -= 10;
			break;
		case 2:
			romanNumber[7] = 'X';
			romanNumber[8] = 'X';
			arabicNumber -= 20;
			break;
		case 3:
			romanNumber[7] = 'X';
			romanNumber[8] = 'X';
			romanNumber[9] = 'X';
			arabicNumber -= 30;
			break;
		case 4:
			romanNumber[7] = 'X';
			romanNumber[8] = 'L';
			arabicNumber -= 40;
			break;
		case 5:
			romanNumber[7] = 'L';
			arabicNumber -= 50;
			break;
		case 6:
			romanNumber[7] = 'L';
			romanNumber[8] = 'X';
			arabicNumber -= 60;
			break;
		case 7:
			romanNumber[7] = 'L';
			romanNumber[8] = 'X';
			romanNumber[9] = 'X';
			arabicNumber -= 70;
			break;
		case 8:
			romanNumber[7] = 'L';
			romanNumber[8] = 'X';
			romanNumber[9] = 'X';
			romanNumber[10] = 'X';
			arabicNumber -= 80;
			break;
		case 9:
			romanNumber[7] = 'X';
			romanNumber[8] = 'C';
			arabicNumber -= 90;
			break;
		}

		switch (arabicNumber) {
		case 1:
			romanNumber[11] = 'I';
			break;
		case 2:
			romanNumber[11] = 'I';
			romanNumber[12] = 'I';
			break;
		case 3:
			romanNumber[11] = 'I';
			romanNumber[12] = 'I';
			romanNumber[13] = 'I';
			break;
		case 4:
			romanNumber[11] = 'I';
			romanNumber[12] = 'V';
			break;
		case 5:
			romanNumber[11] = 'V';
			break;
		case 6:
			romanNumber[11] = 'V';
			romanNumber[12] = 'I';
			break;
		case 7:
			romanNumber[11] = 'V';
			romanNumber[12] = 'I';
			romanNumber[13] = 'I';
			break;
		case 8:
			romanNumber[11] = 'V';
			romanNumber[12] = 'I';
			romanNumber[13] = 'I';
			romanNumber[14] = 'I';
			break;
		case 9:
			romanNumber[11] = 'I';
			romanNumber[12] = 'X';
			break;
		}

		for (int i = 0; i < 20; i++) {
			if (romanNumber[i])
				printf("%c", romanNumber[i]);
		}

		printf("\n\n");

		printf("Continue? Yes - 1. No - 0\n");
		scanf_s("%d", &consoleInput);

		if (consoleInput == 1) {
			checkExit = true;
		}
		else
			checkExit = false;

		printf("\n");

	} while (checkExit);

	return 0;
}