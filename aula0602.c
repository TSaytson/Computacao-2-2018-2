
#include <stdio.h>
#include <stdlib.h>

#include "aula0601.h"

#define NUMERO_ARGUMENTOS				1 + 1 + 1 + 2 + 2 + 2
#define ARGUMENTO_INVALIDO1			1
#define ARGUMENTO_INVALIDO2			2
#define NUMERO_ARGUMENTOS_INVALIDO	2


int
main (int argc, char *argv[])
{
	unsigned indice = 0; 
	unsigned maximoLinhas, maximoColunas, abscissaEsquerda, ordenadaEsquerda, 	
	abscissaDireita, ordenadaDireita, abscissa, ordenada; 
	char *verificador; tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];

	if(argc != NUMERO_ARGUMENTOS)
	{
		printf("Uso: <nome_do_programa> <linhas> <colunas> <canto superior esquerdo> <canto inferior direito> <abscissa> <ordenada>\n");
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}
	while (indice < argc)
	{
		if (argv[indice][0] == '-')
		{
			printf("Argumento \"%s\" invalido, usar numeros naturais\n", argv[indice]);
			exit(ARGUMENTO_INVALIDO1);
		}
		indice++;
	}

	maximoLinhas = strtoul(argv[1], &verificador, 10);
	if (*verificador)
	{
		printf("Argumento \"%s\" invalido, usar numeros\n", argv[1]);
		exit(ARGUMENTO_INVALIDO2);
	}

	if (maximoLinhas > NUMERO_MAXIMO_LINHAS)
	{
		printf("Numero de linhas superior ao maximo:\"%u\"\n", NUMERO_MAXIMO_LINHAS);
		return ordenadaInvalida;
	}

	maximoColunas = strtoul(argv[2], &verificador, 10);
	if (*verificador)
	{
		printf("Argumento \"%s\" invalido, usar numeros\n", argv[2]);
		exit(ARGUMENTO_INVALIDO2);
	}

	if (maximoColunas > NUMERO_MAXIMO_COLUNAS)
	{
		printf("Numero de colunas superior ao maximo: \"%u\"\n", NUMERO_MAXIMO_COLUNAS);
		return abscissaInvalida;
	}

	abscissaEsquerda = strtoul(argv[3], &verificador, 10);
	if (*verificador)
	{
		printf("Argumento \"%s\" invalido, usar numeros\n", argv[3]);
		exit(ARGUMENTO_INVALIDO2);
	}

	ordenadaEsquerda = strtoul(argv[4], &verificador, 10);
	if (*verificador)
	{
		printf("Argumento \"%s\" invalido, usar numeros\n", argv[4]);
		exit(ARGUMENTO_INVALIDO2);
	}
	
	abscissaDireita = strtoul(argv[5], &verificador, 10);
	if (*verificador)
	{
		printf("Argumento \"%s\" invalido, usar numeros\n", argv[5]);
		exit(ARGUMENTO_INVALIDO2);
	}

	ordenadaDireita = strtoul(argv[6], &verificador, 10);
	if (*verificador)
	{
		printf("Argumento \"%s\" invalido, usar numeros\n", argv[6]);
		exit(ARGUMENTO_INVALIDO2);
	}

	abscissa = strtoul(argv[7], &verificador, 10);
	if (*verificador)
	{
		printf("Argumento \"%s\" invalido, usar numeros\n", argv[7]);
		exit(ARGUMENTO_INVALIDO2);
	}

	ordenada = strtoul(argv[8], &verificador, 10);
	if (*verificador)
	{
		printf("Argumento \"%s\" invalido, usar numeros\n", argv[8]);
		exit(ARGUMENTO_INVALIDO2);
	}

	LimparMonitor(monitor, maximoLinhas, maximoColunas);

	PreencherPoligono(monitor, maximoLinhas, maximoColunas, abscissa, ordenada);

	DesenharRetangulo(monitor, maximoLinhas, maximoColunas, ordenadaEsquerda, abscissaEsquerda, ordenadaDireita, abscissaDireita);

	return ok;

}


