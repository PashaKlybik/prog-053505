#define _CRT_SECURE_NO_WARNINGS
#define CST_WORD_LEN 128
#include <stdio.h>
#include <conio.h>
#include<stdbool.h>

char* PROIZ = "proiz.txt";
char* Vocabulary = "zamena.txt";
char* RESULT = "result.txt";

bool proverkaizam(char* textto, char* per, char* vtor)
{
	int i = 0;
	bool z = false;
	do {
		if (textto[i] == '\0' && per[i] != '\0')
		{
			z = false;
			break;
		}
		if (textto[i] != '\0' && per[i] == '\0')
		{
			z = false;
			break;
		}
		if (textto[i] == per[i])
		{
			if (textto[i] == '\0')
				break;
			z = true;
			i++;
		}
		else
		{
			z = false;
			break;
		}

	} while (i < (CST_WORD_LEN - 1));
	i = 0;
	if (z == true)
	{
		while (i< (CST_WORD_LEN - 1) && vtor[i] != '\0')
		{
		     textto[i] = vtor[i];
			textto[i + 1] = '\0';
			i++;
		}
	}
	return z;
}

void Proverka(char* word)
{
	char per[CST_WORD_LEN];
	char vtor[CST_WORD_LEN];
	bool found = false;

	FILE* Zamena = fopen(Vocabulary, "rt");
	if (!Zamena)
	{
		printf("\nError,couldn't open %s", Vocabulary);
		_getch();
		return;
	}
	while (!feof(Zamena) && found == false)
	{
		fscanf(Zamena, "%s %s\n", per, vtor);
		found = proverkaizam(word, per, vtor);
	}
	fclose(Zamena);

}
void Result(char* word)
{
	FILE* result1= fopen(RESULT, "at");
	if (!result1)
	{
		printf("\n Error Couldn't open %s", RESULT);
		_getch();
		return;
	}
	fprintf(result1, " %s ", word);
	fclose(result1);

}
void read(char* word)
{
	char symbol = '\0';
	int index = 0;
	FILE* OriginFile = fopen("proiz.txt", "rt");
	if (!OriginFile)
	{
		printf("\n Error Couldn't open %s", PROIZ);
		_getch();
		return;
	}


	while (!feof(OriginFile))
	{
		fscanf(OriginFile, "%s", word);
		Proverka(word);
		Result(word);
	}
	fclose(OriginFile);
	return;
}

int main()
{
	char Word[CST_WORD_LEN];
	fclose(fopen("result.txt", "wt"));
	read(Word);
	return 0;
}

