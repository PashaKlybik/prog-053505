#include <malloc.h>
#include <cstdio>

typedef struct item {
    int data;
    struct item* left;
    struct item* right;
} Item;
//-------------------------------
Item* AddNode(item** node, int data);
void DeleteNode(Item** node, int level);
void PrintNode(Item** node, int level);
void AddData(Item** node, int count);
void Merge(Item** root1, Item** root2);
//-------------------------------
int main()
{
    Item* node1 = nullptr;
    Item* node2 = nullptr;
    int count;

    printf("Enter the number of 1st tree elements:\n");
    scanf_s("%d", &count, 10);
    printf("\nEnter these elements:\n");
    AddData(&node1, count);

    printf("\nEnter the number of 2nd tree elements:\n");
    scanf_s("%d", &count, 10);
    printf("\nEnter these elements:\n");
    AddData(&node2, count);

    printf("\n1st tree:\n");
    PrintNode(&node1, 0);
    printf("\n2nd tree:\n");
    PrintNode(&node2, 0);

    Merge(&node1, &node2);
    printf("\n\nCommon tree without repeats:\n");
    PrintNode(&node1, 0);

    DeleteNode(&node1, 0);
    DeleteNode(&node2, 0);
}

Item* AddNode(item** node, int data)
{
    if ((*node) == nullptr)
    {
        (*node) = (item*)malloc(sizeof(Item));
        (*node)->data = data;
        (*node)->left = (*node)->right = nullptr;
    }
    else if (data == (*node)->data);
    else if (data < (*node)->data)
    {
        (*node)->left = AddNode(&(*node)->left, data);
    }
    else
    {
        (*node)->right = AddNode(&(*node)->right, data);
    }
    return (*node);
}

void DeleteNode(Item** node, int level)
{
    if (level == 0 && (*node) == nullptr) return;

    if ((*node)->right != nullptr)
    {
        DeleteNode(&(*node)->right, level + 1);
    }
    if ((*node)->left != nullptr)
    {
        DeleteNode(&(*node)->left, level + 1);
    }
    if ((*node) && level != 0)
    {
        free(*node);
    }
    else
    {
        (*node) = nullptr;
    }
}

void PrintNode(Item** node, int level)
{
    if (level == 0 && *node == nullptr) return;
    if ((*node)->right != nullptr)
    {
        PrintNode(&(*node)->right, level + 1);
    }
    for (int i = 0; i < level; i++)
    {
        printf("   ");
    }
    printf("%d\n", (*node)->data);
    if ((*node)->left != nullptr)
    {
        PrintNode(&(*node)->left, level + 1);
    }
}

void AddData(Item** node, int count)
{
    int data;
    for (int i = 0; i < count; i++)
    {
        scanf_s("%d", &data, 10);
        (*node) = AddNode(&(*node), data);
    }
}

void Merge(Item** root1, Item** root2)
{
    if ((*root2)->right != nullptr)
    {
        Merge(root1, &(*root2)->right);
    }
    AddNode(root1, (*root2)->data);
    if ((*root2)->left != nullptr)
    {
        Merge(root1, &(*root2)->left);
    }
}