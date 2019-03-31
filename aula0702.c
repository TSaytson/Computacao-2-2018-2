
#include <stdio.h>
#include <stdlib.h>

#include "aula0701.h"

#define NUMERO_ARGUMENTOS				1 + NUMERO_LINHAS_MATRIZ_A*NUMERO_COLUNAS_MATRIZ_A + NUMERO_LINHAS_MATRIZ_B*NUMERO_COLUNAS_MATRIZ_B
#define ARGUMENTO_INVALIDO				1
#define NUMERO_ARGUMENTOS_INVALIDO	2


int
main (int argc, char *argv[])
{
	float matriz_A[NUMERO_LINHAS_MATRIZ_A][NUMERO_COLUNAS_MATRIZ_A], matriz_B[NUMERO_LINHAS_MATRIZ_B][NUMERO_COLUNAS_MATRIZ_B], 
			matriz_C[NUMERO_LINHAS_MATRIZ_A][NUMERO_COLUNAS_MATRIZ_B];
	unsigned short indiceLinha, indiceColuna, indice;
	char *verificador;

	indice = 1;

	if(argc != NUMERO_ARGUMENTOS)
	{
		printf("Uso: <nome_do_programa> <a11..a1%u..a%u%u b11..b1%u..b%u%u>\n", NUMERO_COLUNAS_MATRIZ_A, NUMERO_LINHAS_MATRIZ_A, NUMERO_COLUNAS_MATRIZ_A, 
					NUMERO_LINHAS_MATRIZ_B, NUMERO_LINHAS_MATRIZ_B,	NUMERO_COLUNAS_MATRIZ_B);
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	while (indice < NUMERO_LINHAS_MATRIZ_A*NUMERO_COLUNAS_MATRIZ_A + 1)
	{
		for (indiceLinha = 0; indiceLinha < NUMERO_LINHAS_MATRIZ_A; indiceLinha++)
			for (indiceColuna = 0; indiceColuna < NUMERO_COLUNAS_MATRIZ_A; indiceColuna++)
			{
				matriz_A[indiceLinha][indiceColuna] = strtof(argv[indice], &verificador);
				if ((*verificador))
				{
					printf("Argumento \"%s\" invalido\n", argv[indice]);
					exit(ARGUMENTO_INVALIDO);
				}
				indice++;
			}
	}
	
	while (indice < NUMERO_LINHAS_MATRIZ_B*NUMERO_COLUNAS_MATRIZ_B + NUMERO_LINHAS_MATRIZ_A*NUMERO_COLUNAS_MATRIZ_A + 1)
	{
		for (indiceLinha = 0; indiceLinha < NUMERO_LINHAS_MATRIZ_B; indiceLinha++)
			for (indiceColuna = 0; indiceColuna < NUMERO_COLUNAS_MATRIZ_B; indiceColuna++)
			{
				matriz_B[indiceLinha][indiceColuna] = strtof(argv[indice], &verificador);
				if ((*verificador))
				{
					printf("Argumento \"%s\" invalido\n", argv[indice]);
					exit(ARGUMENTO_INVALIDO);
				}
				indice++;
			}
	}

	for (indiceLinha = 0; indiceLinha < NUMERO_LINHAS_MATRIZ_A; indiceLinha++)
   {  
      printf("\n");
      for (indiceColuna = 0; indiceColuna < NUMERO_COLUNAS_MATRIZ_A; indiceColuna++)
         printf("%G\t", matriz_A[indiceLinha][indiceColuna]);
   }

	for (indiceLinha = 0; indiceLinha < NUMERO_LINHAS_MATRIZ_B; indiceLinha++)
   {  
      printf("\n");
      for (indiceColuna = 0; indiceColuna < NUMERO_COLUNAS_MATRIZ_B; indiceColuna++)
         printf("%G\t", matriz_B[indiceLinha][indiceColuna]);
   }

	MultiplicarMatrizes (matriz_A, matriz_B, matriz_C);

	for (indiceLinha = 0; indiceLinha < NUMERO_LINHAS_MATRIZ_A; indiceLinha++)
	{
		printf("\n");
		for (indiceColuna = 0; indiceColuna < NUMERO_COLUNAS_MATRIZ_B; indiceColuna++)
			printf("%G\t", matriz_C[indiceLinha][indiceColuna]);
	}

	printf("\n");

	return ok;
}


