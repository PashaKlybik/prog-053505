#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

bool is_valid(const char* input);
void parse(char* input, int** numbers, char** operations);
double solve(const int* numbers, const char* operations);

#endif //MAIN_H
