#include<stdio.h>
#include<math.h>
#include<string.h>
#include<locale.h>
void Mandarin(float *a)
{   
	system("cls");
	printf("Сколько кг мандаринов вы хотели купить (цена мандаринов: 1,14$ за кг)?\n");
	scanf_s("%f",&*a);
	printf("Итак, ваша сумма за мандарины: %.2f$\n",*a * 1.14);
	
}
void Persiki(float *q)
{
	system("cls");
	printf("Сколько кг персиков вы хотели купить (цена персиков: 1,00$ за кг)?\n");
	scanf_s("%f", &*q);
	printf("Итак, ваша сумма за персики: %.2f$\n", *q * 1.00);
	
}
void Vinogr(float *e)
{
	system("cls");
	
	printf("Сколько кг виноградов вы хотели купить (цена винограда: 1,28$ за кг)?\n");
	scanf_s("%f", &*e);
	printf("Итак, ваша сумма за виноград: %.2f$\n", *e * 1.28);

}
float a, q, e;
void Korzina(float e, float a, float q,float *b, float *d )
{
			 *b = a + q + e;
			 *d = a*1.14+ q * 1.00 + e * 1.28;//сумма заказа
			 printf("В сумме ваш заказ весит %.2f кг и обойдётся в %.2f$\n",*b,*d);
}
void Raschet(float e, float a, float q,float b, float d)
{
	float n = 0.0, m = 0.0;
	printf("Мандарины(кг) - 1,14$\nПерсики(кг) - 1,00$\nВиноград(кг) - 1,28$\n");
	printf("Ваш заказ: Мандарины %.2fкг - %.2f$\n\t   Персики %.2fкг - %.2f$\n\t   Виноград %.2fкг - %.2f$\n", a, a * 1.14, q, q * 1.00, e,e*1.28 );
	if (d >= 100)
	{   
		m = d * 0.9;
		printf("Так как ваш заказ выше 99,99$, то мы предоставляем скидку в 10'%' от конечной цены (исключая сумму доставки).\nСумма в итоге(без суммы доставки): %.2f$\n",m);
	}
	else {
		m = d;
		printf("Так как ваша сумма меньше 100$, то у вас нет скидки. Сумма в итоге(без суммы доставки): %.2f$\n", m);
	}
	if (b<5)
	{   
		n = m + 1;
		printf("Ваш заказ весит менее 5 кг, поэтому доставка и обработка заказа вам обойдётся в 1$\n");
	}
	else if (b >= 5 && b <= 20)
	{  
		n = m + 3;
		printf("Ваш заказ весит от 5 до 20 кг, поэтому доставка и обработка заказа вам обойдётся в 3$\n");
	}
	else if (b >20)
	{   
		n= m + 10 + (b - 20) * 2;
		printf("Ваш заказ весит больше 20 кг, поэтому доставка и обработка заказа вам обойдётся в 10$+2$ за каждый килограмм\n");	
	}
	printf("Общая стоимость заказа: %.2f$\n",n);
}
void Svyaz()
{
	printf("Интернет магазин EFruit\nНомер лицензии:ЛО-77-01-015296\nАдрес: Беларусь, Минск, Люцинская, 56\nТелефоны: +375-29-456-18-23\nЧасы работы: Круглосуточно, без обеда и выходных\n");
	printf("Сайт: efruit.by\nE-mail: inf0@efruit.com\n");
}
float a,q,e,b,d;
int main()
{
	char *locale=setlocale(LC_ALL,"ru");
	
	char pr;
	printf("Здравствуйте, вас приветствует предприятие EFruit по продаже фруктов через интернет!\nДля продолжения нажмите на кнопку 'p'.\nДля выхода нажмите кнопку 'v'.\n");
	scanf_s("%c",&pr,1);
	if (pr == 'v')
	{
		return 0;
	}
	while (pr != 'p')
	{
		printf("Для продолжения вы должны нажать на 'p'!!!\n");
		scanf_s("%c", &pr,1);
		if (pr == 'v')
		{
			return 0;
		}
		system("cls");
	}
	system("cls");
	
	char agree;
	if (pr == 'p')
	{    
			do
			{
				system("cls");
				printf("Выберете нужную вам функцию:\n");
				printf(" 1.Заказ мандаринов.\n 2.Заказ персиков.\n 3.Заказ виноградов.\n 4.Корзина(кол-во заказанных продуктов и их стоимость).\n 5.Расчёт стоимости заказа.\n 6.Обратная связь.\n 7.Выход из прогграммы.\n");
				int c;
				scanf_s("%d", &c);
				system("cls");
				switch (c)
				{
				case 1: Mandarin(&a); break;
				case 2: Persiki(&q);break;
				case 3: Vinogr(&e); break;
				case 4: Korzina(e, a, q, &b, &d); break;
				case 5: Raschet(e, a, q, b, d);break;
				case 6: Svyaz();break;
				case 7: return 0; break;
				default: break;
				}
				printf("Хотите продолжить? Для продолжения нажмите p:\n");
				scanf_s(" %c", &agree, 1);
			} while (agree == 'p');	  
	}
	
	system("pause");


}
