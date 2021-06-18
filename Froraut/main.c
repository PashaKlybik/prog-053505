#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "main.h"
#include "List.h"

int teseCase(int initialNumber, int s, int* toCheck)
{
    int* RESULT;
    struct list* head = NULL, * current = NULL;
    int sizeStr, remainder, c, i;
    c = 0;

    RESULT = toSecondarySystem(initialNumber, head, current, remainder);

    for (i = 0; i < s; i++)
    {
        if (RESULT[i] == toCheck[i])
        {
            c++;
        }
    }

    free(RESULT);

    if (c == s)
    {
        return 1;
    }
    return 0;
}


int main()
{
    int* RESULT;
    struct list* head = NULL, * current = NULL;
    int initialNumber, remainder;

    printf("Input the number in 10th system: ");
    scanf("%d", &initialNumber);

    RESULT = toSecondarySystem(initialNumber, head, current, remainder);

    free(RESULT);

    return 0;
}
