#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "main.h"

int* toSecondarySystem(int initialNumber, struct list* head, struct list* current, int remainder)
{
    int counter = 0, index = 0;
    int* S;
    struct list* temp;

    while (initialNumber != 0)
    {
        if (head == NULL)
        {
            remainder = initialNumber % 2;
            initialNumber = initialNumber / 2;
            head = init(remainder);
            counter++;
            continue;
        }
        if (current == NULL)
        {
            remainder = initialNumber % 2;
            initialNumber = initialNumber / 2;
            current = addElement(head, remainder);
            counter++;
            continue;
        }
        remainder = initialNumber % 2;
        initialNumber = initialNumber / 2;
        current = addElement(current, remainder);
        counter++;
    }
    showList(current);
    S = (int*)malloc(sizeof(int) * counter);
    temp = current;

    do
    {
        S[index] = temp->data;
        temp = temp->prev;
        index++;
    } while (temp != NULL);

    free(temp);

    return S;
};