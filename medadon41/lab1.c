#include <stdio.h>

void main() {
    char number[5];
    char result[5] = "";

    printf("Enter the number: ");
    scanf_s("%s", &number, 5);

    if (number[2] == '0') {
        result[0] = number[3];
        result[1] = number[0];
        result[2] = number[1];
    }
    else {
        result[0] = number[2];
        result[1] = number[3];
        result[2] = number[0];
        result[3] = number[1];
    }

    printf("Reversed: ");
    printf("%s", result);

}