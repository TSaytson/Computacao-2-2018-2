
#define _XOPEN_SOURCE			600

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define COMPRIMENTO_MAXIMO_STRING	1024

#define NUMERO_ARGUMENTOS		2
#define NUMERO_ARGUMENTOS_INVALIDO	1

#define ERRO_ABRINDO_ARQUIVO		2
#define ERRO_ABRINDO_ARQUIVO_TEMP	3
#define ERRO_LENDO_ARQUIVO		4

#define LIMITE_NOME_ARQUIVO_EXCEDIDO	5
#define OK				0

/* testar com xxd <nomedoarquivo> */

/* 0A - \n, 0D - \r */

int
main(int argc, char* argv[])
{
	FILE *arquivoDOS, *arquivoUnix;
	char nomeArquivoDOS[23] = {"arquivoDOS_XXXXXX"};
	char nomeArquivoUnix[COMPRIMENTO_MAXIMO_STRING];
	char buffer[COMPRIMENTO_MAXIMO_STRING + 1];
	int identificador;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf("Uso: <nome do arquivo>\n");
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	if (strlen(argv[1]) > COMPRIMENTO_MAXIMO_STRING - 5)
	{
		printf("Nome do arqiuvo excede o tamanho maximo permitido\n");
		exit(LIMITE_NOME_ARQUIVO_EXCEDIDO);
	}
	strcpy(nomeArquivoUnix, argv[1]);

	if (!(arquivoUnix = fopen(argv[1], "r")))
	{
		printf("Erro abrindo o arquivo \"%s\"\n", argv[1]);
		printf("ERRO (#%i): \"%s\"\n", errno, strerror(errno));
		exit(ERRO_ABRINDO_ARQUIVO);
	}
	
	if ((identificador = mkstemp(nomeArquivoDOS)) == -1)
	{
		printf("Erro abrindo o arquivo temporario\n");
		printf("ERRO (#%i): \"%s\"\n", errno, strerror(errno));
		fclose(arquivoUnix);
		exit(ERRO_ABRINDO_ARQUIVO_TEMP);
	}

	if (!(arquivoDOS = fdopen(identificador, "w")))
	{
		printf("Erro criando o arquivo temporario\n");
		printf("ERRO (#%i): \"%s\"\n", errno, strerror(errno));
		fclose(arquivoUnix);
		exit(ERRO_ABRINDO_ARQUIVO_TEMP);
	}

	while ((fgets(buffer, COMPRIMENTO_MAXIMO_STRING, arquivoUnix)))
	{
		if ((buffer[strlen(buffer) - 2] != '\r') && (buffer[strlen(buffer) - 1] == '\n'))
		{
			buffer[strlen(buffer) - 1] = '\0';
			fprintf(arquivoDOS, "%s", buffer);
			fprintf(arquivoDOS, "%s", "\r\n");
		}
		if ((buffer[strlen(buffer) - 2] == '\r') && (buffer[strlen(buffer) - 1] == '\n'))
			fprintf(arquivoDOS, "%s", buffer);
	}

	if (ferror(arquivoUnix))
	{
		printf("Erro lendo o arquivo \"%s\"\n", argv[1]);
		printf("ERRO (#%i): \"%s\"\n", errno, strerror(errno));
		fclose(arquivoUnix);
		fclose(arquivoDOS);
		remove(nomeArquivoDOS);
		exit(ERRO_LENDO_ARQUIVO);
	}

	snprintf(nomeArquivoUnix, strlen(nomeArquivoUnix) + 5, "%s.bak", nomeArquivoUnix);

	rename(argv[1], nomeArquivoUnix);

	rename(nomeArquivoDOS, argv[1]);

	printf("%s\n", nomeArquivoUnix);

	return OK;

}

