#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 255

typedef struct tree
{
	char symbol;
	int amount;
	struct item* left;
	struct item* right;
} Tree;

void AddNode(char data, Tree** node)
{
	if (*node == NULL) 
	{
		*node = (Tree*)calloc(1, sizeof(Tree));
		(*node)->symbol = data;
		(*node)->amount = 1;
		(*node)->left = (*node)->right = NULL;
	}
	else 
	{
		if (data < (*node)->symbol)
			AddNode(data, &(*node)->left);
		else if (data > (*node)->symbol)
			AddNode(data, &(*node)->right);
		else
			(*node)->amount++;
	}
}
void InorderTraversal(Tree* node)
{
	if (node->left)
		InorderTraversal(node->left);
	if (node->amount == 1)
		printf("%c ", node->symbol);
	else
		printf("%c(%d) ", node->symbol, node->amount);
	if (node->right)
		InorderTraversal(node->right);
}
void DeleteTree(Tree* node)
{
	if (node->left)
		DeleteTree(node->left);
	if (node->right)
		DeleteTree(node->right);
	free(node);
}
void GetLeafsNumber(Tree* node, int *number)
{
	if (!(node->left) && !(node->right)) (*number)++;
	else
	{
		if (node->left)
			GetLeafsNumber(node->left, number);
		if (node->right)
			GetLeafsNumber(node->right, number);
	}
}

int main()
{
	char str[BUFFER_SIZE];
	Tree* root = NULL;
	int number = 0;

	puts("Enter text: ");
	fgets(str, BUFFER_SIZE, stdin);
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (isalpha(str[i]))
			AddNode(str[i], &root);
		else if (str[i] == '\n') break;
	}
	InorderTraversal(root);
	GetLeafsNumber(root, &number);
	printf("\nNumber of leafs: %d", number);
	DeleteTree(root);
}