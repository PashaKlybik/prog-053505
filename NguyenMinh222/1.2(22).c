#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int m;
	unsigned long long  mi = 0;
	char chislo[255];
	printf("Vvedite chislo: \n");
	scanf_s("%ld", &m);
	for (int j = m; j > 0; j--)
	{
		mi = 0;
		for (int i = 0, s = j; s > 0; i++)
		{
			mi += (s % 2) * pow(10.0, i);
			s /= 2;
		}
		_ltoa(mi, chislo, 10);//переробразовываем в чаровскую переменную
		int lenght = 0;
		_Bool fail = 0;
		char M[1];
		M[0] = chislo[0];
		while (chislo[lenght] != '\0')
		{
			if (chislo[lenght] == chislo[lenght + 1] && chislo[lenght] == M[0])
			{
				lenght = lenght + 2;
				switch (M[0])
				{
				case '1': M[0] = '0'; break;
				default: M[0] = '1';break;
				}
			}
			else
			{
				fail = 1;
				break;
			}

		}
		if (!fail)
		{
			printf("%lld - %d \n", mi, j);
		}

	}
}