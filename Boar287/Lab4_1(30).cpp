#include "Functions.h"

int GetSize(char* Quote)
{
    int counter = 0;
    while (Quote[counter] != '\0')
    {
        counter++;
    }
    return counter;
}

void CorrectTheStatement(char* Quote)
{
    for (int i = 0; i < GetSize(Quote)-1; i++)
    {
        if ((Quote[i] == '�')||(Quote[i]=='�')|| (Quote[i] == '�') || (Quote[i] == '�'))
        {
            if (Quote[i + 1] == '�')
                Quote[i + 1] = '�';
            else if (Quote[i + 1] == '�')
                Quote[i + 1] = '�';
        } 
        else if ((Quote[i] == '�') || (Quote[i] == '�')|| (Quote[i] == '�') || (Quote[i] == '�'))
        {
            if (Quote[i + 1] == '�')
                Quote[i + 1] = '�';
        }
    }
}

bool QuoteValidation(char* Quote)
{
    char AvelaibleSymbols[] = "!,.?;:()<>\n ";
    bool Avelaible = false;
    for (int i = 0; i < GetSize(Quote); i++)
    {
        if (!((Quote[i] >= '�') && (Quote[i] <= '�')))
        {
            for (int j = 0; j < GetSize(AvelaibleSymbols); j++)
            {
                if (Quote[i] == AvelaibleSymbols[j])
                {
                    Avelaible = true;
                    break;
                }
            }
            if (Avelaible == false)
                return false;
            Avelaible = false;
        }

    }
    return true;
}
