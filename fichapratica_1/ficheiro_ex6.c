#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char nome[20];
    int idd;
    char profissao[20];
    char est_civil;
} Pessoa;

int startwith(char str1[], char str2[], int start);
int substring(char str1[], char str2[]);
void main()
{
    system("cls");
    char name[20], op;
    FILE *fp;
    Pessoa P1;

    fp = fopen("dados.dat", "rb");
    if (fp == NULL)
    {
        puts("Nao foi possivel abrir o ficheiro.\n");
    }
    else
    {
    	do
		{
            puts("Insira o nome da pessoa que quer ver os dados: ");
        	fflush(stdin);
        	gets(name);
            
            /*
            while (fread(&P1, sizeof(Pessoa), 1, fp) != 0)
            {
                if (startwith(name, P1.nome) == 1)
                {
                    printf("Nome: %s\n", P1.nome);
                    printf("Idade: %d\n", P1.idd);
                    printf("Profissao: %s\n", P1.profissao);
                    printf("Estado Civil: %c\n", P1.est_civil);
                    printf("\n");
                }
            }
            */
            if (strlen(name) >= 3)
            {
                do
                {
                    if (fread(&P1, sizeof(Pessoa), 1, fp))
                    {
                        if (substring(name, P1.nome) >= 0)
                        {
                            printf("Nome: %s\n", P1.nome);
                            printf("Idade: %d\n", P1.idd);
                            printf("Profissao: %s\n", P1.profissao);
                            printf("Estado Civil: %c\n", P1.est_civil);
                            printf("\n");
                        }
                    }
                } while (!feof(fp));
                
                fseek(fp, 0L, SEEK_SET);
            }
            else
            {
                puts("Tem de ter pelo menos 3 caracteres");
            }
			
            puts("Deseja sair do programa? S-Sim, N-Não");
            scanf(" %c", &op);
        
    }while (op != 's');
    
    fclose(fp);
    system("pause");
	}
}
/* Funcao para verificar se existe a str1 na str2
   Retorna 1 se existe, 0 se nao existe */
int startwith(char str1[], char str2[], int start)
{
    int i, tam1, tam2, k = 0;
    char c1, c2;
    
    tam1 = strlen(str1);
    tam2 = strlen(str2);
    
    if (tam1 > tam2)
    {
        return 0;
    }

    while (k < tam1)
    {
        for (i = start; i < start + tam1; i++)
        {
            c1 = tolower(str1[k]);
            c2 = tolower(str2[i]);
            
            if (c1 != c2)
            {
                return 0;
            }

            k++;
        }
    }

    return 1;
}

/*Funcao para vereficar se
existe a str1 em alguma
parte da str2
return 1 se existe
return 0 se nao existe */
int substring(char str1[], char str2[])
{
    int i, tam1, tam2;
    
    tam1 = strlen(str1);
    tam2 = strlen(str2);
    
    for (i = 0; i <= tam2 - tam1; i++)
    {
        if (startwith(str1, str2, i) != 0)
        {
            return i;
        }
    }
    return -1;
}