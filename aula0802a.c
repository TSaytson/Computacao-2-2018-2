
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0801.h"

#define NUMERO_ARGUMENTOS				COMPRIMENTO_PIS_PASEP + 1
#define ARGUMENTO_INVALIDO				1
#define NUMERO_ARGUMENTOS_INVALIDO	2
#define OK									0

int
main (int argc, char *argv[])
{
	unsigned indice;
	byte pisPasep[COMPRIMENTO_PIS_PASEP];
	char *verificador;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf("Uso: <nome_do_programa> <numeroPisPasep> \n");
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	for (indice = 1; indice < COMPRIMENTO_PIS_PASEP + 1; indice++)
	{	
		if ((strlen(argv[indice]) != 1) || ((argv[indice][0] < '0') || (argv[indice][0] > '9')))
		{	
			printf("Argumento \"%s\" invalido, entrar com numeros entre \"0\" e \"9\"\n", argv[indice]);
			exit(ARGUMENTO_INVALIDO);
		}
	}

	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP; indice++)
		pisPasep[indice] = (byte) strtoul(argv[indice + 1], &verificador, 10);

	printf("%u\n", (byte) GerarDigitoVerificadorPisPasep(pisPasep));

	return OK;
}


