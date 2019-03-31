
#include "aula0301.h"

ull
CalcularTermoSerieFibonacci(unsigned short termos)
{

	if (termos <= 1)
		return termos;

	return CalcularTermoSerieFibonacci(termos-1) + CalcularTermoSerieFibonacci(termos-2);

}

