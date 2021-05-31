#include "Functions.h"

int Length(const char* string)
{
	int counter = 0;
	while (string[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

void FillBinaryTree(struct binaryTree *Oak,const char* Sentence)
{
    char OneWord[20];
    bool EmptySentence = true;
    int WordCounter = 0;
    for (int i = 0; i < Length(Sentence); i++, WordCounter++)
    {
        if (Sentence[i] != '\n')
        {
            if (ispunct(Sentence[i]) == false)
                OneWord[WordCounter] = Sentence[i];
        }
        if ((Sentence[i] == '\n') || (ispunct(Sentence[i])))
        {
            OneWord[WordCounter] = '\0';
            EmptySentence = false;
            if (WordCounter != 0)
                Insert(Oak->Root, OneWord);
            OneWord[0] = '\0';
            WordCounter = -1;
        }
    }
}

void PrintBinaryTree(binaryTree* Oak, const char* Sentence)
{
    if (Sentence[0] != '\n')
    {
        printf("From left to right:");
        PrintLNR(Oak->Root);
        printf("\n");
        printf("From right to left:");
        PrintReverseLNR(Oak->Root);
    }
    else
        printf("You have entered empty quote...");
}

void DivideSentence(char* Sentence)
{
    for (int i = 0; i < Length(Sentence); i++)
    {
        if (Sentence[i] == ' ')
            Sentence[i] = '\n';
    }
}
