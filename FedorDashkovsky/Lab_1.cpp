//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Lab1_C.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


char itoa(int num) {
	return num + '0';
}
int count_numbers(unsigned long long num, unsigned long long k) {
	static unsigned long long counter = 0;
	static unsigned long long size = 10;

	while (num / size > 0)
		size *= 10;

	for (unsigned long long i = size; i > 1; i /= 10) {
		if (++counter == k) {
			return num / i % 10;
		}
	}
	if (++counter == k)
		return num % 10;

	return -1;
}

int main(int argc, char* argv[])
{
	unsigned long long k;
	int res;

	if (argc == 2)
		k = atoi(argv[1]);
	else
		scanf("%llu", &k);

	for (unsigned long long i = 1; i <= k; i++) {
		res = count_numbers(pow(i, 3), k);
		if (res != -1) {
			printf("%d\n", res);
			return 0;
		}
	}
	return 1;
}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
