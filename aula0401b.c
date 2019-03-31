
#include <math.h>

#include "aula0401.h"


long double
CalcularExponencial(double base, int expoente)
{
	long double resultado = 1;

	if (base == 0 && expoente == 0)
		return 1;

	if (expoente < 0 && base == 0)
		return INFINITY;

	if (expoente == 0)
		return 1;

	if (base == 0)
		return base;

	if (expoente < 0)
	{
		base = 1/base;
		expoente *= -1;
	}

	do
	{
		resultado *= base;
		expoente--;
	}	
	while (expoente);
	
	return resultado;
	
}


