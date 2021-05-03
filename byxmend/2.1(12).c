// lab_2 task 2.1 option 12

/*
Треугольник. Разработать программу, меню которой позволяет
выполнить следующие функции:
1. Ввод координат вершин треугольника.
2. Определить вид треугольника (правильный, прямоугольный, равнобедренный, произвольного вида).
3. Вывод периметра треугольника.
4. Вывод площади треугольника.
5. Вычислить и вывести радиусы вписанной и описанной вокруг
треугольника окружностей.
6. Информация о версии и авторе программы.
7. Выход из программы.
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h> // to add type (bool)

void fillArray(int arrayX[], int arrayY[]) {
    for (int i = 0; i < 3; i++) {
        printf("x%d=", i + 1);
        scanf_s("%d", &arrayX[i]);
        printf("y%d=", i + 1);
        scanf_s("%d", &arrayY[i]);
    }
}

void menu() {
    printf("\n\n1 - Enter the coordinates of the vertices of the triangle\n");
    printf("2 - Determine the type of triangle (regular, rectangular, isosceles, arbitrary)\n");
    printf("3 - Output of the triangle perimeter\n");
    printf("4 - Output of the area of the triangle\n");
    printf("5 - Calculate and output the radii of the circles inscribed and described around the triangle\n");
    printf("6 - Information about the version and author of the program\n");
    printf("7 - Exit the program\n");
}

void fillSideSize(double sideSize[], int arrayX[], int arrayY[]) {
    sideSize[0] = sqrt(pow((arrayX[1] - arrayX[0]), 2) + pow((arrayY[1] - arrayY[0]), 2));
    sideSize[1] = sqrt(pow((arrayX[2] - arrayX[1]), 2) + pow((arrayY[2] - arrayY[1]), 2));
    sideSize[2] = sqrt(pow((arrayX[2] - arrayX[0]), 2) + pow((arrayY[2] - arrayY[0]), 2));
}

bool ExistenceCheck(double sideSize[]) {
    if (sideSize[0] + sideSize[1] > sideSize[2] ||
    sideSize[1] + sideSize[2] > sideSize[0] ||
    sideSize[0] + sideSize[2] > sideSize[1]) {
        return true;
    } else {
        return false;
    }
}

int whatTriangle(double sideSize[]) {
    if (sideSize[0] == sideSize[1] == sideSize[2]) {
        return 1;
    } else if (sideSize[0] == sqrt(pow(sideSize[1], 2) + pow(sideSize[2], 2)) ||
            sideSize[1] == sqrt(pow(sideSize[0], 2) + pow(sideSize[2], 2)) ||
            sideSize[2] == sqrt(pow(sideSize[1], 2) + pow(sideSize[0], 2))) {
        return 2;
    } else if (sideSize[0] == sideSize[1] || sideSize[0] == sideSize[2]) {
        return 3;
    } else {
        return 4;
    }
}

void nameOfTriangle(double sideSize[]) {
    switch (whatTriangle(sideSize)) {
        case 1:
            printf("Regular");
            break;
        case 2:
            printf("Rectangular");
            break;
        case 3:
            printf("Isosceles"); // равнобедренный
            break;
        case 4:
            printf("Arbitrary"); // произвольный
            break;
        default:
            printf("Unknown error");
            break;
    }
}

double perimeter(double sideSize[]) {
    double P;
    P = sideSize[0] + sideSize[1] + sideSize[2];
    return P;
}

double square(double sideSize[]) {
    double S;
    double p = perimeter(sideSize) / 2;
    S = sqrt(p * (p - sideSize[0]) * (p - sideSize[1]) * (p - sideSize[2]));
    return S;
}

double inscribedCircle(double sideSize[]) {
    double inscribed;
    inscribed = square(sideSize) / (perimeter(sideSize) / 2);
    return inscribed;
}

double circumscribedCircle(double sideSize[]) {
    double circumscribed;
    circumscribed = (sideSize[0] * sideSize[1] * sideSize[2]) / (4 * square(sideSize));
    return circumscribed;
}

int main() {
    int arrayX[3];
    int arrayY[3];
    double sideSize[3];
    int reaction;

    fillArray(arrayX, arrayY);
    fillSideSize(sideSize, arrayX, arrayY);

    while(true) {
        menu();

        scanf_s("%d", &reaction);

        switch (reaction) {
            case 1:
                fillArray(arrayX, arrayY);
                fillSideSize(sideSize, arrayX, arrayY);
                break;
            case 2:
                if (!ExistenceCheck(sideSize)) {
                    printf("\nThe triangle cannot exist\n");
                } else {
                    nameOfTriangle(sideSize);
                }
                break;
            case 3:
                printf("\nTriangle perimeter = %f", perimeter(sideSize));
                break;
            case 4:
                printf("\nTriangle square = %f", square(sideSize));
                break;
            case 5:
                printf("\nInscribed circle = %f", inscribedCircle(sideSize)); // вписанная
                printf("\nCircumscribed circle = %f", circumscribedCircle(sideSize)); // писанная
                break;
            case 6:
                printf("\nVersion: the best\nDeveloper: Nikita Pestrak (aka byxmend)");
                break;
            case 7:
                return 0;
            default:
                printf("\nData entry error, please try again\n");
                break;
        }
    }
}