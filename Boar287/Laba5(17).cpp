#include "Functions.h"
#include "Stack.h"

void FillStack(Stack* Stack, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		Push(Stack, rand()%10);
	}
}

void Gluing(Stack* Stack1, Stack* Stack2)
{
	for (int i = 0; i < GetSize(Stack2); i++)
	{
		Push(Stack1, GetElement(Stack2, i));
	}
}

void UniqueElemnt(Stack* Stack1)
{
	for (int i = 0; i < GetSize(Stack1); i++)
	{
		for (int j = 0; j < GetSize(Stack1); j++)
		{
			if ((GetElement(Stack1,i) == GetElement(Stack1, j)) && (i != j))
			{
				RemoveAt(Stack1, j);
			}
		}
	}
}
