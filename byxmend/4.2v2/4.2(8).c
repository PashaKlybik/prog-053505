#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 40

int strLength(const char * s) {
    int count = 0;

    while (s[count] != 0) {
        count++;
    }

    return count;
}

int main()
{
    char endOpenedBracket;
    char stack[N];
    char buffer[N+2];
    char** arr;
    int** lengthOfStrings = (int**)malloc(sizeof(int) * N);

    int pos = -1;
    int counter = 0;
    int round = 0, figured = 0, squared = 0;
    int wrong = 0;

    // Open file
    FILE* fp;

    int err = fopen_s(&fp, "test.txt", "r");

    if (err != 0)
    {
        exit(1);
    }

    // Counting number of strings in file
    printf("Strings from file\n");

    while (fgets(buffer, N+2, fp) != NULL)
    {
        printf("%s", buffer);
        counter++;
    }

    fseek(fp, 0, SEEK_SET);

    // Memory allocation
    arr = (char**)malloc(sizeof(char) * N);

    for (int i = 0; i < counter; i++)
    {
        arr[i] = (char*)malloc(sizeof(char) * N);
    }

    // Fill array with strings from file

    int index = 0;

    while (fgets(buffer, N+2, fp) != NULL)
    {
        for (int i = 0; i < counter; ++i) {
            lengthOfStrings[i] = (int *) strLength(buffer);
        }

        for (int j = 0; j < N; j++)
        {
            arr[index][j] = buffer[j];
        }
        arr[index][N] = '\0';
        index++;
    }

    // Close file
    fclose(fp);

    // Algorithm
    for (int v = 0; v < counter; v++) {
        for (int i = 0; (int *) i < lengthOfStrings[v]; i++) {
            if (arr[v][i] == '(') round++;
            else if (arr[v][i] == ')') round--;
            else if (arr[v][i] == '{') figured++;
            else if (arr[v][i] == '}') figured--;
            else if (arr[v][i] == '[') squared++;
            else if (arr[v][i] == ']') squared--;

            if ((arr[v][i] == '(') || (arr[v][i] == '{') || (arr[v][i] == '[')) {
                endOpenedBracket = arr[v][i];
                pos++;
                stack[pos] = arr[v][i];
            }


            if (round < 0 || figured < 0 || squared < 0) {
                printf("\nWrong");
                wrong++;
                break;
            }

            if (((arr[v][i] == ')') && (endOpenedBracket != '(')) ||
                ((arr[v][i] == '}') && (endOpenedBracket != '{')) ||
                ((arr[v][i] == ']') && (endOpenedBracket != '[')) ) {
                printf("\nWrong");
                wrong++;
                break;
            }


            if ((arr[v][i] == ')') || (arr[v][i] == '}') || (arr[v][i] == ']')) {
                pos--;
                if (pos >= 0)
                    endOpenedBracket = stack[pos];
            }
        }

        if (wrong == 0)
            printf("\nRight");

        wrong = 0;
        round = figured = squared = 0;
        pos = -1;
        endOpenedBracket = '\0';
    }

    return 0;
}