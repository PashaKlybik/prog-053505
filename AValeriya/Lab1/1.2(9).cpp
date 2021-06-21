#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	double ch;
	int r, k;
	printf("Enter the number:\n");
	scanf_s("%lf", &ch);
	while (ch <= 0) 
	{
		printf("Number ch must be greater then 0.\n");
		exit(0);
	}
	r = ch;
	k = round(100 * (ch - r));
	printf("%d rubles\t%d kopecks", r, k);
}