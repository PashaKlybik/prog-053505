#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

struct Node
{
	int inf;
	Node* left;
	Node* right;
};

struct Binary_Tree
{
	Node* root = NULL;
	int size = 0;

	void add(int inf)
	{
		Node* ptr = (Node*)malloc(sizeof(Node));
		if (!ptr) return;
		ptr->inf = inf;
		ptr->left = ptr->right = nullptr;

		if (root == NULL)
		{
			root = ptr;
		}
		else
		{
			Node* rt, * rt_before;
			rt = rt_before = root;
			while (rt)
			{
				rt_before = rt;
				if (inf < rt->inf) rt = rt->left;
				else rt = rt->right;
			}
			if (inf < rt_before->inf) rt_before->left = ptr;
			else rt_before->right = ptr;
		}
		size++;
	}

	void print(Node* p, char dir = '-', int w = 0)
	{
		if (p == nullptr) return;
		print(p->left, (char)218, w + 3);
		for (int i = 0; i < w; i++) printf(" ");
		printf("%c %d\n", dir, p->inf);
		print(p->right, (char)192, w + 3);
	}

	Node* search(int x)
	{
		Node* p = root;
		while (p)
		{
			if (x == p->inf) return p;
			else if (x < p->inf) p = p->left;
			else p = p->right;
		}
		return nullptr;
	}

	void clear(Node* p)
	{
		if (p == nullptr) return;
		clear(p->left);
		clear(p->right);
		free(p);
		p = nullptr;
	}
};

void Obhod(Node* p, Binary_Tree* tree_cmp, Binary_Tree* tree_dest)
{
	if (p == nullptr) return;

	Obhod(p->left, tree_cmp, tree_dest);
	Obhod(p->right, tree_cmp, tree_dest);

	if (tree_cmp->search(p->inf) == nullptr) tree_dest->add(p->inf);
}

int main()
{
	// Create tree 1
	srand(time(NULL));
	int inf;
	int n1; printf("Tree 1 size: "); scanf_s("%d", &n1);
	if (n1 < 1) return 1;
	Binary_Tree t1;
	for (int i = 0; i < n1; i++)
	{
		inf = rand() % (n1 * 2) + 1;
		while (t1.search(inf)) inf = rand() % (n1 * 2) + 1;
		t1.add(inf);
	}

	// Print tree 1
	printf("Tree 1:\n");
	t1.print(t1.root);
	printf("\n");

	// Create tree 2
	int n2; printf("Tree 2 size: "); scanf_s("%d", &n2);
	if (n2 < 1) return 1;
	Binary_Tree t2;
	for (int i = 0; i < n2; i++)
	{
		inf = rand() % (n2 * 2) + 1;
		while (t2.search(inf)) inf = rand() % (n2 * 2) + 1;
		t2.add(inf);
	}

	// Print tree 2
	printf("Tree 2:\n");
	t2.print(t2.root);
	printf("\n");

	// Create 3
	Binary_Tree t3;
	Obhod(t1.root, &t2, &t3);
	Obhod(t2.root, &t1, &t3);

	// Print 3
	printf("Tree 3:\n");
	t3.print(t3.root);
	printf("\n");

	// Clear tree 1 2 3
	t1.clear(t1.root);
	t2.clear(t2.root);
	t3.clear(t3.root);

	return 0;
}