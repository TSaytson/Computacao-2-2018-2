
#ifndef	_AULA0801_
#define	_AULA0801_	"@(#)aula0801.h"

#define COMPRIMENTO_PIS_PASEP		10

typedef unsigned char byte;
typedef enum {falso, verdadeiro} boolean;

byte
GerarDigitoVerificadorPisPasep(byte [COMPRIMENTO_PIS_PASEP]);

boolean
ValidarPisPasep(byte [COMPRIMENTO_PIS_PASEP + 1]);

#endif

