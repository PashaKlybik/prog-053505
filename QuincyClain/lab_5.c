#include<stdio.h>
#include<Windows.h>
#include<math.h>
#include<conio.h>
struct chislo {
	char c;
	chislo* nx;
	chislo* pr;
};
void create(chislo** t, chislo** h) {
	chislo* n;
	char a = ' ';
	printf("Введите число\n");
	while (1) {

		if (!(n = (chislo*)calloc(1, sizeof(chislo))))
		{
			puts("Нет свободной памяти");
			return;
		}
		scanf("%c", &a);
		if (a == '\n') {
			return;
		}
		n->c = a;
		if (!*t || !*h)   // очередь еще не создана
		{
			*t = n;          // указатель на хвост очереди
			*h = n;          // указатель на голову очереди
		}
		else
		{
			n->nx = *t;     // указатель на элемент (хвост) очереди
			(*t)->pr = n;   // хвост указывает на новый элемент
			*t = n;         // передвигаем указатель хвоста на новый элемент
		}
	}

}
void show(chislo* h) {
	do {
		printf("%c", h->c);
		h = h->pr;
	} while (h);
	printf("\n");
}

int NOD(chislo* t1, chislo* h1, chislo* t2, chislo* h2) {
	int ch1 = 0, ch2 = 0, min, trig = 0;
	int l = 1;
	do {
		ch1 += (t1->c - '0') * l;
		l *= 10;
		t1 = t1->nx;
	} while (t1);
	l = 1;
	do {
		ch2 += (t2->c - '0') * l;
		l *= 10;
		t2 = t2->nx;
	} while (t2);
	ch1 = abs(ch1);
	ch2 = abs(ch2);
	if (ch1 > ch2) {
		min = ch2;
	}
	else {
		min = ch1;
	}
	while (min != 1) {
		if ((ch1 % min == 0) && (ch2 % min == 0)) {
			trig = 1;
			break;
		}
		min--;
	}
	return trig;
}

int main() {
	system("chcp 1251>null");
	chislo* t1, * h1, * t2, * h2;
	t1 = t2 = h1 = h2 = nullptr;
	create(&t1, &h1);
	create(&t2, &h2);
	system("cls");
	printf("Первое число\n");
	show(h1);
	printf("Второе число\n");
	show(h2);
	if (NOD(t1, h1, t2, h2) == 1) {
		printf("Не взаимно простые\n");
	}
	else {
		printf("Взаимно простые\n");
	}
	_getch();
	return 0;
}