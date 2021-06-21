//lab4 task 4.1(22)
#include <stdio.h>
#include <math.h>
#include <locale.h>
void setString(char* str)
{
	char ch;
	puts("Enter a string of words no longer than 254 characters: \n");
	int toCap = 1;
	int i = 0;
	while ((ch = getchar()) != '\n')
	{
		switch (ch)
		{
		case '.':
		case '!':
		case '?':
			toCap = 1;
			str[i++] = ' ';
			str[i++] = ch;
			str[i++] = ' ';
			break;
		case ' ': str[i++] = ch; break;
		default:
			if (toCap)
			{
				str[i++] = toupper(ch);
				toCap = 0;
			}
			else str[i++] = ch;
		}
	}
	str[i] = '\0';
}
void ShowWords(char* word[255], int k)
{
	char wordcheckone[255], wordchecktwo[255];
	for (int i = 0; i < k; i++)
	{
		switch (word[i][0])
		{
		case '.':
		case '!':
		case '?':  printf("%s", word[i]); i++; break;
		}
		if (i + 1 != k)
		{
			strcpy(wordcheckone, word[i]);
			strcpy(wordchecktwo, word[i + 1]);
			wordcheckone[0] = tolower(wordcheckone[0]);
			wordchecktwo[0] = tolower(wordchecktwo[0]);
			if (strcmp(wordcheckone, wordchecktwo) == 0)
			{
				word[i + 1][0] = toupper(word[i + 1][0]);
			}
			else
			{
				printf(" %s", word[i]);
			}

		}
		else
		{
			printf(" %s", word[i]);
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	char str[255];
	setString(str);
	char* word[255];
	int k = 0;
	char separator[] = " ,;:", * p;
	p = strtok(str, separator);
	while (p)
	{
		word[k++] = p; //запомнить в массиве
		p = strtok(NULL, separator); // p указывает на следующее слово
	}
	ShowWords(word, k);

}
//privet privet Kirill Kirill. poka poka moy rodnoy - test Text
//privet privet Kirill Kirill. poka poka moy rodnoy - test Text