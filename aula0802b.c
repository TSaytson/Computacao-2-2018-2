
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0801.h"

#define NUMERO_ARGUMENTOS				1 + 1
#define ARGUMENTO_INVALIDO				1
#define NUMERO_ARGUMENTOS_INVALIDO	2
#define OK									0

int
main (int argc, char *argv[])
{
	unsigned indice;
	byte pisPasep[COMPRIMENTO_PIS_PASEP];

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf("Uso: <nome_do_programa> <numeroPisPasep> \n");
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (strlen(argv[1]) != COMPRIMENTO_PIS_PASEP)
	{
		printf("Argumento \"%s\" invalido, entrar com numero PisPasep sem o digito verificador\n", argv[1]);
		exit(ARGUMENTO_INVALIDO);
	}

	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP; indice++)
	{	
		if (((argv[1][indice] < '0') || (argv[1][indice] > '9')))
		{	
			printf("Argumento \"%c\" invalido, entrar com numeros entre \"0\" e \"9\"\n", argv[1][indice]);
			exit(ARGUMENTO_INVALIDO);
		}
	}

	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP; indice++)
		pisPasep[indice] = argv[1][indice] - '0';

	printf("%u\n", (byte) GerarDigitoVerificadorPisPasep(pisPasep));

	return OK;
}


