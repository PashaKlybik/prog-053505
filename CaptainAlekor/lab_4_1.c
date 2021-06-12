#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char* CorrectMistakes()
{
	char input[255], ch, toCap = 0, prevCh = 0;
	int len = 0;
	printf("Enter text:\n>> ");
	while (1)
	{
		if (prevCh == 0 && len < 253) ch = getchar();
		else ch = prevCh;
		if (ch == '\n') break;
		switch (ch)
		{
		case '.':
		case '!':
		case '?':
			toCap = 1;
		case ',':
		case ':':
		case ';':
			if (prevCh != '.' && prevCh != '!' && prevCh != '?' && prevCh != 0) toCap = 0;
			input[len++] = ch;
		case ' ':
			input[len++] = ' ';
			do
			{
				ch = getchar();
				if (ch == '\n') break;
			} while (ch == ' ');
			prevCh = ch;
			break;
		default:
			prevCh = 0;
			if (toCap)
			{
				input[len++] = toupper(ch);
				toCap = 0;
			}
			else input[len++] = ch;
		}
	}
	input[len] = '\0';
	printf("Corrected text:\n%s\n", input);
	return input;
}

void main()
{
	char* text = CorrectMistakes();
}