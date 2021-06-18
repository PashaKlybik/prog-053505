#include "common_interface.h"

void clrscr(void)
{
	system("cls||clear");
}

void header(char* new_path, char* hint)
{
	clrscr();
	puts(new_path);
	puts(delimetr);
	puts(hint);
	puts(delimetr);
}

void program_info(void)
{
	header("Menu->Programm_Info", "ESC -- return to previous menu");
	puts("HotelTracer V 1.2.\nSimple tool created to help travelers and hotel company's promoters");
	puts("Contact mail: nikitnvladimmir@gmail.com");
	puts("--\nCopyright C 2020 by AVPa1ly. All rights reserved.");
	while (1)
	{
		if (_getch() == esc)
			return;
	}
}

void get_unsigned(int* num)
{
	while (1)
	{
		char* nums = (char*)malloc(3 * sizeof(char));
		nums[0] = '\0';
		char ch;
		int counter = 0;
		while ((ch = _getch()) != 13)
		{
			if ((ch == '\b') && counter > 0)
			{
				putchar(ch);
				putchar(' ');
				putchar(ch);
				nums[--counter] = '\0';
			}
			else if (ch > 47 && ch < 58 && counter < 10)
			{
				putchar(ch);
				nums[counter] = ch;
				counter++;
			}
		}
		if (nums[0] != '\0')
		{
			putchar('\n');
			*num = atoi(nums);
			free(nums);
			return;
		}
		puts("");
		return;
	}
}

void free_mem(void)
{
	for (int i = 0; i < NUM_OF_WEBS; i++)
	{
		clear(webs[i]);
	}
}