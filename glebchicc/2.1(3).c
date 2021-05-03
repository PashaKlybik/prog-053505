#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#pragma warning(disable : 4996)

void exitProgram(int i) {
	printf("\nPress any key to exit the program.\n");
	exit(i);
}

double segmentLengthInSQRT(double x1, double x2, double y1, double y2) {
	double d = pow(fabs(x1 - x2), 2) + pow(fabs(y1 - y2), 2);
	return d;
}

void enterInfo(double x[], double y[]) {
	printf("Enter the coordinates.\n");
	bool xORy = true;
	char eol = 0;
	for (int i = 0; i < 3; ) {
		if (xORy) {
			printf("x%d = ", i + 1);
			if (scanf("%lf%c", &x[i], &eol) != 2 || eol != '\n') {
				printf("Incorrect input, try again: \n");
				scanf("%*[^\n]");
			}
			else {
				xORy = false;
			}
			
		}
		else {
			printf("y%d = ", i + 1);
			if (scanf("%lf%c", &y[i], &eol) != 2 || eol != '\n') {
				printf("Incorrect input, try again: \n");
				scanf("%*[^\n]");
			}
			else {
				xORy = true;
				i++;
			}
		}
	}
}

bool isPossibleToBuild(double d1, double d2, double d3) {
	if (d1 + d2 > d3 && d2 + d3 > d1 && d1 + d3 > d2) {
		printf("Possible to build a triangle.\n");
		return true;
	}
	else {
		printf("Impossible to build a triangle.\n");
		exitProgram(2);
		return false;
	}
}

void showTriangleType(double d1, double d2, double d3) {
	bool isThereAnything = false;

	if (d1 == d2 && d2 == d3) {
		printf("The triangle is regular.\n");
		isThereAnything = true;//правильный
	}
	
	if (d1 + d2 == d3 || d2 + d3 == d1 || d1 + d3 == d2) {
		printf("The triangle is right.\n");
		isThereAnything = true;//прямоугольный
	}
	
	if (d1 == d2 || d2 == d3 || d1 == d3) {
		printf("The triangle is isosceles.\n");
		isThereAnything = true; //равнобедренный
	}

	if (!isThereAnything) {
		printf("The triangle is arbitrary.\n"); //произвольный
	}
}

double perimetr(double d1, double d2, double d3) {
	printf("Perimeter = ");
	printf("%lf", d1 + d2 + d3);
	printf("\n");
	return d1 + d2 + d3;
}

void square(double d1, double d2, double d3) {
	double halfperimetr = (d1 + d2 + d3) / 2;
	printf("Square = ");
	printf("%lf", sqrt(halfperimetr * (halfperimetr - d1) * (halfperimetr - d2) * (halfperimetr - d3)));
	printf("\n");
}

void showInfo() {
	printf("Program 'three segments'. Author Gleb Butkevich. v. 1.0");
}

int main() {
	double x[3], y[3];
	enterInfo(x, y);

	double d1 = segmentLengthInSQRT(x[0], x[1], y[0], y[1]);
	double d2 = segmentLengthInSQRT(x[1], x[2], y[1], y[2]);
	double d3 = segmentLengthInSQRT(x[2], x[0], y[2], y[0]);

	if (isPossibleToBuild(sqrt(d1), sqrt(d2), sqrt(d3))) {
		showTriangleType(d1, d2, d3);
		perimetr(sqrt(d1), sqrt(d2), sqrt(d3));
		square(sqrt(d1), sqrt(d2), sqrt(d3));
		showInfo();
		exitProgram(1);
	}
	else {
		showInfo();
		exitProgram(2);
	}
}