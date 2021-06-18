#include "Tree.h"

void enterAndCheckInput(int* a);
void memoryCheck(Node* pointer);
void dispose(Node* node);

int main()
{
	printf("Enter any key to start or \"-\" to exit.\n");
	char start = _getch();
	while (start != '-')
	{
		Node* root = NULL;

		printf("Enter elements of a tree:\n");
		int x = 0;
		do
		{
			enterAndCheckInput(&x);

			if (x != 0)
				addNode(&root, x);

		} while (x != 0);

		printf("\n-------------------------------------------");
		if (root != NULL)
			printf("\nAll nodes of the tree in ascending order: ");
		printTree(root); 

		if (root != NULL)
		{
			int sum = 0;
			int length = getLongestBranchLenAndSum(root, 1, &sum);

			printf("\nThe length of the longest branch: %d\nThe sum of the longest branch: %d", length, sum);

			dispose(root);
		}
		else
			printf("\nThis tree is empty :<");

		printf("\n-------------------------------------------\n");

		printf("\nEnter any symbol to continue or \"-\" to exit ...");
		start = _getch();
		if (start == '-')
			return 0;
		else
			system("cls");
	}
}

void dispose(Node* node)
{
	if (node->left != NULL)
		dispose(node->left);

	if (node->right != NULL)
		dispose(node->right);

	free(node);
}

void enterAndCheckInput(int* a)
{
	while (!scanf("%d", &(*a)))
	{
		printf("Wrong input! Try again :)\n");
		while (getchar() != '\n');
		printf("..new input: ");
	}
}

void memoryCheck(Node* pointer)
{
	if (pointer == NULL)          
	{
		printf("\nNot enough memory :<");
		exit(1);
	}
}