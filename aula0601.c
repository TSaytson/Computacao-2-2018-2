
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "aula0601.h"

#define ACESO		'1'
#define APAGADO	'0'

tipoErros
MostrarMonitor(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
					unsigned maximoLinhas, unsigned maximoColunas)
{ 
	unsigned indiceLinha, indiceColuna;

	system("clear");

	for (indiceLinha = 0; indiceLinha < maximoLinhas; indiceLinha++)
	{
		printf("\n");
		for (indiceColuna = 0; indiceColuna < maximoColunas; indiceColuna++)
		{	
			printf("%c\t", monitor[indiceLinha][indiceColuna] ? ACESO : APAGADO);
		}
	}	

	sleep(0.8);

	printf("\n");

	return ok;
}

tipoErros
LimparMonitor(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
					unsigned maximoLinhas, unsigned maximoColunas)
{
	unsigned indiceLinha, indiceColuna;

	for (indiceLinha = 0; indiceLinha < maximoLinhas; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < maximoColunas; indiceColuna++)
			monitor[indiceLinha][indiceColuna] = apagado;

	MostrarMonitor (monitor, maximoLinhas, maximoColunas);

	return ok;

}

tipoErros
DesenharRetangulo (tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],						 		unsigned maximoLinhas, unsigned maximoColunas, 
						unsigned ordenadaEsquerda, unsigned abscissaEsquerda, 
						unsigned ordenadaDireita, unsigned abscissaDireita)
{
	unsigned indiceLinhas, indiceColunas;

	for (indiceLinhas = abscissaEsquerda; indiceLinhas < abscissaDireita;
			indiceLinhas++)
		for (indiceColunas = ordenadaEsquerda; indiceColunas < ordenadaDireita;
				indiceColunas++)
				monitor[indiceLinhas][indiceColunas] = aceso;

	MostrarMonitor(monitor, maximoLinhas, maximoColunas);

	return ok;

}

tipoErros
PreencherPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
						unsigned maximoLinhas, unsigned maximoColunas, unsigned linha,
						unsigned coluna)
{

	if ((linha < maximoLinhas) && (coluna < maximoColunas))
		if (!monitor[linha][coluna])
		{
			monitor[linha][coluna] = aceso;
			PreencherPoligono (monitor, maximoLinhas, maximoColunas, linha + 1, coluna);
			PreencherPoligono (monitor, maximoLinhas, maximoColunas, linha - 1, coluna);
			PreencherPoligono (monitor, maximoLinhas, maximoColunas, linha, coluna + 1);
			PreencherPoligono (monitor, maximoLinhas, maximoColunas, linha, coluna - 1);
		}
	MostrarMonitor(monitor, maximoLinhas, maximoColunas);

	return ok;
}

