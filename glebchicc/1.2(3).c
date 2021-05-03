#include <stdio.h>;
#include <math.h>;

void main() {
	int k, temp = 0;
	int count = 1, i = 2;
	
	printf("Enter the index: ");
	scanf_s("%d", &k);
	while (k <= 0) {
		printf("Incorrect input, try again: ");
		scanf_s("%d", &k);
	}
	
	while (count < k) {
		temp = pow(i, 3);
		i++;
		count += ceil(log10(temp));
	}

	if (count > k) {
		temp /= 10 * (count - k);
	}

	int j = ceil(log10(temp));
	if (j != 1) {
		temp %= (10 * (j - 1));
	}

	printf("Result: ");
	printf("%d", temp);
}