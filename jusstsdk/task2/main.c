#include <stdio.h>
#include <stdlib.h>
#define N 100

int Length(char *string)
{
    int i = 0;
    while(string[i] != '\0') i++;

    return i;
}

int main()
{
    char str[N];
    FILE* fin;

    errno_t err = fopen_s(&fin, "input.txt", "r");

    if (err != 0)
    {
        puts("error");
        return 0;
    }

    printf("Text from file\n");

    while (fgets(str, N, fin) != NULL)
    {
        printf("%s", str);
    }

    int currentDepth = 0, maxDepth = 0;

    for (int i = 0; i < Length(str); i++)
    {
        if (str[i] == '(')
        {
            str[i] = '{';
            currentDepth++;

            if (currentDepth > maxDepth)
            {
                maxDepth = currentDepth;
            }
        }

        if (str[i] == ')')
        {
            str[i] = '}';
            currentDepth--;
        }
    }

    if (currentDepth != 0) printf("Brackets are not balanced.");

    for (int i = 0; i < Length(str); i++)
    {
        if (str[i] == '{')
        {
            currentDepth++;
            if(currentDepth == maxDepth) str[i] = '(';
            if(currentDepth == maxDepth - 1) str[i] = '[';
        }
        if (str[i] == '}')
        {
            if (currentDepth == maxDepth) str[i] = ')';
            if (currentDepth == maxDepth - 1) str[i] = ']';
            currentDepth--;
        }
    }

    printf("\n\nCorrected text:\n");

    puts(str);
}
