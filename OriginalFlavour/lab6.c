#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Tree {
    int info;
    struct Tree* left, * right;
} *root = NULL;




void Make_Blns(struct Tree** p, int n, int k, int* a) {
    if (n == k) {
        *p = NULL;
        return;
    }
    else {
        int m = (n + k) / 2;
        *p = (struct Tree*)malloc(sizeof(struct Tree));
        (*p)->info = a[m];
        Make_Blns(&(*p)->left, n, m, a);
        Make_Blns(&(*p)->right, m + 1, k, a);
    }
}

void Print(struct Tree* p, int level) {
    if (p) {
        Print(p->right, level + 1); // Вывод левого поддерева
        for (int i = 0; i < level; i++) printf(" ");
        printf("%d \n", p->info);
        Print(p->left, level + 1); // Вывод правого поддерева
    }
}

void Tree_preorder(struct Tree* root) {
    if (!root)
        return;

    printf("%d", root->info);

    printf("(");
    Tree_preorder(root->left);
    printf(",");
    Tree_preorder(root->right);
    printf(")");
}



void Del_All(struct Tree* t) {
    if (t != NULL) {
        Del_All(t->left);
        Del_All(t->right);
        free(t);
    }
}


void bubbleSort(int* num, int size)
{
    // Для всех элементов
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--) 
        {
            if (num[j - 1] > num[j]) // если текущий элемент меньше предыдущего
            {
                int temp = num[j - 1]; // меняем их местами
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}
int* arr;
int main()
{
    FILE* file;
    file = fopen("nums.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return -1;
    }
    int index = 1;
    while (!feof(file)) {
        if (index == 1) {
            if (!(arr = (int*)malloc(sizeof(int)))) {
                printf("Can't allocate memory\n");
                exit(EXIT_FAILURE);
            }


        }
        else if (index > 1) {
            if (!(arr = (int*)realloc(arr, sizeof(int) * index))) {
                printf("Can't allocate memory\n");
                exit(EXIT_FAILURE);
            }
        }
        fscanf(file, "%d", &(arr[index - 1]));
        index++;
    }
    index--;
    bubbleSort(arr, index);
    Make_Blns(&root, 0, index, arr);
    Tree_preorder(root);
    printf("\n");
    Print(root, 0);

    Del_All(root);
    free(arr);
    fclose(file);
    return 0;
}