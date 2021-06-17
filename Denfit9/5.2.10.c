#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define Size 100
typedef struct tnode {
    char* word;
    struct tnode* left;
    struct tnode* right;
}Tnode;

char* doublestr(const char* str) {
    char* d = malloc(strlen(str) + 1);   
    if (d == NULL) 
    {
        return NULL;
    }
    strcpy(d, str);                        
    return d;                           
}

void treeprint(Tnode* tr, int level) {

    if (tr != NULL) 
    {
        treeprint(tr->left, level + 1);
        for (int i = 0; i <= level; i++) 
            printf("   ");
        printf("%s\n", tr->word);
        treeprint(tr->right, level + 1);

    }
}

 Tnode* addtree(struct tnode* tr, char* w) {
    if (tr == NULL) 
    {
        tr = (Tnode*)malloc(sizeof(Tnode));
        tr->word = doublestr(w);
        tr->left = tr->right = NULL;
    }
    int compare;
    compare = strcmp(w, tr->word);
    if (compare < 0)
    {
        tr->left = addtree(tr->left, w);
    }
    else if (compare > 0)
    {
        tr->right = addtree(tr->right, w);
    }
    return tr;
}

void deletetree(Tnode* tree) {
    if (tree != NULL) 
    {
        deletetree(tree->left);
        deletetree(tree->right);
        free(tree->word);
        free(tree);
    }
}
int rightword(char* str)
{
    int lenght = strlen(str);
    for (int i = 0; i < lenght / 2; i++)
    {
        if (str[i] != str[lenght - 1 - i])
            return 0;
    }
    return 1;
}

void palindrome(Tnode* tr) {

    if (tr != NULL) 
    {
        palindrome(tr->left);
        if (rightword(tr->word))
            printf("%s\n", tr->word);
        palindrome(tr->right);
    }
}

int main() {
    Tnode* root=NULL;
    char newWord[Size];
    printf("Enter your words, ""end"" will be your last word\n");
    do 
    {
        scanf_s("%s", newWord, Size);
        if (isalpha(newWord[0]) && strcmp(newWord, "end") != 0)
            root = addtree(root, newWord);
    } while (strcmp(newWord, "end") != 0);   
    printf("\n");
    printf("Binary Tree:\n");
    treeprint(root, 0);
    printf("\n");
    printf("Palindromes in an alphabetical order:\n");
    palindrome(root);
    deletetree(root);
    return 0;
}