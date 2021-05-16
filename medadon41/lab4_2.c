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
	char buffer[128];
	char word[128];

	puts("������� �����, ������� ���� �����: ");
	gets(word);

	FILE* fp;
	fp = fopen("russian.txt", "r");

	puts("���������� ��������: ");
	
	while (fgets(buffer, 128, fp) != NULL) {
		if (Length(word) == Length(buffer))
			if (WordCheck(word, buffer) == 1) {
				printf(buffer);
			}
	}
	
	fclose(fp);
}