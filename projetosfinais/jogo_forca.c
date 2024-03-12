#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_PALAVRA 100

void desenho(int tentativas);
void main()
{
	char palavras[100][MAX_PALAVRA]; // palavras do ficheiro
	int indicePalavra, i;
	char palavra[MAX_PALAVRA];			 // palavra escolhida
	char palavraAdivinhada[MAX_PALAVRA]; // palavra para advinhar
	char letra;
	char jogarNovamente;

	do
	{
		system("cls");
		FILE *fp = fopen("palavras.txt", "r");
		if (fp == NULL)
		{
			printf("Erro ao abrir o ficheiro.\n");
		}
		else
		{
			int tentativas = 0, acertos = 0, totalPalavras = 0;
			while (fscanf(fp, "%s", palavras[totalPalavras]) != EOF)
			{
				totalPalavras++; // incrementa a quantiade de palavras que existe no ficheiro
			}
			fclose(fp);

			srand(time(NULL));
			indicePalavra = rand() % totalPalavras; // o indice fica com o valor que foi escolhido aleatoriamente
			strcpy(palavra, palavras[indicePalavra]);

			for (i = 0; i < strlen(palavra); i++)
			{
				palavra[i] = tolower(palavra[i]); // poe as palavras todas em minusculas
			}

			for (i = 0; i < strlen(palavra); i++)
			{
				palavraAdivinhada[i] = '_';
			}
			palavraAdivinhada[i] = '\0';

			printf("Jogo da forca!\n");
			while (acertos < strlen(palavra) && tentativas < 6)
			{
				printf("\nPalavra a adivinhar: %s\n", palavraAdivinhada);

				printf("Digite uma letra: ");
				scanf(" %c", &letra);

				int letraEncontrada = 0;
				for (i = 0; i < strlen(palavra); i++)
				{
					if (palavra[i] == letra && palavraAdivinhada[i] == '_')
					{
						palavraAdivinhada[i] = letra;
						acertos++;
						letraEncontrada = 1;
					}
				}

				if (!letraEncontrada)
				{
					tentativas++;
					printf("A letra nao esta na palavra. Tentativas utilizadas: %d\n", tentativas);
				}

				printf("\nForca:\n");
				desenho(tentativas);
				if (tentativas == 6)
				{
					printf("\nPerdeste AHAHHAH! A palavra era: %s\n", palavra);
				}
			}

			if (acertos == strlen(palavra))
			{
				printf("\nTiveste sorte e venceste o jogo, a palavra era %s\n", palavra);
			}

			printf("Quer jogar novamente? (s/n): ");
			scanf(" %c", &jogarNovamente);
		}
	} while (tolower(jogarNovamente) == 's');
}

void desenho(int tentativas)
{
	switch (tentativas)
	{
	case 1:
		printf("  O\n");
		break;
	case 2:
		printf("  O\n");
		printf("  |\n");
		break;
	case 3:
		printf("  O\n");
		printf(" \\|\n");
		break;
	case 4:
		printf("  O\n");
		printf(" \\|/\n");
		break;
	case 5:
		printf("  O\n");
		printf(" \\|/\n");
		printf(" /\n");
		break;
	case 6:
		printf("  O\n");
		printf(" \\|/\n");
		printf(" / \\\n");
		break;
	default:
		break;
	}
}
