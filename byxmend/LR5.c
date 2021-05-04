#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct node
{
	int num;
	struct node* pNext;
} Node;

typedef struct list
{
	Node* head;
	Node* top;
	int size;
} List;


void pushback(List* list, int num)
{
	Node* p = (Node*)malloc(sizeof(Node));

	p->num = num;
	p->pNext = NULL;

	if (list->head == NULL) {
		list->head = list->top = p;
	}
	else {
		list->top->pNext = p;
		list->top = p;
	}

	list->size++;
}

void print(List list)
{
	Node* p = list.head;

	while (p)
	{
		printf("%d ", p->num);
		p = p->pNext;
	}
}

void changeList(List* list) {
	int i = 0, j = 0;

	Node* p = list->head;
	Node* e = list->head;
	Node* arrayPNext[5];
	Node* arrayNum[5];

	while (p != NULL)
	{
		arrayPNext[i] = p;
		arrayNum[i] = p->num;
		p = p->pNext;
		i++;
	}

	i--;

	p = list->head;

	while (p != NULL)
	{
		e = p;
		p = arrayPNext[i];
		p->num = arrayNum[j];
		p = e->pNext;
		i--;
		j++;
	}
}

int main()
{
	List list = { NULL, NULL, 0 };

	for (int i = 0; i < 5; i++)
	{
		pushback(&list, i);
	}

	print(list);

	changeList(&list);

	printf("\n");

	print(list);
}