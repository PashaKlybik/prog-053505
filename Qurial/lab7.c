#include <stdlib.h>
#include <stdio.h>

#pragma warning (disable : 4996)

int PrintPlaneInfo(int flightNum)
{
	char numStr[10];
	const unsigned MAX_LENGTH = 256;
	char buffer[256];
	itoa(flightNum, numStr, 10);
	char link[30] = "planes/plane";
	strcat(link, numStr);
	strcat(link, ".txt");
	FILE* fp = fopen(link, "r");
	if (!fp) { return  1; }
	else
	{
		while (fgets(buffer, MAX_LENGTH, fp)) { printf("%s", buffer); }
		fclose(fp);
	}
	return 0;
}
void PrintSchedule()
{
	int flNum = 0, isError = 0;
	while (isError == 0)
	{
		flNum++;
		isError = PrintPlaneInfo(flNum);
		printf("\n");
	}
}
void PrintByCity(char city[50])
{
	int flNum = 0, isError = 0;
	while (isError == 0)
	{
		flNum++;
		char numStr[10];
		const unsigned MAX_LENGTH = 256;
		char buffer[256];
		itoa(flNum, numStr, 10);
		char link[30] = "planes/plane";
		strcat(link, numStr);
		strcat(link, ".txt");
		FILE* fp = fopen(link, "r");
		char ccity[256] = "";//"Arrival point ";
		strcat(ccity, city);
		strcat(ccity, "\n");
		if (!fp) { isError = 1; }
		else
		{
			while (fgets(buffer, MAX_LENGTH, fp))
			{
				if (printf(buffer) == printf(ccity))
				{
					printf("\x1b[1F");
					printf("\x1b[2K");
					printf("\x1b[1F");
					printf("\x1b[2K");
					PrintPlaneInfo(flNum); printf("\n");
					free(buffer); free(ccity);
					break;
				}
				else
				{
					printf("\x1b[1F");
					printf("\x1b[2K");
					printf("\x1b[1F");
					printf("\x1b[2K");
				}
			}
		}
	}
}
void BuyTickets(int flightNum, int ticketsNum)
{
	char numStr[10];
	const unsigned MAX_LENGTH = 256;
	char buffer[256];
	itoa(flightNum, numStr, 10);
	char link[30] = "planes/plane";
	strcat(link, numStr);
	strcat(link, ".txt");
	FILE* fp = fopen(link, "r");
	FILE* fTemp;
	char path[100];
	int count = 0;

	char newline[256];


	while ((fgets(buffer, 256, fp)) != NULL)
	{
		count++;
		if (count == 7)
		{
			itoa((atoi(buffer) - ticketsNum), newline, 10);
			fputs(newline, fTemp);
		}
		else
		{
			fputs(buffer, fTemp);
		}
	}

	fclose(fp);
	fclose(fTemp);
}

int main()
{
	PrintPlaneInfo(1);
	PrintSchedule();
	PrintByCity("Minsk");
	BuyTickets(1, 2);
}