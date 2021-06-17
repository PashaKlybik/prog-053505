#include<stdio.h>
#include<math.h>

int calculateCyclically(float x,float epsilon);

long long int countFact(int temp);

long double calculateRecursively(float x, float epsilon, int i, int numOfIteration);

float decreaseX(long double x);

int main()
{
    long double x;
    float epsilon;

    printf("x = ");
    scanf("%lf", &x);

    printf("epsilon = ");
    scanf("%f", &epsilon);

    float recursiveResult;
    int cyclicResult;
    int numOfIterations=1;
    double angleReduction;
    angleReduction = decreaseX(x);
    printf("\n");

    do
    {
        recursiveResult = calculateRecursively(angleReduction, epsilon, 1, numOfIterations);
        numOfIterations++;

    } while (fabs(sin(angleReduction) - recursiveResult) > epsilon);

    printf("Recursive result =  %f", recursiveResult);
    printf("\n");
    printf("Number of iterations recursively %d", numOfIterations);
    printf("\n\n");

    cyclicResult = calculateCyclically(angleReduction, epsilon);
    printf("\n");
    printf("Number of iterations cyclically %d", cyclicResult);
    printf("\n");
}

int calculateCyclically(float x,float epsilon)
{
    long double row = 0;

    int temp;
    int i = 1;
    long long int fact = 1;
    float coefficient;

    do
    {
        temp = 2 * i - 1;
        for(int j=1;j<=temp;j++)
        {
            fact *= j;
        }

        row = row + pow(-1, (i - 1)) * (pow(x, (2 * i - 1)) / fact);
        fact = 1;
        i++;
        coefficient = fabs(row - sin(x));
    } while (coefficient > epsilon);

    printf("The result of the row cyclically = %f", row);

    return --i;
}

long long int countFact(int temp)
{
    if (temp == 1)
    {
        return 1;
    }

    return temp * countFact(temp-1);
}

long double calculateRecursively(float x, float epsilon, int i, int numOfIteration)
{
    int temp ;

    long long int fact;

    temp = 2 * i - 1;

    fact = countFact(temp);

    if (i == numOfIteration)
    {
        return pow(-1, (i - 1)) * (pow(x, (2 * i - 1)) / fact);
    }

    return pow(-1, (i - 1)) * (pow(x, (2 * i - 1)) / fact) + calculateRecursively(x, epsilon, i + 1, numOfIteration);
}

float decreaseX(long double x)
{
    long double xInDegrees;
    xInDegrees = (x * 180) / 3.141592653589793238462643;

    if (x > 0)
    {
        while (xInDegrees > 0)
        {
            xInDegrees -= 360;
        }
        xInDegrees += 360;
    }
    else
    {
        while (xInDegrees < 0)
        {
            xInDegrees += 360;
        }
        xInDegrees -= 360;
    }

    double alpha;
    alpha = (3.14 * xInDegrees) / 180;

    return alpha;
}