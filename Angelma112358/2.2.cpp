#include <stdio.h>
#include <math.h>
#include <locale.h>
float Factorial(int number) {
    int fact = 1;
    for (int i = 0; i < number; i++) {
        fact = fact * i;
    }
}
int main() {
    setlocale(LC_ALL, ".1251");
    int n = 0;
    float sum = 0, x, e;
    printf("Введите x: ");
    while (1) {
        if (!scanf("%f", &x) || getchar() != '\n')
            while (getchar() != '\n');
        else
            break;
        printf("Повторите ввод: ");
    }
    printf("Введите e: ");
    while (1) {
        if (!scanf("%f", &e) || getchar() != '\n')
            while (getchar() != '\n');
        else
            break;
        printf("Повторите ввод: ");
    }
    while (fabs(sin(x) - sum) >= e) {
        n++;
        sum += pow(-1, n - 1) * pow(x, 2 * n - 1) / Factorial(2 * n - 1);
    }
    printf("sin = %f, e = %f, n = %d", sin(x), e, n);
    return 0;
}
