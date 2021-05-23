#include "ComplexNumber.h"
#include <math.h>
void ComplexNumber::CalculateData()
{
	r = sqrt(pow(Re, 2) + pow(Im, 2));
	if (Re != 0)
		cos = Re / r;
	if (Im != 0)
		sin = Im / r;
}
