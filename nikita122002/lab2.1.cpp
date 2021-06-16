/*Три отрезка.Разработать программу, меню которой позволяет
пользователю выполнить следующие функции :
1. Ввести координаты начала и конца трех отрезков в двумерном
пространстве.
2. Определить, можно ли из этих отрезков составить треугольник.
3. Если это возможно, то определить вид треугольника
(правильный, прямоугольный, равнобедренный, произвольного
    вида).
    4. Вычислить периметр образованного треугольника.
    5. Вычислить площадь треугольника
    6. Информация о версии и авторе программы.
    7. Выход из программы.*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>


int MenuInput()
{
    int value = 0,inp;
    do {
        inp = scanf_s("%d", &value);
        while (getchar() != '\n');
        if (inp == 1) {}
        else printf("%s", "Bad,you can enter only numbers.Repeat enter:\n");
    } while (inp != 1);
    return value;
}
void Coordinates(int* x1, int* y1, int* x2, int* y2, int* x3, int* y3)
{
    int res4,res3,res2,res1,res,res5;
    // Coordinates inputting by dots
    printf("Enter the coordinates of the triangle.\n\n");
    printf("First dot\n");
    do {
        res4 = scanf_s("%d", &(*x1));
        while (getchar() != '\n');
        if (res4 == 1) {}
        else printf("%s", "Bad,you can enter only numbers.Repeat enter:\n");
    } while (res4 != 1);
    do {
        res3 = scanf_s("%d", &(*y1));
        while (getchar() != '\n');
        if (res3 == 1) {}
        else printf("%s", "Bad,you can enter only numbers.Repeat enter:\n");
    } while (res3 != 1);
    printf("Second dot\n");
    do {
        res2 = scanf_s("%d", &(*x2));
        while (getchar() != '\n');
        if (res2 == 1) {}
        else printf("%s", "Bad,you can enter only numbers.Repeat enter:\n");
    } while (res2 != 1);
    do {
        res1 = scanf_s("%d", &(*y2));
        while (getchar() != '\n');
        if (res1 == 1) {}
        else printf("%s", "Bad,you can enter only numbers.Repeat enter:\n");
    } while (res1 != 1);
    printf("Third dot\n");
    do {
        res5 = scanf_s("%d", &(*x3));
        while (getchar() != '\n');
        if (res5 == 1) {}
        else printf("%s", "Bad,you can enter only numbers.Repeat enter:\n");
    } while (res5 != 1);
    do {
        res = scanf_s("%d", &(*y3));
        while (getchar() != '\n');
        if (res == 1) {}
        else printf("%s", "Bad,you can enter only numbers.Repeat enter:\n");
    } while (res != 1);

}
void Sides(int* x1, int* y1, int* x2, int* y2, int* x3, int* y3, double* a, double* b, double* c)
{
    // Sides of triangle
    (*a) = fabs(sqrt(pow(((*x1) - (*x2)), 2) + pow(((*y1) - (*y2)), 2)));
    (*b) = fabs(sqrt(pow(((*x2) - (*x3)), 2) + pow(((*y2) - (*y3)), 2)));
    (*c) = fabs(sqrt(pow(((*x3) - (*x1)), 2) + pow(((*y3) - (*y1)), 2)));
    if ((*a) < (*b) + (*c) && (*b) < (*a) + (*c) && (*c) < (*a) + (*b))
    {
        printf("The triangle exists\n");
    }
    else
    {
        printf("The triangle does not exist\n");
    }
}
void TypeOfTriangle(double* a, double* b, double* c) // Allows you to figure out what type is your triangle
{
    if ((*a) == (*b) == (*c))
    {
        printf("The triangle is correct\n");
    }
    else if ((*a) == (*b) || (*b) == (*c) || (*a) == (*c))
    {
        printf("The triangle is isosceles\n");
    }
    else if ((((*a) * (*a)) == (((*b) * (*b)) + ((*c) * (*c)))) || (((*b) * (*b)) == (((*a) * (*a)) + ((*c) * (*c)))) || (((*c) * (*c)) == (((*b) * (*b)) + ((*a) * (*a)))))
    {
        printf("The triangle is rectangular\n");
    }
    else
    {
        printf("The triangle is arbitrary");
    }

}
void Perimeter(double* a, double* b, double* c, double* Per)
{
    (*Per) = (*a) + (*b) + (*c);
    printf("The perimeter is %f\n", (*Per));
}
void Square(double* a, double* b, double* c, double* p, double* h, double* Sq)
{
    (*p) = 0.5 * ((*a) + (*b) + (*c));
    (*h) = (2 * (sqrt((*p) * ((*p) - (*a)) * ((*p) - (*b)) * ((*p) - (*c))))) / (*a);
    (*Sq) = 0.5 * (*a) * (*h);
    printf("The area is %f\n", (*Sq));
}
void Information()
{
    printf("Version of the program 1.0\n");
    printf("Author:Nikita Kharlap\n");

}


int main()
{
    int choose = 0, ChooseMenu = 0  ;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
    double a = 0, b = 0, c = 0, Perimetr = 0, h = 0, Sq = 0, p = 0, r = 0, R = 0;
    while (ChooseMenu < 2)
    {
        ChooseMenu = 0;
        printf("\nShow menu - 1, exit - 2\n");
        ChooseMenu = MenuInput();
        if (ChooseMenu == 1)
        {
            printf("Choose:\n");
            printf("1.Coordinates.\n");
            printf("2.Type.\n");
            printf("3.Perimeter.\n");
            printf("4.The area.\n");
            printf("5.Information.\n");
            printf("6.Exit.\n\n");
            scanf_s("%d", &choose);
            switch (choose)
            {
            case 1:

                Coordinates(&x1, &y1, &x2, &y2, &x3, &y3);
                Sides(&x1, &y1, &x2, &y2, &x3, &y3, &a, &b, &c);
                while (x1 == x2 && x2 == x3 && x1 == x3)
                {
                    printf("Icorrect coordinates\nAgain\n");
                    Coordinates(&x1, &y1, &x2, &y2, &x3, &y3);
                    Sides(&x1, &y1, &x2, &y2, &x3, &y3, &a, &b, &c);
                }
                while (y1 == y2 && y2 == y3 && y1 == y3)
                {
                    printf("Icorrect coordinates\nAgain\n");
                    Coordinates(&x1, &y1, &x2, &y2, &x3, &y3);
                    Sides(&x1, &y1, &x2, &y2, &x3, &y3, &a, &b, &c);
                }
                break;
            case 2:
                printf("Define the type of triangle.\n\n");
                while (a == 0 || b == 0 || c == 0)
                {
                    printf("Incorrect side\n");
                    Coordinates(&x1, &y1, &x2, &y2, &x3, &y3);
                    Sides(&x1, &y1, &x2, &y2, &x3, &y3, &a, &b, &c);
                }
                TypeOfTriangle(&a, &b, &c);
                break;
            case 3:
                printf("Output of the triangle perimeter.\n\n");
                while (a == 0 || b == 0 || c == 0)
                {
                    printf("Incorrect side\n");
                    Coordinates(&x1, &y1, &x2, &y2, &x3, &y3);
                    Sides(&x1, &y1, &x2, &y2, &x3, &y3, &a, &b, &c);
                }
                Perimeter(&a, &b, &c, &Perimetr);
                break;
            case 4:
                printf("Output the area of the triangle.\n\n");
                while (a == 0 || b == 0 || c == 0)
                {
                    printf("Incorrect side\n");
                    Coordinates(&x1, &y1, &x2, &y2, &x3, &y3);
                    Sides(&x1, &y1, &x2, &y2, &x3, &y3, &a, &b, &c);
                }
                Square(&a, &b, &c, &p, &h, &Sq);
                break;
            case 5:
                printf("Information about version and author\n");
                Information();
                break;
            case 6:
                printf("\n You've just quited this program");
                ChooseMenu = 2;
            }
           
        }
        else
        {
            printf("Thank you for using the program.See you soon.\n");
        }
    }
}
