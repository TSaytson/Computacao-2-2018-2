
#include <stdio.h>
#include <stdlib.h>

#include "aula0501.h"

#define NUMERO_ARGUMENTOS				2
#define ARGUMENTO_INVALIDO				1
#define NUMERO_ARGUMENTOS_INVALIDO	2

#define EOS									'\0'
#define OK									0

int
main (int argc, char *argv[])
{
	unsigned long termos = 0; char *verificador;

	if(argc != NUMERO_ARGUMENTOS)
	{
		printf("Uso: <nome_do_programa> <numero_termos>\n");
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (argv[1][0] == '-')
	{
		printf("Caractere %c invalido\n", argv[1][0]);
		exit(ARGUMENTO_INVALIDO);
	}
	
	termos = strtoul (argv[1], &verificador, 10);

	if (*verificador != EOS)
	{
		printf("Caractere %c invalido\n", *verificador);
		exit(ARGUMENTO_INVALIDO);
	}

	printf("Serie Harmonica Alternada: %.7G\n", 
			CalcularSerieHarmonicaAlternada(termos));

	return OK;
}


