
#include "aula0801.h"

byte
GerarDigitoVerificadorPisPasep(byte pisIncompleto[COMPRIMENTO_PIS_PASEP])
{
	byte pesos[COMPRIMENTO_PIS_PASEP] = {3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
	byte digitoVerificador = 0;
	unsigned indice;

	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP; indice++)
		digitoVerificador += pesos[indice]*pisIncompleto[indice];

	return (digitoVerificador%11 <= 1 ? 0 : 11 - (digitoVerificador%11));
	
}

boolean
ValidarPisPasep(byte pisCompleto[COMPRIMENTO_PIS_PASEP + 1])
{
	
	return ((GerarDigitoVerificadorPisPasep(pisCompleto) == pisCompleto[COMPRIMENTO_PIS_PASEP]) ? verdadeiro : falso);

}

