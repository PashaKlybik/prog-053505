#include "Stack.h"



void Push(Stack* stack, int data)
{
	Node* temp = stack->top;
	stack->top = (Node*)malloc(sizeof(Node));
	stack->top->data = data;
	stack->top->pNext = temp;
	stack->Size++;
}

void RemoveAt(Stack* stack, const int index)
{
	if (index == 0)
		DeleteTopElem(stack);
	else
	{
		Node* previous = stack->top;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		free(toDelete);
	}
	stack->Size--;
}

int GetElement(Stack* stack, const int index)
{
	int counter = 0;
	Node* temp = stack->top;
	while (temp != NULL)
	{
		if (counter == index)
			return temp->data;

		counter++;
		temp = temp->pNext;
	}
	return 0;
}

int GetSize(Stack* stack)
{
	return stack->Size;
}

void DeleteTopElem(Stack* stack)
{
	Node* temp = stack->top;
	stack->top = stack->top->pNext;
	free(temp);
	stack->Size--;
}

void Clear(Stack* stack)
{
	while (stack->Size)
		DeleteTopElem(stack);
}

int TopElem(Stack* stack)
{
	return stack->top->data;
}

void PrintStack(Stack* stack)
{
	for (int i = 0; i < GetSize(stack); i++)
	{
		printf("%d ",GetElement(stack,i));
	}
	printf("\n");
}
