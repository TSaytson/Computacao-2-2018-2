
#include "aula0301.h"

ull
CalcularTermoSerieFibonacci(unsigned short termos)
{
	ull resultadoFuncao, resultadoAnterior;
	resultadoFuncao = 1;
	resultadoAnterior = 0;

	if (termos <= 1)
		return termos;

	for (; termos>1; termos--)
	{	
		resultadoFuncao += resultadoAnterior;
		resultadoAnterior = resultadoFuncao - resultadoAnterior;
	}

	return resultadoFuncao;
}

