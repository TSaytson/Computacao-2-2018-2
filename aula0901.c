
#include		<stdio.h>
#include		"aula0901.h"

tipoErros
CodificarBase64(byte *entrada, unsigned numeroBytes, char *saida)
{
	unsigned indice = 0;
	
	if ((!entrada) || (!saida))
		return argumentoInvalido;
	
	for (indice = 0; indice < numeroBytes; indice++)
	{	
		if ((entrada[indice] < 32) || (entrada[indice] >=127))
		{	
			return argumentoInvalido;
		}
	}

	if (numeroBytes == 1)
	{
		saida[0] = CONJUNTO_BASE_64[((entrada[0]>>2)&0x3F)];
		
		saida[1] = CONJUNTO_BASE_64[((entrada[0]<<4)&0x30)];
		
		saida[2] = '=';

		saida[3] = '=';

	}

	if (numeroBytes == 2)
	{
		saida[0] = CONJUNTO_BASE_64[((entrada[0]>>2)&0x3F)];

		saida[1] = CONJUNTO_BASE_64[(((entrada[0]<<4)&0x30) | ((entrada[1]>>4)&0x0F))];

		saida[2] = CONJUNTO_BASE_64[((entrada[1]<<2)&0x3C)];

		saida [3] = '=';

	}
	
	if (numeroBytes == 3)
	{	
		printf("index0: %i\n", ((entrada[0]>>2)&0x3F));
		saida[0] = CONJUNTO_BASE_64[((entrada[0]>>2)&0x3F)];
	
		printf("index1: %i\n", (((entrada[0]<<4)&0x30) | ((entrada[1]>>4)&0x0F)));
		saida[1] = CONJUNTO_BASE_64[(((entrada[0]<<4)&0x30) | ((entrada[1]>>4)&0x0F))];
	
		printf("index2: %i\n", (((entrada[1]<<2)&0x3C) | ((entrada[2]>>6)&0x03)));		
		saida[2] = CONJUNTO_BASE_64[(((entrada[1]<<2)&0x3C) | ((entrada[2]>>6)&0x03))];
		
		printf("index3: %i\n", ((entrada[2])&0x3F));
		saida[3] = CONJUNTO_BASE_64[((entrada[2])&0x3F)];

	}
	
	return ok;
}

tipoErros
DecodificarBase64(char *entrada, byte *saida, unsigned *numeroBytes)
{

	unsigned char indice = 0;
	
	if ((!entrada) || (!saida))
		return argumentoInvalido;
	
	if (entrada[(*(numeroBytes)) - 1] == '=')
	{
		if (entrada[(*(numeroBytes)) - 2] == '=')
			(*(numeroBytes))--;
		(*(numeroBytes))--;
	}
	for (indice = 0; indice < *(numeroBytes); indice++)
	{	
		if ((entrada[indice] < 32) || (entrada[indice] >=127))
		{	
			return argumentoInvalido;
		}
	}
	printf("numeroBytes: %u\n", (*(numeroBytes)));
	byte index[*(numeroBytes)];

	if (*(numeroBytes) == 1)
	{
		for (indice = 0; entrada[0] != CONJUNTO_BASE_64[indice]; indice++);
		index[0] = ((indice<<2)&0xFC);
		saida[0] = index[0];
		printf("saida[0]: %s\n", saida);
		
	}

	if (*(numeroBytes) == 2)
	{
		for (indice = 0; entrada[0] != CONJUNTO_BASE_64[indice]; indice++);	  
		index[0] = ((indice<<2)&0xFC);
		for (indice = 0; entrada[1] != CONJUNTO_BASE_64[indice]; indice++);
		index[0] = (index[0] | ((indice>>4)&0x03));
		saida[0] = index[0];
		printf("saida[0]: %s\n", saida);

		index[1] = ((indice<<4)&0xF0);
		saida[1] = index[1];
		printf("saida[1]: %s\n", saida);

	}
	
	if (*(numeroBytes) == 3)
	{
		for (indice = 0; entrada[0] != CONJUNTO_BASE_64[indice]; indice++);	  
		index[0] = ((indice<<2)&0xFC);
		for (indice = 0; entrada[1] != CONJUNTO_BASE_64[indice]; indice++);
		index[0] = (index[0] | ((indice>>4)&0x03));
		saida[0] = index[0];
		printf("saida[0]: %s\n", saida);

		index[1] = ((indice<<4)&0xF0);
		for (indice = 0; entrada[2] != CONJUNTO_BASE_64[indice]; indice++);
		index[1] = (index[1] | ((indice>>2)&0x0F));
		saida[1] = index[1];
		printf("saida[1]: %s\n", saida);

		index[2] = ((indice<<6)&0xC0);
		saida[2] = index[2]; 
		printf("saida[2]: %s\n", saida);

	}
	
	if (*(numeroBytes) == 4)
	{
		for (indice = 0; entrada[0] != CONJUNTO_BASE_64[indice]; indice++);	  
		index[0] = ((indice<<2)&0xFC);
		for (indice = 0; entrada[1] != CONJUNTO_BASE_64[indice]; indice++);
		index[0] = (index[0] | ((indice>>4)&0x03));
		saida[0] = index[0];
		printf("saida[0]: %s\n", saida);

		index[1] = ((indice<<4)&0xF0);
		for (indice = 0; entrada[2] != CONJUNTO_BASE_64[indice]; indice++);
		index[1] = (index[1] | ((indice>>2)&0x0F));
		saida[1] = index[1];
		printf("saida[1]: %s\n", saida);

		index[2] = ((indice<<6)&0xC0);
		for (indice = 0; entrada[3] != CONJUNTO_BASE_64[indice]; indice++);
		index[2] = (index[2] | ((indice)&0x3F));
		saida[2] = index[2];
		printf("saida[2]: %s\n", saida);
		
	}
	
	return ok;

}


