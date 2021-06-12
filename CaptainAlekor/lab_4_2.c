#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


#define BUFFER_SIZE 500

char* LastChar(const char* str)
{
	char* endptr = str;
	while (*endptr != '\0') endptr++;
	endptr--;
	return endptr;
}
char IsBalanced(const char* str)
{
	char* ptr = str;
	int brCount = 0;
	while (*ptr != '\0')
	{
		if (*ptr == '(') brCount++;
		else if (*ptr == ')') brCount--;
		ptr++;
	}
	if (!brCount)
	{
		printf("The brackets are in balance\n");
		return 1;
	}
	else
	{
		printf("The brackets are not in balance\n");
		return 0;
	}
}
void ChangeBrackets(char* str)
{
	int brCount = 0, maxCount = 0;
	char* ptr = str;
	while (*ptr != '\0')
	{
		if (brCount == 0) maxCount = 0;
		if (*ptr == '(')
		{
			brCount++;
			maxCount++;
		}
		else if (*ptr == ')')
		{
			if (maxCount == 2)
			{
				if (brCount == 1) *ptr = ']';
			}
			else if (maxCount >= 3)
			{
				if (brCount <= maxCount - 2) *ptr = '}';
				else if (brCount == maxCount - 1) *ptr = ']';
			}
			brCount--;
		}
		ptr++;
	}
	ptr = LastChar(str);
	while (ptr >= str)
	{
		if (brCount == 0) maxCount = 0;
		if (*ptr == ')' || *ptr == ']' || *ptr == '}')
		{
			brCount++;
			maxCount++;
		}
		else if (*ptr == '(')
		{
			if (maxCount == 2)
			{
				if (brCount == 1) *ptr = '[';
			}
			else if (maxCount >= 3)
			{
				if (brCount <= maxCount - 2) *ptr = '{';
				else if (brCount == maxCount - 1) *ptr = '[';
			}
			brCount--;
		}
		ptr--;
	}
	puts("Brackets have been changed\n");
}

int main()
{
	FILE* textFile;
	char fileName[] = "text.txt", text[BUFFER_SIZE];

	if ((textFile = fopen(fileName, "r")) == NULL)
	{
		puts("An error occurred while trying to open the file");
		return 0;
	}
	else
	{
		fgets(text, BUFFER_SIZE, textFile);
		if (!IsBalanced(text))
		{
			fclose(textFile);
			return 0;
		}
		else
		{
			ChangeBrackets(text);
			fclose(textFile);
			textFile = fopen(fileName, "w");
			fprintf(textFile, "%s", text);
			fclose(textFile);
		}
	}
}