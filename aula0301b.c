
#include "aula0301.h"

ull
CalcularTermoSerieFibonacci(unsigned short termos)
{
	ull resultadoFuncao, resultadoAnterior;
	resultadoFuncao = 1;
	resultadoAnterior = 0;

	if (termos <= 1)
		return termos;

	do
	{	
		resultadoFuncao += resultadoAnterior;
		termos--;
		resultadoAnterior = resultadoFuncao - resultadoAnterior;
	}
	while (termos>1);

	return resultadoFuncao;
}

