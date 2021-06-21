#include <stdio.h>

struct CarInfo {
	int carPrice;
	int releaseDate;
	int engineVolume;
	int runDistance;
	int finalPrice;
};

int servicePrice(int carPrice, int releaseDate, int engineVolume, int runDistance)
{
	int finalPrice = runDistance * 0.5;
	int age = 2021 - releaseDate;
	switch (age) {
	case 0: case 1: case 2: case 3: case 11: case 12: case 13:
		finalPrice += 0.6 * engineVolume; break;
	case 4: case 5: case 6: case 7: case 8: case 9: case 10:
		if (engineVolume < 2500) {
			finalPrice += 0.35 * engineVolume;
		}
		else {
			finalPrice += 0.6 * engineVolume;
		}
		break;
	default:
		finalPrice += 2 * engineVolume; break;
	}
	return finalPrice;
}

int main()
{
	char answer[40];
	int i = 0;
	struct CarInfo cInfo[10];

	while (strcmp(answer, "exit") != 0) {
		printf("Enter car characteristics\n");

		printf("Enter car price\n");
		scanf_s("%i", &cInfo[i].carPrice);

		printf("Enter release date\n");
		scanf_s("%i", &cInfo[i].releaseDate);

		printf("Enter engine volume\n");
		scanf_s("%i", &cInfo[i].engineVolume);

		printf("Enter run distance\n");
		scanf_s("%i", &cInfo[i].runDistance);

		cInfo[i].finalPrice = servicePrice(cInfo[i].carPrice, cInfo[i].releaseDate, cInfo[i].engineVolume, cInfo[i].runDistance);
		printf("final price if the service is a %i\n", cInfo[i].finalPrice);
		printf("final price if the car is a %i\n", cInfo[i].finalPrice + cInfo[i].carPrice);

		i++;
		printf("enter 'continue' to analyze another car or 'exit' to exit:\n");
		scanf_s("%s", answer, sizeof(answer));
	}
	printf("v1.0 Konstantin Vertinsky 2021 (c)");
}