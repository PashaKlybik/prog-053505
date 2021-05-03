//Геращенко Павел 053505 Лаб. работа №1, вариант 17

#include <math.h>
#include <stdio.h>

int main()
{
	int a, b, c;
	for (int i = 100; i < 1000; i++)
	{
		a = pow((i/100),3);
		b = pow((i % 100 / 10), 3);
		c = pow((i % 100 % 10), 3);
		if (i == a + b + c)
		{
			printf("%d\t", i);
		}
	}


	return 0;
}