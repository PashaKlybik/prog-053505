#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define len 200
bool minus = 0;

typedef struct item 
{
	int digit;
	struct item* next;
	struct item* prev;
} Item;

typedef struct mnumber 
{
	Item* head;
	Item* tail;
	int n;
} MNumber;

//прототипы всех функций
MNumber CreateMNumber(char* initStr);
void AddDigit(MNumber* number, int digit);
void PrintMNumber(MNumber number);
MNumber Base10toBase8(MNumber n1);
void DeleteMNumber(MNumber* number);
void CheckMinus(char* str);

int main()
{
    printf("Input: ");
    char str[len]; gets(str);
    CheckMinus(str);
	MNumber a = CreateMNumber(str);
    printf("\n");

	MNumber c = Base10toBase8(a);
    if (minus == true)
    {
        printf("\nYour number in Base8 = -");
    }
    else printf("\nYour number in Base8 = ");
	PrintMNumber(c);
	printf("\n");

    DeleteMNumber(&a); 
    DeleteMNumber(&c); 
    return 0;
}

void CheckMinus(char *str)
{
    if (str[0] == '-')
        minus = 1;
}

void DeleteMNumber(MNumber* number) 
{
	Item* temp;
	while (number->n != 0)
	{
		temp = number->tail;
		number->tail = number->tail->prev;
		number->n--;
		if (number->n != 0)
		{
			number->tail->next = NULL;
		}
		else if (number->n == 0)
		{
			number->head = number->tail = NULL;
			number->n = 0;
		}
		free(temp);
	}
}

MNumber CreateMNumber(char* str) 
{
	MNumber number = { NULL, NULL, 0 };
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		if (str[i] != '-')
		{
			AddDigit(&number, str[i] - '0');
		}
	}
	return number;
} 

void AddDigit(MNumber* number, int digit) 
{
	Item* p = (Item*)malloc(sizeof(Item));
	p->digit = digit;
	p->next = p->prev = NULL;
	if (number->head == NULL)
		number->head = number->tail = p;
	else
	{
		number->tail->next = p;
		p->prev = number->tail;
		number->tail = p;
	}
	number->n++;
}

int From10to8(int number) 
{
	int ost, zeloe, arr[100];
	int i = 0, l = 0;
	while (zeloe != 0)
	{
		zeloe = number/8;
		ost = number%8;
		number = zeloe;
		arr[i] = ost;
		i++, l++;
	}
	number = 0;
	for (int i = l-1; i >= 0; i--)
    {
        number *= 10;
        number += arr[i];
    }
    return number;
}

MNumber Base10toBase8(MNumber n1) 
{
	Item* p1 = n1.head;
	int pos = 0, s1, s = 5, i = 0;
    int arr1[s], arr2[s];
	while (p1) 
	{
		s1 = p1->digit; p1 = p1->next;
		arr1[i] = s1;
		i++;
    }
    int ii = i;
    for (int j = 0; j < ii; j++, i--) 
    {
        arr2[j] = arr1[i-1];
    }
    int value = 0;
    for (size_t i = 0; i < ii; ++i) )
    {
        value *= 10;
        value += arr2[i];
    }
    if (minus == true)
    {
        printf("Your number in Base10 = -%d", value);
    }
    else printf("Your number in Base10 = %d", value);


    value = From10to8(value);
    MNumber sum = CreateMNumber("");
    AddDigit(&sum, value);   
	return sum;              
}

void PrintMNumber(MNumber number) 
{
	Item* p = number.tail;
	while (p)
	{
		printf("%d", p->digit);
		p = p->prev;
	}
}