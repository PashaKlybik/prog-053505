#include <stdio.h>
#define N 40

int main()
{

    char A[N];

    FILE* fp;

    int err = fopen_s(&fp, "test.txt", "r");

    if (err != 0)
    {
        printf("File can't open!");
    }

    fgets(A, N, fp);

    char endOpenedBracket;
    char stack[N];
    int pos = -1;
    int count = 0;
    int wrong = 0;

    int round, figured, squared;

    round = figured = squared = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] == '(') round++;
        else if (A[i] == ')') round--;
        else if (A[i] == '{') figured++;
        else if (A[i] == '}') figured--;
        else if (A[i] == '[') squared++;
        else if (A[i] == ']') squared--;

        if ((A[i] == '(') || (A[i] == '{') || (A[i] == '[')) {
            endOpenedBracket = A[i];
            pos++;
            stack[pos] = A[i];
        }

        if (round < 0 || figured < 0 || squared < 0) {
            printf("\nWrong");
            wrong++;
            break;
        }

        if (((A[i] == ')') && (endOpenedBracket != '(')) ||
            ((A[i] == '}') && (endOpenedBracket != '{')) ||
            ((A[i] == ']') && (endOpenedBracket != '[')) ) {
            printf("\nWrong");
            wrong++;
            break;
        }

        if ((A[i] == ')') || (A[i] == '}') || (A[i] == ']')) {
            pos--;
            if (pos >= 0)
                endOpenedBracket = stack[pos];
        }
    }

    if (wrong == 0)
        printf("\nRight");

    return 0;
}