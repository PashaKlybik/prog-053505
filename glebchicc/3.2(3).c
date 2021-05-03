#include <stdio.h> 
#define n 10

void encryption(char a[n * n], char m[n][n]) {
    int count = 0;
    for (int counter = 0; counter < n; ++counter) {
        for (int i = counter; i < n - counter; ++i) {
            if (a[count] != '\n') {
                m[i][counter] = a[count];
                count++;
            }
            else {
                break;
            } 
        }
        for (int j = counter + 1; j < n - counter; ++j) {
            if (a[count] != '\n') {
                m[n - counter - 1][j] = a[count];
                count++;
            }
            else {
                break;
            }
        }
        for (int i = n - counter - 2; i >= counter; --i) {
            if (a[count] != '\n') {
                m[i][n - counter - 1] = a[count];
                count++;
            }
            else {
                break;
            }
        }
        for (int j = n - counter - 2; j > counter; --j) {
            if (a[count] != '\n') {
                m[counter][j] = a[count];
                count++;
            }
            else {
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) printf_s("%c  ", m[i][j]);
        printf_s("\n");
    }
    printf_s("\n");
}

void decryption(char m[n][n], char a[n * n]) {
    int count = 0;
    for (int counter = 0; counter < n; ++counter) {
        for (int i = counter; i < n - counter; ++i) {
            if (a[count] != '\n') {
                a[count] = m[i][counter];
                count++;
            }
            else {
                break;
            }
        }
        for (int j = counter + 1; j < n - counter; ++j) {
            if (a[count] != '\n') {
                a[count] = m[n - counter - 1][j];
                count++;
            }
            else {
                break;
            }
        }
        for (int i = n - counter - 2; i >= counter; --i) {
            if (a[count] != '\n') {
                a[count] = m[i][n - counter - 1];
                count++;
            }
            else {
                break;
            }
        }
        for (int j = n - counter - 2; j > counter; --j) {
            if (a[count] != '\n') {
                a[count] = m[counter][j];
                count++;
            }
            else {
                break;
            }
        }
    }
    for (int i = 0; i < n * n; ++i) {
        printf_s("%c", a[i]);
    }
}

int main() {
    char a[n * n];
    char m[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = ' ';
        }
    }
    char b[n * n];
    printf_s("Enter the line (not more than 100 symbols): ");
    fgets(a, 100, stdin);
    encryption(a, m);
    decryption(m, b);
}