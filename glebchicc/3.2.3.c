#include <stdio.h> 
#include <string.h>
#include <math.h>

void encryption(char a[], char m[][(int)ceil(sqrt(strlen(a)))]) {
    int n = (int)ceil(sqrt(strlen(a)));
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
        for (int j = 0; j < n; ++j) printf("%c", m[i][j]);
    }
    printf("\n");
}

void decryption(int n, char m[][n], char a[]) {
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
        printf("%c", a[i]);
    }
}

int main() {
    char a[101];
    printf("Enter the line (not more than 100 symbols): ");
    fgets(a, 100, stdin);
    int n = ceil(sqrt(strlen(a)));
    char m[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = ' ';
        }
    }
    char b[n * n];
    encryption(a, m);
    decryption(n, m, b);
}