#include <stdio.h>
#include <malloc.h>

bool anagrams_cmp(char*, char*);
char** collect_words(const char*, int&);
void print_anagrams(char**, int);

int main()
{
	int n;
	char** words = collect_words("input.txt", n);
	if (words == NULL) return 0;

	// Output words
	printf("Words:");
	for (int i = 0; i < n; i++) printf(" %s", words[i]);
	printf("\n\n");

	print_anagrams(words, n);
	printf("\n");

	// Clear memory
	for (int i = 0; i < n; i++) free(words[i]);

	return 0;
}

char** collect_words(const char* file_name, int& n)
{
	// Open file
	FILE* fp;
	fopen_s(&fp, file_name, "r");
	if (!fp)
	{
		printf("File open error.");
		return NULL;
	}

	// Count words
	n = 0;
	char chr, chr_before;

	chr = chr_before = fgetc(fp);
	while (chr != EOF)
	{
		chr = fgetc(fp);
		if (chr_before != ' ' && chr_before != '\n' && chr_before != '\t' && chr_before != EOF && (chr == ' ' || chr == '\n' || chr == EOF)) n++;
		chr_before = chr;
	}

	if (n == 0)
	{
		printf("No words.");
		fclose(fp);
		return NULL;
	}

	// Collect words
	char** words = (char**)malloc(n * sizeof(char*));
	n = 0;
	char* wrd = (char*)malloc(32 * sizeof(char));
	int k = 0;

	rewind(fp);
	chr = fgetc(fp);
	while (chr != EOF)
	{
		if (chr != ' ' && chr != '\n' && chr != '\t')
		{
			wrd[k] = chr;
			k++;
		}
		else
		{
			if (k > 0)
			{
				words[n] = (char*)malloc((k + 1) * sizeof(char));
				for (int i = 0; i < k; i++) words[n][i] = wrd[i];
				words[n][k] = '\0';
				n++;
			}
			k = 0;
		}
		chr = fgetc(fp);
	}
	if (k > 0)
	{
		words[n] = (char*)malloc((k + 1) * sizeof(char));
		for (int i = 0; i < k; i++) words[n][i] = wrd[i];
		words[n][k] = '\0';
		n++;
	}
	fclose(fp);
	free(wrd);

	if (n == 0)
	{
		printf("Words read error.");
		return NULL;
	}

	return words;
}

bool anagrams_cmp(char* str1, char* str2)
{
	int len1, len2;

	for (len1 = 0; str1[len1] != '\0'; len1++);
	for (len2 = 0; str2[len2] != '\0'; len2++);

	if (len1 != len2) return false;

	for (int i = 0; i < len1; i++)
		if (str1[i] != str2[len1 - i - 1]) return false;

	return true;
}

void print_anagrams(char** words, int n)
{
	printf("Anagrams:");
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n && words[i]; j++)
		{
			if (words[i] && words[j] && anagrams_cmp(words[i], words[j]))
			{
				printf(" (%s %s)", words[i], words[j]);

				for (int l = j + 1; l < n; l++)
				{
					if (words[l] && anagrams_cmp(words[l], words[i])) words[l] = NULL;
					if (words[l] && anagrams_cmp(words[l], words[j])) words[l] = NULL;
				}
				words[i] = NULL;
				words[j] = NULL;
			}

		}
	}
}
