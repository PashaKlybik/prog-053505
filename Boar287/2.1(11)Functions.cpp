#include "Functions.h"
void AlgebraForm(ComplexNumber number)
{
	if ((number.Re == 0) && (number.Im == 0))
	{
		printf("\tz=0");
		return;
	}
	if (number.Re == 0)
		printf("\tz=%.2fi", number.Im);
	else if (number.Im > 0)
		printf("\tz=%.2f+%.2fi", number.Re, number.Im);
	else if (number.Im < 0)
		printf("\tz=%.2f%.2fi", number.Re, number.Im);
	else if (number.Im == 0)
		printf("\tz=%.2f", number.Re);
}

void TrigonometricForm(ComplexNumber number)
{
	if ((number.Re == 0) && (number.Im == 0))
	{
		printf("\tz=0");
		return;
	}
	printf("\tz=%.2f(cos(A)+sin(A)i)\n", number.r);
	printf("\tcos(A)=%.2f\n\tsin(A)=%.2f", number.cos, number.sin);

}

void IndicativeForm(ComplexNumber number)
{
	if ((number.Re == 0) && (number.Im == 0))
	{
		printf("\tz=0");
		return;
	}

	double Angle = acos(number.cos);
	if (number.Im == 0)
		printf("\tz=%.2f", number.r);
	else
		printf("\tz=%.2fe^(i*%.2f)", number.r, Angle);
}

void Conjugate(ComplexNumber number)
{
	if ((number.Re == 0) && (number.Im == 0))
	{
		printf("\tz=0");
		return;
	}
	if (number.Re == 0)
		printf("\tz=%.2fi", -number.Im);
	else if (number.Im > 0)
		printf("\tz=%.2f-%.2fi", number.Re, number.Im);
	else if (number.Im < 0)
		printf("\tz=%.2f%+.2fi", number.Re, -number.Im);
	else if (number.Im == 0)
		printf("\tz=%.2f", number.Re);
}

void Exponentiation(ComplexNumber number, int DegreeIndicator)
{
	if ((number.Re == 0) && (number.Im == 0))
	{
		printf("\tz=0");
		return;
	}
	number.r = pow(number.r, DegreeIndicator);
	number.cos = cos(DegreeIndicator * acos(number.cos));
	number.sin = sin(DegreeIndicator * asin(number.sin));
	printf("\tz=%.2f^n(cos(n*A)+sin(n*A)i)\n", number.r);
	printf("\tcos(A)=%.2f\n\tsin(A)=%.2f", number.cos, number.sin);
}