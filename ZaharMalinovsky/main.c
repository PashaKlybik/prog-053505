#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

int SUM = 0;

typedef struct Node{
    int key;
    int symbol;
    struct Node* right_child;
    struct Node* left_child;
};


struct Node* newNode(int x, int value);

struct Node* insert(struct Node* root, int x, int value);

void printInorder(struct Node* root);

int sum();

typedef struct Node_tag {
    struct Node* root;
    struct Node_tag* next;
    int value;
} Node_t;

void push(Node_t** head, struct Node* root1);

pop(Node_t** head);

size_t getSize(const Node_t* head);

int main()
{
    srand(time(NULL));

    char exit;

    while (true)
    {
        int count = 0;
        printf("Enter the amount of trees:");
        scanf("%d", &count);
        struct Node** roots = (struct Node**)calloc(count, sizeof(struct Node*));
        int symbol;
        int key;

        for (int i = 0; i < count; i++)
        {
            roots[i] = newNode(3, 3);
        }

        int numberOfNodes = 0;
        printf("Enter the amount of nodes:");
        scanf("%d", &numberOfNodes);

        for (int i = 0; i < count; i++)
        {
            for (int index = 1; index < numberOfNodes; index++)
            {
                insert(roots[i], index, symbol = rand() % 8 + 1);
            }
        }

        for (int i = 0; i < count; i++)
        {
            printf("\nRoot[%d]:\n", i + 1);
            printInorder(roots[i]);
        }

        Node_t* head = NULL;

        for (int i = 0; i < count; i++)
        {
            push(&head, roots[i]);
        }

        printf("\nsize = %d\n", getSize(head));

        while (head) {
            pop(&head);
        }
        printf("\n\nsize = %d\n", getSize(head));

        printf("Continue? -y.\n");
        while ((getchar()) != '\n');
        exit = getchar();
        if (exit == 'y')
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
}

struct Node* newNode(int x, int value) {
    struct Node* root;
    root = malloc(sizeof(struct Node));
    root->key = x;
    root->symbol = value;
    root->left_child = NULL;
    root->right_child = NULL;
    return root;
}

struct Node* insert(struct Node* root, int x, int value) {
    if (root == NULL) {
        return newNode(x, value);
    }
    else if (x > root->key) {
        root->right_child = insert(root->right_child, x, value);
    }
    else {
        root->left_child = insert(root->left_child, x, value);
    }
    return root;
}

void printInorder(struct Node* root) {

    if (root == NULL) {
        return;
    }

    if (root->left_child) {
        printInorder(root->left_child);
    }

    printf("%d ", root->symbol);

    SUM += root->symbol;

    if (root->right_child) {
        printInorder(root->right_child);
    }
}

int sum() {
    int temp = SUM;
    SUM = 0;
    return temp;
}

void push(Node_t** head, struct Node* root1) {
    Node_t* tmp = malloc(sizeof(Node_t));
    if (tmp == NULL) {
        exit(STACK_OVERFLOW);
    }

    tmp->next = *head;
    tmp->root = root1;

    *head = tmp;
}

pop(Node_t** head) {
    Node_t* out;
    struct Node* root1;
    if (*head == NULL) {
        exit(STACK_UNDERFLOW);
    }
    out = *head;
    *head = (*head)->next;
    root1 = out->root;
    free(out);

    printf("\nNext element:\n");

    sum();

    printInorder(root1);

    printf("\nSUM:%d\n", sum());
}

size_t getSize(const Node_t* head) {
    size_t size = 0;
    while (head) {
        size++;
        head = head->next;
    }
    return size;
}
