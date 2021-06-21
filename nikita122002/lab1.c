#include <stdio.h>

int main()
{
	int m;
	printf("Enter a number m:");
	scanf_s("%d", &m);
	while (m <= 0)
	{
		printf("Number m must be greater then 0.Re-enter m:\n");
		scanf_s("%d", &m);
	}
	printf("Decimal form: 1 Binary form:1\n");
	for (int i = 3; i <= m; i += 2)
	{
		int i_rank; char is_sum = 1;
		for (int j = 1;; j++)
		{
			if (i >> j) continue;
			else
			{
				i_rank = j;
				break;
			}
		}
		for (int j = 2; j <= i_rank / 2; j++) {
			int rDigit = 1 & i >> j - 1;
			int lDigit = 1 & i >> i_rank - j;
			if (lDigit != rDigit)
			{
				is_sum = 0;
				break;

			}
		}
		if (is_sum)
		{
			i_rank -= 2;
			printf("Decimal form:%d Binary form:1", i);
			for (i_rank; i_rank > 0; i_rank--)
			{
				if (i & 1 << i_rank) printf("1");
				else printf("0");
			}
			printf("1\n");

		}
	}
}


