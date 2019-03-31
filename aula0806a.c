
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0804.h"

#define NUMERO_ARGUMENTOS				COMPRIMENTO_PIS_PASEP + 2 + 1
#define ARGUMENTO_INVALIDO				1
#define NUMERO_ARGUMENTOS_INVALIDO	2
#define OK									0

int
main (int argc, char *argv[])
{
	unsigned indice;
	char pisPasep[COMPRIMENTO_PIS_PASEP + 2];

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf("Uso: <nome_do_programa> <numeroPisPasep> \n");
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	for (indice = 1; indice < COMPRIMENTO_PIS_PASEP + 3; indice++)
	{	
		if ((strlen(argv[indice]) != 1) || (((argv[indice][0] < '0') || (argv[indice][0] > '9')) && (argv[indice][0]) != '-'))
		{	
			printf("Argumento \"%s\" invalido, entrar com numeros entre \"0\" e \"9\" e hifen separando o digito verificador\n", argv[indice]);
			exit(ARGUMENTO_INVALIDO);
		}
	}

	if (argv[COMPRIMENTO_PIS_PASEP + 1][0] != '-')
	{
		printf("Argumento \"%s\" invalido, entrar com numeros entre \"0\" e \"9\" e hifen separando o digito verificador\n", argv[COMPRIMENTO_PIS_PASEP + 1]);
		exit(ARGUMENTO_INVALIDO);
	}
	strcpy(pisPasep, argv[1]);

	for (indice = 1; indice < COMPRIMENTO_PIS_PASEP + 2; indice++)
		strcat(pisPasep,argv[indice + 1]);

	printf("%s\n", ValidarPisPasep(pisPasep) == verdadeiro ? "valido" : "invalido" );

	return OK;
}



