#include "ListFuncs.h"

void EnterAndCheckInput(int*);

int main(int argc, char* argv[])
{
	struct node* list1Root = NULL, * list2Root = NULL;
	struct node* list1 = NULL, * list2 = NULL;

	int i = 0;
	int n1 = 0;
	printf("Size of first list = ");
	EnterAndCheckInput(&n1);
	printf("Enter elements of first list:\n");
	for (i = 0; i < n1; i++)
	{
		int x = 0;
		scanf("%d", &x);
		if (list1Root == NULL)
		{
			list1Root = (struct node*)malloc(sizeof(struct node));
			MemoryCheck(list1Root);
			list1Root->element = x;
			list1Root->next = list1;
		}
		else
			list1 = AddElement(list1Root, x);
	}
	while (getchar() != '\n');

	int n2 = 0;
	printf("\nSize of second list = ");
	EnterAndCheckInput(&n2);
	printf("Enter elements of second list:\n");
	for (i = 0; i < n2; i++)
	{
		int x = 0;
		scanf("%d", &x);
		if (list2Root == NULL)
		{
			list2Root = (struct node*)malloc(sizeof(struct node));
			MemoryCheck(list2Root);
			list2Root->element = x;
			list2Root->next = list2;
		}
		else
			list2 = AddElement(list2Root, x);
	}
	while (getchar() != '\n');

	system("cls");
	printf("\nFirst list after sort:\n");
	list1Root = Sort(list1Root);
	ShowList(list1Root);
	printf("\nSecond list after sort:\n");
	list2Root = Sort(list2Root);
	ShowList(list2Root);
	DeleteDuplicateElements(list1Root);
	DeleteDuplicateElements(list2Root);
	struct node* generalListRoot = NULL, * generalList = NULL;
	generalListRoot = PlusList(list1Root, generalListRoot);
	generalListRoot = PlusList(list2Root, generalListRoot);
	generalListRoot = Sort(generalListRoot);
	DeleteDuplicateElements(generalListRoot);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~ ~ General list: ~ ~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ShowList(generalListRoot);
	printf("\n");

	free(list1Root);
	free(list2Root);
	return 0;
}

void EnterAndCheckInput(int* a)
{
	while (!scanf("%d", &(*a)))
	{
		printf("Wrong input! Try again :)\n");
		while (getchar() != '\n');
		printf("..new input: ");
	}
	while (getchar() != '\n');
}