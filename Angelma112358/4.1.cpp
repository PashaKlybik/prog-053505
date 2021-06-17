#include <stdio.h>
#include <malloc.h>

void Enter(char **a, int row);
void Print(char *a, int column);
void ToUp(char *str, int column);
void ToEdit(char *str, int column);
void Delete(char **a);
int main() {
	const int row = 3;

	const int column1 = 5;
    const int column2 = 4;
    const int column3 = 6;
	char** A = (char**)malloc(sizeof(char) * row);
    char** B = (char**)malloc(sizeof(char) * row);
    char** C = (char**)malloc(sizeof(char) * row);

	for (int i = 0; i < row; i++) {
		A[i] = (char*)malloc(sizeof(char) * column1);
        B[i] = (char*)malloc(sizeof(char) * column2);
        C[i] = (char*)malloc(sizeof(char) * column3);
	}

    A[0] = "album";
    A[1] = "beers";
    A[2] = "chill";

    B[0] = "beef";
    B[1] = "card";
    B[2] = "cook";
    
    C[0] = "absurd";
    C[1] = "casual";
    C[2] = "system";
   
    for(int i=0; i< row; ++i)
        ToEdit(A[i], column1);
    printf("\n");

    for (int i = 0; i < row; ++i)
        ToEdit(B[i], column2);
    printf("\n");

    for (int i = 0; i < row; ++i)
        ToEdit(C[i], column3);
    Delete(A, row);
    Delete(B, row);
    Delete(C, row);
	return 0;
}
void Enter(char** a, int row) {
    printf("Fill the first array (length - 5).\n");
    for (int i = 0; i < row; ++i) {
        char ch = 0;
        int j = 0;
        printf("Enter word: ");
        while (1) {
            ch = getc(stdin);
            if (ch == '\n') break;
            a[i][j] = ch;
            j++;
        }
    }
}

void Print(char *str, int column) {
    for (int i = 0; i < column; i++) {
        printf("%c", str[i]);
    }
}

void ToUp(char* str, int column) {
    for (int i = 0; i < column; i++) {
        if ((int)str[i] > 96 && (int)str[i] < 123) {
            printf("%c", str[i] - 32);
        }
        else printf("%c", str[i]);
    }
}

int Check(char *str, int column) {
    int num = 1;
    int boolCheck = 0;
    for (int i = 0; i < column; i++) {
        for (int j = num; j < column; ++j) {
            if (str[i] == str[j]) {
                boolCheck = 1;
               break;
            }
            if (boolCheck == 1) break;
        }
        num++;
    }
    return boolCheck;
}

void ToEdit(char* str, int column) {
    if (Check(str, column) == 1) {
        ToUp(str, column);
    }
    else (Print(str, column));
    printf("\n");
}

void Delete(char** a, int row) {
    for (int i = 0; i < row; ++i) {
        a[i] = NULL;
        free(a[i]);
    }
    a = NULL;
    free(a); 
}