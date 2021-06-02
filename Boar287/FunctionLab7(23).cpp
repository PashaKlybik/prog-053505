#include "Functions.h"

void FillSourceCode(DataBaseElement* current,char* FileName)
{
	FILE* file = fopen(FileName, "r");
	if((file = fopen(FileName,"r"))==NULL)
	{
		printf("Error in openning file");
		return;
	}
	int Index = 0;
	while (fscanf(file, "%c", &current->sourceCode->Data[Index]) != EOF) { Index++; }
	fclose(file);
}



void FillStatementCode(DataBaseElement* current, char* FileName)
{	
	current->StateSize = CountNumberInFile(FileName);
	FILE* file = fopen(FileName, "r");
	if ((file = fopen(FileName, "r")) == NULL)
	{
		printf("Error in openning file");
		return;
	}

	int Index = 0;
	char temp;
	for (int i = 0; i < current->StateSize; i++)
	{
		while (fscanf(file, "%c", &temp) != EOF)
		{
			if ((temp != '!') || ((temp == '!') && (Index == 0)))
			{
				current->Statements[i].Data[Index] = temp;
				Index++;
			}
			else
				break;
		}
		current->Statements[i].Data[Index] = '\0';
		Index = 0;
	}
	fclose(file);
}

int CountNumberInFile(char* FileName)
{
	int NumberOfDividers = 0;
	FILE* file = fopen(FileName, "r");
	if ((file = fopen(FileName, "r")) == NULL)
	{
		printf("Error in openning file");
		return 0;
	}

	char temp;
	while (fscanf(file, "%c", &temp) != EOF)
	{
		if (temp == '!')
		{
			NumberOfDividers++;
		}
	}		
	fclose(file);
	return NumberOfDividers;
}

void GetElemInfo(DataBaseElement current,int index)
{
	printf("%d)", (index+1));
	printf("Source Code:\n%s\n", current.sourceCode->Data);
	printf("  Language:%s", current.sourceCode->Language);
	printf("  Theme:%s", current.sourceCode->Theme);
	printf("  Date:%d/%d/%d\n\n", current.sourceCode->date[2], current.sourceCode->date[1], current.sourceCode->date[0]);

	printf("  Statements(%d)\n", current.StateSize);
	for (int i = 0; i < current.StateSize; i++)
	{

		printf("      %d)", (i + 1));
		printf("Theme:%s\n", current.Statements[i].Theme);
		printf("        Date:%d/%d/%d\n", current.Statements[i].date[2], current.Statements[i].date[1], current.Statements[i].date[0]);
		printf("\t%s", current.Statements[i].Data);
	}
	printf("\n\n");
	printf("  Comments(%d)\n", current.ComSize);
	int SIZE = current.ComSize;
	int Index = 1;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(current.Comments[i], "\n") != 0)
		{
			printf("      %d)", (Index));
			printf("%s\n", current.Comments[i]);
			Index++;
		}
		else
			SIZE++;
	}
	printf("\n");
}

void Functionality(int* Choice)
{
	printf("Options:\n");
	printf("0-To finish program\n");
	printf("1-To see information about all elements\n");
	printf("2-To see certain element\n");
	printf("3-To search by theme\n");
	printf("4-To search by language\n");
	printf("Your value:");
	scanf_s("%d", *&Choice);
	if (*Choice < 0 || *Choice>4)
		*Choice = -1;
}

void CommnetFunctionality(int* Choice)
{
	printf("Comment Options:\n");
	printf("0-To go back\n");
	printf("1-To delete comment\n");
	printf("2-To add comment (only 5 are avelaible)\n");
	printf("3-To redact comment\n");
	printf("Your value:");
	scanf_s("%d", *&Choice);
	if (*Choice < 0 || *Choice>3)
		*Choice = -1;
}

void GetAllInfo(DataBaseElement* dataBase, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		ShowInfo(&dataBase[i], i);
	}
}

void SortByTheme(DataBaseElement* database, int SIZE)
{
	char Theme[25];
	printf("Enter theme:");
	fgets(Theme, 25, stdin);
	fgets(Theme, 25, stdin);
	fflush(stdin);
	system("cls");
	int Counter = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(database[i].sourceCode->Theme,Theme)==0)
		{
			GetElemInfo(database[i], i);
			Counter++;
			printf("-------------------------------------------------------------------------\n");//58
		}
	}
	if (Counter == 0)
	{
		printf("No element with such theme...\n");
		return;
	}
}

void SortByLanguage(DataBaseElement* database, int SIZE)
{
	char Language[25];
	printf("Enter language:");
	fgets(Language, 25, stdin);
	fgets(Language, 25, stdin);
	fflush(stdin);
	system("cls");
	int Counter = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(database[i].sourceCode->Language,Language)==0)
		{
			GetElemInfo(database[i], i);
			Counter++;
			printf("-------------------------------------------------------------------------\n");
		}
	}
	if (Counter == 0)
	{
		printf("No element with such language...\n");
		return;
	}
}

void DeleteComment(DataBaseElement* current)
{
	char temp = '1';
	int index = -1;
	if (current->ComSize != 0)
	{
		printf("Enter the index of comment:");
		scanf_s("%d", &index);
		if (index <= 0 || current->ComSize < index)
		{
			printf("Wrong value....\n");
			scanf_s("%c", &temp, 1);
			scanf_s("%c", &temp, 1);
			return;
		}
		else
		{
			strcpy(current->Comments[index - 1], "\n");
			current->ComSize--;
		}
	}
	else
	{
		printf("No comments to delete\n");
		scanf_s("%c", &temp, 1);
		scanf_s("%c", &temp, 1);
	}
}

void AddComment(DataBaseElement* current)
{
	char temp = '1';
	if (current->ComSize <= 4)
	{
		printf("Enter new comment:");
		fgets(current->Comments[current->ComSize], 500, stdin);
		fgets(current->Comments[current->ComSize], 500, stdin);
		for (int i = 0; i < 500; i++)
		{
			if (current->Comments[current->ComSize][i] == '\n')
			{
				current->Comments[current->ComSize][i] = '\0';
				break;
			}
		}
		fflush(stdin);
		current->ComSize++;
	}
	else
	{
		printf("The limit of comments\n");
		scanf_s("%c", &temp,1);
		scanf_s("%c", &temp, 1);
	}
}

void RedactComment(DataBaseElement* current)
{
	char temp = '1';
	int index = -1;
	if (current->ComSize != 0)
	{
		printf("Enter the index of comment:");
		scanf_s("%d", &index);
		if (index <= 0||current->ComSize<index)
		{
			printf("Wrong value....\n");
			scanf_s("%c", &temp, 1);
			scanf_s("%c", &temp, 1);
			return;
		}
		else
		{
			system("cls");
			printf("Enter the new comment (%d):", index);
			fgets(current->Comments[index-1], 500, stdin);
			fgets(current->Comments[index-1], 500, stdin);
			for (int i = 0; i < 500; i++)
			{
				if (current->Comments[index - 1][i] == '\n')
				{
					current->Comments[index - 1][i] = '\0';
					break;
				}
			}
			fflush(stdin);
		}
	}
	else
	{
		printf("No comments to redact\n");
		scanf_s("%c", &temp, 1);
		scanf_s("%c", &temp, 1);
	}
}
