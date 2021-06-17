#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct node{
    int number;
    struct node* next;
}  Node;
typedef struct queue{
    Node* head;
    Node* tail;
}  Queue;
Queue* Push(Queue* queue, int number){
    Node* node = malloc(sizeof(Node));
    node->number = number;
    node->next = NULL;
    if (queue->head && queue->tail){
        queue->tail->next = node;
        queue->tail = node;
    }
    else{
        queue->head = queue->tail = node;
    }
    return queue;
}

int Pop(Queue* queue){
    int value = 0;
    Node* current;
    if (queue->head){
        value = queue->head->number;
        current = queue->head;
        queue->head = queue->head->next;
        free(current);
    }
    return value;
}

void Print(Queue* queue){
    const Node* node = queue->head;
    for (; node; node = node->next){
        printf("%d ", node->number);
    }
    printf("\n");
}

void Clean( Queue* queue){
    Node* node = queue->head;
    while (node->next) {
        Node* current = node;
        node = node->next;
        free(current);
    }
    printf("\n");
}

Queue MinQueue(int *arr, Queue *cabinet) {
    Queue minCabinet = cabinet[0];
    int min = arr[0];
    for (int i = 0; i < 5; ++i) {
        if (arr[i] < min) {
            min = arr[i];
            minCabinet = cabinet[i];
        }
    }
    return minCabinet;
}

int MinNumberInQueue(int* arr) {
    int min = arr[0];
    for (int i = 0; i < 5; i++) 
        if (arr[i] < min) 
            min = arr[i];
    return min;
}

int MinIndex(int* arr) {
    int min = arr[0];
    int numb = 0;
    for (int i = 0; i < 5; i++)
        if (arr[i] < min) {
            min = arr[i];
            numb = i;
        }
    return numb;
}

int PopWIthTime( Queue* cabinet) {
    int a = rand() % 5;
    Pop(&cabinet[a]);
    system("cls");
    for (int i = 0; i < 5; i++)
        Print(&cabinet[i]);
    return a;
}

void PushWithTime(int* arr, Queue* cabinet, int* arrAll) {
    int minIndex = MinIndex(arr);
    int conscript = arrAll[minIndex] + 1;
   
    Push(&cabinet[MinIndex(arr)], conscript);
    system("cls");
    for (int i = 0; i < 5; i++)
        Print(&cabinet[i]);
}

int main() {
    srand(time(NULL));
    int numberOfConscripts[5];
    int numberOfAllConscripts[5];
    Queue cabinet[5] = { NULL,NULL };

    int a = 4;
    do {
        numberOfConscripts[a] = rand() % 6;
        if (numberOfConscripts[a] != 0) a--;
    } while (a!=-1);
    for (int i = 0; i < 5; i++)
        numberOfAllConscripts[i] = numberOfConscripts[i];
    
    for(int i=0; i<5; i++)
        for(int j=0; j<numberOfConscripts[i]; j++)
            Push(&cabinet[i], j+1);
       
    for(int i=0; i<5; i++)
        Print(&cabinet[i]);
    int allTime = 0;
    int Time;
    for (int i = 0; i < 10; i++) {
        Time = rand() % 3000;
        allTime += Time;
        Sleep(Time);
        PushWithTime(numberOfConscripts, &cabinet, numberOfAllConscripts);
        numberOfAllConscripts[MinIndex(numberOfConscripts)] += 1;
        numberOfConscripts[MinIndex(numberOfConscripts)] += 1;
        Time = rand() % 3000;
        Sleep(Time);
        allTime += Time;
        int a = PopWIthTime(&cabinet);
        numberOfConscripts[a] -= 1;   
    }
    printf("\nThe time during which 10 people passed the office: %d", allTime/1000);

    //for(int i=0; i < 5; i++)
        //Clean(&cabinet[0]);
    free(numberOfAllConscripts);
    free(numberOfConscripts);
    return 0;
}