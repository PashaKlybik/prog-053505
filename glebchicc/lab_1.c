#include <stdio.h>
#include <math.h>

#pragma warning(disable : 4996)

void main() {
	int k, temp = 0;
	int count = 1, i = 2;

	
	printf("Enter the index: ");
	for (int i = 0; i < 1; i++) { //проверка ввода
		char eol = 0;
		if (scanf("%d%c", &k, &eol) != 2 || eol != '\n' || k < 0) {
			printf("Incorrect input, try again: \n");
			scanf("%*[^\n]");
			--i;
		}
	}
	
	while (count < k) {
		temp = (int)pow(i, 3);
		i++;
		count += (int)ceil(log10(temp));
	}

	if (count > k) {
		temp /= (int)pow(10, abs(count - k));
	}

	int j = (int)ceil(log10(temp));
	if (j != 1) {
		for (int i = 0; i < abs(j - 1); i++) {
			temp %= 10;
		}
	}

	printf("Result: %d", temp);
}
