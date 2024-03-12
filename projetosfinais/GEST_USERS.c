#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int codigo;
    char nome[20];
    char login[20];
    char password[20];
    char mail[50];
    char contacto[20];
} User;

void menu();
void inserir_user(User dados[], int num_user);
void alterar_dados(User dados[], int num_user);
void consultar_dados(User dados[], int num_user);
void listar_dados(User dados[], int num_user);
int eliminar_user(User dados[], int num_user);
void gravar_info(User dados[], int num_user);
User carregar_info(User dados[], int *num_user);
void pesquisar_users(User dados[], int num_user);
void listar_ordenado(User dados[], int num_user);
void main()
{
    FILE *fp;
    User utilizadores[100];
    int num_utilizadores = 0;
    char op;
    utilizadores[num_utilizadores] = carregar_info(utilizadores, &num_utilizadores);

    do
    {
        system("cls");
        menu();
        puts("Chose one option");
        fflush(stdin);
        scanf("%c", &op);
        system("cls");
        switch (op)
        {
        case 'i':
            inserir_user(utilizadores, num_utilizadores);
            num_utilizadores++;
            break;
        case 'a':
            alterar_dados(utilizadores, num_utilizadores);
            break;
        case 'c':
            consultar_dados(utilizadores, num_utilizadores);
            break;
        case 'l':
            listar_dados(utilizadores, num_utilizadores);
            break;
        case 'o':
            listar_ordenado(utilizadores, num_utilizadores);
            break;
        case 'e':
            num_utilizadores = eliminar_user(utilizadores, num_utilizadores);
            break;
        default:
            break;
        }
        system("pause");
    } while (op != 's');

    gravar_info(utilizadores, num_utilizadores);
}

void menu()
{
    puts("i-Inserir novo utilizador");
    puts("a-Alterar os dados de um utilizador");
    puts("c-Consultar dados de um utilizador");
    puts("l-Listar dados de todos os utilizadores");
    puts("o-Listar dados de forma ordenada");
    puts("e-Eliminar um utilizador");
    puts("s-Sair do programa");
}

void inserir_user(User dados[], int num_user)
{
    int tam, ver_pass = 1, ver_login = 1, ver_email = 1;
    int i;
    dados[num_user].codigo = num_user + 1;

    printf("User: %d\n", dados[num_user].codigo);
    puts("Insira o nome do utilizador");
    fflush(stdin);
    gets(dados[num_user].nome);

    puts("Insira o login");
    fflush(stdin);
    gets(dados[num_user].login);
    do
    {
        ver_login = 1;
        for (i = 0; i < num_user; i++)
        {
            if (strcmp(dados[num_user].login, dados[i].login) == 0)
            {
                printf("Esse login ja esta a ser utilizado\n");
                ver_login = 0;
                break;
            }
        }
        if (!ver_login)
        {
            puts("Insira o nome do login");
            fflush(stdin);
            gets(dados[num_user].login);
        }
    } while (!ver_login);

    do
    {
        puts("Insira a password");
        fflush(stdin);
        gets(dados[num_user].password);
        tam = strlen(dados[num_user].password);
        if (tam < 8)
        {
            printf("Inisra uma palavra com pelo menos 8 caracteres\n");
            ver_pass = 0;
        }
        else
        {
            ver_pass = 1;
        }
    } while (!ver_pass);

    puts("Insira o email");
    fflush(stdin);
    gets(dados[num_user].mail);
    do
    {
        ver_email = 1;
        for (i = 0; i < num_user; i++)
        {
            if (strcmp(dados[num_user].mail, dados[i].mail) == 0)
            {
                printf("Esse email ja esta a ser utilizado\n");
                ver_email = 0;
                break;
            }
        }
        if (!ver_email)
        {
            puts("Insira o email");
            fflush(stdin);
            gets(dados[num_user].mail);
        }
    } while (!ver_email);

    puts("Insira o numero de telefone");
    fflush(stdin);
    gets(dados[num_user].contacto);
}

void alterar_dados(User dados[], int num_user) 
{
    int codigo, i, ver_pass = 1, tam, ver_email, ver_login, j;
    pesquisar_users(dados, num_user);
    printf("Insira o codigo do utilizador que deseja alterar: ");
    scanf("%d", &codigo);

    int encontrado = 0;
    for (i = 0; i < num_user; i++) {
        if (dados[i].codigo == codigo) {
            encontrado = 1;
            printf("Insira o novo nome do utilizador: ");
            fflush(stdin);
            gets(dados[i].nome);

            printf("Insira o novo nome do login: ");
            fflush(stdin);
            gets(dados[i].login);
            do {
                ver_login = 1;
                for ( j = 0; j < num_user; j++) 
				{
                    if (strcmp(dados[num_user].login, dados[j].login) == 0) {
                        printf("Esse login ja esta a ser utilizado\n");
                        ver_login = 0;
                        break;
                    }
                }
                if (!ver_login) 
				{
                    puts("Insira o nome do login");
                    fflush(stdin);
                    gets(dados[num_user].login);
                }
            } while (!ver_login);

            do
            {
                puts("Insira a password");
                fflush(stdin);
                gets(dados[i].password);
                tam = strlen(dados[i].password);
                if (tam < 8)
                {
                    printf("Inisra uma palavra com pelo menos 8 caracteres\n");
                    ver_pass = 0;
                }
                else
                {
                    ver_pass = 1;
                }
            } while (!ver_pass);

            printf("Insira o novo email: ");
            fflush(stdin);
            gets(dados[i].mail);
            do
            {
                ver_email = 1;
                for (i = 0; i < num_user; i++)
                {
                    if (strcmp(dados[num_user].mail, dados[i].mail) == 0)
                    {
                        printf("Esse email ja esta a ser utilizado\n");
                        ver_email = 0;
                        break;
                    }
                }
                if (!ver_email)
                {
                    puts("Insira o email");
                    fflush(stdin);
                    gets(dados[num_user].mail);
                }
            } while (!ver_email);

            printf("Insira o novo numero de telefone: ");
            fflush(stdin);
            gets(dados[i].contacto);

            printf("Dados do utilizador alterados com sucesso!\n");
            break;
        }
    }
    if (!encontrado)
    {
        printf("Utilizador com o codigo %d nao encontrado.\n", codigo);
    }
}

void consultar_dados(User dados[], int num_user)
{
    int codigo, i;
    pesquisar_users(dados, num_user);
    printf("Insira o codigo do utilizador que deseja consultar: ");
    scanf("%d", &codigo);
    int encontrado = 0;
    for (i = 0; i < num_user; i++)
    {
        if (dados[i].codigo == codigo)
        {
            encontrado = 1;
            printf("Codigo\t\tNome\t\tlogin\t\tpassword\t\tmail\t\tcontacto\n");
            printf("%d            %s	   %s		  %s	  %s		%s\n", dados[i].codigo, dados[i].nome, dados[i].login, dados[i].password, dados[i].mail, dados[i].contacto);
        }
    }
    if (!encontrado)
    {
        printf("Utilizador com o codigo %d nao encontrado.\n", codigo);
    }
}

void listar_dados(User dados[], int num_user)
{
    int i;
    printf("Codigo\t\tNome\t\tlogin\t\tpassword\t\tmail\t\tcontacto\n");
    for (i = 0; i < num_user; i++)
    {
        printf("%d            %s	   %s		  %s	  %s		%s\n", dados[i].codigo, dados[i].nome, dados[i].login, dados[i].password, dados[i].mail, dados[i].contacto);
    }
}

int eliminar_user(User dados[], int num_user)
{
    int codigo, j, i;
    pesquisar_users(dados, num_user);
    printf("Insira o codigo do utilizador que deseja eliminar: ");
    scanf("%d", &codigo);

    int encontrado = 0;
    for (i = 0; i < num_user; i++)
    {
        if (dados[i].codigo == codigo)
        {
            encontrado = 1;
            for (j = i; j < num_user - 1; j++)
            {
                dados[j] = dados[j + 1];
                dados[j].codigo = j + 1;
            }
            num_user--;
            printf("Utilizador com o codigo %d eliminado com sucesso!\n", codigo);
            break;
        }
    }

    if (!encontrado)
    {
        printf("Utilizador com o codigo %d nao encontrado.\n", codigo);
    }

    return num_user;
}

User carregar_info(User dados[], int *num_user)
{
    FILE *fp;
    fp = fopen("users.dat", "rb");

    if (fp == NULL)
    {
        printf("Nao foi possivel abrir o ficheiro\n");
    }
    else
    {
        fseek(fp, 0, SEEK_SET);

        *num_user = 0;
        while (fread(&dados[*num_user], sizeof(User), 1, fp))
        {
            (*num_user)++;
        }

        fclose(fp);
    }

    return dados[*num_user - 1];
}

void gravar_info(User dados[], int num_user)
{
    FILE *fp;
    fp = fopen("users.dat", "wb");

    if (fp == NULL)
    {
        printf("Nao foi possivel abrir o ficheiro");
    }
    else
    {
        fwrite(dados, sizeof(User), num_user, fp);
        fclose(fp);
    }
}

void pesquisar_users(User dados[], int num_user)
{
    int j, i;
    for (i = 0; i < num_user; i++)
    {
        printf("Nome: %s\n", dados[i].nome);
        printf("codigo: %d\n", dados[i].codigo);
        printf("\n");
    }
}

void listar_ordenado(User dados[], int num_user)
{
    User temp;
    int i, j;

    for (i = 0; i < num_user - 1; i++)
    {
        for (j = i + 1; j < num_user; j++)
        {
            if (strcmp(dados[i].nome, dados[j].nome) > 0)
            {
                temp = dados[i];
                dados[i] = dados[j];
                dados[j] = temp;
            }
        }
    }

    printf("Lista de utilizadores ordenados por nome:\n");
    printf("Codigo\t\tNome\t\tlogin\t\tpassword\t\tmail\t\tcontacto\n");
    for (i = 0; i < num_user; i++)
    {
        printf("%d            %s	   %s		  %s	  %s		%s\n",
               dados[i].codigo, dados[i].nome, dados[i].login,
               dados[i].password, dados[i].mail, dados[i].contacto);
    }
}
