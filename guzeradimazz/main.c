//
//  main.c
//  5.1.9
//
//  Created by Дима Гузерчук on 22.04.21.
//
//

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 255


void checkPtr(void *ptr) {
    if (ptr == NULL) {
        printf("Failed to allocate memory!!!Program stopped.\n");
        exit(-1);
    }
}

void copy_from_buffer(char **buffer, char **str, int *const length, int *const n){
    *str = (char *)realloc(*str, (*n + *length + 1) * sizeof(char));
    checkPtr(str);
    int i;
    for (i = 0; i < *length; i++) {
        (*str)[(*n)++] = (*buffer)[i];
    }
    *length = 0;
    return;
}

int read_str(char **str){
    char h;
    int length = 0, n = 0;
    char *buffer = (char *)malloc(STACK_SIZE * sizeof(char));
    checkPtr(buffer);

    while ((h = getchar()) != '\n') {
        if (!((h >= 'A' && h <= 'Z') || (h >= 'a' && h <= 'z')))
            continue;

        buffer[length++] = h;

        if (length == STACK_SIZE)
            copy_from_buffer(&buffer, str, &length, &n);
    }
    if (length != 0)
        copy_from_buffer(&buffer, str, &length, &n);
    (*str)[n] = '\0';
    free(buffer);
    return n;
}


typedef struct stack {
    struct stack *l, *r;
    char symb;
} Stack;


int main() {
    int cycle = 1;
    while (cycle) {
        cycle = 0;
        int i;
        printf("Enter your word to test on 'Palindrome'\n>");

        char *str = NULL;
        int n = read_str(&str);

        short ans = 1;
        Stack *ptr = (Stack *)malloc(sizeof(Stack));
        checkPtr(ptr);
        ptr->l = NULL;
        ptr->r = NULL;
        ptr->symb = str[0];
        for (i = 1; i < n / 2; i++) {
            
            ptr->r = (Stack *)malloc(sizeof(Stack));
            checkPtr(ptr->r);
            
            ptr->r->l = ptr;
            ptr->r->r = NULL;
            ptr->r->symb = str[i];
            ptr = ptr->r;
        }
        int m = n / 2;
        if (n % 2 == 1)
            m++;
            
        for (i = m; i < n; i++) {
            if (ptr->symb != str[i])
                ans = 0;
            if (ptr->l == NULL)
                free(ptr);
                else {
                    ptr = ptr->l;
                    free(ptr->r);
                }
        }

        if (ans == 1)
            printf("====The string is a palindrome====\n");
        else
            printf("====The string isn't a palindrome====\n");

        free(str);
        cycle = 1;
    }
    
    return 0;
}
