#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct tree
{
	int numb;
	struct tree* leftChild;
	struct tree* rightChild;
	struct tree* pNext;
	struct tree* pPrev;
} Tree;

// найти узел
Tree* searchNode(Tree* currant, int number)
{
	if (currant->numb == number)
		return currant;

	if (currant->numb > number)
	{
		if (currant->leftChild)
			return searchNode(currant->leftChild, number);
		else
			return NULL;
	}

	if (currant->numb < number)
	{
		if (currant->rightChild)
			return searchNode(currant->rightChild, number);
		else
			return NULL;
	}
}

Tree* searchPrev(Tree* currant, Tree* prev, int number)
{
	if (currant->numb == number)
		return prev;

	if (currant->numb > number)
	{
		if (currant->leftChild)
			return searchPrev(currant->leftChild, currant, number);
		else
			return NULL;
	}

	if (currant->numb < number)
	{
		if (currant->rightChild)
			return searchPrev(currant->rightChild, currant, number);
		else
			return NULL;
	}
}

Tree* findMin(Tree* currant)
{
	if (currant->leftChild != NULL)
		findMin(currant->leftChild);
	else
		return currant;
}

Tree* findMax(Tree* currant)
{
	if (currant->rightChild != NULL)
		findMax(currant->rightChild);
	else
		return currant;
}

int checkTwoNode(Tree* current)
{
	if (current->leftChild || current->rightChild)
		return 1;
	else
		return 0;
}

// удаление последнего узла
void removeLastNode(Tree* currant, Tree* prev)
{
	if (prev->leftChild == currant)
		prev->leftChild = NULL;
	else if (prev->rightChild == currant)
		prev->rightChild = NULL;
}

void Remove(Tree* root, int number)
{
	Tree* currant;
	Tree* prev = root;

	int check;
	currant = searchNode(root, number);

	if (currant != NULL && currant != root)
	{
		prev = searchPrev(root, prev, number);
		check = checkTwoNode(currant);

		Tree* currantMaxElementInSubTree;
		Tree* predtMaxElementInSubTree;

		if (check == 0)
		{
			removeLastNode(currant, prev);
			free(currant);
		}
		else if (check == 1)
		{
			if (currant->leftChild != NULL)
				currantMaxElementInSubTree = findMax(currant->leftChild);
			else
				currantMaxElementInSubTree = findMin(currant->rightChild);

			predtMaxElementInSubTree = currantMaxElementInSubTree;
			predtMaxElementInSubTree = searchPrev(root, predtMaxElementInSubTree, currantMaxElementInSubTree->numb);

			if (currant != predtMaxElementInSubTree)
			{
				if (prev->leftChild == currant)
					prev->leftChild = currantMaxElementInSubTree;
				else if (prev->rightChild == currant)
					prev->rightChild = currantMaxElementInSubTree;

				if (currant->leftChild)
				{
					predtMaxElementInSubTree->rightChild = currantMaxElementInSubTree->leftChild;
					currantMaxElementInSubTree->leftChild = currant->leftChild;
					currantMaxElementInSubTree->rightChild = currant->rightChild;
				}
				else
				{
					currantMaxElementInSubTree->rightChild = currant->rightChild;
					predtMaxElementInSubTree->leftChild = NULL;
				}
			}
			else
			{
				if (prev->leftChild == currant)
					prev->leftChild = currantMaxElementInSubTree;
				else if (prev->rightChild == currant)
					prev->rightChild = currantMaxElementInSubTree;

				if (currant->leftChild)
					currantMaxElementInSubTree->rightChild = currant->rightChild;
			}

			free(currant);
		}
	}
}

void push(Tree* currant, int number)
{
	Tree* check = searchNode(currant, number);

	if (check == NULL)
	{
		if (currant->numb > number)
		{
			if (currant->leftChild)
				push(currant->leftChild, number);
			else
			{
				Tree* p = (Tree*)malloc(sizeof(Tree));

				p->leftChild = NULL;
				p->rightChild = NULL;
				p->numb = number;
				currant->leftChild = p;
			}
		}
		else
		{
			if (currant->rightChild)
				push(currant->rightChild, number);
			else
			{
				Tree* p = (Tree*)malloc(sizeof(Tree));

				p->leftChild = NULL;
				p->rightChild = NULL;
				p->numb = number;
				currant->rightChild = p;
			}
		}
	}
}

void combine(Tree* firstRoot, Tree* secondRoot)
{
	Tree* buffer;
	buffer = searchNode(firstRoot, secondRoot->numb);

	if (buffer == NULL)
		push(firstRoot, secondRoot->numb);

	if (secondRoot->leftChild)
		combine(firstRoot, secondRoot->leftChild);

	if (secondRoot->rightChild)
		combine(firstRoot, secondRoot->rightChild);
}

// сим обход
void traverseSim(Tree* currant)
{
	if (currant->leftChild)
		traverseSim(currant->leftChild);

	printf("%d\n", currant->numb);

	if (currant->rightChild)
		traverseSim(currant->rightChild);
}

// прямой обход
void traversePr(Tree* currant)
{
	printf("%d\n", currant->numb);

	if (currant->leftChild)
		traversePr(currant->leftChild);

	if (currant->rightChild)
		traversePr(currant->rightChild);
}

// обратный обход
void traverseObr(Tree* currant)
{
	if (currant->leftChild)
		traverseObr(currant->leftChild);

	if (currant->rightChild)
		traverseObr(currant->rightChild);

	printf("%d\n", currant->numb);
}

void freeMemory(Tree* currant)
{
	if (currant)
	{
		if (currant->leftChild)
			freeMemory(currant->leftChild);

		if (currant->rightChild != NULL)
			freeMemory(currant->rightChild);

		free(currant);
	}
}

int main()
{	
	// firstRoot
	Tree firstRoot = { 6, NULL, NULL };
	push(&firstRoot, 3);
	push(&firstRoot, 1);
	push(&firstRoot, 4);
	push(&firstRoot, 5);
	push(&firstRoot, 8);
	push(&firstRoot, 7);
	push(&firstRoot, 13);

	// secondRoot
	Tree secondRoot = { 6, NULL, NULL };
	push(&secondRoot, 2);
	push(&secondRoot, 0);
	push(&secondRoot, 5);
	push(&secondRoot, 8);
	push(&secondRoot, 7);
	push(&secondRoot, 16);


	printf("\n\nFirstRoot:\n");
	traversePr(&firstRoot);
	printf("\nSecondRoot:\n");
	traversePr(&secondRoot);
	printf("\nGeneralRoot:\n");
	combine(&firstRoot, &secondRoot);
	traversePr(&firstRoot);

	// clear memory
	// method 1
	freeMemory(&firstRoot);
	freeMemory(&secondRoot);

	// or method 2
	for (int i = 0; i <= 13; i++)
	{
		if (searchNode(&firstRoot, i))
			Remove(&firstRoot, i);
	}

	for (int i = 0; i <= 16; i++)
	{
		if (searchNode(&secondRoot, i))
			Remove(&secondRoot, i);
	}

	// method 2 exactly works
}