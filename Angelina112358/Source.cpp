#include <stdio.h>

int main() {
	while (1) {
		int number, exit_condition;
		printf("Enter a=");
		scanf("%d", &number);
		if (number > 999 && number < 10000) {
			int remainder = number % 100;
			number = number / 100;
			int finite_number = remainder * 100 + number;
			printf("%d\n", finite_number);
			printf("If you want to quit, press '0'. If you want to continue, press '1'\n");
			scanf("%d", &exit_condition);
			if (exit_condition == 0) return 0;
		}
		else printf("You entered a non-four-digit number.\n");
	}
}