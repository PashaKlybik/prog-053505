#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>

typedef struct binNode
{
	int num;
	struct binNode* leftChild;
	struct binNode* rightChild;
	struct binNode* pNext;
	struct binNode* pPrev;
} BinNode;

BinNode* searchYzel(BinNode* currant, int i)
{
	if (currant->num == i)
	{
		return currant;
	}

	if (currant->num > i)
	{
		if (currant->leftChild)
		{
			return searchYzel(currant->leftChild, i);
		}
		else
		{
			return NULL;
		}
	}

	if (currant->num < i)
	{
		if (currant->rightChild)
		{
			return searchYzel(currant->rightChild, i);
		}
		else
		{
			return NULL;
		}
	}
}

BinNode* searchPrev(BinNode* currant, int i, BinNode* Prev)
{
	if (currant->num == i)
	{
		return Prev;
	}

	if (currant->num > i)
	{
		if (currant->leftChild)
		{
			return searchPrev(currant->leftChild, i, currant);
		}
		else
		{
			return NULL;
		}
	}

	if (currant->num < i)
	{
		if (currant->rightChild)
		{
			return searchPrev(currant->rightChild, i, currant);
		}
		else
		{
			return NULL;
		}
	}
}

BinNode* findMin(BinNode* currant)
{
	if (currant->leftChild)
	{
		findMin(currant->leftChild);
	}
	else
	{
		return currant;
	}
}

BinNode* findMax(BinNode* currant)
{
	if (currant->rightChild)
	{
		findMax(currant->rightChild);
	}
	else
	{
		return currant;
	}
}

// проверка на наличие двух узлов после конкретного элемента
int defineNode(BinNode* p)
{
	if (p->leftChild || p->rightChild)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// удаление последнего узна
void removeList(BinNode* currant, BinNode* pred)
{
	if (pred->leftChild == currant)
	{
		pred->leftChild = NULL;
	}
	else if (pred->rightChild == currant)
	{
		pred->rightChild = NULL;
	}
}

void Remove(BinNode* root, int i)
{
	int def;

	BinNode* currant;
	BinNode* pred = root;

	currant = searchYzel(root, i);

	if (currant != NULL && currant != root)
	{
		pred = searchPrev(root, i, pred);
		def = defineNode(currant);

		BinNode* currantMaxElementInSubTree;
		BinNode* predtMaxElementInSubTree;

		if (def == 0)
		{
			removeList(currant, pred);
			free(currant);
		}
		else if (def == 1)
		{
			if (currant->leftChild != NULL)
			{
				currantMaxElementInSubTree = findMax(currant->leftChild);
			}
			else
			{
				currantMaxElementInSubTree = findMin(currant->rightChild);
			}

			predtMaxElementInSubTree = currantMaxElementInSubTree;
			predtMaxElementInSubTree = searchPrev(root, currantMaxElementInSubTree->num, predtMaxElementInSubTree);

			if (currant != predtMaxElementInSubTree)
			{
				if (pred->leftChild == currant)
				{
					pred->leftChild = currantMaxElementInSubTree;
				}
				else if (pred->rightChild == currant)
				{
					pred->rightChild = currantMaxElementInSubTree;
				}

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
				{
					pred->leftChild = currantMaxElementInSubTree;
				}
				else if (pred->rightChild == currant)
				{
					pred->rightChild = currantMaxElementInSubTree;
				}

				if (currant->leftChild)
				{
					currantMaxElementInSubTree->rightChild = currant->rightChild;
				}
			}

			free(currant);
		}
	}
}

void push(BinNode* currant, int num)
{
	BinNode* cheak = searchYzel(currant, num);

	if (cheak == NULL)
	{
		if (currant->num > num)
		{
			if (currant->leftChild)
			{
				push(currant->leftChild, num);
			}
			else
			{
				BinNode* p = (BinNode*)malloc(sizeof(BinNode));

				p->leftChild = NULL;
				p->rightChild = NULL;
				p->num = num;
				currant->leftChild = p;
			}
		}
		else
		{
			if (currant->rightChild)
			{
				push(currant->rightChild, num);
			}
			else
			{
				BinNode* p = (BinNode*)malloc(sizeof(BinNode));

				p->leftChild = NULL;
				p->rightChild = NULL;
				p->num = num;
				currant->rightChild = p;
			}
		}
	}
}

void combine(BinNode* firstRoot, BinNode* secondRoot)
{
	BinNode* buffer;

	buffer = searchYzel(firstRoot, secondRoot->num);

	if (buffer == NULL)
	{
		push(firstRoot, secondRoot->num);
	}

	if (secondRoot->leftChild)
	{
		combine(firstRoot, secondRoot->leftChild);
	}

	if (secondRoot->rightChild)
	{
		combine(firstRoot, secondRoot->rightChild);
	}
}

// сим. обход
void traverseSim(BinNode* currant)
{
	if (currant->leftChild)
	{
		traverseSim(currant->leftChild);
	}

	printf("%d\n", currant->num);

	if (currant->rightChild)
	{
		traverseSim(currant->rightChild);
	}
}

// прямой обход
void traversePr(BinNode* currant)
{
	printf("%d\n", currant->num);

	if (currant->leftChild)
	{
		traversePr(currant->leftChild);
	}

	if (currant->rightChild)
	{
		traversePr(currant->rightChild);
	}
}

// обратный обход
void traverseObr(BinNode* currant)
{
	if (currant->leftChild)
	{
		traverseObr(currant->leftChild);
	}

	if (currant->rightChild)
	{
		traverseObr(currant->rightChild);
	}

	printf("%d\n", currant->num);
}

int main()
{
	BinNode firstRoot = { 100, NULL, NULL };
	BinNode secondRoot = { 100, NULL, NULL };
	
	// firstRoot
	push(&firstRoot, 35);
	push(&firstRoot, 18);
	push(&firstRoot, 43);
	push(&firstRoot, 120);
	push(&firstRoot, 90);
	push(&firstRoot, 150);
	push(&firstRoot, 39);
	push(&firstRoot, 37);
	push(&firstRoot, 36);
	push(&firstRoot, 41);
	push(&firstRoot, 40);
	push(&firstRoot, 60);
	push(&firstRoot, 59);
	push(&firstRoot, 110);
	push(&firstRoot, 20);

	// secondRoot
	push(&secondRoot, 30);
	push(&secondRoot, 18);
	push(&secondRoot, 35);
	push(&secondRoot, 66);
	push(&secondRoot, 56);
	push(&secondRoot, 60);
	push(&secondRoot, 73);
	push(&secondRoot, 67);
	push(&secondRoot, 999);

	printf("\nSim:\n\n");
	printf("FirstRoot:\n");
	traverseSim(&firstRoot);
	printf("\nSecondRoot:\n");
	traverseSim(&secondRoot);
	printf("\nGeneralRoot:\n");
	traverseSim(&firstRoot, &secondRoot);
	traversePr(&firstRoot);

	printf("\nObr:\n\n");
	printf("FirstRoot:\n");
	traverseObr(&firstRoot);
	printf("\nSecondRoot:\n");
	traverseObr(&secondRoot);
	printf("\nGeneralRoot:\n");
	combine(&firstRoot, &secondRoot);
	traverseObr(&firstRoot);

	printf("\nPr:\n\n");
	printf("FirstRoot:\n");
	traversePr(&firstRoot);
	printf("\nSecondRoot:\n");
	traversePr(&secondRoot);
	printf("\nGeneralRoot:\n");
	combine(&firstRoot, &secondRoot);
	traversePr(&firstRoot);
}