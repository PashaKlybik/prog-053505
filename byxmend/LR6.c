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
BinTreeNode* searchNode(BinTreeNode* currant, int i)
{
	if (currant->numb == i)
		return currant;

	if (currant->numb > i)
	{
		if (currant->leftChild)
			return searchNode(currant->leftChild, i);
		else
			return NULL;
	}

	if (currant->numb < i)
	{
		if (currant->rightChild)
			return searchNode(currant->rightChild, i);
		else
			return NULL;
	}
}

BinTreeNode* searchPrev(BinTreeNode* currant, BinTreeNode* prev, int i)
{
	if (currant->numb == i)
		return prev;

	if (currant->numb > i)
	{
		if (currant->leftChild)
			return searchPrev(currant->leftChild, currant, i);
		else
			return NULL;
	}

	if (currant->numb < i)
	{
		if (currant->rightChild)
			return searchPrev(currant->rightChild, currant, i);
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

void Remove(BinTreeNode* root, int i)
{
	int check;

	BinTreeNode* currant;
	BinTreeNode* pred = root;

	currant = searchNode(root, i);

	if (currant != NULL && currant != root)
	{
		pred = searchPrev(root, pred, i);
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

void push(BinTreeNode* currant, int numb)
{
	BinTreeNode* check = searchNode(currant, numb);

	if (check == NULL)
	{
		if (currant->numb > numb)
		{
			if (currant->leftChild)
				push(currant->leftChild, numb);
			else
			{
				BinTreeNode* p = (BinTreeNode*)malloc(sizeof(BinTreeNode));

				p->leftChild = NULL;
				p->rightChild = NULL;
				p->numb = numb;
				currant->leftChild = p;
			}
		}
		else
		{
			if (currant->rightChild)
				push(currant->rightChild, numb);
			else
			{
				BinTreeNode* p = (BinTreeNode*)malloc(sizeof(BinTreeNode));

				p->leftChild = NULL;
				p->rightChild = NULL;
				p->numb = numb;
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
	BinTreeNode firstRoot = { 51, NULL, NULL };
	BinTreeNode secondRoot = { 91, NULL, NULL };
	
	// firstRoot
	push(&firstRoot, 46);
	push(&firstRoot, 29);
	push(&firstRoot, 54);
	push(&firstRoot, 131);
	push(&firstRoot, 101);
	push(&firstRoot, 161);
	push(&firstRoot, 50);
	push(&firstRoot, 48);
	push(&firstRoot, 47);
	push(&firstRoot, 52);
	push(&firstRoot, 51);
	push(&firstRoot, 71);
	push(&firstRoot, 70);
	push(&firstRoot, 121);
	push(&firstRoot, 31);

	// secondRoot
	push(&secondRoot, 41);
	push(&secondRoot, 29);
	push(&secondRoot, 46);
	push(&secondRoot, 77);
	push(&secondRoot, 67);
	push(&secondRoot, 71);
	push(&secondRoot, 84);
	push(&secondRoot, 78);
	push(&secondRoot, 228);

	printf("\n\nFirstRoot:\n");
	traversePr(&firstRoot);
	printf("\nSecondRoot:\n");
	traversePr(&secondRoot);
	printf("\nGeneralRoot:\n");
	combine(&firstRoot, &secondRoot);
	traversePr(&firstRoot);
}