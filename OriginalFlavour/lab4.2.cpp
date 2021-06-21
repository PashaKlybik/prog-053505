#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


int Length(char* str, int wordCount)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			wordCount++;
	}
	return wordCount;
}


char** Filling(char* str, int n, char** words, int position)
{
	for (int i = 0; i < n; i++)
		words[i] = (char*)malloc(n * sizeof(char));
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' || '\0')
		{
			words[position][j] = str[i];
			words[position][j + 1] = '\0';
		}
		j++;
		if (str[i] == ' ')
		{
			position++;
			j = 0;
		}

	}
	return words;
}


char** Sort(char** words, char* temp, int wordCount)
{
	char fir[10];
	char sec[10];
	bool check = true;
	int k = 0;


	for (int i = 0; i < wordCount - 1; i++)
	{
		for (int j = i + 1; j < wordCount; j++)
		{
			if (strcmp(words[i], words[j]) > 0)
			{

				temp = words[i];
				words[i] = words[j];
				words[j] = temp;

			}
		}
	}
	return words;
}


int main()
{


	int n = 100;
	int position = 0;
	char* temp = (char*)malloc(n * sizeof(char));
	char** words = (char**)malloc((n) * sizeof(char*));
	char s[500];

	FILE* fp = fopen("4.2.txt", "r");
	if (!fp)
	{
		printf("Error!\n");
		return 1;
	}
	while (!feof(fp))
	{
		fgets(s, sizeof(s), fp);
	}
	printf(" Words from file: %s ", s);
	fclose(fp);

	int wordCount = Length(s, 1);
	Filling(s, n, words, position);
	printf("\n\n");
	Sort(words, temp, wordCount);
	printf(" Words in alphabetical order: ");

	for (int q = 0; q < wordCount; q++)
		printf("%s ", words[q]);
	printf("\n\n");

	for (int i = 0; i < n; i++)
	{
		free(words[i]);
	}
	free(words);
	free(temp);

	return 0;
}