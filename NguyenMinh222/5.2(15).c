#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

void treeprint(struct Node* p);
void AddNode(int data, Node** node);
int height(Node* tree);
void balance(Node** tree);
void freeman(Node* tree);

	
void AddNode(int data, Node** node)
{
	if (*node == NULL) {
		*node = (Node*)calloc(1, sizeof(Node));
		(*node)->data = data;
		(*node)->left = (*node)->right = NULL;
	}
	else {
		if (data < (*node)->data)
			AddNode(data, &(*node)->left);
		else if (data > (*node)->data)
			AddNode(data, &(*node)->right);
		else
			puts("There is such element in the tree");
	}
	
}
void freeman(Node* tree)
{
	if (tree != NULL)
	{
		freeman(tree->left);
		freeman(tree->right);
		free(tree);
	}
}
void treeprint(struct Node* p )
{
	if (p != NULL)
	{
		treeprint(p->left);
		printf("%d \n",p->data);
		treeprint(p->right);
	}
}

int height(Node* tree) {
	return (tree ? 1 + max(height(tree->left), height(tree->right)) : 0);
}
void balance(Node** tree) {//балансировка
	if (*tree == NULL) {
		return;
	}
	while (abs(height((*tree)->left) - height((*tree)->right)) > 1) {
		if (height((*tree)->left) > height((*tree)->right) + 1) {
			Node* left = (*tree)->left->right, * right = *tree;
			*tree = (*tree)->left;
			right->left = left;
			(*tree)->right = right;
		}
		else if (1 + height((*tree)->left) < height((*tree)->right)) {
			Node* left = *tree, * right = (*tree)->right->left;
			*tree = (*tree)->right;
			left->right = right;
			(*tree)->left = left;
		
		}
	}
	
}
int main(void)
{
	char chisla[128];
	
	Node* root = NULL;
	FILE* fp = fopen("ex52.txt","r");
	if (!fp)
	{
		printf("Error, we couldn't open this file!");
		exit(1);
	}
	//пстрочно высчитываем
	while (fgets(chisla, 128, fp) != NULL)
		AddNode(atoi(chisla), &root);
	balance(&root);
	treeprint(root);
	fclose(fp);
	freeman(root);
}



