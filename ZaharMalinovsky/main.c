
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

/*----------------------------Tree----------------------------*/

struct TreeNode {
    char txt[256];
    struct TreeNode* left;
    struct TreeNode* right;
};

void createNode(struct TreeNode** root, char *msg);

int addItem(struct TreeNode** root, char *msg);

void printInorder(struct TreeNode* root);

void printPreorder(struct TreeNode* root);

void printPostorder(struct TreeNode* root);

int deleteItem(struct TreeNode** root, char *msg);

int find(struct TreeNode* root, char msg[256]);

/*----------------------------Tree----------------------------*/

/*----------------------------Stack----------------------------*/

struct StackNode {
    char txt[256];
    struct StackNode* next;
    struct StackNode* prev;
};

void push(struct StackNode** stack_head, char msg[256]);

void pop(struct StackNode** stack_head);

void buildStack(struct StackNode** stack, struct TreeNode* root);

void workWithStack(struct StackNode** stack_head);

/*----------------------------Stack----------------------------*/


int main(void)
{
    struct TreeNode* treeRoot = NULL;
    struct StackNode* stackHead = NULL;

    puts("Welcome to the menu! Choose an operation number to proceed:\n");
    while (1)
    {
        puts("1. Add node to tree\n2. Print tree inorder");
        puts("3. Print tree preorder\n4. Print tree postorder");
        puts("5. Delete item in the tree\n6. Find item in the tree");
        puts("7. Rebuild tree to stack (opens sub-menu)");
        while (1)
        {
            char choice = _getch();
            while (getchar() != '\n');
            if (choice >= '2' && choice <= '4')
            {
                switch (choice)
                {
                    case '2':
                        printInorder(treeRoot);
                        break;
                    case '3':
                        printPreorder(treeRoot);
                        break;
                    case '4':
                        printPostorder(treeRoot);
                        break;
                }
            }
            else if (choice == '1') {
                puts("Enter a text to insert in the tree (up to 256 characters):");
                char txt[256];
                gets(txt);
                if (addItem(&treeRoot, txt)) {
                    puts("Added successfully!");
                }
                else {
                    puts("Such item already exist");
                }
            }
            else if (choice >= '5' && choice <= '6')
            {
                char txt[256];
                switch (choice)
                {
                    case '5':
                        puts("Enter the text to delete node with:");
                        gets(txt);
                        if (deleteItem(&treeRoot, txt)) {
                            puts("Successfully deleted item!");
                        }
                        else {
                            puts("No such item found!");
                        }
                        break;
                    case '6':
                        puts("Enter the text to find node with:");
                        gets(txt);
                        if (find(treeRoot, &txt)) {
                            puts("Such item exists in the tree!");
                        }
                        else {
                            puts("No such item found!");
                        }
                        break;
                }
            }
            if (choice >= '1' && choice <= '6')
            {
                puts("Press any key to proceed...");
                _getch();
                while (getchar() != '\n');
                break;
            }
            if (choice == '7')
            {
                buildStack(&stackHead, treeRoot);
                workWithStack(&stackHead);
                return 0;
            }
        }
    }
}

void createNode(struct TreeNode** root, char *msg) {
    if (!(*root = (struct TreeNode*)malloc(sizeof(struct TreeNode)))) {
        puts("Critical error! Unable to allocate memory!");
        _getch();
        while (getchar() != '\n');
        exit(0);
    }
    strcpy((*root)->txt, msg);
    (*root)->left = (*root)->right = NULL;
}

int addItem(struct TreeNode** root, char *msg) {
    if (!(*root)) {
        createNode(root, msg);
        return 1;
    }

    if (!strcmp((*root)->txt, msg)) {
        return 0;
    }

    else if (strcmp((*root)->txt, msg) > 0) {
        return addItem(&((*root)->left), msg);
    }

    else {
        return addItem(&((*root)->right), msg);
    }
}

void printInorder(struct TreeNode* root) {
    if (!root) {
        return;
    }

    printInorder(root->left);
    puts(root->txt);
    printInorder(root->right);
}

void printPreorder(struct TreeNode* root) {
    if (!root) {
        return;
    }

    puts(root->txt);
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(struct TreeNode* root) {
    if (!root) {
        return;
    }

    printPostorder(root->left);
    printPostorder(root->right);
    puts(root->txt);
}

int deleteItem(struct TreeNode** root, char *msg) {
    if (!(*root)) {
        return 0;
    }

    if (!strcmp((*root)->txt, msg)) {

        if (!(*root)->left && !(*root)->right) {
            free(*root);
            *root = NULL;
        }

        else if (!(*root)->left) {
            struct TreeNode* temp = (*root)->right;
            strcpy((*root)->txt, temp->txt);
            (*root)->left = temp->left;
            (*root)->right = temp->right;
            free(temp);
        }

        else if (!(*root)->right) {
            struct TreeNode* temp = (*root)->left;
            strcpy((*root)->txt, temp->txt);
            (*root)->left = temp->left;
            (*root)->right = temp->right;
            free(temp);
        }

        else {
            struct TreeNode* temp = (*root)->right;
            while (temp->left) {
                temp = temp->left;
            }
            strcpy((*root)->txt, temp->txt);
            deleteItem(&(*root)->right, temp->txt);
        }

        return 1;
    }

    else if (strcmp((*root)->txt, msg) > 0) {
        return deleteItem(&((*root)->left), msg);
    }

    else {
        return deleteItem(&((*root)->right), msg);
    }
}

int find(struct TreeNode* root, char msg[256]) {
    if (!root) {
        return 0;
    }

    if (!strcmp(root->txt, msg)) {
        return 1;
    }

    if (strcmp(root->txt, msg) > 0) {
        return find(root->left, msg);
    }

    else {
        return find(root->right, msg);
    }
}

void push(struct StackNode** stack_head, char msg[256]) {
    struct StackNode* new_node;
    new_node = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (!new_node) {
        puts("Critical error! Unable to allocate memory!");
        _getch();
        while (getchar() != '\n');
        exit(0);
    }
    strcpy(new_node->txt, msg);
    new_node->prev = NULL;
    if (*stack_head) {
        (*stack_head)->prev = new_node;
    }
    new_node->next = *stack_head;
    *stack_head = new_node;
}

void pop(struct StackNode** stack_head) {
    struct StackNode* curr = *stack_head;
    if (curr == NULL) {
        puts("No more nodes to pop");
        return;
    }
    while (curr->next) {
        curr = curr->next;
    }
    if (curr == *stack_head) {
        *stack_head = NULL;
    }
    else {
        curr->prev->next = NULL;
    }
    char txt[256];
    strcpy(txt, curr->txt);
    printf("You popped \"%s\"\n", txt);
    free(curr);
}

void buildStack(struct StackNode** stack, struct TreeNode* root) {
    if (!root) {
        return;
    }

    buildStack(stack, root->left);
    push(stack, root->txt);
    buildStack(stack, root->right);
}

void workWithStack(struct StackNode** stack_head) {
    while (1) {
        puts("Stack menu. Choose a function to call:\n");
        puts("1. Pop\n2. Push\n0. Exit\n-------");
        char choice = _getch();
        while (getchar() != '\n');
        if (choice == '0')
            return;

        switch (choice)
        {
            case '1':
                pop(stack_head);
                puts("Press any key to proceed...");
                _getch();
                while (getchar() != '\n');
                break;
            case '2':
            {
                char buf[256] = "";
                puts("Enter a text to fill in new node (up to 256 characters):");
                gets(buf);
                push(stack_head, buf);
                puts("Successfully pushed!");
                puts("Press any key to proceed...");
                _getch();
                while (getchar() != '\n');
                break;
            }
        }
    }
}