#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct list
{
    int data;
    struct list* prev;
    struct list* next;
};

struct list* init(int a)
{
    struct list* lst;
    lst = (struct list*)malloc(sizeof(struct list));
    lst->data = a;
    lst->next = NULL;
    lst->prev = NULL;
    return lst;
}

struct list* addElement(struct list* element, int data)
{
    struct list* nextNode, * newNode;
    newNode = (struct list*)malloc(sizeof(struct list)); 
    nextNode = element->next;                             
    element->next = newNode;                              
    newNode->data = data;                                 
    newNode->next = nextNode;                             
    newNode->prev = element;                              
    if (nextNode != NULL)
    {
        nextNode->prev = newNode;
    }
    return newNode;
}

struct list* deleteElement(struct list* element)
{
    struct list* prev, * next;
    prev = element->prev;
    next = element->next;
    if (prev != NULL)
    {
        prev->next = element->next;
    }
    if (next != NULL)
    {
        next->prev = element->prev;
    }
    free(element);
    return prev;
}

struct list* deleteHead(struct list* head)
{
    struct list* newHead;
    newHead = head->next;
    newHead->prev = NULL;
    free(head);
    return newHead;
}

void deleteList(struct list* head)
{
    struct list* toDelete;
    do
    {
        toDelete = head;
        head = head->next;
        free(toDelete);
    } while (head->next != NULL);
}

void showList(struct list* element)
{
    struct list* listIterator;
    listIterator = element;
    do
    {
        printf("%d ", listIterator->data);
        listIterator = listIterator->prev;
    } while (listIterator != NULL);
    printf("\n");
}
