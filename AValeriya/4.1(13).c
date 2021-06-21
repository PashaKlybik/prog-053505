#include <stdio.h>
#include <locale.h>
static char* sot[] = { "��","��","��","������",
            "���","����", "���","�����","�����" };
static char* desiat[] = { " �������"," �������"," �����"," ���"," ����",
               " ���"," �����"," ����" };
static char* edm[] = { ""," ��"," ��"," ��"," �����"," ���"," ����",
            " ���"," �����",
            " �����"," �����"," ����������"," ���������"," ���������",
            " �����������"," ���������"," ����������"," ���������"," �����������"," �����������" };
static char* edw[] = { " ����"," ���" };
long atol(char* b);

void ImenitelVinitelPadez(int L, int n, char* s) // ������������ & ����������� ������
{
    int R, ns, nd;
    char* p;
    int M;
    M = L / 1000;
    R = L % 1000;
    if (M != 0) ImenitelVinitelPadez(M, n + 1, s);
    if (R == 0) return;
    ns = R / 100;
    if (ns) sprintf_s(s + strlen(s), " %s", sot[ns - 1]);
    if (ns == 1) strcat(s, "o");
    if (ns == 2) strcat(s, "����");
    if (ns == 3) strcat(s, "����");
    if (ns == 4) strcat(s, "���");
    if (ns >= 5) strcat(s, "����");
    R = R % 100;
    nd = R / 10;
    if (nd >= 2)
    {
        strcat(s, desiat[nd - 2]);
        if (nd == 2 || nd == 3) strcat(s, "�");
        if (nd >= 5 && nd <= 8) strcat(s, "������");
        if (nd == 9) strcat(s, "�����");
        R = R % 10;
    }
    if (n == 1 && R > 0 && R < 3) p = edw[R - 1];
    else p = edm[R];
    strcat(s, p);
    if (R == 1) strcat(s, "��");
    if (R == 2) strcat(s, "a");
    if (R == 3) strcat(s, "�");
    if (R == 4) strcat(s, "e");
    if (R > 4) strcat(s, "�");
}

void RoditelPadez(unsigned long L, int n, char* s) //����������� �����
{
    int R, ns, nd;
    char* p;
    unsigned long M;
    M = L / 1000;
    R = L % 1000;
    if (M != 0) RoditelPadez(M, n + 1, s);
    if (R == 0) return;
    ns = R / 100;
    if (ns) sprintf_s(s + strlen(s), " %s", sot[ns - 1]);
    if (ns == 1) strcat(s, "�");
    if (ns == 2) strcat(s, "�����");
    if (ns == 3) strcat(s, "�����");
    if (ns == 4) strcat(s, "����");
    if (ns >= 5) strcat(s, "����");
    R = R % 100;
    nd = R / 10;
    if (nd >= 2)
    {
        strcat(s, desiat[nd - 2]);
        if (nd == 2 || nd == 3) strcat(s, "�");
        if (nd == 4) strcat(s, "a");
        if (nd >= 5 && nd <= 8) strcat(s, "�������");
        if (nd == 9) strcat(s, "��������");
        R = R % 10;
    }
    if (n == 1 && R > 0 && R < 3) p = edw[R - 1];
    else p = edm[R];
    strcat(s, p);
    if (R == 1) strcat(s, "����");
    if (R == 2) strcat(s, "��");
    if (R == 3 || R == 4) strcat(s, "��");
    if (R > 4) strcat(s, "�");
}

void DatelPadez(unsigned long L, int n, char* s) // ��������� �����
{
    int R, ns, nd;
    char* p;
    unsigned long M;
    M = L / 1000;
    R = L % 1000;
    if (M != 0) DatelPadez (M, n + 1, s);
    if (R == 0) return;
    ns = R / 100;
    if (ns) sprintf_s(s + strlen(s), " %s", sot[ns - 1]);
    if (ns == 1) strcat(s, "��");
    if (ns == 2) strcat(s, "������");
    if (ns == 3) strcat(s, "������");
    if (ns == 4) strcat(s, "�����");
    if (ns >= 5) strcat(s, "����");
    R = R % 100;
    nd = R / 10;
    if (nd >= 2)
    {
        strcat(s, desiat[nd - 2]);
        if (nd == 2 || nd == 3) strcat(s, "�");
        if (nd == 4) strcat(s, "a");
        if (nd >= 5 && nd <= 8) strcat(s, "�������");
        if (nd == 9) strcat(s, "��������");
        R = R % 10;
    }
    if (n == 1 && R > 0 && R < 3) p = edw[R - 1];
    else p = edm[R];
    strcat(s, p);
    if (R == 1) strcat(s, "����");
    if (R == 2) strcat(s, "��");
    if (R == 3 || R == 4) strcat(s, "��");
    if (R > 4) strcat(s, "�");
}

void TvoritelPadez(unsigned long L, int n, char* s) // ������������ �����
{
    int R, ns, nd;
    char* p;
    unsigned long M;
    M = L / 1000;
    R = L % 1000;
    if (M != 0) TvoritelPadez(M, n + 1, s);
    if (R == 0) return;
    ns = R / 100;
    if (ns) sprintf_s(s + strlen(s), " %s", sot[ns - 1]);
    if (ns == 1) strcat(s, "�");
    if (ns == 2) strcat(s, "�������");
    if (ns == 3) strcat(s, "�������");
    if (ns == 4) strcat(s, "������");
    if (ns >= 5) strcat(s, "������");
    R = R % 100;
    nd = R / 10;
    if (nd >= 2)
    {
        strcat(s, desiat[nd - 2]);
        if (nd == 2 || nd == 3) strcat(s, "��");
        if (nd == 4) strcat(s, "a");
        if (nd >= 5 && nd <= 8) strcat(s, "��������");
        if (nd == 9) strcat(s, "���������");
        R = R % 10;
    }
    if (n == 1 && R > 0 && R < 3) p = edw[R - 1];
    else p = edm[R];
    strcat(s, p);
    if (R == 1) strcat(s, "���");
    if (R == 2) strcat(s, "���");
    if (R == 3) strcat(s, "���");
    if (R == 4) strcat(s, "���");
    if (R > 4) strcat(s, "��");
}

void PredlozPadez(unsigned long L, int n, char* s) // ���������� �����
{
    int R, ns, nd;
    char* p;
    unsigned long M;
    M = L / 1000;
    R = L % 1000;
    if (M != 0) PredlozPadez(M, n + 1, s);
    if (R == 0) return;
    ns = R / 100;
    if (ns) sprintf_s(s + strlen(s), " %s", sot[ns - 1]);
    if (ns == 1) strcat(s, "��");
    if (ns == 2) strcat(s, "������");
    if (ns == 3) strcat(s, "������");
    if (ns == 4) strcat(s, "�����");
    if (ns >= 5) strcat(s, "�����");
    R = R % 100;
    nd = R / 10;
    if (nd >= 2)
    {
        strcat(s, desiat[nd - 2]);
        if (nd == 2 || nd == 3) strcat(s, "�");
        if (nd == 4) strcat(s, "a");
        if (nd >= 5 && nd <= 8) strcat(s, "�������");
        if (nd == 9) strcat(s, "��������");
        R = R % 10;
    }
    if (n == 1 && R > 0 && R < 3) p = edw[R - 1];
    else p = edm[R];
    strcat(s, p);
    if (R == 1) strcat(s, "���");
    if (R == 2) strcat(s, "��");
    if (R == 3 || R == 4) strcat(s, "��");
    if (R > 4) strcat(s, "�");
}

int Pad(int o) //����� ������
{
    o = 0;
    printf_s("�������� �����:\n 1.������������\n 2.�����������\n 3.���������\n 4.�����������\n 5.������������\n 6.����������\n \n�����: ");
    scanf_s("%d", &o);
    if (o > 6)
    {
        printf_s("\n������. �������� ������ �����\n\n");
        return Pad(o);
    }
    return o;
}

void main()
{
    setlocale(LC_ALL, "Rus");
    char b[200], s[1000];
    int L;
    int choice = 0;
    printf("�����: ");
    gets(b);
    if (strlen(b) == 0) return;
    s[0] = '\0';
    L = atol(b);
    switch (Pad(choice))
    {
    case 1:
        ImenitelVinitelPadez(L, 0, s);
        printf("%s\n", s);
        break;
    case 2:
        RoditelPadez(L, 0, s);
        printf("%s\n", s);
        break;
    case 3:
        DatelPadez(L, 0, s);
        printf("%s\n", s);
        break;
    case 4:
        ImenitelVinitelPadez(L, 0, s);
        printf("%s\n", s);
        break;
    case 5:
        TvoritelPadez(L, 0, s);
        printf("%s\n", s);
        break;
    case 6:
        PredlozPadez(L, 0, s);
        printf("%s\n", s);
        break;
    }
}