#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 80
#define FILE_PATH "text.txt"

int size(char* s);

int main(){
    FILE* file;
    char** str;
    str = (char**)malloc(100 * sizeof(char*));
    for (int i = 0; i < 100; i++) {
        str[i] = (char*)malloc(SIZE * sizeof(char));
    }
    if ((file = fopen(FILE_PATH, "r+")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    int counter = 0;
    while (feof(file)==NULL) {
        fgets(str[counter], SIZE, file);
        counter++;
    }
    rewind(file);
    int add;
    for (int i = 0; i < counter; ++i) {
        add = size(str[i]);
        add = (SIZE - add) / 2;
        for (int j = 0; j < add; j++) {
            fputc(' ', file);
        }
        fputs(str[i], file);
    }
    for (int i = 0; i < 100; i++) {
        str[i] = NULL;
        free(str[i]);
    }
    str = NULL;
    free(str);
    fclose(file);
    return 0;
}

int size(char* s) {
    int counter = 0;
    while (s[counter] != '\0') {
        ++counter;
    }
    return counter;
}