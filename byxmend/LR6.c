#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct binTreeNode
{
	int numb;
	struct binTreeNode* leftChild;
	struct binTreeNode* rightChild;
	struct binTreeNode* pNext;
	struct binTreeNode* pPrev;
} BinTreeNode;

// найти узел
BinTreeNode* searchNode(BinTreeNode* currant, int number)
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

BinTreeNode* searchPrev(BinTreeNode* currant, BinTreeNode* prev, int number)
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

BinTreeNode* findMin(BinTreeNode* currant)
{
	if (currant->leftChild)
		findMin(currant->leftChild);
	else
		return currant;
}

BinTreeNode* findMax(BinTreeNode* currant)
{
	if (currant->rightChild)
		findMax(currant->rightChild);
	else
		return currant;
}

// проверка на наличие двух узлов после конкретного элемента
int checkTwoNode(BinTreeNode* current)
{
	if (current->leftChild || current->rightChild)
		return 1;
	else
		return 0;
}

// удаление последнего узла
void removeLastNode(BinTreeNode* currant, BinTreeNode* prev)
{
	if (prev->leftChild == currant)
		prev->leftChild = NULL;
	else if (prev->rightChild == currant)
		prev->rightChild = NULL;
}

void Remove(BinTreeNode* root, int number)
{
	BinTreeNode* currant;
	BinTreeNode* pred = root;

	int check;
	currant = searchNode(root, number);

	if (currant != NULL && currant != root)
	{
		pred = searchPrev(root, pred, number);
		check = checkTwoNode(currant);

		BinTreeNode* currantMaxElementInSubTree;
		BinTreeNode* predtMaxElementInSubTree;

		if (check == 0)
		{
			removeLastNode(currant, pred);
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
				if (pred->leftChild == currant)
					pred->leftChild = currantMaxElementInSubTree;
				else if (pred->rightChild == currant)
					pred->rightChild = currantMaxElementInSubTree;

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
				if (pred->leftChild == currant)
					pred->leftChild = currantMaxElementInSubTree;
				else if (pred->rightChild == currant)
					pred->rightChild = currantMaxElementInSubTree;

				if (currant->leftChild)
					currantMaxElementInSubTree->rightChild = currant->rightChild;
			}

			free(currant);
		}
	}
}

void push(BinTreeNode* currant, int number)
{
	BinTreeNode* check = searchNode(currant, number);

	if (check == NULL)
	{
		if (currant->numb > number)
		{
			if (currant->leftChild)
				push(currant->leftChild, number);
			else
			{
				BinTreeNode* p = (BinTreeNode*)malloc(sizeof(BinTreeNode));

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
				BinTreeNode* p = (BinTreeNode*)malloc(sizeof(BinTreeNode));

				p->leftChild = NULL;
				p->rightChild = NULL;
				p->numb = number;
				currant->rightChild = p;
			}
		}
	}
}

void combine(BinTreeNode* firstRoot, BinTreeNode* secondRoot)
{
	BinTreeNode* buffer;
	buffer = searchNode(firstRoot, secondRoot->numb);

	if (buffer == NULL)
		push(firstRoot, secondRoot->numb);

	if (secondRoot->leftChild)
		combine(firstRoot, secondRoot->leftChild);

	if (secondRoot->rightChild)
		combine(firstRoot, secondRoot->rightChild);
}

// сим обход
void traverseSim(BinTreeNode* currant)
{
	if (currant->leftChild)
		traverseSim(currant->leftChild);

	printf("%d\n", currant->numb);

	if (currant->rightChild)
		traverseSim(currant->rightChild);
}

// прямой обход
void traversePr(BinTreeNode* currant)
{
	printf("%d\n", currant->numb);

	if (currant->leftChild)
		traversePr(currant->leftChild);

	if (currant->rightChild)
		traversePr(currant->rightChild);
}

// обратный обход
void traverseObr(BinTreeNode* currant)
{
	if (currant->leftChild)
		traverseObr(currant->leftChild);

	if (currant->rightChild)
		traverseObr(currant->rightChild);

	printf("%d\n", currant->numb);
}

int main()
{
	BinTreeNode firstRoot = { 6, NULL, NULL };
	BinTreeNode secondRoot = { 6, NULL, NULL };
	
	// firstRoot
	push(&firstRoot, 3);
	push(&firstRoot, 1);
	push(&firstRoot, 4);
	push(&firstRoot, 5);
	push(&firstRoot, 8);
	push(&firstRoot, 7);
	push(&firstRoot, 13);
	push(&firstRoot, 15);

	// secondRoot
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
}