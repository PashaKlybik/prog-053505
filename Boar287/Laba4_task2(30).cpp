#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<malloc.h>

int main() 
{
    int SIZE = 0;
    FILE* file = fopen("Dates.txt", "r");
    if (file == NULL)
    {
        printf("Error in opening file...");
        return -1;
    }
    char SymbolOfFile;
    int CounterOfLines = 1;
    while (!feof(file))
    {
        SymbolOfFile = fgetc(file);
        if (SymbolOfFile == '\n')
            CounterOfLines++;
    }
    rewind(file);

    SIZE = CounterOfLines;
    int* year=(int*)malloc(SIZE*sizeof(int));
    int* month = (int*)malloc(SIZE * sizeof(int));
    int* day = (int*)malloc(SIZE * sizeof(int));
    int maxDay, maxMonth, maxYear;
    int minDay, minMonth, minYear;
    for (int i = 0; i < SIZE; i++) {
        fscanf_s(file, "%d/%d/%d", &day[i], &month[i], &year[i]);
    }

    maxDay = day[0];
    maxMonth = month[0];
    maxYear = year[0];

    for (int i = 1; i < SIZE; i++) {
        if (maxYear < year[i]) {
            maxYear = year[i];
            maxMonth = month[i];
            maxDay = day[i];
        }
        if (maxYear == year[i] && maxMonth < month[i]) {
            maxMonth = month[i];
        }
        if (maxYear == year[i] && maxMonth == month[i] && maxDay < day[i]) {
            maxDay = day[i];
        }
    }

    minDay = day[0];
    minMonth = month[0];
    minYear = year[0];

    for (int i = 1; i < SIZE; i++) {
        if (minYear > year[i]) {
            minYear = year[i];
            minMonth = month[i];
            minDay = day[i];
        }
        if (minYear == year[i] && minMonth > month[i]) {
            maxMonth = month[i];
        }
        if (minYear == year[i] && minMonth == month[i] && minDay > day[i]) {
            minDay = day[i];
        }
    }
    fclose(file);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d/%d/%d\n" ,day[i],month[i],year[i]);
    }
    printf("\n");
    printf("The earliest date:%d/%d/%d\n", minDay, minMonth, minYear);
    printf("The latest date:%d/%d/%d\n", maxDay, maxMonth, maxYear);
    free(year);
    free(month);
    free(day);
    return 0;
}
