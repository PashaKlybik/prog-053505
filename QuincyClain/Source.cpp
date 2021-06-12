#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>

struct _Code {
	char* code;
};
 struct _Title {
	char Language[50];
	char Theme[50];
	char date[50];
};
 struct _Comments {
	char comment[1000];
};
 struct Node {
	_Code code;
	_Title title;
	_Comments comments;
	Node* next;
	Node* prev;

};
 Node* searchLanguage(Node* head, char* s) {

	do{
		if (!strcmp(s, head->title.Language)){
			return head;
		}
		if (head->next == NULL){
			break;
		}
		head = head->next;
	} while (1);
	return NULL;
}
Node* searchTheme(Node* head){
	int i = 1;
	Node* c = head;
	do{
		printf("%d %s\n", i, c->title.Theme);
		i++;
		if (c->next == NULL){
			break;
		}
		c = c->next;
	} while (1);
	int choice;
	do{
	printf("\nВыберите тему\n");
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		return head;
		break;
	case 2:
		return head->next;
		break;
	case 3:
		return head->next->next;
		break;
	}
	}while (1);
	
} // считать по пробелам и потом выводить с нумерацией и потом искать по цифре, a потом смещать всё что дальше
void deleteCom(Node* head){
	int i = 1;
	Node* c = head;
	do{
		printf("%d %s\nКомментарий: %s\n", i, c->title.Theme,c->comments.comment);
		i++;
		if (c->next == NULL){
			break;
		}
		c = c->next;
	} while (1);
	int choice;
	
	printf("\nВыберите тему\n");
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		head->comments.comment[0] = '\0'; 
		break;
	case 2:
		head->next->comments.comment[0] = '\0';
		break;
	case 3:
		head->next->next->comments.comment[0] = '\0';
		break;
	}
}
void gets_max(char* name, int n) {
	int i = 0;
	char c;
	do {
		rewind(stdin);
		i = 0;
		c = ' ';
		int error = 0;
		while (c != '\n') {
			scanf("%c", &c);

			if (c != '\n') {
				name[i] = c;
				i++;
			}
			if (i > n) {
				printf("error\n");
				error = 1;
				break;
			}
		}
		if (error == 0) {
			break;
		}
	} while (1);
	name[i] = '\0';
}
Node* inf(Node* current, FILE* f) {
	char* string;

	string = (char*)calloc(1000, sizeof(char)); 
	char c = ' ';
	int i = 0;
	while (1) {
		fscanf(f, "%c", &c);
		while (c != '\n') {
			fscanf(f, "%c", &c);
		}
		fscanf(f, "%c", &c);
		while (1) {
			string[i] = c;
			if (c == '/') {
				fscanf(f, "%c", &c);
				break;
			}
			fscanf(f, "%c", &c);
			i++;
		}
		string[i] = '\0';
		current->code.code = (char*)calloc(1000, sizeof(char));
		strcpy(current->code.code, string);
		i = 0;
		fscanf(f, "%c", &c);
		while (c != '\n') {
			fscanf(f, "%c", &c);
		}
		fscanf(f, "%c", &c);
		fscanf(f, "%c", &c);
		fscanf(f, "%c", &c);
		fscanf(f, "%c", &c);
		while (1) {
			string[i] = c;
			if (c == ';') {
				fscanf(f, "%c", &c);
				fscanf(f, "%c", &c);
				break;
			}
			fscanf(f, "%c", &c);
			i++;
		}
		string[i] = '\0';
		strcpy(current->title.Language, string);
		i = 0;
		fscanf(f, "%c", &c);
		fscanf(f, "%c", &c);
		fscanf(f, "%c", &c);
		while (1) {
			string[i] = c;
			if (c == ';') {
				fscanf(f, "%c", &c);
				fscanf(f, "%c", &c);
				break;
			}
			fscanf(f, "%c", &c);
			i++;
		}
		string[i] = '\0';
		strcpy(current->title.Theme, string);
		i = 0; 
		fscanf(f, "%c", &c);
		fscanf(f, "%c", &c);
		fscanf(f, "%c", &c);
		while (1) { 
			string[i] = c;
			if (c == ';') {
				fscanf(f, "%c", &c);
				fscanf(f, "%c", &c);
				break;
			}
			fscanf(f, "%c", &c);
			i++;
		}
		string[i] = '\0';
		strcpy(current->title.date, string);
		i = 0;
		if (feof(f)) {
			break;
		}
	}
	return current;
}
void create(Node** head, Node** tail) {
	Node* current, *current1, *current2;

	FILE* f;
	if (!(current = (Node*)calloc(1, sizeof(Node)))) {
		printf("Error\n");
	}
	if (!(current1 = (Node*)calloc(1, sizeof(Node)))) {
		printf("Error\n");
	}
	if (!(current2 = (Node*)calloc(1, sizeof(Node)))) {
		printf("Error\n");
	}
	current->next = current->prev = NULL;
	current1->next = current1->prev = NULL;
	current2->next = current2->prev = NULL;
	if ((f = fopen("java.txt", "r")) == NULL) {
		printf("Error\n");
		return;
	}

	current = inf(current, f);
	if (!(*head) && !(*tail)) {
		(*head) = (*tail) = current;
		(*head)->prev = (*head)->next = NULL;
		(*tail)->prev = (*tail)->next = NULL;
	}
	else {
		current->prev = (*tail);
		(*tail)->next = current;
		(*tail) = current;
	}
	fclose(f);
	if (!(f = fopen("c.txt", "r"))) {
		printf("Error\n");
		return;
	}
	current1 = inf(current1, f);
	if (!(*head) && !(*tail)) {
		(*head) = (*tail) = current1;
		(*head)->prev = (*head)->next = NULL;
		(*tail)->prev = (*tail)->next = NULL;
	}
	else {
		current1->prev = (*tail);
		(*tail)->next = current1;
		(*tail) = current1;
	}
	fclose(f);
	if (!(f = fopen("python.txt", "r"))) {
		printf("Error\n");
		return;
	}
	current2 = inf(current2, f);
	if (!(*head) && !(*tail)) {
		(*head) = (*tail) = current2;
		(*head)->prev = (*head)->next = NULL;
		(*tail)->prev = (*tail)->next = NULL;
	}
	else {
		current2->prev = (*tail);
		(*tail)->next = current2;
		(*tail) = current2;
	}
	fclose(f);

}
void output(Node* head) {
	do {
		printf("\nИсходник\n");
		printf("%s", head->code.code);
		printf("\nСтатья\n");
		printf("Язык: %s", head->title.Language);
		printf("\n");
		printf("Тема: %s", head->title.Theme);
		printf("\n");
		printf("Дата создания: %s", head->title.date);
		if(head->comments.comment){
			printf("\nКомментарии: %s", head->comments.comment);
		}
		printf("\n");
		if (head->next == NULL) {
			break;
		}
		head = head->next;
	} while (1);
}
void one_output(Node* head){
		printf("\nИсходник\n");
		printf("%s", head->code.code);
		printf("\nСтатья\n");
		printf("Язык: %s", head->title.Language);
		printf("\n");
		printf("Тема: %s", head->title.Theme);
		printf("\n");
		printf("Дата создания: %s", head->title.date);
		if(head->comments.comment){
			printf("\nКомментарии: %s", head->comments.comment);
		}
}
void add(char* s1,char* s2, int i){
	int j = 0;
	while(s2[j]){
		s1[i] = s2[j];
		i++;
		j++;
	}
}
void addComments(Node* head){
	char string[1000];
	char prog[50];
	printf("Введите язык программирования\n");
	gets_max(prog, 50);
	head = searchLanguage(head, prog);
	if(!head){
		return;
	}
	int i = 0;
	while(head->comments.comment[i]){
		i++; 
	}
	head->comments.comment[i] = '\n';
	i++;
	printf("\nВведите комментарий\n");
	gets_max(string, 1000);
	add(head->comments.comment, string,i);
}

void RewriteComment(Node* head){
	char string[1000];
	char dop[1000];
	char prog[50];
	printf("Введите язык программирования\n");
	gets_max(prog, 50);
	head = searchLanguage(head, prog);
	if(!head){
		return;
	}
	int i = 0, n, i1 = 0, i2 = 0, i3 = 0;;
	int j = 0;
	while(head->comments.comment[i]){
		printf("%c", head->comments.comment[i]);
		if(head->comments.comment[i] == '\n'){
			printf("%d: ", j+1);
			j++;
		}
		i++;
	}
	i = 0;
	
	printf("\nВведите номер комментария который хотите перезаписать\n");
	while(!scanf("%d",&n)){
		rewind(stdin);
	}
	if(j<n){
		printf("Такого комментария нет\n");
		return;
	}
	j= 1;
	while (head->comments.comment[i]) {
		if(i==0 && n==1){
			i1 = 0;
			break;
		}
		if (head->comments.comment[i] == '\n') {
			if (n == j) {
				i1 = i + 1; // номер первого символа следующего комента
			}
			j++;
		}
		i++;
	}
	
	printf("Введите новый комментарий\n");
	gets_max(string, 1000);
	j = 0;
	char c;
	if(i1 == 0){
		head->comments.comment[i1] = '\n';
		i1++;
	}
	while(string[j]){
		if(head->comments.comment[i1] == '\n' || head->comments.comment[i1] == '\0'){
			i3 = i1 + 1;
			i = 0;
			while(head->comments.comment[i3]){
				dop[i] = head->comments.comment[i3];
				i++;
				i3++;
			}
			dop[i] = '\0';
		}
		head->comments.comment[i1] = string[j];

		i1++;
		j++;
	}
	if (head->comments.comment[i1]) {
		head->comments.comment[i1] = '\n';
	}
	
	i1++;
	if (i3 != 0) {
		add(head->comments.comment, dop, i1);
		return;
	}
	i = i1;
	while(head->comments.comment[i] !='\n' && head->comments.comment[i] != '\0'){
		i++;
	}
	if(head->comments.comment[i] == '\0'){
		i1--;
		head->comments.comment[i1] = '\0';
		return;
	}
	else{
	i2 = i + 1;
	}
	while(head->comments.comment[i2]){
		c = head->comments.comment[i1];
		head->comments.comment[i1] = head->comments.comment[i2];
		head->comments.comment[i2] = c; 
		i1++;
		i2++;
	}
	head->comments.comment[i2-1] = '\0';
}









int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	int New;
	Node* head = NULL;
	Node* tail = NULL;
	Node* prosto;
	create(&head, &tail);
	char string[100];

	while (1)
	{
		printf("\n\t\t\tSource Mannager\n");
		
		printf("1.Вывести список исходников\n");
		printf("2.Добавить комментарий\n");
		printf("3.Редактировать комментарий\n");
		printf("4.Удалить комментарий\n");
		printf("5.Выбрать исходник по тематике\n");
		printf("6.Выбрать исходник по языку\n");
		printf("7.Выйти из программы\n");

		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			output(head);
			break;
		case 2:
			system("cls");
			addComments(head);
			break;
		case 3:
			system("cls");
			RewriteComment(head);
			break;
		case 4:
			system("cls");
			deleteCom(head);
			break;
		case 5:
			system("cls");
			prosto = searchTheme(head);
			one_output(prosto);
			break;
		case 6:
			system("cls");
			printf("Введите название языка\n");
			gets_max(string, 100);
			prosto = searchLanguage(head,string);
			one_output(prosto);
			break;
		case 7:
			return 0;
			break;
		default:
			break;
		}
	}
}