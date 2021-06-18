#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>


int Length(char str[]) {
	int i = 0;
	while (str[i] != '\n' && str[i] != '\0') {
		i++;
	}
	return i;
}

int WordCheck(char word[], char buff[]) {
	for (int i = 0; i < Length(word); i++) {
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

	puts("������� ������ �����, ������� ����������� ������� ������ �������������� ");
	gets(word);

	FILE* file;
	file = fopen("dictionary.txt", "r");

	puts("���������� � ��������� ���������: ");

	while (fgets(buffer, 128, file) != NULL) {
		if (Length(word) == Length(buffer))
			if (WordCheck(word, buffer) == 1) {
				printf(buffer);
			}
	}

	fclose(file);
}