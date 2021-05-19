#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#define N 60

void program1(void) {
	int i = 0;
	char str[80], ch;
	int vowels[6];
	vowels[0] = 0; vowels[1] = 0; vowels[2] = 0; vowels[3] = 0; vowels[4] = 0; vowels[5] = 0;
	puts("\nPrint: ");
	while ((ch = getchar()) != '\n') {
		switch (ch)
		{
		case 'a':
		case 'A':
			vowels[0]++; break;
		case 'e':
		case 'E':
			vowels[1]++; break;
		case 'i':
		case 'I':
			vowels[2]++; break;
		case 'o':
		case 'O':
			vowels[3]++; break;
		case 'u':
		case 'U':
			vowels[4]++; break;
		case 'y':
		case 'Y':
			vowels[5]++; break;
		default:
			break;
		}
	}
	str[i] = '\0';
	puts(str);
	printf("a = %d\n", vowels[0]);
	printf("e = %d\n", vowels[1]);
	printf("i = %d\n", vowels[2]);
	printf("o = %d\n", vowels[3]);
	printf("u = %d\n", vowels[4]);
	printf("y = %d\n", vowels[5]);
}

void program2(void) {
	FILE* file; 
	int number = 10;
	
	int n = 0;
	fopen_s(&file, "input.txt", "r"); 
	if (!file) exit(1); 

	char** names = (char**)malloc(number * sizeof(char*));
	int i = 0;

	for (i = 0; i < number; i++) {
		names[i] = (char*)malloc(N * sizeof(char));
	}
	
	i = 0;
	while (fgets(names[i], N, file) != NULL) {
		i++;
	}
	
	for (i = 0; i < number - 1; i++)
	{
		int numOfMax = i;
		char* maxName = names[i];
		bool found = false;

		for (int j = i + 1; j < number; j++) {
			if (names[j][0] < maxName[0]) {
				numOfMax = j;
				maxName = names[j];
				found = true;
			}
		}

		if (found) {
			char* interim = names[i];
			names[i] = names[numOfMax];
			names[numOfMax] = interim;
		}
	}

	fclose(file);
	fopen_s(&file, "output.txt", "w");
	if (!file) exit(1);

	for (i = 0; i < number; i++) {
		fprintf(file, "%s\n", names[i]);
	}
	fclose(file);


	for (i = 0; i < number; i++) {
		free(names[i]);
	}
	free(names);
}

void main(void)
{
	program1();
	//program2();
}