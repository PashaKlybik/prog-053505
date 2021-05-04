#include <stdio.h>
#include <conio.h>
#include <locale.h>
int main(void)                 
{
    setlocale(LC_ALL, "Rus");
    int n,inf;
    inf = 0;
    while (inf==0) {
        do {
            printf("\nEnter your number\n");
            scanf_s("%d", &n);
        } while (n >= 100 || n < 1);
        if (n <= 19) {
            switch (n) {
            case 1:
                printf("один");
                break;
            case 2:
                printf("два");
                break;
            case 3:
                printf("три");
                break;
            case 4:
                printf("четыре");
                break;
            case 5:
                printf("пять");
                break;
            case 6:
                printf("шесть");
                break;
            case 7:
                printf("семь");
                break;
            case 8:
                printf("восемь");
                break;
            case 9:
                printf("девять");
                break;
            case 10:
                printf("десять");
                break;
            case 11:
                printf("одиннадцать");
                break;
            case 12:
                printf("двенадцать");
                break;
            case 13:
                printf("тринадцать");
                break;
            case 14:
                printf("четырнадцать");
                break;
            case 15:
                printf("пятнадцать");
                break;
            case 16:
                printf("шестнадцать");
                break;
            case 17:
                printf("семнадцать");
                break;
            case 18:
                printf("восемнадцать");
                break;
            case 19:
                printf("девятнадцать");
                break;
            default:
                break;
            }
        }
        else {
            switch (n / 10) {
            case 2:
                printf("двадцать");
                break;
            case 3:
                printf("тридцать");
                break;
            case 4:
                printf("сорок");
                break;
            case 5:
                printf("пятьдесят");
                break;
            case 6:
                printf("шестьдесят");
                break;
            case 7:
                printf("семьдесят");
                break;
            case 8:
                printf("восемьдесят");
                break;
            case 9:
                printf("девяносто");
                break;
            default:
                break;
            }

            switch (n % 10) {
            case 0:
                break;
            case 1:
                printf(" один");
                break;
            case 2:
                printf(" два");
                break;
            case 3:
                printf(" три");
                break;
            case 4:
                printf(" четыре");
                break;
            case 5:
                printf(" пять");
                break;
            case 6:
                printf(" шесть");
                break;
            case 7:
                printf(" семь");
                break;
            case 8:
                printf(" восемь");
                break;
            case 9:
                printf(" девять");
                break;
            default:
                break;
            }
        }
    }
    return 0;                   
}