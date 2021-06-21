//lab4 task 4.2(22)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
void setString(char* str, char* setstr)
{
	char ch;
	int i = 0, j = 0;
	ch = setstr[j];
	do
	{
		ch = setstr[j];
		switch (ch)
		{
		case '.':
		case ',':
		case ';':
		case ':':
		case '!':
		case '?':
		case ')':
		case ']':
		case '}':
		case '{':
		case '[':
		case '(':
			str[i++] = ' ';
			str[i++] = ch;
			str[i++] = ' ';
			break;
		default:  str[i++] = ch; break;
		}
		j++;
	} while (ch != '\0');
	str[i] = '\0';
}
int isLetter(char x)
{
	if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'))
	{
		return 1;
	}
	return 0;
}
void ShowWords(char* word[500], int k)
{

	for (int i = 0; i < k; i++)
	{
		if (i + 1 != k && isLetter(word[i][0]) && isLetter(word[i + 1][0])) 
		{
			printf("%s ", word[i]);
		}
		else if (i + 1 != k && word[i][0] == '.' && word[i + 1][0] == '.') // "..."
		{
			printf("%s", word[i]);
		}
		else
		{
			switch (word[i][0])
			{
			case '.':
			case ',':
			case ';':
			case ':':
			case '!':
			case '?':
			case ')':
			case ']':
			case '}':
				printf("%s ", word[i]); break;
			case '(':
			case '[':
			case '{': printf(" %s", word[i]); break;
			default: printf("%s", word[i]); break;
			}
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	char str[500];
	char setstr[500];
	FILE* fp;
	fp = fopen("open.txt", "r");
	if (!fp)
	{
		exit(1);
	}
	while (fgets(setstr, 500, fp) != NULL)
	{
		setString(str, setstr);
		char* word[500];
		int k = 0;
		char separator[] = " ", * p;
		p = strtok(str, separator);
		while (p)
		{
			word[k++] = p; 
			p = strtok(NULL, separator);
		}
		ShowWords(word, k);
	}

}
//og. ta aa.ww jk.iw]bw[bw]bw? - open.txt