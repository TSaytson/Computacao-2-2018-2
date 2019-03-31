
#include <math.h>

#include "aula0501.h"

float
CalcularSerieHarmonicaAlternada(unsigned long int termos)
{
	if (!termos)
		return termos;

	return (pow(-1, termos+1)/pow(termos, termos)) + 
				CalcularSerieHarmonicaAlternada(termos - 1);
}

