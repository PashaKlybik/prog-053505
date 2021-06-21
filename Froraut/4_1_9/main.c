#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#define MAX_LENGTH 1000

void allocation_error() {
    printf("Not enough memory for allocation");
    exit(EXIT_FAILURE);
}

bool is_number(const char c) {
    return c >= '0' && c <= '9';
}

bool is_math_operation(const char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool is_valid(const char* input) {

    if (is_math_operation(input[0]) && input[0] != '-') {
        return false;
    }

    bool previous_is_operation = false;

    size_t i;
    for (i = 0; i < MAX_LENGTH && input[i] != 0; ++i) {

        bool math_operation = is_math_operation(input[i]);

        if (!is_number(input[i]) && !math_operation) {
            return false;
        }

        if (math_operation) {

            if (previous_is_operation) {
                return false;
            }

            previous_is_operation = true;
        } else {
            previous_is_operation = false;
        }
    }

    return true;
}

char* read_expression() {

    char* input = (char*)malloc(MAX_LENGTH * sizeof(char));

    if (input == NULL) {
        allocation_error();
    }

    size_t i = 0;
    for (i = 0; i < MAX_LENGTH; ++i) {
        input[i] = 0;
    }

    char c;

    i = 0;
    for (;;) {

        bool correct = true;

        for (;;) {
            c = getchar();
            if (c == '\n') {
                break;
            }

            if (c != ' ') {
                input[i++] = c;

                if (i == MAX_LENGTH - 1) {
                    correct = false;
                    break;
                }
            }
        }

        if (correct && is_valid(input)) {
            break;
        }

        printf("Input is invalid. Try again\n");
    }


    return input;
}

void parse(char* input, int** numbers, char** operations) {

    *numbers = (int*)malloc(MAX_LENGTH * sizeof(int));

    if (*numbers == NULL) {
        allocation_error();
    }

    *operations = (char*)malloc(MAX_LENGTH * sizeof(char));

    if (*operations == NULL) {
        allocation_error();
    }

    size_t i;
    for (i = 0; i < MAX_LENGTH; ++i) {
        (*operations)[i] = 0;
    }

    int current_number = 0;

    size_t numbers_i = 0;
    size_t operations_i = 0;
    for (i = 0; i < MAX_LENGTH && input[i] != 0; ++i) {

        if (is_number(input[i])) {
            current_number *= 10;
            current_number += (input[i] - '0');
        } else {
            (*numbers)[numbers_i++] = current_number;
            current_number = 0;

            if (i > 0) {
                (*operations)[operations_i++] = input[i];
            }
        }
    }

    (*numbers)[numbers_i] = current_number;

    if (input[0] == '-') {
        (*numbers)[0] *= -1;
    }
}

size_t get_left(double** ptr, size_t i) {

    while (!ptr[i]) {
        --i;
    }

    return i;
}

size_t get_right(double** ptr, size_t i) {

    while (!ptr[i]) {
        ++i;
    }

    return i;
}

double solve(const int* starter_numbers, const char* operations) {

    double** numbers = (double**)malloc(MAX_LENGTH * sizeof(double*));

    if (numbers == NULL) {
        allocation_error();
    }

    size_t i;
    for (i = 0; i < MAX_LENGTH; ++i) {

        numbers[i] = (double*)malloc(sizeof(double));

        if (numbers[i] == NULL) {
            allocation_error();
        }

        (*numbers[i]) = starter_numbers[i];
    }

    for (i = 0; i < MAX_LENGTH && operations[i] != 0; ++i) {
        if (operations[i] == '*' || operations[i] == '/') {

            size_t left_index = get_left(numbers, i);
            size_t right_index = get_right(numbers, i + 1);

            double left = *(numbers[left_index]);
            double right = *(numbers[right_index]);

            if (operations[i] == '*') {
                *(numbers[left_index]) = left * right;
            } else {
                *(numbers[left_index]) = left / right;
            }

            numbers[right_index] = NULL;
        }
    }

    for (i = 0; i < MAX_LENGTH && operations[i] != 0; ++i) {
        if (operations[i] == '+' || operations[i] == '-') {

            size_t left_index = get_left(numbers, i);
            size_t right_index = get_right(numbers, i + 1);

            double left = *(numbers[left_index]);
            double right = *(numbers[right_index]);

            if (operations[i] == '+') {
                *(numbers[left_index]) = left + right;
            } else {
                *(numbers[left_index]) = left - right;
            }

            numbers[right_index] = NULL;
        }
    }

    double answer = *numbers[0];

    free(numbers);

    return answer;
}

int main() {

    printf("Enter an input: ");
    char* input = read_expression();

    char* operations;
    int* numbers;

    parse(input, &numbers, &operations);

    double answer = solve(numbers, operations);

    printf("Answer: %lf", answer);

    free(input);
    free(numbers);
    free(operations);

    return 0;
}
