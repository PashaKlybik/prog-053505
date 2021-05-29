#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct node
{
    int value;
    struct node* next;
}  Node;

typedef struct queue
{
    Node* head;
    Node* tail;
}  Queue;

Queue* Push(Queue* queue, int value)
{
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    if (queue->head && queue->tail)
    {
        queue->tail->next = node;
        queue->tail = node;
    }
    else
    {
        queue->head = queue->tail = node;
    }

    return queue;
}

int Pop(Queue* queue)
{
    int value = 0;

    if (queue->head)
    {
        value = queue->head->value;
        queue->head = queue->head->next;
    }

    return value;
}

void Clear(Queue* queue)
{
    while (queue->head)
    {
        Pop(queue);
    }

    queue->head = queue->tail = NULL;
}

void Print(const Queue* queue, int* counter)
{
    const Node* node = queue->head;
    *counter = 1;

    for (; node; node = node->next)
    {
        printf("%d ", node->value);
        (*counter)++;
    }
    printf("\n");
}

void Clean(const Queue* queue)
{
    const Node* node = queue->head;

    while (node->next) {
        const Node* current = node;
        node = node->next;
        free(current);
    }

    printf("\n");
}

int main(void) {
    Queue queue = {NULL, NULL};
	int fullTime;
	printf("Print full time: ");
	scanf_s("%d", &fullTime);
    printf("\n");
    
    int dynamicTime = 0;
    int maxCounter = 0;
    int counter = 0;
    int maxTime = 0;
    int oneTime;
    int serviceTime;
    int fortuna;
    srand(time(NULL));
    
    while (dynamicTime < fullTime) {
        oneTime = rand() % 100;
        serviceTime = rand() % 120;
        fortuna = rand() % 3;

        if (oneTime > maxTime)
            maxTime = oneTime;

        Push(&queue, 1);
        Print(&queue, &counter);
        Sleep(oneTime);

        if (fortuna) {
            Pop(&queue);
            Print(&queue, &counter);
            Sleep(serviceTime);
        }

        if (counter > maxCounter)
            maxCounter = counter;

        dynamicTime += oneTime;
    }
    
	printf("Max customers: %d\n", maxCounter);
    printf("Max time of service customer: %d", maxTime);
    Clear(&queue);
    return 0;
}