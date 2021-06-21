#pragma once
#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Functions.h"

typedef struct node
{
	struct node* pLeft;
	struct node* pRight;
	char Data[20]="";
}TNode;

typedef struct binaryTree
{
	TNode* Root=NULL;
}BinaryTree;

void Insert(TNode*& node,const char* data);
void PrintLNR(TNode* node);
void PrintReverseLNR(TNode* node);
void DestroyNode(TNode* node);

