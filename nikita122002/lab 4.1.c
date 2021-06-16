#include <stdio.h>
#define lenth 256
#include <windows.h>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char arr[lenth], letter;
	int i = 0;
	printf_s("Enter sentence:\n");
	while ((letter = getchar()) != '\n')
	{
		if (letter == 'А' || letter == 'а' || letter == 'a' || letter == 'A')
		{
			arr[i] = '.';
			arr[i + 1] = '-';
			arr[i + 2] = ' ';
			arr[i + 3] = '\0';
			i += 3;

		}
		else if (letter == 'B' || letter == 'b' || letter == 'б' || letter == 'Б')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = '.';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (letter == 'W' || letter == 'w' || letter == 'В' || letter == 'в')
		{
			arr[i] = '.';
			arr[i + 1] = '-';
			arr[i + 2] = '-';
			arr[i + 3] = ' ';
			arr[i + 4] = '\0';
			i += 4;
		}
		else if (letter == 'G' || letter == 'g' || letter == 'г' || letter == 'Г')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = '.';
			arr[i + 3] = ' ';
			arr[i + 4] = '\0';
			i += 4;
		}
		else if (letter == 'D' || letter == 'd' || letter == 'д' || letter == 'Д')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = ' ';
			arr[i + 4] = '\0';
			i += 4;
		}
		else if (letter == 'E' || letter == 'e' || letter == 'е' || letter == 'Е' || letter == 'ё' || letter == 'Ё')
		{
			arr[i] = '.';
			arr[i + 1] = ' ';
			arr[i + 2] = '\0';
			i += 2;
		}
		else if (letter == 'V' || letter == 'v' || letter == 'ж' || letter == 'Ж')
		{
			arr[i] = '.';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = '-';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (letter == 'Z' || letter == 'z' || letter == 'з' || letter == 'З')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = '.';
			arr[i + 3] = '.';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (letter == 'I' || letter == 'i' || letter == 'и' || letter == 'И' )
		{
			arr[i] = '.';
			arr[i + 1] = '.';
			arr[i + 2] = ' ';
			arr[i + 3] = '\0';
			i += 3;
		}
		else if (letter == 'J' || letter == 'j' || letter == 'й' || letter == 'Й')
		{
			arr[i] = '.';
			arr[i + 1] = '-';
			arr[i + 2] = '-';
			arr[i + 3] = '-';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (letter == 'K' || letter == 'k' || letter == 'к' || letter == 'К')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = '-';
			arr[i + 3] = ' ';
			arr[i + 4] = '\0';
			i += 4;
		}
		else if (letter == 'L' || letter == 'l' || letter == 'л' || letter == 'Л')
		{
			arr[i] = '.';
			arr[i + 1] = '-';
			arr[i + 2] = '.';
			arr[i + 3] = '.';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (letter == 'M' || letter == 'm' || letter == 'м' || letter == 'М')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = ' ';
			arr[i + 3] = '\0';
			i += 3;
		}
		else if (letter == 'N' || letter == 'n' || letter == 'н' || letter == 'Н')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = ' ';
			arr[i + 3] = '\0';
			i += 3;
		}
		else if (letter == 'O' || letter == 'o' || letter == 'о' || letter == 'О')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = '-';
			arr[i + 3] = ' ';
			arr[i + 4] = '\0';
			i += 4;
		}
		else if (letter == 'P' || letter == 'p' || letter == 'п' || letter == 'П')
		{
			arr[i] = '.';
			arr[i + 1] = '-';
			arr[i + 2] = '-';
			arr[i + 3] = '.';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (letter == 'R' || letter == 'r' || letter == 'р' || letter == 'Р')
		{
			arr[i] = '.';
			arr[i + 1] = '-';
			arr[i + 2] = '.';
			arr[i + 3] = ' ';
			arr[i + 4] = '\0';
			i += 4;
		}
		else if (letter == 'S' || letter == 's' || letter == 'с' || letter == 'С')
		{
			arr[i] = '.';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = ' ';
			arr[i + 4] = '\0';
			i += 4;
		}
		else if (letter == 'T' || letter == 't' || letter == 'т' || letter == 'Т')
		{
			arr[i] = '-';
			arr[i + 1] = ' ';
			arr[i + 2] = '\0';
			i += 2;
		}
		else if (letter == 'U' || letter == 'u' || letter == 'у' || letter == 'У')
		{
			arr[i] = '.';
			arr[i + 1] = '.';
			arr[i + 2] = '-';
			arr[i + 3] = ' ';
			arr[i + 4] = '\0';
			i += 4;
		}
		else if (letter == 'F' || letter == 'f' || letter == 'ф' || letter == 'Ф')
		{
			arr[i] = '.';
			arr[i + 1] = '.';
			arr[i + 2] = '-';
			arr[i + 3] = '.';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (letter == 'H' || letter == 'h' || letter == 'х' || letter == 'Х')
		{
			arr[i] = '.';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = '.';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (letter == 'C' || letter == 'c' || letter == 'ц' || letter == 'Ц')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = '-';
			arr[i + 3] = '.';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (letter == 'Ч' || letter == 'ч' )
		{
		arr[i] = '-';
		arr[i + 1] = '-';
		arr[i + 2] = '-';
		arr[i + 3] = '.';
		arr[i + 4] = ' ';
		arr[i + 5] = '\0';
		i += 5;
		}
		else if (letter == 'Ш' || letter == 'ш')
		{
		arr[i] = '-';
		arr[i + 1] = '-';
		arr[i + 2] = '-';
		arr[i + 3] = '-';
		arr[i + 4] = ' ';
		arr[i + 5] = '\0';
		i += 5;
		}
		else if (letter == 'Q' || letter == 'q' || letter == 'щ' || letter == 'Щ')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = '.';
			arr[i + 3] = '-';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (letter == 'ъ' || letter == 'Ъ')
		{
		arr[i] = '.';
		arr[i + 1] = '-';
		arr[i + 2] = '-';
		arr[i + 3] = '.';
		arr[i + 4] = '-';
		arr[i + 5] = '.';
		arr[i + 6] = ' ';
		arr[i + 7] = '\0';
		i += 7;
		}
		else if (letter == 'Y' || letter == 'y' || letter == 'ы' || letter == 'Ы')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = '-';
			arr[i + 3] = '-';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (letter == 'X' || letter == 'x' || letter == 'ь' || letter == 'Ь')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = '-';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (letter == 'Э' || letter == 'э')
		{
		arr[i] = '.';
		arr[i + 1] = '.';
		arr[i + 2] = '.';
		arr[i + 3] = '-';
		arr[i + 4] = '.';
		arr[i + 5] = '.';
		arr[i + 6] = '.';
		arr[i + 7] = ' ';
		arr[i + 8] = '\0';
		i += 8;
		}
		else if (letter == 'Ю' || letter == 'ю')
		{
		arr[i] = '.';
		arr[i + 1] = '.';
		arr[i + 2] = '-';
		arr[i + 3] = '-';
		arr[i + 4] = ' ';
		arr[i + 5] = '\0';
		i += 5;
		}
		else if (letter == 'я' || letter == 'Я')
		{
		arr[i] = '.';
		arr[i + 1] = '-';
		arr[i + 2] = '.';
		arr[i + 3] = '-';
		arr[i + 4] = ' ';
		arr[i + 5] = '\0';
		i += 5;
		}
		else if (letter == '1')
		{
			arr[i] = '.';
			arr[i + 1] = '-';
			arr[i + 2] = '-';
			arr[i + 3] = '-';
			arr[i + 4] = '-';
			arr[i + 5] = ' ';
			arr[i + 6] = '\0';
			i += 6;
		}
		else if (letter == '2')
		{
			arr[i] = '.';
			arr[i + 1] = '.';
			arr[i + 2] = '-';
			arr[i + 3] = '-';
			arr[i + 4] = '-';
			arr[i + 5] = ' ';
			arr[i + 6] = '\0';
			i += 6;
		}
		else if (letter == '3')
		{
			arr[i] = '.';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = '-';
			arr[i + 4] = '-';
			arr[i + 5] = ' ';
			arr[i + 6] = '\0';
			i += 6;
		}
		else if (letter == '4')
		{
			arr[i] = '.';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = '.';
			arr[i + 4] = '-';
			arr[i + 5] = ' ';
			arr[i + 6] = '\0';
			i += 6;
		}
		else if (letter == '5')
		{
			arr[i] = '.';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = '.';
			arr[i + 4] = '.';
			arr[i + 5] = ' ';
			arr[i + 6] = '\0';
			i += 6;
		}
		else if (letter == '6')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = '.';
			arr[i + 4] = '.';
			arr[i + 5] = ' ';
			arr[i + 6] = '\0';
			i += 6;
		}
		else if (letter == '7')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = '.';
			arr[i + 3] = '.';
			arr[i + 4] = '.';
			arr[i + 5] = ' ';
			arr[i + 6] = '\0';
			i += 6;
		}
		else if (letter == '8')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = '-';
			arr[i + 3] = '.';
			arr[i + 4] = '.';
			arr[i + 5] = ' ';
			arr[i + 6] = '\0';
			i += 6;
		}
		else if (letter == '9')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = '-';
			arr[i + 3] = '-';
			arr[i + 4] = '.';
			arr[i + 5] = ' ';
			arr[i + 6] = '\0';
			i += 6;
		}
		else if (letter == '0')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = '-';
			arr[i + 3] = '-';
			arr[i + 4] = '-';
			arr[i + 5] = ' ';
			arr[i + 6] = '\0';
			i += 6;
		}
		else if (letter == '.')
		{
			arr[i] = '.';
			arr[i + 1] = '-';
			arr[i + 2] = '.';
			arr[i + 3] = '-';
			arr[i + 4] = '.';
			arr[i + 5] = '-';
			arr[i + 6] = ' ';
			arr[i + 7] = '\0';
			i += 7;
		}
		else if (letter == ',')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = '.';
			arr[i + 3] = '.';
			arr[i + 4] = '-';
			arr[i + 5] = '-';
			arr[i + 6] = ' ';
			arr[i + 7] = '\0';
			i += 7;
		}
		else if (letter == ':')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = '-';
			arr[i + 3] = '.';
			arr[i + 4] = '.';
			arr[i + 5] = '.';
			arr[i + 6] = ' ';
			arr[i + 7] = '\0';
			i += 7;
		}
		else if (letter == '?')
		{
			arr[i] = '.';
			arr[i + 1] = '.';
			arr[i + 2] = '-';
			arr[i + 3] = '-';
			arr[i + 4] = '.';
			arr[i + 5] = '.';
			arr[i + 6] = ' ';
			arr[i + 7] = '\0';
			i += 7;
		}
		else if (letter == '-')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = '.';
			arr[i + 4] = '.';
			arr[i + 5] = '-';
			arr[i + 6] = ' ';
			arr[i + 7] = '\0';
			i += 7;
		}
		else if (letter == '/')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = '-';
			arr[i + 4] = '.';
			arr[i + 5] = ' ';
			arr[i + 6] = '\0';
			i += 6;
		}
		else if (letter == ';')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = '-';
			arr[i + 3] = '-';
			arr[i + 4] = '.';
			arr[i + 5] = '-';
			arr[i + 6] = ' ';
			arr[i + 7] = '\0';
			i += 7;
		}
		else if (letter == ' ')
		{
			arr[i] = '/';
			arr[i + 1] = ' ';
			arr[i + 2] = '\0';
			i += 2;
		}
	}
	printf_s("%s", arr);
	getch();
	return 0;
}