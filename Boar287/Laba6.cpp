#include "BinaryTree.h"

int main()
{
    BinaryTree BinaryOak;
    char Sentence[150];

    printf("Enter the sentence:");
    fgets(Sentence, 150, stdin);
    system("cls");
    puts(Sentence);

    DivideSentence(Sentence);
    FillBinaryTree(&BinaryOak,Sentence);
    PrintBinaryTree(&BinaryOak, Sentence);

    DestroyNode(BinaryOak.Root);
    return 0;
}
