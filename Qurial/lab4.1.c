#include <stdio.h>
#include <stdlib.h>

int main()
{
	char text[256];
	int numOfWords = 1, maxWordSize = 0, temp = 0, numOfSentence = 0, maxNumOfWords = 0;
	scanf_s("%[^\n]", &text, 256);
	if (text[strlen(text) - 1] != '.') { strcat(text, "."); }
	printf("%s\n", text);

	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == '.') {
			numOfSentence++;
			if (numOfWords > maxNumOfWords) {
				maxNumOfWords = numOfWords;
			}
			numOfWords = 0;
		}
		if (text[i] == ' ' || (text[i] == '.' && text[i + 1] != ' ')) {
			numOfWords++;
			if (temp > maxWordSize) {
				maxWordSize = temp;
			}
			temp = 0;
		}
		else {
			temp++;
		}
	}
	int** wSize = (int*)malloc(numOfSentence * sizeof(int*));
	for (int i = 0; i < numOfSentence; i++) {
		wSize[i] = (int*)malloc(2 * sizeof(int));
	}

	char*** textArr = (char***)malloc(numOfSentence * sizeof(char**));
	for (int i = 0; i < numOfSentence; i++) {
		textArr[i] = (char**)malloc(maxNumOfWords * sizeof(char*));
		for (int j = 0; j < maxNumOfWords; j++) {
			textArr[i][j] = (char*)malloc((maxWordSize + 1) * sizeof(char));
		}
	}

	int p = 0, tempMin, tempMax;
	for (int i = 0; i < numOfSentence; i++) {
		tempMin = maxWordSize;
		tempMax = 0;
		for (int j = 0; j < maxNumOfWords; j++) {
			for (int k = 0; k <= maxWordSize; k++) {
				if (text[p - 1] == '.' && text[p] == ' ') { p++; }
				textArr[i][j][k] = text[p];
				p++;
				if (text[p] == ' ' || text[p] == '.') {
					textArr[i][j][k + 1] = ' ';
					if (k < tempMin) {
						tempMin = k;
						wSize[i][0] = j;
					}
					if (k > tempMax) {
						tempMax = k;
						wSize[i][1] = j;
					}
					break;
				}
			}
			if (text[p] == '.') {
				p++;
				break;
			}
			p++;
		}
	}
	char tempChar;
	for (int i = 0; i < numOfSentence; i++) {
		for (int j = 0; j <= maxWordSize; j++) {
			tempChar = textArr[i][wSize[i][0]][j];
			textArr[i][wSize[i][0]][j] = textArr[i][wSize[i][1]][j];
			textArr[i][wSize[i][1]][j] = tempChar;
			if (textArr[i][wSize[i][0]][j] == ' ') {
				break;
			}
		}
	}
	char finalText[256];
	for (int i = 0; i < 256; i++) {
		finalText[i] = '\0';
	}
	p = 0;
	for (int i = 0; i < numOfSentence; i++) {
		for (int j = 0; j < maxNumOfWords; j++) {
			for (int k = 0; k <= maxWordSize; k++) {
				finalText[p] = textArr[i][j][k];
				p++;
				if (textArr[i][j][k] == ' ') {
					break;
				}
			}
			if (text[p - 1] == '.') {
				break;
			}
		}
		finalText[p - 1] = '.';
		p++;
		finalText[p - 1] = ' ';
	}
	printf("%s", finalText);
	//some random words.to test how program.works
}


//sentnence of words. second sent.

//She wrote. She completed her literature review. He organized his sources by theme.