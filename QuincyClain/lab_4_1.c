#include <conio.h>
#include <stdio.h>
#include <Windows.h>
int main() {
	char* s;
	char* c;
	int i = 0, j = 0, r = 0, probel = 0, p = 0;
	s = (char*)calloc(100, sizeof(char));
	c = (char*)calloc(100, sizeof(char));
	gets_s(s, 100);
	while (s[i] != ' ' && s[i] != '\0') {  //до первого пробела
		c[i] = s[i];
		i++;
	}
	while (s[i] == ' ') {
		probel++;
		i++;
	}
	i = 0;
	while (s[i]) {
		while (s[i] == ' ') {
			r = 1;
			p++;
			j = 0;
			i++;
		}
		while (s[i] != ' ' && s[i] != '\0') {
			if (r != 0) {
				if (probel != p) {
					printf("Error");
					return 0;
				}
			}
			if (c[j] != s[i]) {
				printf("Error");
				return 0;
			}
			i++;
			j++;
		}
		p = 0;
	}
	printf("Posledovatelnie");
	_getch();
	return 0;
}