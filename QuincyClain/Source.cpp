// 5.2(14)
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#include <locale.h>
#include <string>
struct Tree {
	char word[100];
	int n;
	Tree* right;
	Tree* left;
};
void Push(Tree** head) {
	FILE* f;
	Tree* s, * s1;
	char c;
	char word[100];
	if (!(f = fopen("file.txt", "r"))) { // открываем файл(надо создать file.txt) с английским 
		printf("errror\n");
		return;

	}
	int i = 0;

	while (1) {
		fscanf(f, "%c", &c);
		while (c != ' ' && c != '\0') { 
			if (feof(f)) { 
				break;
			}
			word[i] = c;
			i++;
			fscanf(f, "%c", &c);
		}
		word[i] = '\0';
		i = 0;
		if (!(s1 = (Tree*)calloc(1, sizeof(Tree)))) {
			printf("Error");
			return;
		}
		strcpy(s1->word, word);
		if (!(*head)) {
			(*head) = s1;
			(*head)->n = 0;
			(*head)->left = (*head)->right = nullptr;
		}
		else {
			s = *head;
			while (s) {
				if (!strcmp(s->word, s1->word)) {
					s->n++;
					break;
				}
				else if (strcmp(s->word, s1->word) > 0) {
					if (s->left == nullptr) {
						s->left = s1;
						s1->n = 0;
						s1->left = s1->right = nullptr;
						s = nullptr;
					}
					else {
						s = s->left;
					}
				}
				else {
					if (s->right == nullptr) {
						s->right = s1;
						s1->n = 0;
						s1->left = s1->right = nullptr;
						s = nullptr;
					}
					else {
						s = s->right;
					}
				}
			}
		}
		if (feof(f)) {
			break;
		}
	}
	fclose(f);
}
void recurs_output_symmetric(Tree* s) {
							
	char first, last;
	int i = 0;
	if (s) {

		if (s->left) {
			recurs_output_symmetric(s->left);

		}
		while (s->word[i]) {
			if (i == 0) {
				first = s->word[i];
			}
			if (s->word[i + 1] == '\0') {
				last = s->word[i];
			}
			i++;
		}
		if ((first == last) && i != 1) {
			printf("%s\n", s->word);
		}
		if (s->right) {
			recurs_output_symmetric(s->right);
		}

	}
	else {
		printf("No informations\n");
	}
}
void recurs_output_inorder(Tree* s) {
							
	char first, last;
	int i = 0;
	if (s) {
		while (s->word[i]) {
			if (i == 0) { 
				first = s->word[i];
			}
			if (s->word[i + 1] == '\0') {
				last = s->word[i];
			}
			i++;
		}
		if ((first == last) && i != 1) {
			printf("%s\n", s->word);
		}

		if (s->left) {
			recurs_output_symmetric(s->left);

		}
		if (s->right) {
			recurs_output_symmetric(s->right);
		}

	}
	else {
		printf("No informations\n");
	}
}
void recurs_output_postorder(Tree* s) {
							
	char first, last;
	int i = 0;
	if (s) {

		if (s->left) {
			recurs_output_symmetric(s->left);

		}
		if (s->right) {
			recurs_output_symmetric(s->right);
		}
		while (s->word[i]) {
			if (i == 0) {
				first = s->word[i];
			}
			if (s->word[i + 1] == '\0') {
				last = s->word[i];
			}
			i++;
		}
		if ((first == last) && i != 1) {
			printf("%s\n", s->word);
		}

	}
	else {
		printf("No informations\n");
	}
}
void Print(Tree* current)
{
	if (current)
	{
		printf("%s \n", current->word);
		Print(current->left);
		Print(current->right);
	
	}
}
int main() {
	system("chcp 1251>null");
	Tree* head = nullptr;
	Push(&head);
	setlocale(LC_ALL, "ru");
	while (true) {
		printf("1. Прямой обход\n");
		printf("2. Симметричный обход (по алфавиту)\n");
		printf("3. Обратный обход\n");
		printf("4. Выход\n");
		printf("5. Вывод всего файла\n");
		int n;
		scanf("%d", &n);
		system("cls");
		switch (n)
		{
		case 1: recurs_output_inorder(head);
			break;
		case 2: recurs_output_symmetric(head);
			break;
		case 3: recurs_output_postorder(head);
			break;
		case 4:
			return 0;
			break;
		case 5:
			Print(head);
			break;
			
		default:
			break;
		}
	}
	_getch();
	return 0;
}