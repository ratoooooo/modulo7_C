#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void main()
{
	char s[100], ch;
	FILE *fp;
	
	puts("Introduza o nome do ficheiro");
	gets(s);
	
	fp = fopen(s, "r");
	
	if(fp == NULL)
	{
		printf("Nao foi possivel abrir o ficheiro");
	}
	else
	{
		printf("Ficheiro %s aberto com secesso\n", s);
		ch = fgetc(fp);
		
		while(ch != EOF)
		{
			putchar(ch);
			//printf(" %c", ch);
			ch = fgetc(fp);
		}
		
		fclose(fp);
	}
}
