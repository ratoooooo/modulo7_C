#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void main()
{
    system("cls");
    char nome[10];
    int nota1, nota2, nota3;
    float media;
    FILE *fp;

    fp = fopen("notas.txt", "r");

    if (fp == NULL)
    {
        printf("Nao foi possivel abrir o ficheiro");
    }
    else
    {
        while(fscanf(fp, "%s %d %d %d", nome, &nota1, &nota2, &nota3) != EOF)
        {
        	//printf("A nota do aluno %s foi %d %d e %d\n", nome, nota1, nota2, nota3);
            media = (nota1+nota2+nota3) / 3;
            if(media >= 10)
            {
                printf("A media do aluno %s foi %.2f\n", nome, media);
            }
        }
        fclose(fp);
    }
}