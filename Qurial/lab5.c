#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
};
void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
    return;
}
void printList(struct Node* node)
{
    struct Node* last;
    printf("\nNumber factors:\n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
}
void createList(struct Node** head_ref, int new_data)
{
    int n = 1;
    while (new_data != 1)
    {
        n++;
        if (new_data % n == 0)
        {
            new_data /= n;
            append(head_ref, n);
            n--;
        }
    }
}
int main()
{
    struct Node* head = NULL;
    int num;
    printf("Enter number: ");
    scanf_s("%d", &num);
    createList(&head, num);
    printList(head);
}