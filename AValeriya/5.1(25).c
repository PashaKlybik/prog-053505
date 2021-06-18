#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef int Val;
typedef struct item
{
    Val value;
    struct item* next;
}Item;


void push(Item** head, Val value)
{
    Item* tmp = (Item*)calloc(1, sizeof(Item));
    if (tmp == NULL)
    {
        printf("Stack is full  ");
        return;
    }
    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}


Item* pop(Item** head)
{
    Item* out;
    if ((*head) == NULL)
    {
        printf("Stack is empty ");
        return NULL;
    }
    out = *head;
    *head = (*head)->next;
    return out;
}

Val peek(const Item* head)
{
    if (head == NULL)
    {
        printf("Stack is empty");
        return -1;
    }
    return head->value;
}

void printStack(const Item* head)
{
    printf("Stack >");
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
}

size_t getSize(const Item* head)
{
    size_t size = 0;
    while (head)
    {
        size++;
        head = head->next;
    }
    return size;
}

Item* invert(Item** head)
{
    Item* temp = NULL;
    while ((*head) != NULL)
    {
        push(&temp, pop(head)->value);
    }
    return temp;
}

int main()
{
    int TEST = 21;

    int i;
    Item* head = NULL;
    for (i = 0; i < TEST; i++)
    {
        push(&head, i);
    }
    printf("Size = %d\n", getSize(head));
    printStack(head);
    printf("\n");
    head = invert(&head);
    printf("Size = %d\n", getSize(head));
    printStack(head);

}