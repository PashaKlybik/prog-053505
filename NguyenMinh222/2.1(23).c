#include<stdio.h>
#include<math.h>
#include<string.h>
#include<locale.h>
void Mandarin(float *a)
{   
	system("cls");
	printf("������� �� ���������� �� ������ ������ (���� ����������: 1,14$ �� ��)?\n");
	scanf_s("%f",&*a);
	printf("����, ���� ����� �� ���������: %.2f$\n",*a * 1.14);
	
}
void Persiki(float *q)
{
	system("cls");
	printf("������� �� �������� �� ������ ������ (���� ��������: 1,00$ �� ��)?\n");
	scanf_s("%f", &*q);
	printf("����, ���� ����� �� �������: %.2f$\n", *q * 1.00);
	
}
void Vinogr(float *e)
{
	system("cls");
	
	printf("������� �� ���������� �� ������ ������ (���� ���������: 1,28$ �� ��)?\n");
	scanf_s("%f", &*e);
	printf("����, ���� ����� �� ��������: %.2f$\n", *e * 1.28);

}
float a, q, e;
void Korzina(float e, float a, float q,float *b, float *d )
{
			 *b = a + q + e;
			 *d = a*1.14+ q * 1.00 + e * 1.28;//����� ������
			 printf("� ����� ��� ����� ����� %.2f �� � �������� � %.2f$\n",*b,*d);
}
void Raschet(float e, float a, float q,float b, float d)
{
	float n = 0.0, m = 0.0;
	printf("���������(��) - 1,14$\n�������(��) - 1,00$\n��������(��) - 1,28$\n");
	printf("��� �����: ��������� %.2f�� - %.2f$\n\t   ������� %.2f�� - %.2f$\n\t   �������� %.2f�� - %.2f$\n", a, a * 1.14, q, q * 1.00, e,e*1.28 );
	if (d >= 100)
	{   
		m = d * 0.9;
		printf("��� ��� ��� ����� ���� 99,99$, �� �� ������������� ������ � 10'%' �� �������� ���� (�������� ����� ��������).\n����� � �����(��� ����� ��������): %.2f$\n",m);
	}
	else {
		m = d;
		printf("��� ��� ���� ����� ������ 100$, �� � ��� ��� ������. ����� � �����(��� ����� ��������): %.2f$\n", m);
	}
	if (b<5)
	{   
		n = m + 1;
		printf("��� ����� ����� ����� 5 ��, ������� �������� � ��������� ������ ��� �������� � 1$\n");
	}
	else if (b >= 5 && b <= 20)
	{  
		n = m + 3;
		printf("��� ����� ����� �� 5 �� 20 ��, ������� �������� � ��������� ������ ��� �������� � 3$\n");
	}
	else if (b >20)
	{   
		n= m + 10 + (b - 20) * 2;
		printf("��� ����� ����� ������ 20 ��, ������� �������� � ��������� ������ ��� �������� � 10$+2$ �� ������ ���������\n");	
	}
	printf("����� ��������� ������: %.2f$\n",n);
}
void Svyaz()
{
	printf("�������� ������� EFruit\n����� ��������:��-77-01-015296\n�����: ��������, �����, ���������, 56\n��������: +375-29-456-18-23\n���� ������: �������������, ��� ����� � ��������\n");
	printf("����: efruit.by\nE-mail: inf0@efruit.com\n");
}
float a,q,e,b,d;
int main()
{
	char *locale=setlocale(LC_ALL,"ru");
	
	char pr;
	printf("������������, ��� ������������ ����������� EFruit �� ������� ������� ����� ��������!\n��� ����������� ������� �� ������ 'p'.\n��� ������ ������� ������ 'v'.\n");
	scanf_s("%c",&pr,1);
	if (pr == 'v')
	{
		return 0;
	}
	while (pr != 'p')
	{
		printf("��� ����������� �� ������ ������ �� 'p'!!!\n");
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
				printf("�������� ������ ��� �������:\n");
				printf(" 1.����� ����������.\n 2.����� ��������.\n 3.����� ����������.\n 4.�������(���-�� ���������� ��������� � �� ���������).\n 5.������ ��������� ������.\n 6.�������� �����.\n 7.����� �� ����������.\n");
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
				printf("������ ����������? ��� ����������� ������� p:\n");
				scanf_s(" %c", &agree, 1);
			} while (agree == 'p');	  
	}
	
	system("pause");


}
