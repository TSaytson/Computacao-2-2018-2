
#ifndef	_AULA0804_
#define	_AULA0804_	"@(#)aula0804.h"

#define COMPRIMENTO_PIS_PASEP		10

typedef unsigned char byte;
typedef enum {falso, verdadeiro} boolean;

char
GerarDigitoVerificadorPisPasep(char *);

boolean
ValidarPisPasep(char *);

#endif

