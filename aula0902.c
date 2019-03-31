
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "aula0901.h"

#define NUMERO_ARGUMENTOS				3
#define ARGUMENTO_INVALIDO				1
#define NUMERO_ARGUMENTOS_INVALIDO	2
#define ERRO_ABRINDO_ARQUIVO			3
#define ERRO_LENDO_ARQUIVO				4
#define ERRO_CONVERTENDO_BASE64		5
#define OK									0

int
main (int argc, char *argv[])
{
	FILE *arquivoFonte, *arquivoCodificado;
	byte leitura[4];
	char escrita[5];
	unsigned lidos, escritos, indice;

	if(argc != NUMERO_ARGUMENTOS)
	{
		printf("Uso: <nome_do_programa> <nome_do_arquivo_fonte> <nome_para_o_arquivo_decodificado>\n");
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (!(arquivoFonte = fopen(argv[1], "r")))
	{
		printf("Erro abrindo o arquivo \"%s\"\n", argv[1]);
		printf("Erro (#%i) - %s\n", errno, strerror(errno));
		exit(ERRO_ABRINDO_ARQUIVO);
	}

	if (!(arquivoCodificado = fopen(argv[2], "w")))
	{
		printf("Erro abrindo o arquivo \"%s\"\n", argv[2]);
		printf("Erro (#%i) - %s\n", errno, strerror(errno));
		fclose(arquivoFonte);
		exit(ERRO_ABRINDO_ARQUIVO);
	}

	for (indice = 0; indice < 4; indice++)
		leitura[indice] = '\0';

	for (indice = 0; indice < 5; indice++)
		escrita[indice] = '\0';

	indice = 0;
	for (escritos = 0; (lidos = fread(leitura, 1, 3, arquivoFonte)) > 0;)
	{	
		if (leitura[lidos - 1] == '\n')
		{	
			leitura[lidos - 1] = '\0';
			lidos--;
		}
		if (lidos != 0)
		{
			if (CodificarBase64(leitura, lidos, escrita))
			{
				printf("Erro codificando em base 64\n");
				exit(ERRO_CONVERTENDO_BASE64);
			}
			escritos += fprintf(arquivoCodificado, escrita);
			if (escritos >= COMPRIMENTO_MAXIMO_STRING)
			{
				fprintf(arquivoCodificado, "%s", "\r\n");
				indice += escritos;
				escritos = 0;
			}
		}
	}

	if (ferror(arquivoFonte))
	{
		printf("Erro lendo o arquivo \"%s\"\n", argv[1]);
		printf("Erro (#%i) - %s\n", errno, strerror(errno));
		fclose(arquivoFonte);
		fclose(arquivoCodificado);
		remove(argv[2]);
		exit(ERRO_LENDO_ARQUIVO);
	}
	
	printf("Arquivo criado. %u caracteres gravados.\n", (indice + escritos));
	fclose(arquivoFonte);
	fclose(arquivoCodificado);

	return OK;
}

