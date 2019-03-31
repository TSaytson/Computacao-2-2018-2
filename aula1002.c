
#include <stdio.h>
#include <stdlib.h>
#define _XOPEN_SOURCE							600
#include <string.h>
#include <errno.h>


#define COMPRIMENTO_MAXIMO_STRING		1024

#define NUMERO_ARGUMENTOS					2
#define NUMERO_ARGUMENTOS_INVALIDO		1

#define ERRO_ABRINDO_ARQUIVO				2
#define ERRO_ABRINDO_ARQUIVO_TEMP		3
#define ERRO_LENDO_ARQUIVO					4

#define LIMITE_NOME_ARQUIVO_EXCEDIDO	5
#define OK										0

/* testar com xxd <nomedoarquivo> */

/* 0A - \n, 0D - \r */

int
main(int argc, char* argv[])
{
	FILE *arquivoDOS, *arquivoUnix;
	char nomeArquivoUnix[21] = {"arquivoUnix_XXXXXX"};
	char buffer[COMPRIMENTO_MAXIMO_STRING + 1];

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf("Uso: <nome do arquivo>\n");
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	if (!(arquivoDOS = fopen(argv[1], "r")))
	{
		printf("Erro abrindo o arquivo \"%s\"\n", argv[1]);
		printf("ERRO (#%i): \"%s\"", errno, strerror(errno));
		exit(ERRO_ABRINDO_ARQUIVO);
	}

	if (strlen(argv[1]) > COMPRIMENTO_MAXIMO_STRING)
	{
		printf("Nome do arqiuvo excede o tamanho maximo permitido\n");
		exit(LIMITE_NOME_ARQUIVO_EXCEDIDO);
	}
	
	if (mkstemp(nomeArquivoUnix) != -1)
		if (!(arquivoUnix = fdopen(mkstemp(nomeArquivoUnix), "w")))
		{
			printf("Erro abrindo o arquivo temporario\n");
			printf("ERRO (#%i): \"%s\"", errno, strerror(errno));
			fclose(arquivoDOS);
			exit(ERRO_ABRINDO_ARQUIVO_TEMP);
		}

	while ((fgets(buffer, COMPRIMENTO_MAXIMO_STRING, arquivoUnix)))
	{
		printf("buffer: %s\n", buffer);
		if ((buffer[strlen(buffer) - 1] == '\n') && (buffer[strlen(buffer) - 2] != '\r'))
		{
			fprintf(arquivoDOS, "%s", buffer);
			fprintf(arquivoDOS, "%s", "\r\n");
		}
	}

	if (ferror (arquivoUnix))
	{
		printf("Erro lendo o arquivo \"%s\"\n", argv[1]);
		printf("ERRO (#%i): \"%s\"\n", errno, strerror(errno));
		fclose(arquivoUnix);
		fclose(arquivoDOS);
		remove(arquivoDOS);
		exit(ERRO_LENDO_ARQUIVO);
	}

	snprintf(

	return OK;

}

