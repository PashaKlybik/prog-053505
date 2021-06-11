#include <stdio.h>
#include <math.h>

void genCube(char*** cube, const int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++) {
			for (int k = 0; k < arrSize; k++) {
				cube[i][j][k] = rand() % 2;
			}
		}
	}
}

void printCube(char*** cube, const int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		printf("[ ");
		for (int j = 0; j < arrSize; j++) {
			for (int k = 0; k < arrSize; k++) {
				
				printf("%d ", cube[i][j][k]);
				if ((k + 1 == arrSize) && (j + 1 == arrSize)) {
					printf("] ");
				}
			}
		}
	}
}

int xLightCount(char*** cube, const int arrSize) {
	int xLight = 0;
	int isTransparent = 0;
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++) {
			if (cube[0][i][j] != 0 && arrSize > 1) {
				for (int k = 1; k < arrSize; k++) {
					if (cube[k][j][i] != 0) {
						isTransparent = 1;
					}
					else {
						isTransparent = 0;
						break;
					}

				}
				if (isTransparent != 0) {
					xLight++;
					isTransparent = 0;
				}
			}
		}
	}
	return xLight;
}

int zLightCount(char*** cube, const int arrSize) {
	int isTransparent = 0;
	int zLight = 0;
	for (int i = 0; i < arrSize; i++) {
		if (cube[i][0][0] != 0) {
			for (int j = 0; j < arrSize; j++) {
				if (cube[i][j][0] != 0) {
					isTransparent = 1;
				}
				else {
					isTransparent = 0;
					break;
				}
			}
			if (isTransparent != 0) {
				zLight++;
				isTransparent = 0;
			}
		}
	}
	return zLight;
}

int yLightCount(char*** cube, const int arrSize) {
	int isTransparent = 0;
	int yLight = 0;
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++) {
			if (cube[i][j][0] != 0) {
				isTransparent = 1;
				for (int k = 0; k < arrSize; k++) {
					if (cube[i][j][k] != 0) {
						isTransparent = 1;
					}
					else {
						isTransparent = 0;
						break;
					}
				}
					if (isTransparent != 0) {
						yLight++;
						isTransparent = 0;
					}
			}
		}
	}
	return yLight;
}


int main() {
	int arrSize = 0;
	printf("Please enter size of cube ");
	scanf_s("%d", &arrSize);
	char*** cube = (char***)malloc(sizeof(char**) * arrSize);
	for (int i = 0; i < arrSize; i++) {
		cube[i] = (char**)malloc(sizeof(char*) * arrSize);
		for (int j = 0; j < arrSize; j++) {
			cube[i][j] = (char*)malloc(sizeof(char) * arrSize);
		}
	}
	genCube(cube, arrSize);
	printCube(cube, arrSize);
	printf("\nAmount of lights along the x axis %d", xLightCount(cube, arrSize));
	printf("\nAmount of lights along the y axis %d", yLightCount(cube, arrSize));
	printf("\nAmount of lights along the z axis %d", zLightCount(cube, arrSize));
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++) {
			free(cube[i][j]);
		}
		free(cube[i]);
	}
	
	free(cube);
}