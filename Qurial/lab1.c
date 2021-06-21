#include <stdio.h>

int arraySize(int num) {
    int k = 0, p = num;
    while (p != 0) {
        p = p / 2;
        k++;
    }
    return k;
}
long int* convertTo2(long int num) {
    long int k = 0, p = num;

    k = arraySize(num);
    long int* array = (long int*)malloc(k * sizeof(long int));
    p = num;
    long int i = k - 1;
    while (p != 0) {
        array[i] = p % 2;
        p = p / 2;
        i--;
    }
    i = 0;
    return array;
}

int main() {
    long int maxNumber, n = 0;
    long int* array;

    printf("Input: ");
    scanf_s("%d", &maxNumber);

    long int numSize;
    long int i = 0;

    long int previousNum = 2, k = 0;
    while (n <= maxNumber) {
        array = convertTo2(n);
        numSize = arraySize(n);

        for (long int i = 0; i < numSize; i = i + 3) {
            if ((numSize % 3) != 0) {
                k = 0;
                break;
            }
            if (array[i] == array[i + 1] && array[i] == array[i + 2] && array[i] != previousNum) {
                previousNum = array[i];
                k++;
            }
            else {
                k = 0;
                break;
            }
        }
        if (k > 0) {
            printf("\n%d - ", n);
        }
        for (long int i = 0; i < k; i++) {
            if ((i % 2) == 0) {
                printf("111");
            }
            else if ((i % 2) == 1) {
                printf("000");
            }
        }
        previousNum = 2;
        n++;
    }
}