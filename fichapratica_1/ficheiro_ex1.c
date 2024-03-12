#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void main()
{
	FILE *fp;
	fp = fopen("exp.txt","r");
	
	if(fp == NULL)
	{
		printf("Nao foi possivel abrir o ficheiro");
	}
	else
	{
		printf("Ficheiro aberto com secesso");
		fclose(fp);
	}
}
