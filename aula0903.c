
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
	FILE *arquivoFonte, *arquivoDecodificado;
	byte escrita[4];
	char leitura[4];
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

	if (!(arquivoDecodificado = fopen(argv[2], "w")))
	{
		printf("Erro abrindo o arquivo \"%s\"\n", argv[2]);
		printf("Erro (#%i) - %s\n", errno, strerror(errno));
		fclose(arquivoFonte);
		exit(ERRO_ABRINDO_ARQUIVO);
	}

	for (indice = 0; indice < 4; indice++)
		leitura[indice] = '\0';

	for (indice = 0; indice < 4; indice++)
		escrita[indice] = '\0';

	indice = 0;
	lidos = 4;
	for (escritos = 0; (fgets(leitura, lidos + 1, arquivoFonte));)
	{	
		printf("leitura no for: %s\n", leitura);
		if (leitura[strlen(leitura) - 1] == '\n')
		{	
			printf("1o if, leitura[strlen(leitura) - 1]: %lu\n", strlen(leitura));
			if (leitura[strlen(leitura) - 2] == '\r')
			{
				leitura[strlen(leitura) - 2] = '\0';
				printf("2o if, leitura[strlen(leitura) - 2]: %lu\n", strlen(leitura));
				lidos--;
			}	
			lidos--;
		}

		if ((lidos != 0) && (strlen(leitura)))
		{
			if (DecodificarBase64(leitura, escrita, &lidos))
			{
				printf("Erro codificando em base 64\n");
				exit(ERRO_CONVERTENDO_BASE64);
			}
			escritos += fwrite(escrita, lidos - 1, 1, arquivoDecodificado);
		}
		lidos = 4;
	}

	if (ferror(arquivoFonte))
	{
		printf("Erro lendo o arquivo \"%s\"\n", argv[1]);
		printf("Erro (#%i) - %s\n", errno, strerror(errno));
		fclose(arquivoFonte);
		fclose(arquivoDecodificado);
		remove(argv[2]);
		exit(ERRO_LENDO_ARQUIVO);
	}
	
	printf("Arquivo criado. %u caracteres gravados.\n", (indice + escritos));
	fclose(arquivoFonte);
	fclose(arquivoDecodificado);

	return OK;
}


