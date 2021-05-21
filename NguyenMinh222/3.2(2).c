#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<time.h>
void GlavDiog(int n,int** a,int temp)
{  
	temp = 0;
	printf("\n\nЗеркально относительно главной диагонали\n");
	for(int i=1; i<n-1;i++)
		for (int j = 0; j < i;j++)
		{
			temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n-1;j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}

}
void PobDiag(int n, int **c)
{  
	printf("\n\nЗеркально относительно побочной диагонали\n");
	int temp = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < n -1 - i; j++)

		{
			temp = c[i][j];
			c[i][j] = c[n - 2 - j][n - 2 - i];
			c[n - 2 - j][n - 2 - i] = temp;
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n - 1;j++) {printf("%d ", c[i][j]);}
			
		printf("\n");
	}
}
void maxElement(int n, int **b)
{
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		int max = 0;
		for (int j = 0; j < (n - 1);j++)
		{
			if (b[i][j] > b[i][0]) {
				max = b[i][0];
				b[i][0] = b[i][j];
				b[i][j] = max;
			}
		}
	}
	for (int i = 0;i < n - 1;i++) {
		for (int l = 0; l < n - 1; l++) {
			int m = 0;
			if (b[l][0] > b[l + 1][0]) {
				for (int j = 0; j < n - 1; j++) {
					m = b[l][j];
					b[l][j] = b[l + 1][j];
					b[l + 1][j] = m;
				}
			}
		}
	}
	printf("Нули после макс элемента матрицы в итоге:\n");
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n - 1;j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
	for (int j = 0;j < n - 1;j++)
	{
		printf("0 ");
	}
}

int temp;
int main()
{   
	char* locale = setlocale(LC_ALL,"ru");
	int n;
	printf("Введите значение n: ");
	scanf_s("%d", &n);
	int **a = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc((n - 1) * sizeof(int));
	}
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (n - 1);j++)
		{
			a[i][j] = rand() % 100;
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	//копии главной матрицы
	int** b = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		b[i] = (int*)malloc((n - 1) * sizeof(int));
	}
	for (int i = 0; i < n;i++){
		for (int j = 0; j < n - 1;j++) {
			b[i][j] = a[i][j];
		}
	}
	int **c= (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		c[i] = (int*)malloc((n - 1) * sizeof(int));
	}
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n - 1;j++) {
			c[i][j] = a[i][j];
		}
	}
	
	
	GlavDiog(n, a, temp);
	PobDiag(n, c);
	maxElement(n,b);
	
	for (int i = 0; i < n; i++)
	{
		free(a[i]);
	}
	free(a);
}