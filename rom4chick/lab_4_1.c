#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int strLength(char* str) {
	int length = 0;
	int i = 0;
	while (str[i] != '\0') {
		length++;
		i++;
	}
	return length;
}

long long int fromChartoLong(char* str) {
	long long strInt = 0;
	for (int i = 0; i < strLength(str) - 1; i++) {
		strInt += ((int)str[i] - 48) * pow(10, strLength(str) - (i + 2));
	}
	return strInt;
}

int numLength(long long int num) {
	long long divider = 10;
	int length = 1;
	while (num / divider >= 1) {
		length++;
		divider *= 10;
	}
	return length;
}

int main() {
	int firstStrSize = 10;
	int secondStrSize = 10;
	printf("Please enter size of first string(more than 10 symbols) ");
	scanf_s("%d", &firstStrSize);
	fflush(stdin);
	printf("Please enter size of second string(more than 10 symbols) ");
	scanf_s("%d", &secondStrSize);
	char* firstStr = (char*)malloc(sizeof(char) * firstStrSize);
	char* secondStr = (char*)malloc(sizeof(char) * secondStrSize);
	char* buffer = (char*)malloc(sizeof(char) * 1);
	gets(buffer);
	printf("\nPlease enter first string ");
	fgets(firstStr, firstStrSize, stdin);
	puts(firstStr);
	printf("\nPlease enter second string ");
	fgets(secondStr, secondStrSize, stdin);
	puts(secondStr);
	long long int firstStrInt = fromChartoLong(firstStr);
	long long int secondStrInt = fromChartoLong(secondStr);
	int sumLength = numLength(firstStrInt + secondStrInt);
	char* sumStr = (char*)malloc(sizeof(char) * (sumLength + 1));
	printf("NUm lengl = %d", sumLength);
	_itoa_s(firstStrInt + secondStrInt, sumStr, sumLength + 1, 10);
	printf("\nfirstStrInt = %ld", firstStrInt);
	printf("\nsecondStrInt = %ld", secondStrInt);
	printf("\nSumStr = %s", sumStr);
	free(firstStr);
	free(secondStr);
	free(sumStr);
}  