#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

#define SIZE_STR = 1024

typedef struct item {
    int data;
    struct item* left;
    struct item* right;
} Item;
void AddNode(int data, Item** node);
void LeftOrder(Item* node);

void AddNode(int data, Item** node)
{
    if (*node == NULL) {
        *node = (Item*)calloc(1, sizeof(Item));
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

void Delete(Item* node)
{
    if (node->left)
        Delete(node->left);

    Item* current = node;
    node = node->right;
    free(current);

    if (node)
        Delete(node);
}

void LeftOrder(Item* node)
{
    if (node->left)
        LeftOrder(node->left);
    printf("%d ", node->data);
    if (node->right)
        LeftOrder(node->right);
}

void RightOrder(Item* node)
{
    if (node->right)
        RightOrder(node->right);
    printf("%d ", node->data);
    if (node->left)
        RightOrder(node->left);
}

void main(void)
{
    Item* root = NULL;

    char str[1024];
    int i = 0, num = 0; 
    bool minus = false;

    char c; 
    while ((c = getchar()) != '\n')
        str[i++] = c; 
    str[i] = ' '; 

    for (i = 0; (i < 1024) && (str[i] != '\0'); i++)
        if ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')) 
        {
            if (num != 0 || str[i - 1] == '0') AddNode(num, &root);
            num = 0; 
            minus = false;
        }
        else if ((str[i] >= '0') && (str[i] <= '9')) { 
            if (minus) num = num * 10 - (str[i] - '0');
            else num = num * 10 + str[i] - '0'; 
        }
        else if (str[i] == '-')
        {
            minus = true;
        }

    LeftOrder(root);
    printf("\n");
    RightOrder(root);
    Delete(root);
}
