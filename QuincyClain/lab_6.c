// 5.2(14)
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#include <locale.h>
#include <string>
struct Tree { // Просто дерево. n = это количество повторов
	char word[100];
	int n;
	Tree* right;
	Tree* left;
};
void Push(Tree** head) { // тут создаём дерево
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
		fscanf(f, "%c", &c); // читаем посимвольно
		while (c != ' ' && c != '\0') {  // этот цикл пока не встретим в файле пробел записываем
			if (feof(f)) { // в word слово 
				break;
			}
			word[i] = c;
			i++;
			fscanf(f, "%c", &c);
		}
		word[i] = '\0'; // чтобы нормально работали функции string
		i = 0;
		if (!(s1 = (Tree*)calloc(1, sizeof(Tree)))) {
			printf("Error");
			return;
		}
		strcpy(s1->word, word);
		if (!(*head)) { // создаём голову( корень ) дерева
			(*head) = s1;
			(*head)->n = 0;
			(*head)->left = (*head)->right = nullptr;
		}
		else {
			s = *head; // ставим указатель чтобы пробегать по дереву и не изменять указатель на голову
			while (s) {
				if (!strcmp(s->word, s1->word)) { // если такое уже есть то просто увеличиваем n
					s->n++;
					break;
				}
				else if (strcmp(s->word, s1->word) > 0) { // если слово раньше по алфавиту то двигаемся в лево
					if (s->left == nullptr) { // если мы нашли куда можем добавлять
						s->left = s1;
						s1->n = 0;
						s1->left = s1->right = nullptr;
						s = nullptr; // чтобы выйти из цикла
					}
					else {
						s = s->left; // если слева ещё что-то есть то передвигаемся влево
					}
				}
				else {
					if (s->right == nullptr) { // то же самое что выше, но справа
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
		if (feof(f)) {// если конец файла
			break;
		}
	}
	fclose(f); //закрываем файл по окончанию
}
void recurs_output_symmetric(Tree* s) { //вывод слов с одинаковой первой и последней буквой(это симетричный вывод
							//так как он выводит по алфавиту из-за особенностей бинарного дерева)
							
	char first, last; // в эти переменные запомним первую и последнюю букву
	int i = 0;
	if (s) {

		if (s->left) {
			recurs_output_symmetric(s->left);

		}
		while (s->word[i]) {
			if (i == 0) {
				first = s->word[i];
			}
			if (s->word[i + 1] == '\0') { // если последняя буква то мы проверяем является ли следующий символ '\0'
				last = s->word[i];
			}
			i++;
		}
		if ((first == last) && i != 1) { // если последняя и первая буквы одинаковые и это слово не состоит из одной буквы
			printf("%s\n", s->word);
		}
		if (s->right) {
			recurs_output_symmetric(s->right);
		}

	}
	else {   // если дерева нет
		printf("No informations\n");
	}
}

// далее два других обхода прямой и обратный точно так же.
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
void Print(Tree* current) // вывод всех файлов прямым обходом без условия на равенство первой и последней буквы
{
	if (current)
	{
		printf("%s \n", current->word);
		Print(current->left);
		Print(current->right);
	
	}
}

void free_all(Tree* s) {  // очистка памяти!!!
	if (s) {
		if (s->left) {

			free_all(s->left);

		}

		if (s->right) {

			free_all(s->right);
		}
		free(s);
	}
	else {
		printf("No informations\n");
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
	free_all(head); // очищаем память.
	_getch();
	return 0;
}