#include <stdio.h>
#include <malloc.h>

int str_len(char*);

int main()
{
	int n;
	printf("Enter number of strokes: "); scanf_s("%d", &n); getchar();

	if (n > 0)
	{
		// Input strokes
		char** str = (char**)malloc(n * sizeof(char*));

		printf("Enter strokes:\n");
		for (int i = 0; i < n; i++)
		{
			str[i] = (char*)malloc(40 * sizeof(char));
			gets_s(str[i], 40);
		}

		// Count words number
		int k = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; str[i][j] != '\0'; j++)
				if (str[i][j] != ' ' && (str[i][j + 1] == ' ' || str[i][j + 1] == '\0')) k++;

		printf("\n%s%d\n", "Number of words: ", k);

		// Create array of words
		char** wrd = (char**)malloc(k * sizeof(char*));
		int len_k = 0;
		k = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; str[i][j] != '\0'; j++)
				if (str[i][j] != ' ')
				{
					len_k++;

					// If word ends
					if (str[i][j + 1] == ' ' || str[i][j + 1] == '\0')
					{
						wrd[k] = (char*)malloc((len_k + 1) * sizeof(char));
						for (int l = 0; l < len_k; l++)
						{
							wrd[k][l] = str[i][j - len_k + l + 1];
						}
						wrd[k][len_k] = '\0';
						k++;
						len_k = 0;
					}
				}
				else len_k = 0;

		// Sort words
		char* tmp;

		for (int i = 0; i < k - 1; i++)
			for (int j = i + 1; j < k; j++)
				if (str_len(wrd[i]) > str_len(wrd[j]))
				{
					tmp = wrd[i];
					wrd[i] = wrd[j];
					wrd[j] = tmp;
				}

		// Output words
		printf("\nWords:\n");
		for (int i = 0; i < k; i++) puts(wrd[i]);

		// Clear memory
		for (int i = 0; i < n; i++) free(str[i]);
		free(str);
		for (int i = 0; i < k; i++) free(wrd[i]);
		free(wrd);

	}
	else printf("No strokes");

	return 0;
}

int str_len(char* str)
{
	int len;
	for (len = 0; str[len] != '\0'; len++);
	return len;
}