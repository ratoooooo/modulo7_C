#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main()
{
    system("cls");
    FILE *fp;
    char cadeia[20];

    fp = fopen("ficheiro.txt", "w+");
    if (fp == NULL)
    {
        puts("Nao foi possivel abrir o ficheiro.\n");
    }
    else
    {
        do
        {
            gets(cadeia);
            strcat(cadeia, "\n");
            fputs(cadeia, fp);
        } while (strcmp(cadeia, "\n") != 0);

        puts("Ddados escritos no ficheiro.txt");
        rewind(fp);
        while (feof(fp) == 0)
        {
            fgets(cadeia, sizeof(cadeia), fp);
            printf("%s", cadeia);
        }
        
        
        fclose(fp);
    }
    system("pause");
}