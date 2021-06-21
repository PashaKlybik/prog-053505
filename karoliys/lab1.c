//lab 1 task 1.2(17)
#include <stdio.h>
#include <math.h>

int main()
{
	int x, y, z, i;
	for (x = 1; x <= 9; x++)
	{
		for (y = 0; y <= 9; y++)
		{
			for (z = 0; z <= 9; z++)
			{
				i = x * 100 + y * 10 + z;
				if (pow(x, 3) + pow(y, 3) + pow(z, 3) == i)
				{
					printf("%d\n", i);
				}
			}
		}
	}
	return 0;
}
