#include<stdio.h>
#include<math.h>

int main()
{
	int k = -1;
	int FirstNumber = 100;
	int SearchingNumber = -1;
	int SearchingNumeral = -1;
	printf("You have given a numeric row:100101102.... Enter the number of this row:");
	scanf_s("%d", &k);
	if (k <= 0)
	{
		printf("You have entered wrong value\n");
		return -1;
	}
	SearchingNumber = FirstNumber + (k-1) / 3;
	SearchingNumeral = SearchingNumber / pow(10, 2 - ((k-1) % 3));
	SearchingNumeral = SearchingNumeral % 10;
	printf("The %d number is %d", k, SearchingNumeral);
	return 0;
}