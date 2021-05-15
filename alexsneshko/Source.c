#include <stdio.h>
#include <malloc.h>


void print_numder_2(int number, int rank) {

	char* number_2 = (char*)malloc(rank * sizeof(char));
	int i = 0;

	while (number != 1) {
		if (number % 2 == 0) {
			number /=  2;
			number_2[i] = '0';
		}
		else {
			number = (--number) / 2;
			number_2[i] = '1';
		}
		i++;
	}
	number_2[rank - 1] = '1';
	
	printf("\tnumber in 2 system ");
	for (int i = rank - 1; i >= 0; i--) {
		printf("%c", number_2[i]);
	}
	printf("\n");
	free(number_2);
}

int main() {

	int last_number;
	int needded_number = 7;
	int switcher = 0;
	int rank = 3;
	printf("print last number: ");
	scanf_s("%d", &last_number);

	if (last_number >= needded_number) {
		while (last_number >= needded_number) {
			printf("nuumber: %d", needded_number);
			print_numder_2(needded_number, rank);

			if (switcher % 2 == 0) {
				needded_number = needded_number << 3;
			}
			else {
				needded_number = needded_number << 3;
				needded_number = needded_number | 7;
			}
			switcher++;
			rank += 3;
		}
	}
	else {
		printf("no such numbers");
	}

	_getch();
	return 0;
}