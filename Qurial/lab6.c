#include <stdio.h>
#include <stdlib.h>

struct node {
	int item;
	struct node* left;
	struct node* right;
};

void PrintTree(struct node* root)
{
	if (root == NULL) return;
	PrintTree(root->left);
	printf("%d ", root->item);
	PrintTree(root->right);
}

struct node* createNode(value)
{
	struct node* newNode = malloc(sizeof(struct node));
	newNode->item = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

struct node* insertLeft(struct node* root, int value)
{
	root->left = createNode(value);
	return root->left;
}

struct node* insertRight(struct node* root, int value)
{
	root->right = createNode(value);
	return root->right;
}

struct node* insert(struct node* node, int value) {
	if (node == NULL) return createNode(value);

	if (value < node->item)
		node->left = insert(node->left, value);
	else if (value > node->item)
		node->right = insert(node->right, value);

	return node;
}

void balanceTree(struct node* root, struct node* balancedRoot)
{
	if (root == NULL) return;
	balanceTree(root->left, balancedRoot);
	insert(balancedRoot, root->item);
	balanceTree(root->right, balancedRoot);
}

int main() {
	struct node* root = createNode(1);
	insertLeft(root, 2);
	insertRight(root, 3);
	insertLeft(root->left, 4);
	insertRight(root->left, 5);
	insertLeft(root->right, 6);

	printf("\Not balanced tree:\n");
	PrintTree(root);

	struct node* BalancedRoot = createNode(root->item);
	balanceTree(root, BalancedRoot);

	printf("\nBalanced tree:\n");
	PrintTree(BalancedRoot);
}