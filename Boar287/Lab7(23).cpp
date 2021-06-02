#include "DataBaseElement.h"

void FillSourceInfo(DataBaseElement* current, const char* Language, const char* Theme, int year, int month, int day, char* FileName)
{
	FILE* file = fopen(FileName, "r");
	if ((file = fopen(FileName, "r")) == NULL)
	{
		printf("Error in openning file");
		return;
	}
	int Index = 0;
	while (fscanf(file, "%c", &current->sourceCode->Data[Index]) != EOF) { Index++; }
	current->sourceCode->Data[Index] = '\0';

	fclose(file);
	current->ComSize = 0;
	current->StateSize = 0;
	strcpy(current->sourceCode->Language, Language);
	strcpy(current->sourceCode->Theme, Theme);
	current->sourceCode->date[0] = day;
	current->sourceCode->date[1] = month;
	current->sourceCode->date[2] = year;
}

void FillComInfo(DataBaseElement* current, int index, const char* Data)
{
	current->ComSize++;
	strcpy(current->Comments[index], Data);
}

void FillStateInfo(DataBaseElement* current, int index, const char* _Language, const char* _Theme = "None", int year = 2021, int month = 04, int day = 24)
{
	strcpy(current->Statements[index].Language, _Language);
	strcpy(current->Statements[index].Theme, _Theme);
	current->Statements[index].date[0] = day;
	current->Statements[index].date[1] = month;
	current->Statements[index].date[2] = year;
}

void ShowInfo(DataBaseElement* current, int index)
{
	printf("%d)", (index + 1));
	printf("Source Code:\n%s\n", current->sourceCode->Data);
	printf("  Language:%s", current->sourceCode->Language);
	printf("  Theme:%s", current->sourceCode->Theme);
	printf("  Date:%d/%d/%d\n\n", current->sourceCode->date[2], current->sourceCode->date[1], current->sourceCode->date[0]);

	printf("  Statements(%d)\n", current->StateSize);
	for (int i = 0; i < current->StateSize; i++)
	{
		if (current->Statements[i].date[0] < 0)
		{
			current->Statements[i].date[0] = 1972;
			current->Statements[i].date[1] = 1;
			current->Statements[i].date[2] = 1;
		}
		if ((int)current->Statements[i].Theme[0] < 0)
			strcpy(current->Statements[i].Theme,"None");

		printf("      %d)", (i + 1));
		printf("Theme:%s\n", current->Statements[i].Theme);
		printf("        Date:%d/%d/%d\n", current->Statements[i].date[2], current->Statements[i].date[1], current->Statements[i].date[0]);
		printf("\t%s", current->Statements[i].Data);
	}
	printf("\n\n");
	printf("  Comments(%d)\n", current->ComSize);
	printf("------------------------------------------------------------------------\n");
	printf("\n");
}
