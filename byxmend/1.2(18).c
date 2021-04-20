// lab_1 task 1.2 option 18

/*
Напечатать столбиком пример на умножение двух заданных
натуральных чисел k и l.
*/

#include<stdio.h>

int main()
{
    int a,b, tmp,x,i;
    char format[8];

    scanf_s("%d %d", &a, &b);
    printf("%d x %d\n", a,b);
    printf("%15d\n%15d\n%15s\n", a,b,"________");

    i = 15;
    x = b % 10;
    tmp = b / 10;

    while(tmp || x)
    {
        sprintf(format, "%%%dd\n", i--);
        printf(format, x*a);

        x = tmp % 10;
        tmp = tmp / 10;
    }

    printf("%15s\n%15d\n", "_________", a*b);

    return 0;
}