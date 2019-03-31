
#include <stdio.h>
#include <stdlib.h>

#include "aula0401.h"

#define NUMERO_ARGUMENTOS				3
#define ARGUMENTO_INVALIDO				1
#define NUMERO_ARGUMENTOS_INVALIDO	2

#define OK									0

int
main (int argc, char *argv[])
{
	char *verificador; double base; long unsigned expoente;

	if	(argc != NUMERO_ARGUMENTOS)
	{
		printf("Uso: <nome_do_programa> <base> <expoente>\n");
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	base = strtod(argv[1], &verificador);

	if (*verificador != '\0')
	{
		printf("Argumento com caractere \"%c\" invalido!\n", *verificador);
		exit(ARGUMENTO_INVALIDO);
	}

	expoente = strtol(argv[2], &verificador, 10);

	if (*verificador != '\0')
	{
		printf("Argumento com caractere \"%c\" invalido!\n", *verificador);
		exit(ARGUMENTO_INVALIDO);
	}
	
	printf("Resultado da operacao: %LG\n", CalcularExponencial(base, expoente));

	return OK;

}

