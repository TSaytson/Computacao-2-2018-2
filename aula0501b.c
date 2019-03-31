
#include "aula0401.h"
#include "aula0501.h"

float
CalcularSerieHarmonicaAlternada(unsigned long int termos)
{
	float resultado = 0;

	if (!termos)
		return termos;

	do
	{
		resultado += (CalcularExponencial(-1, termos+1) /
							CalcularExponencial(termos, termos));
		termos--;
	}
	while (termos);

	return resultado;
}

