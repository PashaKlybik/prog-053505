#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node 
{
    int data;
    struct node* right;
    struct node* left;
};

struct node* newNode(int x) 
{
    struct node* p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

struct node* insert(struct node* cur, int x) 
{
    if (cur == NULL) return newNode(x);
    else if (x > cur->data)
        cur->right = insert(cur->right, x);
    else cur->left = insert(cur->left, x);
    return cur;
}

void inOrder(struct node* cur)
{
    if (cur != NULL)
    {
        inOrder(cur->left);
        printf(" %d ", cur->data);
        inOrder(cur->right);
    }
}

void deleteTree(struct node* cur) 
{
    if(cur != NULL) 
    {
        deleteTree(cur->left);
        deleteTree(cur->right);
        free(cur);
    }
}

struct node* treePruning(struct node* cur, struct node* temp) 
{
    if (cur == NULL)
        return NULL;

    else if ((cur->left == NULL) && (cur->right == NULL)) 
    {
        treePruning(temp, NULL);
    }
    else if (cur->left != NULL && cur->right != NULL) // если потомки !NULL
    {
        if ((cur->left)->left != NULL && (cur->left)->right != NULL) 
        {                                                            
            temp = cur->right;                                       
            treePruning(cur->left, temp);
        }
        
        else if ((cur->left)->left == NULL && (cur->left)->right == NULL && ((cur->right)->left != NULL || (cur->right)->right != NULL))
        {
            treePruning(cur->right, temp);
        }
        
        else if ((cur->right)->left == NULL && (cur->right)->right == NULL && ((cur->left)->left != NULL || (cur->left)->right != NULL))
        {
            treePruning(cur->left, temp);
        }
        
        else if ((cur->right)->left == NULL && (cur->right)->right == NULL && (cur->left)->left == NULL && (cur->left)->right == NULL)
        {
            free(cur->right);
            cur->right = NULL;
        }
        treePruning(temp, NULL);
    }
    
    else if (cur->left != NULL && cur->right == NULL)
    {
        treePruning(cur->left, temp);
    }
    
    else if (cur->left == NULL && cur->right != NULL)
        treePruning(cur->right, temp);

    return cur;
}

int main()
{
    struct node* cur;
    struct node* temp;
    cur = newNode(500);
    insert(cur, 480); insert(cur, 490);
    insert(cur, 475); insert(cur, 478);
    insert(cur, 470); insert(cur, 495);
    insert(cur, 498); insert(cur, 492);
    insert(cur, 510); insert(cur, 520);
    insert(cur, 505); insert(cur, 501);
    insert(cur, 507); insert(cur, 527);

    inOrder(cur);
    printf("\n");
    
    treePruning(cur, temp);

    inOrder(cur);
    printf("\n");

    deleteTree(cur);

    return 0;
}