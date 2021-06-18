//Боровой Илья 053505 Lab2.2.6

#include <stdio.h>
#include <math.h>
#include "main.h"
#define _CRT_SECURE_NO_WARNINGS

int Fact(int n) {
    if (n == 0) {
        return 1;
    }
    return n * Fact(n - 1);
}

int FactLoop(int fact, int denominator) {
    fact *= (fact - 1);
    denominator *= fact;
    return denominator;
}


int CountN(double angle, double sinAnswer, double epsilon, int choise) {
    if (angle <= epsilon) {
        return 0;
    }
    int n = 1;
    double leftAnswer = angle;
    int fact = 3;
    int denominator = 1;
    double power = angle;
    while (fabs(leftAnswer - sinAnswer) >= epsilon) {
        power *= angle * angle;
        if (choise == 1) {
            denominator = Fact(fact);
        }
        else {
            denominator = FactLoop(fact, denominator);
        }
        fact += 2;
        double currentAnswer = power / denominator;
        if (n % 2 == 0) {
            leftAnswer += currentAnswer;
        }
        else {
            leftAnswer -= currentAnswer;
        }
        n++;
    }
    return n;
}

double EnterOneDouble() {
    double number;
    while (scanf_s("%lf", &number) != 1 || number <= 0) {
        printf("Incorrect input! Try again\n");
        while (getchar() != '\n') {
        }
    }
    return number;
}

int main() {
    printf("Enter your epsilon\n");
    double epsilon = EnterOneDouble();
    printf("Enter angel (greater than epsilon)\n");
    double angle = EnterOneDouble();
    double sinAnswer = sin(angle);
    int nAnswerLoop = CountN(angle, sinAnswer, epsilon, 0);
    int nAnswerRecurse = CountN(angle, sinAnswer, epsilon, 1);
    printf("Loop result: N = %d\n", nAnswerLoop);
    printf("Recurse result: N = %d\n", nAnswerRecurse);
    system("pause");
    return 0;
}