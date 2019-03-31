
#include "aula0401.h"
#include "aula0501.h"

float
CalcularSerieHarmonicaAlternada(unsigned long int termos)
{
	if (!termos)
		return termos;

	return (CalcularExponencial(-1, termos+1) / 
           CalcularExponencial(termos, termos)) +
           CalcularSerieHarmonicaAlternada(termos - 1);



}

