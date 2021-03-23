//Геращенко Павел 053505 Лаб. работа №2, вариант 23

#include <stdio.h>

typedef enum
{
	false,
	true
} bool;

void orderTang(int* KgOfTangerine)
{
	bool status = 1;
	char next;
	*KgOfTangerine = 0;
	do
	{
		printf("\nEnter kilograms : ");
		int kg = 0;
		scanf_s("%d", &kg);
		*KgOfTangerine += kg;
		printf("Add more? [Y/N]\n");
		scanf_s(" %c", &next, 2);
		if (next == 'N' || next == 'n') status = 0;
	} while (status);

}

void orderGrape(int* KgOfGrape)
{
	bool status = 1;
	char next;
	*KgOfGrape = 0;
	do
	{
		printf("\nEnter kilograms : ");
		int kg = 0;
		scanf_s("%d", &kg);
		*KgOfGrape += kg;
		printf("Add more? [Y/N]\n");
		scanf_s(" %c", &next, 2);
		if (next == 'N' || next == 'n') status = 0;
	} while (status);

}
void orderPeach(int* KgOfPeach)
{
	bool status = 1;
	char next;
	*KgOfPeach = 0;
	do
	{
		printf("\nEnter kilograms : ");
		int kg = 0;
		scanf_s("%d", &kg);
		*KgOfPeach += kg;
		printf("Add more? [Y/N]\n");
		scanf_s(" %c", &next, 2);
		if (next == 'N' || next == 'n') status = 0;
	} while (status);

}

void cart(int KgOfGrape, int KgOfPeach, int KgOfTangerine)
{
	double priceOfGrape = KgOfGrape * 1.28;
	double priceOfPeach = KgOfPeach * 1.0;
	double priceOfTangerine = KgOfTangerine * 1.14;
	printf("\nGrape : %d kilograms\tprice: %f$ \n", KgOfGrape, priceOfGrape);
	printf("Peach : %d kilograms\tprice: %f$ \n", KgOfPeach, priceOfPeach);
	printf("Tangerine : %d kilograms\tprice: %f$\n", KgOfTangerine, priceOfTangerine);
}

void feedback()
{
	printf("\neFruit company\nNumber of license : 053505\nPhone number : +133722869\ngmail : brawlstars@mail.ru\n");
}

void result(int KgOfGrape, int KgOfPeach, int KgOfTangerine)
{
	double priceOfGrape = KgOfGrape * 1.28;
	double priceOfPeach = KgOfPeach * 1.0;
	double priceOfTangerine = KgOfTangerine * 1.14;
	int delivery = 1;
	int totalkg = KgOfGrape + KgOfPeach + KgOfTangerine;
	double price = priceOfGrape + priceOfPeach + priceOfTangerine;
	if (price > 100)
	{
		printf("\n\nYou have discount 10%!!!\n\n");
		price *= 0.9;
	}
	if (totalkg >= 5 && totalkg < 20) delivery = 3;
	if (totalkg >= 20) delivery = 10 + ((totalkg - 20) * 2);
	double totalprice = delivery + price;

	printf("\nGrape price: %f$ \n", priceOfGrape);
	printf("Peach price: %f$ \n", priceOfPeach);
	printf("Tangerine price: %f$\n", priceOfTangerine);
	printf("Cost of delivery : %d$\n", delivery);
	printf("\n\nTOTAL PRICE OF ORDER : %f$\n", totalprice);

}


int main()
{
	int KgOfGrape = 0, KgOfTangerine = 0, KgOfPeach = 0;
	char nav;
	bool status = 1;
		printf("Hello, welcome to eFruit, the shop of fruits\nHere you can buy : mandarins, grape and peaches\n\n");
	do {
		printf("To order tangerines enter : T\nTo order grape enter : G\nTo order peaches enter : P\n");
		printf("To open your cart enter : C\nTo feedback press : F\n");
		scanf_s(" %c", &nav, 2);
		switch (nav) {
		case 't':
		case 'T': orderTang(&KgOfTangerine); break;
		case 'g':
		case 'G': orderGrape(&KgOfGrape); break;
		case 'p':
		case 'P': orderPeach(&KgOfPeach); break;
		case 'c':
		case 'C': cart(KgOfGrape, KgOfPeach, KgOfTangerine); break;
		case 'f':
		case 'F': feedback(); break;
		}

		printf("\nSomething else? [Y/N]\n");
		scanf_s(" %c", &nav, 2);
		if (nav == 'N' || nav == 'n') {
			result(KgOfGrape, KgOfPeach, KgOfTangerine);
			status = 0;
		}

	} while (status);
	return 0;
}
