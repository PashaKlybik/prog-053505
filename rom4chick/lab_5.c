#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "locale.h"

void enterAndCheckInput(int*);

typedef struct node
{
	int data;
	struct node* pNext;
} Node;

void memoryCheck(Node* pointer)
{
	if (pointer == NULL)
	{
		printf("\nНедостаточно памяти :<");
		exit(1);
	}
}

Node* addElement(Node* listRoot, int val)
{
	Node* current = listRoot, * newNode;
	while (current->pNext != NULL)
	{
		current = current->pNext;
	}
	newNode = (Node*)malloc(sizeof(Node)); 
	memoryCheck(newNode);        
	newNode->data = val;
	newNode->pNext = NULL;
	current->pNext = newNode; 
	return newNode;
}

Node* sort(Node* listRoot)
{
	Node* current = listRoot, * tmp = NULL, * prev = NULL;
	int flag = 0;
	do
	{
		flag = 0;
		current = listRoot;
		while (current->pNext != NULL)
		{
			if (current->data > current->pNext->data)
			{
				if (current == listRoot)
				{
					tmp = current;
					current = tmp->pNext;
					tmp->pNext = current->pNext;
					current->pNext = tmp;
					listRoot = current;
					flag = 1;
				}
				else
				{
					tmp = current;
					current = tmp->pNext;
					tmp->pNext = current->pNext;
					current->pNext = tmp;
					prev->pNext = current;
					flag = 1;
				}
			}
			prev = current;
			current = current->pNext;
		}
	} while (flag == 1);
	return listRoot;
}

void deleteDuplicates(Node* listRoot) 
{
	Node* current = listRoot, * placeholder;
	while (current != NULL && current->pNext != NULL)
	{
		if (current->data == current->pNext->data)
		{
			placeholder = current->pNext->pNext;
			free(current->pNext);
			current->pNext = placeholder;
		}
		current = current->pNext;
	}
}

Node* addList(Node* listPlusRoot, Node* generalListRoot) 
{
	Node* listPlus = listPlusRoot, * generalList = generalListRoot;
	while (listPlus != NULL)
	{
		if (generalListRoot == NULL)
		{
			generalListRoot = (Node*)malloc(sizeof(Node));
			memoryCheck(generalListRoot);
			generalListRoot->data = listPlus->data;
			generalListRoot->pNext = generalList;
		}
		else
			generalList = addElement(generalListRoot, listPlus->data);
		listPlus = listPlus->pNext;
	}
	return generalListRoot;
}

void print(Node* listRoot)  
{
	Node* current;
	current = listRoot;
	while (current != NULL)
	{
		printf(" %d ", current->data);
		current = current->pNext;
	}
}

void enterAndCheckInput(int* a)
{
	while (!scanf("%d", &(*a)))
	{
		printf("Неверный ввод, пожалуйста, повторите ввод :)\n");
		while (getchar() != '\n');
		printf("..новый ввод: ");
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	Node* listRoot = NULL, * list2Root = NULL;
	Node* list = NULL, * list2 = NULL;

	int size = 0;
	printf("Введите размер первого списка = ");
	enterAndCheckInput(&size);	

	for (int i = 0; i < size; i++)
	{
		printf("Введите элемент для первого списка:\n");

		int num = 0;

		scanf("%d", &num);
		if (listRoot == NULL)
		{
			listRoot = (Node*)malloc(sizeof(Node));
			memoryCheck(listRoot);
			listRoot->data = num;
			listRoot->pNext = list;
		}
		else
			list = addElement(listRoot, num);
	}

	int size2 = 0;
	printf("\nВведите размер второго списка = "); 
	enterAndCheckInput(&size2); 

	for (int i = 0; i < size2; i++)
	{
		printf("Введите элемент второго списка:\n");
		int num = 0;
		scanf("%d", &num);
		if (list2Root == NULL)
		{
			list2Root = (Node*)malloc(sizeof(Node));
			memoryCheck(list2Root); 
			list2Root->data = num;
			list2Root->pNext = list2;
		}
		else
			list2 = addElement(list2Root, num);
	}

	printf("\nПервый список:\n");
	listRoot = sort(listRoot);
	print(listRoot);
	printf("\nВторой список:\n");
	list2Root = sort(list2Root);
	print(list2Root);
	deleteDuplicates(listRoot);
	deleteDuplicates(list2Root);
	Node* generalListRoot = NULL, * generalList = NULL;
	generalListRoot = addList(listRoot, generalListRoot);
	generalListRoot = addList(list2Root, generalListRoot);
	generalListRoot = sort(generalListRoot);
	deleteDuplicates(generalListRoot);
	printf("\nНовый список\n");
	print(generalListRoot);
	printf("\n");

	free(listRoot);
	free(list2Root);
	return 0;
}

