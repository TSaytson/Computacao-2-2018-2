
#include "aula0301.h"

ull
CalcularTermoSerieFibonacci(unsigned short termos)
{
	ull resultadoFuncao, resultadoAnterior;
	resultadoFuncao = 1;
	resultadoAnterior = 0;

	if (termos <= 1)
		return termos;

	while (termos>1)
	{	
		resultadoFuncao += resultadoAnterior;
		resultadoAnterior = resultadoFuncao - resultadoAnterior;
		termos--;
	}

	return resultadoFuncao;
}
