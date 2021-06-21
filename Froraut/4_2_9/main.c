#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

#define MAX_WORDS_NUMBER 1000
#define MAX_WORD_LENGTH 1000
#define LETTER_NUMBER 26

const char* INPUT_FILENAME = "input.txt";

void allocation_error() {
    printf("Allocation error");
    exit(EXIT_FAILURE);
}

void string_to_lower(char* word) {

    size_t i;
    for (i = 0; i < MAX_WORD_LENGTH && word[i] != 0; ++i) {

        char letter = word[i];

        if (letter >= 'A' && letter <= 'Z') {
            word[i] = letter - 'A' + 'a';
        }
    }
}

char** read_words() {

    FILE* file = fopen(INPUT_FILENAME, "r");

    if (file == NULL) {
        printf("Input file is invalid");
        exit(EXIT_FAILURE);
    }

    char** words = (char**)malloc(MAX_WORDS_NUMBER * sizeof(char*));

    if (words == NULL) {
        allocation_error();
    }

    size_t i;
    for (i = 0; i < MAX_WORDS_NUMBER; ++i) {
        words[i] = NULL;
    }

    for (i = 0; i < MAX_WORDS_NUMBER; ++i) {

        char* word = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));

        if (word == NULL) {
            allocation_error();
        }

        fgets(word, MAX_WORD_LENGTH, file);

        if (word[0] == 0) {
            break;
        }

        size_t j;
        for (j = 0; j < MAX_WORD_LENGTH; ++j) {
            if (word[j] == '\n') {
                word[j] = 0;
            }
        }

        string_to_lower(word);

        *(words + i) = word;
    }

    fclose(file);

    return words;
}

struct word_wrapper* wrap_word(char* word) {

    struct word_wrapper* wrapper = (struct word_wrapper*)malloc(sizeof(struct word_wrapper));

    if (wrapper == NULL) {
        allocation_error();
    }

    wrapper->value = word;

    wrapper->letters = (size_t*)malloc(LETTER_NUMBER * sizeof(size_t));

    if (wrapper->letters == NULL) {
        allocation_error();
    }

    size_t i;
    for (i = 0; i < LETTER_NUMBER; ++i) {
        wrapper->letters[i] = 0;
    }

    for (i = 0; i < MAX_WORD_LENGTH; ++i) {

        if (word[i] == 0) {
            break;
        }

        size_t letter_index = (word[i] - 'a');
        ++wrapper->letters[letter_index];
    }

    return wrapper;
}

struct word_wrapper** wrap_words(char** words) {

    struct word_wrapper** wrappers = (struct word_wrapper**)malloc(MAX_WORDS_NUMBER * sizeof(struct word_wrapper*));

    if (wrappers == NULL) {
        allocation_error();
    }

    size_t i;
    for (i = 0; i < MAX_WORDS_NUMBER; ++i) {
        wrappers[i] = NULL;
    }

    for (i = 0; i < MAX_WORDS_NUMBER && words[i] != NULL; ++i) {
        wrappers[i] = wrap_word(words[i]);
    }

    return wrappers;
}

bool equal_letters(struct word_wrapper* wrapper, struct word_wrapper* other) {

    size_t i;
    for (i = 0; i < LETTER_NUMBER; ++i) {
        if (wrapper->letters[i] != other->letters[i]) {
            return false;
        }
    }

    return true;
}

void print_groups(struct word_wrapper** wrappers) {

    size_t i, j;
    for (i = 0; i < MAX_WORDS_NUMBER && wrappers[i] != NULL; ++i) {

        if (!wrappers[i]->is_used) {
            for (j = i; j < MAX_WORDS_NUMBER && wrappers[j] != NULL; ++j) {

                if (equal_letters(wrappers[i], wrappers[j])) {
                    printf("%s ", wrappers[j]->value);
                    wrappers[j]->is_used = true;
                }
            }

            printf("\n");
        }
    }
}

void clear(struct word_wrapper **wrappers) {

    size_t i;
    for (i = 0; i < MAX_WORDS_NUMBER && wrappers[i] != NULL; ++i) {
        free(wrappers[i]->value);
        free(wrappers[i]->letters);
        free(wrappers[i]);
    }

    free(wrappers);
}

int main() {

    char** words = read_words();

    struct word_wrapper** word_wrappers = wrap_words(words);

    print_groups(word_wrappers);

    clear(word_wrappers);
    free(words);

    return 0;
}
