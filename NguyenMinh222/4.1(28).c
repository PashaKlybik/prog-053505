#include<stdio.h>
#include<locale.h>
char* swap_min_max(char* s);
int main()
{
	char* locale = setlocale(LC_ALL, "ru");
	char text[100],text1[200],text2[100];
	printf("Введите текст\n");
	fgets(text,100,stdin);
	for (int i = 0;i < 100;i++)
	{    
		if (text[i] == '\n')
		{
			text[i] = '\0';
			break;
		}
	}
	for (int i = 0; i < strlen(text);i++)
	{
		
		while (text[i] < 32 || (text[i] > 32 && text[i] < 45) || (text[i] > 45 && text[i] < 65) || (text[i] > 90 && text[i] < 97) || text[i] > 122)
		{
			system("cls");
			printf("Введите предложения только из букв!\n");
			fgets(text, 100,stdin);
			for (int i = 0;i < 100;i++)
			{
				if (text[i] == '\n')
				{
					text[i] = '\0';
					break;
				}
			}
		}
	}
	printf("Первое предложение: %s\n",text);
	swap_min_max(text);
	printf("Замена самого длинного слова на самое короткое: ");
	puts(text);
	fgets(text1,100,stdin);
	for (int i = 0;i < 200;i++)
	{
		if (text1[i] == '\n')
		{
			text1[i] = '\0';
			break;
		}
	}
	for (int i = 0; i < strlen(text1);i++)
	{
		while (text1[i] < 32 || (text1[i] > 32 && text1[i] < 45) || (text1[i] > 45 && text1[i] < 65) || (text1[i] > 90 && text1[i] < 97) || text1[i] > 122)
		{
			system("cls");
			printf("Введите предложения только из букв!\n");
			fgets(text1,100,stdin);
			for (int i = 0;i < 100;i++)
			{
				if (text1[i] == '\n')
				{
					text1[i] = '\0';
					break;
				}
			}
		}
	}
	printf("Второе предложение: %s\n", text1);
	swap_min_max(text1);
	printf("Замена самого длинного слова на самое короткое: ");
	puts(text1);
	fgets(text2,100,stdin);
	for (int i = 0;i < 100;i++)
	{
		if (text2[i] == '\n')
		{
			text2[i] = '\0';
			break;
		}
	}
	for (int i = 0; i < strlen(text2);i++)
	{
		while (text2[i] < 32 || (text2[i] > 32 && text2[i] < 45) || (text2[i] > 45 && text2[i] < 65) || (text2[i] > 90 && text2[i] < 97) || text2[i] > 122)
		{
			system("cls");
			printf("Введите предложения только из букв!\n");
			fgets(text2,100,stdin);
			for (int i = 0;i < 100;i++)
			{
				if (text2[i] == '\n')
				{
					text2[i] = '\0';
					break;
				}
			}
		}
	}
	printf("Третье предложение: %s\n", text2);
	swap_min_max(text2);
	printf("Замена самого длинного слова на самое короткое: ");
	puts(text2);
	printf("\nВесь текст: %s. %s. %s.", text,text1,text2);
	char TEXT[512];
	snprintf(TEXT, sizeof TEXT, "%s %s %s", text,text1,text2);
	char* ptr = strtok(TEXT, " .,!?");
	char* max = ptr, * min = "0",* min1="1",* MIN="0";
	do {
		if (strlen(max) < strlen(ptr))
			max = ptr;
		else  
		{
			min1 = min;
			min = ptr;

			if (strlen(min1) > strlen(min))
			{
				MIN = min;
			}
			{
				MIN = min1;
			}
		}
	} while (ptr = strtok(NULL, " .,!?"));
	printf("\nСамое длинное слово: %s.\tКоличество символов: %d\n", max,strlen(max));
	printf("Самое короткое слово: %s.\tКоличество символов: %d\n", MIN, strlen(MIN));
}
char* swap_min_max(char* s) {
	int   n1 = 0, n2 = 0, k = 0;
	char* p1 = "0", * p2 = "0", * e1 = "0", * e2 = "0";
	char* t, c, * p = s;
	do {
		if (*p && !(*p == ' ' || *p == '.' || *p == ',' || *p == '!' || *p == '?'))
			++k;
		else if (k > 0) {
			if ((k < n1) || !n1) {
				n1 = k;
				p1 = p - k;
				e1 = p;
			}

			if (k > n2) {
				n2 = k;
				p2 = p - k;
				e2 = p;
			}
			k = 0;
		}

	} while (*p++ != '\0');

	if (p1 > p2) {
		t = p1, p1 = p2, p2 = t;
		t = e1, e1 = e2, e2 = t;
	}

	for (; p2 != e2; p2++) {
		for (p = p2; p > p1; p--) {
			c = *p;
			*p = *(p - 1);
			*(p - 1) = c;
		}
		p1++;
		e1++;
	}

	for (--e2; p1 != e1; --e1) {
		for (p = p1; p < e2; ++p) {
			c = *p;
			*p = *(p + 1);
			*(p + 1) = c;
		}
	}
	return s;
}

