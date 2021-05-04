#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct binaryNode
{
	int num;
	struct binaryNode* leftChild;
	struct binaryNode* rightChild;
	struct binaryNode* pNext;
	struct binaryNode* pPrev;
} BinaryNode;

BinaryNode* search(BinaryNode* currant, int index)
{
	if (currant->num == index)
	{
		return currant;
	}

	if (currant->num > index)
	{
		if (currant->leftChild)
		{
			return search(currant->leftChild, index);
		}
		else
		{
			return NULL;
		}
	}

	if (currant->num < index)
	{
		if (currant->rightChild)
		{
			return search(currant->rightChild, index);
		}
		else
		{
			return NULL;
		}
	}
}

BinaryNode* searchPrev(BinaryNode* currant, int index, BinaryNode* Prev)
{
	if (currant->num == index)
	{
		return Prev;
	}

	if (currant->num > index)
	{
		if (currant->leftChild)
		{
			return searchPrev(currant->leftChild, index, currant);
		}
		else
		{
			return NULL;
		}
	}

	if (currant->num < index)
	{
		if (currant->rightChild)
		{
			return searchPrev(currant->rightChild, index, currant);
		}
		else
		{
			return NULL;
		}
	}
}

// проверка на наличие двух узлов после конкретного элемента
int defineNode(BinaryNode* p)
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
void removeList(BinaryNode* currant, BinaryNode* pred)
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

BinaryNode* findMin(BinaryNode* currant)
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

BinaryNode* findMax(BinaryNode* currant)
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

void Remove(BinaryNode* root, int index)
{
	int def;

	BinaryNode* currant;
	BinaryNode* pred = root;

	currant = search(root, index);

	if (currant != NULL && currant != root)
	{
		pred = searchPrev(root, index, pred);
		def = defineNode(currant);

		BinaryNode* currantMaxElementInSubTree;
		BinaryNode* predtMaxElementInSubTree;

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

void push(BinaryNode* currant, int num)
{
	BinaryNode* cheak = search(currant, num);

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
				BinaryNode* p = (BinaryNode*)malloc(sizeof(BinaryNode));

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
				BinaryNode* p = (BinaryNode*)malloc(sizeof(BinaryNode));

				p->leftChild = NULL;
				p->rightChild = NULL;
				p->num = num;
				currant->rightChild = p;
			}
		}
	}
}

// прямой обход
void traversePrev(BinaryNode* currant)
{
	printf("%d\n", currant->num);

	if (currant->leftChild)
	{
		traversePrev(currant->leftChild);
	}

	if (currant->rightChild)
	{
		traversePrev(currant->rightChild);
	}
}

// обратный обход
void traverseObrat(BinaryNode* currant)
{
	if (currant->leftChild)
	{
		traverseObrat(currant->leftChild);
	}

	if (currant->rightChild)
	{
		traverseObrat(currant->rightChild);
	}

	printf("%d\n", currant->num);
}

// сим. обход
void traverseSim(BinaryNode* currant)
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

void combine(BinaryNode* root1, BinaryNode* root2)
{
	BinaryNode* buf;
	buf = search(root1, root2->num);

	if (buf == NULL)
	{
		push(root1, root2->num);
	}

	if (root2->leftChild)
	{
		combine(root1, root2->leftChild);
	}

	if (root2->rightChild)
	{
		combine(root1, root2->rightChild);
	}
}

int main()
{
	BinaryNode firstRoot = { 80, NULL, NULL };
	BinaryNode secondRoot = { 40, NULL, NULL };
	
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

	printf("FirstRoot:\n");
	traversePrev(&firstRoot);
	printf("\n\nSecondRoot\n");
	traversePrev(&secondRoot);
	printf("\n\nGeneralRoot:\n");
	combine(&firstRoot, &secondRoot);
	traversePrev(&firstRoot);
}