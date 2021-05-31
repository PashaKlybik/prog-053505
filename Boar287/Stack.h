#pragma once
#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
	struct node* pNext;
	int data;
} Node;

typedef struct stack
{
	int Size=0;
	Node* top;
} Stack;



void Push(Stack* stack, int data);
void RemoveAt(Stack* stack, const int index);
int GetElement(Stack* stack, const int index);
int GetSize(Stack* stack);
void DeleteTopElem(Stack* stack);
void Clear(Stack* stack);
int TopElem(Stack* stack);
void PrintStack(Stack* stack);



