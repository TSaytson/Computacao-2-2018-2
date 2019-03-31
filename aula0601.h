
#ifndef _AULA0601_
#define _AULA0601_ "@(#)aula0601.h"

#define APAGADO					'0'
#define ACESO						'1'
#define NUMERO_MAXIMO_LINHAS	25
#define NUMERO_MAXIMO_COLUNAS	80

typedef enum {ok, abscissaInvalida, ordenadaInvalida} tipoErros;
typedef enum {apagado, aceso} tipoPixel;

tipoErros
MostrarMonitor(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
					unsigned maximoLinhas, unsigned maximoColunas);

tipoErros
LimparMonitor(tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
					unsigned maximoLinhas, unsigned maximoColunas);

tipoErros
DesenharRetangulo(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS]							, unsigned maximoLinhas, unsigned maximoColunas, 
						unsigned ordenadaEsquerda, unsigned abscissaEsquerda, 
						unsigned ordenadaDireita, unsigned abscissaDireita);

tipoErros
PreencherPoligono(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS]							, unsigned maximoLinhas, unsigned maximoColunas, 
						unsigned linha, unsigned coluna);


#endif

