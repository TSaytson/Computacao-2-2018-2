
#include <string.h>
#include "aula0804.h"

char
GerarDigitoVerificadorPisPasep(char *pisIncompleto)
{
	byte pesos[COMPRIMENTO_PIS_PASEP] = {3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
	byte digitoVerificador = 0;
	unsigned indice;
	byte auxiliar[COMPRIMENTO_PIS_PASEP];

	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP; indice++)
	{	
		auxiliar[indice] = (pisIncompleto[indice] - '0');
		digitoVerificador += pesos[indice]*auxiliar[indice];
	}

	return (digitoVerificador%11 <= 1 ? '0' : (11 - (digitoVerificador%11)) + '0');
	
}

boolean
ValidarPisPasep(char *pisCompleto)
{
	
	return ((GerarDigitoVerificadorPisPasep(pisCompleto) == pisCompleto[COMPRIMENTO_PIS_PASEP + 1])) ? verdadeiro : falso;

}

