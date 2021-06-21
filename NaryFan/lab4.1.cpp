#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <limits.h>

void mem_error() {
	puts("\nНедостаточно памяти");
	_getch();
	exit(0);
}

void input(unsigned char* text)
{
	while (true)
	{
		puts("Ваш текст:");
		unsigned char ch;
		unsigned long counter = 0;
		unsigned char* text2 = NULL;
		while ((ch = _getch()) != 13 && counter < ULONG_MAX)
		{
			if (ch == '\b' && counter > 0)
			{
				putchar(ch);
				putchar(' ');
				putchar(ch);
				if (!(text2 = (unsigned char*)malloc(--counter * sizeof(unsigned char))))
				{
					mem_error();
				}
				for (int i = 0; i < counter; i++)
				{
					text2[i] = text[i];
				}
				free(text);
				text = text2;
				text2 = NULL;
			}
			else if ((ch >= 192 && ch <= 255) || (ch >=32 && ch <= 47) || (ch >= 58 && ch <= 64) || ch == 184 || ch == 168)
			{
				putchar(ch);
				if (counter > 0)
				{
					if (!(text2 = (unsigned char*)malloc(++counter * sizeof(unsigned char))))
					{
						mem_error();
					}
					for (int i = 0; i < counter - 1; i++)
					{
						text2[i] = text[i];
					}
					text2[counter - 1] = ch;
					free(text);
					text = text2;
					text2 = NULL;
				}
				else
				{
					if (!(text = (unsigned char*)malloc(++counter * sizeof(unsigned char))))
					{
						mem_error();
					}
					text[counter - 1] = ch;
				}
			}
		}
		if (text[0] != '\0')
		{
			puts("\nИсправленный текст:");
			for (int i = 0; i < counter; i++)
			{
				if (text[i] == 215 || text[i] == 247 || text[i] == 217 || text[i] == 249 && i != counter - 1)
				{
					switch (text[i + 1])
					{
					case 223:
					case 255:
						text[i + 1] = 224;
						break;
					case 222:
					case 254:
						text[i + 1] = 243;
						break;
					default:
						break;
					}
				}
				else if ((text[i] == 230 || text[i] == 198) || (text[i] == 248 || text[i] == 216) && (text[i + 1] == 219 || text[i + 1] == 251) && i != counter - 1)
					text[i + 1] = 232;
				putchar(text[i]);
			}
			return;
		}
		else
			system("cls");
	}
}

int main(void)
{
	unsigned char* text = NULL;
	/*SetConsoleOutputCP(1251);
	SetConsoleCP(1251);*/
	system("chcp 1251");
	system("cls");
	input(text);
	_getch();
	return 0;
}
