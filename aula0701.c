
#include	"aula0701.h"


void
MultiplicarMatrizes(float matriz_A [NUMERO_LINHAS_MATRIZ_A][NUMERO_COLUNAS_MATRIZ_A], float matriz_B [NUMERO_LINHAS_MATRIZ_B][NUMERO_COLUNAS_MATRIZ_B], 
							float matriz_C [NUMERO_LINHAS_MATRIZ_A][NUMERO_COLUNAS_MATRIZ_B])
{
	unsigned short indiceLinha, indiceColuna, indice;

	for (indiceLinha = 0; indiceLinha < NUMERO_LINHAS_MATRIZ_A; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < NUMERO_COLUNAS_MATRIZ_B; indiceColuna++)
			matriz_C[indiceLinha][indiceColuna] = 0;
	
	for (indiceLinha = 0; indiceLinha < NUMERO_LINHAS_MATRIZ_A; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < NUMERO_COLUNAS_MATRIZ_B; indiceColuna++)
			for (indice = 0; indice < NUMERO_COLUNAS_MATRIZ_A; indice++)
				matriz_C[indiceLinha][indiceColuna] += matriz_A[indiceLinha][indice]*matriz_B[indice][indiceColuna];
}



