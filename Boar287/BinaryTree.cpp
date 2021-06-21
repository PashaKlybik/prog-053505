#define _CRT_SECURE_NO_WARNINGS
#include "BinaryTree.h"

void Insert(TNode*& node,const char* data)
{
		if (node == NULL)
		{
			node = (TNode*)malloc(sizeof(TNode));
			strcpy(node->Data, data);
			node->pLeft = NULL;
			node->pRight = NULL;
		}
		else
		{
			int n = strcmp(data, node->Data);
			if (n < 0)
				Insert(node->pLeft, data);
			else
				Insert(node->pRight, data);
		}
	}

void PrintLNR(TNode* node)
{
	if (node != NULL)
	{
		PrintLNR(node->pLeft);
		printf("%s ", node->Data);
		PrintLNR(node->pRight);
	}
}

void PrintReverseLNR(TNode* node)
{
	if (node != NULL)
	{
		PrintReverseLNR(node->pRight);
		printf("%s ", node->Data);
		PrintReverseLNR(node->pLeft);
	}
}

void DestroyNode(TNode* node)
{
	if (node != NULL)
	{
		DestroyNode(node->pLeft);
		DestroyNode(node->pRight);
		free(node);
	}
}
