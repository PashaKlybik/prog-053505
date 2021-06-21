#include "func.h"
#pragma warning(disable : 4996)

int main(void)
{
    Item* root = NULL;
    int num[100], is_balance, i = 0;

    setlocale(LC_CTYPE, "Russian");
    printf("Enter integers (until '0' is entered). Binary search tree");
    printf("(no repetitions). Balance check\n\n");
    printf("Enter integers separated by a space (0+ \"Enter\" - stoping the input).");
    printf("\nFor example: 1 2 3 4 0+\"Enter\"\n\n");
    do
    {
        if (scanf("%d", &num[i]) != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if (num[i] == 0)
            break;
        AddNode(num[i], &root);
        i++;
    } while (1);
    if (root != 0)
    {
        printf("\nBinary search tree (ascending):\n");
        LeftOrder(root);
        printf("\n\n");
        is_balance = Balance(root);
        if (is_balance)
            printf("The tree is balanced\n");
        if (!is_balance)
            printf("The tree is not balanced\n");
    }
    return 0;
}