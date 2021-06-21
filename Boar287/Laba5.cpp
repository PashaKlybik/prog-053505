#include  <ctime>
#include "Functions.h"

int main()
{
	srand(time(NULL));
	Stack TheFirst;
	Stack TheSecond;
	int SizeStack1 = -1;
	int SizeStack2 = -1;
	printf("Enter the size of the first stack:");
	scanf_s("%d", &SizeStack1);
	printf("Enter the size of the second stack:");
	scanf_s("%d", &SizeStack2);
	FillStack(&TheFirst, SizeStack1);
	FillStack(&TheSecond, SizeStack2);
	system("cls");
	printf("The first stack:");
	PrintStack(&TheFirst);
	printf("The second stack:");
	PrintStack(&TheSecond);
	printf("The shared stack:");
	Gluing(&TheFirst, &TheSecond);
	PrintStack(&TheFirst);
	printf("The final stack:");
	UniqueElemnt(&TheFirst);
	PrintStack(&TheFirst);
	Clear(&TheFirst);
	Clear(&TheSecond);
	return 0;
}