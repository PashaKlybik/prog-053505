#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str;
    const int MAX_STR_LEN = 1000;
    str = malloc(sizeof(char) * (MAX_STR_LEN + 1));
    if (str == NULL){
        printf("Memory error.");
        return 1;
    }
    gets(str);
    int n = strlen(str);
    int brackets_balance = 0;
    for (int i = 0; i < n; i++){
        if (str[i] == '(') {
            brackets_balance++;
            if (brackets_balance == 2){
                str[i] = '[';
            } else if (brackets_balance >= 3){
                str[i] = '{';
            }
        }
        if (str[i] == ')') {
            if (brackets_balance == 2){
                str[i] = ']';
            } else if (brackets_balance >= 3){
                str[i] = '}';
            }
            brackets_balance--;
        }
        if (brackets_balance < 0){
            printf("Brackets aren't balanced.");
            free(str);
            return 0;
        }
    }
    if (brackets_balance != 0){
        printf("Brackets aren't balanced.");
        free(str);
        return 0;
    }

    puts(str);
    free(str);
    return 0;
}