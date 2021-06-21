//lab6 task 5.2(1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <malloc.h> 
#include <locale.h>
typedef struct item
{
	int data;
	struct item* left;
	struct item* right;
} Item;
void LeftOrder(Item* node)
{
	if (node->left)
		LeftOrder(node->left);
	printf("%d ", node->data);
	if (node->right)
		LeftOrder(node->right);
}
void AddNode(int data, Item** node)
{
	if (*node == NULL) {
		*node = (Item*)malloc(sizeof(Item));
		(*node)->data = data;
		(*node)->left = (*node)->right = NULL;
	}
	else {
		if (data < (*node)->data)
			AddNode(data, &(*node)->left);
		else if (data > (*node)->data)
			AddNode(data, &(*node)->right);
	}
}
void Combinate(Item** node, Item** node2)
{
	if ((*node)->left)
		Combinate(&(*node)->left, &(*node2));
	AddNode((*node)->data, &(*node2));
	if ((*node)->right)
		Combinate(&(*node)->right, &(*node2));
}
void clear(Item** node)
{
	if ((*node) == NULL) return;
	clear(&(*node)->left);
	clear(&(*node)->right);
	free((*node));
	(*node) = NULL;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	char buffer[128];
	Item* root1 = NULL;
	Item* root2 = NULL;
	FILE* fp = fopen("nums1.txt", "r");
	if (!fp) exit(1);
	FILE* fp2 = fopen("nums2.txt", "r");
	if (!fp2) exit(1);
	while (fgets(buffer, 128, fp) != NULL)
		AddNode(atoi(buffer), &root1);
	while (fgets(buffer, 128, fp2) != NULL)
		AddNode(atoi(buffer), &root2);
	//first tree
	printf("First tree:");
	LeftOrder(root1);
	printf("\n");
	//second tree
	printf("Second tree:");
	LeftOrder(root2);
	printf("\n");
	//general tree
	printf("Gereral tree:");
	Combinate(&root1, &root2);
	LeftOrder(root2);
	clear(&root1);
	clear(&root2);
	fclose(fp);
	fclose(fp2);
}
