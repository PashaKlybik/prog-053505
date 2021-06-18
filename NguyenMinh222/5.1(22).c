#define _CRT_SECURE_NO_WARNINGS
#define QMAX 100
#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<locale.h>
#include<time.h>
#include<windows.h>
#include<stdbool.h>
struct queue {
	int qu[QMAX];
	int rear, frnt;
}queue;

void init(struct queue* q) {
	q->frnt = 1;
	q->rear = 0;
	return;
}
void insert(struct queue* q, int x) {
	if (q->rear < QMAX - 1) {
		q->rear++;
		q->qu[q->rear] = x;
	}
	else
		printf("Очередь полна!\n");
	return;
}
int isempty(struct queue* q) {
	if (q->rear < q->frnt)    return 1;
	else  return 0;
}
void print(struct queue* q) {
	int h;
	if (isempty(q) == 1) {
		return;
	}
	for (h = q->frnt; h <= q->rear; h++)
		printf("%d ", q->qu[h]);
	printf("\n\n");
	return;
}
int remove(struct queue* q) {
	int x;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
		return(0);
	}
	x = q->qu[q->frnt];
	q->frnt++;
	return x;
}
int add(struct queue* q)
{
	srand(time(NULL));
	int j = rand() % 10 ;
	insert(q,j);
}

void hirurg(float *y,float *t)
{
	struct queue* p;
	int a,b;
	int Time = 0,Time1;
	int Time2 = 0, Time22;
	
	p = (struct queue*)malloc(sizeof(struct queue));
	init(p);
	print(p);
	printf("Обновлено. Очередь в хирургию:");
	srand(time(NULL));
	*y = rand() % 8 + 1;
	for (int i = 1;i <= *y;i++)
	{
		insert(p,i);
	}
	printf("\n");
	print(p);
	int g=0;
	for (int j = 0;j < 3;j++){
		int k = rand() % 3;
		a = remove(p);
		Time1 = rand() % 3000;
		Time += Time1;
		Sleep(Time1);
		system("cls");
		printf("Обновлено. Очередь в хирургию:\n");
		print(p);
		if ( g == k)
		{
			b = add(p);
			Time22 = rand() % 1000;
			Time2 += Time22;
			Sleep(Time2);
			system("cls");
			printf("Обновлено. Очередь в хирургию:\n");
			print(p);
		}
		
	}
	 *t = Time / 1000;
}
void terapeft(float *b, float *t1)
{
	struct queue* p;
	int q,v;
	int Time2 = 0, Time22;
	p = (struct queue*)malloc(sizeof(struct queue));
	init(p);
	print(p);
	printf("Обновлено. Очередь к терапевту:");
	srand(time(NULL));
	*b = rand() % 10 + 1.0;
	for (int i = 1;i <= *b;i++)
	{
		insert(p, i);
	}
	printf("\n");
	print(p);
	int Time = 0, Time1;
	int g = 0;
	for (int j = 0;j < 5;j++) {
		int k = rand() % 3;
		q = remove(p);
		Time1 = rand() % 5000;
		Time += Time1;
		Sleep(Time1);
		system("cls");
		printf("Обновлено. Очередь к терапевту:\n");
		print(p);
		if (g == k)
		{
			v = add(p);
			Time22 = rand() % 1000;
			Time2 += Time22;
			Sleep(Time2);
			system("cls");
			printf("Обновлено. Очередь к терапевту:\n");
			print(p);
		}
	}
	*t1 = Time / 1000;
}
void psycho(float *c, float *t2)
{
	struct queue* p;
	int h,b;
	int Time2 = 0, Time22;
	p = (struct queue*)malloc(sizeof(struct queue));
	init(p);
	print(p);
	printf("Обновлено. Очередь к психологу:");
	srand(time(NULL));
	*c = rand() % 14 + 1;
	for (int i = 1;i <= *c;i++)
	{
		insert(p, i);
	}
	printf("\n");
	print(p);
	int Time = 0, Time1;
	int g = 0;
	for (int j = 0;j < 4;j++) {
		int k = rand() % 3;
		h = remove(p);
		Time1 = rand() % 5000;
		Time += Time1;
		Sleep(Time1);
		system("cls");
		printf("Обновлено. Очередь к психологу:\n");
		print(p);
		if (g == k)
		{
			b = add(p);
			Time22 = rand() % 1000;
			Time2 += Time22;
			Sleep(Time2);
			system("cls");
			printf("Обновлено. Очередь в психологу:\n");
			print(p);
		}
	}
	*t2 = Time / 1000;
}
void dentist(float *n, float *t3)
{
	struct queue* p;
	int o,b;
	
	p = (struct queue*)malloc(sizeof(struct queue));
	init(p);
	print(p);
	printf("Обновлено. Очередь к дантисту:");
	srand(time(NULL));
	*n =rand() % 12 + 1;
	for (int i = 1;i <= *n;i++)
	{
		insert(p, i);
	}
	printf("\n");
	print(p);
	int Time = 0, Time1;
	int Time2 = 0, Time22;
	for (int j = 0;j < 5;j++) {
		int k = rand() % 3;
		o = remove(p);
		Time1 = rand() % 5000;
		Time += Time1;
		Sleep(Time1);
		system("cls");
		printf("Обновлено. Очередь к дантисту:\n");
		print(p);
		int g = 0;
		if (g == k)
		{
			b = add(p);
			Time22 = rand() % 1000;
			Time2 += Time22;
			Sleep(Time2);
			system("cls");
			printf("Обновлено. Очередь в дантисту:\n");
			print(p);
		}
	}
	*t3 = Time / 1000;
}
void nevropotolog(float *m, float *t4)
{
	struct queue* p;
	int l,b;
	int Time2 = 0, Time22;
	p = (struct queue*)malloc(sizeof(struct queue));
	init(p);
	print(p);
	printf("Обновлено. Очередь в невропотологу:");
	srand(time(NULL));
	*m = rand() % 11 + 1;
	for (int i = 1;i <= *m;i++)
	{
		insert(p, i);
	}
	printf("\n");
	print(p);
	int Time = 0, Time1;
	int g = 0;
	for (int j = 0;j < 3;j++) {
		int k = rand() % 3;
		l = remove(p);
		Time1 = rand() % 5000;
		Time += Time1;
		Sleep(Time1);
		system("cls");
		printf("Обновлено. Очередь к невропотологу:\n");
		print(p);
		if (g == k)
		{
			b = add(p);
			Time22 = rand() % 1000;
			Time2 += Time22;
			Sleep(Time2);
			system("cls");
			printf("Обновлено. Очередь к невропотологу:\n");
			print(p);
		}
	}
	*t4 = Time / 1000;
}

float y,b,c,n,m;
float t, t1, t2, t3, t4;
float t5=0;
int main(float t) {
	char* locale = setlocale(LC_ALL,"ru");
	bool a = true;
	system("chcp 1251");
	system("cls");
	int Time;
	int timeo = 0;
	while (a) {
		Time = rand() % 3000;
		timeo += Time;
		Sleep(Time);
		
		hirurg(&y,&t);
	    terapeft(&b,&t1);
		psycho(&c,&t2);
		dentist(&n,&t3);
		nevropotolog(&m,&t4);
	    a=false;
	}
	t5 = t + t1 + t2 + t3 + t4;
	printf("Время для прохождения всей медкомиссии: %.2f min",t5);
	
	return 0;
}
