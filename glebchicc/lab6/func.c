#include "func.h"

int Balance(Item* node)
{
    int l, r;

    if (node == 0) return 1;

    l = Balance(node->left);
    r = Balance(node->right);
    if (l == 0 || r == 0) return 0;
    if (sign(l - r) > 1) return 0;
    if (l > r)
        return (l + 1);
    else return (r + 1);
}

int sign(int a)
{
    if (a < 0)
        a = (-1) * a;
    return a;
}
void AddNode(int data, Item** node)
{
    if (*node == NULL)
    {
        *node = (Item*)calloc(1, sizeof(Item));
        (*node)->data = data;
        (*node)->left = (*node)->right = NULL;
    }
    else
    {
        if (data < (*node)->data)
            AddNode(data, &(*node)->left);
        else if (data > (*node)->data)
            AddNode(data, &(*node)->right);
    }
}

void LeftOrder(Item* node)
{
    if (node->left)
        LeftOrder(node->left);
    printf("%5d", node->data);
    if (node->right)
        LeftOrder(node->right);
}