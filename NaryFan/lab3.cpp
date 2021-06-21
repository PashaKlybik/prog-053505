#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>

void input_check(int& num, int& max_size )
{
	while (true)
	{
		char *nums = (char*)malloc(max_size*sizeof(char));
		nums[0] = '\0';
		char ch;
		int counter = 0;
		while ((ch = _getch()) != 13)
		{
			if ((ch == '\b') && counter > 0)
			{
				putchar(ch);
				putchar(' ');
				putchar(ch);
				nums[--counter] = '\0';			
			}
			else if (ch > 47 && ch < 58 && counter < max_size)
			{
				putchar(ch);
				nums[counter] = ch;
				counter++;
			}
		}
		if (nums[0] != '\0' && atoi(nums)!=0 )
		{
			putchar('\n');
			num = atoi(nums);
			free(nums);
			return;
		}
		printf("\b\b  \b\b");
	}
}

void input_check(double& num, int max_size)
{	
	while (true)
	{
		char* nums = (char*)malloc(max_size * sizeof(char));
		nums[0] = '\0';
		char ch;
		int counter = 0;
		bool dot_put = false;
		while ((ch = _getch()) != 13)
		{
			if ((ch == '\b') && counter > 0)
			{
				if (nums[counter - 1] == '.')
				{
					dot_put = false;
				}
				putchar(ch);
				putchar(' ');
				putchar(ch);
				nums[--counter] = '\0';
			}
			else if ((ch == '.' || (ch == '-' && counter == 0) || (ch > 47 && ch < 58)) && counter < max_size)
			{
				if ((!dot_put && ch == '.' && counter >= 1)|| (ch == '-' && counter == 0)|| (ch > 47 && ch < 58))
				{
					putchar(ch);
					nums[counter] = ch;
					counter++;					
				}
				if (!dot_put && ch == '.' && counter >= 1)				
					dot_put = true;				
			}
		}
		if (nums[0] != '\0')
		{
			putchar('\n');
			num = atof(nums);
			free(nums);
			return;
		}
	}	
}


void fill_matrix(double** ext_matrix, int numof_variables, int numof_equations) {
	int max_value = 9;
	for (int i = 0; i < numof_equations; i++)
	{
		printf("{");
		for (int j = 0; j < numof_variables; j++)
		{
			if (j!= numof_variables - 1 )
			{
				printf("a%d.%d*x%d + ", i + 1, j + 1, j + 1);
			}
			else
			{
				printf("\b\b= b%d\n", i+1);
			}
		}
		for (int j = 0; j < numof_variables; j++)
		{
			if (j != numof_variables - 1)
			{
				printf("a%d.%d = ", i + 1, j + 1);
				input_check(ext_matrix[i][j], 18);
			}
			else
			{
				printf("b%d = ", i + 1);
				input_check(ext_matrix[i][j], 18);
			}
		}
		puts("\n");
	}
	system("cls");
	for (int i = 0; i < numof_equations; i++)
	{
		printf("{");
		for (int j = 0; j < numof_variables; j++)
		{
			if (j != numof_variables - 1)
			{
				printf("%lf*x%d + ",ext_matrix[i][j], j + 1);
			}
			else
			{
				printf("\b\b= %lf\n",ext_matrix[i][j]);
			}
		}
	}
}

void count_solution(double** ext_matrix, int &numof_variables, int &numof_equations) 
{
	bool* suschestv = (bool*)malloc((numof_variables) * sizeof(double));
	for (int i = 0; i < numof_variables; i++)
	{
		suschestv[i] = false;
	}
	//depending on this number choose the way of summing solutions
	int num_of_susch = 0;
	for (int i = 0, s = 0; i < numof_variables - 1 && s < numof_equations;i++)
	{
		if (ext_matrix[s][i] == 0)
		{
			int j;
			for (j = s+1; j < numof_equations; j++)
			{
				if (ext_matrix[j][i] != 0)
				{
					double* temp = (double*)malloc(numof_variables * sizeof(double));
					for (int k = 0; k < numof_variables; k++)
					{
						temp[k] = ext_matrix[j][k] ;
						ext_matrix[j][k] = ext_matrix[0][k];
						ext_matrix[0][k] = temp[k];
					}
					free(temp);
					break;
				}
			}
			if (j == numof_equations)
			{						
				continue;
			}
		}
		suschestv[i] = true;
		num_of_susch++;
		for (int m = i + 1; m < numof_variables; m++)
		{
			ext_matrix[s][m] /= ext_matrix[s][i];
		}
		ext_matrix[s][i] = 1;
		for (int m = s+1; m < numof_equations; m++)
		{
			for (int n = i+1; n < numof_variables; n++)
			{
				ext_matrix[m][n] -= ext_matrix[s][n] * ext_matrix[m][i];
			}
			ext_matrix[m][i] = 0;
		}		
		s++;
	}	
	//check for "system has no solution"
	int f;
	if (numof_variables - 1 != num_of_susch)
	{
		for (int s = numof_equations - 1; s >= 0; s--)
		{
			for (f = 0; f < numof_variables - 1; f++)
			{
				if (ext_matrix[s][f] != 0)
					break;
			}
			if (f == numof_variables - 1 && ext_matrix[s][f] != ext_matrix[s][f - 1])
			{
				puts("\nNo solutions of this system");
				return;
			}
		}
	}
	//check for "any number suits"
	for (f = 0; f < numof_variables; f++)
	{
		if (suschestv[f])
		{
			break;
		}
	}
	if (f == numof_variables)
	{
		puts("Any number suits any variable");
		return;
	}
	//all numbers are significant; method with array is chosen to take extra memory but save some processing time
	if (num_of_susch == numof_variables - 1)
	{
		double* x_matrix;
		if (!(x_matrix = (double*)malloc((numof_variables - 1) * sizeof(double)))) {
			puts("No free memory for processing, terminating...");
			_getch();
			exit(0);
		}
		for (int i = 0; i < numof_variables - 1; i++)
		{
			x_matrix[i] = 1;
		}
		for (int i = numof_equations -1 ; i >= 0; i--)
		{
			double current_x = 0;
			int j;
			for (j = numof_variables - 1; j != i; j--)
			{
				if (i == numof_equations - 1 || j == numof_variables - 1)
				{
					current_x += ext_matrix[i][j];
				}
				else
					current_x += ext_matrix[i][j] * x_matrix[j]*(-1);
			}
			x_matrix[j] = current_x;
		}
		puts("\n\nSingle solution:");
		for (int i = 0; i < numof_variables - 1; i++)
		{
			printf("x%d = %lf\n", i + 1, x_matrix[i]);			
		}
		return;
	}
	//not all numbers are significant; opt for "stairs" method due to high complexcity of array method
	puts("\n\nInfinite amount of solutions. Common view:");
	for (int i = 0; i < numof_variables - 1; i++)
	{
		if (!suschestv[i])
		{
			printf("x%d = x%d\n", i + 1, i + 1);
		}
	}
	int test;
	for (test = numof_equations - 1; ; test--)
	{
		int srch;
		for (srch = numof_variables - 1; ext_matrix[test][srch] == 0 && srch >= 0; srch--)
		{

		}
		if (srch == -1)
			continue;
		break;
	}
	for (int i = test; i >= 0; i--) 
	{
		int k = numof_variables - 1;
		while (!suschestv[k])
		{
			k--;
		}
		suschestv[k] = false;
		for (int j = i-1; j >= 0; j--)
		{			
			for (int m = numof_variables - 1; m > k; m--)
			{
					ext_matrix[j][m] -= ext_matrix[i][m] * ext_matrix[j][k];
			}
			ext_matrix[j][k] = 0;
		}
		printf("x%d = ", k + 1);
		for (k++; k < numof_variables; k++)
		{
			if (ext_matrix[i][k] != 0)
			{
				if (k != numof_variables - 1)
				{
					printf("%lf*x%d + ", ext_matrix[i][k]*(-1), k + 1);
				}
				else if (k == numof_variables - 1)
					printf("%lf\n", ext_matrix[i][k]);
			}
		}
	}
	free(suschestv);
}

int main(void)
{
	int max_size = 2;
	int numof_variables, numof_equations;	
	puts("Number of variables in system (up to 100): ");
	input_check(numof_variables, max_size);
	puts("Number of equations in system (up to 100): ");
	input_check(numof_equations , max_size);
	system("cls");
	double** ext_matrix = NULL;
	if (!(ext_matrix = (double**)malloc(numof_equations * sizeof(double*)))) {
		puts("No free memory for processing, terminating...");
		_getch();
		return 0;
	}
	for (int i = 0; i < numof_equations; i++)
	{
		if (!(ext_matrix[i] = (double*)malloc((numof_variables + 1) * sizeof(double)))) {
			puts("No free memory for processing, terminating...");
			_getch();
			return 0;
		}
	}
	numof_variables++;
	fill_matrix(ext_matrix, numof_variables, numof_equations);
	count_solution(ext_matrix, numof_variables, numof_equations);
	for (int i = 0; i < numof_equations; i++)
	{
		free(ext_matrix[i]);
	}
	free(ext_matrix);
	_getch();
	return 0;
}
