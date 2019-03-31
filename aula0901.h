
#ifndef _AULA0901_
#define _AULA0901_ 						"@(#)aula0901.h"

#define CONJUNTO_BASE_64				"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define COMPRIMENTO_MAXIMO_STRING	76

typedef enum {ok, argumentoInvalido, numeroArgumentosInvalido} tipoErros;
typedef unsigned char byte;

tipoErros
CodificarBase64(byte *, unsigned, char *);

tipoErros
DecodificarBase64(char *, byte *, unsigned *);


#endif

