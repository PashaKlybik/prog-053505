#include <stdio.h>

#define SIZE 80

int main(void) {
    char string[3][SIZE];
    int i, j;
    int c;

    for(i = 0; i < 3; i++)
        for(j = 0; j < SIZE; j++){
            string[i][j] = 0;
        }
    printf("Enter three lines of text:\n");

    for (i = 0; i < 3; i++) {
        j = 0;
        while ((j < SIZE) && ((c = getchar()) != '\n')) {
            string[i][j] = c;
            j++;
        }
    }

    for (i = 2; i >= 0; i--) {
        for (j = SIZE - 1; j >= 0; j--) {
            if (string[i][j] == 0){
                continue;
            }
            else {
                printf("%c", string[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}