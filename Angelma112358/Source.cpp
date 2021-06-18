#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}Node;
typedef struct NodeTree {
	int key;
	struct nodeTree* left, * right;
} NodeTree;
void PushBack( Node** head, int newData);
void Print( Node* node);
NodeTree* NewNode(int data);
void PreOrder(NodeTree* root);
void SymmetricOrder( NodeTree* root);
void PostOrder( NodeTree* root);
NodeTree* AddInTree( NodeTree* node, int key);
NodeTree* FromListToTree(NodeTree* root, Node* list);
void PrintBiggestBranch( NodeTree* root);
void DeleteTree(NodeTree* root);
void DeleteList(Node* list);

void main(){
	int number, d = 0;
	printf("Enter number: ");
	while (1) {
		if (!scanf("%d", &number) || number <= 0 || getchar() != '\n')
			while (getchar() != '\n');
		else
			break;
		printf("Error. Enter number: ");
	}
	Node* lst = NULL;
	NodeTree* root = NULL;
	for (int i = 0; i < number; i++){
		int numb = rand() % 100;
		PushBack(&lst, numb);
	}
	printf("List: ");
	Print(lst);
	printf("\n\n");
	root = FromListToTree(root, lst);
	printf("Preorder: ");
	PreOrder(root);
	printf("\nInorder: ");
	SymmetricOrder(root);
	printf("\nPostorder: ");
	PostOrder(root);
	printf("\n\n");
	PrintBiggestBranch(root);
	DeleteTree(root);
	DeleteList(lst);
	return;
}

void PushBack( Node** head, int newData){
	Node* newNode = ( Node*)malloc(sizeof( Node));
	newNode->data = newData;
	newNode->next = (*head);
	newNode->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = newNode;
	(*head) = newNode;
}
void Print(Node* node){
	Node* tail;
	while (node != NULL) {
		printf(" %d ", node->data);
		tail = node;
		node = node->next;
	}
}
NodeTree* NewNode(int data){
	NodeTree* p= ( NodeTree*)malloc(sizeof( NodeTree));
	p->key = data;
	p->left = p->right = NULL;
	return p;
}
void PreOrder(NodeTree* root) {
	if (root != NULL) {
		printf(" %d ", root->key);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void SymmetricOrder( NodeTree* root){
	if (root != NULL) {
		SymmetricOrder(root->left);
		printf(" %d ", root->key);
		SymmetricOrder(root->right);
	}
}
void PostOrder( NodeTree* root){
	if (root != NULL) {
		PostOrder(root->left);
		PostOrder(root->right);
		printf(" %d ", root->key);
	}
}
NodeTree* AddInTree( NodeTree* node, int key){
	if (node == NULL)
		return NewNode(key);
	if (key < node->key)
		node->left = AddInTree(node->left, key);
	else if (key > node->key)
		node->right = AddInTree(node->right, key);
	return node;
}
NodeTree* FromListToTree( NodeTree* tree, Node* list){
	Node* tail;
	while (list != NULL) {
		tree = AddInTree(tree, list->data);
		tail = list;
		list = list->next;
	}
	return(tree);
}
int FindBigestBranch(NodeTree* root){
	int number = 0;
	if (root != NULL){
		number++;
		number += FindBigestBranch(root->left);
		number += FindBigestBranch(root->right);
	}
	else
		return number;
}
void PrintBiggestBranch( NodeTree* root){
	int leftCount = FindBigestBranch(root->left);
	int rightCount = FindBigestBranch(root->right);

	printf("The biggest branch: ");
	if (leftCount > rightCount)
		PreOrder(root->left);
	else if (leftCount < rightCount)
		PreOrder(root->right);
	else
		printf("No branches or equal.");
}
void DeleteTree(NodeTree* p) {
	if (p != NULL) {
		DeleteTree(p->left);
		DeleteTree(p->right);
		free(p);
		p = NULL;
	}
}
void DeleteList(Node* list) {
	Node* current = list;
	while (list!=NULL) {
		current = list->next;
		free(list);
		list = current;
	}
}