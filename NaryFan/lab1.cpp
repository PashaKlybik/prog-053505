#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <malloc.h>

using namespace std;

int main() {
	// Check input
	unsigned long int num = 0, tonum = 6;
	bool flg = 1;
	char *num_arr = (char*)malloc(11*sizeof(char));
	while (flg) {
		printf("Enter an integer (up to 999'999'999): ");
		scanf_s("%s", num_arr, 10);
		int i = 0;
		for (i, flg = 0; num_arr[i]; i++) {
			if (!isdigit(num_arr[i])) {				
				printf("Wrong input, re-enter\n---------------------\n");
				flg = 1;
				break;
			}			
		}
		if (!flg) {
			if (!num_arr[i]) {
				i--;
			}
			int dec_place = 1;
			for ( i; i >= 0; i--)
			{
				num += (num_arr[i] - 48) * dec_place;
				dec_place *= 10;
			}
		}
	}
    free(num_arr);

	printf("---------------------\n");

	// Checking every number up to num
	while (tonum <= num) {
		int grp = 0, prevbin, bits_tot = 0;
		unsigned long int tonum_cp;
		tonum++;
		tonum_cp = tonum;
		while (tonum_cp > 0) {
			if (grp == 3 || grp == 0) {
				grp = 1;
				prevbin = tonum_cp % 2;
				tonum_cp /= 2;
				bits_tot++;
			}

			else {
				if (prevbin == tonum_cp % 2) {
					tonum_cp /= 2;
					grp++;
					bits_tot++;
				}
				else
					break;
			}

			// If the number suits, represents dec and bin view
			if (tonum_cp == 0 && bits_tot % 3 == 0) {
				int* bin = (int*)malloc(bits_tot*sizeof(int);
				printf("%lu -- ", tonum);
				tonum_cp = tonum;
				int i = 0;
				while (tonum_cp > 0) {
					bin[i] = tonum_cp % 2;
					tonum_cp /= 2;
					i++;
				}
				i--;
				while (i >= 0) {
					printf("%i", bin[i]);
					i--;
				}
				printf("\n");
				free(bin);
				bin = NULL;
			}
		}
	}

	if (tonum == 6) {
		printf("No integers found\n");
	}
	getch();
	return 0;
}
