
#include <stdio.h>
#include <stdlib.h>

#include "aula0301.h"

#define NUMERO_ARGUMENTOS				2
#define ARGUMENTO_INVALIDO				1
#define NUMERO_ARGUMENTOS_INVALIDO	2

#define EOS									'\0'
#define OK									0

int
main (int argc, char *argv[])
{
	unsigned short termos;
	char *verificador;

	if(argc != NUMERO_ARGUMENTOS)
	{
		printf("Uso: <nome_do_programa> <numero_termos>");
		return NUMERO_ARGUMENTOS_INVALIDO;
	}

	if (argv[1][0] == '-')
	{
		printf("Argumento invalido: %c\n", argv[1][0]);
		return ARGUMENTO_INVALIDO;
	}

	termos = strtol (argv[1], &verificador, 10);

	if (*verificador != EOS)
	{
		printf("Argumento invalido: %c\n", *verificador);
		return ARGUMENTO_INVALIDO;
	}
	for (; termos; termos--)
	{
		printf("F(%u) = %llu\n", termos, CalcularTermoSerieFibonacci(termos));
	}

	printf("F(%u) = %llu\n", termos, CalcularTermoSerieFibonacci(termos));

	return OK;
}


