
#include <stdio.h>
#include <stdlib.h>

#include "aula0201.h"

#define NUMERO_ARGUMENTOS 				3
#define NUMERO_ARGUMENTOS_INVALIDO 	1
#define ARGUMENTO_INVALIDO 			2
#define OK 									0

int
main (int argc, char *argv[])
{	ull numero1, numero2; char *verificador;

	numero1 = 0;
	numero2 = 0;

	if(argc != NUMERO_ARGUMENTOS)
	{ printf("Uso: <nome do programa> <primeiro inteiro nao-negativo>\
				 <segundo inteiro nao negativo>\n");
	  return NUMERO_ARGUMENTOS_INVALIDO;
	}
	if (argv[1][0] == '-')
	{
		printf("Caractere invalido: \"%c\"\n", argv[1][0]);
		return ARGUMENTO_INVALIDO;
	}
	if (argv[2][0] == '-')
	{
		printf("Caractere invalido: \"%c\"\n", argv[2][0]);
		return ARGUMENTO_INVALIDO;
	}
	
	numero1 = strtoull(argv[1], &verificador, 10);

	if (*verificador != '\0')
	{
		printf("Caractere invalido: \"%c\"\n", *verificador);
		return ARGUMENTO_INVALIDO;
	}
	numero2 = strtoull(argv[2], &verificador, 10);

	if (*verificador != '\0')
	{
		printf("Caractere invalido: \"%c\"\n", *verificador);
		return ARGUMENTO_INVALIDO;
	}

	printf("\nO resultado do MDC é: %llu\n", CalcularMaximoDivisorComum(numero1, numero2				));
	return OK;
}


