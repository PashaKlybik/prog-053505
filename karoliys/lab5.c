//lab5 task 5.1(3)
#include <stdio.h>
#include <math.h>
#include <locale.h>
typedef struct item {
	char sim;
	struct item* next;
	struct item* prev;
} Item;

typedef struct msim {
	Item* head;
	Item* tail;
	int n;
} MSim;

void AddDigit(MSim* word, char sim)
{
	Item* p = (Item*)malloc(sizeof(Item));
	p->sim = tolower(sim);
	p->next = p->prev = NULL;
	if (word->head == NULL)
		word->head = word->tail = p;
	else {
		word->tail->next = p;
		p->prev = word->tail;
		word->tail = p;
	}
	word->n++;
}

MSim CreateMSim(char initStr[])
{
	MSim word = { NULL, NULL, 0 };
	int n;
	for (n = 0; n <= strlen(initStr) - 1; n++)
		AddDigit(&word, initStr[n]);
	return word;
}

void PrintMSim(MSim word)
{
	Item* p = word.head;
	printf("\nWord: ");
	while (p) {
		printf("%c", p->sim);
		p = p->next;
	}
}
void ClearZnakiMSim(MSim word, int* n)
{
	Item* p = word.head;
	while (p)
	{
		switch (p->sim)
		{
		case '.':
		case ',':
		case ';':
		case ':':
		case '!':
		case '?':
		case ')':
		case ']':
		case '}':
		case '{':
		case '[':
		case '(':
		case ' ':
			p->next->prev = p->prev;
			p->prev->next = p->next;
			(*n)--;
		default:break;
		}
		p = p->next;
	}
}
void CheckSim(MSim word)
{
	Item* pOne = word.head;
	Item* pTwo = word.tail;
	int n = 0;

	while (pOne)
	{
		if (pOne->sim == pTwo->sim)
		{
			n++;
		}
		pOne = pOne->next;
		pTwo = pTwo->prev;
	}
	if (n == word.n)
	{
		printf("\nPalindrome");
	}
	else
	{
		printf("\nnot palindrome");
	}

}
void setString(char* str)
{
	char ch;
	int i = 0;
	puts("\nEnter a string of words: \n");
	while ((ch = getchar()) != '\n')
	{
		str[i++] = ch;
	}
	str[i] = '\0';
}
int main()
{
	setlocale(LC_ALL, "Rus");
	MSim a = CreateMSim("привет я роза азор я тевирп");
	PrintMSim(a);
	ClearZnakiMSim(a, &a.n);
	CheckSim(a);
	char str[1024];
	setString(str);
	MSim b = CreateMSim(str);
	ClearZnakiMSim(b, &b.n);
	CheckSim(b);
}
