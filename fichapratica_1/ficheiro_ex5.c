#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct
{
    char nome[20];
    int idd;
    char profissao[20];
    char est_civil;
} Pessoa;

void main()
{
    system("cls");
    FILE *fp;
    Pessoa P1;

    fp = fopen("dados.dat", "ab");

    if (fp == NULL)
    {
        printf("Nao foi possivel abrir o ficheiro");
    }
    else
    {
		printf("Inisra o nome da pessoa: ");
		scanf(" %19[^\n]", P1.nome);

        printf("Inisra a idade da pessoa: ");
        scanf("%d", &P1.idd);

        printf("Insira a profissao da pessoa: ");
        //fflush(stdin, NULL);
        //setbuf(stdin, NULL);
		scanf(" %19[^\n]", P1.profissao);

        printf("Insira o estado civil da pessoa: ");
        scanf(" %c", &P1.est_civil);

        fwrite(&P1, sizeof(Pessoa), 1, fp);

        fclose(fp);
    }
}
