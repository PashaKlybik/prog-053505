#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>

typedef struct {
	char* language;
	char* subjects;
	char* code;
	char* article;
	char* comment;
	int  dateAdded;
} Manager;

typedef struct {
	Manager* manager;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct {
	Node* head;
	Node* tail;
	int count;
} List;

List* catalog;

void create(List* list) {
	list->count = 0;
	list->head = NULL;
	list->tail = NULL;
}

void push(Manager* temp) {
	Node* newNode = (Node*)malloc(sizeof(Manager));
	newNode->next = NULL;
	newNode->manager = temp;

	if (catalog->head == NULL)
	{
		catalog->head = newNode;
		catalog->tail = newNode;
	}
	else
	{
		catalog->tail->next = newNode;
		newNode->prev = catalog->tail;
		catalog->tail = newNode;
	}

	catalog->count++;
}

char* read(FILE* file) {
	char buffer[256];
	fgets(buffer, 256, file);
	int lenght = strlen(buffer);
	buffer[lenght - 1] = '\0';
	char* string = (char*)calloc(++lenght, sizeof(char));
	if (string == NULL)
	{
		exit(-1);
	}
	strcpy_s(string, lenght, buffer);
	return string;
}

Manager* managerRead(FILE* file) {
	char buffer[256];
	Manager* temp = (Manager*)malloc(sizeof(Manager));
	temp->language = read(file);
	temp->subjects = read(file);
	temp->code = read(file);
	temp->article = read(file);
	temp->comment = read(file);
	fgets(buffer, 256, file);;
	temp->dateAdded = atoi(buffer);
	return temp;
}

void showList() {
	system("cls");
	Node* temp = catalog->head;
	int  choice = 0;
	printf("1.Programming languages\n");
	printf("2.Articles\n");
	printf("3.Subjects\n");

	while (!scanf("%d", &choice) || choice <= 0 || choice > 3) {
		printf("Incorrect input \n");
		while (getchar() != '\n');
	}
	int count = 0;
	system("cls");
	while (temp) {
		printf("%d.", ++count);
		if (choice == 1)
			printf("%s\n", temp->manager->language);
		else if (choice == 2)
			printf("%s\n", temp->manager->article);
		else if (choice == 3)
			printf("%s\n", temp->manager->subjects);
		temp = temp->next;
	}
}

void addComment(Manager* temp) {
	char string[256];
	char result[256];
	printf("Enter comment (max. 256):\n");
	scanf("%s", string, 256);
	sprintf(result, "%s %s", temp->comment, string);
	free(temp->comment);
	temp->comment = (char*)calloc(strlen(result), sizeof(char));
	if (temp->comment == NULL)
		printf("Error");
	for (int i = 0; i < strlen(result); i++)
		temp->comment[i] = result[i];
}

Manager* Search(Node* head, char* search) {
	Node* temp = head;
	while (temp) {
		int k = strlen(search);
		for (int i = 0; i < strlen(search); i++) {
			if (search[i] == temp->manager->code[i])
				k--;
		}
		if (k == 0) return temp->manager;
		temp = temp->next;
	}
	return NULL;
}

void Catalog(Node* head) {
	Node* temp = head;
	while (temp) {
		printf("%s\n", temp->manager->language);
		printf("%s\n", temp->manager->subjects);
		printf("%s\n", temp->manager->code);
		printf("%s\n", temp->manager->article);
		printf("%s\n", temp->manager->comment);
		printf("%d\n\n", temp->manager->dateAdded);
		temp = temp->next;
	}
}

void del(Node* head) {
	Node* temp;
	while (head) {
		temp = head;
		free(head->manager->article);
		free(head->manager->code);
		free(head->manager->comment);
		free(head->manager->language);
		free(head->manager->subjects);
		free(head->manager);
		head = head->next;
		free(temp);

	}
}

void Menu() {
	int n = 0;
	printf("\n\tMenu\n");
	printf("1.Catalog\n");
	printf("2.Add a comment\n");
	printf("3.Edit comment\n");
	printf("4.View source\n");
	printf("5.Save\n");
	printf("6.View article\n");
	printf("7.View code\n");
	printf("8.Exit\n\n");

	while (!scanf("%d", &n) || n <= 0 || n > 8) {
		printf("Incorrect input\n");
		while (getchar() != '\n');
	}
	switch (n) {
	case 1: {
		showList();
		break;
	}

	case 2: {
		char code[20];
		printf("Code to comment\n");
		scanf("%s", code, 20);
		Manager* search = Search(catalog->head, code);
		if (search == NULL){
			printf("Incorrect code\n");
		}
		else{
			addComment(search);
			system("cls");
			printf("comment added");
		}
		break;
	}

	case 3: {
		char buf[100];
		char code[20];
		printf("Code to comment\n");
		scanf("%s", code, 20);
		printf("Enter new comment\n");
		scanf("%s", buf, 100);	
		Manager* search = Search(catalog->head, code);
		if (search == NULL) {
			printf("Incorrect code\n");
		}
		else {
			free(search->comment);
			search->comment = (char*)calloc(strlen(buf), sizeof(char));
			memset(search->comment, 0, strlen(buf));
			for (int i = 0; i < strlen(buf); i++)
				search->comment[i] = buf[i];
		}
		break;
	}

	case 4: {
		system("cls");
		Catalog(catalog->head);
		break;
	}
	case 5: {
		int flag = 0;
		FILE* save;
		errno_t err = fopen_s(&save, "catalogS.txt", "w+");
		if (err != 0) {
			printf("File error");
			exit(-1);
		}
		Node* temp = catalog->head;
		while (temp) {
			if(flag++ != 0){
				fprintf(save, "\n");
			}
			fprintf(save, "%s\n", temp->manager->language);
			fprintf(save, "%s\n", temp->manager->subjects);
			fprintf(save, "%s\n", temp->manager->code);
			fprintf(save, "%s\n", temp->manager->article);
			fprintf(save, "%s\n", temp->manager->comment);
			fprintf(save, "%d", temp->manager->dateAdded);
			temp = temp->next;	
		}
		printf("Saved\n");
		fclose(save);
		break;
	}
	case 6: {
		system("cls");
		FILE* article;
		int count = 0, choice;
		Node* temp = catalog->head;
		while (temp) {
			printf("%d.", ++count);
			printf("%s\n", temp->manager->article);
			temp = temp->next;
		}
		while (!scanf("%d", &choice) || choice <= 0 || choice > count) {
			printf("Incorrect input \n");
			while (getchar() != '\n');
		}
		count = 1;
		temp = catalog->head;
		while(choice != count){
			temp = temp->next;
			count++;
		}
		char path[256];
		sprintf(path, "%s%s", "Article/", temp->manager->article);
		errno_t err = fopen_s(&article, path, "rt");
		if (err != 0) {
			printf("Error");
			return;
		}
		char line[256];
		while(fgets(line, 256, article) != NULL) {
	 		printf ("%s", line);
   		}
		fclose(article);
		break;
	}
	case 7: {
		system("cls");
		FILE* code;
		int count = 0, choice;
		Node* temp = catalog->head;
		while (temp) {
			printf("%d.", ++count);
			printf("%s\n", temp->manager->code);
			temp = temp->next;
		}
		while (!scanf("%d", &choice) || choice <= 0 || choice > count) {
			printf("Incorrect input \n");
			while (getchar() != '\n');
		}
		count = 1;
		temp = catalog->head;
		while(choice != count){
			temp = temp->next;
			count++;
		}
		char path[256];
		sprintf(path, "%s%s", "Source/", temp->manager->code);
		errno_t err = fopen_s(&code, path, "rt");
		if (err != 0) {
			printf("Error");
			return;
		}
		char line[256];
		while(fgets(line, 256, code) != NULL) {
	 		printf ("%s", line);
   		}
		fclose(code);
		break;
	}

	case 8: {
		del(catalog->head);
		free(catalog);
		system("cls");
		exit(1);
		break;
	}
	}
}

int main() {
	catalog = (List*)malloc(sizeof(List));
	create(catalog);
	FILE* mycatalog;
	errno_t err = fopen_s(&mycatalog, "catalogS.txt", "r+");
	if (err != 0) {
		err = fopen_s(&mycatalog, "catalog.txt", "r+");
		if(err != 0){
			printf("File error");
			return -1;
		}
	}
	while (!feof(mycatalog))
		push(managerRead(mycatalog));
	fclose(mycatalog);
	while (1)
		Menu();
}