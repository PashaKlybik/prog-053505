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
        if ((Quote[i] == '÷')||(Quote[i]=='ù')|| (Quote[i] == '×') || (Quote[i] == 'Ù'))
        {
            if (Quote[i + 1] == 'ÿ')
                Quote[i + 1] = 'à';
            else if (Quote[i + 1] == 'þ')
                Quote[i + 1] = 'ó';
        } 
        else if ((Quote[i] == 'æ') || (Quote[i] == 'ø')|| (Quote[i] == 'Æ') || (Quote[i] == 'Ø'))
        {
            if (Quote[i + 1] == 'û')
                Quote[i + 1] = 'è';
        }
    }
}

bool QuoteValidation(char* Quote)
{
    char AvelaibleSymbols[] = "!,.?;:()<>\n ";
    bool Avelaible = false;
    for (int i = 0; i < GetSize(Quote); i++)
    {
        if (!((Quote[i] >= 'À') && (Quote[i] <= 'ÿ')))
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
