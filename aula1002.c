/*Universidade Federal do Rio de Janeiro
 *Escola Politecnica
 *Departamento de Eletronica e de Computacao
 *EEL270 - Computacao II - Turma 2018/2
 *Prof. Marcelo Luiz Drumond Lanza
 *Autor: Thiago Saytson dos Santos Theonilo

 *$Author: thiago.theonilo $
 *$Date: 2018/11/13 11:43:22 $
 *$log$
 */ 


#define _XOPEN_SOURCE							600

#include <stdio.h>
#include <stdlib.h>
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
	char nomeArquivoUnix[24] = {"arquivoUnix_XXXXXX"};
	char buffer[COMPRIMENTO_MAXIMO_STRING + 1];
	char nomeArquivoDOS[COMPRIMENTO_MAXIMO_STRING];
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

	strcpy(nomeArquivoDOS, argv[1]);
	
	if (!(arquivoDOS = fopen(argv[1], "r")))
	{
		printf("Erro abrindo o arquivo \"%s\"\n", argv[1]);
		printf("ERRO (#%i): \"%s\"\n", errno, strerror(errno));
		exit(ERRO_ABRINDO_ARQUIVO);
	}

	if ((identificador = mkstemp(nomeArquivoUnix)) == -1)
	{
		printf("Erro abrindo o arquivo temporario\n");
		printf("ERRO (#%i): \"%s\"\n", errno, strerror(errno));
		fclose(arquivoDOS);
		exit(ERRO_ABRINDO_ARQUIVO_TEMP);
	}

	if (!(arquivoUnix = fdopen(identificador, "w")))
	{
		printf("Erro criando o arquivo temporario\n");
		printf("ERRO (#%i): \"%s\"\n", errno, strerror(errno));
		fclose(arquivoDOS);
		exit(ERRO_ABRINDO_ARQUIVO_TEMP);
	}

	while ((fgets(buffer, COMPRIMENTO_MAXIMO_STRING, arquivoDOS)))
	{
		if ((buffer[strlen(buffer) - 1] == '\n') && (buffer[strlen(buffer) - 2] != '\r'))
			fprintf(arquivoUnix, "%s", buffer);
		if ((buffer[strlen(buffer) - 2] == '\r') && (buffer[strlen(buffer) - 1] == '\n'))
		{	
			printf("buffer0: \"%s\"\n", buffer);
			printf("1o strlen(buffer): %lu\n", strlen(buffer));
			buffer[strlen(buffer) - 1] = '\0';
			printf("buffer1: \"%s\"\n", buffer);
			printf("2o strlen(buffer): %lu\n", strlen(buffer));
			buffer[strlen(buffer) - 1] = '\0';
			printf("buffer2: \"%s\"\n", buffer);
			printf("3o strlen(buffer): %lu\n", strlen(buffer));
			fprintf(arquivoUnix, "%s", buffer);
			fprintf(arquivoUnix, "%s", "\n");
		}
	}

	if (ferror (arquivoDOS))
	{
		printf("Erro lendo o arquivo \"%s\"\n", argv[1]);
		printf("ERRO (#%i): \"%s\"\n", errno, strerror(errno));
		fclose(arquivoDOS);
		fclose(arquivoUnix);
		remove(nomeArquivoUnix);
		exit(ERRO_LENDO_ARQUIVO);
	}

	snprintf(nomeArquivoDOS, strlen(nomeArquivoDOS) + 5, "%s.bak", nomeArquivoDOS);

	rename(argv[1], nomeArquivoDOS);

	printf("argv[1]: %s\n", argv[1]);

	rename(nomeArquivoUnix, argv[1]);

	printf("%s\n", nomeArquivoDOS);

	return OK;

}



/* $RCSfile: aula1002.c,v $ */
