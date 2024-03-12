#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void main()
{
	char texto[100];
	char nome_ficheiro[100], ch;
	int i=0;
	FILE *fp;
	
	puts("Introduza o nome do ficheiro");
	gets(nome_ficheiro);
	
	fp = fopen(nome_ficheiro, "a");
	
	if(fp == NULL)
	{
		printf("Nao foi possivel abrir o ficheiro");
	}
	else
	{
		puts("Digite o texto para inserir no ficheiro");
		gets(texto);
		
		while(texto[i] != '\0')
		{
			fputc(texto[i], fp);
			i++;
		}
		
		close(fp);
	}
	
}
