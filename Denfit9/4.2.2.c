#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#define Size 128

int Balance(const char* line) {      //Checking balance of brackets
	char* processed = line;
	int openBr = 0;
	int closeBr = 0;
	while (*processed != '\0') {
		if (*processed == '(') {
			openBr++;
		}
		else if (*processed == ')') {
			closeBr++;
		}
		processed++;
	}
	if (openBr == 0 && closeBr == 0) {
		printf("Your file doesn't have any brackets or empty");
		return 0;
	}
	else if (openBr == closeBr) {
		printf("Brackets are in balance");
		return 1;
	}
	else {
		printf("Brackets are not in balance");
		return 0;
	}
 }
void CorrectBrackets(char *line) {     //starting to correct brackets
	char* processed = line;
	int bracketCount = 0;
	int bracketMax = 0;
	int procCount = 0;
	while (*processed != '\0')         //changing all brackets to '{' or '}'
	{
		if (*processed == '(') 
		{
			*processed = '{';
			bracketCount++;
			if (bracketCount > bracketMax)     //finding max level of brackets
			{
				bracketMax = bracketCount;
			}
		}
		if (*processed == ')') 
		{
			*processed = '}';
			bracketCount--;
		}
		processed++;
		procCount++;
	}
	for (int i = 0; i < procCount; i++)   //return to starting position
	{
		processed--;
	}
	while (*processed != '\0')      // and then changing all brackets with our rules
	{
		if (*processed == '{')
		{
			bracketCount++;
			if (bracketCount == bracketMax) 
			{ 
				*processed = '(';
			}
			if (bracketCount == bracketMax - 1) { 
				*processed = '[';
			}
		}
		if (*processed == '}')
		{
			if (bracketCount == bracketMax) { 
				*processed = ')'; 
			}
			if (bracketCount == bracketMax - 1) { 
				*processed = ']'; 
			}
			bracketCount--;
		}
		processed++;
	}
}

void main(void)
{
	char text[Size];
	FILE* workingFile; 
	workingFile = fopen("text.txt", "r"); 
	if (!workingFile) {
		printf("error");
		exit(1);
	}
	else {
		fgets(text, Size, workingFile);
		
		if (Balance(text)) {
			fclose(workingFile);
			workingFile = fopen("text.txt", "w");
			CorrectBrackets(text);
			printf("\n...and already have been changed!");
			fprintf(workingFile, "%s", text);
			fclose(workingFile);
		}
		else {
			fclose(workingFile);
			return 0;
		}
	}
}