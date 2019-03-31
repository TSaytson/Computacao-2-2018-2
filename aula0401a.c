
#include <math.h>

#include "aula0401.h"


long double
CalcularExponencial(double base, int expoente)
{
	if (base == 0 && expoente == 0)
		return 1;

	if (expoente < 0 && base == 0)
		return INFINITY;

	if (expoente == 0)
		return 1;

	if (base == 0)
		return base;

	if (expoente < 0)
		return (1/base) * CalcularExponencial(base, expoente + 1);

	return base * CalcularExponencial(base, expoente - 1);
	
}
