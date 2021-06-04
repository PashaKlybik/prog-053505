#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>


int main()
{
    int mandarins = 0, peaches = 0, grapes = 0;
    double mandarinsPrice = 1.14, peachesPrice = 1.00, grapesPrice = 1.28;
    double price = 0, discount;
    int n, k = 1, weight, delivery;

    while (k)
    {
        
        setlocale(LC_ALL, "ru");
        
        printf("1.Заказ мандаринов.\n");
        printf("2.Заказ персиков.\n");
        printf("3.Заказ винограда.\n");
        printf("4.Корзина.\n");
        printf("5.Конечная стоимость заказа.\n");
        printf("6.Обратная связь.\n");
        printf("7.Выход из программы.\n");
        scanf("%d", &n);
        system("cls");
        
        switch (n)
        {
        case 1:
            printf("Килограмм мандаринов = ");
            scanf("%d", &mandarins);
            break;
        case 2:
            printf("Килограмм персиков = ");
            scanf("%d", &peaches);
            break;
        case 3:
            printf("Килограмм винограда = ");
            scanf("%d", &grapes);
            break;
        case 4:
            price = mandarins * mandarinsPrice + peaches * peachesPrice + grapes * grapesPrice;
            printf("%d кг мандаринов\n", mandarins);
            printf("%d кг персиков\n", peaches);
            printf("%d кг винограда\n", grapes);
            printf("цена: %.2f\n", price);
            printf("\n");
            break;
        case 5:
            price = (mandarins * mandarinsPrice) + (peaches * peachesPrice) + (grapes * grapesPrice);
            weight = mandarins + peaches + grapes;
            if (price >= 100) discount = 0.1;
            else discount = 0;

            if (mandarins != 0) printf("Мандарины: %.2f\n", mandarins * mandarinsPrice);
            if (peaches != 0) printf("Персики: %.2f\n", peaches * peachesPrice);
            if (grapes != 0) printf("Виноград: %.2f\n", grapes * grapesPrice);

            if (weight <= 5) delivery = 1;
            else if (weight <= 20) delivery = 3;
            else delivery = 2 * weight + 10;

            printf("Затраты на доставку: %d\n", delivery);
            if (discount != 0) printf("Скидка: %.2f %%\n", discount*100);
            printf("Итого: %.2f\n", (price + delivery) * (1 - discount));
            break;
        case 6:
            printf("Магазин EFruit, телефон: 8-800-555-35-35\n");
            break;
        case 7:
            k = 0;
            break;
        default:
            printf("Такого пункта нет! Введите другой:\n");
            break;
        }
    }
}