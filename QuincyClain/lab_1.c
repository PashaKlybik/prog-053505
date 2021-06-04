#include <stdio.h>

int main() {
    for (int i = 1; i <= 1000; i++) {
        if (i < 10 && i == (i * i) % 10)
        {
            printf("%d\n", i);
        }
        else if (i >= 10 && i == (i * i) % 100)
        {
            printf("%d\n", i);
        }
        else if (i >= 100 && i == (i * i) % 1000)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}