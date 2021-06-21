#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_string() {
    static char number[81] = "";
    char c = 'a';
    int kol = 0;
    while (1) {
        c = getchar();
        if (c == '\n') break;
        if (kol == 80) {
            puts("The input is too big, try again");
            while (c != '\n') c = getchar();
            return get_string();
        }
        number[kol++] = c;
    }
    if (kol == 0) {
        puts("String is empty, try again");
        return get_string();
    }
    number[kol] = '\0';
    return number;
}

int valid(char* number) {
    int i;
    for (i = 0; number[i] != '\0'; i++) {
        if (number[i] == ' ') continue;
        if (number[i] < '0' || number[i] > '9') return 0;
    }
    return 1;
}

int get_int(int n) {
    while (1) {
        char* number = get_string();
        if (valid(number)) return atoi(number);
        puts("String contains restricted symbols. Try again");
    }
}

int valid_n_ints(char* numbers, int n, int* list) {
    int i = 0, kol = 0;
    char* current = (char*)malloc(100 * sizeof(char));
    current[0] = '\0';
    for (i = 0; numbers[i] != '\0'; i++) {
        strncat(current, &numbers[i], 1);
        if ((numbers[i] != ' ' && numbers[i + 1] == '\0') || (numbers[i] != ' ' && numbers[i + 1] == ' ')) {
            if (kol > n) return 0;
            list[kol++] = atoi(current);
            current[0] = '\0';
        }
    }
    if (kol != n) return 0;
    return 1;
}

int* get_n_ints(int n) {
    int* list = (int*)malloc(n * sizeof(int));
    while (1) {
        char* number = get_string();
        if (!valid(number)) {
            puts("String contains restricted symbols. Try again");
            continue;
        }
        if (valid_n_ints(number, n, list)) return list;
        printf("There should be %d numbers in string\n", n);
    }
    return list;
}