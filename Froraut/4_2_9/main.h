#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

struct word_wrapper {
    char* value;
    size_t* letters;
    bool is_used;
};

void string_to_lower(char* word);
struct word_wrapper* wrap_word(char* word);
struct word_wrapper** wrap_words(char** words);
bool equal_letters(struct word_wrapper* wrapper, struct word_wrapper* other);

#endif //MAIN_H
