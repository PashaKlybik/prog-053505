#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char a[], char b[]) {
    memcpy(b, a, strlen(a));
	for (int i = 0; i < strlen(a) / 2; i++) {
	    int n = strlen(a) - i;
		char temp = b[i];
		b[i] = b[n - 1];
		b[n - 1] = temp;
	}
}

int main() {
	FILE* file = fopen("text.txt", "r");
	
	char a[100];
	char b[100] = "";
	char c[100] = "";
	char* temp;
	while (fgets(a, 100, file) != NULL) {
	    char c[100] = "";
		memcpy(c, a, strlen(a));
		temp = strtok(a, " ");
		char b[100] = "";
		
		while (temp != NULL)
		{
		    char temp_[] = "";
		    for (int i = 0; i < strlen(temp); i++) {
		        temp[i] = (char)tolower(temp[i]);
		    }
			reverse(temp, temp_);
			if (strcmp(temp, temp_) == 0) {
			    printf("%s - word-palindrom\n", temp);
			}
			strcat(b, temp);
			temp = strtok(NULL, " ,.-");
		}
		
		char temp_[strlen(b)];
	    reverse(b, temp_);
	    if (strcmp(b, temp_) == 0) {
	        printf("%s - phrase-palindrom\n", c);
	    }
	}
}
