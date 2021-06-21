#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int strLength(char* str) {
	int length = 0;
	int i = 0;
	while (str[i] != '\0') {
		length++;
		i++;
	}
	return length;
}

int checkWord(char word[], char buff[]) {
	for (int i = 0; i < strLength(word); i++) {
		if (word[i] == '_')
			continue;
		else if (word[i] != buff[i])
			return 0;
		else
			continue;
	}
	return 1;
}

int main() {
	system("chcp 1251");
	system("cls");
	char buffer[255];
	char word[255];

	puts("¬ведите шаблон слова, замен€€ пропущенные символы нижним подчЄркиванием ");
	gets(word);

	FILE* file;
	file = fopen("dictionary.txt", "r");

	puts("—овпадени€ в текстовом документе: ");

	while (fgets(buffer, 128, file) != NULL) {
		if (strLength(word) == strLength(buffer))
			if (checkWord(word, buffer) == 1) {
				printf(buffer);
			}
	}

	fclose(file);
}