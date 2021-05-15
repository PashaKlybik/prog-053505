#include <stdio.h>
#include <string.h>

#include "list.h"

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int compare(struct list *l1, struct list *l2) {
    // compares 2 long numbers //
    if (l1->size < l2->size) { return -1; }
    if (l1->size > l2->size) { return 1; }
    struct node *n1, *n2;
    n1 = l1->head;
    n2 = l2->head;
    while (n1 && n2) {
        if (n1->data < n2->data) { return -1; }
        if (n1->data > n2->data) { return 1; }
        n1 = n1->next;
        n2 = n2->next;
    }
    return 0;
}

void multiply(struct list *number1, int number2, struct list *result) {
    while (result->size) pop_back(result); // clear result
    struct node *current_digit = number1->tail;
    int next_digit_add = 0;
    while (current_digit) {
        int n = current_digit->data * number2 + next_digit_add;
        push_front(result, n % 10);
        next_digit_add = n / 10;
        current_digit = current_digit->prev;
    }
    if (next_digit_add) {
        push_front(result, next_digit_add);
    }
}

void subtract(struct list *minuend, struct list *subtrahend) {
    struct node *n1, *n2;
    n1 = minuend->tail;
    n2 = subtrahend->tail;
    while (n1 && n2) {
        if (n1->data < n2->data) {
            // take 10 from senior rank
            struct node *n = n1->prev;
            while (n->data == 0) {
                n->data = 9;
                n = n->prev;
            }
            n->data--;
            n1->data += 10;
        }
        n1->data -= n2->data;
        n1 = n1->prev;
        n2 = n2->prev;
    }
}

void free_memory(
        char *num1,
        char *num2,
        struct list *l1,
        struct list *l2,
        struct list *result,
        struct list *incomplete_dividend,
        struct list *temp_list) {
    free(num1);
    free(num2);
    free_list(l1);
    free_list(l2);
    free_list(result);
    free_list(incomplete_dividend);
    free_list(temp_list);
}

int main() {
    const int MAX_NUMBER_LENGTH = 1000;
    const char MEMORY_ERROR_MESSAGE[] = "Error while allocating memory. Aborting.";
    char *num1, *num2;
    int num1_len, num2_len;
    num1 = malloc(sizeof(char) * 1000);
    num2 = malloc(sizeof(char) * 1000);
    if (num1 == NULL || num2 == NULL) {
        printf(MEMORY_ERROR_MESSAGE);
        free_memory(num1, num2, NULL, NULL, NULL, NULL, NULL);
        return 1;
    }
    // input //
    gets(num1);
    gets(num2);
    num1_len = strlen(num1);
    num2_len = strlen(num2);

    for (int i = 0; i < num1_len; i++) {
        if (!is_digit(num1[i])) {
            printf("Error. '%c' isn't digit.", num1[i]);
            free(num1);
            free(num2);
            return 1;
        }
    }
    for (int i = 0; i < num2_len; i++) {
        if (!is_digit(num2[i])) {
            printf("Error. '%c' isn't digit.", num2[i]);
            free(num1);
            free(num2);
            return 1;
        }
    }

    // array of strings that represents answer in formatted style //
    char **answer_matrix = malloc(sizeof(char *) * 2 * (num1_len - num2_len + 1));
    if (answer_matrix == NULL) {
        printf(MEMORY_ERROR_MESSAGE);
        free_memory(num1, num2, NULL, NULL, NULL, NULL, NULL);
        free(answer_matrix);
        return 1;
    }
    for (int i = 0; i < 2 * (num1_len - num2_len + 1); i++) {
        answer_matrix[i] = malloc(sizeof(char) * (num1_len + 1));
        if (answer_matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(answer_matrix[i]);
            }
            printf(MEMORY_ERROR_MESSAGE);
            free_memory(num1, num2, NULL, NULL, NULL, NULL, NULL);
            free(answer_matrix);
            return 1;
        }
        answer_matrix[i][0] = '\0';
    }

    // lists that represent long numbers //
    // l1 - dividend, l2 - divider       //
    // temp_list contains result of multiplication of divider to 0..9 in each step
    struct list *l1, *l2, *result, *incomplete_dividend, *temp_list;
    l1 = list();
    l2 = list();
    result = list();
    temp_list = list();
    incomplete_dividend = list();

    if (l1 == NULL || l2 == NULL || result == NULL || temp_list == NULL || incomplete_dividend == NULL) {
        printf(MEMORY_ERROR_MESSAGE);
        free_memory(num1, num2, l1, l2, result, incomplete_dividend, temp_list);
        return 1;
    }
    for (int i = 0; i < num1_len; i++) {
        push_back(l1, num1[i] - '0');
    }
    for (int i = 0; i < num2_len; i++) {
        push_back(l2, num2[i] - '0');
    }

    // work //
    printf("%s | %s\n", num1, num2);
    struct node *n = l1->head;
    while (incomplete_dividend->size < l2->size - 1) {
        push_back(incomplete_dividend, n->data);
        n = n->next;
    }
    int margin_right = num1_len - num2_len; // for formatted out. Number of spaces needed from the right
    for (int i = 0; i < num1_len - num2_len + 1; i++) {
        push_back(incomplete_dividend, n->data);
        n = n->next;
        for (int num = 9; num >= 0; num--) {
            multiply(l2, num, temp_list);
            // delete leading zeroes //
            while (incomplete_dividend->size && incomplete_dividend->head->data == 0) pop_front(incomplete_dividend);
            while (temp_list->size && temp_list->head->data == 0) pop_front(temp_list);

            if (compare(incomplete_dividend, temp_list) >= 0) {
                if (num != 0) {
                    // we shoudln't print anything if we deducted 0 //
                    struct node *it = incomplete_dividend->head;
                    int j = 0;
                    while (j < num1_len - margin_right - incomplete_dividend->size) {
                        // left margin //
                        answer_matrix[i * 2][j] = ' ';
                        j++;
                    }
                    while (it) {
                        answer_matrix[i * 2][j] = (char) ('0' + it->data);
                        it = it->next;
                        j++;
                    }
                    answer_matrix[i * 2][j] = '\0';
                    it = temp_list->head;
                    j = 0;
                    while (j < num1_len - margin_right - temp_list->size) {
                        // left margin //
                        answer_matrix[i * 2 + 1][j] = ' ';
                        j++;
                    }
                    while (it) {
                        answer_matrix[i * 2 + 1][j] = (char) ('0' + it->data);
                        it = it->next;
                        j++;
                    }
                    answer_matrix[i * 2 + 1][j] = '\0';
                }
                subtract(incomplete_dividend, temp_list);
                push_back(result, num);
                break;
            }
        }
        margin_right--;
    }

    // output //
    int answer_showed = 0;
    int first_string_skipped = 0;
    for (int i = 0; i < 2 * (num1_len - num2_len + 1); i++) {
        if (strlen(answer_matrix[i]) > 0) {
            if (!first_string_skipped) {
                first_string_skipped = 1;
                continue;
            }
            printf("%s", answer_matrix[i]);
            if (!answer_showed) {
                for (int j = 0; j < num1_len - strlen(answer_matrix[i]); j++) { printf(" "); }
                printf(" | ");
                while (result->head->data == 0) pop_front(result);
                struct node *it = result->head;
                while (it) {
                    printf("%d", it->data);
                    it = it->next;
                }
                answer_showed = 1;
            }
            printf("\n");
        }

    }
    free_memory(num1, num2, l1, l2, result, incomplete_dividend, temp_list);
    return 0;
}