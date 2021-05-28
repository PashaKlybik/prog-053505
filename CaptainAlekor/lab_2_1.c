#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void GetType(float ab, float ac, float bc, const int power)
{
	if (ab == bc || ab == ac || bc == ac)
	{
		printf("Isosceles");
		if (roundf(ac * power) == roundf(ab * sqrt(2) * power)) printf(" and right triangle\n");
		else if (roundf(bc * power) == roundf(ac * sqrt(2) * power)) printf(" and right triangle\n");
		else if (roundf(ab * power) == roundf(ac * sqrt(2) * power)) printf(" and right triangle\n");
		else printf(" triangle\n");
	}
	else if (round(pow(ab, 2) * power) == round(pow(bc, 2) + pow(ac, 2)) * power) printf("Right triangle\n");
	else if (round(pow(ac, 2) * power) == round(pow(bc, 2) + pow(ab, 2)) * power) printf("Right triangle\n");
	else if (round(pow(bc, 2) * power) == round(pow(ac, 2) + pow(ab, 2)) * power) printf("Right triangle\n");
}

float GetSemiPerimeter(float ab, float ac, float bc)
{
	printf("Perimeter: %f\n", ab + bc + ac);
	return (ab + bc + ac) / 2;
}

float GetSquare(float ab, float ac, float bc)
{
	float semi_perimeter = GetSemiPerimeter(ab, ac, bc);
	float square = sqrt(semi_perimeter * (semi_perimeter - ab) * (semi_perimeter - bc) * (semi_perimeter - ac));
	printf("Square: %f\n", square);
	return square;
}

void GetInscribedRadius(float ab, float ac, float bc)
{
	printf("Inscribed circle radius: %f\n", GetSquare(ab, ac, bc) / GetSemiPerimeter(ab, ac, bc));
}

void GetCircumscribedRadius(float ab, float ac, float bc)
{
	printf("Circumsribed circle radius: %f\n\n", (ab * bc * ac) / (4 * GetSquare(ab, ac, bc)));
}

void Wait()
{
	printf("Press any button to continue\n");
	getch();
}

void main()
{
	const int power = 10000;
	float ax, ay, bx, by, cx, cy;
	int choice = 0;
	do
	{
		system("cls");
		printf("Enter coordinates of point A\n");
		scanf_s("%f", &ax); scanf_s("%f", &ay);
		printf("Enter coordinates of point B\n");
		scanf_s("%f", &bx); scanf_s("%f", &by);
		printf("Enter coordinates of point C\n");
		scanf_s("%f", &cx); scanf_s("%f", &cy);
		do
		{
			system("cls");
			float ab = sqrt(pow(fabs(ax - bx), 2) + pow(fabs(ay - by), 2));
			float ac = sqrt(pow(fabs(ax - cx), 2) + pow(fabs(ay - cy), 2));
			float bc = sqrt(pow(fabs(bx - cx), 2) + pow(fabs(by - cy), 2));
			printf("What do you want to calculate?\n");
			printf("1 - type\n2 - perimeter\n3 - square\n4 - inscribed circle radius\n5 - circumcribed circle radius\n0 - none of this\n");
			scanf_s("%d", &choice);
			switch (choice)
			{
			case 1:
				GetType(ab, ac, bc, power);
				Wait();
				break;
			case 2:
				GetSemiPerimeter(ab, ac, bc);
				Wait();
				break;
			case 3:
				GetSquare(ab, ac, bc);
				Wait();
				break;
			case 4:
				GetInscribedRadius(ab, ac, bc);
				Wait();
				break;
			case 5:
				GetCircumscribedRadius(ab, ac, bc);
				Wait();
				break;
			case 0:
				break;
			default:
				printf("Invalid input, try again\n");
				Wait();
			}
			if (!choice) break;
		} while (1);
		printf("Enter 0 to exit or any other button to input new coordinates\n");
		scanf_s("%d", &choice);
		if (!choice)
			break;
		else puts("\n");
	} while (1); 
	printf("Korostelev Alexander, 2021");
}