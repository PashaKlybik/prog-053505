#include <stdio.h> 
#include <stdlib.h>

typedef struct binaryNode {
	int data;
	struct binaryNode* leftChild;
	struct binaryNode* rightChild;
} BinaryNode;

typedef struct node {
	int data;
	struct node* pNext;
	struct node* pPrev;
} Node;


int getSize(Node* s) {
	Node* temp = s;
	int k = 0;
	while (temp != NULL) {
		temp = temp->pNext;
		k++;
	}
	return k;
}

Node* init(int x) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->pPrev = NULL;
	newNode->pNext = NULL;
	return newNode;
}

void addNode(int data, BinaryNode** node)
{
	if (*node == NULL) {
		*node = (BinaryNode*)calloc(1, sizeof(BinaryNode));
		(*node)->data = data;
		(*node)->leftChild = (*node)->rightChild = NULL;
	}
	else {
		if (data <= (*node)->data)
			addNode(data, &(*node)->leftChild);
		else if (data > (*node)->data)
			addNode(data, &(*node)->rightChild);
	}
}


void preOrder(BinaryNode* node)
{
	printf("%d ", node->data);
	if (node->leftChild)
		preOrder(node->leftChild);
	if (node->rightChild)
		preOrder(node->rightChild);
}

void inOrder(BinaryNode* node)
{
	if (node->leftChild)
		preOrder(node->leftChild);
	printf("%d ", node->data);
	if (node->rightChild)
		preOrder(node->rightChild);
}

void postOrder(BinaryNode* node)
{
	if (node->leftChild)
		preOrder(node->leftChild);
	if (node->rightChild)
		preOrder(node->rightChild);
	printf("%d ", node->data);
}



void insertLast(int x, Node** head, Node** tail) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->pNext = NULL;
	newNode->data = x;
	if (*head == NULL) {
		(*head) = (*tail) = init(x);
	}
	else {
		newNode->pPrev = (*tail);
		(*tail)->pNext = newNode;
		(*tail) = newNode;
	}
}

void push(Node** makeStack, int x) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->pNext = NULL;
	newNode->data = x;
	if ((*makeStack) == NULL) {
		(*makeStack) = init(x);
	}
	else {
		Node* last = (*makeStack);
		while (last->pNext != NULL)
			last = last->pNext;
		newNode->pPrev = last;
		last->pNext = newNode;

	}
}

void makeStack(BinaryNode* node, Node** stack, Node** stack2)
{
	if ((node->data) % 2 == 0)
		push(&(*stack), node->data);
	else
		push(&(*stack2), node->data);

	if (node->leftChild)
		makeStack(node->leftChild, &(*stack), &(*stack2));
	if (node->rightChild)
		makeStack(node->rightChild, &(*stack), &(*stack2));

}

void print(Node* s) {
	while (s != NULL) {
		printf("%d ", s->data);
		s = s->pNext;
	}
	printf("\n");
}

int top(Node* s)
{
	return s->data;
}


void pop(Node** tail, Node* head) {
	Node* current = NULL, * pPrevious = NULL;
	if (getSize(head) == 1)
	{
		(*tail) = (*tail)->pPrev;
		free(tail);
	}
	else
	{
		(*tail) = (*tail)->pPrev;
	}
}


void main(void)
{
	int randValue, size;
	BinaryNode* root = NULL;
	Node* head = NULL;
	Node* tail = NULL;
	Node* stack = NULL;
	Node* stack2 = NULL;

	for (int i = 0; i < 10; i++) {
		randValue = rand() % 100 + 1;
		insertLast(randValue, &head, &tail);
	}
	printf("Your list:\n");
	print(head);
	size = getSize(head);
	for (int i = 0; i < size; i++) {
		addNode(top(tail), &root);
		pop(&tail, head);
	}
	printf("preOrder:\n");
	preOrder(root);
	printf("\ninOrder:\n");
	inOrder(root);
	printf("\npostOrder:\n");
	postOrder(root);
	makeStack(root, &stack, &stack2);
	printf("\nEven nodes:\n");
	print(stack);
	printf("Odd nodes:\n");
	print(stack2);
}


