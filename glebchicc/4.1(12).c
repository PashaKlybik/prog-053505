#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define n 100
#pragma warning(disable : 4996)

char b[n / 2][n];
char repeat[n / 2][n];
static int repeatCount = 0;
int i = 0, j = 0, spaces = 0, word = 0;


void writeTheLine() {
    char c;
    printf_s("Enter the line: ");
    while ((c = getchar()) != '\n')
    {
        if (c == ' ')
        {
            if (spaces == 0 && word > 0)
            {
                b[i][j] = '\0';
                b[i++][j];
                j = 0;
            }
            spaces++;
        }
        else
        {
            b[i][j++] = c;
            spaces = 0;
            word++;
        }
    }
    b[i][j] = '\0';
}

void toLowerTheLine() {
    for (int f = 0; f <= i; f++) {
        for (int k = 0; k < (int)strlen(b[f]); k++) {
            b[f][k] = tolower((int)b[f][k]);
        }
    }
}

void sortTheLine() {
    for (int f = 0; f < i; f++)
    {
        for (int k = 0; k < i; k++)
        {
            if (strcmp(b[k], b[k + 1]) > 0)
            {
                char temp[n];
                strcpy(temp, b[k]);
                strcpy(b[k], b[k + 1]);
                strcpy(b[k + 1], temp);
            }
        }
    }
}

void toCountWords() {
    for (int f = 0; f <= i; f++) {
        int count = 1;
        bool toContinue = true;
        for (int r = 0; r < repeatCount; r++) {
            if (strcmp(b[f], repeat[r]) == 0) {
                toContinue = false;
                break;
            }
        }
        for (int k = 1; k <= i - f; k++) {
            if (strcmp(b[f], b[f + k]) == 0) {
                if (toContinue) {
                    count++;
                }
            }
        }
        if (count != 1) {
            for (int y = 0; y < (int)strlen(b[f]); y++) {
                repeat[repeatCount][y] = b[f][y];
            }
            repeatCount++;
        }
        if (toContinue) {
            printf("%s: %d\n", b[f], count);
        }
    }
}

int main() {
    writeTheLine();
    toLowerTheLine();
    sortTheLine();
    for (int f = 0; f <= i; f++) {
        printf("%s ", b[f]);
    }
    printf("\n");
    toCountWords();
}