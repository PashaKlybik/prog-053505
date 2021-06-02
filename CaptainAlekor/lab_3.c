#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char*** CreateSpace(int size)
{
	char*** space = (char***)malloc(sizeof(char**) * size);
	for (int i = 0; i < size; i++)
	{
		space[i] = (char**)malloc(sizeof(char*) * size);
		for (int j = 0; j < size; j++)
		{
			space[i][j] = (char*)malloc(sizeof(char) * size);
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				space[i][j][k] = 0;
			}
		}
	}
	printf("Space has been created\n");
	return space;
}
void RandFill(char*** space, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++) 
			{
				space[i][j][k] = !(rand() % 4);
			}
		}
	}
	printf("Space has been randomly filled\n");
}
void CubeFill(char*** space, int size)
{
	printf("Enter the coordinates of the vertex of the cube:\n");
	int x = 0, y = 0, z = 0, len = 0;
	printf("x: "); scanf_s("%d", &x);
	printf("y: "); scanf_s("%d", &y);
	printf("z: "); scanf_s("%d", &z);
	printf("Enter cube's size: "); scanf_s("%d", &len);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				if (i < x || j < y || k < z) space[i][j][k] = 0;
				else
				{
					if ((i < x + len) && (j < y + len) && (k < z + len)) space[i][j][k] = 1;
					else space[i][j][k] = 0;
				}
			}
		}
	}
	printf("Cube has been created\n");
}
void XYprojection(const char*** space, int size)
{
	putchar('+');
	for (int n = 0; n < size; n++) putchar('-');
	puts("x");
	for (int j = 0; j < size; j++)
	{
		putchar('|');
		for (int i = 0; i < size; i++)
		{
			char isFilled = 0;
			for (int k = 0; k < size; k++)
			{
				if (space[i][j][k])
				{
					isFilled = 1;
					break;
				}
			}
			if (isFilled) printf("1");
			else printf("0");
		}
		printf("\n");
	}
	printf("y\n");
}
void XZprojection(const char*** space, int size)
{
	putchar('+');
	for (int n = 0; n < size; n++) putchar('-');
	puts("x");
	for (int k = 0; k < size; k++)
	{
		putchar('|');
		for (int i = 0; i < size; i++)
		{
			char isFilled = 0;
			for (int j = 0; j < size; j++)
			{
				if (space[i][j][k])
				{
					isFilled = 1;
					break;
				}
			}
			if (isFilled) printf("1");
			else printf("0");
		}
		printf("\n");
	}
	printf("z\n");
}
void YZprojection(const char*** space, int size)
{
	putchar('+');
	for (int n = 0; n < size; n++) putchar('-');
	puts("y");
	for (int k = 0; k < size; k++)
	{
		putchar('|');
		for (int j = 0; j < size; j++)
		{
			char isFilled = 0;
			for (int i = 0; i < size; i++)
			{
				if (space[i][j][k])
				{
					isFilled = 1;
					break;
				}
			}
			if (isFilled) printf("1");
			else printf("0");
		}
		printf("\n");
	}
	printf("z\n");
}
void ClearSpace(char*** space, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				space[i][j][k] = 0;
			}
		}
	}
	printf("Space has been cleared\n");
}
void Wait()
{
	printf("Press any button to continue\n");
	getch();
}


void main() 
{
	int size, choice = 42;
	do
	{
		choice = 42;
		system("cls");
		printf("Enter spaces's size: ");
		scanf_s("%d", &size);
		char*** space = CreateSpace(size);
		Wait();
		do
		{
			system("cls");
			if (choice == 0 || choice == 7) break;
			printf("Select an action:\n1 - Randomly fill space\n2 - Create a cube in the space\n3 - Clear space\n4 - Show XY projection\n");
			printf("5 - Show XZ projection\n6 - Show YZ projection\n7 - Create new space\n0 - Finish work\n");
			scanf_s("%d", &choice);
			switch (choice)
			{
			case 1:
				system("cls");
				RandFill(space, size);
				Wait();
				break;
			case 2:
				system("cls");
				CubeFill(space, size);
				Wait();
				break;
			case 3:
				system("cls");
				ClearSpace(space, size);
				Wait();
				break;
			case 4:
				system("cls");
				XYprojection(space, size);
				Wait();
				break;
			case 5:
				system("cls");
				XZprojection(space, size);
				Wait();
				break;
			case 6:
				system("cls");
				YZprojection(space, size);
				Wait();
				break;
			default:
				printf("Invalid input, try again\n");
				Wait();
				break;
			case 0:
			case 7:;
			}
		} while (1);
		if (choice == 0) break;
	} while (1);
}