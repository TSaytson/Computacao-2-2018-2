
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0804.h"

#define NUMERO_ARGUMENTOS				1 + 1
#define ARGUMENTO_INVALIDO				1
#define NUMERO_ARGUMENTOS_INVALIDO	2
#define OK									0

int
main (int argc, char *argv[])
{
	unsigned indice;
	char pisPasep[COMPRIMENTO_PIS_PASEP];

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf("Uso: <nome_do_programa> <numeroPisPasep> \n");
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (strlen(argv[1]) != COMPRIMENTO_PIS_PASEP + 2)
	{
		printf("Argumento \"%s\" invalido, entrar com numero PisPasep separado pelo digito verificador\n", argv[1]);
		exit(ARGUMENTO_INVALIDO);
	}

	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP + 1; indice++)
	{	
		if (((argv[1][indice] < '0') || (argv[1][indice] > '9')) && (argv[1][indice] != '-'))
		{	
			printf("Argumento \"%c\" invalido, entrar com numeros entre \"0\" e \"9\" e com hifen separando o digito verificador\n", argv[1][indice]);
			exit(ARGUMENTO_INVALIDO);
		}
	}

	if (argv[1][COMPRIMENTO_PIS_PASEP] != '-')
	{
		printf("Argumento \"%c\" invalido, entrar com numeros entre \"0\" e \"9\" e com hifen separando o digito verificador\n", argv[1][COMPRIMENTO_PIS_PASEP]);
		exit(ARGUMENTO_INVALIDO);
	}
	
	strcpy(pisPasep, argv[1]);

	printf("%s\n", ValidarPisPasep(pisPasep) == verdadeiro ? "valido" : "invalido" );

	return OK;
}


